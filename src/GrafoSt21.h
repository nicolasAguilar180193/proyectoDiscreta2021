#ifndef _GRAFOST_H
#define _GRAFOST_H

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int u32;

typedef struct GrafoSt {
    u32 Vertices;  // Cantidad de vertices.
    u32 Lados;  // Cantidad de lados.
    u32 Colores; // Cantidad de colores en coloreo actual.
    // VerticeP V; // Arreglo de vertices.
    // VerticeP *ordenproc;  // Orden de proceso de los vertices para Greedy.
} GrafoSt;






#endif