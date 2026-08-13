/*
 * ensure_domain_settings_response.h
 *
 * 
 */

#ifndef _ensure_domain_settings_response_H_
#define _ensure_domain_settings_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ensure_domain_settings_response_t ensure_domain_settings_response_t;

#include "ensure_domain_settings_response_user.h"



typedef struct ensure_domain_settings_response_t {
    int created; //boolean
    char *identifier; // string
    struct ensure_domain_settings_response_user_t *user; //model

    int _library_owned; // Is the library responsible for freeing this object?
} ensure_domain_settings_response_t;

__attribute__((deprecated)) ensure_domain_settings_response_t *ensure_domain_settings_response_create(
    int created,
    char *identifier,
    ensure_domain_settings_response_user_t *user
);

void ensure_domain_settings_response_free(ensure_domain_settings_response_t *ensure_domain_settings_response);

ensure_domain_settings_response_t *ensure_domain_settings_response_parseFromJSON(cJSON *ensure_domain_settings_responseJSON);

cJSON *ensure_domain_settings_response_convertToJSON(ensure_domain_settings_response_t *ensure_domain_settings_response);

#endif /* _ensure_domain_settings_response_H_ */

