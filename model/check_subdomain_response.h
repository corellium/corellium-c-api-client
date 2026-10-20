/*
 * check_subdomain_response.h
 *
 * 
 */

#ifndef _check_subdomain_response_H_
#define _check_subdomain_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct check_subdomain_response_t check_subdomain_response_t;




typedef struct check_subdomain_response_t {
    int available; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} check_subdomain_response_t;

__attribute__((deprecated)) check_subdomain_response_t *check_subdomain_response_create(
    int available
);

void check_subdomain_response_free(check_subdomain_response_t *check_subdomain_response);

check_subdomain_response_t *check_subdomain_response_parseFromJSON(cJSON *check_subdomain_responseJSON);

cJSON *check_subdomain_response_convertToJSON(check_subdomain_response_t *check_subdomain_response);

#endif /* _check_subdomain_response_H_ */

