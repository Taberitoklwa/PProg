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
void test1_set_create();
void test2_set_create();
void test1_set_destroy();
void test2_set_destroy();
void test1_set_set_get_id();
void test2_set_set_get_id();
void test1_set_get_nids();
void test2_set_get_nids();
void test1_set_add_id();
void test2_set_add_id();
void test3_set_add_id();
void test1_set_del_id();
void test2_set_del_id();
void test3_set_del_id();
void test1_set_id_belongs();
void test2_set_id_belongs();
void test3_set_id_belongs();
void test1_set_set_is_empty();
void test2_set_set_is_empty();
void test2_set_set_is_full();
void test2_set_set_is_full();
void test1_set_get_ids();
void test1_set_get_ids();

#endif
