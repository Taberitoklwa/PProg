/**
 * @brief It tests set module
 *
 * @file set_test.c
 * @author Diego Tabero & Marcos Leo
 * @version 3.0
 * @date 09-03-2021
 * @copyright GNU Public License
 */

#include "set.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "set_test.h"
#include "test.h"

#define MAX_TESTS 28

/**
 * @brief Main function for SET unit tests.
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

  if (all || test == 1) test1_set_create();
  if (all || test == 2) test2_set_create();
  if (all || test == 3) test1_set_destroy();
  if (all || test == 4) test2_set_destroy();
  if (all || test == 5) test1_set_set_get_id();
  if (all || test == 6) test2_set_set_get_id();
  if (all || test == 7) test1_set_get_nids();
  if (all || test == 8) test2_set_get_nids();
  if (all || test == 9) test1_set_add_id();
  if (all || test == 10) test2_set_add_id();
  if (all || test == 11) test3_set_add_id();
  if (all || test == 12) test1_set_del_id();
  if (all || test == 13) test2_set_del_id();
  if (all || test == 14) test3_set_del_id();
  if (all || test == 15) test1_set_id_belongs();
  if (all || test == 16) test2_set_id_belongs();
  if (all || test == 17) test3_set_id_belongs();
  if (all || test == 18) test1_set_set_is_empty();
  if (all || test == 19) test2_set_set_is_empty();
  if (all || test == 20) test2_set_set_is_full();
  if (all || test == 21) test2_set_set_is_full();
  if (all || test == 22) test1_set_get_ids();
  if (all || test == 23) test1_set_get_ids();
  if (all || test == 24) test1_set_print();
  if (all || test == 25) test2_set_print();


  PRINT_PASSED_PERCENTAGE;

  return 1;
}

void test1_set_create() {
  int result;
  Set *s;
  s = set_create();
  result = s != NULL;
  PRINT_TEST_RESULT(result);
  set_destroy(s);
}

void test2_set_create() {
  Set *s;
  s = set_create();
  PRINT_TEST_RESULT(set_get_nids(s) == 0);
  set_destroy(s);
}

void test1_set_destroy(){
  Set *s=NULL;
  PRINT_TEST_RESULT(set_destroy(s) == ERROR);
  set_destroy(s);
}

void test2_set_destroy() {
    Set *s;
    s=set_create();

    PRINT_TEST_RESULT(set_destroy(s) == OK);
}

void test1_set_set_get_id() {
  Set *s;
  s = set_create();
  set_add_id(s, 6);
  PRINT_TEST_RESULT(set_get_id(s, 0) == 6);
  set_destroy(s);
}

void test2_set_set_get_id() {
  Set *s=NULL;
  PRINT_TEST_RESULT(set_get_id(s, 0) == ERROR);
  set_destroy(s);
}

void test1_set_get_nids() {
  Set *s = NULL;
  s = set_create();
  set_add_id(s, 5);
  set_add_id(s, 7);
  PRINT_TEST_RESULT(set_get_nids(s) == 2);
  set_destroy(s);
}

void test2_set_get_nids() {
  Set *s=NULL;
  s = set_create();
  PRINT_TEST_RESULT(set_get_nids(s) == 0);
  set_destroy(s);
}

void test1_set_add_id() {
  Set *s = NULL;
  PRINT_TEST_RESULT(set_add_id(s, 4) == ERROR);
}

void test2_set_add_id() {
  Set *s;
  s = set_create();
  set_add_id(s, 5);
  PRINT_TEST_RESULT(set_id_belongs(s, 5) == 0);
  set_destroy(s);
}

void test3_set_add_id() {
  Set *s = NULL;
  s=set_create();
  set_add_id(s, 6);
  PRINT_TEST_RESULT(set_add_id(s, 6) == ERROR);
  set_destroy(s);
}

void test1_set_del_id() {
  Set *s=NULL;
  PRINT_TEST_RESULT(set_del_id(s, 4) == ERROR);
  set_destroy(s);
}

void test2_set_del_id() {
  Set *s=NULL;
  s=set_create();
  PRINT_TEST_RESULT(set_del_id(s, 4) == ERROR);
  set_destroy(s);
}

void test3_set_del_id() {
  Set *s=NULL;
  s=set_create();
  set_add_id(s, 5);
  PRINT_TEST_RESULT(set_del_id(s, 5) == OK);
  set_destroy(s);
}

void test1_set_id_belongs() {
  Set *s;
  s = set_create();

  set_add_id(s, 5);
  set_add_id(s, 6);
  
  PRINT_TEST_RESULT(set_id_belongs(s, 6) == 1);
  set_destroy(s);
}

void test2_set_id_belongs() {
  Set *s=NULL;
  
  PRINT_TEST_RESULT(set_id_belongs(s, 6) == -1);
  set_destroy(s);
}

void test3_set_id_belongs() {
  Set *s;
  s = set_create();

  set_add_id(s, 5);

  PRINT_TEST_RESULT(set_id_belongs(s, 6) == -1);
  set_destroy(s);
}


void test1_set_set_is_empty() {
  Set *s;
  s = set_create();

  PRINT_TEST_RESULT(set_is_empty(s) == TRUE);
  set_destroy(s);
}

void test2_set_set_is_empty() {
  Set *s=NULL;

  PRINT_TEST_RESULT(set_is_empty(s) == TRUE);
  set_destroy(s);
}

void test1_set_set_is_full() {
  Set *s=NULL;

  PRINT_TEST_RESULT(set_is_full(s) == TRUE);
  set_destroy(s);
}

void test2_set_set_is_full() {
  Set *s=NULL;
  int i;
  s=set_create();


  for(i=0; i<12; i++){
    set_add_id(s,i);

  }

  PRINT_TEST_RESULT(set_is_full(s) == TRUE);
  set_destroy(s);
}

void test1_set_get_ids() {
  Set *s;
  s = set_create();
  PRINT_TEST_RESULT(set_get_ids(s) != NULL);
  set_destroy(s);
}

void test2_set_get_ids() {
  Set *s=NULL;

  PRINT_TEST_RESULT(set_get_ids(s) == NULL);
  set_destroy(s);
}

void test1_set_print(){
  Set* set = set_create();
  PRINT_TEST_RESULT(set_print(set) == OK);
  set_destroy(set);
}

void test2_set_print(){
  PRINT_TEST_RESULT(set_print(NULL) == ERROR);
}