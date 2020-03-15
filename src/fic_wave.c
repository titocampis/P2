#include <stdio.h> 
#include "fic_wave.h"

#ifndef FIC_WAVE_H 
#define FIC_WAVE_H

FILE *abre_wave(const char *ficWave, float *fm);
size_t lee_wave(void *x, size_t size, size_t nmemb, FILE *fpWave); void cierra_wave(FILE *fpWave);
#endif /* FIC_WAV_H */

FILE *abre_wave(const char *ficWave, float *fm) { 
    FILE *fpWave;
  //  int fmuest;

    if ((fpWave = fopen(ficWave, "r")) == NULL) return NULL; 
    if (fseek(fpWave, 44, SEEK_SET) < 0) return NULL;

// Con fseek cambiamos el offset de lectura y en este caso le indicamos que lo modifique en el
// fichero fpWave, que ponga un offset de 24 bits y que empiece a poner el offset al inicio del fichero
// la frecuencia de muestreo recordemos se encuentra en el bit 24 como vemos arriba
  //  fseek(fpWave, 24, SEEK_SET);
// Con fread leemos 4 bits, del fichero fpWave y los guardamos como una variable en fmuest
  //  fread(&fmuest, 4, 1, fpWave);
// Le indicamos al fichero que empiece a leer a partir del 44 (offset) a partir del bit donde se encuentran los datos
 //   fseek(fpWave, 44, SEEK_SET);
 //   *fm = (float)fmuest; 
    *fm=16000;
  //  printf("La fm es: %d Hz\n",fmuest);
    return fpWave;
}

size_t lee_wave(void *x, size_t size, size_t nmemb, FILE *fpWave) {
    return fread(x, size, nmemb, fpWave); 
}

void cierra_wave(FILE *fpWave) {
    fclose(fpWave);
}