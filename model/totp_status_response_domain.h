/*
 * totp_status_response_domain.h
 *
 * Domain context.
 */

#ifndef _totp_status_response_domain_H_
#define _totp_status_response_domain_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct totp_status_response_domain_t totp_status_response_domain_t;




typedef struct totp_status_response_domain_t {
    char *name; // string
    char *label; // string

    int _library_owned; // Is the library responsible for freeing this object?
} totp_status_response_domain_t;

__attribute__((deprecated)) totp_status_response_domain_t *totp_status_response_domain_create(
    char *name,
    char *label
);

void totp_status_response_domain_free(totp_status_response_domain_t *totp_status_response_domain);

totp_status_response_domain_t *totp_status_response_domain_parseFromJSON(cJSON *totp_status_response_domainJSON);

cJSON *totp_status_response_domain_convertToJSON(totp_status_response_domain_t *totp_status_response_domain);

#endif /* _totp_status_response_domain_H_ */

