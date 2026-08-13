/*
 * allowed_domains_response.h
 *
 * 
 */

#ifndef _allowed_domains_response_H_
#define _allowed_domains_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct allowed_domains_response_t allowed_domains_response_t;




typedef struct allowed_domains_response_t {
    list_t *allowed_domains; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} allowed_domains_response_t;

__attribute__((deprecated)) allowed_domains_response_t *allowed_domains_response_create(
    list_t *allowed_domains
);

void allowed_domains_response_free(allowed_domains_response_t *allowed_domains_response);

allowed_domains_response_t *allowed_domains_response_parseFromJSON(cJSON *allowed_domains_responseJSON);

cJSON *allowed_domains_response_convertToJSON(allowed_domains_response_t *allowed_domains_response);

#endif /* _allowed_domains_response_H_ */

