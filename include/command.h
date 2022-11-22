/**
 * @brief Implementa la interpretación de los comandos
 *
 * @file command.h
 * @author Profesores PPROG, modificado por Carolina Monedero
 * @version 2.0
 * @date 10/02/2021
 * @copyright GNU Public License
 */

#ifndef COMMAND_H
#define COMMAND_H

#include "types.h"

#define N_CMDT 2  /*!< Numero de argumentos maximos */
#define N_CMD 19  /*!< Numero de comandos disponibles */

/**
* @brief Lista de posibles argumentos
*/
typedef enum enum_CmdType {
  CMDS,             /*!< comando*/
  CMDL              /*!< Comando extra */
} T_CmdType;

/**
* @brief Lista de posibles comandos
*/
typedef enum enum_Command {
  NO_CMD = -1,         /*!< No hay comando */
  UNKNOWN,             /*!< comando desconocido */
  EXIT,                /*!< Comando exit */
  NEXT,                /*!< Comando next */
  BACK,                /*!< Comando Back */
  TAKE,                /*!< Comando take */
  DROP,                /*!< comando drop */
  RIGHT,               /*!< Comando right */
  LEFT,                /*!< comando left*/
  ROLL,                /*!< comando roll */
  MOVE,                /*!< comando move*/
  INSPECT,             /*!< comando inspect*/
  TURNON,
  TURNOFF,
  OPEN,
  SAVE,
  LOAD,
  ANSWER,
  PET
} T_Command;

/**
* @brief Command def
*
* Esta estructura define un command
*/

typedef struct _Command Command;

/**
* @brief Recupera el input del usuario
*
* get_user_input Recupera el comando introducido por consola
*
* @date 10/02/2021
* @author: Profesores PPROG, modificado por Carolina Monedero
*
* @return Comando introducido por consola
*/
STATUS command_get_user_input(Command* c);

/**
* @brief Inicializa una nueva la estructura Command
* @date 10/03/2021
* @author: Daniel Molano
* @return Puntero al nuevo comando
*/
Command* command_create();

/**
* @brief Destruye la estructura Command
* @date 10/03/2021
* @author: Daniel Molano
* @param command puntero a la estructura Command
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS command_destroy(Command* command);

/**
* @brief Actualiza el comando
* @date 10/03/2021
* @author: Daniel Molano
* @param c puntero a la estructura Command
* @param cmd nuevo comando
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS command_set_cmd(Command* c, T_Command cmd);

/**
* @brief Recupera el comando
* @date 10/03/2021
* @author: Daniel Molano
* @param c puntero a la estructura Command
* @return el comando
*/
T_Command command_get_cmd(Command* c);

/**
* @brief Actualiza la cadena de caracteres extra
* @date 10/03/2021
* @author: Daniel Molano
* @param c puntero a la estructura Command
* @param newE nueva cadena de caracteres extra
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS command_set_extra(Command* c, char* newE);

/**
* @brief Recupera la cadena de caracteres extra
* @date 10/03/2021
* @author: Daniel Molano
* @param c puntero a la estructura Command
* @return la cadena de caracteres extra
*/
char* command_get_extra(Command* c);

/**
* @brief Recupera la cadena de caracteres log
* @date 10/03/2021
* @author: Daniel Molano
*
* @param c puntero a la estructura Command
* @return la cadena de caracteres del comando
*/
char* command_get_log(Command* c);

/**
* @brief Recupera la cadena de caracteres last
* @date 03/05/2021
* @author: Daniel Molano
*
* @param c puntero a la estructura Command
* @return la cadena de caracteres
*/
char* command_get_last(Command* c);

#endif
