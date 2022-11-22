/**
 * @brief Realiza las prubeas del modulo Link
 *
 * @file link_test.c
 * @author Adrián Martínez Bayán
 * @version 1.0
 * @date 29-03-2021
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/link.h"
#include "../include/link_test.h"
#include "../include/types.h"
#include "../include/test.h"

#define MAX_TESTS 28 /*!<Numero maximo de pruebas */

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
		printf("Running all test for module Link:\n");
	else {
		test = atoi(argv[1]);
		all = 0;
		printf("Running test %d: \t", test);
		if (test < 1 && test > MAX_TESTS) {
			printf("Error: unknown test %d\t", test);
			exit(EXIT_SUCCESS);
		}
	}

	if (all || test == 1) test1_link_create();
	if (all || test == 2) test2_link_create();
	if (all || test == 3) test1_link_destroy();
	if (all || test == 4) test2_link_destroy();
	if (all || test == 5) test1_link_set_id();
	if (all || test == 6) test2_link_set_id();
	if (all || test == 7) test1_link_set_name();
	if (all || test == 8) test2_link_set_name();
	if (all || test == 9) test1_link_set_id_primero();
	if (all || test == 10) test2_link_set_id_primero();
	if (all || test == 11) test1_link_set_id_segundo();
	if (all || test == 12) test2_link_set_id_segundo();
	if (all || test == 13) test1_link_set_estado();
	if (all || test == 14) test2_link_set_estado();
	if (all || test == 15) test1_link_get_id();
	if (all || test == 16) test2_link_get_id();
	if (all || test == 17) test1_link_get_name();
	if (all || test == 18) test2_link_get_name();
	if (all || test == 19) test1_link_get_id_primero();
	if (all || test == 20) test2_link_get_id_primero();
	if (all || test == 21) test1_link_get_id_segundo();
	if (all || test == 22) test2_link_get_id_segundo();
	if (all || test == 23) test1_link_get_estado();
	if (all || test == 24) test2_link_get_estado();
	if (all || test == 25) test1_link_get_dir();
	if (all || test == 26) test2_link_get_dir();
	if (all || test == 27) test1_link_set_dir();
	if (all || test == 28) test2_link_set_dir();

	PRINT_PASSED_PERCENTAGE;

  return 1;

}


void test1_link_create() {
	Link *link = NULL;

	link = link_create(1);
	PRINT_TEST_RESULT(link != NULL);

	link_destroy(link);
}

void test2_link_create() {
	Link *link = NULL;

	link = link_create(-1);

	PRINT_TEST_RESULT(link == NULL);
}

void test1_link_destroy() {
	Link* link = NULL;

	link = link_create(1);

	PRINT_TEST_RESULT(link_destroy(link) == OK);

}

void test2_link_destroy(){
	Link* link = NULL;

	PRINT_TEST_RESULT(link_destroy(link) == ERROR);

}

void test1_link_set_id() {
	Link *link = NULL;

	link = link_create(1);

	PRINT_TEST_RESULT(link_set_id(link, 4) ==  OK);
	link_destroy(link);
}

void test2_link_set_id() {
	Link *link = NULL;

	link = link_create(1);

	PRINT_TEST_RESULT(link_set_id(link, -1) ==  ERROR);
	link_destroy(link);
}

void test1_link_set_name() {
	Link *link = NULL;

	link = link_create(1);

	PRINT_TEST_RESULT(link_set_name(link, "puerta") ==  OK);
	link_destroy(link);
}

void test2_link_set_name() {
	Link *link = NULL;
	char *name = NULL;
	link = link_create(1);

	PRINT_TEST_RESULT(link_set_name(link, name) ==  ERROR);
	link_destroy(link);
}

void test1_link_set_id_primero() {
	Link *link = NULL;

	link = link_create(1);

	PRINT_TEST_RESULT(link_set_id_primero(link, 2) == OK);
	link_destroy(link);
}

void test2_link_set_id_primero() {
	Link *link = NULL;

	link = link_create(1);

	PRINT_TEST_RESULT(link_set_id_primero(link, -1) == 	ERROR);
	link_destroy(link);
}

void test1_link_set_id_segundo() {
	Link *link = NULL;

	link = link_create(1);

	PRINT_TEST_RESULT(link_set_id_segundo(link, 2) == OK);
	link_destroy(link);
}

void test2_link_set_id_segundo() {
	Link *link = NULL;

	link = link_create(1);

	PRINT_TEST_RESULT(link_set_id_segundo(link, -1) == ERROR);
	link_destroy(link);
}

void test1_link_set_estado() {
	Link *link = NULL;

	link = link_create(1);

	PRINT_TEST_RESULT(link_set_estado(link, CERRADO) == OK);
	link_destroy(link);
}

void test2_link_set_estado() {
	Link *link = NULL;

	PRINT_TEST_RESULT(link_set_estado(link, ABIERTO) == ERROR);
	link_destroy(link);
}

void test1_link_get_id() {
	Link *link = NULL;

	link = link_create(1);

	PRINT_TEST_RESULT(link_get_id(link) == 1);
	link_destroy(link);
}

void test2_link_get_id() {
	Link *link = NULL;

	PRINT_TEST_RESULT(link_get_id(link) == NO_ID);
}

void test1_link_get_name() {
	Link *link = NULL;

	link = link_create(1);
	link_set_name(link, "puerta");

	PRINT_TEST_RESULT(strcmp(link_get_name(link), "puerta") == 0);
	link_destroy(link);
}

void test2_link_get_name() {
	Link *link = NULL;

	PRINT_TEST_RESULT(link_get_name(link) == NULL);
}

void test1_link_get_id_primero() {
	Link *link = NULL;

	link = link_create(1);
	link_set_id_primero(link, 8);

	PRINT_TEST_RESULT(link_get_id_primero(link) == 8);
	link_destroy(link);
}

void test2_link_get_id_primero() {
	Link *link = NULL;

	PRINT_TEST_RESULT(link_get_id_primero(link) == NO_ID);
}

void test1_link_get_id_segundo() {
	Link *link = NULL;

	link = link_create(1);
	link_set_id_segundo(link, 8);

	PRINT_TEST_RESULT(link_get_id_segundo(link) == 8);
	link_destroy(link);
}

void test2_link_get_id_segundo() {
	Link *link = NULL;

	PRINT_TEST_RESULT(link_get_id_segundo(link) == NO_ID);
}

void test1_link_get_estado() {
	Link *link = NULL;

	link = link_create(1);
	link_set_estado(link, ABIERTO);

	PRINT_TEST_RESULT(link_get_estado(link) == ABIERTO);
	link_destroy(link);
}

void test2_link_get_estado() {
	Link *link = NULL;

	PRINT_TEST_RESULT(link_get_estado(link) == CERRADO);
}

void test1_link_get_dir(){
  Link *link = NULL;

  link = link_create(1);
  link_set_dir(link, "OE");
  PRINT_TEST_RESULT(strcmp(link_get_dir(link), "OE" ) == 0);
  link_destroy(link);

}

void test2_link_get_dir(){
  Link *link = NULL;

  PRINT_TEST_RESULT(link_get_dir(link) == NULL);
}

void test1_link_set_dir(){
  Link *link = NULL;

  link = link_create(1);
  PRINT_TEST_RESULT(link_set_dir(link, "NS") == OK);
  link_destroy(link);

}

void test2_link_set_dir(){
  Link *link = NULL;

  PRINT_TEST_RESULT(link_set_dir(link, "NS") == ERROR);
}
