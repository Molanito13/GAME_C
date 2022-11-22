/**
 * @brief Define el motor gráfico
 *
 * @file graphic_engine.c
 * @author Profesores PPROG
 * @version 2.0
 * @date 07-02-2021
 * @copyright GNU Public License
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "../include/screen.h"
#include "../include/graphic_engine.h"
#include "../include/command.h"
#include "../include/die.h"
#include "../include/types.h"
#include "../include/set.h"
#include "../include/inventory.h"

#define STR 255                               /*!< Longitud maxima de la string str*/
#define DARK "#########################"      /*!< "Dibujo" cuando un espacio no esta iluminado*/
#define BLANK "                                                                                  "  /*!<Relleno de la casilla*/
#define LIMITS "   +----------------------------------------------------------------------------------+ " /*!<Limite de la casilla*/

/**
* @brief Estructura de datos Graphic_engine              
* @author Profesores de PPROG,                           
* @date 13-01-2015                                       
*/
struct _Graphic_engine{
  Area *map;          /*!< Area del mapa*/
  Area *descript;     /*!< Area de la descripcion*/
  Area *banner;       /*!< Area del banner*/
  Area *help;         /*!< Area de la ayuda*/
  Area *feedback;     /*!< Area del feedback*/
  Area *description;  /*!< Area de la descripcion*/
};

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
Graphic_engine *graphic_engine_create(){
  static Graphic_engine *ge = NULL;

  if (ge)
    return ge;

  screen_init();
  ge = (Graphic_engine *) malloc(sizeof(Graphic_engine));
  if (ge == NULL)
    return NULL;

  ge->map      = screen_area_init( 2, 1, 90, 30);
  ge->descript = screen_area_init(95, 1, 43, 34);
  ge->help     = screen_area_init( 2,36, 136,  3);
  ge->feedback = screen_area_init( 2,32, 90,  3);
  ge->description = screen_area_init(2, 40, 136, 3);

  return ge;
}

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
void graphic_engine_destroy(Graphic_engine *ge){
  if (!ge)
    return;

  screen_area_destroy(ge->map);
  screen_area_destroy(ge->descript);
  screen_area_destroy(ge->help);
  screen_area_destroy(ge->feedback);
  screen_area_destroy(ge->description);

  screen_destroy();
  free(ge);
}

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
void graphic_engine_paint_game(Graphic_engine *ge, Game *game){
  Id id_act = NO_ID,obj_loc = NO_ID;
  Space* space_act = NULL;
  char objA[STR] = "";
  char str[STR] = "";
  int i, j;
  T_Command last_cmd = UNKNOWN;
  int aux = 30;
  BOOL objI = FALSE;
  extern char *cmd_to_str[N_CMD][N_CMDT];

  /* Paint the in the map area */
  screen_area_clear(ge->map);

  if ((id_act = game_get_player_location(game)) != NO_ID){
    space_act = game_get_space(game, id_act);  



    /*CASILLA ACTUAL*/

    for(i=1; i <= MAX_OBJECTS && game_get_object(game,i) != NULL ; i++){
      if(game_get_object_location(game, object_get_id(game_get_object(game,i))) == id_act){
        if(space_get_iluminacion(space_act) == TRUE){
          strcat(objA, object_get_name(game_get_object(game,i)));
        } else{
          for(j=1; j <= MAX_OBJECTS && game_get_object(game,j) != NULL ; j++){
            if(set_has_id(inventory_getIds(player_get_inventory(game_get_player(game))), object_get_id(game_get_object(game,j))) == TRUE && object_get_turnedon(game_get_object(game,j)) == TRUE){
              objI = TRUE;
              strcat(objA, object_get_name(game_get_object(game,i)));
            }
          }

          if(objI == FALSE){
            strcat(objA,"####");
          }
        }
      }else{
        strcat(objA,"    ");
      }
    }


    if (id_act != NO_ID) {

      sprintf(str, "  ");
      screen_area_puts(ge->map, str);
      sprintf(str, "%s", LIMITS);
      screen_area_puts(ge->map, str);
      sprintf(str, "   | %s                                                                          %2d |",player_get_name(game_get_player(game)),(int) id_act);
      screen_area_puts(ge->map, str);

      for(i=0;i<8;i++){
        sprintf(str, "   |%s|", BLANK);
        screen_area_puts(ge->map, str);
      }

      for(i = 0; i<3; i++){
        if(space_get_gdesc(space_act,i) == NULL){
          sprintf(str, "   |%s|", BLANK);
          screen_area_puts(ge->map, str);
        } else if (space_get_iluminacion(space_act) == TRUE){
          sprintf(str, "   |                          %s                               |", space_get_gdesc(space_act,i));
          screen_area_puts(ge->map, str);
        } else {
            for(j=1; j <= MAX_OBJECTS && game_get_object(game,j) != NULL ; j++){
              if(set_has_id(inventory_getIds(player_get_inventory(game_get_player(game))), object_get_id(game_get_object(game,j))) == TRUE && object_get_turnedon(game_get_object(game,j)) == TRUE){
                sprintf(str, "   |                          %s                               |", space_get_gdesc(space_act,i));
                objI = TRUE;
                screen_area_puts(ge->map, str);
               }
             }
          if(objI == FALSE){
            sprintf(str, "   |                          %s                               |", DARK);
            screen_area_puts(ge->map, str);
          }
          
        }
      }

      for(i=0;i<2;i++){
        sprintf(str, "   |%s|", BLANK);
        screen_area_puts(ge->map, str);
      }

      for(i = 0; i<3; i++){
        if(space_get_gdesc(space_act,i) == NULL){
          sprintf(str, "   |%s|", BLANK);
          screen_area_puts(ge->map, str);
        } else if (space_get_iluminacion(space_act) == TRUE){
          sprintf(str, "   |                          %s                               |", space_get_gdesc(space_act,i));
          screen_area_puts(ge->map, str);
        } else {
            for(j=1; j <= MAX_OBJECTS && game_get_object(game,j) != NULL ; j++){
              if(set_has_id(inventory_getIds(player_get_inventory(game_get_player(game))), object_get_id(game_get_object(game,j))) == TRUE && object_get_turnedon(game_get_object(game,j)) == TRUE){
                sprintf(str, "   |                          %s                               |", space_get_gdesc(space_act,i));
                objI = TRUE;
                screen_area_puts(ge->map, str);
               }
             }
          if(objI == FALSE){
            sprintf(str, "   |                          %s                               |", DARK);
            screen_area_puts(ge->map, str);
          }
          
        }
      }

      for(i=0;i<8;i++){
        sprintf(str, "   |%s|", BLANK);
        screen_area_puts(ge->map, str);
      }
      
      sprintf(str, "   | %s |",objA);
      screen_area_puts(ge->map, str);
      sprintf(str, "%s", LIMITS);
      screen_area_puts(ge->map, str);
    }
  }

  /* Paint in the description area */
  screen_area_clear(ge->descript);

  sprintf(str," ");
  screen_area_puts(ge->descript, str);

  sprintf(str,"  Matriculas restantes: %d" ,game_get_matriculas(game));
  screen_area_puts(ge->descript, str);
  sprintf(str," ");
  screen_area_puts(ge->descript, str);

  sprintf(str, "  Object location: ");
  screen_area_puts(ge->descript, str);


  for(i=1; i<= MAX_OBJECTS && game_get_object(game,i) != NULL; i++){
    if ((obj_loc = game_get_object_location(game, object_get_id(game_get_object(game,i)))) != NO_ID && space_get_iluminacion(game_get_space(game, obj_loc)) == TRUE){
      sprintf(str, "  %s:%d", object_get_name(game_get_object(game, i)), (int)obj_loc);
      screen_area_puts(ge->descript, str);
    }else{
      for(j=1; j <= MAX_OBJECTS && game_get_object(game,j) != NULL ; j++){
            if(set_has_id(inventory_getIds(player_get_inventory(game_get_player(game))), object_get_id(game_get_object(game,j))) == TRUE && object_get_turnedon(game_get_object(game,j)) == TRUE && game_get_player_location(game) == obj_loc){
              sprintf(str, "  %s:%d", object_get_name(game_get_object(game, i)), (int)obj_loc);
              screen_area_puts(ge->descript, str);
            }
      }
    }
  }

  sprintf(str," ");
  screen_area_puts(ge->descript, str);


  sprintf(str,"  Player object: ");
  screen_area_puts(ge->descript, str);

  for(i=1; i <= MAX_OBJECTS && game_get_object(game,i) != NULL ; i++){
    if(set_has_id(inventory_getIds(player_get_inventory(game_get_player(game))), object_get_id(game_get_object(game,i))) == TRUE){
      sprintf(str, "  %s", object_get_name(game_get_object(game, i)));
      screen_area_puts(ge->descript, str);
     }
  }

  sprintf(str," ");
  screen_area_puts(ge->descript, str);

  sprintf(str, "  Last die value: %d", die_get_value(game_get_die(game)));
  screen_area_puts(ge->descript, str);

  sprintf(str," ");
  screen_area_puts(ge->descript, str);


  sprintf(str, "  Casillas adyacentes:");
  screen_area_puts(ge->descript, str);

  if(space_get_north(game_get_space(game, space_get_id(space_act))) != NO_ID && link_get_estado(space_get_north_link(game_get_space(game, space_get_id(space_act)))) == ABIERTO){
    sprintf(str, "  Norte: %ld  Estado: Abierto  Link: %ld", space_get_north(game_get_space(game, space_get_id(space_act))), link_get_id(space_get_north_link(game_get_space(game, space_get_id(space_act)))));
    screen_area_puts(ge->descript, str);
  } else if(space_get_north(game_get_space(game, space_get_id(space_act))) != NO_ID && link_get_estado(space_get_north_link(game_get_space(game, space_get_id(space_act)))) == CERRADO){
    sprintf(str, "  Norte: %ld  Estado: Cerrado  Link: %ld", space_get_north(game_get_space(game, space_get_id(space_act))), link_get_id(space_get_north_link(game_get_space(game, space_get_id(space_act)))));
    screen_area_puts(ge->descript, str);
  }

  if(space_get_east(game_get_space(game, space_get_id(space_act))) != NO_ID && link_get_estado(space_get_east_link(game_get_space(game, space_get_id(space_act)))) == ABIERTO){
    sprintf(str, "  Este:  %ld  Estado: Abierto  Link: %ld", space_get_east(game_get_space(game, space_get_id(space_act))), link_get_id(space_get_east_link(game_get_space(game, space_get_id(space_act)))));
    screen_area_puts(ge->descript, str);
  } else if(space_get_east(game_get_space(game, space_get_id(space_act))) != NO_ID && link_get_estado(space_get_east_link(game_get_space(game, space_get_id(space_act)))) == CERRADO){
    sprintf(str, "  Este:  %ld  Estado: Cerrado  Link: %ld", space_get_east(game_get_space(game, space_get_id(space_act))), link_get_id(space_get_east_link(game_get_space(game, space_get_id(space_act)))));
    screen_area_puts(ge->descript, str);
  }

  if(space_get_south(game_get_space(game, space_get_id(space_act))) != NO_ID && link_get_estado(space_get_south_link(game_get_space(game, space_get_id(space_act)))) == ABIERTO){
    sprintf(str, "  Sur:   %ld  Estado: Abierto  Link: %ld", space_get_south(game_get_space(game, space_get_id(space_act))), link_get_id(space_get_south_link(game_get_space(game, space_get_id(space_act)))));
    screen_area_puts(ge->descript, str);
  } else if(space_get_south(game_get_space(game, space_get_id(space_act))) != NO_ID && link_get_estado(space_get_south_link(game_get_space(game, space_get_id(space_act)))) == CERRADO){
    sprintf(str, "  Sur:   %ld  Estado: Cerrado  Link: %ld", space_get_south(game_get_space(game, space_get_id(space_act))), link_get_id(space_get_south_link(game_get_space(game, space_get_id(space_act)))));
    screen_area_puts(ge->descript, str);
  }

  if(space_get_west(game_get_space(game, space_get_id(space_act))) != NO_ID && link_get_estado(space_get_west_link(game_get_space(game, space_get_id(space_act)))) == ABIERTO){
    sprintf(str, "  Oeste: %ld  Estado: Abierto  Link: %ld", space_get_west(game_get_space(game, space_get_id(space_act))), link_get_id(space_get_west_link(game_get_space(game, space_get_id(space_act)))));
    screen_area_puts(ge->descript, str);
  } else if(space_get_west(game_get_space(game, space_get_id(space_act))) != NO_ID && link_get_estado(space_get_west_link(game_get_space(game, space_get_id(space_act)))) == CERRADO){
    sprintf(str, "  Oeste: %ld  Estado: Cerrado  Link: %ld", space_get_west(game_get_space(game, space_get_id(space_act))), link_get_id(space_get_west_link(game_get_space(game, space_get_id(space_act)))));
    screen_area_puts(ge->descript, str);
  }

  if(space_get_up(game_get_space(game, space_get_id(space_act))) != NO_ID && link_get_estado(space_get_up_link(game_get_space(game, space_get_id(space_act)))) == ABIERTO){
    sprintf(str, "  Piso superior: %ld  Estado: Abierto", space_get_up(game_get_space(game, space_get_id(space_act))));
    screen_area_puts(ge->descript, str);
  } else if(space_get_up(game_get_space(game, space_get_id(space_act))) != NO_ID && link_get_estado(space_get_up_link(game_get_space(game, space_get_id(space_act)))) == CERRADO){
    sprintf(str, "  Piso superior: %ld  Estado: Cerrado", space_get_up(game_get_space(game, space_get_id(space_act))));
    screen_area_puts(ge->descript, str);

  }

  if(space_get_down(game_get_space(game, space_get_id(space_act))) != NO_ID && link_get_estado(space_get_down_link(game_get_space(game, space_get_id(space_act)))) == ABIERTO){
    sprintf(str, "  Piso inferior: %ld  Estado: Abierto", space_get_down(game_get_space(game, space_get_id(space_act))));
    screen_area_puts(ge->descript, str);
  } else if(space_get_down(game_get_space(game, space_get_id(space_act))) != NO_ID && link_get_estado(space_get_down_link(game_get_space(game, space_get_id(space_act)))) == CERRADO){
    sprintf(str, "  Piso inferior: %ld  Estado: Cerrado", space_get_down(game_get_space(game, space_get_id(space_act))));
    screen_area_puts(ge->descript, str);
  }

  /* Paint in the help area */
  screen_area_clear(ge->help);
  sprintf(str, " The commands you can use are:");
  screen_area_puts(ge->help, str);
  sprintf(str, " move or m, take or t, drop or d, roll or rll, inspect or i, turnon or ton, turnoff or toff, open <lnkx> with <object> or o, save or s,");
  screen_area_puts(ge->help, str);
  sprintf(str, " load or lo, answer or a");
  screen_area_puts(ge->help, str);


  /* Paint in the feedback area */
  last_cmd = game_get_last_command(game);
  sprintf(str, " %s (%s)", cmd_to_str[last_cmd-NO_CMD][CMDL], cmd_to_str[last_cmd-NO_CMD][CMDS]);
  screen_area_puts(ge->feedback, str);
  sprintf(str," ");
  screen_area_puts(ge->feedback, str);

  screen_area_clear(ge->description);
  sprintf(str," ");
  screen_area_puts(ge->description, str);

  if(strcasecmp(command_get_log(game_get_command(game)), "anser") == 0 || strcasecmp(command_get_log(game_get_command(game)), "a") == 0 ){
    aux += strlen(game_get_description(game));
    sprintf(str, " > %s ", game_get_description(game));
    screen_area_puts(ge->description, str);
    game_clear_description(game);
  }else  if(strcasecmp(command_get_log(game_get_command(game)), "inspect") == 0 || strcasecmp(command_get_log(game_get_command(game)), "i") == 0 ){
    aux += strlen(game_get_description(game));
    sprintf(str, " > %s ", game_get_description(game));
    screen_area_puts(ge->description, str);
    game_clear_description(game);
  }else if(strcasecmp(command_get_log(game_get_command(game)), "pet") == 0 || strcasecmp(command_get_log(game_get_command(game)), "p") == 0 ){
    sprintf(str, "> %s ", game_get_description(game));
    screen_area_puts(ge->description, str);
    game_clear_description(game);
  } else if(strcasecmp(command_get_log(game_get_command(game)), "answer") != 0 || strcasecmp(command_get_log(game_get_command(game)), "a") != 0 ){
    sprintf(str, "> %s ", space_get_description(space_act));
    screen_area_puts(ge->description, str);
    game_clear_description(game);
  }
  /* Dump to the terminal */
  screen_paint();
  printf("prompt:> ");
}
