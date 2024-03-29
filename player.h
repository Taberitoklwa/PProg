/**
 * @brief It defines the Player interface
 *
 * @file Player.h
 * @author Diego Tabero & Marcos Leo Sonck
 * @version 3.5
 * @date 26-01-2024
 * @copyright GNU Public License
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"

typedef struct _Player Player;

/**
 * @brief It creates a new Player, allocating memory and initializing its members
 * @author Diego Tabero & Marcos Leo Sonck
 *
 * @param id the identification number for the new Player
 * @return a new Player, initialized
 */
Player* player_create(Id id);

/**
 * @brief It destroys a Player, freeing the allocated memory
 * @author Diego Tabero & Marcos Leo Sonck
 *
 * @param Player a pointer to the Player that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_destroy(Player* player);

/**
 * @brief It gets the id of a Player
 * @author Diego Tabero & Marcos Leo Sonck
 *
 * @param Player a pointer to the Player
 * @return the id of Player
 */
Id player_get_id(Player* player);

/**
 * @brief It sets the name of a Player
 * @author Diego Tabero & Marcos Leo Sonck
 *
 * @param Player a pointer to the Player
 * @param name a string with the name to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_set_name(Player* player, char* name);

/**
 * @brief It gets the name of a Player
 * @author Diego Tabero & Marcos Leo Sonck
 *
 * @param Player a pointer to the Player
 * @return  a string with the name of the Player
 */

const char* player_get_name(Player* player);

/**
 * @brief Sets the location of a player to a given ID.
 * @author Diego Tabero & Marcos Leo Sonck
 * 
 * @param player, pointer to a Player struct.
 * @param id, the location where the player is being set.
 * 
 * @return OK, if everything goes well or ERROR if there was some mistake
 */

Status player_set_location(Player *player, Id id);

/**
 * @brief Returns the location of a player.
 *  @author Diego Tabero & Marcos Leo Sonck
 * 
 * @param player, pointer to a Player struct.
 * 
 * @return, location of the player.
 */
Id player_get_location(Player *player);

/**
 * @brief It sets the id of the object which the player is currently holding
 * @author Diego Tabero & Marcos Leo Sonck
 *
 * @param Player, pointer to the Player
 * @param id, specifying the id of the object
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_set_object(Player* player, Id id);

/**
 * @brief It gets whether the Player has an object, if so, returns its Id
 * @author Diego Tabero & Marcos Leo Sonck
 *
 * @param Player, pointer to the Player
 * @return the Players object Id
 */
Id player_get_object(Player* player);

/**
 * @brief It gets whether the Player has an object, if so, returns its Id
 * @author Diego Tabero & Marcos Leo Sonck
 *
 * @param Player, pointer to the Player
 * @param hp the amount of health points that you want to set for the player. It is an integer value that should be greater than 0.
 * @return  OK, if everything goes well or ERROR if there was some mistake
 */

Status player_set_health(Player* player, int hp);

/**
 * @brief  Returns the health points of a player if the player exists.
 * @author Diego Tabero & Marcos Leo Sonck
 *
 * @param Player, pointer to the Player
 *
 * @return the health points (hp) of the player. If the player pointer is NULL, return ERROR
 */

int player_get_health(Player* player);

/**
 * @brief It prints the Player information
 * @author Diego Tabero & Marcos Leo Sonck
 *
 * @param Player, pointer to the Player
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status player_print(Player* player);

#endif