/**
 * @brief Funciones para el manejo de enlaces entre espacios
 *
 * @file link.c
 * @author Adrián Martínez Bayán
 * @version 1.0
 * @date 27-03-2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/link.h"

/**
* @brief Estructura de datos Link
* @author Adrián Martínez Bayán
* @date 27/03/2021
*/
struct _Link {
	Id id;                      /*!<Id del enlace*/
	char name[WORD_SIZE + 1];   /*!<Nombre del enlace*/
	Id primero;                 /*!<Id del primer espacio del enlace*/
	Id segundo;                 /*!<Id del segundo espacio del enlace*/
	ESTADO estado;              /*!<Estado del enlace*/
	char dir[WORD_SIZE+1];			/*!<Direccion del enlace*/
};

Link* link_create(Id id) {
	Link *link = NULL;

	if (id == NO_ID)
		return NULL;

	link = (Link*) malloc(sizeof(Link));
	if(!link)
		return NULL;

	link->id = id;
	link->primero = NO_ID;
	link->segundo = NO_ID;
	link->name[0] ='\0';
	link->estado = CERRADO;
	link->dir[0] = '\0';

	return link;
}

STATUS link_destroy(Link* link) {
	if (!link) {
		return ERROR;
  }

	free(link);
	return OK;
}

STATUS link_set_id(Link* link, Id id) {
	if (!link || id == NO_ID)
		return ERROR;
	link->id = id;
	return OK;
}

STATUS link_set_name(Link* link, char* name) {
	if (!link || !name)
		return ERROR;

	if (!strcpy(link->name, name))
		return ERROR;

	return OK;
}

STATUS link_set_id_primero(Link* link, Id id) {
	if (!link || id == NO_ID)
		return ERROR;

	link->primero = id;

	return OK;
}

STATUS link_set_id_segundo(Link* link, Id id) {
	if (!link || id == NO_ID)
		return ERROR;

	link->segundo = id;

	return OK;
}

STATUS link_set_estado(Link* link, ESTADO estado) {
	if (!link)
		return ERROR;

	link->estado = estado;

	return OK;
}

Id link_get_id(Link* link) {
	if (!link)
		return NO_ID;
	return link->id;
}

const char* link_get_name(Link* link) {
	if (!link)
		return NULL;
	return link->name;
}

Id link_get_id_primero(Link* link) {
	if (!link)
		return NO_ID;
	return link->primero;
}

Id link_get_id_segundo(Link* link) {
	if (!link)
		return NO_ID;
	return link->segundo;
}

ESTADO link_get_estado(Link* link) {
	if (!link)
		return CERRADO;
	return link->estado;
}

char* link_get_dir(Link* link){
	if(!link) return NULL;
	return link->dir;
}

STATUS link_set_dir(Link* link, char* dir){
	if(!link || !dir) return ERROR;
	strcpy(link->dir, dir);
	return OK;
}

STATUS link_print(Link* link) {
	if (!link)
		return ERROR;

	printf("--> link (Id: %ld; Nombre: %s; Estado: %d; Primer espacio: %ld; Segundo espacio: %ld)\n", link->id, link->name, link->estado, link->primero, link->segundo);

	return OK;
}
