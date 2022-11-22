/**
 * @brief Implementa la interfaz del juego y todos los callbacks asociados
 * a cada comando
 *
 * @file game.c
 * @author Daniel Molano y Carolina Monedero
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "../include/game.h"
#include "../include/game_management.h"
#include "../include/player.h"
#include "../include/object.h"
#include "../include/die.h"
#include "../include/command.h"
#include "../include/types.h"


#define N_CALLBACK 19 /*!< Numero maximo de callbacks */
#define TEXTO 60      /*!< Longitud de texto */

/**
* @brief Estructura de datos _Game
* @author Profesores de PPROG, modificado por el grupo F
* @date 10/04/2021
*/
struct _Game{
  Player* player;                       /*!<Puntero a la estructura Player*/
  Object* objects[MAX_OBJECTS + 1];     /*!<Puntero a la estructura Object*/
  Space* spaces[MAX_SPACES + 1];        /*!<Los espacios en el juego*/
  Link* links[MAX_LINKS + 1];           /*!<Contiene los enlaces del juego*/
  Die *die;                             /*!<Puntero a la estructura Die*/
  Command* command;                     /*!<Último comando introducido por el usuario*/
  char description[WORD_SIZE+1];        /*!<Última descripción del objeto*/
  int matriculas;                       /*!<Numero de vidas del jugador*/
  BOOL examen;                          /*!<Estado del jugador*/
  BOOL licenciado;                      /*!<Indica si terminas la partida*/
};

/**
* @brief Callbacks
*
* Define los callbacks
*/
typedef void (*callback_fn)(Game* game);

/*
* Listado de callbacks para cada comando del juego
*/

/**
* @brief callback UNKNOWN
* @author Profesores de PPROG
* @date 11/02/2021
* @param game Puntero a la estructura Game
*/
void game_callback_unknown(Game* game);


/**
* @brief callback EXIT
* @author Profesores de PPROG
* @date 11/02/2021
* @param game Puntero a la estructura Game
*/
void game_callback_exit(Game* game);

/**
* @brief El callback cuando el comando es 'next'.
* En este caso el jugador va al espacio que se encuentra
* al sur del que se encuentra
* @author Profesores PPROG
* @param game Puntero a la estructura Game
*/
void game_callback_next(Game* game);

/**
* @brief El callback cuando el comando es 'back'.
* En este caso el jugador va al espacio que se encuentra
* al norte del que se encuentra
* @author Profesores de PPROG
* @param game Puntero a la estructura Game
*/
void game_callback_back(Game* game);

/**
* @brief El callback cuando el comando es 'take'.
* El jugador coge un objeto del espacio en el que está
* si hay alguno
* @date 11/02/2021
* @author Carolina Monedero
* @param game puntero a la estructura Game
*/
void game_callback_take(Game *game);

/**
* @brief El callback cuando el comando es 'drop'.
* El jugador deja un objeto en el espacio en el que está
* si no hay ninguno en este
* @date 11/02/2021
* @author Carolina Monedero
* @param game puntero a la estructura Game
*/
void game_callback_drop(Game *game);

/**
* @brief El callback cuando el comando es 'right'.
* El jugador se mueve una casilla al este de la que
* se encuentra
* @date 10/03/2021
* @author Daniel Molano
* @param game puntero a la estructura Game
*/
void game_callback_right(Game *game);

/**
* @brief El callback cuando el comando es 'left'.
* El jugador se mueve una casilla al oeste de la que
* se encuentra
* @date 10/03/2021
* @author Daniel Molano
* @param game puntero a la estructura Game
*/
void game_callback_left(Game *game);

/**
* @brief El callback cuando el comando es 'roll'.
* Con este comando se tira el dado
* @date 10/03/2021
* @author Daniel Molano Caraballo
* @param game puntero a la estructura Game
*/
void game_callback_roll(Game *game);

/**
* @brief El callback cuando el comando es 'move'.
* En este caso el jugador va al espacio que indique con
* north, south, east o west
* @date 03/04/2021
* @author Jaime Martinez
* @param game Puntero a la estructura Game
*/
void game_callback_move(Game* game);

/**
* @brief El callback cuando el comando es 'inspect'
* Inspecciona el espacio o los objetos
* @date 10/04/2021
* @author Carolina Monedero Juzgado
* @param game Puntero a la estructura Game
*/
void game_callback_inspect(Game* game);

/**
* @brief El callback cuando el comando es 'turnon'
* Enciende un objeto que se puede iluminar
* @date 01/05/2021
* @author Daniel Molano
* @param game Puntero a la estructura Game
*/
void game_callback_turnon(Game* game);

/**
* @brief El callback cuando el comando es 'turnoff'
* Apaga un objeto que se puede iluminar
* @date 01/05/2021
* @author Daniel Molano
* @param game Puntero a la estructura Game
*/
void game_callback_turnoff(Game* game);

/**
* @brief El callback cuando el comando es 'open'
* Abre una puerta
* @date 01/05/2021
* @author Daniel Molano
* @param game Puntero a la estructura Game
*/
void game_callback_open(Game* game);

/**
* @brief El callback cuando el comando es 'save'
* Guarda el juego
* @date 01/05/2021
* @author Daniel Molano
* @param game Puntero a la estructura Game
*/
void game_callback_save(Game* game);

/**
* @brief El callback cuando el comando es 'open'
* Carga el juego
* @date 01/05/2021
* @author Daniel Molano
* @param game Puntero a la estructura Game
*/
void game_callback_load(Game* game);

/**
* @brief El callback cuando el comando es 'answer'
* Responde la pregunta
* @date 01/05/2021
* @author Daniel Molano
* @param game Puntero a la estructura Game
*/
void game_callback_answer(Game* game);

/**
* @brief El callback cuando el comando es 'pet'
* Acaricia animales
* @date 01/05/2021
* @author Daniel Molano
* @param game Puntero a la estructura Game
*/
void game_callback_pet(Game* game);

static callback_fn game_callback_fn_list[N_CALLBACK]={
  game_callback_unknown,
  game_callback_exit,
  game_callback_next,
  game_callback_back,
  game_callback_take,
  game_callback_drop,
  game_callback_right,
  game_callback_left,
  game_callback_roll,
  game_callback_move,
  game_callback_inspect,
  game_callback_turnon,
  game_callback_turnoff,
  game_callback_open,
  game_callback_save,
  game_callback_load,
  game_callback_answer,
  game_callback_pet
};


/**********FUNCIONES PRIVADAS**********/

/**
* @brief Establece la localización de un jugador cuyo
* id es pasado como argumento
* @author Profesores de PPROG, modificada por
* Daniel Molano
* @date 11/02/2021
* @param game Puntero a la estructura Game
* @param id Entero que indica el id del jugador
* @return STATUS, OK si todo ha ido bien o ERROR en
* caso contrario
*/
STATUS game_set_player_location(Game* game, Id id);

/**
* @brief Recupera el puntero a object en funcion del name
* @author Carolina Monedero y Daniel Molano
* @param game Puntero a la estructura Game
* @param name Nombre del object
* @return game->player o NULL
*/
Object* game_get_object_to_inspect(Game* game, char* name);

/**
* @brief Recupera el puntero a link en funcion del name
* @author Carolina Monedero y Daniel Molano
* @param game Puntero a la estructura Game
* @param name Nombre del object
* @return game->link o NULL
*/
Link* game_get_link_to_inspect(Game* game, char* name);

/**********IMPLEMENTACION DE LA INTERFAZ DEL JUEGO**********/

STATUS game_create(Game** game) {
  int i;

  (*game) = (Game*)malloc(sizeof(Game));

  if(!(*game)) return ERROR;

  for (i = 0; i < MAX_SPACES; i++) {
    (*game)->spaces[i] = NULL;
  }

  (*game)->player = NULL;
  for(i=0; i < MAX_OBJECTS; i++){
    (*game)->objects[i] = NULL;
  }

  for (i = 0; i < MAX_LINKS; i++){
    (*game)->links[i] = NULL;
  }

  (*game)->die = die_create(0);

  (*game)->command = command_create();


  if(command_set_cmd((*game)->command, NO_CMD) == ERROR){
    player_destroy((*game)->player);
    die_destroy((*game)->die);
    command_destroy((*game)->command);
    return ERROR;
  }

  (*game)->matriculas = 3;
  (*game)->examen = FALSE;
  (*game)->licenciado = FALSE;
  return OK;
}

STATUS game_create_from_file(Game** game, char* filename) {

  if(!filename) return ERROR;

  if (game_create(game) == ERROR){
    return ERROR;
  }

  if (game_management_load_space((*game), filename) == ERROR) return ERROR;

  if(game_management_load_objects((*game), filename) == ERROR) return ERROR;

  if(game_management_load_player((*game), filename) == ERROR) return ERROR;

  if(game_management_load_links((*game), filename) == ERROR) return ERROR;

  return OK;
}

STATUS game_destroy(Game* game) {
  int i;

  for (i = 0; (i < MAX_SPACES) && (game->spaces[i] != NULL); i++) {
    space_destroy(game->spaces[i]);
  }

  for (i = 0; (i < MAX_LINKS); i++) {
    link_destroy(game->links[i]);
  }

  if(player_destroy(game->player) == ERROR) return ERROR;
  if(die_destroy(game->die) == ERROR) return ERROR;
  if(command_destroy(game->command) == ERROR) return ERROR;

  for(i=0; i < MAX_OBJECTS; i++)
    if(object_destroy(game->objects[i]) == ERROR);

  free(game);

  return OK;
}

STATUS game_semi_destroy(Game* game){
  int i;

  for (i = 0; (i < MAX_SPACES) && (game->spaces[i] != NULL); i++) {
    space_destroy(game->spaces[i]);
    game->spaces[i] = NULL;
  }

  for (i = 0; (i < MAX_LINKS); i++) {
    link_destroy(game->links[i]);
    game->links[i] = NULL;
  }

  for(i=0; i < MAX_OBJECTS; i++){
    object_destroy(game->objects[i]);
    game->objects[i] = NULL;
  }

  player_destroy(game->player);
  game->player = NULL;

  die_destroy(game->die);
  game->die = NULL;
  
  return OK;
}

STATUS game_add_space(Game *game, Space *space){
  int i = 0;

  if (space == NULL) {
    return ERROR;
  }

  while ((i < MAX_SPACES) && (game->spaces[i] != NULL)){
    i++;
  }

  if (i >= MAX_SPACES) {
    return ERROR;
  }

  game->spaces[i] = space;

  return OK;
}

STATUS game_add_object(Game *game, Object *object){
  int i = 0;

  if (!game || !object) return ERROR;

  while((i < MAX_OBJECTS) && (game->objects[i] != NULL))
    i++;

  if (i >= MAX_OBJECTS) return ERROR;

  game->objects[i] = object;

  return OK;
}

STATUS game_add_link(Game *game, Link *l){
  int i = 0;

  if (!game || !l) return ERROR;

  while((i < MAX_LINKS) && (game->links[i] != NULL))
    i++;

  if (i >= MAX_LINKS) return ERROR;

  game->links[i] = l;

  return OK;
}

STATUS game_add_player(Game *game, Player *player){

  if (!game || !player) return ERROR;

  game->player = player;

  return OK;
}

Id game_get_space_id_at(Game* game, int position) {

  if (position < 0 || position >= MAX_SPACES) {
    return NO_ID;
  }

  return space_get_id(game->spaces[position]);
}

Space* game_get_space(Game* game, Id id){
  int i = 0;

  if (id == NO_ID) {
    return NULL;
  }

  for (i = 0; i<= MAX_SPACES && game->spaces[i] != NULL; i++) {
    if (id == space_get_id(game->spaces[i])){
      return game->spaces[i];
    }
  }

  return NULL;
}

STATUS game_set_player_location(Game* game, Id id) {

  if (id == NO_ID) {
    return ERROR;
  }

  if(player_set_location(game->player, id) == ERROR) return ERROR;

  return OK;

}

Id game_get_player_location(Game* game) {
  return player_get_location(game->player);
}

Id game_get_object_location(Game* game, Id object) {
  Set* s=NULL;
  int i;

  if (!game || object == NO_ID) return NO_ID;

  for (i=1; i <= MAX_SPACES && game->spaces[i] != NULL; i++){
    s = space_get_object(game->spaces[i]);
    if(set_has_id(s, object) == TRUE){
      return space_get_id(game->spaces[i]);
    }
  }

  return NO_ID;
}

STATUS game_update(Game* game, T_Command cmd) {

  if(command_set_cmd(game->command, cmd) == ERROR) return ERROR;

  (*game_callback_fn_list[cmd])(game);
  return OK;
}

T_Command game_get_last_command(Game* game){
  return command_get_cmd(game->command);
}

STATUS game_get_command_status(Game *game){

  if (!game) return ERROR;

  return OK;
}

void game_print_data(Game* game) {
  int i;

  printf("\n\n-------------\n\n");

  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    space_print(game->spaces[i]);
  }



  printf("=> Object location: ");
  for(i=1; i < MAX_OBJECTS && game->objects[i] != NULL; i++)
    printf("%d\n", (int)game_get_object_location(game, i));
  printf("=> Player location: %d\n", (int) player_get_location(game->player));
  printf("=> Links: \n");
  for (i = 0; game->links[i] != NULL; i++)
    link_print(game->links[i]);
  printf("prompt:> ");
}

BOOL game_is_over(Game* game) {
  return FALSE;
}

/**********IMPLEMENTACION DE LOS CALLBACK**********/

void game_callback_unknown(Game* game) {
}

void game_callback_exit(Game* game) {
}

void game_callback_next(Game* game) {
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;
  ESTADO estado;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = space_get_south(game->spaces[i]);
      estado = link_get_estado(space_get_south_link(game->spaces[i]));
      if (current_id != NO_ID && estado == ABIERTO) {
         game_set_player_location(game, current_id);
      }
      return;
    }
  }
}

void game_callback_back(Game* game) {
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;
  ESTADO estado;
  space_id = game_get_player_location(game);

  if (NO_ID == space_id) {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = space_get_north(game->spaces[i]);
      estado = link_get_estado(space_get_north_link(game->spaces[i]));
      if (current_id != NO_ID && estado == ABIERTO) {
  game_set_player_location(game, current_id);
      }
      return;
    }
  }
}

void game_callback_take(Game *game){
  Id player_id = NO_ID; /*localización del jugador*/
  Id object_location = NO_ID;
  Set* object_id = NULL; /*localización del objeto*/
  char aux[WORD_SIZE + 1] = " ";
  Object * obj = NULL;
  Id dependency;  /*Dependencia del objeto*/
  int i;
  Id* inventory=NULL; /*Inventario del jugador*/

  if(game->examen == TRUE) return;

  /*Comprueba si tenemos espacio suficiente en la mochila*/
  if(inventory_getNumObjects(player_get_inventory(game->player)) == inventory_getMaxTam(player_get_inventory(game->player))) return;

  /*Recuperamos el nombre del objeto*/
  strcpy(aux, command_get_extra(game->command));

  /*Recuperamos el objeto en funcion al nombre*/
  obj = game_get_object_to_inspect(game, aux);
  if(!obj) return;

  if(object_get_movable(obj) == FALSE) return;

  /*Si el player tiene le objeto return*/
  if(player_getObject_from_inventory(game->player, object_get_id(obj)) != NO_ID) return;

  /*Recupera el id del espacio donde esta el objeto*/
  object_location = game_get_object_location(game, object_get_id(obj));
  if(object_location == NO_ID) return;

  /*Recupera el id del espacio donde esta el player*/
  player_id = player_get_location(game->player);
  if(player_id == NO_ID) return;

  dependency = object_get_dependency(obj);
  inventory = set_getIds(inventory_getIds(player_get_inventory(game->player)));

  /*Si depende de algún objeto busca en el inventario para ver si el jugador lo tiene o no*/
  if(dependency != NO_ID){
    for(i=0; i < inventory_getNumObjects(player_get_inventory(game->player)); i++){
      if(inventory[i] == dependency)
        return;
    }
  }


  object_id = space_get_object(game_get_space(game, player_id));
  if(set_has_id(object_id, object_get_id(obj)) == FALSE) return;
  if (!object_id) return;

  set_del_id(object_id, object_get_id(obj));
  player_set_object(game->player, object_get_id(obj));

  if (strcasecmp(object_get_name(obj), "Titu") == 0){
    game->licenciado = TRUE;
  }

  return;


}

void game_callback_drop(Game *game){

  Id player_id = NO_ID; /*localización del jugador*/
  Id object_id = NO_ID;
  int i;
  char aux[WORD_SIZE + 1] = " ";
  Object* obj = NULL;

  if(game->examen == TRUE) return;

  strcpy(aux, command_get_extra(game->command));

  obj = game_get_object_to_inspect(game, aux);

  if(!obj) return;

  if(player_getObject_from_inventory(game->player, object_get_id(obj)) == NO_ID) return;

  player_id = player_get_location(game->player);
  if(player_id == NO_ID)
    return;

  object_id = object_get_id(obj);

  /*Busca el objeto a borrar y los objetos que dependen de él*/
  for(i=0; i < MAX_OBJECTS && game->objects[i] != NULL; i++){
    if(object_get_id(game->objects[i]) == object_get_id(obj) || object_id == object_get_dependency(game->objects[i])){
      set_del_id(inventory_getIds(player_get_inventory(game->player)), object_get_id(obj));
      set_add_id(space_get_object(game->spaces[player_id-1]), object_get_id(obj));
      /*return;*/
    }
  }

  return;
}

void game_callback_right(Game* game) {
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;
  ESTADO estado;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = space_get_east(game->spaces[i]);
      estado = link_get_estado(space_get_east_link(game->spaces[i]));
      if (current_id != NO_ID && estado == ABIERTO) {
        game_set_player_location(game, current_id);
      }
      return;
    }
  }
}

void game_callback_left(Game* game) {
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;
  ESTADO estado;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = space_get_west(game->spaces[i]);
      estado = link_get_estado(space_get_west_link(game->spaces[i]));
      if (current_id != NO_ID && estado == ABIERTO) {
        game_set_player_location(game, current_id);
      }
      return;
    }
  }
}

void game_callback_roll(Game *game){

  if(game->examen == TRUE) return;

  game_print_data(game);

  if(die_roll(game->die) == -1) return;

  return;

}

void game_callback_move(Game* game){
  char aux[WORD_SIZE + 1] = " ";
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;
  ESTADO estado;

  strcpy(aux, command_get_extra(game->command));
  if(aux == NULL)
    return;

  if (strcasecmp(aux, "North") == 0 || strcasecmp(aux, "n") == 0){
    space_id = game_get_player_location(game);

    if (NO_ID == space_id) {
      return;
    }

    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
      current_id = space_get_id(game->spaces[i]);
      if (current_id == space_id) {
        current_id = space_get_north(game->spaces[i]);
        estado = link_get_estado(space_get_north_link(game->spaces[i]));
        if (current_id != NO_ID && estado == ABIERTO) {
          game_set_player_location(game, current_id);
         }

        if(current_id == game_get_object_location(game, object_get_id(game_get_object_to_inspect(game,"exam"))))  game->examen = TRUE;
        return;
      }
     }
  } else if (strcasecmp(aux, "South") == 0 || strcasecmp(aux, "s") == 0){
    space_id = game_get_player_location(game);
    if (space_id == NO_ID) {
      return;
    }

    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
      current_id = space_get_id(game->spaces[i]);
      if (current_id == space_id) {
        current_id = space_get_south(game->spaces[i]);
        estado = link_get_estado(space_get_south_link(game->spaces[i]));
        if (current_id != NO_ID && estado == ABIERTO) {
          game_set_player_location(game, current_id);
        }

        if(current_id == game_get_object_location(game, object_get_id(game_get_object_to_inspect(game,"exam"))))  game->examen = TRUE;

        return;
      }
    }
  } else if(strcasecmp(aux, "East") == 0 || strcasecmp(aux, "e") == 0){
    space_id = game_get_player_location(game);
    if (space_id == NO_ID) {
      return;
    }

    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
      current_id = space_get_id(game->spaces[i]);
      if (current_id == space_id) {
        current_id = space_get_east(game->spaces[i]);
        estado = link_get_estado(space_get_east_link(game->spaces[i]));
        if (current_id != NO_ID && estado == ABIERTO) {
         game_set_player_location(game, current_id);
        }

        if(current_id == game_get_object_location(game, object_get_id(game_get_object_to_inspect(game,"exam"))))  game->examen = TRUE;

        return;
      }
    }
  } else if (strcasecmp(aux, "West") == 0 || strcasecmp(aux, "w") == 0){
    space_id = game_get_player_location(game);
    if (space_id == NO_ID) {
      return;
    }

   for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
      current_id = space_get_id(game->spaces[i]);
     if (current_id == space_id) {
        current_id = space_get_west(game->spaces[i]);
        estado = link_get_estado(space_get_west_link(game->spaces[i]));
        if (current_id != NO_ID && estado == ABIERTO) {
          game_set_player_location(game, current_id);
        }

        if(current_id == game_get_object_location(game, object_get_id(game_get_object_to_inspect(game,"exam"))))  game->examen = TRUE;

        return;
      }
    }
  } else if(strcasecmp(aux, "Up") == 0 || strcasecmp(aux, "u") == 0){
    space_id = game_get_player_location(game);
    if (space_id == NO_ID) {
      return;
    }
    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
      current_id = space_get_id(game->spaces[i]);
      if (current_id == space_id) {
        current_id = space_get_up(game->spaces[i]);
        estado = link_get_estado(space_get_up_link(game->spaces[i]));
        if (current_id != NO_ID && estado == ABIERTO) {
          game_set_player_location(game, current_id);
        }

        if(current_id == game_get_object_location(game, object_get_id(game_get_object_to_inspect(game,"exam"))))  game->examen = TRUE;

        return;
      }
    }
  } else if(strcasecmp(aux, "Down") == 0 || strcasecmp(aux, "d") == 0){
    space_id = game_get_player_location(game);
    if (space_id == NO_ID) {
      return;
    }
    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
      current_id = space_get_id(game->spaces[i]);
      if (current_id == space_id) {
        current_id = space_get_down(game->spaces[i]);
        estado = link_get_estado(space_get_down_link(game->spaces[i]));
        if (current_id != NO_ID && estado == ABIERTO) {
          game_set_player_location(game, current_id);
        }

        if(current_id == game_get_object_location(game, object_get_id(game_get_object_to_inspect(game,"exam"))))  game->examen = TRUE;

        return;
      }
    }
  }
}

void game_callback_inspect(Game* game){
  char aux[WORD_SIZE+1];
  char fin[WORD_SIZE + 1];
  Object *object = NULL;
  Player* player = NULL;
  Set* set = NULL;

  if(!game) return;

  aux[0] = '\0';
  fin[0] = '\0';

  strcpy(aux, command_get_extra(game->command));
  if (aux == NULL) return;

  object = game_get_object_to_inspect(game, aux);
  player = game_get_player(game);
  set = inventory_getIds(player_get_inventory(player));

  /*Si lo que se quiere inspeccionar es el espacio*/
  if ((strcasecmp(aux, "space") == 0) || (strcasecmp(aux, "s") == 0)){
    /*Si el espacio está iluminado se puede ver su descripción más detallada*/
    if(space_get_iluminacion(game_get_space(game,game_get_player_location(game))) == TRUE){
      /*strcat(fin, (char*)player_get_location(player));   Lo quito porque genera violacion de segmento */
      strcat(fin, space_get_description_detallada(game_get_space(game, game_get_player_location(game))));
      strcpy(game->description, fin);
    }
    /*Si el espacio está oscuro no se puede inspeccionar*/
    else{
      strcat(fin, "el espacio no esta iluminado. No puedes ver nada");
      strcpy(game->description, fin);
    }
    return;
  }

  /*Si lo que se quiere es inspeccionar un objeto*/
  else {
    /*Si el objeto en cuestión está en el inventario */
    if (set_has_id(set, object_get_id(object)) == TRUE){
      strcat(fin, "Objeto del inventario: ");
      strcat(fin, object_get_name(object));
      strcat(fin, " ");
      strcat(fin, object_get_description(game_get_object(game, object_get_id(object))));
      strcpy(game->description, fin);
      return;
    }
    /*Si el objeto en cuestión está en el espacio*/
    else {
      set = space_get_object(game_get_space(game, game_get_player_location(game)));
      if(set_has_id(set, object_get_id(object)) == FALSE){
      return;
    }
      strcat(fin, "Objeto del espacio: ");
      /*Si el espacio está iluminado podemos ver los objetos que hay en él e inspeccionarlos*/
      if(space_get_iluminacion(game_get_space(game, game_get_player_location(game))) == TRUE){
        strcat(fin, object_get_name(object));
        strcat(fin, " ");
        strcat(fin, object_get_description(game_get_object(game, object_get_id(object))));
        strcpy(game->description, fin);
      }
      /*Si está oscuro no podrá examinarlos*/
      else{
        strcat(fin, "El espacio esta oscuro. No se pueden ver los objetos");
        strcpy(game->description, fin);
      }
      return;
    }
  }

  return;

}

void game_callback_turnon(Game* game){

  char aux[WORD_SIZE+1];
  Object *object = NULL;
  Player* player = NULL;
  Set* set = NULL;

  if(!game) return;

  if(game->examen == TRUE) return;

  strcpy(aux, command_get_extra(game->command));
  if (aux == NULL) return;

  object = game_get_object_to_inspect(game, aux);
  player = game_get_player(game);
  set = inventory_getIds(player_get_inventory(player));

  if (set_has_id(set, object_get_id(object)) == TRUE){
      object_set_turnedon(object, TRUE);
      return;
    }

  else {
      set = space_get_object(game_get_space(game, game_get_player_location(game)));
      if(set_has_id(set, object_get_id(object)) == FALSE){
      return;
    }
      object_set_turnedon(object, TRUE);
      return;
    }


    return;
}

void game_callback_turnoff(Game* game){

  char aux[WORD_SIZE+1];
  Object *object = NULL;
  Player* player = NULL;
  Set* set = NULL;

  if(!game) return;

  if(game->examen == TRUE) return;

  strcpy(aux, command_get_extra(game->command));
  if (aux == NULL) return;

  object = game_get_object_to_inspect(game, aux);
  player = game_get_player(game);
  set = inventory_getIds(player_get_inventory(player));

  if (set_has_id(set, object_get_id(object)) == TRUE){
      object_set_turnedon(object, FALSE);
      return;
    }

  else {
      set = space_get_object(game_get_space(game, game_get_player_location(game)));
      if(set_has_id(set, object_get_id(object)) == FALSE){
      return;
    }
      object_set_turnedon(object, FALSE);
      return;
    }


    return;
}

void game_callback_open(Game* game){

  int i;
  char aux[WORD_SIZE+1];
  Link* l = NULL;
  Object* o = NULL;

  if(!game) return;

  if(game->examen == TRUE) return;

  strcpy(aux, command_get_extra(game->command));

  if(aux == NULL) return;

  l = game_get_link_to_inspect(game, aux);

  if(!l) return;

  strcpy(aux, command_get_last(game->command));

  if(aux == NULL) return;

  o = game_get_object_to_inspect(game, aux);

  if(!o) return;

  for(i=1; i <= MAX_OBJECTS && game->objects[i] != NULL ; i++){
    if(set_has_id(inventory_getIds(player_get_inventory(game->player)), object_get_id(o)) == TRUE){
      if(object_get_open(game->objects[i]) == link_get_id(l)) link_set_estado(l, ABIERTO);
     }
  }



  return;
}

void game_callback_save(Game* game){
  if(!game) return;

  game_management_save(game, command_get_extra(game->command));

  return;
}

void game_callback_load(Game* game){
  if(!game) return;

  game_management_load(&game, command_get_extra(game->command));

  return;
}

void game_callback_answer(Game* game){

  if(!game) return;

  if(strcasecmp(command_get_extra(game->command), "B") == 0){
    strcpy(game->description,"Respuesta correcta! Ya puedes coger la llave e ir a por tu diploma!");
    game->examen = FALSE;
  }else{
    strcpy(game->description,"Respuesta incorrecta, has perdido una matricula!");
    game_set_matriculas(game, game_get_matriculas(game)-1);
  }
}

void game_callback_pet(Game* game){
  if(!game) return;

  if(strcasecmp(command_get_extra(game->command), "doge") == 0){
    strcpy(game->description,"Woof Woof");
  }else{
    strcpy(game->description,"No puedes acariciar eso");
  }

}


/**
* @brief Recupera el puntero a player
* @author Daniel Molano Caraballo
* @param game Puntero a la estructura Game
* @return game->player o NULL
*/
Player* game_get_player(Game* game){

  if(!game) return NULL;

  return game->player;
}

/**
* @brief Recupera el puntero a Object en funcion del id
* @author Daniel Molano Caraballo
* @param game Puntero a la estructura Game
* @param id Id del object
* @return game->object[i] o NULL
*/
Object* game_get_object(Game* game, Id id){

  int i;

  if(!game || id < 0) return NULL;

  for(i = 0; i < MAX_OBJECTS && game->objects[i]  != NULL; i++){
    if(object_get_id(game->objects[i]) == id){
      return game->objects[i];
    }
  }

  return NULL;
}

Link* game_get_link(Game* game, Id id){

  int i;

  if(!game || id < 0) return NULL;

  for(i=0; i<MAX_LINKS && game->links[i] != NULL; i++){
    if(link_get_id(game->links[i]) == id){
      return game->links[i];
    }
  }



  return NULL;
}

/**
* @brief Recupera el puntero a die
* @author Daniel Molano Caraballo
* @param game Puntero a la estructura Game
* @return game->die o NULL
*/
Die* game_get_die(Game* game){

  if(!game) return NULL;

  return game->die;
}

/**
* @brief Recupera el puntero a command
* @author Daniel Molano Caraballo
* @param game Puntero a la estructura Game
* @return game->command o NULL
*/
Command* game_get_command(Game* game){

  if(!game) return NULL;

  return game->command;
}

/**
* @brief Recupera el puntero a object en funcion del name
* @author Carolina Monedero y Daniel Molano
* @param game Puntero a la estructura Game
* @param name Nombre del object
* @return game->player o NULL
*/
Object* game_get_object_to_inspect(Game* game, char* name){

  int i;

  if(!game || !name) return NULL;

  for(i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++){
    if(strcasecmp(object_get_name(game->objects[i]), name) == 0){
      return game->objects[i];
    }
  }

  return NULL;
}

Link* game_get_link_to_inspect(Game* game, char* name){

  int i;

  if(!game || !name) return NULL;

  for(i = 0; i < MAX_LINKS && game->links[i] != NULL; i++){
    if(strcasecmp(link_get_name(game->links[i]) ,name) == 0){
      return game->links[i];
    }
  }

  return NULL;
}

/**
* @brief Recupera el puntero a description
* @author Carolina Monedero Juzgado
* @param game Puntero a la estructura Game
* @return game->description o NULL
*/
char* game_get_description(Game* game){

  if(!game) return NULL;

  return game->description;
}

/**
* @brief Limpia el campo description
* @author Daniel Molano Caraballo
* @param game Puntero a la estructura Game
*/
void game_clear_description(Game* game){
  if(!game) return;
  strcpy(game->description,"\0");
  return;
}


int game_get_matriculas(Game* game){
  if(!game) return -1;
  return game->matriculas;
}

STATUS game_set_matriculas(Game* game, int m){
  if(!game || m < 0) return ERROR;
  game->matriculas = m;
  return OK;
}

BOOL game_get_licenciado(Game* game){
  if(!game) return FALSE;
  return game->licenciado;
}