/**
 * @brief It defines the space interface
 *
 * @file space.h
 * @author Profesores PPROG
 * @version 3.5
 * @date 26-01-2024
 * @copyright GNU Public License
 */

#ifndef SPACE_H
#define SPACE_H

#include "types.h"
#include "set.h"

typedef struct _Space Space;

/**
 * @brief It creates a new space, allocating memory and initializing its members
 * @author Profesores PPROG
 *
 * @param id the identification number for the new space
 * @return a new space, initialized
 */
Space *space_create(Id id);

/**
 * @brief It destroys a space, freeing the allocated memory
 * @author Profesores PPROG
 *
 * @param space a pointer to the space that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_destroy(Space *space);

/**
 * @brief It gets the id of a space
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @return the id of space
 */
Id space_get_id(Space *space);

/**
 * @brief It sets the name of a space
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @param name a string with the name to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_set_name(Space *space, char *name);

/**
 * @brief It gets the name of a space
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @return  a string with the name of the space
 */
const char *space_get_name(Space *space);

/**
 * @brief It sets the id of the space located at the north
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @param id the id number of the space located at the north
 * @return OK, if everything goes well or ERROR if there was some mistake
 */

Status space_set_north(Space *space, Id id);

/**
 * @brief It gets the id of the space located at the north
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @return the id number of the space located at the north
 */
Id space_get_north(Space *space);

/**
 * @brief It sets the id of the space located at the south
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @param id the id number of the space located at the south
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_set_south(Space *space, Id id);

/**
 * @brief It gets the id of the space located at the south
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @return the id number of the space located at the south
 */
Id space_get_south(Space *space);

/**
 * @brief It sets the id of the space located at the east
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @param id the id number of the space located at the east
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_set_east(Space *space, Id id);

/**
 * @brief It gets the id of the space located at the east
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @return the id number of the space located at the east
 */
Id space_get_east(Space *space);

/**
 * @brief It sets the id of the space located at the west
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @param id the id number of the space located at the west
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_set_west(Space *space, Id id);

/**
 * @brief It gets the id of the space located at the west
 * @author Profesores PPROG
 *
 * @param space a pointer to the space
 * @return the id number of the space located at the west
 */
Id space_get_west(Space *space);

/**
 * @brief Sets the character ID of a given space.
 * @author Diego Tabero & Marcos Leo
 *
 * @param space a pointer to the space
 * @param Id that we want to assign
 * @return OK, if everything goes well or ERROR if there was some mistake
 */

Status space_set_character_id(Space *space, Id id);

/**
 * @brief Returns the ID of the character in a given space, or `NO_ID`
 * if the space is NULL.
 * @author Diego Tabero & Marcos Leo
 *
 * @param space a pointer to the space
 * @return OK, if everything goes well or ERROR if there was some mistake
 */

Id space_get_character_id(Space *space);

/**
 * @brief adds an object to a set of IDs.
 * @author Diego Tabero & Marcos Leo
 *
 * @param space a pointer to the space
 * @param Id that we want to add to the set
 * @return OK, if everything goes well or ERROR if there was some mistake
 */

Status space_add_object(Space *space, Id id);

/**
 * @brief Removes an object with a specific ID from a space.
 * @author Diego Tabero & Marcos Leo
 *
 * @param space a pointer to the space
 * @param Id that we want to remove
 * @return OK, if everything goes well or ERROR if there was some mistake
 */

Status space_del_object(Space *space, Id id);

/**
 * @brief This function returns the number of objects in a given space.
 * @author Diego Tabero & Marcos Leo
 *
 * @param space a pointer to the space
 * @return number of objects in the space
 */

int space_get_n_objects(Space *space);

/**
 * @brief Checks if a given object ID belongs to a space and
 * returns its position.
 * @author Diego Tabero & Marcos Leo
 *
 * @param space a pointer to the space
 * @param Id of the space object whose position in space you want
 * to find.
 * @return index position of the object in the set
 */

int space_object_position_in_space(Space *space, Id id);

Set *space_get_set_object(Space* space);

Set *space_get_set_of_objects(Space* space);

/**
 * @brief It prints the space information
 * @author Profesores PPROG
 *
 * This fucntion shows the id and name of the space, the spaces that surrounds it and wheter it has an object or not.
 * @param space a pointer to the space
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status space_print(Space *space);

#endif
