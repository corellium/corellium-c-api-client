/*
 * input_response.h
 *
 * 
 */

#ifndef _input_response_H_
#define _input_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct input_response_t input_response_t;




typedef struct input_response_t {
    double eta; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} input_response_t;

__attribute__((deprecated)) input_response_t *input_response_create(
    double eta
);

void input_response_free(input_response_t *input_response);

input_response_t *input_response_parseFromJSON(cJSON *input_responseJSON);

cJSON *input_response_convertToJSON(input_response_t *input_response);

#endif /* _input_response_H_ */

