/*
Fecha 4/4/2024
Autor: Juan Diego Palacios Toeldo
Materia: Sistemas Operativos
Tema: Concurrencia
Objetivo: Metodologia para la implementacion de la 
  multiplicacion de matrices haciendo uso de paralelismo 
  por medio de la biblioteca Pthreads. Se hace uso del
  algoritmo clásico de multiplicación de matrices, en este
  caso, matrices cuadradas.
    -Reserva de memoria.
    -Creación de punteros para matrices del tipo double.
    -Asignación de memoria.
    -Ingreso de argumentos de entrada.
    -Inicialización de matrices.
    -Imprimir matrices.
    -Funcion para inicializar matrices.
    -funcion para imprimir matrices.
    - Algoritmo clasico de multiplicacion de matrices.
    - verificar el resultado de la multiplicacion.
    - Declaracion de vector de hilos.
    - Creacion de hilos segun tamaño de vector de hilos.
    - Crear estrucutura de datos que encapsule los arguemtos de entrada de la funcion MM
*/

// Incluimos las librerias necesarias
// stdio.h: Libreria estandar de entrada y salida
#include <stdio.h>
// stdlib.h: Libreria estandar de funciones
#include <stdlib.h>
// time.h: Libreria para el manejo de tiempo
#include <sys/time.h>
// pthread.h: Libreria para el manejo de hilos
#include <pthread.h>

// Definicion de la cantidad de memoria a reservar
#define RESERVA (1024*128*64*8)

// Estrucutra de datos
struct datosMM{
    int N;
    int H;
    double *mA;
    double *mB;
    double *mC;
};

// Definicion de la memoria a reservar
static double MEM_CHUNK[RESERVA];

// Funcion para inicializar matrices
void initMatrix( void *argMM) {
    for (int i = 0; i < n*n; i++) {
        m1[i] = i*1.1;
        m2[i] = i*2.2;
        m3[i] = i;
    }

};

// Funcion para imprimir matrices
void printMatrix(int n, double *matris){
    if (n < 9) {
    for (int i = 0; i < n*n; i++) {
        if(i%n==0) printf("\n");
        printf("\t%.2f", matris[i]);
    }
    printf("\n#####################################\n");
    } else {
        printf("\n#####################################\n");
    }
};

// Funcion para multiplicar matrices
void *multiMatriz( int n, double *m1, double *m2, double *m3) {
    // calcular la multiplicacion de matrices
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {   
            double sumaTemp, *p1, *p2;
            sumaTemp = 0.0;
            p1 = m1 + i*n;
            p2 = m2 + j;  
            for (int k = 0; k < n; k++, p1++, p2 += n) {
                sumaTemp += *p1 * *p2;
            }
            m3[i*n+j] = sumaTemp;
        }
    }
    return 0;
};

int main (int argc, char *argv[]) {

    // Verificamos que se ingresen los argumentos necesarios
    if (argc <= 2) {
        printf("\n\tError: Faltan argumentos\n\n");
        // Argumentos necesarios
        printf("\tArgumentos:\n");
        printf("\n\t $ejecutable.exe DIM NumHilos\n");
        return -1;
    }
    // Verificar numero negativos y el 0
    if (atoi(argv[1]) <= 0 || atoi(argv[2]) <= 0) {
        printf("\n\tError: Argumentos Negativos o con Valor 0\n\n");
        return -1;
    }


    // Definicion de variables
    int N = (int) atof(argv[1]);
    int H = (int) atof(argv[2]);

    pthread_t hilos[H];

    double *mA, *mB, *mC;
    mA = MEM_CHUNK;
    mB = mA + N*N;
    mC = mB + N*N;

    // Inicializacion de matrices
    initMatrix(N, mA, mB, mC);

    // Imprimir matrices
    printMatrix(N, mA);
    printMatrix(N, mB);

    for (int h = 0; h < H; h++) {
        pthread_create(&hilos[h], NULL, multiMatriz, &h);
    }
    
    // Llamado a la funcion para multiplicar matrices
    multiMatriz(N, mA, mB, mC);

    // Imprimir matriz resultante
    printMatrix(N, mC);

    

    printf("\n\tFin del programa\n\n");
    return 0;
}