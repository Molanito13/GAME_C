/**
 * @brief Declara las prubeas del modulo Object
 *
 * @file object_test.h
 * @author Carolina Monedero Juzgado
 * @version 1.0
 * @date 16-04-2021
 */

#ifndef OBJECT_TEST_H
#define OBJECT_TEST_H

/**
  * @test Prueba object_create
  * @pre Id del nuevo objeto
  * @post Puntero no nulo a Object
  */
void test1_object_create();

/**
  * @test Prueba object_create
  * @pre id == NO_ID
  * @post Puntero nulo a Object
  */
void test2_object_create();


/**
  * @test Prueba object_destroy
  * @pre Puntero no nulo de Object
  * @post Output == OK
  */
void test1_object_destroy();

/**
  * @test Prueba object_destroy
  * @pre Puntero nulo de Object
  * @post Output == ERROR
  */
void test2_object_destroy();

/**
  * @test Prueba object_set_name
  * @pre Puntero no nulo de Object, nombre del objeto
  * @post Output == OK
  */
void test1_object_set_name();

/**
  * @test Prueba object_set_name
  * @pre Puntero nulo de Object, nombre del objeto
  * @post Output == ERROR
  */
void test2_object_set_name();

/**
  * @test Prueba object_get_name
  * @pre Puntero no nulo de Object
  * @post Output == 0
  */
void test1_object_get_name();

/**
  * @test Prueba object_get_name
  * @pre Puntero nulo de Object
  * @post Output == NULL
  */
void test2_object_get_name();

/**
  * @test Prueba object_get_name
  * @pre Puntero no nulo de Object
  * @post Output == 1
  */
void test1_object_get_id();

/**
  * @test Prueba object_get_name
  * @pre Puntero nulo de Object
  * @post Output == NO_ID
  */
void test2_object_get_id();

/**
  * @test Prueba object_set_Id
  * @pre Puntero no nulo a Object, Id a añadir
  * @post Ouput == OK
  */
void test1_object_set_id();

/**
  * @test Prueba object_set_Id
  * @pre Puntero nulo a Object, Id a añadir
  * @post Ouput == ERROR
  */
void test2_object_set_id();

/**
  * @test Prueba object_set_description
  * @pre Puntero no nulo a Object, descripcion a añadir
  * @post Ouput == OK
  */
void test1_object_set_description();

/**
  * @test Prueba object_set_description
  * @pre Puntero nulo a Object, descripcion a añadir
  * @post Ouput == ERROR
  */
void test2_object_set_description();

/**
  * @test Prueba object_get_description
  * @pre Puntero no nulo a Object
  * @post Ouput == 0
  */
void test1_object_get_description();

/**
  * @test Prueba object_get_description
  * @pre Puntero nulo a Object
  * @post Ouput == NULL
  */
void test2_object_get_description();

/**
  * @test Prueba object_set_movable
  * @pre Puntero no nulo a Object, campo movable nuevo
  * @post Ouput == OK
  */
void test1_object_set_movable();

/**
  * @test Prueba object_set_movable
  * @pre Puntero nulo a Object, campo movable nuevo
  * @post Ouput == ERROR
  */
void test2_object_set_movable();

/**
  * @test Prueba object_get_movable
  * @pre Puntero no nulo a Object
  * @post Ouput == TRUE
  */
void test1_object_get_movable();

/**
  * @test Prueba object_get_movable
  * @pre Puntero nulo a Object
  * @post Ouput == FALSE
  */
void test2_object_get_movable();

/**
  * @test Prueba object_set_dependency
  * @pre Puntero no nulo a Object, campo dependency nuevo
  * @post Ouput == OK
  */
void test1_object_set_dependency();

/**
  * @test Prueba object_set_dependency
  * @pre Puntero nulo a Object, campo dependency nuevo
  * @post Ouput == ERROR
  */
void test2_object_set_dependency();

/**
  * @test Prueba object_get_dependency
  * @pre Puntero no nulo a Object
  * @post Ouput == 2
  */
void test1_object_get_dependency();

/**
  * @test Prueba object_get_dependency
  * @pre Puntero nulo a Object
  * @post Ouput == NO_ID
  */
void test2_object_get_dependency();

/**
  * @test Prueba object_set_open
  * @pre Puntero no nulo a Object, campo open nuevo
  * @post Ouput == OK
  */
void test1_object_set_open();

/**
  * @test Prueba object_set_open
  * @pre Puntero nulo a Object, campo open nuevo
  * @post Ouput == ERROR
  */
void test2_object_set_open();

/**
  * @test Prueba object_get_open
  * @pre Puntero no nulo a Object
  * @post Ouput == 2
  */
void test1_object_get_open();

/**
  * @test Prueba object_get_open
  * @pre Puntero nulo a Object
  * @post Ouput == NO_ID
  */
void test2_object_get_open();

/**
  * @test Prueba object_set_illuminate
  * @pre Puntero no nulo a Object, campo illuminate nuevo
  * @post Ouput == OK
  */
void test1_object_set_illuminate();

/**
  * @test Prueba object_set_illuminate
  * @pre Puntero nulo a Object, campo illuminate nuevo
  * @post Ouput == ERROR
  */
void test2_object_set_illuminate();

/**
  * @test Prueba object_get_illuminate
  * @pre Puntero no nulo a Object
  * @post Ouput == TRUE
  */
void test1_object_get_illuminate();

/**
  * @test Prueba object_get_illuminate
  * @pre Puntero nulo a Object
  * @post Ouput == FALSE
  */
void test2_object_get_illuminate();

/**
  * @test Prueba object_set_turnedon
  * @pre Puntero no nulo a Object, campo turnedon nuevo
  * @post Ouput == OK
  */
void test1_object_set_turnedon();

/**
  * @test Prueba object_set_turnedon
  * @pre Puntero nulo a Object, campo turnedon nuevo
  * @post Ouput == ERROR
  */
void test2_object_set_turnedon();

/**
  * @test Prueba object_get_turnedon
  * @pre Puntero no nulo a Object
  * @post Ouput == TRUE
  */
void test1_object_get_turnedon();

/**
  * @test Prueba object_get_turnedon
  * @pre Puntero nulo a Object
  * @post Ouput == FALSE
  */
void test2_object_get_turnedon();

#endif
