/**
 * @brief It defines the object interface
 *
 * @file object.h
 * @author Diego Tabero & Marcos Leo Sonck
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
 * @author Diego Tabero & Marcos Leo Sonck
 *
 * @param id the identification number for the new object
 * @return a new object, initialized
 */
Object* object_create(Id id);

/**
 * @brief It destroys a object, freeing the allocated memory
 * @author Diego Tabero & Marcos Leo Sonck
 *
 * @param object a pointer to the object that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status object_destroy(Object* object);

/**
 * @brief It gets the id of a object
 * @author Diego Tabero & Marcos Leo Sonck
 *
 * @param object a pointer to the object
 * @return the id of object
 */
Id object_get_id(Object* object);

/**
 * @brief It sets the name of a object
 * @author Diego Tabero & Marcos Leo Sonck
 *
 * @param object a pointer to the object
 * @param name a string with the name to store
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status object_set_name(Object* object, char* name);

/**
 * @brief It gets the name of a object
 * @author Diego Tabero & Marcos Leo Sonck
 *
 * @param object a pointer to the object
 * @return  a string with the name of the object
 */
const char* object_get_name(Object* object);

/**
 * @brief It sets whether the object has an object or not
 * @author Diego Tabero & Marcos Leo Sonck
 *
 * @param object a pointer to the object
 * @param value a boolean, specifying if in the object there is an object (TRUE) or not (FALSE)
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status object_set_portable(Object* object, Bool value);

/**
 * @brief It prints the object information
 * @author Diego Tabero & Marcos Leo Sonck
 *
 * This fucntion shows the id and name of the object, the objects that surrounds it and wheter it has an object or not.
 * @param object a pointer to the object
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status object_print(Object* object);

#endif








