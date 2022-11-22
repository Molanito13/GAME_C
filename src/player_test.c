/**
 * @brief Realiza las prubeas del modulo Player
 *
 * @file player_test.c
 * @author Carolina Monedero Juzgado
 * @version 1.0
 * @date 27-03-2021
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/player_test.h"
#include "../include/player.h"
#include "../include/inventory.h"
#include "../include/test.h"
#include "../include/set.h"

#define MAX_TESTS 28 /*!<Numero maxim de pruebas */

/**
* @brief main
*
* Player_test main
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

  if (all || test == 1) test1_player_create();
  if (all || test == 2) test2_player_create();
  if (all || test == 3) test1_player_destroy();
  if (all || test == 4) test2_player_destroy();
  if (all || test == 5) test1_player_set_name();
  if (all || test == 6) test2_player_set_name();
  if (all || test == 7) test1_player_get_name();
  if (all || test == 8) test2_player_get_name();
  if (all || test == 9) test1_player_set_id();
  if (all || test == 10) test2_player_set_id();
  if (all || test == 11) test1_player_get_id();
  if (all || test == 12) test2_player_get_id();
  if (all || test == 13) test1_player_get_location();
  if (all || test == 14) test2_player_get_location();
  if (all || test == 15) test1_player_set_location();
  if (all || test == 16) test2_player_set_location();
  if (all || test == 17) test1_player_get_inventory();
  if (all || test == 18) test2_player_get_inventory();
  if (all || test == 19) test1_player_set_inventory();
  if (all || test == 20) test2_player_set_inventory();
  if (all || test == 21) test1_player_getObject_from_inventory();
  if (all || test == 22) test2_player_getObject_from_inventory();
  if (all || test == 23) test1_player_set_object();
  if (all || test == 24) test2_player_set_object();
  if (all || test == 25) test1_player_set_maxTam_inventory();
  if (all || test == 26) test2_player_set_maxTam_inventory();
  if (all || test == 27) test1_player_get_maxTam_inventory();
  if (all || test == 28) test2_player_get_maxTam_inventory();

  PRINT_PASSED_PERCENTAGE;

  return 1;

}


void test1_player_create(){
  Player* player = NULL;

  player = player_create(1, 1);
  PRINT_TEST_RESULT(player != NULL);

  player_destroy(player);
}

void test2_player_create(){
  Player* player = NULL;

  PRINT_TEST_RESULT(player == NULL);

}

void test1_player_destroy(){
  Player *player = NULL;

  player = player_create(1, 1);
  PRINT_TEST_RESULT(player_destroy(player) == OK);

}

void test2_player_destroy(){
  Player* player = NULL;

  PRINT_TEST_RESULT(player_destroy(player) == ERROR);

}

void test1_player_set_name(){
  Player* player = NULL;

  player = player_create(1, 1);
  PRINT_TEST_RESULT(player_set_name(player, "jugador1") == OK);

  player_destroy(player);
}

void test2_player_set_name(){
  Player *player = NULL;

  PRINT_TEST_RESULT(player_set_name(player, "jugador1") == ERROR);

}

void test1_player_get_name(){
  Player* player = NULL;

  player = player_create(1, 5);
  player_set_name(player, "jugador1");
  PRINT_TEST_RESULT(strcmp(player_get_name(player), "jugador1") == 0);

  player_destroy(player);
}

void test2_player_get_name(){
  Player* player = NULL;

  PRINT_TEST_RESULT(player_get_name(player) == NULL);

}

void test1_player_set_id() {
  Player* player = NULL;

  player = player_create(1, 1);
  PRINT_TEST_RESULT(player_set_id(player, 2) == OK);

  player_destroy(player);

}

void test2_player_set_id(){
  Player* player = NULL;

  PRINT_TEST_RESULT(player_set_id(player, 2) == ERROR);

}
void test1_player_get_id(){
  Player* player = NULL;

  player = player_create(1, 1);
  PRINT_TEST_RESULT(player_get_id(player) == 1);

  player_destroy(player);
}

void test2_player_get_id(){
  Player* player = NULL;

  PRINT_TEST_RESULT(player_get_id(player) == NO_ID);
}

void test1_player_get_location(){
  Player* player = NULL;

  player = player_create(1, 1);
  player_set_location(player, 1);
  PRINT_TEST_RESULT(player_get_location(player) == 1);

  player_destroy(player);

}

void test2_player_get_location(){
  Player* player = NULL;

  PRINT_TEST_RESULT(player_get_location(player) == NO_ID);

}

void test1_player_set_location(){
  Player* player = NULL;

  player = player_create(1, 1);
  PRINT_TEST_RESULT(player_set_location(player, 2) == OK);

  player_destroy(player);

}

void test2_player_set_location(){
  Player* player = NULL;

  PRINT_TEST_RESULT(player_set_location(player, 2) == ERROR);

}

void test1_player_get_inventory(){
  Player* player = NULL;
  Inventory* inv = NULL;

  player = player_create(1, 1);
  player_set_inventory(player, inv);
  PRINT_TEST_RESULT(player_get_inventory(player) != NULL);

  player_destroy(player);

}

void test2_player_get_inventory(){
  Player* player = NULL;
  Inventory* inv = NULL;

  inv = inventory_create(1);
  player_set_inventory(player, inv);
  PRINT_TEST_RESULT(player_get_inventory(player) == NULL);

  inventory_destroy(inv);

}

void test1_player_set_inventory(){
  Player* player = NULL;

  player = player_create(1, 1);
  PRINT_TEST_RESULT(player_set_inventory(player, player_get_inventory(player)) == OK);

  player_destroy(player);

}

void test2_player_set_inventory(){
  Player* player = NULL;
  Inventory* inv = NULL;

  player = player_create(1, 1);
  PRINT_TEST_RESULT(player_set_inventory(player, inv) == ERROR);

  player_destroy(player);

}

void test1_player_getObject_from_inventory(){
  Player* player = NULL;

  player = player_create(1, 1);
  player_set_object(player, 1);
  PRINT_TEST_RESULT(player_getObject_from_inventory(player, 1) == 1);

  player_destroy(player);

}

void test2_player_getObject_from_inventory(){
  Player* player = NULL;

  PRINT_TEST_RESULT(player_getObject_from_inventory(player, 1) == NO_ID);

}

void test1_player_set_object(){
  Player* player = NULL;

  player = player_create(1, 1);
  PRINT_TEST_RESULT(player_set_object(player, 1) == OK);

  player_destroy(player);

}

void test2_player_set_object(){
  Player* player = NULL;

  PRINT_TEST_RESULT(player_set_object(player, 1) == ERROR);

}

void test1_player_set_maxTam_inventory() {
  Player* player = NULL;

  player = player_create(1, 1);
  PRINT_TEST_RESULT(player_set_maxTam_inventory(player, 2) == OK);

  player_destroy(player);
}

void test2_player_set_maxTam_inventory() {
  Player* player = NULL;
  PRINT_TEST_RESULT(player_set_maxTam_inventory(player, 2) == ERROR);
}

void test1_player_get_maxTam_inventory() {
  Player* player = NULL;

  player = player_create(1, 1);
  player_set_maxTam_inventory(player, 2);
  PRINT_TEST_RESULT(player_get_maxTam_inventory(player) == 2);
  player_destroy(player);
}

void test2_player_get_maxTam_inventory() {
  Player* player = NULL;

  PRINT_TEST_RESULT(player_get_maxTam_inventory(player) == -1);
}
