/*
 * text_input_request.h
 *
 * 
 */

#ifndef _text_input_request_H_
#define _text_input_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct text_input_request_t text_input_request_t;




typedef struct text_input_request_t {
    char *text; // string
    double key_duration; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} text_input_request_t;

__attribute__((deprecated)) text_input_request_t *text_input_request_create(
    char *text,
    double key_duration
);

void text_input_request_free(text_input_request_t *text_input_request);

text_input_request_t *text_input_request_parseFromJSON(cJSON *text_input_requestJSON);

cJSON *text_input_request_convertToJSON(text_input_request_t *text_input_request);

#endif /* _text_input_request_H_ */

