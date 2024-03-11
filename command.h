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
 * @author Diego Tabero & Marcos Leo Sonck
 * 
 * This function reads a line of user input from stdin, tokenizes it, and matches it against
 * the command mappings to determine the corresponding command value
 * 
 * @return The command value corresponding to the user input, or NO_CMD if no valid command is found
 **/

void command_get_user_input(Command *command);


/**
 * @brief Allocates memory for the command structure and initializes its values
 * @author Diego Tabero & Marcos Leo Sonck
 * 
 * @return a pointer to the command structure, or NULL if something went wrong
 **/

Command *command_create(); 

/**
 * @brief sets the last_cmd to the given value
 * @author Diego Tabero & Marcos Leo Sonck

 * @param command,  pointer to a Command structure
 * @param cmd, the last command
 * @return OK, if everything goes well or ERROR if there was some mistake
 
 */
Status command_set_last_cmd(Command *command, Cmd cmd);


/**
 * @brief gets the last_cmd executed in the game
 * @author Diego Tabero & Marcos Leo Sonck

 * @param command,  pointer to a Command structure
 * @return the command, if everything goes well and if there was some mistake, NO_CMD
 
 */
Cmd command_get_last_cmd(Command *command);


/**
 * @brief sets the status of the last command
 * @author Diego Tabero & Marcos Leo Sonck

 * @param command,  pointer to a Command structure
 * @param status, the status output of the last command
 * @return OK, if everything goes well or ERROR if there was some mistake
 
 */
Status command_set_last_cmd_status(Command *command,Status status);


/**
 * @brief sets the status of the last command
 * @author Diego Tabero & Marcos Leo Sonck
 * 
 * @param command,  pointer to a Command structure
 * @return the status output of the last command
 */
Status command_get_last_cmd_status(Command *command);

/**
 * @brief frees the memory used by the command strcture and sets the pointer to NULL
 * @author Diego Tabero & Marcos Leo Sonck
 * 
 * @param command,  pointer to a Command structure
 * @return OK, if everything goes well, or ERROR if there was some mistake
 */
Status command_destroy(Command *command);

/**
 * @brief gets the current command being executed
 * @author Diego Tabero & Marcos Leo Sonck
 * 
 * @param command,  pointer to a Command structure
 * @return the command, if everything goes well and if there was some mistake, NO_CMD
 
 */
Cmd command_get_cmd(Command *command);

/**
 * @brief returns the target of the command being executed
 * @author Diego Tabero & Marcos Leo Sonck
 * 
 * @param command,  pointer to a Command structure
 * @return an arrary containing the input of the user
 */
char *command_get_target(Command *command);


/**
 * @brief it cleans the target of the command 
 * @author Diego Tabero & Marcos Leo Sonck
 * 
 * @param command,  pointer to a Command structure
 * @return OK, if everuthing goes well or ERROR if there was some mistake
 */
Status command_clean_target(Command *command);

#endif