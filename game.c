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

/**
 * @brief Returns the ID of the space at a given position in the game.
 * 
 * @param game, pointer to a `Game` structure, which represents the current state of the game being played
 * @param position. ndex of the space in the game's array of spaces for which we want to retrieve the ID.
 * 
 * @return the ID of the space at the specified position in the game. If the position is out of bounds, it returns NO_ID.
 */
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

  for (i = 0; i < MAX_OBJECTS; i++)
    {
      game->objects[i] = NULL;
    }

  for (i = 0; i < MAX_CHARACTERS; i++)
    {
      game->characters[i] = NULL;
    }

  
  /* Assigns default values ​​to the different fields of the structure */
  game->n_characters=0;
  game->n_objects = 0;
  game->n_spaces = 0; 
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

  if (game_reader_load_objects(game,filename) == ERROR){
    return ERROR;
  }

  game->characters[0]=character_create(1);
  if(game->characters[0] == NULL){
      return ERROR;
  }
  game->n_characters++;

  if(!character_set_hp(game->characters[0],3)){
    return ERROR;

  }

  if(!character_set_name((game->characters[0]), "/\\00/\\")){
    return ERROR;
  }

  if(!character_set_message((game->characters[0]), "Hi")){
    return ERROR;
  }

  if(!character_set_friendly((game->characters[0]), FALSE)){
    return ERROR;
  }
  
  space_set_character_id(game->spaces[0], 1);

  game->characters[1]=character_create(2);
  if(game->characters[1] == NULL){
      return ERROR;
  }
  game->n_characters++;

  if(!character_set_hp(game->characters[1],5)){
    return ERROR;

  }

  if(!character_set_name((game->characters[1]), "^0m")){
    return ERROR;
  }

  if(!character_set_message((game->characters[1]), "POOOO")){
    return ERROR;
  }

  if(!character_set_friendly((game->characters[1]), TRUE)){
    return ERROR;
  }

  space_set_character_id(game->spaces[1], 2);

  game->player = player_create(1);
  if( game->player == NULL){
      return ERROR;
  }

  if(!player_set_health(game->player,3)){
    return ERROR;
  }

  game->command = command_create();
  if(game->command == NULL){
    return ERROR;
  }

  /* The player and the object are located in the first space */
  game_set_player_location(game, game_get_space_id_at(game, 0));

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

Status game_destroy(Game *game) {
  int i = 0;

  /*Destroys the different spaces by freeing their allocated memory*/

  for (i = 0; i < game->n_spaces; i++) {
    space_destroy(game->spaces[i]);
  }

  for (i = 0; i < game->n_objects; i++) {
    object_destroy(game->objects[i]);
  }

  for (i = 0; i < game->n_characters; i++) {
    character_destroy(game->characters[i]);
  }

  player_destroy(game->player);

  command_destroy(game->command);


  return OK;
}

Id game_get_space_character_id(Space *space){

  if(!space){
    return NO_ID;
  }

  return space_get_character_id(space);

}

Character *game_get_character(Game *game, Id id){

  int i;
  if(!game){
    return NULL;
  }

  for(i=0;i<game->n_characters;i++){
    if(character_get_id(game->characters[i]) == game_get_space_character_id(game_get_space(game, id))){

      return game->characters[i];


    }
  }
  return NULL;
}

Id game_get_character_location(Game *game, Character *character){

  Id character_id=NO_ID;
  int i;


  if(!game){
    return NO_ID;
  }

  character_id=character_get_id(character);

  for(i=0;i<game->n_spaces;i++){
    if(character_id == game_get_space_character_id(game->spaces[i])){

      return space_get_id(game->spaces[i]);

    }
  }

  return NO_ID;

}

Space *game_get_space(Game *game, Id id){
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

Object **game_get_objects(Game *game){
    if (!game){
        return NULL;
    }
    return game->objects;
}


int game_get_num_objects(Game *game){

  int i;

  if(!game){
    return -1;
  }

  for(i=0; i< MAX_OBJECTS && game->objects[i]!=NULL; i++);

  return i;

}


Id game_get_player_location(Game *game) { return player_get_location(game->player);}

Status game_set_player_location(Game *game, Id id) {
  if (id == NO_ID) {
    return ERROR;
  }

  player_set_location(game->player, id);

  return OK;
}

Player *game_get_player(Game *game){

  if(!game){
    return NULL;
  }

  return game->player;
}

Status game_add_object(Game *game, Object *object){

  if ((object == NULL) || (game == NULL)) {
    return ERROR;
  }

  game->objects[game->n_objects] = object;
  game->n_objects++;
  
  return OK;

}


Id game_get_object_location(Game *game, Object *object){ 

  int i = 0;

  Id object_id=object_get_id(object);

  

  for (i = 0; i < game->n_spaces; i++) {
    if (space_object_position_in_space((game->spaces[i]), object_id) >=0 ){

      /*When it finds that there is an object id returns the ID of the space */

      return space_get_id(game->spaces[i]);
    }

  }
  return NO_ID;
 }


Set *game_get_objects_in_space(Game *game, Id id){

  Space *space = NULL;

  if(!game || id == NO_ID){
    return NULL;
  }

  space = game_get_space(game, id);

  if(!space){
    return NULL;
  }
  
  return space_get_set_of_objects(space);


}

Id game_set_get_id(Game *game,Set *set, int i){

  if(!game || !set){
    return NO_ID;
  }

    return set_get_id(set,i);
}

Status game_set_object_location(Game* game, Object* object, Id id) {
 
  if (id == NO_ID || !object) {
    return ERROR;
  }

  /* It is setting the object location in the game structure to the
  given id */
  space_add_object(game_get_space(game, id), object_get_id(object));
  
  return OK;
}


Cmd game_get_command_cmd(Game *game){

  if(!game){
    return NO_CMD;
  }

  return command_get_cmd(game->command);

}

Command *game_get_command(Game *game){

  if(!game){
    return NULL;
  }

  return game->command;

}

char *game_get_command_target(Game *game){

  if(!game){
    return NULL;
  }

  return command_get_target(game->command);

}
Cmd game_get_last_command(Game *game) {  return command_get_last_cmd(game->command); }

/*Command game_get_last_command_status(Game *game) {return game->last_cmd_status;}*/


Status game_set_last_command(Game *game, Cmd cmd) {
  return command_set_last_cmd(game->command,cmd);
}

Status game_get_last_command_status(Game *game){ return command_get_last_cmd_status(game->command);}

Status game_set_last_command_status(Game *game, Status status) {

  return command_set_last_cmd_status(game->command,status);
}

Status game_command_clean_target(Game *game){

  if(!game){
    return ERROR;
  }

  return  command_clean_target(game->command);;
}

Bool game_get_finished(Game *game) { return game->finished; }

Status game_set_finished(Game *game, Bool finished) {
  game->finished = finished;

  return OK;
}

int game_get_set_nids(Game *game,Set* set){

   if(!game || !set){
    return 0;
  }

 return set_get_nids(set);

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

  /*It prints the information and the location of the game's object and the player.*/

  if (player_print(game->player) == ERROR){
    return;
  }

  for(i=0; i<game->n_objects; i++){

    if((object_print(game->objects[i]) == ERROR)){
      return;
    }

  }

  for(i=0; i<game->n_objects; i++){

    if((character_print(game->characters[i]) == ERROR)){
      return;
    }

  }

}
