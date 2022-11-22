/**
 * @brief Define el bucle del juego
 *
 * @file game_loop.c
 * @author Profesores PPROG
 * @version 2.0
 * @date 13-01-2020
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/graphic_engine.h"
#include "../include/command.h"
#include "../include/game.h"

/**
* @brief game_loop_init
*
* Mantiene la partida en marcha
*/
int game_loop_init(Game **game, Graphic_engine **gengine, char *file_name);

/**
* @brief game_loop_run
*
* Inicia la partida
*/
void game_loop_run(Game **game, Graphic_engine *gengine, int flag, FILE *f);

/**
* @brief game_loop_cleanup
*
* Libera todos los recursos asociados a la partida
*/
void game_loop_cleanup(Game **game, Graphic_engine *gengine, FILE *f, int flag);

/**
* @brief Main
*
* Main
*/
int main(int argc, char *argv[]) {
  Game *game = NULL;
  Graphic_engine *gengine;
  FILE *f = NULL;
  int flag = 0;/*Flag para saber si se ha ejecutado el programa con el argumento -l. flag = 0, sin -l*/

  if (argc < 2) {
    fprintf(stderr, "Use: %s <game_data_file>\n", argv[0]);
    return 1;
  }

  /*Si hay tres argumentos y el tercero es -l, se abre un nuevo fichero en modo lectura y ponemos el flag a 1*/
  if (argv[2] && strcmp(argv[2], "-l") == 0){
    f = fopen(argv[3], "w");
    flag = 1;
    if (f == NULL) return -1;
  }

  if (game_loop_init(&game, &gengine, argv[1]) ==  0){
    game_loop_run(&game, gengine, flag, f);
    game_loop_cleanup(&game, gengine, f, flag);
  }

  return 0;
}

/**
* @brief Inicializa la partida
*
* game_loop_init Inicializa el bucle que mantiene la partida activa
*
* @date 10/02/2021
* @author: Profesores PPROG
* @param game Puntero a la estructura del juego
* @param gengine Puntero al graphic engine
* @param file_name Puntero al nombre del fichero de datos
* @return  0 si todo ha ido bien o 1 en
* caso contrario
*/
int game_loop_init(Game **game, Graphic_engine **gengine, char *file_name){

  if (game_create_from_file(game, file_name) == ERROR) {
    fprintf(stderr, "Error while initializing game.\n");
    game_destroy((*game));
    return 1;
  }

  if ((*gengine = graphic_engine_create()) == NULL) {
    fprintf(stderr, "Error while initializing graphic engine.\n");
    game_destroy((*game));
    return 1;
  }

  return 0;
}

/**
* @brief Mantiene la partida
*
* game_loop_run Mantiene el bucle de la partida activo hasta que quiera el usuario
*
* @date 10/02/2021
* @author: Profesores PPROG
* @param game Puntero a la estructura del juego
* @param gengine Puntero al graphic engine
* @param f Fichero log
* @param flag Indica si se usa un fichero log
*/
void game_loop_run(Game **game, Graphic_engine *gengine, int flag, FILE *f){
    T_Command command = NO_CMD;
    char aux[1024];
    aux[0] = '\0';

  while ((command != EXIT) && !game_is_over((*game)) && (game_get_matriculas(*game) != 0) && (game_get_licenciado(*game) == FALSE)) {

    if((command == LOAD)){
      strcpy(aux, command_get_extra(game_get_command(*game)));
      command_destroy(game_get_command(*game));
      free(*game);
      game_loop_init(game, &gengine, aux);
    }

    graphic_engine_paint_game(gengine, (*game));
    command_get_user_input(game_get_command((*game)));
    command = command_get_cmd(game_get_command((*game)));
    game_update((*game), command);
    if (flag == 1){ /*Si se ha ejecutado con -l se escribe el comando ejecutado y el resultado en el fichero log*/

      fprintf(f, "%s %s %s: ", command_get_log(game_get_command((*game))), command_get_extra(game_get_command((*game))) ,command_get_last(game_get_command(*game)));
      if (game_get_command_status((*game)) == OK)
        fprintf(f, "OK \n");
      else
        fprintf(f, "ERROR \n");
    }

  }

  if(game_get_matriculas(*game) == 0){
    fprintf(stdout, "\n\n\n\n\n\nNUMERO DE MATRICULAS AGOTADAS\n\n\n\n\n\n");
  }

  if(game_get_licenciado(*game) == TRUE)
    fprintf(stdout, "\n\n\n\n\n\nTE HAS PASADO LA CARRERA!!!\n\n\n\n\n\n");
}

/**
* @brief Libera recursos
*
* game_loop_cleanup Libera los recursos asociados a la partida
*
* @date 10/02/2021
* @author: Profesores PPROG
* @param game Puntero a la estructura del juego
* @param gengine Puntero al graphic engine
* @param f Fichero log
* @param flag Indica si se usa un fichero log
*/
void game_loop_cleanup(Game **game, Graphic_engine *gengine, FILE *f, int flag){

  graphic_engine_destroy(gengine);
  if (flag == 1) /*Si se ha ejecutado el juego con -l, se cierra el fichero*/
    fclose(f);
  game_destroy((*game));
}
