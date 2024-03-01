/**
 * @brief It tests set module
 *
 * @file set_test.c
 * @author Diego Tabero & Marcos Leo
 * @version 3.0
 * @date 09-03-2021
 * @copyright GNU Public License
 */

#include "character.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "character_test.h"
#include "test.h"

#define MAX_TESTS 26

/**
 * @brief Main function for CHARACTER unit tests.
 *
 * You may execute ALL or a SINGLE test
 *   1.- No parameter -> ALL test are executed
 *   2.- A number means a particular test (the one identified by that number)
 *       is executed
 *
 */
int main(int argc, char **argv) {
  int test = 0;
  int all = 1;

  if (argc < 2) {
    printf("Running all test for module Space:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 && test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }

  if (all || test == 1) test1_character_create();
  if (all || test == 2) test2_character_create();
  if (all || test == 3) test1_character_destroy();
  if (all || test == 4) test2_character_destroy();
  if (all || test == 5) test1_character_get_id();
  if (all || test == 6) test2_character_get_id();
  if (all || test == 7) test1_character_set_name();
  if (all || test == 8) test2_character_set_name();
  if (all || test == 9) test1_character_get_name();
  if (all || test == 10) test2_character_get_name();
  if (all || test == 11) test3_character_get_name();
  if (all || test == 12) test1_character_set_hp();
  if (all || test == 13) test2_character_set_hp();
  if (all || test == 14) test3_character_set_hp();
  if (all || test == 15) test1_character_get_hp();
  if (all || test == 16) test2_character_get_hp();
  if (all || test == 17) test1_character_set_message();
  if (all || test == 18) test2_character_set_message();
  if (all || test == 19) test1_character_get_message();
  if (all || test == 20) test2_character_get_message();
  if (all || test == 21) test1_character_set_friendly();
  if (all || test == 22) test2_character_set_friendly();
  if (all || test == 23) test1_character_get_friendly();
  if (all || test == 24) test2_character_get_friendly();
  if (all || test == 25) test1_character_print();
  if (all || test == 26) test2_character_print();

  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_character_create(){
    int result;
    Character *c;
    c = character_create(7);
    result = c != NULL;
    PRINT_TEST_RESULT(result);
    character_destroy(c);
}

void test2_character_create(){
    int result;
    Character *c;
    c = character_create(8);
    PRINT_TEST_RESULT(character_get_id(c) == 8);
    character_destroy(c);
}

void test1_character_destroy(){
    

}