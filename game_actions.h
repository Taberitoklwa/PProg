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

/**
 * @brief Updates the game state based on the user command
 *
 * This function is responsible for updating the game state based on the user command received.
 *
 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 * @param cmd The command received from the user
 * @return OK, if everything goes well or ERROR if there was some mistake
 **/
Status game_actions_update(Game *game, Command *command);

#endif
