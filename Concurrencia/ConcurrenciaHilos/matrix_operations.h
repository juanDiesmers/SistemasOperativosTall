#ifndef __MATRIX_OPERATIONS_H
#define __MATRIX_OPERATIONS_H

#include <stdio.h>

struct datosMM{
    int N;
    int H;
    double *mA;
    double *mB;
    double *mC;
};

void initMatrix( int n, double *m1, double *m2, double *m3);
void printMatrix(int n, double *m);
void *multiMatriz( void *argMM);

#endif