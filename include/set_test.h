/**
 * @brief Declara las prubeas del modulo Set
 *
 * @file set_test.h
 * @author Carolina Monedero Juzgado
 * @version 1.0
 * @date 02-03-2021
 * Modificado el 26-03-2021
 * @copyright GNU Public License
 */

#ifndef SET_TEST_H
#define SET_TEST_H

/**
 * @test Prueba set_create
 * @pre Puntero no nulo de set
 * @post Puntero no nulo a Set
 */
void test1_set_create();

/**
 * @test Prueba set_create
 * @pre Puntero nulo de set
 * @post Puntero nulo a Set
 */
void test2_set_create();

/**
 * @test Prueba set_destroy
 * @pre Puntero no nulo de set
 * @post Ouput == OK
 */
void test1_set_destroy();

/**
 * @test Prueba set_destroy
 * @pre Puntero nulo de set
 * @post Ouput == ERROR
 */
void test2_set_destroy();

/**
 * @test Prueba set_add_id
 * @pre Puntero no nulo a Set, Id a añadir
 * @post Ouput == OK
 */
void test1_set_add_id();

/**
 * @test Prueba set_add_id
 * @pre Puntero no nulo a Set, Id == NO_ID
 * @post Ouput == ERROR
 */
void test2_set_add_id();

/**
 * @test Prueba set_del_id
 * @pre Puntero no nulo a Set, Id a eliminar
 * @post Ouput == OK
 */
void test1_set_del_id();

/**
 * @test Prueba set_add_id
 * @pre Puntero no nulo a Set, Id == NO_ID
 * @post Ouput == ERROR
 */
void test2_set_del_id();

/**
 * @test Prueba set_full
 * @pre Set lleno
 * @post Ouput == TRUE
 */
void test1_set_full();

/**
 * @test Prueba set_full
 * @pre Set vacio
 * @post Ouput == FALSE
 */
void test2_set_full();

/**
 * @test Prueba set_empty
 * @pre Set no vacio
 * @post Ouput == FALSE
 */
void test1_set_empty();

/**
 * @test Prueba set_empty
 * @pre Set vacio
 * @post Ouput == TRUE
 */
void test2_set_empty();

/**
 * @test Prueba set_get_numIds
 * @pre Set vacio
 * @post Ouput == 0
 */
void test1_set_get_numIds();

/**
 * @test Prueba set_get_numIds
 * @pre Set no vacio
 * @post Ouput == 4
 */
void test2_set_get_numIds();

/**
 * @test Prueba set_getIds
 * @pre puntero no nulo a Set
 * @post puntero no nulo a Set
 */
void test1_set_getIds();

/**
 * @test Prueba set_getIds
 * @pre puntero nulo a Set
 * @post puntero nulo a Set
 */
void test2_set_getIds();

/**
 * @test Prueba set_find_gap
 * @pre puntero no nulo a Set
 * @post Output == 0
 */
void test1_set_find_gap();

/**
 * @test Prueba set_find_gap
 * @pre puntero nulo a Set
 * @post Output == -1
 */
void test2_set_find_gap();

/**
 * @test Prueba set_has_id
 * @pre puntero no nulo a Set, id a comprobar
 * @post Output == 1
 */
void test1_set_has_id();

/**
 * @test Prueba set_has_id
 * @pre puntero no nulo a Set, id nulo
 * @post Output == NO_ID
 */
void test2_set_has_id();

/**
 * @test Prueba set_getOneId
 * @pre puntero no nulo a Set, id a recuperar
 * @post Output == 2
 */
void test1_set_getOneId();

/**
 * @test Prueba set_getOneId
 * @pre puntero nulo a Set, id a recuperar
 * @post Output == NO_ID
 */
void test2_set_getOneId(); 

 #endif
 
