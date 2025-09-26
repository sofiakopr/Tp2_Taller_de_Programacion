#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>

DE_Nodo agregar_nodo(DE_Nodo lista, int primo){ //ver de ir borrando los elems de primos para ya tener los primos sig
    Nodo* nuevo_nodo = malloc(sizeof(Nodo));
    nuevo_nodo->msj = 'c';
    nuevo_nodo->id = primo;
    nuevo_nodo->ant = NULL;
    nuevo_nodo->sig = NULL;

    if(lista.ult == NULL){
        lista.prim = nuevo_nodo;
        lista.ult = nuevo_nodo;
    }
    else{
        lista.ult->sig = nuevo_nodo;
        nuevo_nodo->ant = lista.ult;
    }
    
    lista.ult = nuevo_nodo;
    return lista;
}

int* crear_arbol(int* bc_federada, int cant_bc){ 
    int *arbol = malloc((sizeof(int)) * (cant_bc * 2));
    //chequear si *nodos_totales* es cierto para arboles mas grandes (no lo es pero ver como hacerlo)
    int nodos_totales = cant_bc*2;

    if(cant_bc % 2 != 0){ //chequeo si la cantidad de blockchains es multiplo de 2 o no
        for(nodos_totales; nodos_totales > 0; nodos_totales = nodos_totales / 2){ 
            if(nodos_totales > cant_bc){
                arbol[nodos_totales] = 1; //el 1 en el primer elem solo es valido para 3 blockchains; agregar 1's hasta igualar con el indicador? 
                for(int j = nodos_totales-1, aux = cant_bc-1; j >= cant_bc; j--, aux--){ //ingreso solo los id de los ultimos nodos de c/blockchain
                    arbol[j] = bc_federada[aux];
                }
            }
            if(nodos_totales <= cant_bc){ //una vez que la cantidad de nodos totales es menor o igual a la cant de blockchains, multiplico los id de cada una de ellas
                for(int ayuda = nodos_totales-1; ayuda >= 0; ayuda--){
                    arbol[ayuda] = arbol[ayuda*2 + 1] * arbol[ayuda*2 + 2];
                }
            }
        }
    }else{  
        for(nodos_totales; nodos_totales > 0; nodos_totales = nodos_totales / 2){ 
            if(nodos_totales > cant_bc){
                for(int j = nodos_totales, aux = cant_bc-1; j >= cant_bc; j--, aux--){
                    arbol[j] = bc_federada[aux];
                }
            }
            if(nodos_totales <= cant_bc){
                for(int ayuda = nodos_totales-1; ayuda >= 0; ayuda--){
                    arbol[ayuda] = arbol[ayuda*2 + 1] * arbol[ayuda*2 + 2];
                }
            }
        }
    }
    for(int i = 0; i <= nodos_totales; i++){ //muestra el arbol
      printf("%d\n", arbol[i]);
    }

    return arbol;
}

int* alta(int* bc_federada, int nro_de_bc, DE_Nodo lista[], int primo){

    lista[nro_de_bc] = agregar_nodo(lista[nro_de_bc], primo);
    bc_federada[nro_de_bc] = lista[nro_de_bc].ult->id;

    int cant_bc = strlen(bc_federada);

    return crear_arbol(bc_federada, cant_bc);
    
}

DE_Nodo* actualizacionNodo(DE_Nodo* lista_bcs, int id, int cant_bc, char msj, int* p, int ultPrimo){

    Nodo* nuevo_nodo = malloc(sizeof(Nodo)); //chequear si podemos hacer de no hacer todo esto devuelta
    
    for(int i = 0; i < cant_bc; i++){

        Nodo* aux = lista_bcs[i].ult;
        int nodosPorActualizar = lista_bcs[cant_bc].cant_nodos;

        for(int j = 0; j < lista_bcs[cant_bc].cant_nodos; j++, aux = aux->ant){
            if(aux->id == id){
                nuevo_nodo = aux; 
                nuevo_nodo->msj = msj;          
                nuevo_nodo->id = p[ultPrimo];   
                nuevo_nodo->ant = aux->ant;     
                nuevo_nodo->sig = aux->sig;
                nuevo_nodo->ant->sig = nuevo_nodo;
                nuevo_nodo->sig->ant = nuevo_nodo;
                for(int n = 0; n < nodosPorActualizar; i++, aux = aux->ant){
                    aux->ant->id = p[ultPrimo++];
                    ultPrimo+=1;
                }
                lista_bcs[i].prim = aux;
            }
            nodosPorActualizar-=1;
        }
    }

    return lista_bcs;
}


int validacion(int* bc_federada, int indiceBc, DE_Nodo lista[], int* arbol){

    Nodo* aux_nodo = lista[indiceBc].ult;
    int producto = 1;

    while(aux_nodo->sig != NULL){
        if(aux_nodo->id > aux_nodo->sig->id){
            return 1;
        }
        else{
            aux_nodo = aux_nodo->sig;
        }
    }

    for(int i = 0; i < lista[indiceBc].cant_nodos; i ++){
        producto *= bc_federada[i];
    }

    printf("producto: %d\n", producto);
    if(producto == arbol[0]){
        return producto;
    }
    else{
        return 1;
    }
}