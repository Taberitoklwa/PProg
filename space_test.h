/** 
 * @brief It declares the tests for the space module
 * 
 * @file space_test.h
 * @author Profesores Pprog
 * @version 2.0 
 * @date 09-03-2021
 * @copyright GNU Public License
 */

#ifndef SPACE_TEST_H
#define SPACE_TEST_H


/**
 * @test Test space creation
 * @pre Space ID 
 * @post Non NULL pointer to space 
 */
void test1_space_create();

/**
 * @test Test space creation
 * @pre Space ID 
 * @post Space_ID == Supplied Space Id
 */
void test2_space_create();

/**
 * @test Test function for space_name setting
 * @pre String with space name
 * @post Ouput==OK 
 */
void test1_space_set_name();

/**
 * @test Test function for space_name setting
 * @pre pointer to space = NULL 
 * @post Output==ERROR
 */
void test2_space_set_name();

/**
 * @test Test function for space_name setting
 * @pre pointer to space_name = NULL (point to space = NON NULL) 
 * @post Output==ERROR
 */

void test3_space_set_name();

/**
 * @test Test function for space_north setting
 * @pre pointer to space
 * @post Output== OK
 */

void test1_space_set_north();

/**
 * @test Test function for space_north setting
 * @pre pointer to space = NULL
 * @post Output==ERROR
 */

void test2_space_set_north();

/**
 * @test Test function for space_south setting
 * @pre pointer to space
 * @post Output== OK
 */

void test1_space_set_south();

/**
 * @test Test function for space_south setting
 * @pre pointer to space = NULL
 * @post Output==ERROR
 */

void test2_space_set_south();

/**
 * @test Test function for space_east setting
 * @pre pointer to space
 * @post Output== OK
 */

void test1_space_set_east();

/**
 * @test Test function for space_east setting
 * @pre pointer to space = NULL
 * @post Output==ERROR
 */

void test2_space_set_east();

/**
 * @test Test function for space_west setting
 * @pre pointer to space
 * @post Output== OK
 */

void test1_space_set_west();

/**
 * @test Test function for space_west setting
 * @pre pointer to space = NULL
 * @post Output==ERROR
 */

void test2_space_set_west();

/**
 * @test Test function for space_name getting
 * @pre pointer to space 
 * @pre valid name
 * @post Output== The introduced name
 */

void test1_space_get_name();

/**
 * @test Test function for space_name getting
 * @pre pointer to space = NULL
 * @post Output==NULL
 */

void test2_space_get_name();

/**
 * @test Test function for space_north getting
 * @pre pointer to space 
 * @pre valid ID location
 * @post Output==The ID
 */
void test1_space_get_north();

/**
 * @test Test function for space_north getting
 * @pre pointer to space = NULL 
 * @post Output==NO_ID
 */

void test2_space_get_north();

/**
 * @test Test function for space_south getting
 * @pre pointer to space 
 * @pre valid ID location
 * @post Output==The ID
 */

void test1_space_get_south();

/**
 * @test Test function for space_south getting
 * @pre pointer to space = NULL 
 * @post Output==NO_ID
 */

void test2_space_get_south();

/**
 * @test Test function for space_south getting
 * @pre pointer to space 
 * @pre valid ID location
 * @post Output==The ID
 */

void test1_space_get_east();

/**
 * @test Test function for space_east getting
 * @pre pointer to space = NULL 
 * @post Output==NO_ID
 */

void test2_space_get_east();

/**
 * @test Test function for space_west getting
 * @pre pointer to space 
 * @pre valid ID location
 * @post Output==The ID
 */

void test1_space_get_west();

/**
 * @test Test function for space_west getting
 * @pre pointer to space = NULL 
 * @post Output==NO_ID
 */

void test2_space_get_west();

/**
 * @test Test function for space_id getting
 * @pre valid ID location
 * @post Output== ID location introduced
 */

void test1_space_get_id();

/**
 * @test Test function for space_id getting
 * @pre pointer to space = NULL 
 * @post Output== NO_ID
 */

void test2_space_get_id();

/**
 * @test Test function for space destroying
 * @pre pointer to space 
 * @post Output== Ok
 */

void test1_space_destroy();

/**
 * @test Test function for space destroying
 * @pre NULL pointer
 * @post Output== ERROR
 */

void test2_space_destroy();

/**
 * @test Test function for adding objects
 * @pre pointer to space
 * @post Output== OK
 */

void test1_space_add_object();

/**
 * @test Test function for adding objects
 * @pre pointer to NULL
 * @post Output== ERROR
 */

void test2_space_add_object();

/**
 * @test Test function for deleting objects
 * @pre pointer to space
 * @pre object added in space
 * @post Output== OK
 */

void test1_space_del_object();

/**
 * @test Test function for deleting objects
 * @pre pointer to NULL
 * @post Output== ERROR
 */

void test2_space_del_object();

/**
 * @test Test function for getting the number of objects
 * @pre pointer to space
 * @pre object added in space
 * @post Output== Number of added objects
 */

void test1_space_get_n_objects();

/**
 * @test Test function for getting the number of objects
 * @pre pointer to NULL
 * @post Output== -1
 */


void test2_space_get_n_objects();

/**
 * @test Test function for getting the index ob the object in the set (if the object is in the set)
 * @pre pointer to space
 * @pre added object
 * @post Output== Position of the object
 */


void test1_space_object_position_in_space();

/**
 * @test Test function for getting the index of the object in the set (if the object is in the set)
 * @pre pointer to NULL
 * @post Output== -1
 */

void test2_space_object_position_in_space();

/**
 * @test Test function for getting the character id
 * @pre Pointer to space
 * @pre Character set in the space
 * @post Output== Character Id 
 */

void test1_space_get_character_id();

/**
 * @test Test function for getting the character id
 * @pre pointer to NULL
 * @post Output== Character Id 
 */

void test2_space_get_character_id();

/**
 * @test Test function for getting the character id
 * @pre Pointer to space
 * @pre Character set in the space
 * @post Output== Character Id 
 */
void test1_space_set_character_id();

/**
 * @test Test function for setting the character id
 * @pre pointer to NULL
 * @post Output== ERROR
 */
void test2_space_set_character_id();

/**
 * @test Test function for printing the Space information
 * @pre pointer to space
 * @post Output== OK 
 */

void test1_space_print();

/**
 * @test Test function for printing the Space information
 * @pre pointer to NULL
 * @post Output== ERROR
 */


void test2_space_print();


#endif