/**
 * @brief It defines the object interface
 *
 * @file object.h
 * @author Recurso1
 * @version 3.5
 * @date 6-02-2024
 * @copyright GNU Public License
 */

#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"

typedef struct _Object Object;

/**
 * @brief It creates a new object, allocating memory and initializing its members
 * @author Profesores PPROG
 *
 * @param id the identification number for the new object
 * @return a new object, initialized
 */
Object* object_create(Id id);

/**
 * @brief It destroys a object, freeing the allocated memory
 * @author Profesores PPROG
 *
 * @param object a pointer to the object that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status object_destroy(Object* object);

/**
 * @brief It gets the id of a object
 * @author Profesores PPROG
 *
 * @param object a pointer to the object
 * @return the id of object
 */
Id object_get_id(Object* object);

/**
 * @brief It sets the name of a object
 * @author Profesores PPROG
 *
 * @param object a pointer to the object
 * @param name a string with the name to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status object_set_name(Object* object, char* name);

/**
 * @brief It gets the name of a object
 * @author Profesores PPROG
 *
 * @param object a pointer to the object
 * @return  a string with the name of the object
 */
const char* object_get_name(Object* object);

/**
 * @brief It sets the id of the object located at the north
 * @author Profesores PPROG
 *
 * @param object a pointer to the object
 * @param id the id number of the object located at the north
 * @return OK, if everything goes well or ERROR if there was some mistake
 */

Status object_set_north(Object* object, Id id);

/**
 * @brief It gets the id of the object located at the north
 * @author Profesores PPROG
 *
 * @param object a pointer to the object
 * @return the id number of the object located at the north
 */
Id object_get_north(Object* object);

/**
 * @brief It sets the id of the object located at the south
 * @author Profesores PPROG
 *
 * @param object a pointer to the object
 * @param id the id number of the object located at the south
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status object_set_south(Object* object, Id id);

/**
 * @brief It gets the id of the object located at the south
 * @author Profesores PPROG
 *
 * @param object a pointer to the object
 * @return the id number of the object located at the south
 */
Id object_get_south(Object* object);

/**
 * @brief It sets the id of the object located at the east
 * @author Profesores PPROG
 *
 * @param object a pointer to the object
 * @param id the id number of the object located at the east
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status object_set_east(Object* object, Id id);

/**
 * @brief It gets the id of the object located at the east
 * @author Profesores PPROG
 *
 * @param object a pointer to the object
 * @return the id number of the object located at the east
 */
Id object_get_east(Object* object);

/**
 * @brief It sets the id of the object located at the west
 * @author Profesores PPROG
 *
 * @param object a pointer to the object
 * @param id the id number of the object located at the west
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status object_set_west(Object* object, Id id);

/**
 * @brief It gets the id of the object located at the west
 * @author Profesores PPROG
 *
 * @param object a pointer to the object
 * @return the id number of the object located at the west
 */
Id object_get_west(Object* object);

/**
 * @brief It sets whether the object has an object or not
 * @author Profesores PPROG
 *
 * @param object a pointer to the object
 * @param value a boolean, specifying if in the object there is an object (TRUE) or not (FALSE)
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status object_set_object(Object* object, Bool value);

/**
 * @brief It gets whether the object has an object or not
 * @author Profesores PPROG
 *
 * @param object a pointer to the object
 * @return a boolean, specifying if in the object there is an object (TRUE) or not (FALSE)
 */
Bool object_get_object(Object* object);

/**
 * @brief It prints the object information
 * @author Profesores PPROG
 *
 * This fucntion shows the id and name of the object, the objects that surrounds it and wheter it has an object or not.
 * @param object a pointer to the object
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status object_print(Object* object);

#endif








