
/** 
 * @brief It declares the tests for the set module
 * 
 * @file set_test.h
 * @author Profesores Pprog
 * @version 2.0 
 * @date 09-03-2021
 * @copyright GNU Public License
 */

#ifndef SET_TEST_H
#define SET_TEST_H

/**
 * @brief Test function for creating a set.
 * @pre None.
 * @post A non-null pointer to a newly created set is returned.
 */
void test1_set_create();

/**
 * @brief Test function for creating a set.
 * @pre None.
 * @post The set contains no elements.
 */
void test2_set_create();

/**
 * @brief Test function for destroying a set.
 * @pre A valid pointer to a set.
 * @post The set is successfully destroyed.
 */
void test1_set_destroy();

/**
 * @brief Test function for destroying a set.
 * @pre A null pointer to a set.
 * @post Function returns an error code indicating failure to destroy the set.
 */
void test2_set_destroy();

/**
 * @brief Test function for setting and getting an ID in a set.
 * @pre A valid pointer to a set and a valid ID.
 * @post The set contains the specified ID.
 */
void test1_set_set_get_id();

/**
 * @brief Test function for setting and getting an ID in a set.
 * @pre A null pointer to a set.
 * @post Function returns an error code indicating failure to set or get the ID.
 */
void test2_set_set_get_id();

/**
 * @brief Test function for getting the number of IDs in a set.
 * @pre A valid pointer to a set with one or more IDs.
 * @post The function returns the correct number of IDs in the set.
 */
void test1_set_get_nids();

/**
 * @brief Test function for getting the number of IDs in a set.
 * @pre A null pointer to a set.
 * @post The function returns 0, indicating an empty set.
 */
void test2_set_get_nids();

/**
 * @brief Test function for adding an ID to a set.
 * @pre A valid pointer to a set and a valid ID.
 * @post The ID is successfully added to the set.
 */
void test1_set_add_id();

/**
 * @brief Test function for adding an ID to a set.
 * @pre A null pointer to a set.
 * @post Function returns an error code indicating failure to add the ID.
 */
void test2_set_add_id();

/**
 * @brief Test function for adding an existing ID to a set.
 * @pre A valid pointer to a set and an ID already present in the set.
 * @post Function returns an error code indicating failure to add the ID.
 */
void test3_set_add_id();

/**
 * @brief Test function for deleting an ID from a set.
 * @pre A valid pointer to a set and a valid ID.
 * @post The ID is successfully removed from the set.
 */
void test1_set_del_id();

/**
 * @brief Test function for deleting an ID from a set.
 * @pre A null pointer to a set.
 * @post Function returns an error code indicating failure to delete the ID.
 */
void test2_set_del_id();

/**
 * @brief Test function for deleting a non-existing ID from a set.
 * @pre A valid pointer to a set and an ID not present in the set.
 * @post Function returns an error code indicating failure to delete the ID.
 */
void test3_set_del_id();

/**
 * @brief Test function for checking if an ID belongs to a set.
 * @pre A valid pointer to a set and a valid ID.
 * @post Function returns 1 if the ID belongs to the set, otherwise returns 0.
 */
void test1_set_id_belongs();

/**
 * @brief Test function for checking if an ID belongs to a set.
 * @pre A null pointer to a set.
 * @post Function returns -1, indicating an error.
 */
void test2_set_id_belongs();

/**
 * @brief Test function for checking if a non-existing ID belongs to a set.
 * @pre A valid pointer to a set and an ID not present in the set.
 * @post Function returns -1, indicating that the ID does not belong to the set.
 */
void test3_set_id_belongs();

/**
 * @brief Test function for checking if a set is empty.
 * @pre A valid pointer to a set.
 * @post Function returns TRUE if the set is empty, otherwise returns FALSE.
 */
void test1_set_set_is_empty();

/**
 * @brief Test function for checking if a set is empty.
 * @pre A null pointer to a set.
 * @post Function returns TRUE, indicating an empty set.
 */
void test2_set_set_is_empty();

/**
 * @brief Test function for checking if a set is full.
 * @pre A valid pointer to a set.
 * @post Function returns TRUE if the set is full, otherwise returns FALSE.
 */
void test1_set_set_is_full();

/**
 * @brief Test function for checking if a set is full.
 * @pre A null pointer to a set.
 * @post Function returns TRUE, indicating a full set.
 */
void test2_set_set_is_full();

/**
 * @brief Test function for getting the IDs of a set.
 * @pre A valid pointer to a set with one or more IDs.
 * @post The function returns a non-null pointer to an array containing the set's IDs.
 */
void test1_set_get_ids();

/**
 * @brief Test function for getting the IDs of a set.
 * @pre A null pointer to a set.
 * @post The function returns a null pointer, indicating an empty set.
 */
void test2_set_get_ids();

/**
 * @brief Test function for printing the set
 * @pre A valid pointer to a set 
 * @post The function returns OK
 */
void test1_set_print();
/**
 * @brief Test function for printing the set
 * @pre A null pointer
 * @post The function returns ERROR
 */
void test2_set_print();

#endif
