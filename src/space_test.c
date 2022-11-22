/**
 * @brief Prueba el modulo Space
 *
 * @file space_test.c
 * @author Profesores Pprog
 * @version 3.0
 * @date 09-03-2021
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/space.h"
#include "../include/space_test.h"
#include "../include/test.h"
#include "../include/set.h"
#include "../include/link.h"

#define MAX_TESTS 70  /*!<Cantidad de pruebas a ejecutar*/

/**
 * @brief Funcion principal para la prueba del modulo Space
 *
 * Debe ejecutar uno o todos los tests
 *   1.- Sin parametros -> Se ejecutan todos los tests
 *   2.- Un numero significa que un test en particular es ejecutado
 *
 */
int main(int argc, char** argv) {

  int test = 0;
  int all = 1;

  if (argc < 2) {
    printf("Running all test for module Space:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }


  if (all || test == 1) test1_space_create();
  if (all || test == 2) test2_space_create();
  if (all || test == 3) test2_space_destroy();
  if (all || test == 4) test2_space_destroy();
  if (all || test == 5) test1_space_set_name();
  if (all || test == 6) test2_space_set_name();
  if (all || test == 7) test3_space_set_name();
  if (all || test == 8) test1_space_set_north();
  if (all || test == 9) test2_space_set_north();
  if (all || test == 10) test1_space_set_south();
  if (all || test == 11) test2_space_set_south();
  if (all || test == 12) test1_space_set_east();
  if (all || test == 13) test2_space_set_east();
  if (all || test == 14) test1_space_set_west();
  if (all || test == 15) test2_space_set_west();
  if (all || test == 16) test1_space_get_name();
  if (all || test == 17) test2_space_get_name();
  if (all || test == 18) test1_space_get_object();
  if (all || test == 19) test2_space_get_object();
  if (all || test == 20) test3_space_get_object();
  if (all || test == 21) test1_space_get_north();
  if (all || test == 22) test2_space_get_north();
  if (all || test == 23) test1_space_get_south();
  if (all || test == 24) test2_space_get_south();
  if (all || test == 25) test1_space_get_east();
  if (all || test == 26) test2_space_get_east();
  if (all || test == 27) test1_space_get_west();
  if (all || test == 28) test2_space_get_west();
  if (all || test == 29) test1_space_get_id();
  if (all || test == 30) test2_space_get_id();
  if (all || test == 31) test1_space_set_object();
  if (all || test == 32) test2_space_set_object();
  if (all || test == 33) test1_space_get_object();
  if (all || test == 34) test2_space_get_object();
  if (all || test == 35) test1_space_get_gdesc();
  if (all || test == 36) test2_space_get_gdesc();
  if (all || test == 37) test1_space_set_gdesc();
  if (all || test == 38) test2_space_set_gdesc();
  if (all || test == 39) test1_space_get_north_link();
  if (all || test == 40) test2_space_get_north_link();
  if (all || test == 41) test1_space_get_south_link();
  if (all || test == 42) test2_space_get_south_link();
  if (all || test == 43) test1_space_get_east_link();
  if (all || test == 44) test2_space_get_east_link();
  if (all || test == 45) test1_space_get_west_link();
  if (all || test == 46) test2_space_get_west_link();
  if (all || test == 47) test1_space_set_iluminacion();
  if (all || test == 48) test2_space_set_iluminacion();
  if (all || test == 49) test1_space_get_iluminacion();
  if (all || test == 50) test2_space_get_iluminacion();
  if (all || test == 51) test1_space_set_up();
  if (all || test == 52) test2_space_set_up();
  if (all || test == 53) test1_space_set_down();
  if (all || test == 54) test2_space_set_down();
  if (all || test == 55) test1_space_get_up();
  if (all || test == 56) test2_space_get_up();
  if (all || test == 57) test1_space_get_down();
  if (all || test == 58) test2_space_get_down();
  if (all || test == 59) test1_space_get_up_link();
  if (all || test == 60) test2_space_get_up_link();
  if (all || test == 61) test1_space_get_down_link();
  if (all || test == 62) test2_space_get_down_link();
  if (all || test == 63) test1_space_set_description();
  if (all || test == 64) test2_space_set_description();
  if (all || test == 65) test1_space_get_description();
  if (all || test == 66) test2_space_get_description();
  if (all || test == 67) test1_space_set_description_detallada();
  if (all || test == 68) test2_space_set_description_detallada();
  if (all || test == 69) test1_space_get_description_detallada();
  if (all || test == 70) test2_space_get_description_detallada();


  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_space_create() {
  int result;
  Space *s;
  s = space_create(5);
  result=s!=NULL ;
  PRINT_TEST_RESULT(result);
  space_destroy(s);
}

void test2_space_create() {
  Space *s;
  s = space_create(4);
  PRINT_TEST_RESULT(space_get_id(s) == 4);
  space_destroy(s);
}

void test1_space_destroy(){
  Space *s = NULL;

  s = space_create(4);
  PRINT_TEST_RESULT(space_destroy(s) == OK);
}

void test2_space_destroy(){
    Space *s = NULL;

    PRINT_TEST_RESULT(space_destroy(s) == ERROR);
}

void test1_space_set_name() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_name(s, "hola") == OK);
  space_destroy(s);
}

void test2_space_set_name() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_name(s, "hola") == ERROR);
}

void test3_space_set_name() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_name(s, NULL) == ERROR);
  space_destroy(s);
}

void test1_space_set_north() {
  Space *s;
  Link *l = NULL;

  s = space_create(5);
  l = link_create(1);
  link_set_id_primero(l, 5);
  link_set_id_segundo(l, 6);

  PRINT_TEST_RESULT(space_set_north(s, l) == OK);
  space_destroy(s);
  link_destroy(l);
}

void test2_space_set_north() {
  Space *s = NULL;
  Link *l = NULL;
  PRINT_TEST_RESULT(space_set_north(s, l) == ERROR);
}

void test1_space_set_south() {
  Space *s;
  Link *l;

  s = space_create(5);
  l = link_create(1);
  link_set_id_primero(l, 5);
  link_set_id_segundo(l, 4);

  PRINT_TEST_RESULT(space_set_south(s, l) == OK);
  space_destroy(s);
}

void test2_space_set_south() {
  Space *s = NULL;
  Link *l = NULL;
  PRINT_TEST_RESULT(space_set_south(s, l) == ERROR);
}

void test1_space_set_east() {
  Space *s;
  Link *l;

  s = space_create(5);
  l = link_create(1);
  link_set_id_primero(l, 5);
  link_set_id_segundo(l, 6);

  PRINT_TEST_RESULT(space_set_east(s, l) == OK);
  space_destroy(s);
}

void test2_space_set_east() {
  Space *s = NULL;
  Link *l = NULL;
  PRINT_TEST_RESULT(space_set_east(s, l) == ERROR);
}

void test1_space_set_west() {
  Space *s;
  Link *l;

  s = space_create(5);
  l = link_create(1);
  link_set_id_primero(l, 5);
  link_set_id_segundo(l, 4);

  PRINT_TEST_RESULT(space_set_west(s, l) == OK);
  space_destroy(s);
  link_destroy(l);
}

void test2_space_set_west() {
  Space *s = NULL;
  Link *l = NULL;
  PRINT_TEST_RESULT(space_set_west(s, l) == ERROR);
}

void test1_space_set_object() {
  Space *s;
  s = space_create(1);
  PRINT_TEST_RESULT(space_set_object(s,TRUE) == OK);
  space_destroy(s);
}

void test2_space_set_object() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_object(s,TRUE) == ERROR);
}

void test1_space_get_name() {
  Space *s;
  s = space_create(1);
  space_set_name(s, "adios");
  PRINT_TEST_RESULT(strcmp(space_get_name(s), "adios") == 0);
  space_destroy(s);
}

void test2_space_get_name() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_name(s) == NULL);
}

void test1_space_get_object() {
  Space *s;
  s = space_create(1);
  PRINT_TEST_RESULT(space_get_object(s) != NULL);
  space_destroy(s);
}

void test2_space_get_object() {
  Space *s = NULL;
  s = space_create(1);
  space_set_object(s,TRUE);
  PRINT_TEST_RESULT(space_get_object(s) != NULL);
  space_destroy(s);
}

void test3_space_get_object() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_object(s) == FALSE);
}

void test1_space_get_north() {
  Space *s;
  Link *l;

  s = space_create(5);
  l = link_create(1);
  link_set_id_primero(l, 5);
  link_set_id_segundo(l, 6);

  space_set_north(s, l);

  PRINT_TEST_RESULT(space_get_north(s) != NO_ID);
  space_destroy(s);
  link_destroy(l);
}

void test2_space_get_north() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_north(s) == NO_ID);
}

void test1_space_get_south() {
  Space *s;
  Link *l;

  s = space_create(5);
  l = link_create(1);
  link_set_id_primero(l, 5);
  link_set_id_segundo(l, 4);

  space_set_south(s, l);
  PRINT_TEST_RESULT(space_get_south(s) != NO_ID);
  space_destroy(s);
}

void test2_space_get_south() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_south(s) == NO_ID);
}

void test1_space_get_east() {
  Space *s;
  Link *l;

  s = space_create(5);
  l = link_create(1);
  link_set_id_primero(l, 5);
  link_set_id_segundo(l, 6);

  space_set_east(s, l);
  PRINT_TEST_RESULT(space_get_east(s) != NO_ID);
  space_destroy(s);
}

void test2_space_get_east() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_east(s) == NO_ID);
}

void test1_space_get_west() {
  Space *s;
  Link *l;

  s = space_create(5);
  l = link_create(1);
  link_set_id_primero(l, 5);
  link_set_id_segundo(l, 4);

  space_set_west(s, l);
  PRINT_TEST_RESULT(space_get_west(s) != NO_ID);
  space_destroy(s);
  link_destroy(l);
}

void test2_space_get_west() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_west(s) == NO_ID);
}

void test1_space_get_id() {
  Space *s;
  s = space_create(25);
  PRINT_TEST_RESULT(space_get_id(s) == 25);
  space_destroy(s);
}

void test2_space_get_id() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_id(s) == NO_ID);
}

void test1_space_get_gdesc(){

  Space * s = NULL;

  PRINT_TEST_RESULT(space_get_gdesc(s, 2) == NULL);
}

void test2_space_get_gdesc(){

  Space * s = NULL;

  s = space_create(12);

  space_set_gdesc(s, "aaa", "bbb", "ccc");
  PRINT_TEST_RESULT(space_get_gdesc(s, 1) != NULL);

  space_destroy(s);

}

void test1_space_set_gdesc(){

  Space * s = NULL;
  PRINT_TEST_RESULT(space_set_gdesc(s, "aaa", "bbb", "ccc") == ERROR);
}

void test2_space_set_gdesc(){

  Space * s = NULL;
  s = space_create(234);
  PRINT_TEST_RESULT(space_set_gdesc(s, "aaa", "bbb", "ccc") == OK);

  space_destroy(s);

}

void test1_space_get_north_link() {
  Space *s = NULL;
  Link *l = NULL;

  s = space_create(1);
  l = link_create(1);
  space_set_north(s, l);

  PRINT_TEST_RESULT(space_get_north_link(s) != NULL);
  space_destroy(s);
  link_destroy(l);
}

void test2_space_get_north_link() {
  Space *s = NULL;

  PRINT_TEST_RESULT(space_get_north_link(s) == NULL);
}

void test1_space_get_south_link() {
  Space *s = NULL;
  Link *l = NULL;

  s = space_create(1);
  l = link_create(1);
  space_set_south(s, l);

  PRINT_TEST_RESULT(space_get_south_link(s) != NULL);
  space_destroy(s);
}

void test2_space_get_south_link() {
  Space *s = NULL;

  PRINT_TEST_RESULT(space_get_south_link(s) == NULL);
}

void test1_space_get_east_link() {
  Space *s = NULL;
  Link *l = NULL;

  s = space_create(1);
  l = link_create(1);
  space_set_east(s, l);

  PRINT_TEST_RESULT(space_get_east_link(s) != NULL);
  space_destroy(s);
}

void test2_space_get_east_link() {
  Space *s = NULL;

  PRINT_TEST_RESULT(space_get_east_link(s) == NULL);
}

void test1_space_get_west_link(){
  Space *s = NULL;
  Link *l = NULL;

  s = space_create(1);
  l = link_create(1);
  space_set_west(s, l);

  PRINT_TEST_RESULT(space_get_west_link(s) != NULL);
  space_destroy(s);
  link_destroy(l);
}

void test2_space_get_west_link() {
  Space *s = NULL;

  PRINT_TEST_RESULT(space_get_west_link(s) == NULL);
}

void test1_space_set_iluminacion() {
  Space *s = NULL;

  s = space_create(1);
  PRINT_TEST_RESULT(space_set_iluminacion(s, TRUE) == OK);
  space_destroy(s);
}

void test2_space_set_iluminacion() {
  Space *s = NULL;

  PRINT_TEST_RESULT(space_set_iluminacion(s, TRUE) == ERROR);
}

void test1_space_get_iluminacion() {
  Space *s = NULL;

  s = space_create(1);
  space_set_iluminacion(s, TRUE);
  PRINT_TEST_RESULT(space_get_iluminacion(s) == TRUE);
  space_destroy(s);
}

void test2_space_get_iluminacion() {
  Space *s = NULL;

  PRINT_TEST_RESULT(space_get_iluminacion(s) == FALSE);
}

void test1_space_set_up() {
  Space *s = NULL;
  Link *l = NULL;

  s = space_create(5);
  l = link_create(1);

  PRINT_TEST_RESULT(space_set_up(s, l) == OK);
  space_destroy(s);
  link_destroy(l);
}

void test2_space_set_up() {
  Space *s = NULL;
  Link *l = NULL;
  PRINT_TEST_RESULT(space_set_up(s, l) == ERROR);
}

void test1_space_set_down() {
  Space *s = NULL;
  Link *l = NULL;

  s = space_create(5);
  l = link_create(1);

  PRINT_TEST_RESULT(space_set_down(s, l) == OK);
  space_destroy(s);
  link_destroy(l);
}

void test2_space_set_down() {
  Space *s = NULL;
  Link *l = NULL;
  PRINT_TEST_RESULT(space_set_down(s, l) == ERROR);
}

void test1_space_get_up() {
  Space *s;
  Link *l;

  s = space_create(5);
  l = link_create(1);
  link_set_id_primero(l, 5);
  link_set_id_segundo(l, 6);

  space_set_up(s, l);

  PRINT_TEST_RESULT(space_get_up(s) != NO_ID);
  space_destroy(s);
  link_destroy(l);
}

void test2_space_get_up() {
  Space *s = NULL;

  PRINT_TEST_RESULT(space_get_up(s) == NO_ID);
}

void test1_space_get_down() {
  Space *s;
  Link *l;

  s = space_create(5);
  l = link_create(1);
  link_set_id_primero(l, 5);
  link_set_id_segundo(l, 6);

  space_set_down(s, l);

  PRINT_TEST_RESULT(space_get_down(s) != NO_ID);
  space_destroy(s);
  link_destroy(l);
}

void test2_space_get_down() {
  Space *s = NULL;

  PRINT_TEST_RESULT(space_get_down(s) == NO_ID);
}

void test1_space_get_up_link() {
  Space *s = NULL;
  Link *l = NULL;

  s = space_create(1);
  l = link_create(1);
  space_set_up(s, l);

  PRINT_TEST_RESULT(space_get_up_link(s) != NULL);
  space_destroy(s);
  link_destroy(l);
}

void test2_space_get_up_link() {
  Space *s = NULL;

  PRINT_TEST_RESULT(space_get_up_link(s) == NULL);
}

void test1_space_get_down_link() {
  Space *s = NULL;
  Link *l = NULL;

  s = space_create(1);
  l = link_create(1);
  space_set_down(s, l);

  PRINT_TEST_RESULT(space_get_down_link(s) != NULL);
  space_destroy(s);
  link_destroy(l);
}

void test2_space_get_down_link() {
  Space *s = NULL;

  PRINT_TEST_RESULT(space_get_down_link(s) == NULL);
}

void test1_space_set_description() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_description(s, "hola") == OK);
  space_destroy(s);
}

void test2_space_set_description() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_name(s, "hola") == ERROR);
}

void test1_space_get_description() {
  Space *s;
  s = space_create(1);
  space_set_description(s, "adios");
  PRINT_TEST_RESULT(strcmp(space_get_description(s), "adios") == 0);
  space_destroy(s);
}

void test2_space_get_description() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_description(s) == NULL);
}

void test1_space_set_description_detallada() {
  Space *s;
  s = space_create(5);
  PRINT_TEST_RESULT(space_set_description_detallada(s, "hola") == OK);
  space_destroy(s);
}

void test2_space_set_description_detallada() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_set_name(s, "hola") == ERROR);
}

void test1_space_get_description_detallada() {
  Space *s;
  s = space_create(1);
  space_set_description_detallada(s, "adios");
  PRINT_TEST_RESULT(strcmp(space_get_description_detallada(s), "adios") == 0);
  space_destroy(s);
}

void test2_space_get_description_detallada() {
  Space *s = NULL;
  PRINT_TEST_RESULT(space_get_description_detallada(s) == NULL);
}
