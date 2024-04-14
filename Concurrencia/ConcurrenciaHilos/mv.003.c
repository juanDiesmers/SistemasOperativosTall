/*
Fecha 04/04/2024
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
    mv.003.c -------------------------------------
    - Declaracion de vectores de Hilos.
    /// Implementacion de Paralelismo (clase 4/11/2024)
    - Resolucion de la multiplicacion de Hilos.
    - Se crea el vector de hilos.
    - Se tiene pendiente la exclusion de los hilos.
    - Se convierten las matrices a variables de alcance global.
    - Encapsular los datos para enviarlos como argunmentos a la funcion que ejecutara el hilo.
    - Posteriormente, se desencapsulan los datos una vez han sido recibidos por el metodo 
    multiplicacionMatriz.
*/

// Incluimos las librerias necesarias
// stdio.h: Libreria estandar de entrada y salida
#include <stdio.h>
// pthread.h: Libreria para el manejo de hilos
#include <pthread.h>
// stdlib.h: Libreria estandar de C
#include <stdlib.h>
// Referencia a matrix_operations.h
#include "matrix_operations.h"

// Definicion de la cantidad de memoria a reservar
#define RESERVA (1024*128*64*8)
// Creacion de un vector cuyo tamaño sera igual a RESERVA
static double MEM_CHUNK[RESERVA];

int main(int argc, char *argv[]){
    // Verificacion de que la cantidad de argumentos ingresados sea correcta
    if (argc<2){
        printf("Error: No se ingreso suficientes argumentos\n");
        return 1;
    } else if (atoi(argv[1]) <= 0 && atoi(argv[2]) <= 0){
        printf("Error: Los argumentos ingresados no son validos\n");
        return 1;
    }

    // Captura de los valores ingresados por el usuario
    int N = atoi(argv[1]);
    int H = atoi(argv[2]);

    // Creacion variables apuntandoras que hacen referencia a las matrices
    // dentro de la memoria reservada
    double *mA, *mB, *mC;

    // Definicion de los espacio de memoria para las matrices
    mA = MEM_CHUNK;
    mB = mA + (N*N);
    mC = mB + (N*N);

    // Inicializacion de las matrices
    initMatrix(N, mA, mB, mC);

    // Impresion de las matrices
    printf("Matriz A\n");
    printMatrix(N, mA);
    printf("Matriz B\n");
    printMatrix(N, mB);

    // Intancia de un puntero de tipo estructura datosMM
    // Se asigna su tamaño en memoria por medio del metodo malloc
    struct datosMM* valoresMM = (struct datosMM*)malloc(sizeof(struct datosMM));

    // Asignacion de los valores a la estructura
    valoresMM->N = N;
    valoresMM->H = H;
    valoresMM->mA = mA;
    valoresMM->mB = mB;
    valoresMM->mC = mC;

    // Creacion de tantos hilos como se haya ingresado por el usuario
    pthread_t hilos[H];

    // Calcular la matiz resultante
    printf("Calculando la matriz resultante\n");

    for(int h=0; h<H; h++){
        // Creacion de los hilos
        pthread_create(&hilos[h], NULL, multiMatriz, (void*)valoresMM);
    }
    // Puerto de espera para que los hilos terminen
    for(int h=0; h<H; h++){
        pthread_join(hilos[h], NULL);
    }

    // Impresion de la matriz resultante
    printf("Matriz C\n");
    printMatrix(N, mC);

    // fin del programa
    printf("Fin del programa\n");

    // Liberacion de memoria
    pthread_exit(NULL);
    free(valoresMM);
    return 0;
}