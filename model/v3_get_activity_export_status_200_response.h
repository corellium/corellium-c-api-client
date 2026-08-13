/*
 * v3_get_activity_export_status_200_response.h
 *
 * 
 */

#ifndef _v3_get_activity_export_status_200_response_H_
#define _v3_get_activity_export_status_200_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v3_get_activity_export_status_200_response_t v3_get_activity_export_status_200_response_t;


// Enum STATUS for v3_get_activity_export_status_200_response

typedef enum  { corellium_api_v3_get_activity_export_status_200_response_STATUS_NULL = 0, corellium_api_v3_get_activity_export_status_200_response_STATUS_in_progress, corellium_api_v3_get_activity_export_status_200_response_STATUS_complete, corellium_api_v3_get_activity_export_status_200_response_STATUS_error } corellium_api_v3_get_activity_export_status_200_response_STATUS_e;

char* v3_get_activity_export_status_200_response_status_ToString(corellium_api_v3_get_activity_export_status_200_response_STATUS_e status);

corellium_api_v3_get_activity_export_status_200_response_STATUS_e v3_get_activity_export_status_200_response_status_FromString(char* status);



typedef struct v3_get_activity_export_status_200_response_t {
    corellium_api_v3_get_activity_export_status_200_response_STATUS_e status; //enum

    int _library_owned; // Is the library responsible for freeing this object?
} v3_get_activity_export_status_200_response_t;

__attribute__((deprecated)) v3_get_activity_export_status_200_response_t *v3_get_activity_export_status_200_response_create(
    corellium_api_v3_get_activity_export_status_200_response_STATUS_e status
);

void v3_get_activity_export_status_200_response_free(v3_get_activity_export_status_200_response_t *v3_get_activity_export_status_200_response);

v3_get_activity_export_status_200_response_t *v3_get_activity_export_status_200_response_parseFromJSON(cJSON *v3_get_activity_export_status_200_responseJSON);

cJSON *v3_get_activity_export_status_200_response_convertToJSON(v3_get_activity_export_status_200_response_t *v3_get_activity_export_status_200_response);

#endif /* _v3_get_activity_export_status_200_response_H_ */

