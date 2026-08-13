/*
 * input_response_v1.h
 *
 * 
 */

#ifndef _input_response_v1_H_
#define _input_response_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct input_response_v1_t input_response_v1_t;




typedef struct input_response_v1_t {
    double eta; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} input_response_v1_t;

__attribute__((deprecated)) input_response_v1_t *input_response_v1_create(
    double eta
);

void input_response_v1_free(input_response_v1_t *input_response_v1);

input_response_v1_t *input_response_v1_parseFromJSON(cJSON *input_response_v1JSON);

cJSON *input_response_v1_convertToJSON(input_response_v1_t *input_response_v1);

#endif /* _input_response_v1_H_ */

