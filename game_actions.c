/**
 * @brief It implements the game update through user actions
 *
 * @file game.c
 * @author Profesores PPROG, Diego Tabero, Marcos Leo Sonck
 * @version 3.5
 * @date 11-02-2024
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "game_actions.h"

/**
   Private functions
*/

void game_actions_unknown(Game *game);

void game_actions_exit(Game *game);

void game_actions_next(Game *game);

void game_actions_back(Game *game);

void game_actions_left(Game *game);

void game_actions_right(Game *game);

void game_actions_take(Game *game);

void game_actions_drop(Game *game);

void game_actions_attack(Game *game);

void game_actions_chat(Game *game);

/**
   Game actions implementation
*/

Status game_actions_update(Game *game) {

  Cmd cmd = game_get_command_cmd(game);

  game_set_last_command(game, cmd);
  

  switch (cmd) {
    case UNKNOWN:
      game_actions_unknown(game);
      break;

    case EXIT:
      game_actions_exit(game);
      break;

    case NEXT:
      game_actions_next(game);
      break;

    case BACK:
      game_actions_back(game);
      break;

    case LEFT:
      game_actions_left(game);
      break;

    case RIGHT:
      game_actions_right(game);

    case TAKE:
      game_actions_take(game);
      break;

    case DROP:
      game_actions_drop(game);
      break;

    case ATTACK:
      game_actions_attack(game);
      break;

    case CHAT:
      game_actions_chat(game);
      break;

    default:
      break;
  }

  return OK;
}


/**
   Calls implementation for each action
*/

/**
 * @brief Handles unknown commands in the game
 *
 *
 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 **/

void game_actions_unknown(Game *game) {}
/**
 * @brief Handles the exit command in the game
 *
 *
 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 **/
void game_actions_exit(Game *game) {}
/**
 * @brief Handles the next command in the game
 *
 * This function updates the player's location to the next space to the south if possible.
 *
 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 **/

void game_actions_next(Game *game) {
  Id current_id = NO_ID; /*Initializes an id to NO_ID*/
  Id space_id = NO_ID; /*Initializes space id to NO_ID*/
  game_set_last_command_status(game, ERROR);

  if(!game){
    return;
  }

  space_id = game_get_player_location(game); /*Sets space_id to the id of the location of the player*/
  if (space_id == NO_ID) {
    return;
  }

  current_id = space_get_south(game_get_space(game, space_id)); /*Sets current_id to the id of the space south to the current space of the player */
  if (current_id != NO_ID) {
    game_set_player_location(game, current_id); /*Updates player´s location to the previous space*/
    game_set_last_command_status(game, OK);
  }



  return;
}

/**
 * @brief Handles the back command in the game
 * 
 * This function updates the player's location to the next space to the north if possible
 * 
 * @param game A pointer to the Game struct, which contains information about the current state of the
 * game.

 */
  void game_actions_back(Game *game) {
    Id current_id = NO_ID;
    Id space_id = NO_ID; 
    game_set_last_command_status(game, ERROR);

    if(!game){
      return;
    }

    space_id = game_get_player_location(game); /*Sets space_id to the id of the location of the player*/

    if (NO_ID == space_id) {
      return;
    }

    current_id = space_get_north(game_get_space(game, space_id)); /*Sets current_id to the id of the space north to the current space of the player */
    if (current_id != NO_ID) {
      game_set_player_location(game, current_id); /*Updates player´s location to the previous space*/
      game_set_last_command_status(game, OK);
    }


    return;
  }

  /**
 * @brief Handles the left command in the game
 * 
 * This function updates the player's location to the next space to the west if possible
 * 
 * @param game A pointer to the Game struct, which contains information about the current state of the
 * game.

 */

  void game_actions_left(Game *game) {
    Id current_id = NO_ID;
    Id space_id = NO_ID; 
    game_set_last_command_status(game, ERROR);

    if(!game){
      return;
    }

    space_id = game_get_player_location(game); /*Sets space_id to the id of the location of the player*/

    if (NO_ID == space_id) {
      return;
    }

    current_id = space_get_west(game_get_space(game, space_id)); /*Sets current_id to the id of the space west to the current space of the player*/
    if (current_id != NO_ID) {
      game_set_player_location(game, current_id); /*Updates player´s location to the previous space*/
      game_set_last_command_status(game, OK);
    }

    return;

  }

   /**
 * @brief Handles the left command in the game
 * 
 * This function updates the player's location to the next space to the west if possible
 * 
 * @param game A pointer to the Game struct, which contains information about the current state of the
 * game.

 */

  void game_actions_right(Game *game) {
    Id current_id = NO_ID;
    Id space_id = NO_ID; 
    game_set_last_command_status(game, ERROR);

    if(!game){
      return;
    }

    space_id = game_get_player_location(game); /*Sets space_id to the id of the location of the player*/

    if (NO_ID == space_id) {
      return;
    }

    current_id = space_get_east(game_get_space(game, space_id)); /*Sets current_id to the id of the space west to the current space of the player*/
    if (current_id != NO_ID) {
      game_set_player_location(game, current_id); /*Updates player´s location to the previous space*/
      game_set_last_command_status(game, OK);
    }


    return;
  }


/**
 * @brief Allows the player to take an object from their current location in the game.
 * 
 * @param game, pointer to a `Game` structure, which represents the current state of the game being played

 */
void game_actions_take(Game *game){

  Set *objects = NULL;
  Id target = NO_ID;
  char targetstr[10]; 
  int nobjects, i; 
  Id player_location_id = NO_ID;
  Space * space = NULL;

  game_set_last_command_status(game, ERROR);

  if(!game){
    return;
  }

  player_location_id = game_get_player_location(game);

  if (NO_ID == player_location_id) {
    return;
  }

  space = game_get_space(game,player_location_id);

  if(!space){
    return;
  }

  /*MIRAAAAAAAAAAAAAAR**/

  objects = game_get_objects_in_space(game, player_location_id);

  if(!objects) {
    return;
  }

  nobjects = game_get_set_nids(game,objects);

  strcpy(targetstr,game_get_command_target(game)+1);
  
  target = atoi(targetstr);
  
  for(i=0;i<nobjects;i++){

    if(game_set_get_id(game,objects,i) == target){

      player_set_object(game->player, game_set_get_id(game,objects,i));

      /*Eliminates the object from the space*/

      space_del_object(space, game_set_get_id(game,objects,i));

    }

  }

  game_command_clean_target(game);

  game_set_last_command_status(game,OK);

  return;
}

/**
 * @brief Allows the player to drop an object they are currently holding in the game, placing it in the current space they are in.
 * 
 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 *
 */

void game_actions_drop(Game *game) {
  Id object_id = NO_ID;
  Id playerlocation_id = NO_ID;
  Space *space = NULL;
  Status status = ERROR;

  if(!game){
    return;
  }

  object_id = player_get_object(game_get_player(game));

  if(object_id == NO_ID) {
    game_set_last_command_status(game,status);
    return;
  }

  playerlocation_id = game_get_player_location(game);

  if(playerlocation_id == NO_ID) {
    game_set_last_command_status(game,status);
    return;
  }

  space = game_get_space(game, playerlocation_id);

  if(space == NULL) {
    game_set_last_command_status(game,status);
    return;
  }



  /*Function call that sets the object ID of the player to NO_ID, indicating that the player is not currently holding an object. */
  
  player_set_object(game->player, NO_ID);

   /*Sets the object ID of the current space to an ID, indicating that there is an object in that space because the player has dropped it.*/

  space_add_object(space,object_id);  

  status=OK;
  game_set_last_command_status(game,status);

  return;
}

void game_actions_attack(Game *game){
  Space *space = NULL;
  Character * npc = NULL;
  Player *player = NULL;
  Id character_location = NO_ID;
  int attack, php, chp;

  game_set_last_command_status(game, ERROR);

  player = game_get_player(game);

  if(!player){
    return;
  }

  space = game_get_space(game,game_get_player_location(game));

  if(!space){
    return;
  }

  character_location = space_get_id(space);

  npc = game_get_character(game,character_location);

  if(!npc){
    return;
  }

  if(character_get_friendly(npc)){
    return;
  }

  php = player_get_health(player);
  chp = character_get_hp(npc);

  if(chp > 0){

    attack = rand()%10;

    if(attack <= 4){
    player_set_health(player, (php-1));
    }else{
    character_set_hp(npc,(chp-1));
    }

    if(!php){
    game_set_finished(game,TRUE);
    }

  }

  
  game_set_last_command_status(game, OK);
  return;
}

void game_actions_chat(Game *game) {
  Id player_location_id = NO_ID; /*Initializes an id to NO_ID*/
  Id character_location_id = NO_ID; /*Initializes space id to NO_ID*/

  if(!game){
    return;
  }

  game_set_last_command_status(game, ERROR);

  player_location_id = game_get_player_location(game); /*Sets space_id to the id of the location of the player*/
  if (player_location_id == NO_ID) {
    return;
  }


  character_location_id = game_get_space_character_id(game_get_space(game, player_location_id)); 
  if (character_location_id == NO_ID) {
    return;
  }

  if(character_get_friendly(game_get_character(game, player_location_id))!=TRUE){
    return;
  }

  game_set_last_command_status(game, OK);
  return;
}

