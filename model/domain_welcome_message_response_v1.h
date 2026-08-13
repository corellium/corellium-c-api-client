/*
 * domain_welcome_message_response_v1.h
 *
 * 
 */

#ifndef _domain_welcome_message_response_v1_H_
#define _domain_welcome_message_response_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct domain_welcome_message_response_v1_t domain_welcome_message_response_v1_t;




typedef struct domain_welcome_message_response_v1_t {
    char *identifier; // string
    char *domain; // string
    char *message; // string
    char *created_at; // string
    char *updated_at; // string

    int _library_owned; // Is the library responsible for freeing this object?
} domain_welcome_message_response_v1_t;

__attribute__((deprecated)) domain_welcome_message_response_v1_t *domain_welcome_message_response_v1_create(
    char *identifier,
    char *domain,
    char *message,
    char *created_at,
    char *updated_at
);

void domain_welcome_message_response_v1_free(domain_welcome_message_response_v1_t *domain_welcome_message_response_v1);

domain_welcome_message_response_v1_t *domain_welcome_message_response_v1_parseFromJSON(cJSON *domain_welcome_message_response_v1JSON);

cJSON *domain_welcome_message_response_v1_convertToJSON(domain_welcome_message_response_v1_t *domain_welcome_message_response_v1);

#endif /* _domain_welcome_message_response_v1_H_ */

