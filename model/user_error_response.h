/*
 * user_error_response.h
 *
 * 
 */

#ifndef _user_error_response_H_
#define _user_error_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct user_error_response_t user_error_response_t;

#include "user_error.h"
#include "user_errors.h"

// Enum ERRORID for user_error_response

typedef enum  { corellium_api_user_error_response_ERRORID_NULL = 0, corellium_api_user_error_response_ERRORID_UserErrors } corellium_api_user_error_response_ERRORID_e;

char* user_error_response_error_id_ToString(corellium_api_user_error_response_ERRORID_e error_id);

corellium_api_user_error_response_ERRORID_e user_error_response_error_id_FromString(char* error_id);



typedef struct user_error_response_t {
    char *error; // string
    corellium_api_user_error_response_ERRORID_e error_id; //enum
    char *field; // string
    char *validator; // string
    list_t *project_ids; //primitive container
    list_t *missing_fw_assets; //primitive container
    list_t *errors; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} user_error_response_t;

__attribute__((deprecated)) user_error_response_t *user_error_response_create(
    char *error,
    corellium_api_user_error_response_ERRORID_e error_id,
    char *field,
    char *validator,
    list_t *project_ids,
    list_t *missing_fw_assets,
    list_t *errors
);

void user_error_response_free(user_error_response_t *user_error_response);

user_error_response_t *user_error_response_parseFromJSON(cJSON *user_error_responseJSON);

cJSON *user_error_response_convertToJSON(user_error_response_t *user_error_response);

#endif /* _user_error_response_H_ */

