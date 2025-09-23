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
    printf("%d ",p[i]);
  }

  // Uso los números primos

  int indicadorPrimos = 0;
  Bloque* blockchain = crear_blockchain();
  blockchain = agregar_nodo(blockchain, p[0]);
  blockchain = agregar_nodo(blockchain, p[1]);
  blockchain = agregar_nodo(blockchain, p[2]);
  
  for(Nodo *nodo = blockchain->primero; nodo; nodo = nodo->sig){
    printf("\n%d\n", *(nodo->id)); 
    printf("%c\n", nodo->msj);
  }


  // IMPORTANTE: libero la memoria pedida para el arreglo de números primos
  free(p);
  free(blockchain);
  return 0;
}
