/**
 * @brief Define un conjunto
 *
 * @file set.c
 * @author Carolina Monedero Juzgado
 * @version 1.0
 * @date 22-02-2021
 */

#include "../include/set.h"

/**
* @brief Estructura de datos Set
* @author Carolina Monedero Juzgado
* @date 22/02/2021
*/
struct _Set{
  Id ids[MAX_IDS_PER_SET]; /*!<Array donde se guardan los identificadores*/
  int num_ids;             /*!<Número de identificadores que hay en el conjunto*/
};

Set *set_create() {
  Set *set;
  int i;

  set = (Set*)malloc(MAX_IDS_PER_SET*sizeof(Set));
  if (!set)
    return NULL;

  set->num_ids = 0;

  for(i=0; i < MAX_IDS_PER_SET; i++)
    set->ids[i] = -1;

  return set;
}

STATUS set_destroy(Set *set){

  if (!set) return ERROR;

  free(set);

  return OK;

}

STATUS set_add_id(Set *set, Id id){
  int i;
  int num;

  if (!set || id == NO_ID || set_full(set) == TRUE) return ERROR;

  if(set_empty(set) == TRUE){
    set->num_ids++;
    set->ids[0] = id;
    return OK;
  }

  num = set_get_numIds(set);

  for(i=0; i < num; i++){ /*Comprueba si el identificador ya estaba en el conjunto*/
    if (set->ids[i] == id){
      return ERROR;
    }
  }

  set->ids[i] = id;
  set->num_ids++;
  return OK;

}

STATUS set_del_id(Set *set, Id id){
  int i;
  int num;

  if (!set || id == NO_ID || set_empty(set) == TRUE) return ERROR;

  num = set_get_numIds(set);

  for(i=0; i < num; i++){ /*Recorre el conjunto y elimina el elemento cuyo id se ha pasado como argumento*/
    if (set->ids[i] == id){
      set->ids[i] = set->ids[num-1];
      set->num_ids--;
      return OK;
    }
  }

  return ERROR; /*Si no encuentra el elemento, ERROR*/

}

void set_print(Set *set){
  int i;
  int num;

  if (!set) return;

  num = set_get_numIds(set);
  if (num == 0){
    fprintf(stdout, "El conjunto esta vacio\n");
    return;
  }

  fprintf(stdout, "Numero de identificadores del conjunto: %d", num);
  fprintf(stdout, "Elementos del conjunto: ");

  for(i=0; i < set_get_numIds(set); i++)
    fprintf(stdout, "%ld ", set->ids[i]);

  return;
}

BOOL set_full(Set *set){

  if (!set) return FALSE;

  if (set->num_ids == MAX_IDS_PER_SET) return TRUE;

  return FALSE;
}

BOOL set_empty(Set *set){

  if (!set) return TRUE;

  if (set_get_numIds(set) == 0)
    return TRUE;

  return FALSE;

}

int set_get_numIds(Set *set){

  if (!set) return -1;

  return set->num_ids;

}

int set_find_gap(Set *set){
  int i;
  int num;

  if(!set || set_full(set)== TRUE) return -1;

  num = set_get_numIds(set);
  if (num == 0)
    return num;

  for(i=0; i < num; i++){
    if (set->ids[i] == -1)
      return i;
  }
  return i++;
}

Id* set_getIds(Set *set){

  if (!set) return NULL;

  return set->ids;

}

BOOL set_has_id(Set * s, Id id){

  int i;

  if(!s || id == NO_ID) return FALSE;

  for(i=0; i < set_get_numIds(s); i++){
    if(s->ids[i] == id) return TRUE;
  }

  return FALSE;
}

Id set_getOneId(Set* set, Id id){
  int i;

  if (!set || id == NO_ID || set_has_id(set, id) == FALSE) return NO_ID;

  for(i=0; i < set_get_numIds(set); i++)
    if (set->ids[i] == id) return set->ids[i];

  return NO_ID;
}
