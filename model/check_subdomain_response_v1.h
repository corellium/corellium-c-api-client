/*
 * check_subdomain_response_v1.h
 *
 * 
 */

#ifndef _check_subdomain_response_v1_H_
#define _check_subdomain_response_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct check_subdomain_response_v1_t check_subdomain_response_v1_t;




typedef struct check_subdomain_response_v1_t {
    int available; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} check_subdomain_response_v1_t;

__attribute__((deprecated)) check_subdomain_response_v1_t *check_subdomain_response_v1_create(
    int available
);

void check_subdomain_response_v1_free(check_subdomain_response_v1_t *check_subdomain_response_v1);

check_subdomain_response_v1_t *check_subdomain_response_v1_parseFromJSON(cJSON *check_subdomain_response_v1JSON);

cJSON *check_subdomain_response_v1_convertToJSON(check_subdomain_response_v1_t *check_subdomain_response_v1);

#endif /* _check_subdomain_response_v1_H_ */

