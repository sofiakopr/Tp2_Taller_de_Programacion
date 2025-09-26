#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stddef.h>

typedef struct Nodo_{
    char msj;
    int id;
    struct Nodo_* ant;
    struct Nodo_* sig;
}Nodo;

typedef struct Bloque_{
    Nodo* prim;
    Nodo* ult;
    int cant_nodos;
}DE_Nodo;

DE_Nodo agregar_nodo(DE_Nodo lista, int primo); //agrego un nodo a una blockchain

int* crear_arbol(int* bc_federada, int cant_bc); //crear arbol de blockchain //ver si es doble puntero x lista de blockchains

int* alta(int bc_federada[], int nro_de_bc ,DE_Nodo lista[], int primo); //AGREGAR un nodo

int* actualizacionNodo(int bc_federada[], DE_Nodo list_nodo[], int id, int cant_bc, int nro_bc, int p[], int ultPrimo); //actualizar el contenido de un nodo y cambiar su id

int validacion(int* bc_federada, int nro, DE_Nodo lista[], int* arbol); //validar formato de blockchain

int validacionSubconjunto(DE_Nodo lista[], int bc_fedrada[], int cant_bc, int bc1, int bc2, int* arbol); //LA PRIMER BLOCKCHAIN DEL MUNDO!!!

void destruir_bc(Nodo *nodo);

#endif

//1. el arbol no es un arbol (osea si es) es un arreglo, al igual que las blockchains
//2. lista doblemente enlazada para los nodos 
//3. BLOQUE NODO = BLOQUE