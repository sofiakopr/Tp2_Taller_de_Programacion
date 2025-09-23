#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "generador_primos.h"
#include "funciones.h"

int main() {
  // Genero y muestro los primeros 100 números primos
  int *p = primos(100);
  for(int i = 0; i < 100; i++){
    printf("%d ",p[i]);
  }

  // Uso los números primos

  Bloque* blockchain = crear_blockchain();

  for(int i = 0; i < 3; i++){
    Nodo* nodo = agregar_nodo(blockchain, p[i]);
    printf("\n%d", *(nodo->id)); //aa chequear si nodo sig es posta nodo sig
    p[i] = 0;
  }
  



  // IMPORTANTE: libero la memoria pedida para el arreglo de números primos
  free(p);
  return 0;
}
