/**
 * @brief Define un jugador
 *
 * @file player.c
 * @author Daniel Molano Caraballo
 * @version 1.0
 * @date 10-02-2021
 * Modificado por Carolina Monedero 26-03-2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/types.h"
#include "../include/player.h"
#include "../include/inventory.h"

/**
* @brief Estructura de datos Player
* @author Daniel Molano Caraballo
* @date 11/02/2021
*/
struct _Player {
  Id id;						          /*!<Id del jugador*/
  Id location;                /*!<Id the la localizacion*/
  Inventory* objects;         /*!<Inventario del jugador*/
  char name[WORD_SIZE + 1]; 	/*!<Nombre del jugador*/
};

Player* player_create(Id id, int t_mochila) {

  Player *newPlayer = NULL;

  newPlayer = (Player *) malloc(sizeof (Player));

  if (!newPlayer) {
    return NULL;
  }

  newPlayer->id = id;

  newPlayer->name[0] = '\0';

  newPlayer->location = NO_ID;
  newPlayer->objects = inventory_create(t_mochila);

  return newPlayer;
}

STATUS player_destroy(Player* player) {

  if (!player) {
    return ERROR;
  }

  inventory_destroy(player->objects);

  free(player);

  return OK;
}

STATUS player_set_name(Player* player, char* name) {

  if (!player || !name) {
    return ERROR;
  }

  if (!strcpy(player->name, name)) {
    return ERROR;
  }

  return OK;
}

const char * player_get_name(Player* player) {

  if (!player) {
    return NULL;
  }
  return player->name;
}

STATUS player_set_id(Player* player, Id id) {

  if (!player) return ERROR;

  player->id = id;

  return OK;
}

Id player_get_id(Player* player) {

  if (!player) {
    return NO_ID;
  }
  return player->id;
}

Id player_get_location(Player* player){

  if(!player) return NO_ID;

  return player->location;
}

STATUS player_set_location(Player* player, Id location){

  if(!player) return ERROR;

  player->location = location;

  return OK;
}

Inventory* player_get_inventory(Player* player){

  if(!player) return NULL;

  return player->objects;
}

STATUS player_set_inventory(Player* player, Inventory* inv){

  if (!player || !inv) return ERROR;

  player->objects = inv;

  return OK;
}

Id player_getObject_from_inventory(Player *player, Id id){
  Id object;

  if (!player || id == NO_ID) return NO_ID;

  object = inventory_get_objectWithId(player->objects, id);
  if (object == NO_ID) return NO_ID;

  return object;

}

int player_get_maxTam_inventory(Player* player) {
  if (!player) return -1;

  return inventory_getMaxTam(player->objects);
}

STATUS player_set_maxTam_inventory(Player* player, int tam){
  if (!player || tam < 0) return ERROR;

  return inventory_setMaxTam(player->objects, tam);
}

STATUS player_set_object(Player* player, Id object){

  if(!player || object == NO_ID) return ERROR;

  inventory_setId(player->objects, object);

  return OK;
}

STATUS player_print(Player* player) {

  if (!player) {
    return ERROR;
  }

  fprintf(stdout, "--> Player (Id: %ld; Name: %s; Location: %ld; Objects: )\n", player->id, player->name, player->location);
  inventory_print(player->objects);
  fprintf(stdout, "\n");

  return OK;
}
