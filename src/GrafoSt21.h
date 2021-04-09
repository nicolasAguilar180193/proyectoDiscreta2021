#ifndef _GRAFOST_H
#define _GRAFOST_H


typedef unsigned int u32;

typedef struct VerticeSt{
    u32 nombre;
    u32 color;
    u32 grado;
    u32 etiqueta; //Etiqueta del vertice (igual al indice en el arreglo principal)
    list_t vecinos;
    // u32 primerVecino;
} VerticeSt;

typedef VerticeSt* Vertice;

typedef struct GrafoSt {
    u32 cantidadVertices;
    u32 cantidadLados;
    Vertice vertices;
    // u32 *vecinos; // array de todos los vecinos de todos los vertices
} GrafoSt;






#endif