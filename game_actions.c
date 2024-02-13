/**
 * @brief It implements the game update through user actions
 *
 * @file game.c
 * @author Profesores PPROG, Diego Tabero, Marcos Leo Sonck
 * @version 3.5
 * @date 11-02-2024
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game_actions.h"

/**
   Private functions
*/

void game_actions_unknown(Game *game);

void game_actions_exit(Game *game);

void game_actions_next(Game *game);

void game_actions_back(Game *game);

void game_actions_take(Game *game);

void game_actions_drop(Game *game);

/**
   Game actions implementation
*/

Status game_actions_update(Game *game, Command cmd) {
  game_set_last_command(game, cmd);

  switch (cmd) {
    case UNKNOWN:
      game_actions_unknown(game);
      break;

    case EXIT:
      game_actions_exit(game);
      break;

    case NEXT:
      game_actions_next(game);
      break;

    case BACK:
      game_actions_back(game);
      break;

    case TAKE:
      game_actions_take(game);
      break;

    case DROP:
      game_actions_drop(game);
      break;

    default:
      break;
  }

  return OK;
}

/**
   Calls implementation for each action
*/

/**
 * @brief Handles unknown commands in the game
 *
 *
 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 **/

void game_actions_unknown(Game *game) {}
/**
 * @brief Handles the exit command in the game
 *
 *
 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 **/
void game_actions_exit(Game *game) {}
/**
 * @brief Handles the next command in the game
 *
 * This function updates the player's location to the next space to the south if possible.
 *
 * @param game, pointer to a Game structure, which represents the current state of the game being played
 **/

void game_actions_next(Game *game) {
  Id current_id = NO_ID; /*Initializes an id to NO_ID*/
  Id space_id = NO_ID; /*Initializes space id to NO_ID*/

  space_id = game_get_player_location(game); /*Sets space_id to the id of the location of the player*/
  if (space_id == NO_ID) {
    return;
  }

  current_id = space_get_south(game_get_space(game, space_id)); /*Sets current_id to the id of the space south to the current space of the player */
  if (current_id != NO_ID) {
    game_set_player_location(game, current_id); /*Updates player´s location to the previous space*/
  }

  return;
}

/**
 * @brief Handles the back command in the game
 * 
 * This function updates the player's location to the next space to the north if possible
 * 
 * @param game A pointer to the Game struct, which contains information about the current state of the
 * game.

 */
  void game_actions_back(Game *game) {
    Id current_id = NO_ID;
    Id space_id = NO_ID; 

    space_id = game_get_player_location(game); /*Sets space_id to the id of the location of the player*/

    if (NO_ID == space_id) {
      return;
    }

    current_id = space_get_north(game_get_space(game, space_id)); /*Sets current_id to the id of the space north to the current space of the player */
    if (current_id != NO_ID) {
      game_set_player_location(game, current_id); /*Updates player´s location to the previous space*/
    }

    return;
  }


/**
 * @brief Allows the player to take an object from their current location in the game.
 * 
 * @param game, pointer to a `Game` structure, which represents the current state of the game being played

 */
void game_actions_take(Game *game){

  /* Declaring variables and initializing them with the default value NO_ID or NULL(pointer) */

  Id object_id = NO_ID;
  Id player_location_id = NO_ID;
  Id object_location_id = NO_ID;
  Space * space = NULL;
  

  object_id = object_get_id(game->object);

  if (NO_ID == object_id) {
    return;
  }

  player_location_id = player_get_location(game->player);

  if (NO_ID == player_location_id) {
    return;
  }

  object_location_id = game_get_object_location(game);

   if (NO_ID == object_location_id) {
    return;
  }

  if( object_location_id!=player_location_id) {
    return;
  }

  space = game_get_space(game, object_location_id);

  if(!space) {
    return;
  }
  

  /*Function call that sets the object ID of the player to an ID, indicating that the player is currently holding any object. */

  player_set_object(game->player, object_id);

  /*Is setting the object ID of the current space to NO_ID, indicating that there is no object in that space because the player has taken it.*/

  space_set_object(space,NO_ID);


  return;
}

/**
 * @brief Allows the player to drop an object they are currently holding in the game, placing it in the current space they are in.
 * 
 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 *
 */

void game_actions_drop(Game *game) {
  Id object_id = NO_ID;
  Id playerlocation_id = NO_ID;
  Space *space = NULL;

  object_id = player_get_object(game->player);

  if(object_id == NO_ID) {
    return;
  }

  playerlocation_id = player_get_location(game->player);

  if(playerlocation_id == NO_ID) {
    return;
  }

  space = game_get_space(game, playerlocation_id);

  if(space == NULL) {
    return;
  }



  /*Function call that sets the object ID of the player to NO_ID, indicating that the player is not currently holding any object. */
  
  player_set_object(game->player, NO_ID);

   /*Is setting the object ID of the current space to an ID, indicating that there is an object in that space because the player has dropped it.*/

  space_set_object(space,object_id);  

  return;
}