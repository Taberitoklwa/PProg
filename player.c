/**
 * @brief It implements the Player module
 *
 * @file Player.c
 * @author Profesores PPROG
 * @version 3.5
 * @date 26-01-2024
 * @copyright GNU Public License
 */

#include "player.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Player
 *
 * This struct stores all the information of a Player.
 */
struct _Player {
  Id id;                    /*!< Id number of the Player, it must be unique */
  char name[WORD_SIZE + 1]; /*!< Name of the Player */                
  Id location; /*!<Id of the players location*/
  Id object;  /*!< Whether the Player has an object an if so, which one */
};

/** Player_create allocates memory for a new Player
 *  and initializes its members
 */
Player* player_create(Id id) {
  Player* newPlayer = NULL;

  /* Error control */
  if (id == NO_ID) return NULL;

  newPlayer = (Player*)malloc(sizeof(Player));
  if (newPlayer == NULL) {
    return NULL;
  }

  /* Initialization of an empty Player*/
  newPlayer->id = id;
  newPlayer->name[0] = '\0';
  newPlayer->location = NO_ID;
  newPlayer->object = NO_ID;

  return newPlayer;
}

Status Player_destroy(Player* Player) {
  if (!Player) {
    return ERROR;
  }

  free(Player);
  Player = NULL;
  return OK;
}

Id Player_get_id(Player* Player) {
  if (!Player) {
    return NO_ID;
  }
  return Player->id;
}

Status Player_set_name(Player* Player, char* name) {
  if (!Player || !name) {
    return ERROR;
  }

  if (!strcpy(Player->name, name)) {
    return ERROR;
  }
  return OK;
}

const char* Player_get_name(Player* Player) {
  if (!Player) {
    return NULL;
  }
  return Player->name;
}

Status Player_set_location(Player* Player, Id id) {
  if (!Player || id == NO_ID) {
    return ERROR;
  }
  Player->location = id;
  return OK;
}

Id Player_get_location(Player* Player) {
  if (!Player) {
    return NO_ID;
  }
  return Player->location;
}

Status Player_set_object(Player* Player, Id id) {
  if (!Player || id == NO_ID) {
    return ERROR;
  }
  Player->object = id;
  return OK;
}

Id Player_get_object(Player* Player) {
  if (!Player) {
    return NO_ID;
  }
  return Player->object;
}

Status Player_print(Player* Player) {
  Id idaux = NO_ID;

  /* Error Control */
  if (!Player) {
    return ERROR;
  }

  /* 1. Print the id and the name of the Player */
  fprintf(stdout, "--> Player (Id: %ld; Name: %s)\n", Player->id, Player->name);

  /* 2. For each direction, print its link */
  idaux = Player_get_location(Player);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> Location: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No location.\n");
  }
  /* 3. Print if the player has an object and if so, its Id */
  if (Player_get_object(Player)!=NO_ID) {
    fprintf(stdout, "---> Object id: %ld the Player.\n",Player->object);
  } else {
    fprintf(stdout, "---> Player has no object.\n");
  }

  return OK;
}
