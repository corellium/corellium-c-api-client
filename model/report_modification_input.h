/*
 * report_modification_input.h
 *
 * 
 */

#ifndef _report_modification_input_H_
#define _report_modification_input_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct report_modification_input_t report_modification_input_t;

#include "any_type.h"
#include "object.h"



typedef struct report_modification_input_t {
    char *check_id; // string
    object_t *property; //object
    int suppressed; //boolean
    char *value; // string

    int _library_owned; // Is the library responsible for freeing this object?
} report_modification_input_t;

__attribute__((deprecated)) report_modification_input_t *report_modification_input_create(
    char *check_id,
    object_t *property,
    int suppressed,
    char *value
);

void report_modification_input_free(report_modification_input_t *report_modification_input);

report_modification_input_t *report_modification_input_parseFromJSON(cJSON *report_modification_inputJSON);

cJSON *report_modification_input_convertToJSON(report_modification_input_t *report_modification_input);

#endif /* _report_modification_input_H_ */

