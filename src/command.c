/**
 * @brief Implementa la interpretación de los comandos
 *
 * @file command.c
 * @author Profesores PPROG, modificado por Carolina Monedero y Daniel Molano caraballo
 * @version 2.0
 * @date 10/02/2021
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include "../include/command.h"

#define CMD_LENGHT 30 /*!<Longitud maxima de lso comandos*/

/**
* @brief Estructura de datos Command
* @author Daniel Molano Caraballo
* @date 10/03/2021
*/
struct _Command {
	T_Command cmd; 								/*!<Comando a ejecutar*/
	char extra[WORD_SIZE + 1];		/*!<Cadena de caracteres extra por si se añade algo despues del comando ej, take o1*/
	char log[WORD_SIZE + 1];		/*!<Cadena de caracteres extra donde se guarda el comando para el log*/
	char last[WORD_SIZE + 1];		/*!<Cadena de caracters extra donde se guarda el 4º elemento a la hora de usar open*/	
};

/**
* @brief Recupera el comando introducido
*
* cmd_to_str Recupera el numero del comando introducido
*
* @date 10/02/2021
* @author: Profesores PPROG, modificado por grupo F
*
* @return Comando introducido por consola
*/
char *cmd_to_str[N_CMD][N_CMDT] = {
	{"","No command"},
	{"","Unknown"},
  {"e","Exit"},
	{"n","Next"},
	{"b","Back"},
  {"t", "Take"},
	{"d", "Drop"},
	{"r", "Right"},
	{"l", "Left"},
	{"rll", "Roll"},
	{"m", "Move"},
	{"i", "Inspect"},
	{"ton", "Turnon"},
	{"toff", "Turnoff"},
	{"o", "Open"},
	{"s", "Save"},
	{"lo", "Load"},
	{"a", "Answer"},
	{"p", "Pet"}
};

STATUS command_get_user_input(Command* c) {

	T_Command cmd = NO_CMD;
	char input[CMD_LENGHT] = "";
	char aux[CMD_LENGHT] = "";
	char* tok = NULL;
	int i = UNKNOWN - NO_CMD + 1;

	if(!c) return ERROR;

	if (fgets(input,CMD_LENGHT, stdin) != NULL)	{
		cmd = UNKNOWN;
		c->last[0] = '\0';
		if(strcmp(input,"\n") != 0){
			tok = strtok(input, " \n");
			if(tok != NULL){
				strcpy(aux, tok);
				tok = strtok(NULL," \n");
				if(tok != NULL){
					strcpy(c->extra, tok);
				} else{
					c->extra[0] = '\0';
				}
				tok = strtok(NULL," \n");
				if(tok != NULL){
					tok = strtok(NULL," \n");
					if(tok != NULL){
						strcpy(c->last, tok);
					} else{
						c->extra[0] = '\0';
					}
				}
			}
		}
		while(cmd == UNKNOWN && i < N_CMD){
			if (!strcasecmp(aux, cmd_to_str[i][CMDS]) || !strcasecmp(aux, cmd_to_str[i][CMDL])){
				cmd = i + NO_CMD;
				strcpy(c->log, cmd_to_str[i][CMDS]);
			}
			else
				i++;
		}
	}

	c->cmd = cmd;

  return OK;

}

Command* command_create(){

	Command* newC = NULL;

	newC = (Command*)calloc(1,sizeof(Command));

	if(!newC) return NULL;

	return newC;
}

STATUS command_destroy(Command* command){

	if(!command) return ERROR;

	free(command);

	return OK;
}

STATUS command_set_cmd(Command* c, T_Command cmd){

	if(!c) return ERROR;

	c->cmd = cmd;

	return OK;
}

T_Command command_get_cmd(Command* c){

	if(!c) return NO_CMD;

	return c->cmd;
}

STATUS command_set_extra(Command* c, char* newE){

	if(!c || !newE) return ERROR;

	strcpy(c->extra, newE);

	return OK;
}

char* command_get_extra(Command* c){

	if(!c) return NULL;

	return c->extra;
}

char* command_get_log(Command* c){

	if(!c) return NULL;

	return c->log;
}

char* command_get_last(Command* c){

	if(!c) return NULL;

	return c->last;
}
