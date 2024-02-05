/**
 * @brief It defines the game loop
 *
 * @file game_loop.c
 * @author Profesores PPROG
 * @version 3.5
 * @date 26-01-2024
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>

#include "command.h"
#include "game.h"
#include "game_actions.h"
#include "graphic_engine.h"
/**
 * @brief Initializes the game loop
 *
 * This function initializes the game and graphic engine for the game loop.
 *
 * @param game Pointer to the game object
 * @param gengine Double pointer to the graphic engine object
 * @param file_name The name of the file containing game data
 * @return 0 if initialization is successful, 1 otherwise
 **/
int game_loop_init(Game *game, Graphic_engine **gengine, char *file_name);
/**
 * @brief Runs the game loop
 *
 * This function runs the main game loop, which continuously paints the game on the screen,
 * gets user input, and updates the game state accordingly until the game finishes or the user exits.
 *
 * @param game The game object
 * @param gengine Pointer to the graphic engine object
 **/
void game_loop_run(Game game, Graphic_engine *gengine);
/**
 * @brief Cleans up resources after the game loop
 *
 * This function cleans up memory and resources used by the game and graphic engine after the game loop ends.
 *
 * @param game The game object
 * @param gengine Pointer to the graphic engine object
 **/
void game_loop_cleanup(Game game, Graphic_engine *gengine);


int main(int argc, char *argv[]) {
  Game game; /*Decalres a game object*/
  Graphic_engine *gengine; /*Declares a pointer to a graphic engine object*/

  if (argc < 2) { /*Checks if the correct number of command line arguments are provided */
    fprintf(stderr, "Use: %s <game_data_file>\n", argv[0]); /*Prints error message*/
    return 1;
  }

  if (!game_loop_init(&game, &gengine, argv[1])) { /*Calls function to initialize game loop*/
    game_loop_run(game, gengine); /*Runs game loop*/
    game_loop_cleanup(game, gengine); /*Cleans up resources after the game loop*/
  }

  return 0;
}

int game_loop_init(Game *game, Graphic_engine **gengine, char *file_name) {
  if (game_create_from_file(game, file_name) == ERROR) { /*Creates game object from file*/
    fprintf(stderr, "Error while initializing game.\n"); /*Prints error message*/
    return 1;
  }

  if ((*gengine = graphic_engine_create()) == NULL) { /*Creates graphic engine object*/
    fprintf(stderr, "Error while initializing graphic engine.\n"); /*Prints error message*/
    game_destroy(game); /*Destroys game object*/
    return 1;
  }

  return 0;
}

void game_loop_run(Game game, Graphic_engine *gengine) {
  Command command = NO_CMD; /*Declares a commandvariable initialized to NO_CMD*/

  while ((command != EXIT) && (game_get_finished(&game) == FALSE)) { /*Loop until exit command is received or game is finished */
    graphic_engine_paint_game(gengine, &game); /*Paints the game on the screen using graphic engine*/
    command = command_get_user_input(); /*Gets user input command*/
    game_actions_update(&game, command); /*Updates game state based on user command*/
  }
}

void game_loop_cleanup(Game game, Graphic_engine *gengine) { 
  game_destroy(&game); /*Destroys game object*/
  graphic_engine_destroy(gengine); /*Destroys graphic engine object*/
}
