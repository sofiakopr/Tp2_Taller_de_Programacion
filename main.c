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

  int cant_bc;

  printf("\ncantidad de bc: ");
  scanf("%i", &cant_bc);
  
  DE_Nodo list_nodo[cant_bc]; //cambiar nombre a "lista_bcs"? para q sea mas intuitivo?
  
  for(int i = 0; i < cant_bc; i ++){
    list_nodo[i].prim = NULL;
    list_nodo[i].ult = NULL;
  }

  int ultPrimo = 0;
  int* bc_federada = malloc((sizeof(int)) * cant_bc); 
  
  for(int i = 0; i < cant_bc; i ++){
    printf("\nBlockchain nro %i", i+1);

    int cant_nodos; 
    printf("\n¿Cuántos nodos tiene esta blockchain?: ");
    scanf("%i", &cant_nodos);

    for(int j = 0; j < cant_nodos; j ++){
      list_nodo[i] = agregar_nodo(list_nodo[i], p[ultPrimo]);
      list_nodo[i].cant_nodos = cant_nodos;
      ultPrimo += 1;
    }

    bc_federada[i] = (list_nodo[i].ult)->id;
  }

  getchar();
  int* arbol = crear_arbol(bc_federada, cant_bc);

  int modificar;
  int nro_bc;
  printf("\nAcción a realizar? [Alta(1), Actualizar Nodo(2), Validación(3), Validación Conjunto (4), Nada(0)]\n");
  scanf("%i", &modificar);

  if(modificar == 1){
    
    printf("\nNro de bc a modificar: ");
    scanf("%i", &nro_bc);

    arbol = alta(bc_federada, nro_bc, list_nodo, p[ultPrimo]);
  }
  else if(modificar == 2){
    int id, nro_del_bc;

    printf("\nNro de bc a modificar: ");
    scanf("%i", &nro_bc);

    printf("\nId del nodo a actualizar: ");
    scanf("%i", &id);

    arbol = actualizacionNodo(bc_federada, list_nodo, id, cant_bc, nro_bc, p, ultPrimo);
  }
  else if(modificar == 3){
    
    printf("\nNro de bc a validar: ");
    scanf("%i", &nro_bc);

    if(validacion(bc_federada, nro_bc, list_nodo, arbol) != 1){
      printf("La blockchain es valida!!!\n");
    }
    else{
      printf("La blockchain no es valida :(\n");
    }
  }
  else if(modificar == 4){
    int bc1, bc2;

    printf("\nRango de bc a validar: ");
    scanf("%i %i", &bc1, &bc2);

    printf("\n%i %i", bc1, bc2);

    if(validacionSubconjunto(list_nodo, bc_federada, cant_bc, bc1, bc2, arbol) != 1){
      printf("\nSí pertenece :D");
    }
    else{
      printf("\nNo pertenece... FUERA!!!");
    }
  }

  destruir_bc(list_nodo->prim);    
  free(p);
  free(arbol);
  free(bc_federada);
  return 0;
}
