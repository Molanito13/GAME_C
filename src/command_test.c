/**
 * @brief Prueba el modulo Command
 *
 * @file command_test.c
 * @author Adrian Martinez
 * @version 1.0
 * @date 17-04-2021
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/command.h"
#include "../include/command_test.h"
#include "../include/test.h"

#define MAX_TESTS 18    /*!<Numero de test*/

/**
 * @brief Funcion principal para la prueba del modulo Command
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

    if (all || test == 1) test1_command_get_user_input();
    if (all || test == 2) test2_command_get_user_input();
    if (all || test == 3) test1_command_create();
    if (all || test == 4) test2_command_create();
    if (all || test == 5) test1_command_destroy();
    if (all || test == 6) test2_command_destroy();
    if (all || test == 7) test1_command_set_cmd();
    if (all || test == 8) test2_command_set_cmd();
    if (all || test == 9) test1_command_get_cmd();
    if (all || test == 10) test2_command_get_cmd();
    if (all || test == 11) test1_command_set_extra();
    if (all || test == 12) test2_command_set_extra();
    if (all || test == 13) test1_command_get_extra();
    if (all || test == 14) test2_command_get_extra();
    if (all || test == 15) test1_command_get_log();
    if (all || test == 16) test2_command_get_log();
    if (all || test == 17) test1_command_get_last();
    if (all || test == 18) test2_command_get_last();

    PRINT_PASSED_PERCENTAGE;

    return 1;
}

void test1_command_get_user_input() {
  Command *c=NULL;
  c = command_create();
  printf("Write the command 'BACK':\n");
  command_get_user_input(c);
  PRINT_TEST_RESULT(command_get_cmd(c) == BACK);
  command_destroy(c);
}

void test2_command_get_user_input() {
  Command *c=NULL;
  PRINT_TEST_RESULT(command_get_user_input(c) == ERROR);
}

void test1_command_create() {
  Command *c=NULL;
  c = command_create();
  PRINT_TEST_RESULT(c != NULL);
  command_destroy(c);
}

void test2_command_create() {
  Command *c;
  c = command_create();
  PRINT_TEST_RESULT(sizeof(c) != 0);
  command_destroy(c);
}

void test1_command_destroy() {
  Command *c=NULL;
  c = command_create();
  PRINT_TEST_RESULT(command_destroy(c) == OK);
}

void test2_command_destroy() {
  Command *c=NULL;
  PRINT_TEST_RESULT(command_destroy(c) == ERROR);
}

void test1_command_set_cmd() {
  Command *c=NULL;
  c = command_create();
  PRINT_TEST_RESULT(command_set_cmd(c, BACK) == OK);
  command_destroy(c);
}

void test2_command_set_cmd() {
  Command *c=NULL;
  PRINT_TEST_RESULT(command_set_cmd(c, BACK) == ERROR);
}

void test1_command_get_cmd() {
  Command *c=NULL;
  c = command_create();
  command_set_cmd(c, BACK);
  PRINT_TEST_RESULT(command_get_cmd(c) == BACK);
  command_destroy(c);
}

void test2_command_get_cmd() {
  Command *c=NULL;
  PRINT_TEST_RESULT(command_get_cmd(c) == NO_CMD);
}

void test1_command_set_extra() {
  Command *c=NULL;
  c = command_create();
  PRINT_TEST_RESULT(command_set_extra(c, "01") == OK);
  command_destroy(c);
}

void test2_command_set_extra() {
  Command *c=NULL;
  PRINT_TEST_RESULT(command_set_extra(c, "01") == ERROR);
}

void test1_command_get_extra() {
  Command *c=NULL;
  c = command_create();
  command_set_extra(c, "01");
  PRINT_TEST_RESULT(strcmp(command_get_extra(c), "01") == 0);
  command_destroy(c);
}

void test2_command_get_extra(){
  Command *c=NULL;
  PRINT_TEST_RESULT(command_get_extra(c) == NULL);
}

void test1_command_get_log() {
  Command *c=NULL;
  c = command_create();
  PRINT_TEST_RESULT(command_get_log(c) != NULL);
  command_destroy(c);
}

void test2_command_get_log() {
  Command *c=NULL;
  PRINT_TEST_RESULT(command_get_log(c) == NULL);
}

void test1_command_get_last() {
  Command *c=NULL;
  c = command_create();
  PRINT_TEST_RESULT(command_get_last(c) != NULL);
  command_destroy(c);

}

void test2_command_get_last(){
  Command *c=NULL;

  PRINT_TEST_RESULT(command_get_last(c) == NULL);

}
