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


#include "game.h"

/**
 * @brief It loads new space.

 * @param game,  pointer to a `Game` structure, which represents the current state of the game being played
 * @param filename, pointer to char, (string) with the filename
 * @return OK, if everything goes well or ERROR if there was some mistake
 
 */
Status game_reader_load_spaces(Game *game, char *filename);

/**
 * @brief It loads new objects.

 * @param game,  pointer to a `Game` structure, which represents the current state of the game being played
 * @param filename, pointer to char, (string) with the filename
 * @return OK, if everything goes well or ERROR if there was some mistake
 
 */
Status game_reader_load_objects(Game *game, char *filename);

#endif