#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stddef.h>

typedef struct Nodo_{
    char msj;
    int* id;
    struct Nodo_* ant;
    struct Nodo_* sig;
}Nodo;

typedef struct Bloque_{
    Nodo* primero;
    Nodo* ultimo;
}Bloque;

Bloque* crear_blockchain(); //inicializo una blockchain

Nodo* agregar_nodo(Bloque* blockchain, int primo); //agrego un nodo a una blockchain

Nodo* crear_arbol(Nodo* nodo); //crear arbol de blockchain

Nodo* alta(Nodo* blockchain, Nodo* nodo, int primo); //AGREGAR un nodo

Nodo* actualizacionNodo(Nodo* blockchain, char msj); //actualizar el contenido de un nodo y cambiar su id

Nodo* validacion(Nodo* blockchain); //validar formato de blockchain

Nodo* validacionConjunto(Nodo* blockchain, int nroValidacion); //LA PRIMER BLOCKCHAIN DEL MUNDO!!!

#endif

//1. el arbol no es un arbol (osea si es) es un arreglo, al igual que las blockchains
//2. lista doblemente enlazada para los nodos 
//3. BLOQUE NODO = BLOQUE