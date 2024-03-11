/**
 * @brief It implements the set module
 *
 * @file set.c
 * @author Diego Tabero & Marcos Leo Sonck
 * @version 3.5
 * @date 27-02-2024
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "set.h"

/**
 * @brief Set
 *
 * This struct stores all the information of a set.
 */

struct _Set
{
    Id ids[MAX_ID];  /*!< Ids array containing object ids */
    int n_ids; /*!< Number of arrays saved in the set */
};

/** set_create allocates memory for a new set
 *  and initializes its members
 */
Set *set_create()
{
    Set *newSet = NULL;
    int i;

    /*Allocates memory for a new set and Error control*/

    newSet = (Set *)malloc(sizeof(Set));
    if (newSet == NULL)
    {
        return NULL;
    }

    /* Initialization of an empty set*/
    for(i=0;i<MAX_ID; i++){

        newSet->ids[i] = NO_ID;

    }
    
    newSet->n_ids = 0;

    return newSet;
}


Status set_destroy(Set *set)
{
    if (!set)
    {
        return ERROR;
    }

    free(set);
    set = NULL;
    return OK;
}

Id set_get_id(Set *set, int i){

    if(!set || i<0 || i>(set->n_ids-1)){
        return NO_ID;
    }

    return set->ids[i];


}

int set_get_nids(Set *set){

    if(!set){

        return ERROR;

    }

    return set->n_ids;

}


Status set_add_id(Set *set, Id id){

    if(!set || id == NO_ID || set->n_ids>=MAX_ID||set_id_belongs(set,id)>=0){

        return ERROR;

    }

    set->ids[set->n_ids]=id;
    (set->n_ids)++;

    return OK;

}


Status set_del_id(Set *set, Id id){

    int i=set_id_belongs(set, id);

    if(!set || set->n_ids==0||i<0){

        return ERROR;

    }

    set->ids[i]=set->ids[set->n_ids-1];
    set->ids[set->n_ids-1]=NO_ID;
   

    (set->n_ids)--;

    return OK;

}

int set_id_belongs(Set *set, Id id){

    int i;

    if(!set || id == NO_ID){

        return -1;

    }

    for(i=0; i<set->n_ids; i++){

        if(id==set->ids[i]){
            return i;
        }

    }

    return -1;

}

Bool set_is_empty(Set *set){

     if (!set)
    {
        return TRUE;
    }

    return set->n_ids==0;


}

Bool set_is_full(Set *set){

     if (!set)
    {
        return TRUE;
    }

    return set->n_ids==MAX_ID;

}

Status set_print(Set *set)
{

    int i;

    /* Error Control */
    if (!set)
    {
        return ERROR;
    }
    /* 1. Print the id and the name of the set */
    fprintf(stdout, "--> Set N_IDS: %d", set->n_ids);

    for (i = 0; i < set->n_ids; i++)
    {
        printf("ID %d %ld", i, set->ids[i]);
    }

    return OK;
}
