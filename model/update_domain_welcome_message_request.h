/*
 * update_domain_welcome_message_request.h
 *
 * 
 */

#ifndef _update_domain_welcome_message_request_H_
#define _update_domain_welcome_message_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct update_domain_welcome_message_request_t update_domain_welcome_message_request_t;




typedef struct update_domain_welcome_message_request_t {
    char *message; // string
    int enabled; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} update_domain_welcome_message_request_t;

__attribute__((deprecated)) update_domain_welcome_message_request_t *update_domain_welcome_message_request_create(
    char *message,
    int enabled
);

void update_domain_welcome_message_request_free(update_domain_welcome_message_request_t *update_domain_welcome_message_request);

update_domain_welcome_message_request_t *update_domain_welcome_message_request_parseFromJSON(cJSON *update_domain_welcome_message_requestJSON);

cJSON *update_domain_welcome_message_request_convertToJSON(update_domain_welcome_message_request_t *update_domain_welcome_message_request);

#endif /* _update_domain_welcome_message_request_H_ */

