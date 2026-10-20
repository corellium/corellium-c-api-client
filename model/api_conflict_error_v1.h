/*
 * api_conflict_error_v1.h
 *
 * 
 */

#ifndef _api_conflict_error_v1_H_
#define _api_conflict_error_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct api_conflict_error_v1_t api_conflict_error_v1_t;

#include "any_type.h"
#include "object.h"

// Enum ERRORID for api_conflict_error_v1

typedef enum  { corellium_api_api_conflict_error_v1_ERRORID_NULL = 0, corellium_api_api_conflict_error_v1_ERRORID_Conflict } corellium_api_api_conflict_error_v1_ERRORID_e;

char* api_conflict_error_v1_error_id_ToString(corellium_api_api_conflict_error_v1_ERRORID_e error_id);

corellium_api_api_conflict_error_v1_ERRORID_e api_conflict_error_v1_error_id_FromString(char* error_id);



typedef struct api_conflict_error_v1_t {
    char *error; // string
    corellium_api_api_conflict_error_v1_ERRORID_e error_id; //enum
    object_t *object; //object

    int _library_owned; // Is the library responsible for freeing this object?
} api_conflict_error_v1_t;

__attribute__((deprecated)) api_conflict_error_v1_t *api_conflict_error_v1_create(
    char *error,
    corellium_api_api_conflict_error_v1_ERRORID_e error_id,
    object_t *object
);

void api_conflict_error_v1_free(api_conflict_error_v1_t *api_conflict_error_v1);

api_conflict_error_v1_t *api_conflict_error_v1_parseFromJSON(cJSON *api_conflict_error_v1JSON);

cJSON *api_conflict_error_v1_convertToJSON(api_conflict_error_v1_t *api_conflict_error_v1);

#endif /* _api_conflict_error_v1_H_ */

