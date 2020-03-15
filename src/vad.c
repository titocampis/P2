#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "pav_analysis.h"
#include "vad.h"

const float FRAME_TIME = 10.0F; /* in ms. */
const int N_init = 10; // Numero de muestras iniciales que cogemos
const int alpha_1 = 4; // Margen k1 = k0 + alpha_1
const int alpha_2 = 12; // Margen k2 = ko + alpha_2
/* 
 * As the output state is only ST_VOICE, ST_SILENCE, or ST_UNDEF,
 * only this labels are needed. You need to add all labels, in case
 * you want to print the internal state in string format
 */
int fm;

const char *state_str[] = {
  "UNDEF", "S", "V", "INIT"
};

int signo(float x){
    if(x>=0){
        return 1;
    } else {
        return 0;
    }
}

const char *state2str(VAD_STATE st) {
  return state_str[st];
}

/* Define a datatype with interesting features */
typedef struct {
  float zcr;
  float p;
  float am;
} Features;

/* 
 * TODO: Delete and use your own features!
 */

Features compute_features(const float *x, int N) {
  /*
   * Input: x[i] : i=0 .... N-1 
   * Ouput: computed features
   */
  /* 
   * DELETE and include a call to your own functions
   *
   * For the moment, compute random value between 0 and 1 
   */
  Features feat;
  float pow, am, zcr;

  float sum = 0;
  for(int i=0; i<N;i++){
    sum = sum + (x[i]*x[i]);
  }
  pow = 10*log10(sum/N);
  sum = 0;

  for(int i = 0; i < N; i ++){
        sum = sum + fabs(x[i]);
  }
  am = sum/N;
  sum = 0;

  for(int i = 1; i < N ; i++){
    if(signo(x[i-1])!=signo(x[i])){
      sum += 1;
    }
  }
  zcr = (fm/2)*(sum/(N-1));

  feat.p = pow;
  feat.am = am;
  feat.zcr = zcr;
//  feat.zcr = feat.p = feat.am = (float) rand()/RAND_MAX;
  return feat;
}

/* 
 * TODO: Init the values of vad_data
 */

VAD_DATA * vad_open(float rate) {
  VAD_DATA *vad_data = malloc(sizeof(VAD_DATA));
  vad_data->state = ST_INIT;
  vad_data->sampling_rate = rate;
  vad_data->frame_length = rate * FRAME_TIME * 1e-3;
  vad_data->k0;
  vad_data->k1;
  vad_data->k2;
  vad_data->total_sil = 0; // # Muestras consecutivas de silencio
  vad_data->total_voi = 0; // # Muestras consecutivas de voz
  // vad_data->time_wait = 90; // Referencia de silencio real
  vad_data->sample_wait = 1440; //time_wait*fm
  return vad_data;
}

VAD_STATE vad_close(VAD_DATA *vad_data) {
  VAD_STATE state = ST_SILENCE;
  /* 
   * TODO: decide what to do with the last undecided frames
   */
  state = vad_data->state;

  free(vad_data);
  return state;
}

unsigned int vad_frame_size(VAD_DATA *vad_data) {
  return vad_data->frame_length;
}

/* 
 * TODO: Implement the Voice Activity Detection 
 * using a Finite State Automata
 */

VAD_STATE vad(VAD_DATA *vad_data, float *x) {

  /* 
   * TODO: You can change this, using your own features,
   * program finite state automaton, define conditions, etc.
   */

  Features f = compute_features(x, vad_data->frame_length);
  vad_data->last_feature = f.p; /* save feature, in case you want to show */

  switch (vad_data->state) {
    case ST_INIT:
      if(vad_data->total_sil < N_init){
        vad_data->k0+=pow(10,f.p/10);
        vad_data->total_sil += 1;
      } else {
        vad_data->total_sil = 0;
        vad_data->k0 = 10*log10(vad_data->k0/N_init);
        vad_data->k1 = vad_data->k0 + alpha_1;
        vad_data->k2 = vad_data->k0 + alpha_2;
        vad_data->state = ST_SILENCE;
      }
    break;

    case ST_SILENCE:
      if (f.p > vad_data->k1){
        vad_data->state = ST_MAYBEVOICE;
        vad_data->total_voi = 0;
        // No hay que poner a cero las muestras de silencio, 
        // pues puede ser un pico de silencio
      }
    break;

    case ST_VOICE:
      if (f.p < vad_data->k2){
        vad_data->state = ST_MAYBESILENCE;
        vad_data->total_sil = 0;
      }
    break;
  
    case ST_MAYBESILENCE:
      if(vad_data->total_sil < vad_data->sample_wait){
        if(f.p > vad_data->k2) vad_data->state = ST_VOICE;
        else vad_data->total_sil += 1;
      } else {
      //  if(f.p > vad_data->k2) vad_data->state = ST_VOICE;
        if(f.p < vad_data->k1) vad_data->state = ST_SILENCE;
        else vad_data->total_sil += 1;
      }
    break;

      case ST_MAYBEVOICE:
        if(f.p > vad_data->k2){
          vad_data->state = ST_VOICE;
        } else if(f.p < vad_data->k1){
          vad_data->state = ST_SILENCE;
        } else vad_data->total_voi += 1;
      break;

      case ST_UNDEF:
      break;
  }

  if (vad_data->state == ST_SILENCE || vad_data->state == ST_VOICE)
    return vad_data->state;
  else
    return ST_UNDEF;
}

void vad_show_state(const VAD_DATA *vad_data, FILE *out) {
  fprintf(out, "%d\t%f\n", vad_data->state, vad_data->last_feature);
}
