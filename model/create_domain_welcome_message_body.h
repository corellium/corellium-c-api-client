/*
 * create_domain_welcome_message_body.h
 *
 * 
 */

#ifndef _create_domain_welcome_message_body_H_
#define _create_domain_welcome_message_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_domain_welcome_message_body_t create_domain_welcome_message_body_t;




typedef struct create_domain_welcome_message_body_t {
    char *message; // string
    int enabled; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} create_domain_welcome_message_body_t;

__attribute__((deprecated)) create_domain_welcome_message_body_t *create_domain_welcome_message_body_create(
    char *message,
    int enabled
);

void create_domain_welcome_message_body_free(create_domain_welcome_message_body_t *create_domain_welcome_message_body);

create_domain_welcome_message_body_t *create_domain_welcome_message_body_parseFromJSON(cJSON *create_domain_welcome_message_bodyJSON);

cJSON *create_domain_welcome_message_body_convertToJSON(create_domain_welcome_message_body_t *create_domain_welcome_message_body);

#endif /* _create_domain_welcome_message_body_H_ */

