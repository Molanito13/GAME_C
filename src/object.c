/**
 * @brief Define un objeto
 *
 * @file object.c
 * @author Daniel Molano Caraballo
 * @version 1.0
 * @date 09-02-2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/types.h"
#include "../include/object.h"

/**
* @brief Estructura de datos Object
* @author Daniel Molano Caraballo
* @date 11/02/2021
*/
struct _Object {
  Id id;					          	             /*!<Id del objeto*/
  char name[WORD_SIZE + 1]; 	             /*!<Nombre del objeto*/
  char description[WORD_SIZE + 1];         /*!<Descripción del objeto*/
  BOOL movable;                            /*!<Indica si el objeto se puede mover o no de su ubicación*/
  Id dependency;                           /*!<Indica si un objeto depende de otro para ser cogido*/
  Id open;                                 /*!<Indica si un objeto puede abrir un enlace*/
  BOOL illuminate;                         /*!<Indica si un objeto puede iluminar un espacio*/
  BOOL turnedon;                           /*!<Indica si un objeto QUE SE PUEDE ILUMINAR está encendido*/
};

Object* object_create(Id id) {

  Object *newObject = NULL;

  if (id == NO_ID) return NULL;

  newObject = (Object *) malloc(sizeof (Object));

  if (!newObject) {
    return NULL;
  }

  newObject->id = id;
  newObject->name[0] = '\0';
  newObject->movable = FALSE;
  newObject->dependency = NO_ID;
  newObject->open = NO_ID;
  newObject->illuminate = FALSE;
  newObject->turnedon = FALSE;

  return newObject;
}

STATUS object_destroy(Object* object) {

  if (!object) {
    return ERROR;
  }

  free(object);
  object = NULL;

  return OK;
}

STATUS object_set_id(Object* object, Id id){

  if(!object) return ERROR;

  object->id = id;

  return OK;
}

STATUS object_set_name(Object* object, char* name) {

  if (!object || !name) {
    return ERROR;
  }

  if (!strcpy(object->name, name)) {
    return ERROR;
  }

  return OK;
}

const char * object_get_name(Object* object) {

  if (!object) {
    return NULL;
  }
  return object->name;
}

Id object_get_id(Object* object) {

  if (!object) {
    return NO_ID;
  }
  return object->id;
}

STATUS object_set_description(Object* object, char* desc){

  if (!object || !desc) return ERROR;

  if(!strcpy(object->description, desc)) return ERROR;

  return OK;
}

const char* object_get_description(Object* object){

  if (!object) return NULL;

  return object->description;
}

STATUS object_set_movable(Object* object, BOOL mov){

  if (!object) return ERROR;

  object->movable = mov;

  return OK;

}

BOOL object_get_movable(Object* object) {

  if (!object) return FALSE;

  return object->movable;

}

STATUS object_set_dependency(Object *object, Id dep){

  if (!object) return ERROR;

  object->dependency = dep;

  return OK;

}

Id object_get_dependency(Object* object){

  if (!object) return NO_ID;

  return object->dependency;

}

STATUS object_set_open(Object* object, Id op){

  if (!object) return ERROR;

  object->open = op;

  return OK;

}

Id object_get_open(Object* object){

  if (!object) return NO_ID;

  return object->open;

}

STATUS object_set_illuminate(Object* object, BOOL ill){

  if (!object) return ERROR;

  object->illuminate = ill;

  return OK;

}

BOOL object_get_illuminate(Object* object){

  if (!object) return FALSE;

  return object->illuminate;

}

STATUS object_set_turnedon(Object* object, BOOL turn){

  if (!object) return ERROR;

  object->turnedon = turn;

  return OK;

}

BOOL object_get_turnedon(Object* object){

  if (!object) return FALSE;

  return object->turnedon;

}

STATUS object_print(Object* object) {

  if (!object) {
    return ERROR;
  }

  fprintf(stdout, "--> Object (Id: %ld; Name: %s; Open: %ld)\n", object->id, object->name, object->open);

  return OK;
}
