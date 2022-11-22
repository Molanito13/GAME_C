/**
 * @brief Define la pantalla
 *
 * @file screen.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 07-02-2021
 * @copyright GNU Public License
 */

#ifndef __SCREEN__
#define __SCREEN__

#define SCREEN_MAX_STR 255		/*!<LOngitud maxima de la string*/

/**
* @brief Area
*
* Define la estructura area
*/
typedef struct _Area Area;

/**
* @brief Inicia la pantalla
*
* screen_init Inicia la estructura Area y sus valores asociados
*
* @date 07-02-2021
* @author: Profesores PPROG
*/
void  screen_init();

/**
* @brief Destruye la pantalla
*
* screen_destroy Destruye la estructura Area y sus valores asociados
*
* @date 07-02-2021
* @author: Profesores PPROG
*/
void  screen_destroy();

/**
* @brief Dibuja la pantalla
*
* screen_paint Dibuja la interfaz grafica
*
* @date 07-02-2021
* @author: Profesores PPROG
*/
void  screen_paint();

/**
* @brief Inicia un area de la pantalla
*
* screen_area_init Inicia un area de la interfaz grafica
*
* @date 07-02-2021
* @author: Profesores PPROG
*
* @param x Coordenada de la interfaz grafica
* @param y Coordenada de la interfaz grafica
* @param width Anchura de la interfaz grafica
* @param height Altura de la interfaz grafica
* @return Interfaz grafica
*/
Area* screen_area_init(int x, int y, int width, int height);

/**
* @brief Destruye un area de la pantalla
*
* screen_area_destroy Destruye una parte de la interfaz grafica
*
* @date 07-02-2021
* @author: Profesores PPROG
*
* @param area Puntero a la estructura area
*/
void  screen_area_destroy(Area* area);

/**
* @brief Limpia un area de la pantalla
*
* screen_area_clear Limpia una parte de la interfaz grafica
*
* @date 07-02-2021
* @author: Profesores PPROG
*
* @param area Puntero a la estructura area
*/
void  screen_area_clear(Area* area);

/**
* @brief Reinicia el cursor
*
* screen_area_reset_cursor Reinicia el cursor de una parte de la interfaz grafica
*
* @date 07-02-2021
* @author: Profesores PPROG
*
* @param area Puntero a la estructura area
*/
void  screen_area_reset_cursor(Area* area);

/**
* @brief Introduce una cadena en la pantalla
*
* screen_area_puts Introduce una cadena en la pantalla
*
* @date 07-02-2021
* @author: Profesores PPROG
*
* @param area Puntero a la estructura area
* @param str Cadena a imprimir
*/
void  screen_area_puts(Area* area, char *str);

#endif
