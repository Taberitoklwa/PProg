/**
 * @brief It implements the Character module
 *
 * @file Character.c
 * @author Diego Tabero & Marcos Leo Sonck
 * @version 3.5
 * @date 20-02-2024
 * @copyright GNU Public License
 */

#include "character.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Character
 *
 * This struct stores all the information of a Character.
 */
struct _Character {
  Id id;/*!< Id number of the Character, it must be unique */
  char name[WORD_SIZE + 1]; /*!< Name of the Character */ 
  char description[WORD_SIZE + 1];
  char message[WORD_SIZE +1];              
  unsigned int hp; /*!<Health points of the Character*/
  Bool friendly;
};

/** Character_create allocates memory for a new Character
 *  and initializes its members
 */
Character* character_create(Id id) {
  Character* newCharacter = NULL;

  /* Error control */
  if (id == NO_ID) return NULL;

  newCharacter = (Character*)malloc(sizeof(Character));
  if (newCharacter == NULL) {
    return NULL;
  }

  /* Initialization of an empty Character*/
  newCharacter->id = id;
  newCharacter->name[0] = '\0';
  newCharacter->message[0] = '\0';
  newCharacter->friendly = TRUE;

  return newCharacter;
}

Status character_destroy(Character *character) {
  if (!character) {
    return ERROR;
  }

  free(character);
  character = NULL;
  return OK;
}

Id character_get_id(Character* character) {
  if (!character) {
    return NO_ID;
  }
  return character->id;
}

Status character_set_name(Character* character, char* name) {
  if (!character || !name) {
    return ERROR;
  }

  if (!strcpy(character->name, name)) {
    return ERROR;
  }
  return OK;
}

const char* character_get_name(Character *character) {
  if (!character) {
    return NULL;

  }
  return character->name;
}

Status character_set_description(Character* character, char* description) {
  if (!character || !description) {
    return ERROR;
  }

  if (!strcpy(character->description, description)) {
    return ERROR;
  }
  return OK;
}

const char* character_get_description(Character *character) {
  if (!character) {
    return NULL;

  }
  return character->description;
}

Status character_set_message(Character* character, char* message) {
  if (!character || !message) {
    return ERROR;
  }

  if (!strcpy(character->message, message)) {
    return ERROR;
  }
  return OK;
}

const char* character_get_message(Character *character) {
  if (!character) {
    return NULL;

  }
  return character->message;
}



Status character_set_hp(Character *character, int hp){

if (!character || hp<0){
    return ERROR;

}

character->hp=hp;

return OK;
}

int character_get_hp(Character *character){

if (!character){
    return ERROR;

}

return character->hp;
}

Status character_set_friendly(Character *character, Bool value){

if (!character || (value!=FALSE && value!=TRUE)){
    return ERROR;

}

character->friendly=value;

return OK;
}

Bool character_get_friendly(Character *character){

if (!character){
    return ERROR;

}

return character->friendly;
}



Status character_print(Character* character) {

  /* Error Control */
  if (!character) {
    return ERROR;
  }

  /* 1. Print the id and the name of the Character */
  fprintf(stdout, "--> Character (Id: %ld; Name: %s; Hp %d; Message %s)\n", character->id, character->name, character->hp, character->message);

  /* 3. Print if the Character has an object and if so, its Id */

  return OK;
}