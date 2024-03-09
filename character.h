/*
 * @brief It defines the Character interface
 *
 * @file Character.h
 * @author Diego Tabero & Marcos Leo Sonck
 * @version 3.5
 * @date 27-02-2024
 * @copyright GNU Public License
 */

#ifndef CHARACTER_H
#define CHARACTER_H

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
Status character_set_name(Character* Character, char* name);

/**
 * @brief It gets the name of a Character
 * @author Diego Tabero & Marcos Leo Sonck
 *
 * @param Character a pointer to the Character
 * @return  a string with the name of the Character
 */

const char* character_get_name(Character* Character);

/**
 * @brief Sets the HP (health points) of a character to a specified value.
 * @author Diego Tabero & Marcos Leo Sonck
 *
 * @param Character a pointer to the Character
 * @param hp represents the amount of health points, it is an integer value that should be greater than 0
 * 
 * @return OK, if everything goes well or ERROR if there was some mistake
 */

Status character_set_hp(Character *character, int hp);

/**
 * @brief Returns the health points of a character if it exists
 * @author Diego Tabero & Marcos Leo Sonck
 *
 * @param Character a pointer to the Character
 *
 * 
 * @return the health points of a character if it exists, if not returns ERROR
 */
int character_get_hp(Character *character);

/**
 * @brief Sets a message for a given character 
 * @author Diego Tabero & Marcos Leo Sonck
 * 
 * @param character a pointer to the character
 * @param message strings that contains the message to be set for the character.
 * 
 * @return OK, if everything goes well or ERROR if there was some mistake
 */

Status character_set_message(Character* character, char* message);

/**
 * @brief Returns the message associated with a given character
 * @author Diego Tabero & Marcos Leo Sonck
 * 
 * @param character a pointer to the character
 * @return the message stored in the Character struct and if the pointer is NULL, the function returns
 * NULL.
 */

const char* character_get_message(Character *character);


/**
 * @brief Sets the friendly attribute of a character to a specified
 * boolean value.
 * @author Diego Tabero & Marcos Leo Sonck
 * 
 * @param value value that indicates whether the character is friendly or not. It should be either true or
 * false
 * @param character a pointer to the character
 * @return OK, if everything goes well or ERROR if there was some mistake
 */

Status character_set_friendly(Character *character, Bool value);

/**
 * @brief Returns the friendly status of a character
 * 
 * @param character a pointer to the character
 * 
 * @return the value of the "friendly" attribute of the Character, if the pointer is NULL, the function will return false
 */
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
