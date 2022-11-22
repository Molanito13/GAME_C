/**
 * @brief Define tipos comunes
 *
 * @file types.h
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */

#ifndef TYPES_H
#define TYPES_H

#define WORD_SIZE 1000	/*!< Tamaño maximo de la palabra */
#define NO_ID -1 /*!< Valor de NO_ID */


/**
* @brief Define Id como tipo de dato
*/
typedef long Id;

/**
* @brief Lista de posibles valores booleanos
*/
typedef enum {
  FALSE,	/*!<Valor falso*/
  TRUE		/*!<Valor verdaderon*/
} BOOL;

/**
* @brief Lista de posibles estados
*/
typedef enum {
  ERROR,	/*!<Valor erroneo*/
  OK		/*!<Valor correcto*/
} STATUS;

/**
* @brief Lista de posibles coordenadas
*/

typedef enum {
  N,		/*!<Norte*/
  S, 		/*!<Sur*/
  E, 		/*!<Este*/
  W, 		/*!Oeste*/
  U,    /*!Arriba*/
  D     /*!Abajo*/
} DIRECTION;

#endif
