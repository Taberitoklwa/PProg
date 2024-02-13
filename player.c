/**
 * @brief It implements the Player module
 *
 * @file Player.c
 * @author Diego Tabero & Marcos Leo Sonck
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
  Id id;/*!< Id number of the Player, it must be unique */
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

Status player_destroy(Player *player) {
  if (!player) {
    return ERROR;
  }

  free(player);
  player = NULL;
  return OK;
}

Id player_get_id(Player* player) {
  if (!player) {
    return NO_ID;
  }
  return player->id;
}

Status player_set_name(Player* player, char* name) {
  if (!player || !name) {
    return ERROR;
  }

  if (!strcpy(player->name, name)) {
    return ERROR;
  }
  return OK;
}

const char* player_get_name(Player *player) {
  if (!player) {
    return NULL;

  }
  return player->name;
}


Status player_set_location(Player *player, Id id) {
  if (!player || id == NO_ID) {
    return ERROR;
  }
  player->location = id;
  return OK;
}


Id player_get_location(Player *player) {
  if (!player) {
    return NO_ID;
  }

  return player->location;
}

Status player_set_object(Player *player, Id id) {
  if (!player) {
    return ERROR;
  }
  player->object = id;
  return OK;
}

Id player_get_object(Player *player) {
  if (!player) {
    return NO_ID;
  }
  return player->object;
}

Status player_print(Player* player) {
  Id idaux = NO_ID;

  /* Error Control */
  if (!player) {
    return ERROR;
  }

  /* 1. Print the id and the name of the Player */
  fprintf(stdout, "--> Player (Id: %ld; Name: %s)\n", player->id, player->name);

  /* 2. For each direction, print its link */
  idaux = player_get_location(player);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> Location: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No location.\n");
  }
  /* 3. Print if the player has an object and if so, its Id */
  if (player_get_object(player)!=NO_ID) {
    fprintf(stdout, "---> Object id: %ld the Player.\n",player->object);
  } else {
    fprintf(stdout, "---> Player has no object.\n");
  }

  return OK;
}