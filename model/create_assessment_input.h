/*
 * create_assessment_input.h
 *
 * 
 */

#ifndef _create_assessment_input_H_
#define _create_assessment_input_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_assessment_input_t create_assessment_input_t;




typedef struct create_assessment_input_t {
    char *instance_id; // string
    char *bundle_id; // string
    char *wordlist_id; // string
    char *frida_script_id; // string
    char *created_by; // string

    int _library_owned; // Is the library responsible for freeing this object?
} create_assessment_input_t;

__attribute__((deprecated)) create_assessment_input_t *create_assessment_input_create(
    char *instance_id,
    char *bundle_id,
    char *wordlist_id,
    char *frida_script_id,
    char *created_by
);

void create_assessment_input_free(create_assessment_input_t *create_assessment_input);

create_assessment_input_t *create_assessment_input_parseFromJSON(cJSON *create_assessment_inputJSON);

cJSON *create_assessment_input_convertToJSON(create_assessment_input_t *create_assessment_input);

#endif /* _create_assessment_input_H_ */

