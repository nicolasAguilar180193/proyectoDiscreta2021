#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "RomaVictor.h"

// void test(void) {
//     printf("dale ctm \n\n");
//     return;
// }


Grafo ConstruccionDelGrafo() {
    Grafo G = calloc(1 , sizeof( GrafoSt));
    if(G == NULL) {
        printf("Error al alocar memoria.\n");
        return G;
    }

    int  n, m;
    char *line = calloc(80,sizeof(char));

    do { /* Salta los comentarios */
        line = fgets(line, 80, stdin);
    } while(line != "" && line[0] == 'c' && !feof(stdin));
    sscanf(line,"p edge %u %u ", &n,&m);
    printf("You n: %d", n);
    printf("\n");
    printf("You m: %d", m);
    printf("\n");

    G->Vertices = n; // Cantidad de vertices
    G->Lados = m; // Cantidad de lados.
    G->Colores = n; // Inicializa la cantidad de colores igual a la cantidad de vertices.
    return G;
}