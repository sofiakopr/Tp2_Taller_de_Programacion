#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "generador_primos.h"
#include "funciones.h"

int main() {
  setbuf(stdout, NULL);
  // Genero y muestro los primeros 100 números primos
  int *p = primos(100);
  for(int i = 0; i < 100; i++){
   // printf("%d ",p[i]);
  }

  int indicador = 0;
  int* Arrblockchain = malloc((sizeof(int)) * 3); 
  Bloque* blockchain = crear_blockchain();
  blockchain = agregar_nodo(blockchain, p[0]);
  blockchain = agregar_nodo(blockchain, p[1]);
  blockchain = agregar_nodo(blockchain, p[2]);
  Arrblockchain[indicador] = *(blockchain->ultimo->id);
  indicador+=1;
  
  Bloque* blockchain2 = crear_blockchain();
  blockchain2 = agregar_nodo(blockchain2, p[3]);
  blockchain2 = agregar_nodo(blockchain2, p[4]);
  blockchain2 = agregar_nodo(blockchain2, p[5]);
  Arrblockchain[indicador] = *(blockchain2->ultimo->id);
  indicador+=1;

  Bloque* blockchain3 = crear_blockchain();
  blockchain3 = agregar_nodo(blockchain3, p[6]);
  blockchain3 = agregar_nodo(blockchain3, p[7]);
  blockchain3 = agregar_nodo(blockchain3, p[8]);
  Arrblockchain[indicador] = *(blockchain3->ultimo->id);
  indicador+=1;

  int* arbol = crear_arbol(Arrblockchain, indicador);

  for(Nodo *nodo = blockchain->primero; nodo; nodo = nodo->sig){
    printf("\n%d\n", *(nodo->id)); 
    printf("%c\n", nodo->msj);
  }

  for(int i = 0; i <= indicador*2; i++){
    //printf("%d\n", Arrblockchain[i]);
    printf("%d\n", arbol[i]);
  }


  free(p);
  free(blockchain);
  return 0;
}
