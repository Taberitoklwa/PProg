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
  Player* player; /*!< Id number of the object location */
  Object* objects[MAX_OBJECTS]; /*!< Id number of the player location */
  int n_objects; /*<Number of objects */
  Character* characters[MAX_CHARACTERS];
  int n_characters;
  Space *spaces[MAX_SPACES];/*!<It is declaring an array of pointers to `Space` objects.This array is used to store the different spaces in the game.>!*/
  int n_spaces; /*!<It is declaring an integer that contains the number of spaces>!*/
  Command *command; /*!<Command Struct */
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

Status game_actions_update(Game *game);

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
 * @brief It returns the pointer to the player

 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 * @return the pointer of the player, or NULL if there was an error
 */

Player *game_get_player(Game *game);

/**
 * @brief Set the current location of the player in the game

 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 * @param  id, the id number of the player location 
 * @return OK, if everything goes well or ERROR if there was some mistake
 */

Status game_set_player_location(Game *game, Id id);

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

Status game_set_object_location(Game *game, Object*object, Id id);

/**
 * @brief Retrieves the character ID associated with a space.
 *
 * This function retrieves the ID of the character associated with the specified space in the game.
 *
 * @param space Pointer to the space structure.
 * @return The ID of the character associated with the space.
 *         Returns NO_ID if there is no character associated with the space or if the space is NULL.
 */
Id game_get_space_character_id(Space *space);

/**
 * @brief Retrieves a character by its ID from the game.
 *
 * This function retrieves the character with the specified ID from the game.
 *
 * @param game Pointer to the game structure.
 * @param id The ID of the character to be retrieved.
 * @return Pointer to the character structure if found, NULL otherwise.
 */
Character *game_get_character(Game *game, Id id);

/**
 * @brief Retrieves the location ID of a character in the game.
 *
 * This function retrieves the location ID of the specified character in the game.
 *
 * @param game Pointer to the game structure.
 * @param character Pointer to the character whose location ID is to be retrieved.
 * @return The location ID of the character. Returns NO_ID if the character or game is NULL, or if the character is not found in the game.
 */
Id game_get_character_location(Game *game, Character *character);

/**
 * @brief Retrieves the number of objects in the game.
 *
 * This function retrieves the total number of objects present in the game.
 *
 * @param game Pointer to the game structure.
 * @return The number of objects in the game.
 *         Returns 0 if the game is NULL or if there are no objects in the game.
 */
int game_get_num_objects(Game *game);

/**
 * @brief Gets an id of a set at a especified position
 *
 * @param game Pointer to the game structure.
 * @param set Poinyer to the set structure
 * @param i, index in the set
 * @return Id especified in the set.
 */
Id game_set_get_id(Game *game,Set *set, int i);

/**
 * @brief Returns the object at a specified index in a game's object array
 * 
 * @param game pointer to the `Game` struct
 * @param i Index of the object in the game's object array that you want to retrieve.
 * 
 * @return Returns the object at index i in the objects array. If the Game pointer is NULL or if the index i is out of bounds then it returns NULL
 */
Object *game_get_object_at(Game *game, int i);


Set *game_get_objects_in_space(Game *game, Id id);

/**
 * @brief Returns the character at a specified index in a game's character array
 * 
 * @param game pointer to the `Game` struct
 * @param i Index of the object in the game's character array that you want to retrieve.
 * 
 * @return Returns the character at index i in the objects array. If the Game pointer is NULL or if the index i is out of bounds then it returns NULL
 */
Character *game_get_character_at(Game *game, int i);

/**
 * @brief Retrieves the command structure that was executed in the game

 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 * @return a command type variable
 */
Command *game_get_command(Game *game);

/**
 * @brief Retrieves the last command that was executed in the game

 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 * @return a command type variable
 */
Cmd game_get_last_command(Game *game);

/**
 * @brief sets the last command that was executed in the game
 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 * @param cmd, the command that wants to be set
 * @return Ok if everything goes well or ERROR if there was some mistake
 */
Status game_set_last_command(Game *game, Cmd cmd);

/**
 * @brief Retrieves the current command being executed in the game
 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 * @return a command type variable
 */
Cmd game_get_command_cmd(Game *game);

/**
 * @brief returns the target of the command being executed
 * @param command,  pointer to a Command structure
 * @return an arrary containing the input of the user
 */
char *game_get_command_target(Game *game);

/**
 * @brief it cleans the target of the command in the game
 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 * @return OK, if everuthing goes well or ERROR if there was some mistake
 */
Status game_command_clean_target(Game *game);

/**
 * @brief sets the status of the last command
 * @param  game, pointer to a `Game` structure, which represents the current state of the game being played
 * @param status, the status output of the last command
 * @return OK, if everything goes well or ERROR if there was some mistake
 
 */
Status game_set_last_command_status(Game *game, Status status);

/**
 * @brief sets the status of the last command
 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 * @return the status output of the last command
 */
Status game_get_last_command_status(Game *game);

/**
 * @brief It is used to get the finished status of the game
 * 
 * @param game, pointer to a Game structure, which represents the current state of the game being played

 * @return true or false wether the game is finished or not
 
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
 * @brief Retrieves the number of IDs contained in a set associated with a game.
 *
 * This function retrieves the number of IDs contained within the specified set that is associated with the given game.
 *
 * @param game Pointer to the game structure.
 * @param set Pointer to the set whose number of IDs is to be retrieved.
 * @return The number of IDs contained in the set associated with the game. Returns -1 if the game or set is NULL, or if the set is not associated with the game.
 */
int game_get_set_nids(Game *game, Set *set);

/** 
 * @brief It prints information about the current state of a game
 * 
 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 
 */

void game_print(Game *game);

#endif
