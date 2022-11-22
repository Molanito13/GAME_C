/**
 * @brief Declara los tests para el modulo command
 *
 * @file command_test.h
 * @author Adrian Martinez
 * @version 1.0
 * @date 17-04-2021
 * @copyright GNU Public License
 */

#ifndef SPACE_TEST_H
#define SPACE_TEST_H

/**
  * @test Prueba command_get_user_input
  * @pre Puntero no nulo de command
  * @post Output == BACK
  */
void test1_command_get_user_input();

/**
  * @test Prueba command_get_user_input
  * @pre Puntero nulo de command
  * @post Output == ERROR
  */
void test2_command_get_user_input();

/**
  * @test Prueba command_create
  * @pre Puntero no nulo de command
  * @post Puntero no nulo a command
  */
void test1_command_create();

/**
  * @test Prueba command_create
  * @pre Puntero no nulo de command
  * @post Sizeof(c) != 0
  */
void test2_command_create();

/**
  * @test Prueba command_destroy
  * @pre Puntero no nulo de command
  * @post Output == OK
  */
void test1_command_destroy();

/**
  * @test Prueba command_destroy
  * @pre Puntero nulo de command
  * @post Output == ERROR
  */
void test2_command_destroy();

/**
  * @test Prueba command_set_cmd
  * @pre Puntero no nulo de command
  * @post Output == OK
  */
void test1_command_set_cmd();

/**
  * @test Prueba command_set_cmd
  * @pre Puntero nulo de command
  * @post Output == ERROR
  */
void test2_command_set_cmd();

/**
  * @test Prueba command_get_cmd
  * @pre Puntero no nulo de command
  * @post Output == BACK
  */
void test1_command_get_cmd();

/**
  * @test Prueba command_get_cmd
  * @pre Puntero nulo de command
  * @post Output == NO_CMD
  */
void test2_command_get_cmd();

/**
  * @test Prueba command_set_extra
  * @pre Puntero no nulo de command
  * @post Output == OK
  */
void test1_command_set_extra();

/**
  * @test Prueba command_set_extra
  * @pre Puntero nulo de command
  * @post Output == ERROR
  */
void test2_command_set_extra();

/**
  * @test Prueba command_get_extra
  * @pre Puntero no nulo de command
  * @post Output == 0
  */
void test1_command_get_extra();

/**
  * @test Prueba command_get_extra
  * @pre Puntero nulo de command
  * @post Output == NULL
  */
void test2_command_get_extra();

/**
  * @test Prueba command_get_log
  * @pre Puntero no nulo de command
  * @post Output != NULL
  */
void test1_command_get_log();

/**
  * @test Prueba command_get_log
  * @pre Puntero nulo de command
  * @post Output == NULL
  */
void test2_command_get_log();

/**
  * @test Prueba command_get_last
  * @pre Puntero no nulo de command
  * @post Output != NULL
  */
void test1_command_get_last();

/**
  * @test Prueba command_get_last
  * @pre Puntero nulo de command
  * @post Output == NULL
  */
void test2_command_get_last();

#endif
