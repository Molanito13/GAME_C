/**
 * @brief Define un conjunto
 *
 * @file set.h
 * @author Carolina Monedero Juzgado
 * @version 1.0
 * @date 22-02-2021
 */

 #ifndef SET_H
 #define SET_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "types.h"

#define MAX_IDS_PER_SET 20			/*!<Objetos maximos por set*/

/**
* @brief Set
*
* Define una estructura Set
*/
typedef struct _Set Set;

/**
* @brief Inicializa la estrucutra Set
*
* set_create Inicializa la estrucutra Set y los valores correspondientes
*
* @date 22/02/2021
* @author: Carolina Monedero Juzgado
*/
Set *set_create();

/**
* @brief Destruye la estrucutra Set
*
* set_destroy Destruye la estrucutra Set y los valores correspondientes
*
* @date 22/02/2021
* @author: Carolina Monedero Juzado
*
* @param set Puntero a la estructura Set
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS set_destroy(Set *set);

/**
* @brief Añade un nuevo identificador al conjunto
*
* @date 22/02/2021
* @author: Carolina Monedero Juzado
*
* @param set Puntero a la estructura Set
* @param id Identificador a insertar
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS set_add_id(Set *set, Id id);

/**
* @brief Elimina un identificador del conjunto
*
* @date 22/02/2021
* @author: Carolina Monedero Juzado
*
* @param set Puntero a la estructura Set
* @param id Identificador a eliminar
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS set_del_id(Set *set, Id id);

/**
* @brief Imprime los elementos del conunto
*
* @date 22/02/2021
* @author: Carolina Monedero Juzado
*
* @param set Puntero a la estructura Set
*/
void set_print(Set *set);

/**
* @brief Comprueba si el conjunto esta lleno
*
* @date 22/02/2021
* @author: Carolina Monedero Juzado
*
* @param set Puntero a la estructura Set
* @return BOOL, TRUE si esta lleno o FALSE en
* caso contrario
*/
BOOL set_full(Set *set);

/**
* @brief Comprueba si el conjunto esta vacio
*
* @date 22/02/2021
* @author: Carolina Monedero Juzado
*
* @param set Puntero a la estructura Set
* @return BOOL, TRUE si esta vacio o FALSE en
* caso contrario
*/
BOOL set_empty(Set *set);

/**
* @brief Devuelve el número de elementos que hay en el conjunto
*
* @date 22/02/2021
* @author: Carolina Monedero Juzado
*
* @param set Puntero a la estructura Set
* @return int, el numero de elementos o -1
* si ha habido algun error
*/
int set_get_numIds(Set *set);

/**
* @brief Devuelve el array de identificadores
*
* @date 28/02/2021
* @author: Carolina Monedero Juzado
*
* @param set Puntero a la estructura Set
* @return Id, el array de identificadores
*/
Id* set_getIds(Set *set);

/**
* @brief Busca la primera posicion vacia del conjunto
*
* @date 22/02/2021
* @author: Carolina Monedero Juzado
*
* @param set Puntero a la estructura Set
* @return int, la posicion del conjunto o -1
* si esta llena o ha habido algun error
*/
int set_find_gap(Set *set);

/**
* @brief Comprueba su un identificador esta
* en el conjunto
*
* @date 28/02/2021
* @author: Carolina Monedero Juzado
*
* @param s Puntero a la estructura Set
* @param id Identificador que queremos ver si
* esta en el conjunto
* @return TRUE si el identificador esta en el conjunto,
* FALSE en caso de error.
*/
BOOL set_has_id(Set * s, Id id);

/**
* @brief Devuelve uno de los identificadores del array
*
* @date 26/03/2021
* @author: Carolina Monedero Juzado
*
* @param set Puntero a la estructura Set
* @param id el identificador a devolver
* @return Id, el id que queremos que nos devuelva
*/
Id set_getOneId(Set* set, Id id);

 #endif
