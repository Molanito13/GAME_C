/**
 * @brief Declara las prubeas del modulo Die
 *
 * @file die_test.h
 * @author Daniel Molano Caraballo
 * @version 1.0
 * @date 02-03-2021
 * @copyright GNU Public License
 */

#ifndef DIE_TEST_H
#define DIE_TEST_H

/**
 * @test Prueba de la creacion del Die
 * @pre Die ID
 * @post Non NULL puntero a Die
 */
void test1_die_create();

/**
 * @test Prueba de la creacion del Die
 * @pre NO_ID
 * @post NULL
 */
void test2_die_create();

/**
 * @test Prueba de la destruye el Die
 * @pre Puntero no nulo a Die
 * @post OK
 */
void test1_die_destroy();

/**
 * @test Prueba de la destruye el Die
 * @pre Puntero nulo a Die
 * @post ERROR
 */
void test2_die_destroy();
/**
 * @test Prueba de la funcion de tirar el dado
 * @pre Puntero no nulo a Die
 * @post Entero entre 0 y 7
 */
void test1_die_roll();

/**
 * @test Prueba de la funcion de tirar el dado
 * @pre Puntero nulo a Die
 * @post -1
 */
void test2_die_roll();

/**
 * @test Prueba de actualizar el value del Die
 * @pre Puntero no nulo a Die
 * @post OK
 */
void test1_die_set_value();

/**
 * @test Prueba de actualizar el value del Die
 * @pre Puntero nulo a Die
 * @post ERROR
 */
void test2_die_set_value();

/**
 * @test Prueba de la funcion que obtiene el valor del dado
 * @pre Puntero no nulo a Die
 * @post Entero entre 0 y 7
 */
void test1_die_get_value();

/**
 * @test Prueba de la funcion que obtiene el valor del dad
 * @pre Puntero nulo a Die
 * @post -1
 */
void test2_die_get_value();

 /**
 * @test Prueba de actualizar el ID del Die
 * @pre Puntero no nulo a Die
 * @post OK
 */
void test1_die_set_id();

/**
 * @test Prueba de actualizar el ID del Die
 * @pre Puntero nulo a Die
 * @post ERROR
 */
void test2_die_set_id();

/**
 * @test Prueba de la funcion que coge el id del dado
 * @pre Puntero no nulo a Die
 * @post Id
 */
void test1_die_get_id();

/**
 * @test Prueba de la funcion que coge el id del dado
 * @pre Puntero nulo a Die
 * @post NO_ID
 */
void test2_die_get_id();


#endif
