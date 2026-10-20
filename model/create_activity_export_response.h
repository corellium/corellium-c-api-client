/*
 * create_activity_export_response.h
 *
 * 
 */

#ifndef _create_activity_export_response_H_
#define _create_activity_export_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_activity_export_response_t create_activity_export_response_t;




typedef struct create_activity_export_response_t {
    char *id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} create_activity_export_response_t;

__attribute__((deprecated)) create_activity_export_response_t *create_activity_export_response_create(
    char *id
);

void create_activity_export_response_free(create_activity_export_response_t *create_activity_export_response);

create_activity_export_response_t *create_activity_export_response_parseFromJSON(cJSON *create_activity_export_responseJSON);

cJSON *create_activity_export_response_convertToJSON(create_activity_export_response_t *create_activity_export_response);

#endif /* _create_activity_export_response_H_ */

