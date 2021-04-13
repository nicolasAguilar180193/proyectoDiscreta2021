#include "RomaVictor.h"


bool checkFormat(int i) {
    if (i != 2) {
        // printf("Error de formato del archivo.\n");
        return false;
    }
    return true;
}


Grafo AgegarVertice(Grafo G, u32 nombre, int posicionVertice ) {
    G->vertices[posicionVertice].nombre = nombre;
    G->vertices[posicionVertice].color = posicionVertice + 1;
    G->vertices[posicionVertice].etiqueta = posicionVertice;
    G->vertices[posicionVertice].grado = 0;
    G->orden[posicionVertice] = &G->vertices[posicionVertice];
    G->vertices[posicionVertice].vecinos = NULL;

    return G;
}

Grafo AgegarVecino(Grafo G, int posicionVertice, int vecino) { 
    G->vertices[posicionVertice].grado++;
    if(G->vertices[posicionVertice].vecinos == NULL){
        G->vertices[posicionVertice].vecinos = (u32*)calloc(1, sizeof(u32));
        if(G->vertices[posicionVertice].vecinos == NULL){
            printf("Error al intentar reservar memoria \n");
        }
        G->vertices[posicionVertice].vecinos[0] = vecino;
    } else {
        G->vertices[posicionVertice].vecinos = (u32*)realloc(G->vertices[posicionVertice].vecinos, G->vertices[posicionVertice].grado * sizeof(u32));
        if(G->vertices[posicionVertice].vecinos == NULL){
            printf("Error al intentar reservar memoria \n");
        }
        u32 posVecino = G->vertices[posicionVertice].grado - 1;
        G->vertices[posicionVertice].vecinos[posVecino] = vecino;
    }
    return G;
}


void DestruccionDelGrafo(Grafo G) {
    u32 i = 0;
    while (i < G->cantidadVertices) {
        free(G->vertices[i].vecinos);
        i++;
    }
    free(G->orden);
    free(G->vertices);
    free(G);
}

Grafo ConstruccionDelGrafo() {
    Grafo G = calloc(1 , sizeof( GrafoSt));
    if(G == NULL) {
        printf("Error al intentar reservar memoria \n");
        return G;
    }

    u32 n, m;
    char *line = calloc(80, sizeof(char));

    do { /* Para ignorar comentarios */
        line = fgets(line, 80, stdin);
    } while(line[0] == 'c' && !feof(stdin));

    int aux = sscanf(line,"p edge %u %u ", &n,&m);
    assert(checkFormat(aux));

    G->cantidadVertices = n;
    G->cantidadLados = m;

    printf("Vertice cantidad: %d\n", G->cantidadVertices );

    G->orden = calloc(n, sizeof(VerticeSt));
    if(G->orden == NULL) {
        printf("Error al intentar reservar memoria \n");
        free(G);
        return NULL;
    }


    G->vertices = calloc(n, sizeof(struct VerticeSt));

    if(G->vertices == NULL) {
        printf("Error al intentar reservar memoria \n");
        free(G->orden);
        free(G);
        return NULL;
    }

    // u32 vecinos[m*2];
    // G->verticesecinos = vecinos;

    // G->verticesecinos[0] = 2;

    // // printf("el primer vecino %d es %d", 0, G->verticesecinos[0]);
    // // printf("\n");

    hashTable hash = newHash(n); //Hash para optimizar la carga.

    u32 verticesCargados = 0;
    u32 ladosCargados = 0;
    int x, y;

    while ( verticesCargados < G->cantidadVertices || ladosCargados < G->cantidadLados) {
        if (!feof(stdin)) {
            line = fgets(line, 80, stdin);
            aux = sscanf(line, "e %u %u ", &x ,&y);
            assert(checkFormat(aux));
            // Posiciones de los vertices en el grafo G, si es que existen.
            int posicionVertice1, posicionVertice2;
            posicionVertice1 = searchElemntHash(hash, x);
            posicionVertice2 = searchElemntHash(hash, y);

            // Ninguno de los vertices fue agregado
            if (posicionVertice1 == NOT_ADDED && posicionVertice2 == NOT_ADDED)
            {
                // // printf("if 1 \n");
                posicionVertice1 = verticesCargados;
                posicionVertice2 = verticesCargados + 1;
                G = AgegarVertice(G, x, posicionVertice1);
                hash = insertElemntHash(hash, x, posicionVertice1);
                // printf("Vertice numero???????: %d \n", verticesCargados );
                G = AgegarVecino(G, posicionVertice1 , posicionVertice2);

                G = AgegarVertice(G, y, posicionVertice2);
                // printf("Vertice numereeeee: %d \n", verticesCargados );
                hash = insertElemntHash(hash, y, posicionVertice2);
                G = AgegarVecino(G, posicionVertice2 , posicionVertice1);
                verticesCargados++;
                verticesCargados++;
            }
            // posicionVertice1 fue agregado posicionVertice2 no
            else if (posicionVertice1 != NOT_ADDED && posicionVertice2 == NOT_ADDED)
            {
                // // printf("if 2 \n");
                posicionVertice2 = verticesCargados;
                G = AgegarVertice(G, y, posicionVertice2);
                hash = insertElemntHash(hash, y, posicionVertice2);
                G = AgegarVecino(G, posicionVertice2, posicionVertice1);
                G = AgegarVecino(G, posicionVertice1, posicionVertice2);
                verticesCargados++;
            }
            // posicionVertice1 no fue agregado pos 2 si
            else if (posicionVertice1 == NOT_ADDED && posicionVertice2 != NOT_ADDED)
            {
                // // printf("if 3 \n");
                posicionVertice1 = verticesCargados;
                G = AgegarVertice(G, x, posicionVertice1);
                hash = insertElemntHash(hash, x, posicionVertice1);
                G = AgegarVecino(G, posicionVertice1, posicionVertice2);
                G = AgegarVecino(G, posicionVertice2, posicionVertice1);
                verticesCargados++;
            }
            // ambos ya fueron agregados
            else if (posicionVertice1 != NOT_ADDED && posicionVertice2 != NOT_ADDED)
            {
                // // printf("if 4 \n");
                G = AgegarVecino(G, posicionVertice1, posicionVertice2);
                G = AgegarVecino(G, posicionVertice2, posicionVertice1);
            }
            ladosCargados++;


        } else {
            printf("Error. No coinciden la cantidad de lados y vertices\n");
            DestruccionDelGrafo(G);
            break;
        }
    }
    destroyHash(hash);
    free(line);

    return G;

}

// Devuelve el nombre del vecino numero j del vertice numero i en el orden guardado en ese momento en G
u32 NombreVecino(u32 j,u32 i,Grafo G) {
    if(i >= G->cantidadVertices || j >= G->vertices[i].grado) {
        return MAX_U32;
    }

    u32 posicionVecino = G->orden[i]->vecinos[j];

    return G->vertices[posicionVecino].nombre;
}