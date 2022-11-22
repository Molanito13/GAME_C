/**
 * @brief Define un objeto
 *
 * @file object.h
 * @author Daniel Molano Caraballo
 * @version 1.0
 * @date 09-02-2021
 */

#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"

/**
* @brief Object
*
* Define un object
*/
typedef struct _Object Object;

#define MAX_OBJECTS 100			/*!<Numero maximo de objetos*/
#define MAX_DESCRIPTION 100		/*!<Longitud maxima de la descripcion*/

/**
* @brief Inicializa la estrucutra Object
*
* object_create Inicializa la estrucutra Object y los valores correspondientes
*
* @date 10/02/2021
* @author: Daniel Molano Caraballo
*
* @param id Id asociada al object
* @return Puntero al nuevo object
*/
Object* object_create(Id id);

/**
* @brief Destruye la estrucutra Object
*
* object_destroy Destruye la estrucutra Object y los valores correspondientes
*
* @date 10/02/2021
* @author: Daniel Molano Caraballo
*
* @param object Puntero a la estructura object
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS object_destroy(Object* object);

/**
* @brief Actualiza el nombre
*
* object_set_name Actualiza el nombre del objeto
*
* @date 10/02/2021
* @author: Daniel Molano Caraballo
*
* @param object Puntero a la estructura object
* @param name Nuevo nombre del objeto
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS object_set_name(Object* object, char* name);

/**
* @brief Recupera el nombre del object
*
* object_get_name Recupera el nombre del object
*
* @date 10/02/2021
* @author: Daniel Molano Caraballo
*
* @param object Puntero a la estructura object
* @return Nombre del objeto
*/
const char * object_get_name(Object* object);

/**
* @brief Recupera el id del object
*
* object_get_id Recupera el id del object
*
* @date 10/02/2021
* @author: Daniel Molano Caraballo
*
* @param object Puntero a la estructura object
* @return Id del objeto
*/
Id object_get_id(Object* object);

/**
* @brief Imprime el objeto
*
* object_print Imprime los diferentes campos de la estructura object
*
* @date 10/02/2021
* @author: Daniel Molano Caraballo
*
* @param object Puntero a la estructura object
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS object_print(Object* object);

/**
* @brief Actualiza el id
*
* object_set_id Actualiza el id del objeto
*
* @date 10/02/2021
* @author: Daniel Molano Caraballo
*
* @param object Puntero a la estructura object
* @param id Nuevo id del object
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS object_set_id(Object* object, Id id);

/**
* @brief Actualiza la descripción del objecto
*
* object_set_description Actualiza la descripción del objecto
*
* @date 05/04/2021
* @author: Carolina Monedero Juzgado
*
* @param object Puntero a la estructura object
* @param desc la nueva descripción del objeto
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS object_set_description(Object* object, char* desc);

/**
* @brief Recupera la descripción del objecto
*
* object_set_description Recupera la descripción del objecto
*
* @date 05/04/2021
* @author: Carolina Monedero Juzgado
*
* @param object Puntero a la estructura object
* @return la descripción del objeto
*/
const char* object_get_description(Object* object);

/**
* @brief Actualiza el campo movable
*
* object_set_movable Actualiza el campo movable
*
* @date 19/04/2021
* @author: Carolina Monedero Juzgado
*
* @param object Puntero a la estructura object
* @param mov nuevo campo movable
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS object_set_movable(Object* object, BOOL mov);

/**
* @brief Recupera el campo movable
*
* object_get_movable Recupera el campo movable
*
* @date 19/04/2021
* @author: Carolina Monedero Juzgado
*
* @param object Puntero a la estructura object
* @return el campo movable
*/
BOOL object_get_movable(Object* object);

/**
* @brief Actualiza el campo dependency
*
* object_set_dependency Actualiza el campo dependency
*
* @date 19/04/2021
* @author: Carolina Monedero Juzgado
*
* @param object Puntero a la estructura object
* @param dep nuevo campo dependency
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS object_set_dependency(Object *object, Id dep);

/**
* @brief Recupera el campo dependency
*
* object_get_dependency Recupera el campo dependency
*
* @date 19/04/2021
* @author: Carolina Monedero Juzgado
*
* @param object Puntero a la estructura object
* @return el campo dependency
*/
Id object_get_dependency(Object* object);

/**
* @brief Actualiza el campo open
*
* object_set_open Actualiza el campo open
*
* @date 19/04/2021
* @author: Carolina Monedero Juzgado
*
* @param object Puntero a la estructura object
* @param op nuevo campo open
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS object_set_open(Object* object, Id op);

/**
* @brief Recupera el campo open
*
* object_get_open Recupera el campo open
*
* @date 19/04/2021
* @author: Carolina Monedero Juzgado
*
* @param object Puntero a la estructura object
* @return el campo open
*/
Id object_get_open(Object* object);

/**
* @brief Actualiza el campo illuminate
*
* object_set_illuminate Actualiza el campo illuminate
*
* @date 19/04/2021
* @author: Carolina Monedero Juzgado
*
* @param object Puntero a la estructura object
* @param ill nuevo campo illuminate
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS object_set_illuminate(Object* object, BOOL ill);

/**
* @brief Recupera el campo illuminate
*
* object_get_illuminate Recupera el campo illuminate
*
* @date 19/04/2021
* @author: Carolina Monedero Juzgado
*
* @param object Puntero a la estructura object
* @return el campo illuminate
*/
BOOL object_get_illuminate(Object* object);

/**
* @brief Actualiza el campo turnedon
*
* object_set_turnedon Actualiza el campo turnedon
*
* @date 19/04/2021
* @author: Carolina Monedero Juzgado
*
* @param object Puntero a la estructura object
* @param turn nuevo campo turnedon
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS object_set_turnedon(Object* object, BOOL turn);

/**
* @brief Recupera el campo turnedon
*
* object_get_turnedon Recupera el campo turnedon
*
* @date 19/04/2021
* @author: Carolina Monedero Juzgado
*
* @param object Puntero a la estructura object
* @return el campo turnedon
*/
BOOL object_get_turnedon(Object* object);


#endif
