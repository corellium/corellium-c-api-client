/*
 * ensure_domain_settings_response_user.h
 *
 * Admin user info.
 */

#ifndef _ensure_domain_settings_response_user_H_
#define _ensure_domain_settings_response_user_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ensure_domain_settings_response_user_t ensure_domain_settings_response_user_t;




typedef struct ensure_domain_settings_response_user_t {
    char *identifier; // string
    int created; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} ensure_domain_settings_response_user_t;

__attribute__((deprecated)) ensure_domain_settings_response_user_t *ensure_domain_settings_response_user_create(
    char *identifier,
    int created
);

void ensure_domain_settings_response_user_free(ensure_domain_settings_response_user_t *ensure_domain_settings_response_user);

ensure_domain_settings_response_user_t *ensure_domain_settings_response_user_parseFromJSON(cJSON *ensure_domain_settings_response_userJSON);

cJSON *ensure_domain_settings_response_user_convertToJSON(ensure_domain_settings_response_user_t *ensure_domain_settings_response_user);

#endif /* _ensure_domain_settings_response_user_H_ */

