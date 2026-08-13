/*
 * activity_export_response.h
 *
 * 
 */

#ifndef _activity_export_response_H_
#define _activity_export_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct activity_export_response_t activity_export_response_t;




typedef struct activity_export_response_t {
    char *id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} activity_export_response_t;

__attribute__((deprecated)) activity_export_response_t *activity_export_response_create(
    char *id
);

void activity_export_response_free(activity_export_response_t *activity_export_response);

activity_export_response_t *activity_export_response_parseFromJSON(cJSON *activity_export_responseJSON);

cJSON *activity_export_response_convertToJSON(activity_export_response_t *activity_export_response);

#endif /* _activity_export_response_H_ */

