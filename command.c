/**
 * @brief It implements the command interpreter
 *
 * @file command.c
 * @author Profesores PPROG, Diego Tabero, Marcos Leo Sonck
 * @version 3.5
 * @date 12-02-2024
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <string.h>
#include <strings.h>

#include "command.h"

#define CMD_LENGHT 30 /*Maximum lenght of command string*/

/*Array to map command enum values to their string representations*/
char *cmd_to_str[N_CMD][N_CMDT] = {{"", "No command"}, {"", "Unknown"}, {"e", "Exit"}, {"n", "Next"}, {"b", "Back"}, {"t", "Take"}, {"d", "Drop"}};

Command command_get_user_input() {
  Command cmd = NO_CMD; /*Initializes command variable to default value NO_CMD*/
  char input[CMD_LENGHT] = "", *token = NULL; /*Initializes buffer for user input to empty string and pointer to a token to NULL */
  int i = UNKNOWN - NO_CMD + 1; /*Sets index for command search in array*/

  /*Reads user input from stdin*/
  if (fgets(input, CMD_LENGHT, stdin)) {
    token = strtok(input, " \n"); /*Divides input into tokens*/
    cmd = UNKNOWN;  /*Sets command to UNKNOWN*/

    /*Loop that ends when a match is found in command mapings or end of array is reached*/
    while (token && cmd == UNKNOWN && i < N_CMD) {
      /*Checks if token matches short or long form of a command*/
      if (!strcasecmp(token, cmd_to_str[i][CMDS]) || !strcasecmp(token, cmd_to_str[i][CMDL])) { 
        cmd = i + NO_CMD; /*Sets command to enum value*/
      } else {
        i++; /*Move to next command mapping*/
      }
    }
  }

  return cmd; /*Returns the identified commannd*/
}
