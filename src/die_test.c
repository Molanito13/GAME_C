/**
 * @brief Prueba el modulo Die
 *
 * @file   die_test.c
 * @author Daniel Molano Caraballo
 * @version 1.0
 * @date 02/03/2021
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/die.h"
#include "../include/die_test.h"
#include "../include/test.h"

#define MAX_TESTS 14 /*!< Numero maximo de pruebas */
/**
 * @brief Ejecuta el test
 * @param argc primer argumento
 * @param *argv[] segundo argumento
 *
 */
int main(int argc, char** argv) {

    int test = 0;
    int all = 1;

    if (argc < 2) {
        printf("Running all test for module Die:\n");
    } else {
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
        if (test < 1 && test > MAX_TESTS) {
            printf("Error: unknown test %d\t", test);
            exit(EXIT_SUCCESS);
        }
    }


    if (all || test == 1) test1_die_create();
    if (all || test == 2) test2_die_create();
    if (all || test == 3) test1_die_destroy();
    if (all || test == 4) test2_die_destroy();
    if (all || test == 5) test1_die_roll();
    if (all || test == 6) test2_die_roll();
    if (all || test == 7) test1_die_set_value();
    if (all || test == 8) test2_die_set_value();
    if (all || test == 9) test1_die_get_value();
    if (all || test == 10) test2_die_get_value();
    if (all || test == 11) test1_die_set_id();
    if (all || test == 12) test2_die_set_id();
    if (all || test == 13) test1_die_get_id();
    if (all || test == 14) test2_die_get_id();


    PRINT_PASSED_PERCENTAGE;

    return 1;
}
void test1_die_create() {
    Die *die = NULL;
    die = die_create(6);

    PRINT_TEST_RESULT(die != NULL);
    die_destroy(die);
}

void test2_die_create(){
    Die *die = NULL;
    die = die_create (NO_ID);

    PRINT_TEST_RESULT(die == NULL);
}

void test1_die_destroy() {
    Die *die = NULL;
    die = die_create(6);
    PRINT_TEST_RESULT(die_destroy(die) == OK);
}

void test2_die_destroy() {
    Die *die = NULL;
    PRINT_TEST_RESULT(die_destroy(die) == ERROR);
}

void test1_die_roll() {
    Die *die = NULL;
    int result;
    die = die_create (10);

    result = die_roll(die);
    PRINT_TEST_RESULT(result > 0 || result < 7);
    die_destroy(die);
}

void test2_die_roll(){
    Die *die = NULL;
    PRINT_TEST_RESULT(die_roll(die) == -1);
}

void test1_die_set_value() {
    Die *die = NULL;
    die = die_create (9);
    PRINT_TEST_RESULT(die_set_value(die, 5) == OK);
    die_destroy(die);
}

void test2_die_set_value() {
    Die *die = NULL;
    PRINT_TEST_RESULT(die_set_value(die, 5) == ERROR);
}

void test1_die_get_value(){
    Die *die = NULL;
    int result;
    die = die_create (9);

    result = die_get_value(die);
    PRINT_TEST_RESULT(result > 0 || result < 7);
    die_destroy(die);
}

void test2_die_get_value(){
    Die *die = NULL;
    PRINT_TEST_RESULT(die_get_value(die) == -1);
}

void test1_die_set_id() {
    Die *die = NULL;
    die = die_create (9);
    PRINT_TEST_RESULT(die_set_id(die, 5) == OK);
    die_destroy(die);
}

void test2_die_set_id() {
    Die *die = NULL;
    PRINT_TEST_RESULT(die_set_id(die, 5) == ERROR);
}

void test1_die_get_id(){
    Die *die;
    die = die_create (24);

    PRINT_TEST_RESULT(die_get_id(die) == 24);
    die_destroy(die);
}

void test2_die_get_id(){
    Die *die = NULL;

    PRINT_TEST_RESULT (die_get_id(die) == NO_ID);
}