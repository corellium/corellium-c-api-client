/*
 * v3_create_activity_export_201_response.h
 *
 * 
 */

#ifndef _v3_create_activity_export_201_response_H_
#define _v3_create_activity_export_201_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v3_create_activity_export_201_response_t v3_create_activity_export_201_response_t;




typedef struct v3_create_activity_export_201_response_t {
    char *id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v3_create_activity_export_201_response_t;

__attribute__((deprecated)) v3_create_activity_export_201_response_t *v3_create_activity_export_201_response_create(
    char *id
);

void v3_create_activity_export_201_response_free(v3_create_activity_export_201_response_t *v3_create_activity_export_201_response);

v3_create_activity_export_201_response_t *v3_create_activity_export_201_response_parseFromJSON(cJSON *v3_create_activity_export_201_responseJSON);

cJSON *v3_create_activity_export_201_response_convertToJSON(v3_create_activity_export_201_response_t *v3_create_activity_export_201_response);

#endif /* _v3_create_activity_export_201_response_H_ */

