/**
 * @brief It loads the game spots
 *
 * @file game_reader.c
 * @author Recurso 1
 * @version 3.5
 * @date 01-02-2024
 * @copyright GNU Public License
 */



#include "game_reader.h"
#include "game.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * @brief It loads the game spaces
 */


Status game_load_spaces(Game *game, char *filename) {
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID;/* Is declaring and initializing variables of type `Id` with the default value `NO_ID`.*/
  Space *space = NULL; /*It initializes the pointer to the space structure to null*/
  Status status = OK;


 /* Error Control */
  if (!filename) {
    return ERROR;
  }

  file = fopen(filename, "r");
  /* Error Control */
  if (file == NULL) {
    return ERROR;
  }

  /* Reading lines from a file and parsing them (strtok) to extract information about game
  spaces. */
  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#s:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      north = atol(toks);
      toks = strtok(NULL, "|");
      east = atol(toks);
      toks = strtok(NULL, "|");
      south = atol(toks);
      toks = strtok(NULL, "|");
      west = atol(toks);
#ifdef DEBUG
      printf("Leido: %ld|%s|%ld|%ld|%ld|%ld\n", id, name, north, east, south, west);
#endif
      space = space_create(id);
      if (space != NULL) {
        space_set_name(space, name);
        space_set_north(space, north);
        space_set_east(space, east);
        space_set_south(space, south);
        space_set_west(space, west);
        game_add_space(game, space);
      }
    }
  }
  /* Error Control */
  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);

  return status;


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

Id game_get_space_id_at(Game *game, int position) {
  /* Error Control */
  if (position < 0 || position >= game->n_spaces) {
    return NO_ID;
  }

  return space_get_id(game->spaces[position]);
}

