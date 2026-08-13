/*
 * user_error_v1.h
 *
 * 
 */

#ifndef _user_error_v1_H_
#define _user_error_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct user_error_v1_t user_error_v1_t;


// Enum ERRORID for user_error_v1

typedef enum  { corellium_api_user_error_v1_ERRORID_NULL = 0, corellium_api_user_error_v1_ERRORID_UserError } corellium_api_user_error_v1_ERRORID_e;

char* user_error_v1_error_id_ToString(corellium_api_user_error_v1_ERRORID_e error_id);

corellium_api_user_error_v1_ERRORID_e user_error_v1_error_id_FromString(char* error_id);



typedef struct user_error_v1_t {
    char *error; // string
    corellium_api_user_error_v1_ERRORID_e error_id; //enum
    char *field; // string

    int _library_owned; // Is the library responsible for freeing this object?
} user_error_v1_t;

__attribute__((deprecated)) user_error_v1_t *user_error_v1_create(
    char *error,
    corellium_api_user_error_v1_ERRORID_e error_id,
    char *field
);

void user_error_v1_free(user_error_v1_t *user_error_v1);

user_error_v1_t *user_error_v1_parseFromJSON(cJSON *user_error_v1JSON);

cJSON *user_error_v1_convertToJSON(user_error_v1_t *user_error_v1);

#endif /* _user_error_v1_H_ */

