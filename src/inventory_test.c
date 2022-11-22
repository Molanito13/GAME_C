/**
 * @brief Realiza las prubeas del modulo Inventory
 *
 * @file inventory_test.c
 * @author Carolina Monedero Juzgado
 * @version 1.0
 * @date 24-03-2021
 */

 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #include "../include/inventory_test.h"
 #include "../include/inventory.h"
 #include "../include/test.h"

 #define MAX_TESTS 18 /*!<Numero maxim de pruebas */

/**
* @brief Main
*
* Inventory_test main
*/
int main(int argc, char **argv) {
  int test = 0;
  int all = 1;

  if (argc < 2)
    printf("Running all test for module Inventory:\n");
  else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d: \t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }

  if (all || test == 1) test1_inventory_create();
  if (all || test == 2) test2_inventory_create();
  if (all || test == 3) test1_inventory_destroy();
  if (all || test == 4) test2_inventory_destroy();
  if (all || test == 5) test1_inventory_setId();
  if (all || test == 6) test2_inventory_setId();
  if (all || test == 7) test1_inventory_setMaxTam();
  if (all || test == 8) test2_inventory_setMaxTam();
  if (all || test == 9) test1_inventory_getIds();
  if (all || test == 10) test2_inventory_getIds();
  if (all || test == 11) test1_inventory_getMaxTam();
  if (all || test == 12) test2_inventory_getMaxTam();
  if (all || test == 13) test1_inventory_get_objectWithId();
  if (all || test == 14) test2_inventory_get_objectWithId();
  if (all || test == 15) test1_inventory_hasId();
  if (all || test == 16) test2_inventory_hasId();
  if (all || test == 17) test1_inventory_getNumObjects();
  if (all || test == 18) test2_inventory_getNumObjects();

  PRINT_PASSED_PERCENTAGE;

  return 1;

}

void test1_inventory_create(){
  Inventory* inv = NULL;

  inv = inventory_create(1);
  PRINT_TEST_RESULT(inv != NULL);

  inventory_destroy(inv);

}

void test2_inventory_create() {
  Inventory *inv = NULL;

  PRINT_TEST_RESULT(inv ==NULL);

}

void test1_inventory_destroy() {
  Inventory* inv = NULL;

  inv = inventory_create(1);

  PRINT_TEST_RESULT(inventory_destroy(inv) == OK);

}

void test2_inventory_destroy(){
  Inventory* inv = NULL;

  PRINT_TEST_RESULT(inventory_destroy(inv) == ERROR);

}

void test1_inventory_setId() {
  Inventory* inv = NULL;

  inv = inventory_create(5);
  PRINT_TEST_RESULT(inventory_setId(inv, 1) == OK);

  inventory_destroy(inv);

}

void test2_inventory_setId() {
  Inventory *inv = NULL;

  inv = inventory_create(1);
  PRINT_TEST_RESULT(inventory_setId(inv, -1) == ERROR);

  inventory_destroy(inv);

}

void test1_inventory_setMaxTam(){
  Inventory* inv = NULL;

  inv = inventory_create(1);
  PRINT_TEST_RESULT(inventory_setMaxTam(inv, 12) == OK);

  inventory_destroy(inv);

}

void test2_inventory_setMaxTam(){
  Inventory* inv = NULL;

  inv = inventory_create(1);
  PRINT_TEST_RESULT(inventory_setMaxTam(inv, -1) == ERROR);

  inventory_destroy(inv);

}

void test1_inventory_getIds(){
  Inventory* inv = NULL;

  inv = inventory_create(3);
  inventory_setId(inv, 1);
  inventory_setId(inv, 2);
  inventory_setId(inv, 3);

  PRINT_TEST_RESULT(inventory_getIds(inv) != NULL);

  inventory_destroy(inv);

}

void test2_inventory_getIds(){
  Inventory* inv = NULL;

  inventory_setId(inv, 1);
  inventory_setId(inv, 2);
  inventory_setId(inv, 3);

  PRINT_TEST_RESULT(inventory_getIds(inv) == NULL);

}

void test1_inventory_getMaxTam(){
  Inventory* inv = NULL;

  inv = inventory_create(12);
  inventory_setMaxTam(inv, 12);

  PRINT_TEST_RESULT(inventory_getMaxTam(inv) == 12);

  inventory_destroy(inv);
}

void test2_inventory_getMaxTam(){
  Inventory* inv = NULL;

  PRINT_TEST_RESULT(inventory_getMaxTam(inv) == -1);
}

void test1_inventory_get_objectWithId(){
  Inventory* inv = NULL;

  inv = inventory_create(3);
  inventory_setId(inv, 1);
  inventory_setId(inv, 2);
  inventory_setId(inv, 3);

  PRINT_TEST_RESULT(inventory_get_objectWithId(inv, 2) == 2);
  inventory_destroy(inv);

}

void test2_inventory_get_objectWithId() {
  Inventory* inv = NULL;

  inv = inventory_create(1);

  PRINT_TEST_RESULT(inventory_get_objectWithId(inv, 2) == NO_ID);

  inventory_destroy(inv);

}

void test1_inventory_hasId(){
  Inventory* inv = NULL;

  inv = inventory_create(3);
  inventory_setId(inv, 1);
  inventory_setId(inv, 2);
  inventory_setId(inv, 3);

  PRINT_TEST_RESULT(inventory_hasId(inv,2) == TRUE);

  inventory_destroy(inv);
}

void test2_inventory_hasId(){
  Inventory* inv = NULL;

  inventory_setId(inv, 1);
  inventory_setId(inv, 2);
  inventory_setId(inv, 3);

  PRINT_TEST_RESULT(inventory_hasId(inv, 2) == FALSE);

}

void test1_inventory_getNumObjects(){
  Inventory* inv = NULL;

  inv = inventory_create(3);
  inventory_setId(inv, 1);
  inventory_setId(inv, 2);
  inventory_setId(inv, 3);

  PRINT_TEST_RESULT(inventory_getNumObjects(inv) == 3);

  inventory_destroy(inv);

}

void test2_inventory_getNumObjects(){
  Inventory* inv = NULL;

  PRINT_TEST_RESULT(inventory_getNumObjects(inv) == -1);

}
