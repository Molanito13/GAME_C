/**
 * @brief Define un enlace
 *
 * @file link.h
 * @author Adrián Martínez Bayán
 * @version 1.0
 * @date 27-03-2021
 */

#ifndef LINK_H
#define LINK_H

#include "types.h"

/**
* @brief Define un enlace
*
* Define un enlace
*/
typedef struct _Link Link;

#define MAX_LINKS 100		/*!<Numero maximo de links*/


/**
* @brief Enlace
*
* Define si un enlace está abierto o cerrado
*/
typedef enum {
	ABIERTO=0, 		/*!<Valor de "Abierto"*/
	CERRADO=1		/*!<Valor de "Cerrado"*/
} ESTADO;

/**
* @brief Inicializa la estrucutra Link
*
* link_create Inicializa la estrucutra Link y los valores correspondientes
*
* @date 27-03-2021
* @author: Adrián Martínez Bayán
*
* @param id Id asociada al enlace
* @return Link*, Puntero al nuevo enlace o NULL si falla algo
*/
Link* link_create(Id id);

/**
* @brief Destruye la estructura link
*
* link_destroy Borra el enlace y sus datos asociados
*
* @date 27-03-2021
* @author: Adrián Martínez Bayán
*
* @param link Puntero al enlace a borrar
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS link_destroy(Link* link);

/**
* @brief Actualiza el id del enlace
*
* link_set_id Actualiza el id del enlace
*
* @date 27-03-2021
* @author: Adrián Martínez Bayán
*
* @param link Puntero al enlace
* @param id Id Nuevo id del enlace
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS link_set_id(Link* link, Id id);

/**
* @brief Actualiza el nombre del enlace
*
* link_set_name Actualiza el nombre del enlace
*
* @date 27-03-2021
* @author: Adrián Martínez Bayán
*
* @param link Puntero al enlace
* @param name Nuevo nombre del enlace
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS link_set_name(Link* link, char* name);

/**
* @brief Actualiza el id de la primera casilla del enlace
*
* link_set_id_primero Actualiza el id de la primera casilla del enlace
*
* @date 27-03-2021
* @author: Adrián Martínez Bayán
*
* @param link Puntero al enlace
* @param id Nuevo id de la primera casilla del enlace
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS link_set_id_primero(Link* link, Id id);

/**
* @brief Actualiza el id de la primera casilla del enlace
*
* link_set_id_segundo Actualiza el id de la segunda casilla del enlace
*
* @date 27-03-2021
* @author: Adrián Martínez Bayán
*
* @param link Puntero al enlace
* @param id Nuevo id de la segunda casilla del enlace
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS link_set_id_segundo(Link* link, Id id);

/**
* @brief Actualiza el estado del enlace
*
* link_set_estado Actualiza el estado del enlace
*
* @date 27-03-2021
* @author: Adrián Martínez Bayán
*
* @param link Puntero al enlace
* @param estado Nuevo estado del enlace
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS link_set_estado(Link* link, ESTADO estado);

/**
* @brief Recupera el id del enlace
*
* link_get_id Recupera el id del enlace
*
* @date 27-03-2021
* @author: Adrián Martínez Bayán
*
* @param link Puntero al enlace
* @return Id, Id del enlace si todo ha ido bien o NO_ID(-1) si algo falla
*/
Id link_get_id(Link* link);

/**
* @brief Recupera el nombre del enlace
*
* link_get_name Recupera el nombre del enlace
*
* @date 27-03-2021
* @author: Adrián Martínez Bayán
*
* @param link Puntero al enlace
* @return char, El nombre si ha ido bien o NULL si falla algo
*/
const char* link_get_name(Link* link);

/**
* @brief Recupera el id de la primera casilla del enlace
*
* link_get_id_primero Recupera el id de la primera casilla del enlace
*
* @date 27-03-2021
* @author: Adrián Martínez Bayán
*
* @param link Puntero al enlace
* @return Id, Id del enlace si todo ha ido bien o NO_ID(-1) si algo falla
*/
Id link_get_id_primero(Link* link);

/**
* @brief Recupera el id de la segunda casilla del enlace
*
* link_get_id_segundo Recupera el id de la segunda casilla del enlace
*
* @date 27-03-2021
* @author: Adrián Martínez Bayán
*
* @param link Puntero al enlace
* @return Id, Id del enlace si todo ha ido bien o NO_ID(-1) si algo falla
*/
Id link_get_id_segundo(Link* link);

/**
* @brief Recupera el estado del enlace
*
* link_get_estado Recupera el estado del enlace
*
* @date 27-03-2021
* @author: Adrián Martínez Bayán
*
* @param link Puntero al enlace
* @return ESTADO, Cerrado si falla o está cerrado, Abierto si está abierto
*/
ESTADO link_get_estado(Link* link);

/**
* @brief Imprime por pantalla los datos del enlace
*
* link_print Imprime por pantalla los datos del enlace
*
* @date 27-03-2021
* @author: Adrián Martínez Bayán
*
* @param link Puntero al enlace
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS link_print(Link* link);

/**
* @brief Recupera la direccion del Enlace
*
* link_get_dir Recupera la direccion del enlace
*
* @date 03/05/2021
* @author Daniel Molano
*
* @param link Puntero al enlace
* @return char, la direccion del enlace si todo va bien,
* NULL si ha habido algun error
*/
char* link_get_dir(Link* link);

/**
* @brief Actualiza la direccion del Enlace
*
* link_set_dir Actualiza la direccion del enlace
*
* @date 03/05/2021
* @author Daniel Molano
*
* @param link Puntero al enlace
* @param dir Nueva direccion del enlace
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS link_set_dir(Link* link, char* dir);

#endif
