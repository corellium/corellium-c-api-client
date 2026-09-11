/*
 * unauthorized_error.h
 *
 * 
 */

#ifndef _unauthorized_error_H_
#define _unauthorized_error_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct unauthorized_error_t unauthorized_error_t;


// Enum ERRORID for unauthorized_error

typedef enum  { corellium_api_unauthorized_error_ERRORID_NULL = 0, corellium_api_unauthorized_error_ERRORID_Unauthorized } corellium_api_unauthorized_error_ERRORID_e;

char* unauthorized_error_error_id_ToString(corellium_api_unauthorized_error_ERRORID_e error_id);

corellium_api_unauthorized_error_ERRORID_e unauthorized_error_error_id_FromString(char* error_id);



typedef struct unauthorized_error_t {
    char *error; // string
    corellium_api_unauthorized_error_ERRORID_e error_id; //enum

    int _library_owned; // Is the library responsible for freeing this object?
} unauthorized_error_t;

__attribute__((deprecated)) unauthorized_error_t *unauthorized_error_create(
    char *error,
    corellium_api_unauthorized_error_ERRORID_e error_id
);

void unauthorized_error_free(unauthorized_error_t *unauthorized_error);

unauthorized_error_t *unauthorized_error_parseFromJSON(cJSON *unauthorized_errorJSON);

cJSON *unauthorized_error_convertToJSON(unauthorized_error_t *unauthorized_error);

#endif /* _unauthorized_error_H_ */

