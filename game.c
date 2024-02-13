/**
 * @brief It implements the game interface and all the associated calls
 * for each command
 *
 * @file game.c
 * @author Profesores PPROG
 * @version 3.5
 * @date 26-01-2024
 * @copyright GNU Public License
 */

#include "game.h"
#include "game_reader.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** <Private functions>*/

Id game_get_space_id_at(Game *game, int position) {
  /* Error Control */
  if (position < 0 || position >= game->n_spaces) {
    return NO_ID;
  }

  return space_get_id(game->spaces[position]);
}

/**
   Game interface implementation
*/

Status game_create(Game *game) {
  int i;

  /*  Initializing all the elements of the space pointers array to `NULL` */
  for (i = 0; i < MAX_SPACES; i++) {
    game->spaces[i] = NULL; 
  }

  /* Assigns default values ​​to the different fields of the structure */

  game->n_spaces = 0;
  game->object=object_create(1);
  game->player=player_create(1);
  game->last_cmd = NO_CMD;  
  game->finished = FALSE;

  return OK;
}

Status game_create_from_file(Game *game, char *filename) {

  /*Error Control*/
  if (game_create(game) == ERROR) {
    return ERROR;
  }

  /*Error Control*/
  if (game_reader_load_spaces(game, filename) == ERROR) {
    return ERROR;
  }

  /* The player and the object are located in the first space */
  game_set_player_location(game, game_get_space_id_at(game, 0));
  game_set_object_location(game, game_get_space_id_at(game, 0));

  return OK;
}

/*
 game_add_space increases the number of spaces
*/

Status game_add_space(Game *game, Space *space) {
  /* Error Control */
  if ((space == NULL) || (game->n_spaces >= MAX_SPACES)) {
    return ERROR;
  }

  game->spaces[game->n_spaces] = space;
  game->n_spaces++;

  return OK;
}

/*
 game_get_space_id_at Returns the id of the space you are currently on
 
*/


Status game_destroy(Game *game) {
  int i = 0;

  /*Destroys the different spaces by freeing their allocated memory*/

  for (i = 0; i < game->n_spaces; i++) {
    space_destroy(game->spaces[i]);
  }

  player_destroy(game->player);
  object_destroy(game->object);


  return OK;
}

Space *game_get_space(Game *game, Id id) {
  int i = 0;

  if (id == NO_ID) {
    return NULL;
  }

  for (i = 0; i < game->n_spaces; i++) {
    if (id == space_get_id(game->spaces[i])) {

      /*When it finds that the space id matches one of the defined spaces it returns a pointer to the space structure*/

      return game->spaces[i];
    }
  }

  return NULL;
}


Id game_get_player_location(Game *game) { return player_get_location(game->player);}

Status game_set_player_location(Game *game, Id id) {
  if (id == NO_ID) {
    return ERROR;
  }

  player_set_location(game->player, id);

  return OK;
}


Id game_get_object_location(Game *game){ 

  int i = 0;

  for (i = 0; i < game->n_spaces; i++) {
    if (space_get_object(game->spaces[i]) != NO_ID ){

      /*When it finds that there is an object id returns the ID of the space */

      return space_get_id(game->spaces[i]);
    }
  }
  
  return NO_ID;
  
 }


Status game_set_object_location(Game* game, Id id) {
 
  if (id == NO_ID) {
    return ERROR;
  }

  /*Mirar*/


  /* It is setting the object location in the game structure to the
  given id */
  space_set_object(game_get_space(game, id), object_get_id(game->object));
  
  return OK;
}


Command game_get_last_command(Game *game) { return game->last_cmd; }

Status game_set_last_command(Game *game, Command command) {
  
  /* It is setting the last command in the game structure to the
  introduced command */
  game->last_cmd = command;

  return OK;
}

Bool game_get_finished(Game *game) { return game->finished; }

Status game_set_finished(Game *game, Bool finished) {
  game->finished = finished;

  return OK;
}

void game_print(Game *game) {
  int i = 0;

  /*Header(Separator line)*/

  printf("\n\n-------------\n\n");

  /*It iterates through each space in the game, printing information about each space.*/

  printf("=> Spaces: \n");
  for (i = 0; i < game->n_spaces; i++) {
    space_print(game->spaces[i]);
  }

  /*It prints the location of the game's object and the player.*/

  if (player_print(game->player) == ERROR){
    return;
  }

  if (object_print(game->object) == ERROR){
    return;
  }

  printf("=> Object location: %d\n", (int)game_get_object_location(game));
}
