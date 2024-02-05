/**
 * @brief It defines the game update through user actions
 *
 * @file game.h
 * @author Profesores PPROG
 * @version 3.5
 * @date 26-01-2024
 * @copyright GNU Public License
 */

#ifndef GAME_ACTIONS_H
#define GAME_ACTIONS_H

#include "command.h"
#include "game.h"
#include "types.h"

/**
 * @brief Updates the game state based on the user command
 *
 * This function is responsible for updating the game state based on the user command received.
 *
 * @param game The game object
 * @param cmd The command received from the user
 * @return The status of the update operation (OK if successful, ERROR otherwise)
 **/
Status game_actions_update(Game *game, Command cmd);

#endif
