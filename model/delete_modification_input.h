/*
 * delete_modification_input.h
 *
 * 
 */

#ifndef _delete_modification_input_H_
#define _delete_modification_input_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct delete_modification_input_t delete_modification_input_t;

#include "any_type.h"
#include "object.h"



typedef struct delete_modification_input_t {
    char *check_id; // string
    object_t *property; //object

    int _library_owned; // Is the library responsible for freeing this object?
} delete_modification_input_t;

__attribute__((deprecated)) delete_modification_input_t *delete_modification_input_create(
    char *check_id,
    object_t *property
);

void delete_modification_input_free(delete_modification_input_t *delete_modification_input);

delete_modification_input_t *delete_modification_input_parseFromJSON(cJSON *delete_modification_inputJSON);

cJSON *delete_modification_input_convertToJSON(delete_modification_input_t *delete_modification_input);

#endif /* _delete_modification_input_H_ */

