/**
 * @brief It defines the set interface
 *
 * @file set.h
 * @author Diego Tabero & Marcos Leo Sonck
 * @version 3.5
 * @date 20-02-2024
 * @copyright GNU Public License
 */

#ifndef SET_H
#define SET_H


#include "set.h"
#include "types.h"

#define MAX_ID 12

typedef struct _Set Set;

/**
 * @brief It creates a new set, allocating memory and initializing its members
 * @author Diego Tabero & Marcos Leo Sonck
 *
 * @return a new set, initialized
 */
Set *set_create();

/**
 * @brief It destroys a set, freeing the allocated memory
 * @author Diego Tabero & Marcos Leo Sonck
 *
 * @param, set a pointer to the set that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status set_destroy(Set *set);

/**
 * @brief Retrieve the ID at a specific index within the set.
 * @author Diego Tabero & Marcos Leo Sonck
 *
 * @param, set a pointer to the space that must be destroyed
 * @param, i, index od the array
 * @return the ID at the specified index `i` within the set.
 */
Id set_get_id(Set *set, int i);

/**
 * @brief Retrieve the number of IDS at a specific index within the set.
 * @author Diego Tabero & Marcos Leo Sonck
 *
 * @param, set a pointer to the set
 * @return the ID at the specified index `i` within the set.
 */

int set_get_nids(Set *set);

/**
 * @brief Retrieve the array of ids saved in the set
 * @author Diego Tabero & Marcos Leo Sonck
 *
 * @param, set a pointer to the set
 * @return the ID at the specified index `i` within the set.
 */

Id * set_get_ids(Set *set);

/**
 * @brief Adds an ID if it isn´t already in the Set
 * @author Diego Tabero & Marcos Leo Sonck
 *
 * @param set, pointer to a set structure containing a collection of IDs
 * @return the ID at the specified index `i` within the set.
 */

Status set_add_id(Set *set, Id id);

/**
 * @brief Removes a specific ID from a set data structure.
 * 
 * @param set, pointer to a set structure containing a collection of IDs
 * @param id Represents the identifier of an element that you want to remove from the set. 
 * 
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status set_del_id(Set *set, Id id);

/**
 * @brief Checks if a given ID belongs to a set and returns its index if found.
 * 
 * @param set, pointer to a set structure containing a collection of IDs
 * @param id, that we are checking for in the set. 
 * 
 * @return, index of the element in the set's array of IDs that matches the given ID. If not found returns -1
 */

int set_id_belongs(Set *set, Id id);



/**
 * @brief Checks if a given Set is empty.
 * 
 * @param set, pointer to a set structure containing a collection of IDs.
 * 
 * @return, TRUE or FALSE whether the set is empty or not.
 */
Bool set_is_empty(Set *set);

/**
 * @brief Checks if a given Set is empty.
 * 
 * @param set, pointer to a set structure containing a collection of IDs.
 * 
 * @return, TRUE or FALSE whether the set is full or not.
 */

Bool set_is_full(Set *set);
/**
 * @brief It prints the set information
 * @author Diego Tabero & Marcos Leo Sonck
 
 * @param, set a pointer to the  set
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status set_print(Set *set);


#endif








