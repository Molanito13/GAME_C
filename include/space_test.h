/**
 * @brief Declara los tests para el modulo space
 *
 * @file space_test.h
 * @author Profesores Pprog
 * @version 2.0
 * @date 19-01-2016
 * @copyright GNU Public License
 */

#ifndef SPACE_TEST_H
#define SPACE_TEST_H

/**
 * @test Prueba space_create
 * @pre Space ID
 * @post Puntero no nulo a Space
 */
void test1_space_create();

/**
 * @test Prueba space_create
 * @pre Space ID
 * @post Space_ID == Space Id suministrado
 */
void test2_space_create();

/**
 * @test Prueba space_destroy
 * @pre Puntero no nulo a Space
 * @post Output == OK
 */
void test1_space_destroy();

/**
 * @test Prueba space_destroy
 * @pre Puntero nulo a Space
 * @post Output == ERROR
 */
void test2_space_destroy();

/**
 * @test Prueba space_set_name
 * @pre Cadena con el nombre del espacio
 * @post Ouput==OK
 */
void test1_space_set_name();

/**
 * @test Prueba space_set_name
 * @pre Puntero a Space nulo
 * @post Output==ERROR
 */
void test2_space_set_name();

/**
 * @test Prueba space_set_name
 * @pre Puntero no nulo a Space, puntero nulo a name
 * @post Output==ERROR
 */
void test3_space_set_name();

/**
 * @test Prueba space_set_north
 * @pre Link al norte
 * @post Output==OK
 */
void test1_space_set_north();

/**
 * @test Prueba space_set_north
 * @pre Puntero nulo a space
 * @post Output==ERROR
 */
void test2_space_set_north();

/**
 * @test Prueba space_set_south
 * @pre Link al sur
 * @post Output==OK
 */
void test1_space_set_south();

/**
 * @test Prueba space_set_south
 * @pre Puntero nulo a space
 * @post Output==ERROR
 */
void test2_space_set_south();

/**
 * @test Prueba space_set_east
 * @pre Link al este
 * @post Output==OK
 */
void test1_space_set_east();

/**
 * @test Prueba space_set_east
 * @pre Puntero nulo a space
 * @post Output==ERROR
 */
void test2_space_set_east();

/**
 * @test Prueba space_set_west
 * @pre Link al oeste
 * @post Output==OK
 */
void test1_space_set_west();

/**
 * @test Prueba space_set_west
 * @pre Puntero nulo a space
 * @post Output==ERROR
 */
void test2_space_set_west();

/**
 * @test Prueba space_set_object
 * @pre object == TRUE
 * @post Output==OK
 */
void test1_space_set_object();

/**
 * @test Prueba space_set_object
 * @pre Puntero nulo a Space
 * @post Output==ERROR
 */
void test2_space_set_object();

/**
 * @test Prueba space_get_name
 * @pre Devuelve el nombre del espacio
 * @post Output==0
 */
void test1_space_get_name();

/**
 * @test Prueba space_get_name
 * @pre Puntero nulo a Space
 * @post Output==NULL
 */
void test2_space_get_name();

/**
 * @test Prueba space_get_object
 * @pre No hay objeto en el espacio
 * @post Output!=NULL
 */
void test1_space_get_object();

/**
 * @test Prueba space_get_object
 * @pre Hay objeto en el espacio
 * @post Output!=NULL
 */
void test2_space_get_object();

/**
 * @test Prueba space_get_object
 * @pre Puntero nulo a space
 * @post Output==FALSE
 */
void test3_space_get_object();

/**
 * @test Prueba space_get_north
 * @pre Puntero no nulo al espacio, Id norte
 * @post Output==Id norte
 */
void test1_space_get_north();

/**
 * @test Prueba space_get_north
 * @pre Puntero nulo al espacio
 * @post Output==NO_ID
 */
void test2_space_get_north();

/**
 * @test Prueba space_get_south
 * @pre Puntero no nulo al espacio, Id sur
 * @post Output==Id sur
 */
void test1_space_get_south();

/**
 * @test Prueba space_get_south
 * @pre Puntero nulo al espacio
 * @post Output==NO_ID
 */
void test2_space_get_south();

/**
 * @test Prueba space_get_east
 * @pre Puntero no nulo al espacio, Id este
 * @post Output==Id este
 */
void test1_space_get_east();

/**
 * @test Prueba space_get_east
 * @pre Puntero nulo al espacio
 * @post Output==NO_ID
 */
void test2_space_get_east();

/**
 * @test Prueba space_get_west
 * @pre Puntero no nulo al espacio, Id oeste
 * @post Output==Id oeste
 */
void test1_space_get_west();

/**
 * @test Prueba space_get_west
 * @pre Puntero nulo al espacio
 * @post Output==NO_ID
 */
void test2_space_get_west();

/**
 * @test Prueba space_get_id
 * @pre Puntero no nulo al espacio
 * @post Output==Id espacio
 */
void test1_space_get_id();

/**
 * @test Prueba space_get_id
 * @pre Puntero nulo al espacio
 * @post Output==NO_ID
 */
void test2_space_get_id();


/**
 * @test Prueba space_get_id
 * @pre Puntero nulo al espacio, fila 2
 * @post Output==NULL
 */
void test1_space_get_gdesc();

/**
 * @test Prueba space_get_id
 * @pre Puntero a espacio, fila 1
 * @post Output==NO_ID
 */
void test2_space_get_gdesc();

/**
 * @test Prueba space_set_id
 * @pre Puntero nulo al espacio, fila 2
 * @post Output==NULL
 */
void test1_space_set_gdesc();

/**
 * @test Prueba space_set_id
 * @pre Puntero nulo al espacio, fila 2
 * @post Output==NULL
 */
void test2_space_set_gdesc();

/**
 * @test Prueba space_get_north_link
 * @pre Puntero no nulo al espacio y al enlace
 * @post Output!=NULL
 */
void test1_space_get_north_link();

/**
 * @test Prueba space_get_north_link
 * @pre Puntero nulo al espacio
 * @post Output==NULL
 */
void test2_space_get_north_link();

/**
 * @test Prueba space_get_south_link
 * @pre Puntero no nulo al espacio y al enlace
 * @post Output!=NULL
 */
void test1_space_get_south_link();

/**
 * @test Prueba space_get_south_link
 * @pre Puntero nulo al espacio
 * @post Output==NULL
 */
void test2_space_get_south_link();

/**
 * @test Prueba space_get_east_link
 * @pre Puntero no nulo al espacio y al enlace
 * @post Output!=NULL
 */
void test1_space_get_east_link();

/**
 * @test Prueba space_get_east_link
 * @pre Puntero nulo al espacio
 * @post Output==NULL
 */
void test2_space_get_east_link();

/**
 * @test Prueba space_get_west_link
 * @pre Puntero no nulo al espacio y al enlace
 * @post Output!=NULL
 */
void test1_space_get_west_link();

/**
 * @test Prueba space_get_west_link
 * @pre Puntero nulo al espacio
 * @post Output==NULL
 */
void test2_space_get_west_link();

/**
 * @test Prueba space_set_iluminacion
 * @pre Puntero no nulo al espacio
 * @post Output==OK
 */
void test1_space_set_iluminacion();

/**
 * @test Prueba space_set_iluminacion
 * @pre Puntero nulo al espacio
 * @post Output==ERROR
 */
void test2_space_set_iluminacion();

/**
 * @test Prueba space_get_iluminacion
 * @pre Puntero no nulo al espacio
 * @post Output==TRUE
 */
void test1_space_get_iluminacion();

/**
 * @test Prueba space_get_iluminacion
 * @pre Puntero nulo al espacio
 * @post Output==FALSE
 */
void test2_space_get_iluminacion();

/**
 * @test Prueba space_set_up
 * @pre Puntero no nulo al espacio
 * @post Output==OK
 */
void test1_space_set_up();

/**
 * @test Prueba space_set_up
 * @pre Puntero nulo al espacio
 * @post Output==ERROR
 */
void test2_space_set_up();

/**
 * @test Prueba space_set_down
 * @pre Puntero no nulo al espacio
 * @post Output==OK
 */
void test1_space_set_down();

/**
 * @test Prueba space_set_down
 * @pre Puntero nulo al espacio
 * @post Output==ERROR
 */
void test2_space_set_down();

/**
 * @test Prueba space_get_up
 * @pre Puntero no nulo al espacio
 * @post Output==Id up
 */
void test1_space_get_up();

/**
 * @test Prueba space_get_up
 * @pre Puntero nulo al espacio
 * @post Output==NO_ID
 */
void test2_space_get_up();

/**
 * @test Prueba space_get_down
 * @pre Puntero no nulo al espacio
 * @post Output==Id down
 */
void test1_space_get_down();

/**
 * @test Prueba space_get_down
 * @pre Puntero nulo al espacio
 * @post Output==NO_ID
 */
void test2_space_get_down();

/**
 * @test Prueba space_get_up_link
 * @pre Puntero no nulo al espacio y al enlace
 * @post Output!=NULL
 */
void test1_space_get_up_link();

/**
 * @test Prueba space_get_up_link
 * @pre Puntero nulo al espacio y al enlace
 * @post Output==NULL
 */
void test2_space_get_up_link();

/**
 * @test Prueba space_get_down_link
 * @pre Puntero no nulo al espacio y al enlace
 * @post Output!=NULL
 */
void test1_space_get_down_link();

/**
 * @test Prueba space_get_down_link
 * @pre Puntero nulo al espacio y al enlace
 * @post Output==NULL
 */
void test2_space_get_down_link();

/**
 * @test Prueba space_set_description
 * @pre Cadena con la descripcion
 * @post Ouput==OK
 */
void test1_space_set_description();

/**
 * @test Prueba space_set_description
 * @pre Puntero nulo a Space, puntero no nulo a name
 * @post Output==ERROR
 */
void test2_space_set_description();

/**
 * @test Prueba space_get_description
 * @pre Devuelve la descripcion
 * @post Output==0
 */
void test1_space_get_description();

/**
 * @test Prueba space_get_description
 * @pre Puntero nulo a Space
 * @post Output==NULL
 */
void test2_space_get_description();

/**
 * @test Prueba space_set_description_detallada
 * @pre Cadena con la descripcion
 * @post Ouput==OK
 */
void test1_space_set_description_detallada();

/**
 * @test Prueba space_set_description_detallada
 * @pre Puntero nulo a Space, puntero no nulo a name
 * @post Output==ERROR
 */
void test2_space_set_description_detallada();

/**
 * @test Prueba space_get_description_detallada
 * @pre Devuelve la descripcion detallada
 * @post Output==0
 */
void test1_space_get_description_detallada();

/**
 * @test Prueba space_get_description_detallada
 * @pre Puntero nulo a Space
 * @post Output==NULL
 */
void test2_space_get_description_detallada();

#endif
