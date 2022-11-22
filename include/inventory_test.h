/**
 * @brief Declara las prubeas del modulo Inventory
 *
 * @file inventory_test.h
 * @author Carolina Monedero Juzgado
 * @version 1.0
 * @date 24-03-2021
 */

#ifndef INVENTORY_TEST_H
#define INVENTORY_TEST_H

/**
  * @test Prueba inventory_create
  * @pre Puntero no nulo de Inventory
  * @post Puntero no nulo a Inventory
  */
void test1_inventory_create();

/**
  * @test Prueba inventory_create
  * @pre Puntero nulo de inventory
  * @post Puntero nulo a inventory
  */
void test2_inventory_create();

/**
  * @test Prueba inventory_destroy
  * @pre Puntero no nulo de inventory
  * @post Output == OK
  */
void test1_inventory_destroy();

/**
  * @test Prueba inventory_destroy
  * @pre Puntero nulo de inventory
  * @post Output == ERROR
  */
void test2_inventory_destroy();

/**
  * @test Prueba inventory_setId
  * @pre Puntero no nulo a Inventory, Id a añadir
  * @post Ouput == OK
  */
void test1_inventory_setId();

/**
  * @test Prueba inventory_setId
  * @pre Puntero no nulo a Inventory, Id == NO_ID
  * @post Ouput == ERROR
  */
void test2_inventory_setId();

/**
  * @test Prueba inventory_setMaxTam
  * @pre Puntero no nulo a Inventory
  * @post Ouput == OK
  */
void test1_inventory_setMaxTam();

/**
  * @test Prueba inventory_setMaxTam
  * @pre Puntero no nulo a Inventory, tam == -1
  * @post Ouput == ERROR
  */
void test2_inventory_setMaxTam();

 /**
  * @test Prueba inventory_getIds
  * @pre Puntero no nulo a Inventory
  * @post Puntero no nulo a Set
  */
void test1_inventory_getIds();

/**
  * @test Prueba inventory_getIds
  * @pre Puntero nulo a Inventory
  * @post Puntero nulo a Set
  */
void test2_inventory_getIds();

/**
  * @test Prueba inventory_getMaxTam
  * @pre Puntero no nulo a Inventory
  * @post Tamanio del inventario
  */
void test1_inventory_getMaxTam();

/**
  * @test Prueba inventory_getMaxTam
  * @pre Punter nulo a Inventory
  * @post Output == -1
  */
void test2_inventory_getMaxTam();

/**
  * @test Prueba inventory_get_objectWithId
  * @pre Puntero no nulo a Inventory, id == 2
  * @post Output == 2
  */
void test1_inventory_get_objectWithId();

/**
  * @test Prueba inventory_get_objectWithId
  * @pre Puntero nulo a Inventory, id == 2
  * @post Output == NO_ID
  */
void test2_inventory_get_objectWithId();

/**
  * @test Prueba inventory_hasId
  * @pre Puntero no nulo a Inventory, id == 2
  * @post Output == TRUE
  */
void test1_inventory_hasId();

/**
  * @test Prueba inventory_hasId
  * @pre Puntero nulo a Inventory, id == 2
  * @post Output == FALSE
  */
void test2_inventory_hasId();

/**
  * @test Prueba inventory_getNumObjects
  * @pre Puntero no nulo a Inventory
  * @post Numero de objetos en el inventario
  */
void test1_inventory_getNumObjects();

/**
  * @test Prueba inventory_getNumObjects
  * @pre Puntero nulo a Inventory
  * @post Output == -1
  */void test2_inventory_getNumObjects();

 #endif
