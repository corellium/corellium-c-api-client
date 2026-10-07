/*
 * invalid_credentials_error.h
 *
 * 
 */

#ifndef _invalid_credentials_error_H_
#define _invalid_credentials_error_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct invalid_credentials_error_t invalid_credentials_error_t;


// Enum ERRORID for invalid_credentials_error

typedef enum  { corellium_api_invalid_credentials_error_ERRORID_NULL = 0, corellium_api_invalid_credentials_error_ERRORID_InvalidUsernameorPassword } corellium_api_invalid_credentials_error_ERRORID_e;

char* invalid_credentials_error_error_id_ToString(corellium_api_invalid_credentials_error_ERRORID_e error_id);

corellium_api_invalid_credentials_error_ERRORID_e invalid_credentials_error_error_id_FromString(char* error_id);



typedef struct invalid_credentials_error_t {
    char *error; // string
    corellium_api_invalid_credentials_error_ERRORID_e error_id; //enum

    int _library_owned; // Is the library responsible for freeing this object?
} invalid_credentials_error_t;

__attribute__((deprecated)) invalid_credentials_error_t *invalid_credentials_error_create(
    char *error,
    corellium_api_invalid_credentials_error_ERRORID_e error_id
);

void invalid_credentials_error_free(invalid_credentials_error_t *invalid_credentials_error);

invalid_credentials_error_t *invalid_credentials_error_parseFromJSON(cJSON *invalid_credentials_errorJSON);

cJSON *invalid_credentials_error_convertToJSON(invalid_credentials_error_t *invalid_credentials_error);

#endif /* _invalid_credentials_error_H_ */

