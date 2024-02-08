/**
 * @brief It defines the Player interface
 *
 * @file Player.h
 * @author Profesores PPROG
 * @version 3.5
 * @date 26-01-2024
 * @copyright GNU Public License
 */

#ifndef Player_H
#define Player_H

#include "types.h"

typedef struct _Player Player;

/**
 * @brief It creates a new Player, allocating memory and initializing its members
 * @author Profesores PPROG
 *
 * @param id the identification number for the new Player
 * @return a new Player, initialized
 */
Player* player_create(Id id);

/**
 * @brief It destroys a Player, freeing the allocated memory
 * @author Profesores PPROG
 *
 * @param Player a pointer to the Player that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status Player_destroy(Player* Player);

/**
 * @brief It gets the id of a Player
 * @author Profesores PPROG
 *
 * @param Player a pointer to the Player
 * @return the id of Player
 */
Id Player_get_id(Player* Player);

/**
 * @brief It sets the name of a Player
 * @author Profesores PPROG
 *
 * @param Player a pointer to the Player
 * @param name a string with the name to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status Player_set_name(Player* Player, char* name);

/**
 * @brief It gets the name of a Player
 * @author Profesores PPROG
 *
 * @param Player a pointer to the Player
 * @return  a string with the name of the Player
 */
const char* Player_get_name(Player* Player);

/**
 * @brief It sets whether the object the player has
 * @author Profesores PPROG
 *
 * @param Player a pointer to the Player
 * @param id, specifying the id of the object
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status Player_set_object(Player* Player, Id id);

/**
 * @brief It gets whether the Player has an object, if so, returns its Id
 * @author Profesores PPROG
 *
 * @param Player a pointer to the Player
 * @return the Players object Id
 */
Id Player_get_object(Player* Player);

/**
 * @brief It prints the Player information
 * @author Profesores PPROG
 *
 * This fucntion shows the id and name of the Player, the Players location id and the Players object id.
 * @param Player a pointer to the Player
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status Player_print(Player* Player);

#endif
