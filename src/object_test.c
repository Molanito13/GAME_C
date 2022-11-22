/**
 * @brief Realiza las prubeas del modulo Object
 *
 * @file object_test.c
 * @author Carolina Monedero Juzgado
 * @version 1.0
 * @date 16-04-2021
 */

 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #include "../include/object_test.h"
 #include "../include/object.h"
 #include "../include/test.h"

#define MAX_TESTS 36 /*!<Numero maximo de pruebas*/

/**
* @brief main
*
* Object_test main
*/
int main (int argc, char **argv) {
  int test = 0;
  int all = 1;

  if (argc < 2)
    printf("Running all test for module Player:\n");
  else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d: \t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }

  if (all || test == 1) test1_object_create();
  if (all || test == 2) test2_object_create();
  if (all || test == 3) test1_object_destroy();
  if (all || test == 4) test2_object_destroy();
  if (all || test == 5) test1_object_set_name();
  if (all || test == 6) test2_object_set_name();
  if (all || test == 7) test1_object_get_name();
  if (all || test == 8) test2_object_get_name();
  if (all || test == 9) test1_object_get_id();
  if (all || test == 10) test2_object_get_id();
  if (all || test == 11) test1_object_set_id();
  if (all || test == 12) test2_object_set_id();
  if (all || test == 13) test1_object_set_description();
  if (all || test == 14) test2_object_set_description();
  if (all || test == 15) test1_object_get_description();
  if (all || test == 16) test2_object_get_description();
  if (all || test == 17) test1_object_set_movable();
  if (all || test == 18) test2_object_set_movable();
  if (all || test == 19) test1_object_get_movable();
  if (all || test == 20) test2_object_get_movable();
  if (all || test == 21) test1_object_set_dependency();
  if (all || test == 22) test2_object_set_dependency();
  if (all || test == 23) test1_object_get_dependency();
  if (all || test == 24) test2_object_get_dependency();
  if (all || test == 25) test1_object_set_open();
  if (all || test == 26) test2_object_set_open();
  if (all || test == 27) test1_object_get_open();
  if (all || test == 28) test2_object_get_open();
  if (all || test == 29) test1_object_set_illuminate();
  if (all || test == 30) test2_object_set_illuminate();
  if (all || test == 31) test1_object_get_illuminate();
  if (all || test == 32) test2_object_get_illuminate();
  if (all || test == 33) test1_object_set_turnedon();
  if (all || test == 34) test2_object_set_turnedon();
  if (all || test == 35) test1_object_get_turnedon();
  if (all || test == 36) test2_object_get_turnedon();

  PRINT_PASSED_PERCENTAGE;

  return 1;

}

void test1_object_create(){
  Object* object = NULL;

  object = object_create(1);
  PRINT_TEST_RESULT(object != NULL);

  object_destroy(object);
}

void test2_object_create(){
  Object* object = NULL;

  object = object_create(-1);
  PRINT_TEST_RESULT(object == NULL);
}

void test1_object_destroy(){
  Object* object = NULL;

  object = object_create(1);
  PRINT_TEST_RESULT(object_destroy(object) == OK);

}

void test2_object_destroy(){
  Object* object = NULL;

  PRINT_TEST_RESULT(object_destroy(object) == ERROR);

}

void test1_object_set_name(){
  Object* object = NULL;

  object = object_create(1);
  PRINT_TEST_RESULT(object_set_name(object, "obj1") == OK);

  object_destroy(object);

}

void test2_object_set_name(){
  Object* object = NULL;

  PRINT_TEST_RESULT(object_set_name(object, "obj1") == ERROR);

}

void test1_object_get_name(){
  Object* object = NULL;

  object = object_create(1);
  object_set_name(object, "obj1");
  PRINT_TEST_RESULT(strcmp(object_get_name(object), "obj1") == 0);

  object_destroy(object);

}

void test2_object_get_name(){
  Object* object = NULL;

  PRINT_TEST_RESULT(object_get_name(object) == NULL);

}

void test1_object_get_id(){
  Object* object = NULL;

  object = object_create(1);
  PRINT_TEST_RESULT(object_get_id(object) == 1);

  object_destroy(object);

}

void test2_object_get_id(){
  Object* object = NULL;

  PRINT_TEST_RESULT(object_get_id(object) == -1);

}

void test1_object_set_id(){
  Object* object = NULL;

  object = object_create(1);
  PRINT_TEST_RESULT(object_set_id(object, 2) == OK);

  object_destroy(object);

}

void test2_object_set_id(){
  Object* object = NULL;

  PRINT_TEST_RESULT(object_set_id(object, 2) == ERROR);

}

void test1_object_set_description(){
  Object* object = NULL;

  object = object_create(1);
  PRINT_TEST_RESULT(object_set_description(object, "Desc prueba") == OK);

  object_destroy(object);

}

void test2_object_set_description(){
  Object* object = NULL;

  PRINT_TEST_RESULT(object_set_description(object, "Desc prueba") == ERROR);

}

void test1_object_get_description(){
  Object* object = NULL;

  object = object_create(1);
  object_set_description(object, "Desc prueba");
  PRINT_TEST_RESULT(strcmp(object_get_description(object), "Desc prueba") == 0);

  object_destroy(object);

}

void test2_object_get_description(){
  Object* object = NULL;

  PRINT_TEST_RESULT(object_get_description(object) == NULL);

}

void test1_object_set_movable(){
  Object* object = NULL;

  object = object_create(1);
  PRINT_TEST_RESULT(object_set_movable(object, TRUE) == OK);

  object_destroy(object);

}

void test2_object_set_movable(){
  Object* object = NULL;

  PRINT_TEST_RESULT(object_set_movable(object, TRUE) == ERROR);

}

void test1_object_get_movable(){
  Object* object = NULL;

  object = object_create(1);
  object_set_movable(object, TRUE);
  PRINT_TEST_RESULT(object_get_movable(object) == TRUE);

  object_destroy(object);

}

void test2_object_get_movable(){
  Object* object = NULL;

  PRINT_TEST_RESULT(object_get_movable(object) == FALSE);

}

void test1_object_set_dependency(){
  Object* object = NULL;

  object = object_create(1);
  PRINT_TEST_RESULT(object_set_dependency(object, 4) == OK);

  object_destroy(object);

}

void test2_object_set_dependency(){
  Object* object = NULL;

  PRINT_TEST_RESULT(object_set_dependency(object, 3) == ERROR);

}

void test1_object_get_dependency(){
  Object* object = NULL;

  object = object_create(1);
  object_set_dependency(object, 4);
  PRINT_TEST_RESULT(object_get_dependency(object) == 4);

  object_destroy(object);

}

void test2_object_get_dependency(){
  Object* object = NULL;

  PRINT_TEST_RESULT(object_get_dependency(object) == NO_ID);

}

void test1_object_set_open(){
  Object* object = NULL;

  object = object_create(1);
  PRINT_TEST_RESULT(object_set_open(object, 4) == OK);

  object_destroy(object);

}

void test2_object_set_open(){
  Object* object = NULL;

  PRINT_TEST_RESULT(object_set_open(object, 4) == ERROR);

}

void test1_object_get_open(){
  Object *object = NULL;

  object = object_create(1);
  object_set_open(object, 4);
  PRINT_TEST_RESULT(object_get_open(object) == 4);

  object_destroy(object);

}

void test2_object_get_open(){
  Object* object = NULL;

  PRINT_TEST_RESULT(object_get_open(object) == NO_ID);

}

void test1_object_set_illuminate(){
  Object* object = NULL;

  object = object_create(1);
  PRINT_TEST_RESULT(object_set_illuminate(object, TRUE) == OK);

  object_destroy(object);

}

void test2_object_set_illuminate(){
  Object* object = NULL;

  PRINT_TEST_RESULT(object_set_illuminate(object, TRUE) == ERROR);

}

void test1_object_get_illuminate(){
  Object* object = NULL;

  object = object_create(1);
  object_set_illuminate(object, TRUE);
  PRINT_TEST_RESULT(object_get_illuminate(object) == TRUE);

  object_destroy(object);

}

void test2_object_get_illuminate(){
  Object* object = NULL;

  PRINT_TEST_RESULT(object_get_illuminate(object) == FALSE);


}

void test1_object_set_turnedon(){
  Object* object = NULL;

  object = object_create(1);
  PRINT_TEST_RESULT(object_set_turnedon(object, TRUE) == OK);

  object_destroy(object);

}

void test2_object_set_turnedon(){
  Object* object = NULL;

  PRINT_TEST_RESULT(object_set_turnedon(object, TRUE) == ERROR);

}

void test1_object_get_turnedon(){
  Object* object = NULL;

  object = object_create(1);
  object_set_turnedon(object, TRUE);
  PRINT_TEST_RESULT(object_get_turnedon(object) == TRUE);

  object_destroy(object);

}

void test2_object_get_turnedon(){
  Object* object = NULL;

  PRINT_TEST_RESULT(object_get_turnedon(object) == FALSE);
  
}
