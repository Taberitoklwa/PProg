/**
 * @brief It declares the tests for the character module
 *
 * @file character_test.h
 * @author Diego Tabero & Marcos Leo Sonck
 */

#ifndef CHARACTER_TEST_H
#define CHARACTER_TEST_H

/**
 * @brief Test function for creating a character.
 * @pre None.
 * @post A non-null pointer to a newly created character is returned.
 */
void test1_character_create();

/**
 * @brief Test function for creating a character.
 * @pre None.
 * @post The character has the specified ID.
 */
void test2_character_create();

/**
 * @brief Test function for destroying a character.
 * @pre A valid pointer to a character.
 * @post The character is successfully destroyed.
 */
void test1_character_destroy();

/**
 * @brief Test function for destroying a character.
 * @pre A null pointer to a character.
 * @post Function returns an error code indicating failure to destroy the character.
 */
void test2_character_destroy();

/**
 * @brief Test function for getting the ID of a character.
 * @pre A valid pointer to a character with a specified ID.
 * @post The function returns the correct ID of the character.
 */
void test1_character_get_id();

/**
 * @brief Test function for getting the ID of a character.
 * @pre A null pointer to a character.
 * @post Function returns NO_ID, indicating an error.
 */
void test2_character_get_id();

/**
 * @brief Test function for setting the name of a character.
 * @pre A valid pointer to a character and a valid name string.
 * @post The character's name is successfully set.
 */
void test1_character_set_name();

/**
 * @brief Test function for setting the name of a character.
 * @pre A null pointer to a character.
 * @post Function returns an error code indicating failure to set the name.
 */
void test2_character_set_name();

/**
 * @brief Test function for getting the name of a character.
 * @pre A valid pointer to a character with a specified name.
 * @post The function returns a non-null pointer to the character's name.
 */
void test1_character_get_name();

/**
 * @brief Test function for getting the name of a character.
 * @pre A null pointer to a character.
 * @post Function returns NULL, indicating an error.
 */
void test2_character_get_name();

/**
 * @brief Test function for setting the hit points (HP) of a character.
 * @pre A valid pointer to a character and a valid HP value.
 * @post The character's HP is successfully set to the specified value.
 */
void test1_character_set_hp();

/**
 * @brief Test function for setting the hit points (HP) of a character.
 * @pre A null pointer to a character.
 * @post Function returns an error code indicating failure to set the HP.
 */
void test2_character_set_hp();

/**
 * @brief Test function for getting the hit points (HP) of a character.
 * @pre A valid pointer to a character with a specified HP value.
 * @post The function returns the correct HP value of the character.
 */
void test1_character_get_hp();

/**
 * @brief Test function for getting the hit points (HP) of a character.
 * @pre A null pointer to a character.
 * @post Function returns an error code indicating failure to get the HP.
 */
void test2_character_get_hp();

/**
 * @brief Test function for setting a message for a character.
 * @pre A valid pointer to a character and a valid message string.
 * @post The character's message is successfully set to the specified value.
 */
void test1_character_set_message();

/**
 * @brief Test function for setting a message for a character.
 * @pre A null pointer to a character.
 * @post Function returns an error code indicating failure to set the message.
 */
void test2_character_set_message();

/**
 * @brief Test function for getting the message of a character.
 * @pre A valid pointer to a character with a specified message.
 * @post The function returns a non-null pointer to the character's message.
 */
void test1_character_get_message();

/**
 * @brief Test function for getting the message of a character.
 * @pre A null pointer to a character.
 * @post Function returns NULL, indicating an error.
 */
void test2_character_get_message();

/**
 * @brief Test function for setting the "friendly" attribute of a character.
 * @pre A valid pointer to a character and a valid boolean value.
 * @post The character's "friendly" attribute is successfully set to the specified value.
 */
void test1_character_set_friendly();

/**
 * @brief Test function for setting the "friendly" attribute of a character.
 * @pre A null pointer to a character.
 * @post Function returns an error code indicating failure to set the "friendly" attribute.
 */
void test2_character_set_friendly();

/**
 * @brief Test function for getting the "friendly" attribute of a character.
 * @pre A valid pointer to a character with a specified "friendly" attribute.
 * @post The function returns the correct "friendly" attribute value of the character.
 */
void test1_character_get_friendly();

/**
 * @brief Test function for getting the "friendly" attribute of a character.
 * @pre A null pointer to a character.
 * @post Function returns 0, indicating an error.
 */
void test2_character_get_friendly();

/**
 * @brief Test function for character information printing
 * @pre A pointer to a character.
 * @post Function returns OK, indicating success
 */

void test1_character_print();
/**
 * @brief Test function for character information printing
 * @pre A null pointer to a character.
 * @post Function returns 0, indicating an error.
 */

void test2_character_print();

#endif 