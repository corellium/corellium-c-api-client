/*
 * patch_domain_welcome_message_body.h
 *
 * 
 */

#ifndef _patch_domain_welcome_message_body_H_
#define _patch_domain_welcome_message_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct patch_domain_welcome_message_body_t patch_domain_welcome_message_body_t;




typedef struct patch_domain_welcome_message_body_t {
    char *message; // string
    int enabled; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} patch_domain_welcome_message_body_t;

__attribute__((deprecated)) patch_domain_welcome_message_body_t *patch_domain_welcome_message_body_create(
    char *message,
    int enabled
);

void patch_domain_welcome_message_body_free(patch_domain_welcome_message_body_t *patch_domain_welcome_message_body);

patch_domain_welcome_message_body_t *patch_domain_welcome_message_body_parseFromJSON(cJSON *patch_domain_welcome_message_bodyJSON);

cJSON *patch_domain_welcome_message_body_convertToJSON(patch_domain_welcome_message_body_t *patch_domain_welcome_message_body);

#endif /* _patch_domain_welcome_message_body_H_ */

