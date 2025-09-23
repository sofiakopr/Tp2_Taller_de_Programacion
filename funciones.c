#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

Bloque* crear_blockchain(){
    Bloque *blockchain = malloc(sizeof(Bloque));
    blockchain->primero = NULL;
    blockchain->ultimo = NULL;

    return blockchain;
}

Nodo* agregar_nodo(Bloque* blockchain, int primo){ //ver de ir borrando los elems de primos para ya tener los primos sig
    Nodo* nuevo_nodo = malloc(sizeof(Nodo));
    nuevo_nodo->msj = 'c';
    nuevo_nodo->id = &primo;
    nuevo_nodo->ant = blockchain->primero;
    nuevo_nodo->sig = NULL;

    if(blockchain->primero != NULL){
        blockchain->primero->sig = nuevo_nodo;
    }

    if(blockchain->ultimo == NULL){
        blockchain->ultimo = nuevo_nodo;
    }
    
    blockchain->ultimo = nuevo_nodo;
    return nuevo_nodo;
}

Nodo* crear_arbol(Nodo* nodo){ //por hacer
    return nodo;
}

/*con el argumento "nodo" se refiere a que le pasa el primer nodo de la blockchain
Nodo* alta(Nodo* nodo, int primo){ 
    nuevo_nodo = crear_nodo(nuevo_nodo, primo);
    for(int i  = 0; i < 3; i++){
        if(nodo->id_sig == NULL){
            Nodo* aux = nodo;
            nodo->id_sig = nuevo_nodo->id;
        }
    }
         


    return nodo;
}*/
