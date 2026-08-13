/*
 * totp_generate_response.h
 *
 * 
 */

#ifndef _totp_generate_response_H_
#define _totp_generate_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct totp_generate_response_t totp_generate_response_t;




typedef struct totp_generate_response_t {
    char *qr_code; // string
    char *secret; // string

    int _library_owned; // Is the library responsible for freeing this object?
} totp_generate_response_t;

__attribute__((deprecated)) totp_generate_response_t *totp_generate_response_create(
    char *qr_code,
    char *secret
);

void totp_generate_response_free(totp_generate_response_t *totp_generate_response);

totp_generate_response_t *totp_generate_response_parseFromJSON(cJSON *totp_generate_responseJSON);

cJSON *totp_generate_response_convertToJSON(totp_generate_response_t *totp_generate_response);

#endif /* _totp_generate_response_H_ */

