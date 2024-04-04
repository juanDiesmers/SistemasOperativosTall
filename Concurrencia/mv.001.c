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

// Definicion de la memoria a reservar
static double MEM_CHUNK[RESERVA];

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
    double *mA, *mB, *mC;
    mA = MEM_CHUNK;
    mB = mA + N*N;
    mC = mB + N*N;

    printf("\n\tFin del programa\n\n")
    return 0;
}