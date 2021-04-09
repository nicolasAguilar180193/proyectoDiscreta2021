#include "RomaVictor.h"


bool checkFormat(int i) {
    if (i != 2) {
        printf("Error de formato del archivo.\n");
        return false;
    }
    return true;
}


Grafo AgegarVertice(Grafo G, u32 nombre , int vecino, int vertice ) {
    G->vertices[vertice].nombre = nombre;
    G->vertices[vertice].color = vertice + 1; 
    G->vertices[vertice].etiqueta = vertice;
    G->vertices[vertice].grado = 1;

    return G;
}


Grafo ConstruccionDelGrafo() {
    Grafo G = calloc(1 , sizeof( GrafoSt));
    if(G == NULL) {
        printf("Error al alocar memoria.\n");
        return G;
    }

    int n, m;
    char *line = calloc(80, sizeof(char));

    do { /* Para ignorar comentarios */
        line = fgets(line, 80, stdin);
    } while(line[0] == 'c' && !feof(stdin));

    int aux = sscanf(line,"p edge %u %u ", &n,&m);
    assert(checkFormat(aux));

    G->cantidadVertices = n;
    G->cantidadLados = m;

    G->vertices = calloc(n, sizeof(struct VerticeSt));

    if(G->vertices == NULL) {
        printf("Error al alocar memoria.\n");
        free(G);
        return NULL;
    }

    // u32 vecinos[m*2];
    // G->verticesecinos = vecinos;

    // G->verticesecinos[0] = 2;

    // printf("el primer vecino %d es %d", 0, G->verticesecinos[0]);
    // printf("\n");

    hashTable hash = newHash(n); //Hash para optimizar la carga.

    u32 verticesCargados = 0;
    u32 ladosCargados = 0;

    while ( verticesCargados < G->cantidadVertices || ladosCargados < G->cantidadLados) {
        if (!feof(stdin)) {

            line = fgets(line, 80, stdin);
            aux = sscanf(line, "e %u %u ", &n ,&m);
            assert(checkFormat(aux));
            // Posiciones de los vertices en el grafo G, si es que existen.
            int pos1, pos2;
            pos1 = searchElemntHash(hash, n);
            pos2 = searchElemntHash(hash, m);

            if (pos1 == NOT_ADDED && pos2 == NOT_ADDED) 
            {
                G = AgegarVertice(G, n, verticesCargados+1, verticesCargados);
                hash = insertElemntHash(hash, n, verticesCargados); 

                G = AgegarVertice(G, m, verticesCargados-1, verticesCargados);
                hash = insertElemntHash(hash, m, verticesCargados);
                verticesCargados++;

            } else if (pos1 != NOT_ADDED && pos2 == NOT_ADDED) 
            {
                G = AgegarVertice(G, m, pos1, verticesCargados);
                hash = insertElemntHash(hash, m, verticesCargados); 
                G->vertices[pos1].vecinos = listAppend(G->vertices[pos1].vecinos, verticesCargados);
                G->vertices[pos1].grado++;
                verticesCargados++;
            
            } else if (pos1 == NOT_ADDED && pos2 != NOT_ADDED) 
            {
                G = AgegarVertice(G, n, pos2, verticesCargados);
                hash = insertElemntHash(hash, n, verticesCargados);
                G->vertices[pos2].vecinos = listAppend(G->vertices[pos2].vecinos, verticesCargados);
                G->vertices[pos2].grado++;
                verticesCargados++;

            } else if (pos1 != NOT_ADDED && pos2 != NOT_ADDED) 
            {
                G->vertices[pos1].vecinos = listAppend(G->vertices[pos1].vecinos, pos2);
                G->vertices[pos2].vecinos = listAppend(G->vertices[pos2].vecinos, pos1);
                G->vertices[pos1].grado++;
                G->vertices[pos2].grado++;
            }
            ladosCargados++;


        } else {
            printf("Error. No coinciden la cantidad de lados y vertices\n");
            DestruccionDelGrafo(G);
            break;
        }
    }


    return G;
}