/**
 * @brief Declara las prubeas del modulo Set
 *
 * @file set_test.h
 * @author Carolina Monedero Juzgado
 * @version 1.0
 * @date 02-03-2021
 * @copyright GNU Public License
 */

#ifndef LINK_TEST_H
#define LINK_TEST_H

/**
  * @test Prueba link_create
  * @pre Puntero no nulo de link
  * @post Puntero no nulo a link
  */
void test1_link_create();

/**
  * @test Prueba link_create
  * @pre Puntero nulo de link
  * @post Puntero nulo a link
  */
void test2_link_create();

/**
  * @test Prueba link_create
  * @pre Puntero no nulo de link
  * @post Output == OK
  */
void test1_link_destroy();

/**
  * @test Prueba link_create
  * @pre Puntero nulo de link
  * @post Output == ERROR
  */
void test2_link_destroy();

/**
  * @test Prueba link_set_id
  * @pre Puntero no nulo de link
  * @post Output == OK
  */
void test1_link_set_id();

/**
  * @test Prueba link_set_id
  * @pre Puntero no nulo de link
  * @post Output == ERROR
  */
void test2_link_set_id();

/**
  * @test Prueba link_set_name
  * @pre Puntero no nulo de link
  * @post Output == OK
  */
void test1_link_set_name();

/**
  * @test Prueba link_set_name
  * @pre Puntero no nulo de link, cadena con nombre vacía
  * @post Output == ERROR
  */
void test2_link_set_name();

/**
  * @test Prueba link_set_id_primero
  * @pre Puntero no nulo de link
  * @post Output == OK
  */
void test1_link_set_id_primero();

/**
  * @test Prueba link_set_id_primero
  * @pre Puntero no nulo de link
  * @post Output == ERROR
  */
void test2_link_set_id_primero();

/**
  * @test Prueba link_set_id_segundo
  * @pre Puntero no nulo de link
  * @post Output == OK
  */
void test1_link_set_id_segundo();

/**
  * @test Prueba link_set_id_segundo
  * @pre Puntero no nulo de link
  * @post Output == ERROR
  */
void test2_link_set_id_segundo();

/**
  * @test Prueba link_set_estado
  * @pre Puntero no nulo de link
  * @post Output == OK
  */
void test1_link_set_estado();

/**
  * @test Prueba link_set_estado
  * @pre Puntero no nulo de link
  * @post Output == ERROR
  */
void test2_link_set_estado();

/**
  * @test Prueba link_get_id
  * @pre Puntero no nulo de link
  * @post Output == 1
  */
void test1_link_get_id();

/**
  * @test Prueba link_get_id
  * @pre Puntero nulo de link
  * @post Output == NO_ID (-1)
  */
void test2_link_get_id();

/**
  * @test Prueba link_get_name
  * @pre Puntero no nulo de link
  * @post Output == "puerta"
  */
void test1_link_get_name();

/**
  * @test Prueba link_get_name
  * @pre Puntero nulo de link
  * @post Output == NULL
  */
void test2_link_get_name();

/**
  * @test Prueba link_get_id_primero
  * @pre Puntero no nulo de link
  * @post Output == 8
  */
void test1_link_get_id_primero();

/**
  * @test Prueba link_get_id_primero
  * @pre Puntero nulo de link
  * @post Output == NO_ID (-1)
  */
void test2_link_get_id_primero();

/**
  * @test Prueba link_get_id_segundo
  * @pre Puntero no nulo de link
  * @post Output == 8
  */
void test1_link_get_id_segundo();

/**
  * @test Prueba link_get_id_segundo
  * @pre Puntero nulo de link
  * @post Output == NO_ID (-1)
  */
void test2_link_get_id_segundo();

/**
  * @test Prueba link_get_estado
  * @pre Puntero no nulo de link
  * @post Output == ABIERTO
  */
void test1_link_get_estado();

/**
  * @test Prueba link_get_estado
  * @pre Puntero nulo de link
  * @post Output == CERRADO
  */
void test2_link_get_estado();

/**
  * @test Prueba link_get_dir
  * @pre Puntero no nulo de link
  * @post Output == "OE"
  */
void test1_link_get_dir();

/**
  * @test Prueba link_get_dir
  * @pre Puntero nulo de link
  * @post Output == NULL
  */
void test2_link_get_dir();

/**
  * @test Prueba link_set_dir
  * @pre Puntero no nulo de link
  * @post Output == OK
  */
void test1_link_set_dir();

/**
  * @test Prueba link_set_dir
  * @pre Puntero nulo de link
  * @post Output == ERROR
  */
void test2_link_set_dir();

#endif
