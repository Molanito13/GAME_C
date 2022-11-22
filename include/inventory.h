/**
 * @brief Implementa el inventario del jugador
 *
 * @file inventory.h
 * @author Carolina Monedero
 * @date 22-03-2021
 */

#ifndef INVENTORY_H
#define INVENTORY_H

#include "types.h"
#include "set.h"

/**
* @brief Define la estructura Inventory
*/
typedef struct _Inventory Inventory;

/**
* @brief Inicializa la estrucutra Inventory
*
* inventory_create Inicializa la estrucutra Inventory y los valores correspondientes
*
* @param tam tamanio del inventario
*
* @date 23/03/2021
* @author: Carolina Monedero Juzgado
*/
Inventory* inventory_create(int tam);

/**
* @brief Destruye la estrucutra Inventory
*
* inventory_destroy Destruye la estrucutra Inventory y los valores correspondientes
*
* @date 23/032021
* @author: Carolina Monedero Juzado
*
* @param inv Puntero a la estructura Inventory
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS inventory_destroy(Inventory* inv);

/**
* @brief Añade un identificador nuevo al inventario
*
* @date 23/03/2021
* @author: Carolina Monedero Juzado
*
* @param inv Puntero a la estructura Inventory
* @param id Identificador a insertar
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS inventory_setId(Inventory* inv, Id id);

/**
* @brief Actualiza el tamanio maximo del inventario
*
* @date 23/03/2021
* @author: Carolina Monedero Juzado
*
* @param inv Puntero a la estructura Inventory
* @param tam Nuevo tamanio del inventario
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS inventory_setMaxTam(Inventory* inv, int tam);

/**
* @brief Devuelve el conjunto de identificadores
*
* @date 23/03/2021
* @author: Carolina Monedero Juzado
*
* @param inv Puntero a la estructura Inventorio
* @return Set, el conjunto de identificadores
*/
Set* inventory_getIds(Inventory* inv);

/**
* @brief Devuelve el id del object
*
* @date 23/03/2021
* @author: Carolina Monedero Juzado
*
* @param inv Puntero a la estructura Inventorio
* @param id Id del object
* @return object, el objeto
*/
Id inventory_get_objectWithId(Inventory* inv, Id id);

/**
* @brief Devuelve la capacidad maxima del inventario
*
* @date 23/03/2021
* @author: Carolina Monedero Juzado
*
* @param inv Puntero a la estructura Set
* @return int, la capacidad del inventario
*/
int inventory_getMaxTam(Inventory* inv);

/**
* @brief Imprime los elementos del inventario
*
* @date 23/03/2021
* @author: Carolina Monedero Juzado
*
* @param inv Puntero a la estructura Inventory
*/
void inventory_print(Inventory* inv);

/**
* @brief Comprueba su un identificador esta
* en el inventario
*
* @date 26/03/2021
* @author: Carolina Monedero Juzado
*
* @param inv Puntero a la estructura Inventory
* @param id Identificador que queremos ver si
* esta en el inventario
* @return TRUE si el identificador esta en el inventario,
* FALSE en caso de error.
*/
BOOL inventory_hasId(Inventory* inv, Id id);

/**
* @brief Devuelve el número de elementos que hay en el inventario
*
* @date 26/03/2021
* @author: Carolina Monedero Juzado
*
* @param inv Puntero a la estructura Inventario
* @return int, el numero de elementos o -1
* si ha habido algun error
*/
int inventory_getNumObjects(Inventory* inv);

#endif
