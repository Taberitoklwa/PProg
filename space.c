/**
 * @brief It implements the space module
 *
 * @file space.c
 * @author Profesores PPROG, Diego Tabero, Marcos Leo Sonck
 * @version 3.5
 * @date 9-2-2024
 * @copyright GNU Public License
 */

#include "space.h"
#include "character.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Space
 *
 * This struct stores all the information of a space.
 */
struct _Space {
  Id id;                    /*!< Id number of the space, it must be unique */
  char name[WORD_SIZE + 1]; /*!< Name of the space */
  Id north;                 /*!< Id of the space at the north */
  Id south;                 /*!< Id of the space at the south */
  Id east;                  /*!< Id of the space at the east */
  Id west;                  /*!< Id of the space at the west */
  Set *objects_id;              /*!< Whether the space has an object or not */
  Id character;  /*!< Id of the character located in the space */
};

/** space_create allocates memory for a new space
 *  and initializes its members
 */
Space* space_create(Id id) {
  Space* newSpace = NULL;

  /* Error control */
  if (id == NO_ID) return NULL;

  newSpace = (Space*)malloc(sizeof(Space));
  if (newSpace == NULL) {
    return NULL;
  }

  /* Initialization of an empty space*/
  newSpace->id = id;
  newSpace->name[0] = '\0';
  newSpace->north = NO_ID;
  newSpace->south = NO_ID;
  newSpace->east = NO_ID;
  newSpace->west = NO_ID;
  newSpace->objects_id = set_create();
  newSpace->character = NO_ID;

  return newSpace;
}

Status space_destroy(Space* space) {
  if (!space) {
    return ERROR;
  }

   if (space->objects_id)
    {
        set_destroy(space->objects_id);
    }

  free(space);
  space = NULL;
  return OK;
}

Id space_get_id(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->id;
}

Status space_set_name(Space* space, char* name) {
  if (!space || !name) {
    return ERROR;
  }

  if (!strcpy(space->name, name)) {
    return ERROR;
  }
  return OK;
}

const char* space_get_name(Space* space) {
  if (!space) {
    return NULL;
  }
  return space->name;
}


Status space_set_north(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->north = id;
  return OK;
}

Id space_get_north(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->north;
}

Status space_set_south(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->south = id;
  return OK;
}

Id space_get_south(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->south;
}

Status space_set_east(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->east = id;
  return OK;
}

Id space_get_east(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->east;
}

Status space_set_west(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->west = id;
  return OK;
}

Id space_get_west(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->west;
}

Id space_get_character_id(Space *space){

  if(!space){
    return NO_ID;
  }

  return space->character;

}

Status space_set_character_id(Space *space, Id id){

  if(!space){
    return ERROR;
  }

  space->character=id;

  return OK;
}

Status space_add_object(Space* space, Id id) {
  if (!space ||id==NO_ID) {
    return ERROR;
  }

  set_add_id(space->objects_id, id);

  return OK;
}

Status space_del_object(Space *space, Id id)
{
    /*Control error*/
    if (!space || id == NO_ID)
    {
        return ERROR;
    }
    return set_del_id(space->objects_id ,id);

}

Set *space_get_set_of_objects(Space* space) {
  if (!space) {
    return NULL;
  }

  return space->objects_id;
  
}

int space_get_n_objects(Space *space){
    if( !space){
        return -1;
    }
    return set_get_nids(space->objects_id);
}

int space_object_position_in_space(Space *space, Id id){

  if(!space || id==NO_ID){
    return -1;
  }

  return set_id_belongs(space->objects_id, id);
}


Status space_print(Space* space) {
  Id idaux = NO_ID;

  /* Error Control */
  if (!space) {
    return ERROR;
  }

  /* 1. Print the id and the name of the space */
  fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);

  /* 2. For each direction, print its link */
  idaux = space_get_north(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> North link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No north link.\n");
  }
  idaux = space_get_south(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> South link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No south link.\n");
  }
  idaux = space_get_east(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> East link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No east link.\n");
  }
  idaux = space_get_west(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> West link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No west link.\n");
  }

  /* 3. Print if there is an object in the space or not */

  /*

  if (space_get_object(space)!=NO_ID) {
    fprintf(stdout, "---> Object in the space.\n");
  } else {
    fprintf(stdout, "---> No object in the space.\n");
  }

  /*/


  return OK;
}