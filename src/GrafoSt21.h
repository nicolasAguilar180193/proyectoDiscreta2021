#ifndef _GRAFOST_H
#define _GRAFOST_H


typedef unsigned int u32;

typedef struct VerticeSt{
    u32 nombre;
    u32 color;
    u32 grado;
    u32 etiqueta;
    u32 *vecinos;
} VerticeSt;

typedef VerticeSt* Vertice;

typedef struct GrafoSt {
    u32 cantidadVertices;
    u32 cantidadLados;
    Vertice vertices;
    Vertice *orden;
} GrafoSt;



#endif