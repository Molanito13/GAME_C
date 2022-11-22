/**
* @brief Carga el juego
*
* @file game_management.c
* @author Carolina Monedero
* @version 1.0
* @date 10/03/2021
* Modificado el 09/02/2021
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../include/game_management.h"
#include "../include/link.h"
#include "../include/game.h"

STATUS game_management_load_space(Game *game, char *filename){
  FILE* file = NULL;
   char line[WORD_SIZE] = "";
   char name[WORD_SIZE] = "";
   char* toks = NULL;
   char fila1[WORD_SIZE+1] = "", fila2[WORD_SIZE+1] = "", fila3[WORD_SIZE+1] = "", desc[MAX_DESCRIPTION+1], desc_extra[MAX_DESCRIPTION+1] = "";
   Id id = NO_ID;
   Space* space = NULL;
   STATUS status = OK;
   BOOL lumin = 0;

   if (!filename) {
     return ERROR;
   }

   file = fopen(filename, "r");
   if (file == NULL) {
     return ERROR;
   }

   while (fgets(line, WORD_SIZE, file)) {
     if (strncmp("#s:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      toks = strtok(NULL, "|");
      toks = strtok(NULL, "|");
      toks = strtok(NULL, "|");
      toks = strtok(NULL, "|");
      lumin=atoi(toks);
      toks = strtok(NULL, "|");


      if(toks != NULL){
       if(strcmp(toks, " ") == 0){
        strcpy(fila1, "F");
       }else{
        strcpy(fila1, toks);
       }
      }
      toks = strtok(NULL, "|");
      if(toks != NULL){
       if(strcmp(toks, " ") == 0){
        strcpy(fila2, "F");
       }else{
        strcpy(fila2, toks);
       }
      }
      toks = strtok(NULL, "|");
      if(toks != NULL){
       if(strcmp(toks, " ") == 0){
        strcpy(fila3, "F");
       }else{
        strcpy(fila3, toks);
       }
      }
      toks = strtok(NULL, "|");
      strcpy(desc, toks);
      toks = strtok(NULL, "|");
      if(toks)
      strcpy(desc_extra, toks);
 #ifdef DEBUG
       printf("Leido: %ld|%s|%ld|%ld|%ld|%ld|%s|%s|%s|%s|%s|%d\n", id, name, north, east, south, west, fila1, fila2, fila3, desc, desc_extra,lumin);
 #endif
       space = space_create(id);
       if (space != NULL) {
         space_set_name(space, name);

         game_add_space(game, space);
         space_set_gdesc(space, fila1, fila2, fila3);
         space_set_iluminacion(space, lumin);
         space_set_description(space, desc);
         strcpy(&desc_extra[strlen(desc_extra)-2], "\0");
         space_set_description_detallada(space, desc_extra);

       }
    }
 }

   if (ferror(file)) {
     status = ERROR;
   }

   fclose(file);

   return status;
}

STATUS game_management_load_objects(Game *game, char *filename){
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char desc[MAX_DESCRIPTION] = "";
  char *toks = NULL;
  Object *object = NULL;
  STATUS st = OK;
  Id id = NO_ID, pos_ini = NO_ID, dep = NO_ID, open = NO_ID;
  int i = 0;
  BOOL movable = FALSE, illuminate = FALSE, on = FALSE;

  if (!filename) return ERROR;

  file = fopen(filename, "r");
  if (file == NULL)
    return ERROR;

  while(fgets(line, WORD_SIZE, file)){
    if (strncmp("#o:", line, 3) == 0){
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      pos_ini = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(desc, toks);
      toks = strtok(NULL, "|");
      if(toks)
      movable = atoi(toks);
      toks = strtok(NULL, "|");
      if(toks)
      dep = atol(toks);
      toks = strtok(NULL, "|");
      if(toks)
      open = atol(toks);
      toks = strtok(NULL, "|");
      if(toks)
      illuminate = atol(toks);
      toks = strtok(NULL, "|");
      if(toks)
      on = atol(toks);

 #ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%s|%s|%ld|%ld|%s|%s\n", id, name, pos_ini, movable, dep, open, illuminate, on);
 #endif
      object = object_create(id);

      if (object != NULL) {
        object_set_name(object, name);
        space_set_object(game_get_space(game, pos_ini), id);
        object_set_description(object, desc);
        object_set_movable(object, movable);
        object_set_dependency(object, dep);
        object_set_open(object, open);
        object_set_illuminate(object, illuminate);
        object_set_turnedon(object, on);
        game_add_object(game, object);
      }
    }
  }

   for(i=1; i <= MAX_OBJECTS; i++){
    set_add_id(space_get_object(game_get_space(game,pos_ini-1)), object_get_id(game_get_object(game,i-1)));
  }

  if (ferror(file))
    st = ERROR;

  fclose(file);
  return st;
}

STATUS game_management_load_player(Game* game, char* filename){
FILE *file = NULL;
char line[WORD_SIZE] = "";
char name[WORD_SIZE] = "";
char *toks = NULL;
Id id = NO_ID, pos_ini = NO_ID;
int t_mochila = 0, i;
Player *player = NULL;
STATUS st = OK;

if (!filename) return ERROR;

file = fopen(filename, "r");
if (file == NULL) return ERROR;

while(fgets(line, WORD_SIZE, file)){
  if (strncmp("#p:", line, 3) == 0){
    toks = strtok(line + 3, "|");
    id = atol(toks);
    toks = strtok(NULL, "|");
    strcpy(name, toks);
    toks = strtok(NULL, "|");
    pos_ini = atol(toks);
    toks = strtok(NULL, "|");
    t_mochila = atol(toks);
#ifdef DEBUG
    printf("Leido: %ld|%s|%ld|%d\n", id, name, pos_ini, t_mochila);
#endif
    player = player_create(id, t_mochila);

    if (player != NULL) {
      player_set_id(player, id);
      player_set_name(player, name);
      player_set_location(player, pos_ini + 1);
      player_set_maxTam_inventory(player, t_mochila);
      for(i=0;i<t_mochila;i++){
        toks = strtok(NULL, "|");
        if(toks != NULL) player_set_object(player, atol(toks));
      }
      game_add_player(game, player);

    }
  }
}

if(ferror(file))
  st = ERROR;

fclose(file);
return st;

}

STATUS game_management_load_links(Game* game, char* filename) {
FILE* f;
char nombre[WORD_SIZE] = "";
char line[WORD_SIZE] = "";
char dir[WORD_SIZE] = "";
char* tokens = NULL;
Id id = NO_ID;
Id primero, segundo;
Id estado;
Link *link;
Space *space1, *space2;
STATUS st = OK;

if (!filename)
  return ERROR;

f = fopen(filename, "r");
if (!f)
  return ERROR;


while (fgets(line, WORD_SIZE, f)) {
  if (strncmp("#l:", line, 3) == 0) {
    tokens = strtok(line + 3, "|");
    id = atol(tokens);
    tokens = strtok(NULL, "|");
    strcpy(nombre, tokens);
    tokens = strtok(NULL, "|");
    primero = atol(tokens);
    tokens = strtok(NULL, "|");
    segundo = atol(tokens);
    tokens = strtok(NULL, "|");
    estado = atol(tokens);
    tokens = strtok(NULL, "|");
    strcpy(dir,tokens);

#ifdef DEBUG
    printf("Leido: %ld|%s|%ld|%ld|%ld|%s\n", id, nombre, primero, segundo, estado, dir);
#endif

    if (id != NO_ID) {
      link = link_create(id);
      link_set_name(link, nombre);
      link_set_id_primero(link, primero);
      link_set_id_segundo(link, segundo);
      link_set_estado(link, estado);
      link_set_dir(link, dir);

      space1 = game_get_space(game, primero);
      space2 = game_get_space(game, segundo);
      strcpy(&dir[strlen(dir) - 2], "\0");

      if(strcmp(dir,"NS")==0){
        space_set_south(space1, link);
        space_set_north(space2, link);
      } else if(strcmp(dir,"OE")==0){
          space_set_east(space1, link);
          space_set_west(space2, link);
      } else{
          space_set_down(space1, link);
          space_set_up(space2, link);
      }

      /*
      if(primero + 1 == segundo) {
        space_set_south(space1, link);
        space_set_north(space2, link);
      } else if (primero + 8 == segundo){
          space_set_east(space1, link);
          space_set_west(space2, link);
      } else {
         space_set_east(space1, link);
      }
      */
      game_add_link(game, link);
    }
  }



}



if (ferror(f)) {
  st = ERROR;
}

fclose(f);

return st;
}


STATUS game_management_save(Game* game, char* f){
  FILE* f1 = NULL;
  Id space = -1, object = -1;
  int i = 0;

  if(!game || !f) return ERROR;

  f1 = fopen(f, "w");
  if(!f1) return ERROR;

  space = game_get_space_id_at(game, i);

  for(i=1; i <= MAX_SPACES && game_get_space(game, space) != NULL; i++){
    space = game_get_space_id_at(game, i);
    if(space == NO_ID) break;
    fprintf(f1, "#s:");
    fprintf(f1, "%ld|", game_get_space_id_at(game, i-1));
    fprintf(f1, "%s|", space_get_name(game_get_space(game, i)));
    fprintf(f1, "%ld|", space_get_north(game_get_space(game, i)));
    fprintf(f1, "%ld|", space_get_east(game_get_space(game, i)));
    fprintf(f1, "%ld|", space_get_south(game_get_space(game, i)));
    fprintf(f1, "%ld|", space_get_west(game_get_space(game, i)));
    fprintf(f1, "%d|", space_get_iluminacion(game_get_space(game, i)));
    if(space_get_gdesc(game_get_space(game, i), 1) != NULL){
      if(space_get_gdesc(game_get_space(game, i), 0) == NULL){
        fprintf(f1, " |");
      }else{
        fprintf(f1, "%s|", space_get_gdesc(game_get_space(game, i), 0));
      }

      fprintf(f1, "%s|", space_get_gdesc(game_get_space(game, i), 1));
      if(space_get_gdesc(game_get_space(game, i), 2) == NULL){
        fprintf(f1, " |");
      }else{
        fprintf(f1, "%s|", space_get_gdesc(game_get_space(game, i), 2));
      }
      
    }else{
      fprintf(f1, " |");
      fprintf(f1, " |");
      fprintf(f1, " |");
    }
    fprintf(f1, "%s|", space_get_description(game_get_space(game, i)));
    fprintf(f1, "%s", space_get_description_detallada(game_get_space(game, i)));
    
    fprintf(f1, "\n");

  }
    /*Ultima casilla*/
    fprintf(f1, "#s:");
    fprintf(f1, "%ld|", game_get_space_id_at(game, i-1));
    fprintf(f1, "%s|", space_get_name(game_get_space(game, i)));
    fprintf(f1, "%ld|", space_get_north(game_get_space(game, i)));
    fprintf(f1, "%ld|", space_get_east(game_get_space(game, i)));
    fprintf(f1, "%ld|", space_get_south(game_get_space(game, i)));
    fprintf(f1, "%ld|", space_get_west(game_get_space(game, i)));
    fprintf(f1, "%d|", space_get_iluminacion(game_get_space(game, i)));
    if(space_get_gdesc(game_get_space(game, i), 1) != NULL){
      if(space_get_gdesc(game_get_space(game, i), 0) == NULL){
        fprintf(f1, " |");
      }else{
        fprintf(f1, "%s|", space_get_gdesc(game_get_space(game, i), 0));
      }

      fprintf(f1, "%s|", space_get_gdesc(game_get_space(game, i), 1));
      if(space_get_gdesc(game_get_space(game, i), 2) == NULL){
        fprintf(f1, " |");
      }else{
        fprintf(f1, "%s|", space_get_gdesc(game_get_space(game, i), 2));
      }
      
    }else{
      fprintf(f1, " |");
      fprintf(f1, " |");
      fprintf(f1, " |");
    }
    fprintf(f1, "%s|", space_get_description(game_get_space(game, i)));
    fprintf(f1, "%s", space_get_description_detallada(game_get_space(game, i)));
    
    fprintf(f1, "\n");




  for(i=1; i<= MAX_OBJECTS && game_get_object(game, i) != NULL; i++){
    object = object_get_id(game_get_object(game, i));
    if(object == NO_ID){
      fclose(f1);
      return ERROR;
    }

    fprintf(f1, "#o:");
    fprintf(f1, "%ld|", object);
    fprintf(f1, "%s|", object_get_name(game_get_object(game, i)));
    fprintf(f1, "%ld|", game_get_object_location(game, i));
    fprintf(f1, "%s|", object_get_description(game_get_object(game, i)));
    fprintf(f1, "%d|", object_get_movable(game_get_object(game, i)));
    fprintf(f1, "%ld|", object_get_dependency(game_get_object(game, i)));
    fprintf(f1, "%ld|", object_get_open(game_get_object(game, i)));
    fprintf(f1, "%d|", object_get_illuminate(game_get_object(game, i)));
    fprintf(f1, "%d", object_get_turnedon(game_get_object(game, i)));
    fprintf(f1, "\n");
  }

  fprintf(f1, "#p:");
  fprintf(f1, "%ld|", player_get_id(game_get_player(game)));
  fprintf(f1, "%s|", player_get_name(game_get_player(game)));
  fprintf(f1, "%ld|", game_get_player_location(game)-1);
  fprintf(f1, "%d", player_get_maxTam_inventory(game_get_player(game)));
  for(i=0; i<MAX_OBJECTS; i++){
    if(player_getObject_from_inventory(game_get_player(game), i+1) != NO_ID){
      fprintf(f1, "|%ld", player_getObject_from_inventory(game_get_player(game), i+1));
    }
  }
  fprintf(f1, "\n");


  for(i=1; i<= MAX_LINKS && game_get_link(game, i) != NULL; i++){
    fprintf(f1, "#l:");
    fprintf(f1, "%d|", i);
    fprintf(f1, "%s|", link_get_name(game_get_link(game, i)));
    fprintf(f1, "%ld|", link_get_id_primero(game_get_link(game, i)));
    fprintf(f1, "%ld|", link_get_id_segundo(game_get_link(game, i)));
    fprintf(f1, "%d|", link_get_estado(game_get_link(game, i)));
    fprintf(f1, "%s", link_get_dir(game_get_link(game, i)));
  }

  fclose(f1);

  return OK;
}


STATUS game_management_load(Game** game, char* f){

  if(!f || !game) return ERROR;

  if(game_semi_destroy(*game) == ERROR) return ERROR;

  return OK;

}
