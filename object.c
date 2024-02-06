/**
 * @brief It implements the object module
 *
 * @file object.c
 * @author Recurso 1
 * @version 3.5
 * @date 6-01-2024
 * @copyright GNU Public License
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"

/**
 * @brief Object
 *
 * This struct stores all the information of a object.
 */

struct _Object {
  Id id;                    /*!< Id number of the object, it must be unique */
  char name[WORD_SIZE + 1]; /*!< Name of the object */
  char description[WORD_SIZE +1]; /*!< Description of the object */
  Id north;                 /*!< Id of the object at the north */
  Id south;                 /*!< Id of the object at the south */
  Id east;                  /*!< Id of the object at the east */
  Id west;                  /*!< Id of the object at the west */
  Bool portable;              /*!< Whether the object is portable or not */
};

typedef struct _Object Object;

/** object_create allocates memory for a new object
 *  and initializes its members
 */
Object* object_create(Id id) {
  Object* newObject = NULL;

  /* Error control */
  if (id == NO_ID) return NULL;

  newObject = (Object*)malloc(sizeof(Object));
  if (newObject == NULL) {
    return NULL;
  }

  /* Initialization of an empty object*/
  newObject->id = id;
  newObject->name[0] = '\0';
  newObject->description[0] = '\0';
  newObject->north = NO_ID;
  newObject->south = NO_ID;
  newObject->east = NO_ID;
  newObject->west = NO_ID;
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

Status object_set_north(Object* object, Id id) {
  if (!object || id == NO_ID) {
    return ERROR;
  }
  object->north = id;
  return OK;
}

Id object_get_north(Object* object) {
  if (!object) {
    return NO_ID;
  }
  return object->north;
}

Status object_set_south(Object* object, Id id) {
  if (!object || id == NO_ID) {
    return ERROR;
  }
  object->south = id;
  return OK;
}

Id space_get_south(Object* object) {
  if (!object) {
    return NO_ID;
  }
  return object->south;
}


Status object_set_east(Object* object, Id id) {
  if (!object || id == NO_ID) {
    return ERROR;
  }
  object->east = id;
  return OK;
}

Id object_get_east(Object* object) {
  if (!object) {
    return NO_ID;
  }
  return object->east;
}

Status object_set_west(Object* object, Id id) {
  if (!object || id == NO_ID) {
    return ERROR;
  }
  object->west = id;
  return OK;
}

Id object_get_west(Object* object) {
  if (!object) {
    return NO_ID;
  }
  return object->west;
}

Status object_set_portable(Object* object, Bool value) {
  if (!object) {
    return ERROR;
  }
  object->portable = value;
  return OK;
}

Status object_print(Object* object) {
  Id idaux = NO_ID;

  /* Error Control */
  if (!object) {
    return ERROR;
  }
  /* 1. Print the id and the name of the object */
  fprintf(stdout, "--> object (Id: %ld; Name: %s)\n", object->id, object->name);

  /* 2. For each direction, print its link */
  idaux = object_get_north(object);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> North link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No north link.\n");
  }
  idaux = object_get_south(object);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> South link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No south link.\n");
  }
  idaux = object_get_east(object);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> East link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No east link.\n");
  }
  idaux = object_get_west(object);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> West link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No west link.\n");
  }

  return OK;
}
