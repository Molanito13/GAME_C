/**
 * @brief Define la pantalla
 *
 * @file screen.c
 * @author Profesores PPROG
 * @version 2.0
 * @date 07-02-2021
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/screen.h"

#pragma GCC diagnostic ignored "-Wpedantic"

#define ROWS 44                           /*!<Alto de la pantalla*/
#define COLUMNS 140                       /*!<Largo de la pantalla*/
#define TOTAL_DATA (ROWS * COLUMNS) + 1   /*!<Cantidad maxima de elementos en pantalla*/

#define BG_CHAR '~'                       /*!<caracter BG*/
#define FG_CHAR ' '                       /*!<Caracter FG*/
#define PROMPT " prompt:> "               /*!<String prompt*/

#define ACCESS(d, x, y) (d + ((y) * COLUMNS) + (x)) /*!<Area de la pantalla*/

/**
* @brief Estructura de datos Area
* @author Profesores de PPROG
* @date 11/02/2021
*/
struct _Area{
  int x;        /*!<Valor X*/
  int y;        /*!<Valor Y*/
  int width;    /*!<Ancho*/
  int  height;  /*!<Alto*/
  char *cursor; /*!<Cursor*/
};

/**
* @brief Data
*
* Material proporcionado pro el profesorado
*/
char *__data;

/****************************/
/*     Private functions    */
/****************************/

/**
* @brief Detecta la posicion del cursor
* @author Profesores PPROG
* @param area Puntero a la estructura Area
* @return int, area
*/
int  screen_area_cursor_is_out_of_bounds(Area* area);

/**
* @brief Desconocido
* @author Profesores PPROG
* @param area Puntero a la estructura Area
*/
void screen_area_scroll_up(Area* area);

/**
* @brief Desconocido
* @author Profesores PPROG
* @param str String a sustituir
*/
void screen_utils_replaces_special_chars(char* str);

/****************************/
/* Functions implementation */
/****************************/

void screen_init(){
  screen_destroy(); /* Dispose if previously initialized */
  __data = (char *) malloc(sizeof(char) * TOTAL_DATA);

  if (__data){
    memset(__data, (int) BG_CHAR, TOTAL_DATA); /*Fill the background*/
    *(__data + TOTAL_DATA - 1) = '\0';         /*NULL-terminated string*/
  }
}

void screen_destroy(){
  if (__data)
    free(__data);
}

void screen_paint(){
  char *src = NULL;
  char dest[COLUMNS + 1];
  int i=0;

  memset(dest, 0, COLUMNS + 1);

  if (__data){
    /* puts(__data); */ /*Dump data directly to the terminal*/
    /*It works fine if the terminal window has the right size*/

    puts("\033[2J"); /*Clear the terminal*/
    for (src=__data; src < (__data + TOTAL_DATA - 1); src+=COLUMNS){
      memcpy(dest, src, COLUMNS);
      for (i=0; i<COLUMNS; i++){
	if (dest[i] == BG_CHAR){
	  printf("\033[0;35;45m%c\033[0m", dest[i]); /* fg:blue(34);bg:blue(44) */
	}else{
	  printf("\033[0;30;47m%c\033[0m", dest[i]); /* fg:black(30);bg:white(47)*/
	}
      }
      printf("\n");
    }
  }
}

Area* screen_area_init(int x, int y, int width, int height){
  int i = 0;
  Area* area = NULL;

  if ( (area  = (Area*) malloc (sizeof(struct _Area))) ){
    *area = (struct _Area) {x, y, width, height, ACCESS(__data, x, y)};

    for (i=0; i < area->height; i++)
      memset(ACCESS(area->cursor, 0, i), (int) FG_CHAR, (size_t) area->width);
  }

  return area;
}

void screen_area_destroy(Area* area){
  if(area)
    free(area);
}

void screen_area_clear(Area* area){
  int i = 0;

  if (area){
    screen_area_reset_cursor(area);

    for (i=0; i < area->height; i++)
      memset(ACCESS(area->cursor, 0, i), (int) FG_CHAR, (size_t) area->width);
  }
}

void screen_area_reset_cursor(Area* area){
  if (area)
    area->cursor = ACCESS(__data, area->x, area->y);
}

void screen_area_puts(Area* area, char *str){
  int len = 0;
  char *ptr = NULL;

  if (screen_area_cursor_is_out_of_bounds(area))
    screen_area_scroll_up(area);

  screen_utils_replaces_special_chars(str);

  for (ptr = str; ptr < (str + strlen(str)); ptr+=area->width){
    memset(area->cursor, FG_CHAR, area->width);
    len = (strlen(ptr) < area->width)? strlen(ptr) : area->width;
    memcpy(area->cursor, ptr, len);
    area->cursor += COLUMNS;
  }
}

int screen_area_cursor_is_out_of_bounds(Area* area){
  return area->cursor > ACCESS(__data,
			       area->x + area->width,
			       area->y + area->height - 1);
}

void screen_area_scroll_up(Area* area){
  for(area->cursor = ACCESS(__data, area->x, area->y);
      area->cursor < ACCESS(__data, area->x + area->width, area->y + area->height - 2);
      area->cursor += COLUMNS){
    memcpy(area->cursor, area->cursor+COLUMNS, area->width);
  }
}

void screen_utils_replaces_special_chars(char* str){
  char *pch = NULL;

  /* Replaces acutes and tilde with '??' */
  while ((pch = strpbrk (str, "????????????????????????")))
    memcpy(pch, "??", 2);
}
