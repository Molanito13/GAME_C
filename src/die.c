/**
 * @brief Define un dado
 *
 * @file die.c
 * @author Daniel Molano Caraballo
 * @version 1.0
 * @date 02-03-2021
 */

#include "../include/die.h"

/**
* @brief Estructura de datos Die
* @author Daniel Molano Caraballo
* @date 02/03/2021
*/
struct _Die{
	Id id;			/*!<Id del objeto*/
	int max;		/*!<Valor maximo del dado*/
	int min;		/*!<Valor minimo del dado*/
	int value;		/*!<Valores del objeto*/
};

Die* die_create(Id id){

	Die * newDie = NULL;

	if(id <= NO_ID) return NULL;

	newDie = (Die*)malloc(sizeof(Die));

	if(!newDie) return NULL;

	newDie->id = id;
	newDie->max = MAX_DIE_V;
	newDie->min = MIN_DIE_V;
	newDie->value = 0;

	return newDie;
}

STATUS die_destroy(Die* die){

	if(!die) return ERROR;

	free(die);

	return OK;
}

STATUS die_print(Die* die){

	if(!die) return ERROR;

	fprintf(stdout, "\nId del dado: %ld", die->id);
	fprintf(stdout, "\nValor maximo del dado: %d", die->max);
	fprintf(stdout, "\nValor minimo del dado: %d", die->min);
	fprintf(stdout, "\nValor del dado: %d", die->value);

	return OK;
}

int die_roll(Die* die){

	int i;

	if(!die) return -1;

	srand(time(NULL));

	for(i = 0; i<MAX_DIE; i++){
		die->value = ((rand()%MAX_DIE_V) + MIN_DIE_V);
	}

	return die->value;
}

Id die_get_id(Die* die){

	if(!die) return NO_ID;

	return die->id;
}

STATUS die_set_id(Die* die, Id id){

	if(!die) return ERROR;

	die->id = id;

	return OK;
}

int die_get_value(Die* die){

	if(!die) return -1;

	return die->value;
}

STATUS die_set_value(Die* die, int newValue){

	if(!die) return ERROR;

	die->value=newValue;

	return OK;
}
