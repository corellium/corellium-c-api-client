/*
 * reset_unauthorized_response.h
 *
 * 
 */

#ifndef _reset_unauthorized_response_H_
#define _reset_unauthorized_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct reset_unauthorized_response_t reset_unauthorized_response_t;

#include "invalid_totp_error.h"
#include "unauthorized_error.h"

// Enum ERRORID for reset_unauthorized_response

typedef enum  { corellium_api_reset_unauthorized_response_ERRORID_NULL = 0, corellium_api_reset_unauthorized_response_ERRORID_Unauthorized } corellium_api_reset_unauthorized_response_ERRORID_e;

char* reset_unauthorized_response_error_id_ToString(corellium_api_reset_unauthorized_response_ERRORID_e error_id);

corellium_api_reset_unauthorized_response_ERRORID_e reset_unauthorized_response_error_id_FromString(char* error_id);



typedef struct reset_unauthorized_response_t {
    char *error; // string
    corellium_api_reset_unauthorized_response_ERRORID_e error_id; //enum

    int _library_owned; // Is the library responsible for freeing this object?
} reset_unauthorized_response_t;

__attribute__((deprecated)) reset_unauthorized_response_t *reset_unauthorized_response_create(
    char *error,
    corellium_api_reset_unauthorized_response_ERRORID_e error_id
);

void reset_unauthorized_response_free(reset_unauthorized_response_t *reset_unauthorized_response);

reset_unauthorized_response_t *reset_unauthorized_response_parseFromJSON(cJSON *reset_unauthorized_responseJSON);

cJSON *reset_unauthorized_response_convertToJSON(reset_unauthorized_response_t *reset_unauthorized_response);

#endif /* _reset_unauthorized_response_H_ */

