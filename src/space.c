/**
 * @brief Define un espacio
 *
 * @file space.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/types.h"
#include "../include/space.h"
#include "../include/link.h"

/**
* @brief Estructura de datos Space
* @author Profesores de PPROG
* @date 11/02/2021.
* Modificada por Adrián Martínez 20/04/2021
*/
struct _Space {
  Id id;                                          /*!<Id de la casilla*/
  char name[WORD_SIZE + 1];                       /*!<Nombre de la casilla*/
  Link* north;                                    /*!<Enlace con la casilla norte*/
  Link* south;                                    /*!<Enlace con la  casilla sur*/
  Link* east;                                     /*!<Enlace con la  casilla este*/
  Link* west;                                     /*!<Enlace con la  casilla oeste*/
  Link* up;                                       /*!<Enlace al piso de arriba*/
  Link* down;                                     /*!<Enlace al piso de abajo*/
  Set* objects;                                   /*!<Conjunto de objetos*/
  char gdesc[MAX_H][MAX_V];                       /*!<Descripcion grafica de los espacios*/
  char description[MAX_DESCRIPTION+1];            /*!<Descripción del espacio*/
  char description_detallada[MAX_DESCRIPTION+1];  /*!<Descripción mas detallada*/
  BOOL iluminado;                                 /*!<Estado de la iluminacion (FALSE == Luz apagada) */
};

Space* space_create(Id id) {
  Space *newSpace = NULL;

  if (id == NO_ID)
    return NULL;

  newSpace = (Space*) malloc(sizeof(Space));
  if (newSpace == NULL) {
    return NULL;
  }
  newSpace->id = id;

  newSpace->name[0] = '\0';
  newSpace->description[0] = '\0';
  newSpace->description_detallada[0] = '\0';

  newSpace->north = NULL;
  newSpace->south = NULL;
  newSpace->east = NULL;
  newSpace->west = NULL;
  newSpace->up = NULL;
  newSpace->down = NULL;

  newSpace->iluminado = TRUE;
  newSpace->objects = set_create();

  return newSpace;
}

STATUS space_destroy(Space* space) {


  if (!space) {
    return ERROR;
  }

  set_destroy(space->objects);

  free(space);

  return OK;
}

STATUS space_set_name(Space* space, char* name) {

  if (!space || !name) {
    return ERROR;
  }

  if (!strcpy(space->name, name)) {
    return ERROR;
  }

  return OK;
}

STATUS space_set_north(Space* space, Link* link) {

  if (!space || !link)
    return ERROR;

  space->north = link;

  return OK;
}

STATUS space_set_south(Space* space, Link* link) {

  if (!space || !link)
    return ERROR;

  space->south = link;

  return OK;
}

STATUS space_set_east(Space* space, Link* link) {

  if (!space || !link)
    return ERROR;

  space->east = link;

  return OK;
}

STATUS space_set_west(Space* space, Link* link) {

  if (!space || !link)
    return ERROR;

  space->west = link;

  return OK;
}

STATUS space_set_up(Space* space, Link* link) {

  if (!space || !link)
    return ERROR;

  space->up = link;

  return OK;
}

STATUS space_set_down(Space* space, Link* link) {

  if (!space || !link)
    return ERROR;

  space->down = link;

  return OK;
}

STATUS space_set_object(Space* space, Id value) {
  STATUS st;

  if (!space) {
    return ERROR;
  }

  st = set_add_id(space->objects, value);
  if (st == ERROR)
    return ERROR;

  return OK;
}

const char * space_get_name(Space* space) {

  if (!space) {
    return NULL;
  }
  return space->name;
}

Id space_get_id(Space* space) {

  if (!space) {
    return NO_ID;
  }
  return space->id;
}

Id space_get_north(Space* space) {

  if (!space) {
    return NO_ID;
  }
  return link_get_id_primero(space->north);
}

Id space_get_south(Space* space) {

  if (!space) {
    return NO_ID;
  }
  return link_get_id_segundo(space->south);
}

Id space_get_east(Space* space) {

  if (!space) {
    return NO_ID;
  }
  return link_get_id_segundo(space->east);
}

Id space_get_west(Space* space) {

  if (!space) {
    return NO_ID;
  }
  return link_get_id_primero(space->west);
}

Id space_get_up(Space* space) {

  if (!space) {
    return NO_ID;
  }
  return link_get_id_primero(space->up);
}

Id space_get_down(Space* space) {

  if (!space) {
    return NO_ID;
  }
  return link_get_id_segundo(space->down);
}

Link* space_get_north_link(Space* space) {

  if(!space)
    return NULL;

  return space->north;
}

Link* space_get_south_link(Space* space) {

  if(!space)
    return NULL;

  return space->south;
}

Link* space_get_east_link(Space* space) {

  if(!space)
    return NULL;

  return space->east;
}

Link* space_get_west_link(Space* space) {

  if(!space)
    return NULL;

  return space->west;
}

Link* space_get_up_link(Space* space) {

  if(!space)
    return NULL;

  return space->up;
}

Link* space_get_down_link(Space* space) {

  if(!space)
    return NULL;

  return space->down;
}

Set* space_get_object(Space* space) {

  if (!space) {
    return NULL;
  }
  return space->objects;
}

STATUS space_print(Space* space) {
  int i;
  Id idaux = NO_ID;

  if (!space) {
    return ERROR;
  }

  fprintf(stdout, "--> Space (Id: %ld; Name: %s; Iluminación: Luz ", space->id, space->name);
  if (space->iluminado == TRUE)
    fprintf(stdout,"encendida)\n");
  else
    fprintf(stdout,"apagada)\n");

  idaux = space_get_north(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> North link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No north link.\n");
  }

  idaux = space_get_south(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> South link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No south link.\n");
  }

  idaux = space_get_east(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> East link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No east link.\n");
  }

  idaux = space_get_west(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> West link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No west link.\n");
  }

  idaux = space_get_up(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> Up link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No up link.\n");
  }

  idaux = space_get_down(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> Down link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No down link.\n");
  }

  if (space_get_object(space)) {
    fprintf(stdout, "---> Objects in the space.\n");
    set_print(space->objects);
  } else {
    fprintf(stdout, "---> No object in the space.\n");
  }

  for(i=0; i < MAX_H; i++)
    fprintf(stdout, "%s\n", space->gdesc[i]);

  return OK;
}

STATUS space_set_gdesc(Space *space, char* fila1, char* fila2, char* fila3){

  if(!space || !fila1 || !fila2 || !fila3) return ERROR;

  if (!strcpy(space->gdesc[0], fila1)) return ERROR;
  if (!strcpy(space->gdesc[1], fila2)) return ERROR;
  if (!strcpy(space->gdesc[2], fila3)) return ERROR;

  return OK;

}

char* space_get_gdesc(Space *space, int fila){

  if (!space || fila < 0) return NULL;

  if(strcmp(space->gdesc[fila], "F") == 0) return NULL;

  return space->gdesc[fila];
}

STATUS space_set_description(Space* space, char* desc){

  if (!space || !desc) return ERROR;

  if (!strcpy(space->description, desc)) return ERROR;

  return OK;
}

STATUS space_set_description_detallada(Space* space, char* desc){

  if (!space || !desc) return ERROR;

  if (!strcpy(space->description_detallada, desc)) return ERROR;

  return OK;
}

const char* space_get_description(Space* space){

  if (!space) return NULL;

  return space->description;

}

const char* space_get_description_detallada(Space* space){

  if (!space) return NULL;

  return space->description_detallada;

}

STATUS space_set_iluminacion(Space *space, BOOL iluminacion) {
  if (!space) return ERROR;

  space->iluminado = iluminacion;

  return OK;
}

BOOL space_get_iluminacion(Space *space) {

  if (!space) return FALSE;

  return space->iluminado;
}
