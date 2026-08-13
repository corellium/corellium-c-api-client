/*
 * test_assessment_input.h
 *
 * 
 */

#ifndef _test_assessment_input_H_
#define _test_assessment_input_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct test_assessment_input_t test_assessment_input_t;




typedef struct test_assessment_input_t {
    int invert; //boolean
    char *grep; // string

    int _library_owned; // Is the library responsible for freeing this object?
} test_assessment_input_t;

__attribute__((deprecated)) test_assessment_input_t *test_assessment_input_create(
    int invert,
    char *grep
);

void test_assessment_input_free(test_assessment_input_t *test_assessment_input);

test_assessment_input_t *test_assessment_input_parseFromJSON(cJSON *test_assessment_inputJSON);

cJSON *test_assessment_input_convertToJSON(test_assessment_input_t *test_assessment_input);

#endif /* _test_assessment_input_H_ */

