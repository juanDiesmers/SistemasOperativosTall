// Definicion de la logica de las funciones que estan en 
// matrix_operations.h

// Librerias
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "matrix_operations.h"

// Firma de funciones
void initMatrix( int n, double *m1, double *m2, double *m3) {
    // Inicializacion de las matrices
    for (int i = 0; i < n*n; i++){
        m1[i] = i*1.1;
        m2[i] = i*2.2;
        m3[i] = i;
    }
}

void printMatrix(int n, double* m) {
    // Impresion de las matrices
    if (n<9) {
        for (int i = 0; i < n*n; i++){
            if(i%n == 0) {
                printf("\n");
            }
            printf("%f ", m[i]);
        }
        printf("\n************************************\n");
    } else {
        printf("\n************************************\n");
    }
}

// Multiplicacion de matrices
void* multiMatriz(void* arg) {
    struct datosMM *valoresMM = arg;
    for(int i = 0; i < valoresMM->N; i++) {
        for(int j = 0; j < valoresMM->N; j++) {
            double sumaTemp = 0;
            for (int k = 0; k < valoresMM->N; k++) {
                sumaTemp += valoresMM->mA[i * valoresMM->N + k] * valoresMM->mB[k * valoresMM->N + j];
            }
            valoresMM->mC[i * valoresMM->N + j] = sumaTemp;
        }
    }
    return NULL;
}

