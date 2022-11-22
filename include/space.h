/**
 * @brief Define un espacio
 *
 * @file space.h
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015.
 * Modificado por Carolina Monedero
 * @copyright GNU Public License
 */

#ifndef SPACE_H
#define SPACE_H

#include "types.h"
#include "set.h"
#include "link.h"
#include "object.h"

/**
* @brief Define la estrucutra espacio
*/
typedef struct _Space Space;

#define MAX_SPACES 100			/*!<Numero maximo de espacios*/
#define FIRST_SPACE 1			/*!<Casilla inicial*/
#define MAX_H 3					/*!<Numero maximo de filas de una descripcion*/
#define MAX_V 26				/*!<Longitud maxima de cada fila de la descripcion*/

/**
* @brief Inicializa la estrucutra Space
*
* space_create Inicializa la estrucutra Space y los valores correspondientes
*
* @date 10-02-2021
* @author: Carolina Monedero
*
* @param id Id de la casilla
* @return newSpace o NULL
*/
Space* space_create(Id id);

/**
* @brief Borra la casilla y sus datos asociados
*
* @date 10-02-2021
* @author: Carolina Monedero
*
* @param space La casilla
* @return OK o ERROR
*/
STATUS space_destroy(Space* space);

/**
* @brief Recupera el id de la casilla
*
* @date 10-02-2021
*
* @param space La casilla
* @return space->id
*/
Id space_get_id(Space* space);

/**
* @brief Actualiza el nombre de la casilla
*
* @date 10-02-2021
* @author: Carolina Monedero
*
* @param space La casilla
* @param name Nuevo nombre de la casilla
* @return OK o ERROR
*/
STATUS space_set_name(Space* space, char* name);

/**
* @brief Recupera el nombre de la casilla
*
* @date 10-02-2021
*
* @param space La casilla
* @return space->name
*/
const char* space_get_name(Space* space);

/**
* @brief Actualiza el link norte
*
* @date 10-02-2021
* @author: Jaime Martinez
*
* @param space La casilla
* @param link Nuevo link
* @return OK o ERROR
*/
STATUS space_set_north(Space* space, Link* link);

/**
* @brief Recupera el link norte
*
* @date 10-02-2021
* @author: Jaime Martinez
*
* @param space La casilla
* @return id del link norte
*/
Id space_get_north(Space* space);

/**
* @brief Actualiza el link sur
*
* @date 10-02-2021
* @author: Jaime Martinez
*
* @param space La casilla
* @param link Nuevo link
* @return OK o ERROR
*/
STATUS space_set_south(Space* space, Link* link);

/**
* @brief Recupera el link sur
*
* @date 10-02-2021
* @author: Jaime Martinez
*
* @param space La casilla
* @return id del link sur
*/
Id space_get_south(Space* space);

/**
* @brief Actualiza el link este
*
* @date 10-02-2021
* @author: Jaime Martinez
*
* @param space La casilla
* @param link Nuevo link
* @return OK o ERROR
*/
STATUS space_set_east(Space* space, Link* link);

/**
* @brief Recupera el link este
*
* @date 10-02-2021
* @author: Jaime Martinez
*
* @param space La casilla
* @return id del link este
*/
Id space_get_east(Space* space);

/**
* @brief Actualiza el link oeste
*
* @date 10-02-2021
* @author: Jaime Martinez
*
* @param space La casilla
* @param link Nuevo link
* @return OK o ERROR
*/
STATUS space_set_west(Space* space, Link* link);

/**
* @brief Recupera el link oeste
*
* @date 10-02-2021
* @author: Jaime Martinez
*
* @param space La casilla
* @return id del link oeste
*/
Id space_get_west(Space* space);

/**
* @brief Actualiza el link up
*

* @date 20-04-2021
* @author: Adrian Martinez
*
* @param space La casilla
* @param link Nuevo link
* @return OK o ERROR
*/
STATUS space_set_up(Space* space, Link* link);

/**
* @brief Recupera el id del link up
*
* @date 20-04-2021
* @author: Adrian Martinez
*
* @param space La casilla
* @return id del link up
*/
Id space_get_up(Space* space);

/**
* @brief Actualiza el link down
*
* @date 20-04-2021
* @author: Adrian Martinez
*
* @param space La casilla
* @param link Nuevo link
* @return OK o ERROR
*/
STATUS space_set_down(Space* space, Link* link);

/**
* @brief Recupera el id del link down
*
* @date 20-04-2021
* @author: Adrian Martinez
*
* @param space La casilla
* @return id del link down
*/
Id space_get_down(Space* space);

/**
* @brief Actualiza el estado del objeto
*
* @date 10-02-2021
* @author: Carolina Monedero
*
* @param space La casilla
* @param value Nuevo id del set
* @return OK o ERROR
*/
STATUS space_set_object(Space* space, Id value);

/**
* @brief Recupera el puntero al enlace del norte
*
* space_get_north_link Recupera el puntero al enlace del norte
*
* @date 31-03-2021
* @author: Jaime Martínez
*
* @param space Puntero al espacio
* @return Link*, puntero al enlace si todo ha ido bien o NULL
* en caso contrario
*/
Link* space_get_north_link(Space* space);

/**
* @brief Recupera el puntero al enlace del sur
*
* space_get_north_link Recupera el puntero al enlace del sur
*
* @date 31-03-2021
* @author: Jaime Martínez
*
* @param space Puntero al espacio
* @return Link*, puntero al enlace si todo ha ido bien o NULL
* en caso contrario
*/
Link* space_get_south_link(Space* space);

/**
* @brief Recupera el puntero al enlace del este
*
* space_get_north_link Recupera el puntero al enlace del este
*
* @date 31-03-2021
* @author: Jaime Martínez
*
* @param space Puntero al espacio
* @return Link*, puntero al enlace si todo ha ido bien o NULL
* en caso contrario
*/
Link* space_get_east_link(Space* space);

/**
* @brief Recupera el puntero al enlace del oeste
*
* space_get_north_link Recupera el puntero al enlace del oeste
*
* @date 31-03-2021
* @author: Jaime Martínez
*
* @param space Puntero al espacio
* @return Link*, puntero al enlace si todo ha ido bien o NULL
* en caso contrario
*/
Link* space_get_west_link(Space* space);

/**
* @brief Recupera el puntero al enlace del up
*
* space_get_up_link Recupera el puntero al enlace del up
*
* @date 20-04-2021
* @author: Adrian Martínez
*
* @param space Puntero al espacio
* @return Link*, puntero al enlace si todo ha ido bien o NULL
* en caso contrario
*/
Link* space_get_up_link(Space* space);

/**
* @brief Recupera el puntero al enlace del down
*
* space_get_down_link Recupera el puntero al enlace del down
*
* @date 20-04-2021
* @author: Adrian Martínez
*
* @param space Puntero al espacio
* @return Link*, puntero al enlace si todo ha ido bien o NULL
* en caso contrario
*/
Link* space_get_down_link(Space* space);

/**
* @brief Recupera el set del espacio
*
* space_get_object Recupera el set del espacio
*
* @date 10-02-2021
* @author: Carolina Monedero
*
* @param space Puntero al espacio
* @return Set*, puntero al set si todo ha ido bien o NULL
* en caso contrario
*/
Set* space_get_object(Space* space);

/**
* @brief Space print
*
* space_print
*
* @date 10-02-2021
* @author: Carolina Monedero
*
* @param space Puntero al espacio
* @return OK o ERROR
*/
STATUS space_print(Space* space);

/**
* @brief Actualiza la descripcion grafica del espacio
*
* @date 15-03-2021
* @author: Carolina Monedero
*
* @param space Puntero al espacio
* @param fila1 Parte superior
* @param fila2 parte central
* @param fila3 parte inferior
* @return OK o ERROR
*/
STATUS space_set_gdesc(Space *space, char* fila1, char* fila2, char* fila3);

/**
* @brief recupera la descripcion grafica del espacio
*
* @date 15-03-2021
* @author: Carolina Monedero
*
* @param space Puntero al espacio
* @param fila Parte a recuperar
* @return char*
*/
char* space_get_gdesc(Space *space, int fila);

/**
* @brief Actualiza la descripcion del espacio
*
* @date 15-03-2021
* @author: Carolina Monedero
*
* @param space Puntero al espacio
* @param desc Nueva descripcion
* @return OK o ERROR
*/
STATUS space_set_description(Space* space, char* desc);

/**
* @brief Recupera la descripcion del espacio
*
* @date 15-03-2021
* @author: Carolina Monedero
*
* @param space Puntero al espacio
* @return space->description
*/
const char* space_get_description(Space* space);

/**
* @brief Actualiza la descripcion del espacio
*
* @date 25-04-2021
* @author: Adrian Martinez
*
* @param space Puntero al espacio
* @param desc Nueva descripcion
* @return STATUS
*/
STATUS space_set_description_detallada(Space* space, char* desc);

/**
* @brief Recupera la descripcion detallada del espacio
*
* @date 25-04-2021
* @author: Adrian Martinez
*
* @param space Puntero al espacio
* @return space->description_detallada
*/
const char* space_get_description_detallada(Space* space);

/**
* @brief Actualiza el estado de la iluminacion

*

* @date 20-04-2021
* @author: Adrián Martínez
*
* @param space Puntero al espacio
* @param iluminacion Nueva iluminacion
* @return Status
*/
STATUS space_set_iluminacion(Space *space, BOOL iluminacion);

/**
* @brief Recupera el estado de la iluminacion
*
* @date 20-04-2021
* @author: Adrián Martínez
*
* @param space Puntero al espacio
* @return space->iluminado
*/
BOOL space_get_iluminacion(Space *space);

#endif
