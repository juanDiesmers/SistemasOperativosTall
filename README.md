# Multiplicación de Matrices con Pthreads

Este proyecto implementa el algoritmo clásico de multiplicación de matrices cuadradas, optimizado a través del uso de paralelismo con la biblioteca Pthreads en C. Desarrollado como parte de los estudios en la materia de Sistemas Operativos, el objetivo es demostrar la metodología para mejorar el rendimiento de operaciones computacionalmente intensivas mediante la distribución de la carga de trabajo entre múltiples hilos.

## Información General

- **Fecha:** 4 de abril de 2024
- **Autor:** Juan Diego Palacios Toledo
- **Materia:** Sistemas Operativos
- **Tema:** Concurrencia
- **Objetivo:** Implementar la multiplicación de matrices cuadradas utilizando paralelismo con Pthreads.


## Requisitos

Para compilar y ejecutar este programa, necesitarás:

- Un compilador de C, como GCC.
- La biblioteca Pthreads instalada en tu sistema.

## Compilación y Ejecución

Para compilar el programa, puedes usar el siguiente comando en la terminal:

```bash
cd Concurrencia

gcc mv.002.c

```
Para ejecutar el programa:
```bash
./a.out <dimensión de la matriz> <número de hilos>
```

# Descripcion del Código

### Reserva de Memoria
- **Reserva de Memoria:** A través de una constante `RESERVA`, el programa especifica la cantidad de memoria que se reservará para almacenar las matrices involucradas en la operación. Esta aproximación asegura que hay suficiente espacio para las matrices de entrada y el resultado de su multiplicación, evitando así la fragmentación de memoria.
  
### Inicialización y Presentación de Matrices
- **Inicialización (`initMatrix`):** Esta función asigna valores a las matrices de entrada de manera programática, garantizando que las matrices estén listas para la multiplicación. Los valores asignados pueden ajustarse para probar diferentes escenarios y cargas de trabajo.

- **Presentación (`printMatrix`):** Con el fin de verificar los resultados y proporcionar una interfaz de usuario más interactiva, el programa incluye una función para imprimir las matrices. Dicha función está diseñada para facilitar la visualización de matrices pequeñas, limitando la impresión a matrices de dimensiones manejables.

### Multiplicación de Matrices

- **Algoritmo Clásico (`multiMatriz`):** Se implementa el algoritmo clásico de multiplicación de matrices, el cual realiza el producto punto entre filas y columnas de las matrices de entrada. Esta función es el núcleo computacional del programa, donde se lleva a cabo la operación matemática que determina el rendimiento del mismo.

### Declaración de Estructuras
- **Declaración de Estructuras:** Se declara una estructura `datosMM` para encapsular los datos necesarios para realizar la multiplicación de matrices. Esta estructura incluye las dimensiones de las matrices (`N`) y punteros a las matrices de entrada (`mA`, `mB`) así como al resultado (`mC`), facilitando el paso de múltiples datos a las funciones de manera organizada.


### Paralelismo con Pthreads

- **Distribución del Trabajo:** El uso de la biblioteca Pthreads permite al programa distribuir el trabajo de multiplicación de matrices entre varios hilos de ejecución. Esto significa que, en sistemas con múltiples núcleos de procesador, el programa puede realizar varias operaciones de multiplicación de manera simultánea, mejorando significativamente el rendimiento general.

