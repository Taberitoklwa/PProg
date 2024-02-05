/**
 * @brief It implements the game update through user actions
 *
 * @file game.c
 * @author Profesores PPROG
 * @version 3.5
 * @date 26-01-2024
 * @copyright GNU Public License
 */

#include "game_actions.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"

/**
   Private functions
*/

void game_actions_unknown(Game *game);

void game_actions_exit(Game *game);

void game_actions_next(Game *game);

void game_actions_back(Game *game);

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
 * @param game The game object
 **/

void game_actions_unknown(Game *game) {}
/**
 * @brief Handles the exit command in the game
 *
 *
 * @param game The game object
 **/
void game_actions_exit(Game *game) {}
/**
 * @brief Handles the next command in the game
 *
 * This function updates the player's location to the next space to the south if possible.
 *
 * @param game The game object
 **/

void game_actions_next(Game *game) {
  Id current_id = NO_ID; /*Initializes an id to NO_ID*/
  Id space_id = NO_ID; /*Initializes space if to NO_ID*/

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

void game_actions_back(Game *game) {
  Id current_id = NO_ID; /*Initializes an id to NO_ID*/
  Id space_id = NO_ID; /*Initializes space if to NO_ID*/

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
