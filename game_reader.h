/**
 * @brief It loads the game spaces
 *
 * @file game_reader.h
 * @author Recurso 1
 * @version 3.5
 * @date 4-02-2024
 * @copyright GNU Public License
 */


#ifndef GAMEREADER_H
#define GAMEREADER_H

#include "types.h"
#include "game.h"

/**
 * @brief It loads new space.

 * @param game, pointer to Game structure
 * @param filename, pointer to char, (string) with the filename
 * @return OK, if everything goes well or ERROR if there was some mistake
 
 */
Status game_load_spaces(Game *game, char *filename);


/**
 * @brief It adds a space to the game.

 * @param game, pointer to Game structure
 * @param filename, pointer to char, (string) with the filename
 * @return OK, if everything goes well or ERROR if there was some mistake
 */

Status game_add_space(Game *game, Space *space);

/**
 * @brief It is used to get the ID of the space located at a specific position in the game

 * @param game, pointer to Game structure
 * @param position, integer
 * @return ID of the space at the specified position
 */

Id game_get_space_id_at(Game *game, int position);

#endif