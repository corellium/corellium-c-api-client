/*
 * user_errors.h
 *
 * 
 */

#ifndef _user_errors_H_
#define _user_errors_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct user_errors_t user_errors_t;

#include "user_error.h"

// Enum ERRORID for user_errors

typedef enum  { corellium_api_user_errors_ERRORID_NULL = 0, corellium_api_user_errors_ERRORID_UserErrors } corellium_api_user_errors_ERRORID_e;

char* user_errors_error_id_ToString(corellium_api_user_errors_ERRORID_e error_id);

corellium_api_user_errors_ERRORID_e user_errors_error_id_FromString(char* error_id);



typedef struct user_errors_t {
    char *error; // string
    corellium_api_user_errors_ERRORID_e error_id; //enum
    list_t *errors; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} user_errors_t;

__attribute__((deprecated)) user_errors_t *user_errors_create(
    char *error,
    corellium_api_user_errors_ERRORID_e error_id,
    list_t *errors
);

void user_errors_free(user_errors_t *user_errors);

user_errors_t *user_errors_parseFromJSON(cJSON *user_errorsJSON);

cJSON *user_errors_convertToJSON(user_errors_t *user_errors);

#endif /* _user_errors_H_ */

