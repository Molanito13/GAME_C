/**
 * @brief Carga el juego
 *
 * @file game_management.h
 * @author Carolina Monedero
 * @version 1.0
 * @date 10/02/2021
 * Modificado el 09/03/2021
 */

 #ifndef GAME_MANAGEMENT_H
 #define GAME_MANAGEMENT_H

#include "types.h"
#include "game.h"

/**
* @brief Función que carga los espacios del juego
* @author Profesores de PPROG, modificada por
* CArolina Monedero
* @date 09/02/2021
* @param game Puntero a la estructura Game
* @param filename  Nombre del fichero del juego
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS game_management_load_space(Game *game, char *filename);

/**
* @brief Función que carga los objetos del juego
* @author Carolina Monedero
* @date 09/03/2021
* @param game Puntero a la estructura Game
* @param filename Nombre del fichero del juego
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS game_management_load_objects(Game *game, char *filename);

/**
* @brief Función que carga los players del juego
* @author Carolina Monedero
* @date 09/03/2021
* @param game Puntero a la estructura Game
* @param filename Nombre del fichero del juego
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS game_management_load_player(Game *game, char *filename);

/**
* @brief Función que carga los enlaces del juego
* @author Jaime Martinez
* @date 30/03/2021
* @param game Puntero a la estructura Game
* @param filename Nombre del fichero del juego
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS game_management_load_links(Game *game, char *filename);

/**
* @brief Función que carga una partida anteriormente guardada del juego
* @author Daniel Molano Caraballo
* @date 01/05/2021
* @param game Puntero a la estructura Game
* @param f Nombre del fichero del juego
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS game_management_load(Game** game, char* f);

/**
* @brief Función que guarda el estado de una partida
* @author Daniel Molano Caraballo
* @date 01/05/2021
* @param game Puntero a la estructura Game
* @param f Nombre del fichero del juego
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS game_management_save(Game* game, char* f);

 #endif
