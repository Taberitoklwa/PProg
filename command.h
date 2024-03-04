/**
 * @brief It implements the command interpreter interface
 *
 * @file command.h
 * @author Profesores PPROG, Diego Tabero, Marcos Leo Sonck
 * @version 3.5
 * @date 12-02-2024
 * @copyright GNU Public License
 */

#ifndef COMMAND_H
#define COMMAND_H

#define N_CMDT 2 /*Number of types of commands*/
#define N_CMD 11 /*Number of commands*/

typedef enum { CMDS, CMDL } CommandType; /*Enumeration for command type (short or long)*/

typedef enum { NO_CMD = -1, UNKNOWN, EXIT, NEXT, BACK, LEFT, RIGHT, TAKE, DROP, ATTACK, CHAT } Command; /*Enumeration for command values*/

/**
 * @brief Reads user input and returns the corresponding command
 * 
 * This function reads a line of user input from stdin, tokenizes it, and matches it against
 * the command mappings to determine the corresponding command value
 * 
 * @return The command value corresponding to the user input, or NO_CMD if no valid command is found
 **/

Command command_get_user_input();

#endif