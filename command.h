/**
 * @brief It implements the command interpreter interface
 *
 * @file command.h
 * @author Profesores PPROG, Diego Tabero, Marcos Leo Sonck
 * @version 3.5
 * @date 12-02-2024
 * @copyright GNU Public License
 */


#include "game.h"
#include "types.h"
#ifndef COMMAND_H
#define COMMAND_H

#define N_CMDT 2 /*Number of types of commands*/
#define N_CMD 11 /*Number of commands*/


typedef enum { CMDS, CMDL } CommandType; /*Enumeration for command type (short or long)*/

typedef enum { NO_CMD = -1, UNKNOWN, EXIT, NEXT, BACK, LEFT, RIGHT, TAKE, DROP, ATTACK, CHAT } Cmd; /*Enumeration for command values*/

typedef struct _Command Command; 

/**
 * @brief Reads user input and returns the corresponding command
 * 
 * This function reads a line of user input from stdin, tokenizes it, and matches it against
 * the command mappings to determine the corresponding command value
 * 
 * @return The command value corresponding to the user input, or NO_CMD if no valid command is found
 **/

void command_get_user_input(Command *command);

Command *command_create(); 

Status command_destroy(Command *command);

Cmd command_get_cmd(Command *command);

char *command_get_target(Command *command);

#endif