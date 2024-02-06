/**
 * @brief It defines the game interface
 *
 * @file game.h
 * @author Profesores PPROG
 * @version 3.5
 * @date 26-01-2024
 * @copyright GNU Public License
 */

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h"
#include "types.h"

#define MAX_SPACES 100

typedef struct _Game {
  Id player_location; /*!< Id number of the player location */
  Id object_location; /*!< Id number of the object location */
  Space *spaces[MAX_SPACES];/*!<It is declaring an array of pointers to `Space` objects.This array is used to store the different spaces in the game.>!*/
  int n_spaces; /*!<It is declaring an integer that contains the number of spaces>!*/
  Command last_cmd; 
  Bool finished; /*!< Whether it is finished or not */
} Game;

/**
 * @brief Creates a new game.

 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 * @return OK, if everything goes well or ERROR if there was some mistake
 
 */

Status game_create(Game *game);

/**
 * @brief Creates a new game by loading the spaces from a file and makes a call to the function.

 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 * @param filename, pointer to char, (string) with the filename
 * @return OK, if everything goes well or ERROR if there was some mistake
 
 */

Status game_create_from_file(Game *game, char *filename);

/**
 * @brief Updates the game state based on the given command.

 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 * @param cmd, Command
 * @return OK, if everything goes well or ERROR if there was some mistake
 
 */


Status game_actions_update(Game *game, Command cmd);

/**
 * @brief It destroys the game by by successive calls to the space_destroy function that frees the allocated memory.

 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 * @return OK, if everything goes well or ERROR if there was some mistake
 
 */
Status game_destroy(Game *game);

/**
 * @brief Retrieves a specific space in the game based on its ID

 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 * @param  id, the id number of the space  
 * @return It returns a pointer to Space structure (a especific space in the game based on its ID)
 
 */


Space *game_get_space(Game *game, Id id);

/**
 * @brief It is used to retrieve the current location of the player in the game

 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 * @return the Id number of the player location
 
 */


Id game_get_player_location(Game *game);

/**
 * @brief Set the current location of the player in the game

 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 * @param  id, the id number of the player location 
 * @return OK, if everything goes well or ERROR if there was some mistake
 
 */

Status game_set_player_location(Game *game, Id id);

/**
 * @brief  It is used to get the current location of the object in the game

 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 * @return the ID of the object at the specified position
 
 */

Id game_get_object_location(Game *game);

/**
 * @brief Set the current location of the object in the game

 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 * @param  id, the id number of the object location 
 * @return OK, if everything goes well or ERROR if there was some mistake
 
 */

Status  game_set_object_location(Game *game, Id id);

/**
 * @brief Retrieves the last command that was executed in the game

 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 * @return a command type variable
 
 */

Command game_get_last_command(Game *game);

/**
 * @brief It is used to set the last command that was executed in the game

 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 * @param  command, last read command
 * @return OK, if everything goes well or ERROR if there was some mistake
 
 */


Status game_set_last_command(Game *game, Command command);

/**
 * @brief It is used to retrieve the current state of the game

 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 * @return It returns a boolean value  `finished`
 
 */


Bool game_get_finished(Game *game);

/**
 * @brief It is used to set is used to set the finished status of the game
 * 
 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 * @param  finished, boolean value indicating the game is finished 
 * @return OK, if everything goes well or ERROR if there was some mistake
 
 */

Status game_set_finished(Game *game, Bool finished);

/**
 * @brief 
 * 
 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 
 */

void game_print(Game *game);

#endif
