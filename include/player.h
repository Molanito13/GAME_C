/**
 * @brief Define un jugador
 *
 * @file player.h
 * @author Daniel Molano Caraballo
 * @version 1.0
 * @date 10-02-2021
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"
#include "inventory.h"

/**
* @brief player
*
* Define la estructura player
*/
typedef struct _Player Player;

#define MAX_PLAYERS 100 /*!<NUmero maximo de jugadores*/

/**
* @brief Inicializa la estrucutra Player
*
* player_create Inicializa la estrucutra Player y los valores correspondientes
*
* @date 10/02/2021
* @author: Daniel Molano Caraballo
*
* @param id Id asociada al player
* @param t_mochila Tamaño de la mochila
* @return Puntero al nuevo player
*/
Player* player_create(Id id, int t_mochila);

/**
* @brief Destruye la estrucutra player
*
* player_destroy Borra el player y sus datos asociados
*
* @date 10/02/2021
* @author: Daniel Molano Caraballo
*
* @param player Puntero al Player a borrar
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS player_destroy(Player* player);

/**
* @brief Actualiza el nombre del player
*
* player_set_name Actualiza el nombre del player
*
* @date 10/02/2021
* @author: Daniel Molano Caraballo
*
* @param player Puntero al Player a modificar
* @param name Nuevo nombre del player
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS player_set_name(Player* player, char* name);

/**
* @brief Recupera el nombre del player
*
* player_get_name Recupera el nombre del player
*
* @date 10/02/2021
* @author: Daniel Molano Caraballo
*
* @param player Puntero al Player a consultar
* @return Nombre del player
*/
const char * player_get_name(Player* player);

/**
* @brief Actualiza el id del player
*
* player_set_id Actualiza el id del player
*
* @date 27/03/2021
* @author: Daniel Molano Caraballo
*
* @param player Puntero al Player a modificar
* @param id nuevo identificador del jugador
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS player_set_id(Player* player, Id id);

/**
* @brief Recupera el id del player
*
* player_get_id Recupera el id del player
*
* @date 10/02/2021
* @author: Daniel Molano Caraballo
*
* @param player Puntero al Player a consultar
* @return Id del player
*/
Id player_get_id(Player* player);

/**
* @brief Imprime la estrucutra
*
* player_print Imprime por pantalla los valores de la estructura player
*
* @date 10/02/2021
* @author: Daniel Molano Caraballo
*
* @param player Puntero al Player a consultar
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS player_print(Player* player);

/**
* @brief Recupera la localidad del player
*
* player_get_location Recupera la location del player
*
* @date 10/02/2021
* @author: Daniel Molano Caraballo
*
* @param player Puntero al Player a consultar
* @return Location del player
*/
Id player_get_location(Player* player);

/**
* @brief Actualiza la location del player
*
* player_set_location Actualiza la location del player
*
* @date 10/02/2021
* @author: Daniel Molano Caraballo
*
* @param player Puntero al Player a modificar
* @param location Nuevo location del player
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS player_set_location(Player* player, Id location);

/**
* @brief Recupera el object del player
*
* player_get_inventory Recupera el inventario del player
*
* @date 10/02/2021
* @author: Daniel Molano Caraballo
*
* Modificada el 26/03/2021, Carolina Monedero
*
* @param player Puntero al Player a consultar
* @return Inventory del player
*/
Inventory* player_get_inventory(Player* player);

/**
* @brief Actualiza el inventario completo del Player
*
* player_get_inventory Actualiza el inventario del player
*
* @date 10/02/2021
* @author: Daniel Molano Caraballo
*
* Modificada el 26/03/2021, Carolina Monedero
*
* @param player Puntero a la estructura Player
* @param inv puntero al inventario
* @return inventario del player
*/
STATUS player_set_inventory(Player* player, Inventory *inv);

/**
* @brief Recupera un objeto del inventario
*
* player_getObject_from_inventory recupera un objeto del inventario
*
* @date 26/03/2021
* @author: Carolina Monedero
*
* @param player Puntero al Player a consultar
* @param id Id del objeto a recuperar
* @return id del objeto
*/
Id player_getObject_from_inventory(Player *player, Id id);

/**
* @brief Actualiza el object del player
*
* player_set_object Actualiza el object del player
*
* @date 10/02/2021
* @author: Daniel Molano Caraballo
*
* @param player Puntero al Player a modificar
* @param object Nuevo object del player
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/STATUS player_set_object(Player* player, Id object);

/**
* @brief Recupera el tamaño del inventario
*
* player_get_maxTam_inventory recupera el tamaño del inventario
*
* @date 26/03/2021
* @author: Carolina Monedero
*
* @param player Puntero al Player a consultar
* @return tamaño del inventario
*/
int player_get_maxTam_inventory(Player* player);

/**
* @brief Actualiza el tamaño del inventario
*
* player_set_maxTam_inventory actualiza el tamaño del inventario
*
* @date 26/03/2021
* @author: Carolina Monedero
*
* @param player Puntero al Player a consultar
* @param tam Nuevo tamaño del inventario
* @return OK si todo ha ido bien, ERROR en caso contrario
*/
STATUS player_set_maxTam_inventory(Player* player, int tam);

#endif
