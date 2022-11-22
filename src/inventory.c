/**
 * @brief Implementa el inventario del jugador
 *
 * @file inventory.c
 * @author Carolina Monedero
 * @date 23-03-2021
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../include/set.h"
#include "../include/inventory.h"


/**
* @brief Estructura de datos Inventory
* @author Carolina Monedero Juzgado
* @date 23/03/2021
*/
struct _Inventory {
  Set* ids;     /*!<Conjunto de identificadores */
  int maxTam;    /*!<Tamaño del inventario*/
};

Inventory* inventory_create(int tam){
  Inventory* new_inv;

  new_inv = (Inventory*)malloc(sizeof(Inventory));
  if (!new_inv) return NULL;

  new_inv->ids = set_create();
  if (!new_inv->ids) return NULL;

  new_inv->maxTam = tam;

  return new_inv;
}

STATUS inventory_destroy(Inventory* inv){

  if (!inv) return ERROR;

  set_destroy(inv->ids);
  free(inv);

  return OK;
}

STATUS inventory_setId(Inventory* inv, Id id){
  int num;

  if (!inv || id == NO_ID) return ERROR;

  if (!set_add_id(inv->ids, id)) return ERROR;

  num = set_get_numIds(inv->ids);
  if (num == inv->maxTam) return ERROR;

  return OK;

}

STATUS inventory_setMaxTam(Inventory* inv, int tam){

  if (!inv || tam < 0) return ERROR;

  inv->maxTam = tam;

  return OK;
}

Set* inventory_getIds(Inventory* inv){

  if (!inv) return NULL;

  return inv->ids;
}

Id inventory_get_objectWithId(Inventory* inv, Id id){
  Id object;

  if (!inv || id == NO_ID || set_has_id(inv->ids, id) == FALSE) return NO_ID;

  object = set_getOneId(inv->ids, id);
  if (object == NO_ID) return NO_ID;

  return object;
}

int inventory_getMaxTam(Inventory* inv){

  if (!inv) return -1;

  return inv->maxTam;
}

void inventory_print(Inventory* inv){
  int num;

  if (!inv) return;

  fprintf(stdout, " --> Inventory:\n");

  num = set_get_numIds(inv->ids);
  if (num < 0)
    return;

  fprintf(stdout, "Objetos del inventario: ");
  set_print(inv->ids);

  fprintf(stdout, "\nCapacidad inventario: %d", inventory_getMaxTam(inv));
return;
}

BOOL inventory_hasId(Inventory* inv, Id id){

  if (!inv || id == NO_ID) return FALSE;

  if (set_has_id(inv->ids, id) == TRUE) return TRUE;

  return FALSE;

}

int inventory_getNumObjects(Inventory* inv){
  int num = 0;

  if (!inv) return -1;

  num = set_get_numIds(inv->ids);

  return num;

}
