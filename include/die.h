/**
 * @brief Define un dado
 *
 * @file die.h
 * @author Daniel Molano Caraballo
 * @version 1.0
 * @date 02-03-2021
 */

 #ifndef DIE_H
 #define DIE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "types.h"

#define MAX_DIE_V 6	/*!< Numero maximo del dado */
#define MIN_DIE_V 1	/*!< Numero minimo del dado */
#define MAX_DIE 1	/*!< Numero de dados maximos */

/**
* @brief Die def
*
* Esta estructura define un dado
*/
typedef struct _Die Die;

/**
* @brief Inicializa la estrucutra Die
*
* die_create Inicializa la estrucutra Die y los valores correspondientes
*
* @date 02/03/2021
* @author: Daniel Molano Caraballo
*
* @param id Id asociada al dado
* @return Puntero al nuevo dado
*/
Die* die_create(Id id);

/**
* @brief Destruye la estrucutra Die
*
* die_destroy Destruye la estrucutra die y los valores correspondientes
*
* @date 02/03/2021
* @author: Daniel Molano Caraballo
*
* @param die Puntero a la estructura die
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS die_destroy(Die* die);

/**
* @brief Imprime el dado
*
* die_print Imprime los diferentes campos de la estructura die
*
* @date 02/03/2021
* @author: Daniel Molano Caraballo
*
* @param die Puntero a la estructura die
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS die_print(Die* die);

/**
* @brief lanza el dado
*
* die_roll Rolls the dice
*
* @date 02/03/2021
* @author: Daniel Molano Caraballo
*
* @param die Puntero a la estructura die
* @return valor del dado lanzado o -1 en
* caso de error
*/
int die_roll(Die* die);

/**
* @brief Recupera el id del dado
*
* die_get_id Recupera el id del die
*
* @date 10/02/2021
* @author: Daniel Molano Caraballo
*
* @param die Puntero a la estructura die
* @return Id del dado
*/
Id die_get_id(Die* die);

/**
* @brief Actualiza el id
*
* die_set_id Actualiza el id del dado
*
* @date 02/03/2021
* @author: Daniel Molano Caraballo
*
* @param die Puntero a la estructura die
* @param id Nuevo id del dado
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS die_set_id(Die* die, Id id);

/**
* @brief Recupera el value del dado
*
* die_get_value Recupera el value del dado
*
* @date 02/03/2021
* @author: Daniel Molano Caraballo
*
* @param die Puntero a la estructura die
* @return value del dado
*/
int die_get_value(Die* die);

/**
* @brief Actualiza el valor
*
* die_set_value Actualiza el value del dado
*
* @date 02/03/2021
* @author: Daniel Molano Caraballo
*
* @param die Puntero a la estructura die
* @param newValue Nuevo value del dado
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS die_set_value(Die* die, int newValue);


 #endif
