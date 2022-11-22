/**
 * @brief Realiza las prubeas del modulo Set
 *
 * @file set_test.c
 * @author Carolina Monedero Juzgado
 * @version 1.0
 * @date 08-03-2021
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/set_test.h"
#include "../include/set.h"
#include "../include/test.h"

#define MAX_TESTS 22 /*!<Numero maxim de pruebas */

/**
 * @brief Ejecuta el test
 * @param argc primer argumento
 * @param *argv[] segundo argumento
 *
 */
int main(int argc, char **argv) {

  int test = 0;
  int all = 1;

  if (argc < 2)
    printf("Running all test for module Set:\n");
  else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d: \t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }

  if (all || test == 1) test1_set_create();
  if (all || test == 2) test2_set_create();
  if (all || test == 3) test1_set_destroy();
  if (all || test == 4) test2_set_destroy();
  if (all || test == 5) test1_set_add_id();
  if (all || test == 6) test2_set_add_id();
  if (all || test == 7) test1_set_del_id();
  if (all || test == 8) test2_set_del_id();
  if (all || test == 9) test1_set_full();
  if (all || test == 10) test2_set_full();
  if (all || test == 11) test1_set_empty();
  if (all || test == 12) test2_set_empty();
  if (all || test == 13) test1_set_get_numIds();
  if (all || test == 14) test2_set_get_numIds();
  if (all || test == 15) test1_set_getIds();
  if (all || test == 16) test2_set_getIds();
  if (all || test == 17) test1_set_find_gap();
  if (all || test == 18) test2_set_find_gap();
  if (all || test == 19) test1_set_has_id();
  if (all || test == 20) test2_set_has_id();
  if (all || test == 21) test1_set_getOneId();
  if (all || test == 22) test2_set_getOneId();

  PRINT_PASSED_PERCENTAGE;

  return 1;

}

void test1_set_create() {
  Set *set = NULL;

  set = set_create();
  PRINT_TEST_RESULT(set != NULL);

  set_destroy(set);

}

void test2_set_create() {
  Set *set = NULL;

  PRINT_TEST_RESULT(set == NULL);

}

void test1_set_destroy() {
  Set *set = NULL;
  set = set_create();
  PRINT_TEST_RESULT(set_destroy(set) == OK);
}

void test2_set_destroy() {
  Set *set = NULL;
  PRINT_TEST_RESULT(set_destroy(set) == ERROR);
}

void test1_set_add_id() {
  Set *set = NULL;

  set = set_create();
  PRINT_TEST_RESULT(set_add_id(set, 1) == OK);

  set_destroy(set);
}

void test2_set_add_id(){
  Set *set = NULL;

  set = set_create();
  PRINT_TEST_RESULT(set_add_id(set, -1) == ERROR);

  set_destroy(set);

}

void test1_set_del_id(){
  Set *set = NULL;

  set = set_create();
  PRINT_TEST_RESULT(set_del_id(set, 1) == ERROR);

  set_destroy(set);

}

void test2_set_del_id(){
  Set *set = NULL;

  set = set_create();
  PRINT_TEST_RESULT(set_del_id(set, -1) == ERROR);

  set_destroy(set);

}

void test1_set_full() {
  Set *set = NULL;
  int i;
  
  set = set_create();
  for (i = 0; i < MAX_IDS_PER_SET; i++)
    set_add_id(set, i);
  PRINT_TEST_RESULT(set_full(set) == TRUE);
  set_destroy(set);
}

void test2_set_full() {
   Set *set = NULL;
   PRINT_TEST_RESULT(set_full(set) == FALSE);
}

void test1_set_empty() {
   Set *set = NULL;
   set = set_create();
   set_add_id(set, 4);
   PRINT_TEST_RESULT(set_empty(set) == FALSE);
   set_destroy(set);
}

void test2_set_empty() {
   Set *set = NULL;
   PRINT_TEST_RESULT(set_empty(set) == TRUE);
}

void test1_set_get_numIds(){
  Set *set = NULL;
  int num;

  set = set_create();
  num = set_get_numIds(set);
  PRINT_TEST_RESULT(num == 0);

  set_destroy(set);
}

void test2_set_get_numIds(){
  Set *set = NULL;
  int num;

  set = set_create();
  set_add_id(set, 1);
  set_add_id(set, 8);
  set_add_id(set, 6);
  set_add_id(set, 4);

  num = set_get_numIds(set);

  PRINT_TEST_RESULT(num == 4);

  set_destroy(set);

}

void test1_set_getIds(){
  Set* set = NULL;

  set = set_create();
  set_add_id(set, 1);
  set_add_id(set, 2);

  PRINT_TEST_RESULT(set_getIds(set) != NULL);

  set_destroy(set);

}

void test2_set_getIds(){
  Set* set = NULL;

  set_add_id(set,1);
  set_add_id(set,2);

  PRINT_TEST_RESULT(set_getIds(set) == NULL);

}

void test1_set_find_gap(){
  Set* set = NULL;

  set = set_create();

  PRINT_TEST_RESULT(set_find_gap(set) == 0);

  set_destroy(set);

}

void test2_set_find_gap(){
  Set* set = NULL;

  PRINT_TEST_RESULT(set_find_gap(set) == -1);

}

void test1_set_has_id(){
  Set* set = NULL;

  set = set_create();
  set_add_id(set, 1);

  PRINT_TEST_RESULT(set_has_id(set, 1) == TRUE);

  set_destroy(set);

}
void test2_set_has_id(){
  Set* set = NULL;

  set = set_create();
  set_add_id(set, 1);
  PRINT_TEST_RESULT(set_has_id(set, NO_ID) == FALSE);

  set_destroy(set);

}

void test1_set_getOneId(){
  Set* set = NULL;

  set = set_create();
  set_add_id(set, 1);
  set_add_id(set, 2);
  set_add_id(set, 3);
  PRINT_TEST_RESULT(set_getOneId(set, 2) == 2);

  set_destroy(set);

}

void test2_set_getOneId(){
  Set* set = NULL;

  PRINT_TEST_RESULT(set_getOneId(set, 2) == NO_ID);

}
