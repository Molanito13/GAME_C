/**
 * @brief Declara las prubeas del modulo Player
 *
 * @file player_test.h
 * @author Carolina Monedero Juzgado
 * @version 1.0
 * @date 27-03-2021
 */

#ifndef PLAYER_TEST_H
#define PLAYER_TEST_H

/**
  * @test Prueba player_create
  * @pre Puntero no nulo de Player
  * @post Puntero no nulo a Player
  */
void test1_player_create();

/**
  * @test Prueba player_create
  * @pre Puntero nulo de Player
  * @post Puntero nulo a Player
  */
void test2_player_create();

/**
  * @test Prueba player_destroy
  * @pre Puntero no nulo de Player
  * @post Output == OK
  */
void test1_player_destroy();

/**
  * @test Prueba player_destroy
  * @pre Puntero nulo de Player
  * @post Output == ERROR
  */
void test2_player_destroy();

/**
  * @test Prueba player_set_name
  * @pre Puntero no nulo de Player, nombre del jugador
  * @post Output == OK
  */
void test1_player_set_name();

/**
  * @test Prueba player_set_name
  * @pre Puntero nulo de Player, nombre del jugador
  * @post Output == ERROR
  */
void test2_player_set_name();

/**
  * @test Prueba player_get_name
  * @pre Puntero no nulo de Player
  * @post Output == 0
  */
void test1_player_get_name();

/**
  * @test Prueba player_get_name
  * @pre Puntero nulo de Player
  * @post Output == NULL
  */
void test2_player_get_name();

/**
  * @test Prueba player_set_Id
  * @pre Puntero no nulo a Player, Id a añadir
  * @post Ouput == OK
  */
void test1_player_set_id();

/**
  * @test Prueba player_set_Id
  * @pre Puntero nulo a Player, Id a añadir
  * @post Ouput == ERROR
  */
void test2_player_set_id();

/**
  * @test Prueba player_get_name
  * @pre Puntero no nulo de Player
  * @post Output == 1
  */
void test1_player_get_id();

/**
  * @test Prueba player_get_name
  * @pre Puntero nulo de Player
  * @post Output == NO_ID
  */
void test2_player_get_id();

/**
  * @test Prueba player_get_location
  * @pre Puntero no nulo de Player
  * @post Output == 1
  */
void test1_player_get_location();

/**
  * @test Prueba player_get_location
  * @pre Puntero nulo de Player
  * @post Output == NO_ID
  */
void test2_player_get_location();

/**
  * @test Prueba player_set_location
  * @pre Puntero no nulo a Player, Id de la nueva localizacion
  * @post Ouput == OK
  */
void test1_player_set_location();

/**
  * @test Prueba player_set_location
  * @pre Puntero nulo a Player, Id de la nueva localizacion
  * @post Ouput == ERROR
  */
void test2_player_set_location();

/**
  * @test Prueba player_get_inventory
  * @pre Puntero no nulo de Player, puntero no nulo de Inventory
  * @post puntero no nulo de Inventory
  */
void test1_player_get_inventory();

/**
  * @test Prueba player_get_inventory
  * @pre Puntero no nulo de Player, puntero nulo de Inventory
  * @post puntero nulo de Inventory
  */
void test2_player_get_inventory();

/**
  * @test Prueba player_set_inventory
  * @pre Puntero no nulo a Player, puntero no nulo a Inventory
  * @post Ouput == OK
  */
void test1_player_set_inventory();

/**
  * @test Prueba player_set_inventory
  * @pre Puntero no nulo a Player, puntero nulo a Inventory
  * @post Ouput == ERROR
  */
void test2_player_set_inventory();

/**
  * @test Prueba player_getObject_from_inventory
  * @pre Puntero no nulo de Player, Id del objeto
  * @post id del objeto recuperado
  */
void test1_player_getObject_from_inventory();

/**
  * @test Prueba player_getObject_from_inventory
  * @pre Puntero nulo de Player, Id del objeto
  * @post NO_ID
  */
void test2_player_getObject_from_inventory();

/**
  * @test Prueba player_set_object
  * @pre Puntero no nulo a Player, Id del objeto
  * @post Ouput == OK
  */
void test1_player_set_object();

/**
  * @test Prueba player_set_object
  * @pre Puntero nulo a Player, Id del objeto
  * @post Ouput == ERROR
  */
void test2_player_set_object();

/**
  * @test Prueba player_set_maxTam_inventory
  * @pre Puntero no nulo a Player
  * @post Ouput == OK
  */
void test1_player_set_maxTam_inventory();

/**
  * @test Prueba player_set_maxTam_inventory
  * @pre Puntero nulo a Player
  * @post Ouput == ERROR
  */
void test2_player_set_maxTam_inventory();

/**
  * @test Prueba player_get_maxTam_inventory
  * @pre Puntero no nulo a Player
  * @post Ouput == 2
  */
void test1_player_get_maxTam_inventory();

/**
  * @test Prueba player_get_maxTam_inventory
  * @pre Puntero nulo a Player
  * @post Ouput == -1
  */
void test2_player_get_maxTam_inventory();

#endif

