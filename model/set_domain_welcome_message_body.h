/*
 * set_domain_welcome_message_body.h
 *
 * 
 */

#ifndef _set_domain_welcome_message_body_H_
#define _set_domain_welcome_message_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct set_domain_welcome_message_body_t set_domain_welcome_message_body_t;




typedef struct set_domain_welcome_message_body_t {
    char *message; // string
    int enabled; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} set_domain_welcome_message_body_t;

__attribute__((deprecated)) set_domain_welcome_message_body_t *set_domain_welcome_message_body_create(
    char *message,
    int enabled
);

void set_domain_welcome_message_body_free(set_domain_welcome_message_body_t *set_domain_welcome_message_body);

set_domain_welcome_message_body_t *set_domain_welcome_message_body_parseFromJSON(cJSON *set_domain_welcome_message_bodyJSON);

cJSON *set_domain_welcome_message_body_convertToJSON(set_domain_welcome_message_body_t *set_domain_welcome_message_body);

#endif /* _set_domain_welcome_message_body_H_ */

