/*
 * domain_welcome_message_response.h
 *
 * 
 */

#ifndef _domain_welcome_message_response_H_
#define _domain_welcome_message_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct domain_welcome_message_response_t domain_welcome_message_response_t;




typedef struct domain_welcome_message_response_t {
    char *identifier; // string
    char *domain; // string
    char *message; // string
    int enabled; //boolean
    char *created_at; //date time
    char *updated_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} domain_welcome_message_response_t;

__attribute__((deprecated)) domain_welcome_message_response_t *domain_welcome_message_response_create(
    char *identifier,
    char *domain,
    char *message,
    int enabled,
    char *created_at,
    char *updated_at
);

void domain_welcome_message_response_free(domain_welcome_message_response_t *domain_welcome_message_response);

domain_welcome_message_response_t *domain_welcome_message_response_parseFromJSON(cJSON *domain_welcome_message_responseJSON);

cJSON *domain_welcome_message_response_convertToJSON(domain_welcome_message_response_t *domain_welcome_message_response);

#endif /* _domain_welcome_message_response_H_ */

