/**
 * @brief It implements the game update through user actions
 *
 * @file game.c
 * @author Profesores PPROG
 * @version 3.5
 * @date 26-01-2024
 * @copyright GNU Public License
 */


#ifndef GAMEREADER_H
#define GAMEREADER_H

#include "types.h"
#include "game.h"

Status game_load_spaces(Game *game, char *filename);

Status game_add_space(Game *game, Space *space);

Id game_get_space_id_at(Game *game, int position);


#endif