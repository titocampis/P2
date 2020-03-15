#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <errno.h> 
#include "pav_analysis.h" 
#include "fic_wave.h"

int main(int argc, char *argv[]) {
    float durTrm = 0.010;
    float fm;
    int N;
    int trm;
    float *x;
    short *buffer;
    FILE *fpWave;
    FILE *f_writte=fopen(argv[2],"w");
    FILE *p_writte=fopen("pot.txt","w"); 

    if (argc != 2 && argc != 3) {
        fprintf(stderr, "Empleo: %s inputfile [outputfile]\n", argv[0]); 
        return -1;
    }

    if ((fpWave = abre_wave(argv[1], &fm)) == NULL) {
        fprintf(stderr, "Error al abrir %s (%s)\n", argv[1], strerror(errno)); 
        return -1;
    }

    N = durTrm * fm;

    if ((buffer = malloc(N * sizeof(*buffer))) == 0 ||(x = malloc(N * sizeof(*x))) == 0) {
        fprintf(stderr, "Error al ubicar los vectores (%s)\n", strerror(errno)); 
        return -1;
    }

    trm = 0;
    //Entonces crear un fichero si no existe o abrirlo y escribir en el el resultado

    while (lee_wave(buffer, sizeof(*buffer), N, fpWave) == N) {
        for (int n = 0; n < N; n++) x[n] = buffer[n] / (float) (1 << 15);
        //Si el argumento contiene 3 elementos: la funcion y 2 más
        if(argc==3){
            fprintf(f_writte,"%d\t%f\t%f\t%f\n", trm, compute_power(x, N), 
                compute_am(x, N), compute_zcr(x, N, fm) );
            fprintf(p_writte,"%f\n", compute_power(x,N));
        } else {
            printf("%d\t%f\t%f\t%f\n", trm, compute_power(x, N), compute_am(x, N), compute_zcr(x, N, fm));
        }
        trm += 1; 
    }
        cierra_wave(fpWave); 
        cierra_wave(f_writte);
        cierra_wave(p_writte);
        free(buffer); 
        free(x);
    return 0;
}