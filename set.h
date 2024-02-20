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
 * @param, set a pointer to the space that must be destroyed
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status set_destroy(Set *set);

Id set_get_id(Set *set, int i);

int set_get_nids(Set *set);

Status set_add_id(Set *set, Id id);

Status set_del_id(Set *set, Id id);

int set_id_belongs(Set *set, Id id);

Bool set_is_empty(Set *set);

Bool set_is_full(Set *set);
/**
 * @brief It prints the set information
 * @author Diego Tabero & Marcos Leo Sonck
 *
 * This fucntion shows the number of ids and prints all the ids of the ids that contains
 * @param, set a pointer to the  set
 * @return OK, if everything goes well or ERROR if there was some mistake
 */
Status set_print(Set *set);

#endif








