/*
 * @brief It defines the Character interface
 *
 * @file Character.h
 * @author Diego Tabero & Marcos Leo Sonck
 * @version 3.5
 * @date 26-01-2024
 * @copyright GNU Public License
 */

#ifndef Character_H
#define Character_H

#include "types.h"

typedef struct _Character Character;

/**
 * @brief It creates a new Character, allocating memory and initializing its members
 * @author Diego Tabero & Marcos Leo Sonck
 *
 * @param id the identification number for the new Character
 * @return a new Character, initialized
 */
Character* character_create(Id id);

/**
 * @brief It destroys a character, freeing the allocated memory
 * @author Diego Tabero & Marcos Leo Sonck
 *
 * @param character a pointer to the Character that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status character_destroy(Character* character);

/**
 * @brief It gets the id of a Character
 * @author Diego Tabero & Marcos Leo Sonck
 *
 * @param Character a pointer to the Character
 * @return the id of Character
 */
Id character_get_id(Character* character);

/**
 * @brief It sets the name of a Character
 * @author Diego Tabero & Marcos Leo Sonck
 *
 * @param Character a pointer to the Character
 * @param name a string with the name to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status Character_set_name(Character* Character, char* name);

/**
 * @brief It gets the name of a Character
 * @author Diego Tabero & Marcos Leo Sonck
 *
 * @param Character a pointer to the Character
 * @return  a string with the name of the Character
 */

const char* Character_get_name(Character* Character);

Status character_set_hp(Character *character, int hp);


int character_get_hp(Character *character);

Status character_set_message(Character* character, char* message);

const char* character_get_message(Character *character);

Status character_set_friendly(Character *character, Bool value);

Bool character_get_friendly(Character *character);



/**
 * @brief It prints the Character information
 * @author Diego Tabero & Marcos Leo Sonck
 *
 * @param Character, pointer to the Character
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status character_print(Character* Character);

#endif
