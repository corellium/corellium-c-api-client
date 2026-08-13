/*
 * text_input_request_v1.h
 *
 * 
 */

#ifndef _text_input_request_v1_H_
#define _text_input_request_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct text_input_request_v1_t text_input_request_v1_t;




typedef struct text_input_request_v1_t {
    char *required; // string
    double key_duration; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} text_input_request_v1_t;

__attribute__((deprecated)) text_input_request_v1_t *text_input_request_v1_create(
    char *required,
    double key_duration
);

void text_input_request_v1_free(text_input_request_v1_t *text_input_request_v1);

text_input_request_v1_t *text_input_request_v1_parseFromJSON(cJSON *text_input_request_v1JSON);

cJSON *text_input_request_v1_convertToJSON(text_input_request_v1_t *text_input_request_v1);

#endif /* _text_input_request_v1_H_ */

