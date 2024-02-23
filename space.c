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
#include "set.h"

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
  Set *objects;              /*!< Set of objects in the space */
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
  newSpace->objects = set_create();

  if(!newSpace->objects){

    return NULL;
  }

  return newSpace;
}

Status space_destroy(Space* space) {
  if (!space) {
    return ERROR;
  }

  if(!set_destroy(space->objects)){

    return ERROR;
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

/* ¡PENDIENTE DE REVISAR SI SE NECESITA BORRAR!
Status space_set_object(Space* space, Id id) { 
  if (!space) {
    return ERROR;
  }
  space->object = id;
  return OK;
}
*/

/* ¡HAY QUE REVISAR QUE OPCION ES CORRECTA!
Set* space_get_objects(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->objects;
}
*/



long* space_get_objects(Space* space) {

  if(!space || !space->objects) {
    return NULL;
  }

  int n,i;

  n = set_get_nids(space->objects);

  if(n<=0){
    return NULL;
  }

  long* ids = NULL;

  ids = (long*) malloc(n*sizeof(long));

  if(!ids){
    return NULL;

  }

  for(i=0;i<n;i++){

    ids[i] = set_get_id(space->objects,i);
    /*¡REVISAR SI HACE FALTA ROMPER SI SE RECIVE NO_ID!*/

  }

  return ids;

}

Bool space_is_object_contained(Space *space, Id id){

  if(!space || id == NO_ID || set_is_empty(space->objects) ){

    return FALSE;
  }

  if(set_id_belongs(space->objects,id)){
    return TRUE;
  }else{
    return FALSE;
  }

}

Status space_add_object(Space* space, Id id) {

  if (!space || id == NO_ID || !space->objects) {
    return ERROR;
  }

  if(!set_add_id(space->objects, id)){

    return ERROR;
  }

  return OK;

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


/* 3. Prints the set of objects in the space */
   if(!set_print(space->objects)){

    return ERROR;
   }


  return OK;
}
