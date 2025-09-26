#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

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

/*int* crear_arbol(int* bc_federada, int cant_bc){
    printf("hola entre a crear arbol\n");

    int cant_hojas = cant_bc;

    if((cant_hojas % 2 != 0) || (cant_hojas % 2 == 0 && ((cant_hojas / 2) % 2) != 0)){
        cant_hojas ++;
    }

    int cant_nodos = (2*cant_hojas)-1;
    int *final_lista  = &cant_nodos;
    int aux_cant_nodos = *final_lista;

    int *arbol = malloc(sizeof(int*) * cant_nodos);

    if(cant_bc != cant_hojas){
        int j = (cant_hojas - cant_bc);
        for(; j > 0; aux_cant_nodos --, j --){
            arbol[aux_cant_nodos] = 1;
        }
        
        cant_bc --;
        while(cant_bc >= 0){
            arbol[aux_cant_nodos] = bc_federada[cant_bc];
            aux_cant_nodos --;
            cant_bc --;
        }

        while(aux_cant_nodos >= 0){
            arbol[aux_cant_nodos] = 0;
            aux_cant_nodos --;
        }
    }
    else{
        for(int i = cant_bc; i > 0; aux_cant_nodos--, i --){
            arbol[aux_cant_nodos] = bc_federada[i]; 
        }

        while(aux_cant_nodos >= 0){
            arbol[aux_cant_nodos] = 0;
            aux_cant_nodos --;
        }
    }

    while(cant_nodos >= 0){
        int aux_cant_hojas = cant_hojas;
        for(int j = (aux_cant_hojas/2-1), i = aux_cant_hojas-1; j >= 0; i--, j--){
           arbol[j] = arbol[i*2 +1]*arbol[i*2 +2];
        }
        
    }

    for(int i = 0; i <= cant_nodos; i++){ //muestra el arbol
      printf("%d\n", arbol[i]);
    }

    return arbol;  
*/

    
int* crear_arbol(int* bc_federada, int cant_bc){
    int *arbol = malloc((sizeof(int*)) * (cant_bc * 2));
    int nodos_totales = 2*cant_bc;
    int* aux;

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
    for(int i = 0; i <= cant_bc*2; i++){ //printea todo el arbol
      printf("%d\n", arbol[i]);
    }

    return arbol;
}

int* alta(int* bc_federada, int nro_de_bc, DE_Nodo lista[], int primo){
    int* aux = bc_federada;

    lista[nro_de_bc] = agregar_nodo(lista[nro_de_bc], primo);
    aux[nro_de_bc] = lista[nro_de_bc].ult->id;

    return crear_arbol(aux, lista[nro_de_bc].cant_nodos);
    
}

int* actualizacionNodo(int bc_federada[], DE_Nodo list_nodo[], int id, int cant_bc, int nro_bc, int p[], int ultPrimo){

    printf("id ultimo: %d\n", list_nodo[nro_bc].ult->id);

    if(list_nodo[nro_bc].ult->id == id){
        list_nodo[nro_bc].ult->id = p[ultPrimo];
    }
    else{
        if(list_nodo[nro_bc].cant_nodos % 2 != 0/*(list_nodo[nro_bc].ult->id - id) <= (id - list_nodo[nro_bc].prim->id)*/){
            do{
                list_nodo[nro_bc].prim = list_nodo[nro_bc].prim->sig;
            }while(list_nodo[nro_bc].prim->sig->id != id);
            list_nodo[nro_bc].prim->sig = list_nodo[nro_bc].prim;
        }
        else{
            Nodo* aux = list_nodo[nro_bc].prim;
            do{
                aux = list_nodo[nro_bc].prim->sig;
            }while(aux->ant->id != id);

            list_nodo[nro_bc].ult = aux;
            //list_nodo[nro_bc].ult->sig = list_nodo[nro_bc].ult;
        }

        for(int i = 0; i < list_nodo[nro_bc].cant_nodos; i ++, ultPrimo++){
            printf("holi\n");
            //list_nodo[nro_bc].ult->ant->id = p[ultPrimo]; 
            list_nodo[nro_bc] = agregar_nodo(list_nodo[nro_bc], p[ultPrimo]);
        }
    }

    bc_federada[nro_bc] = list_nodo[nro_bc].ult->id;

    return crear_arbol(bc_federada, list_nodo[nro_bc].cant_nodos);
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

int validacionSubconjunto(DE_Nodo lista[], int bc_fedrada[], int cant_bc, int bc1, int bc2, int arbol[]){
    int nro_validacion = 1;
    int producto_aux = 1;

    for(int i = cant_bc*2; i > 0; i --){
        if(arbol[i] != 1){
            for(int j = i; j > bc1; j --){
                nro_validacion *= arbol[j];
                printf("\n%i", arbol[j]);
            }
            i=0;            
        }
    }

    for(int i = bc1; i <= bc2; i ++){
        producto_aux *= bc_fedrada[i];
    }

    printf("\n%i %i", producto_aux, nro_validacion);

    if(nro_validacion == producto_aux){
        return nro_validacion;
    }
    else{
        return 1;
    }
}

void destruir_bc(Nodo *nodo) {
  if(nodo != NULL) {
    Nodo *nodo_a_eliminar = nodo;
    destruir_bc(nodo->sig);
    free(nodo_a_eliminar);
  }
}
