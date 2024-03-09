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
#include "object.h"
#include "player.h"
#include "character.h"

#define MAX_SPACES 100
#define MAX_OBJECTS 10
#define MAX_CHARACTERS 10

typedef struct _Game {
  Object* objects[MAX_OBJECTS]; /*!< Id number of the player location */
  int n_objects;
  Player* player; /*!< Id number of the object location */
  Character* characters[MAX_CHARACTERS];
  int n_characters;
  Space *spaces[MAX_SPACES];/*!<It is declaring an array of pointers to `Space` objects.This array is used to store the different spaces in the game.>!*/
  int n_spaces; /*!<It is declaring an integer that contains the number of spaces>!*/
  Cmd last_cmd; /*!<Last command that has been introduced>!*/
  Command *command;
  Status last_cmd_status;
  Bool finished; /*!< Whether it is finished or not>!*/
} Game;

/**
 * @brief Creates a new game.
 * 
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
 * @brief It adds a space to the game.

 * @param game, pointer to Game structure
 * @param filename, pointer to char, (string) with the filename
 * @return OK, if everything goes well or ERROR if there was some mistake
 */

Status game_add_space(Game *game, Space *space);

/**
 * @brief Updates the game state based on the given command.

 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 * @param cmd, Command
 * @return OK, if everything goes well or ERROR if there was some mistake
 
 */

Status game_actions_update(Game *game, Command *command);

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

Id game_get_character_location(Game *game, Character *character);
/**
 * @brief It adds an object to the game.

 * @param game, pointer to Game structure
 * @param filename, pointer to char, (string) with the filename
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status game_add_object(Game *game, Object *object);

/**
 * @brief  It is used to get the current location of the object in the game

 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 * @return the ID of the object at the specified position
 
 */

/*Id game_get_object_location(Game *game);*/

Id game_get_object_location(Game *game, Object *object);

/**
 * @brief Retrieves a specific object in the game based on its ID

 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 * @param  id, the id number of the object  
 * @return It returns a pointer to Object structure (a especific object in the game based on its ID)
 
 */

Object* game_get_object(Game *game, Id id);

/**
 * @brief Set the current location of the object in the game

 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 * @param  id, the id number of the object location 
 * @param object, pointer to the object 
 * @return OK, if everything goes well or ERROR if there was some mistake
 
 */

Status  game_set_object_location(Game *game, Object*object, Id id);

Id game_get_space_character_id(Space *space);

Character *game_get_character(Game *game, Id id); 

int game_get_num_objects(Game *game);

/*Command game_get_last_command_status(Game *game) {return game->last_cmd_status;}*/


Object **game_get_objects(Game *game);

/**
 * @brief Returns the set of object ids in a space

 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 * @param  id, the id number of the space  
 * @return a pointer to the set, if everything goes well or NULL if there was some mistake
 
 */
Set *game_get_objects_in_space(Game *game, Id id);

/**
 * @brief Retrieves the last command that was executed in the game

 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 * @return a command type variable
 */

Cmd game_get_last_command(Game *game);

Cmd game_get_command_cmd(Game *game,Command *command);

char *game_get_command_target(Game *game,Command *command);
/**
 * @brief Returns a pointer to the ids of a set

 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 * @param  set, a pointer to the set  
 * @return a pointer to the ids, if everything goes well or NULL if there was some mistake
 
 */
Id * game_get_set_ids(Game *game,Set *set);


/**
 * @brief Returns number of ids in a set

 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 * @param  set, a pointer to the set  
 * @return a the number of ids
 
 */
int game_get_set_nids(Game *game,Set* objects);
/**
 * @brief It is used to set the last command that was executed in the game

 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 * @param  command, last read command
 * @return OK, if everything goes well or ERROR if there was some mistake
 
 */

Status game_set_last_command(Game *game, Cmd cmd);

Status game_set_last_command_status(Game *game, Status status);

Status game_get_last_command_status(Game *game);
/**
 * @brief It is used to retrieve the current state of the game

 * @param game, pointer to a  Game structure, which represents the current state of the game being played
 * @return It returns a boolean value `finished`
 * 
 */


Bool game_get_finished(Game *game);

/**
 * @brief It is used to set is used to set the finished status of the game
 * 
 * @param game, pointer to a Game structure, which represents the current state of the game being played
 * @param  finished, boolean value indicating the game is finished 
 * @return OK, if everything goes well or ERROR if there was some mistake
 
 */

Status game_set_finished(Game *game, Bool finished);

/** 
 * @brief It prints information about the current state of a game
 * 
 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 
 */

void game_print(Game *game);

#endif
