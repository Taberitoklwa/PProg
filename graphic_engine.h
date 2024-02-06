/**
 * @brief It defines the textual graphic engine interface
 *
 * @file graphic_engine.h
 * @author Profesores PPROG
 * @version 3.5
 * @date 26-01-2024
 * @copyright GNU Public License
 */

#ifndef GRAPHIC_ENGINE_H
#define GRAPHIC_ENGINE_H

#include "game.h"

typedef struct _Graphic_engine Graphic_engine;


/**
 * @brief Creates a pointer to a `Graphic_engine` structure and reserve memory for this structure, initializing all its members by calling other functions.

 *
 * @return It returns a pointer to a `Graphic_engine` structure

 */

Graphic_engine *graphic_engine_create(); 

/**
 * @brief It destroys the graphic engine structure by calling other functions and free the memory allocated for this structure
 * 
 * @param ge, pointer to a Graphic_engine structure, which contains information about the graphical interface of the game.

 */

void graphic_engine_destroy(Graphic_engine *ge);

/**
 * @brief It is responsible for painting the game state on the screen.

 * @param ge, pointer to a Graphic_engine structure, which contains information about the graphical interface of the game
 * @param game, pointer to a `Game` struct, which represents the current state of the game being played

 */

void graphic_engine_paint_game(Graphic_engine *ge, Game *game);

#endif
