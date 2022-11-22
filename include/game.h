/**
 * @brief Implementa la interfaz del juego y todos los callbacks asociados
 * a cada comando
 *
 * @file game.h
 * @author Daniel Molano y Carolina Monedero
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h"
#include "player.h"
#include "object.h"
#include "die.h"
#include "inventory.h"

/**
* @brief Game def
*
* Esta estructura define un Game
*/
typedef struct _Game Game;

/**
* @brief Inicializa una nueva estructura Game
* @author Profesores de PPROG, modificada por
* Daniel Molano y Carolina Monedero
* @date 02/03/2021
* @param game Puntero a la estructura Game
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS game_create(Game** game);

/**
* @brief Crea un nuevo juego a partir de un archivo
* cuyo nombre es pasado como argumento
* @author Profesores de PPROG, modificada por Daniel Molano
* @date 11/02/2021
* @param game Puntero a la estructura Game
* @param filename fichero desde el que se crea
* el juego
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS game_create_from_file(Game** game, char* filename);

/**
* @brief Actualiza el dato last_cmd de la estructura
* Game con el último comando que ha sido introducido
* @author Profesoresde PPROG
* @param game Puntero a la estructura Game
* @param cmd Último comando introducido
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS game_update(Game* game, T_Command cmd);

/**
* @brief Destruye la estructura Game y libera memoria
* @author Profesores de PPROG, modificada por
* Daniel Molano y Carolina Monedero
* @date 02/03/2021
* @param game Puntero a la estructura Game
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS game_destroy(Game* game);

/**
* @brief Semi-destruye la estructura Game y libera memoria
* @author Daniel Molano
* @date 09/05/2021
* @param game Puntero a la estructura Game
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS game_semi_destroy(Game* game);

/**
* @brief Añade un nuevo espacio si no se ha llegado
* al número
* máximo de espacios determinado
* @author Profesores de PPROG
* @param game Puntero a la estructura Game
* @param space Puntero a la estructura Space
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS game_add_space(Game *game, Space *space);

/**
* @brief Añade un nuevo objeto si no se ha llegado
* al número
* máximo de objetos determinado
* @author Carolina Monedero
* @param game Puntero a la estructura Game
* @param object Puntero a la estructura Object
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS game_add_object(Game *game, Object *object);

/**
* @brief Añade un nuevo player
* @author Carolina Monedero
* @param game Puntero a la estructura Game
* @param player Puntero a la estructura player
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS game_add_player(Game* game, Player* player);

/**
* @brief Está función siempre devuelve FALSE
* @author Profesoresde PPROG
* @param game Puntero a la estructura Game
* @return FALSE
*/
BOOL game_is_over(Game* game);

/**
* @brief Imprime la información del juego
* @author Profesores de PPROG, modificada por
* Daniel Molano
* @date 11/02/2021
* @param game Puntero a la estructura Game
*/
void game_print_data(Game* game);

/**
* @brief A través del id pasado como argumento, devuelve
* la estructura con dicho id
* @author Profesores de PPROG
* @param game Puntero a la estructura Game
* @param id Entero que indica el id del espacio
* @return Estructura Space
*/
Space* game_get_space(Game* game, Id id);

/**
* @brief Establece la locacización de un objeto
* cuyo id es pasado como argumento
* @author Profesores de PPROG, modificada por
* Daniel Molano
* @date 11/02/2021
* @param game Puntero a la estructura Game
* @return STATUS, OK si todo ha ido bien o ERROR en caso contrario
*/
Id game_get_player_location(Game* game);

/**
* @brief Devuelve el id del espacio
* @author Profesores de PPROG, modificada por Daniel Molano
* @date 11/02/2021
* @param game Puntero a la estructura Game
* @param object Id del object
* @return El Id del objeto
*/
Id game_get_object_location(Game* game, Id object);

/**
* @brief Devuelve el último comando que ha sido
* introducido por el usuario
* @author Profesoresde PPROG
* @param game Puntero a la estructura Game
* @return Último comando
*/
T_Command game_get_last_command(Game* game);

/**
* @brief Devuelve el estado de la ejecucion del comando
* introducido por el usuario
* @author Carolina Monedero
* @date 18/03/2021
* @param game Puntero a la estructura Game
* @return Estado del comando
*/
STATUS game_get_command_status(Game *game);

/**
* @brief Recupera el puntero a command
* @author Daniel Molano Caraballo
* @param game Puntero a la estructura Game
* @return game->command o NULL
*/
Command* game_get_command(Game* game);

/**
* @brief Recupera el puntero a die
* @author Daniel Molano Caraballo
* @param game Puntero a la estructura Game
* @return game->die o NULL
*/
Die* game_get_die(Game* game);

/**
* @brief Recupera el puntero a Object en funcion del id
* @author Daniel Molano Caraballo
* @param game Puntero a la estructura Game
* @param id Id del object
* @return game->object[i] o NULL
*/
Object* game_get_object(Game* game, Id id);

/**
* @brief Recupera el puntero a player
* @author Daniel Molano Caraballo
* @param game Puntero a la estructura Game
* @return game->player o NULL
*/
Player* game_get_player(Game* game);

/**
* @brief Recupera el puntero a description
* @author Carolina Monedero Juzgado
* @param game Puntero a la estructura Game
* @return game->description o NULL
*/
char* game_get_description(Game* game);

/**
* @brief Limpia el campo description
* @author Daniel Molano Caraballo
* @param game Puntero a la estructura Game
*/
void game_clear_description(Game* game);

/**
* @brief Devuelve el id del espacio en una posición
* determinada
* @author Profesores de PPROG
* @param game Puntero a la estructura Game
* @param position Entero que indica una posición
* @return El Id del espacio
*/
Id game_get_space_id_at(Game* game, int position);

/**
* @brief Recupera el puntero a Link en funcion del id
* @author Daniel Molano Caraballo
* @param game Puntero a la estructura Game
* @param id Id del link
* @return game->links[i] o NULL
*/
Link* game_get_link(Game* game, Id id);

/**
* @brief Añade un nuevo link
* @author Carolina Monedero
* @param game Puntero a la estructura Game
* @param l Puntero a la estructura link
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS game_add_link(Game *game, Link *l);

/**
* @brief Devuelve el numero de vidas restantes
* @author Daniel Molano
* @param game Puntero a la estructura Game
* @return -1 si ha habido error o numero de matriculas
*/
int game_get_matriculas(Game* game);


/**
* @brief Actualiza el numero de vidas restantes
* @author Daniel Molano
* @param game Puntero a la estructura Game
* @param m nuevo numero de matriculas
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS game_set_matriculas(Game* game, int m);

/**
* @brief Devuelve el estado del jugador
* @author Daniel Molano
* @param game Puntero a la estructura Game
* @return BOOL, TRUE si ha recogido el objeto clave o FALSE en caso contrario
*/
BOOL game_get_licenciado(Game* game);
#endif
