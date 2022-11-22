/**
 * @brief Define el motor gráfico
 *
 * @file graphic_engine.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 07-02-2021
 * @copyright GNU Public License
 */

#ifndef __GRAPHIC_ENGINE__
#define __GRAPHIC_ENGINE__

#include "game.h"

/**
* @brief Graphic_Engine def
*
* Esta estructura define un Graphic_engine
*/
typedef struct _Graphic_engine Graphic_engine;

/**
* @brief Inicializa la estrucutra Graphic_engine
*
* graphic_engine_create Inicializa la estrucutra Graphic_engine y los valores correspondientes
*
* @date 10/02/2021
* @author: Profesores PPROG
*
* @return Puntero al nuevo graphic_engine
*/
Graphic_engine* graphic_engine_create();

/**
* @brief Destruye la estrucutra Graphic_engine
*
* graphic_engine_destroy Destruye la estrucutra Graphic_engine y los valores correspondientes
*
* @date 10/02/2021
* @author: Profesores PPROG
*
* @param ge Puntero al Graphic_engine a destruir
*/
void graphic_engine_destroy(Graphic_engine *ge);

/**
* @brief Dibuja la partida
*
* graphic_engine_paint_game Accede a los valores de las diferentes estructuras que componen la partida para representar sus datos
*
* @date 10/02/2021
* @author: Profesores PPROG
*
* @param ge Puntero al Graphic_engine
* @param game Puntero a la estructura Game
*/
void graphic_engine_paint_game(Graphic_engine *ge, Game *game);

#endif
