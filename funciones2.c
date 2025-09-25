#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

Nodo** crear_blockchain(){
    int size = 3; //chequear de hacerlo general
    Nodo **blockchain = calloc(size, sizeof(Nodo));
    //blockchain->primero = NULL;
    //blockchain->ultimo = NULL;

    return blockchain;
}

Nodo* agregar_nodo(Nodo** blockchain, int primo, int indiceNodo){ //ver de ir borrando los elems de primos para ya tener los primos sig
    Nodo* nuevo_nodo = malloc(sizeof(Nodo));
    nuevo_nodo->msj = 'c';
    nuevo_nodo->id = &primo;
    nuevo_nodo->ant = NULL;
    nuevo_nodo->sig = NULL;

    if(blockchain[indiceNodo] == NULL){
        blockchain[indiceNodo] = nuevo_nodo;
    }

    if(blockchain[indiceNodo-1] != NULL && blockchain[indiceNodo-1]->sig == NULL && indiceNodo > 0){
        blockchain[indiceNodo-1]->sig = nuevo_nodo;
        nuevo_nodo->ant = blockchain[indiceNodo-1];
    }
    
    /*if(blockchain->primero != NULL){
        blockchain->primero->sig = nuevo_nodo;
    }

    if(blockchain->ultimo == NULL){
        blockchain->ultimo = nuevo_nodo;
    }
    
    blockchain->ultimo = nuevo_nodo;*/

    return nuevo_nodo;
}

int* crear_arbol(int* Arrblockchain, int indicador){ 
    int *arbol = malloc((sizeof(int)) * (indicador * 2)); //el 3 representa la cant de blockchains q hay en el arreglo, ver de una manera en q se pueda el tamaño sin poner un numero
    //chequear si *i* es cierto para arboles mas grandes (no lo es pero ver como hacerlo)
    int i = indicador*2;

    if(indicador % 2 != 0){
        for(i; i > 0; i = i / 2){ 
            if(i > indicador){
                arbol[i] = 1; //el primer elem en 1 es solo valido para 3 blockchains, ver como hacerlo general; agregar un 1 hasta q se llegue a la cant justa de numeros?
                for(int j = i-1, aux = indicador-1; j >= indicador; j--, aux--){
                    arbol[j] = Arrblockchain[aux];
                }
            }
            if(i <= indicador){
                for(int ayuda = i-1; ayuda >= 0; ayuda--){
                    arbol[ayuda] = arbol[ayuda*2 + 1] * arbol[ayuda*2 + 2];
                }
            }
        }
    }
    else{  
        for(i; i > 0; i = i / 2){ 
            if(i > indicador){
                for(int j = i, aux = indicador-1; j >= indicador; j--, aux--){
                    arbol[j] = Arrblockchain[aux];
                }
            }
            if(i <= indicador){
                for(int ayuda = i-1; ayuda >= 0; ayuda--){
                    arbol[ayuda] = arbol[ayuda*2 + 1] * arbol[ayuda*2 + 2];
                }
            }
        }
    } //RECORDAR CAMBIAR NOMBRES VARIABLES; SINO NO SE ENTIENDE NADA!!!!!!!!!!!!11

    return arbol;
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

Nodo** actualizacionNodo(Nodo** blockchain, char msj, int indice, int primo){

    //(*blockchain[indice]->msj) = msj;
    //(*blockchain[indice]->id) = primo;

    


    return blockchain;
}
