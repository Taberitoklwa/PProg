/**
 * @brief It implements the object module
 *
 * @file object.c
 * @author Diego Tabero & Marcos Leo Sonck
 * @version 3.5
 * @date 6-01-2024
 * @copyright GNU Public License
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "object.h"

/**
 * @brief Object
 *
 * This struct stores all the information of a object.
 */

struct _Object {
  Id id;                    /*!< Id number of the object, it must be unique */
  char name[WORD_SIZE + 1]; /*!< Name of the object */
  char description[WORD_SIZE +1]; /*!< Description of the object */
  Bool portable;              /*!< Whether the object is portable or not */
};

/** object_create allocates memory for a new object 
 *  and initializes its members
 */
Object* object_create(Id id) {
  Object* newObject = NULL;

  /* Error control */
  if (id == NO_ID) return NULL;

  /*Allocates memory for a new object and Error control*/

  newObject = (Object*)malloc(sizeof(Object));
  if (newObject == NULL) {
    return NULL;
  }

  /* Initialization of an empty object*/
  newObject->id = id;
  newObject->name[0] = '\0';
  newObject->description[0] = '\0';
  newObject->portable = FALSE;

  return newObject;
}

Status object_destroy(Object* object) {
  if (!object) {
    return ERROR;
  }

  free(object);
  object = NULL;
  return OK;
}

Id object_get_id(Object* object) {
  if (!object) {
    return NO_ID;
  }
  return object->id;
}

Status object_set_name(Object* object, char* name) {
  if (!object || !name) {
    return ERROR;
  }

  if (!strcpy(object->name, name)) {
    return ERROR;
  }
  return OK;
}

Status object_set_description(Object* object, char* description) {
  if (!object || !description) {
    return ERROR;
  }

  if (!strcpy(object->description, description)) {
    return ERROR;
  }
  return OK;
}


const char* object_get_name(Object* object) {
  if (!object) {
    return NULL;
  }
  return object->name;
}

Status object_set_portable(Object* object, Bool value) {
  if (!object) {
    return ERROR;
  }
  object->portable = value;
  return OK;
}

Status object_print(Object* object) {

  /* Error Control */
  if (!object) {
    return ERROR;
  }
  /* 1. Print the id and the name of the object */
  fprintf(stdout, "--> object (Id: %ld; Name: %s)\n", object->id, object->name);

  return OK;
}
