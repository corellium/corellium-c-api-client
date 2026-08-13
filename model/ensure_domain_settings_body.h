/*
 * ensure_domain_settings_body.h
 *
 * 
 */

#ifndef _ensure_domain_settings_body_H_
#define _ensure_domain_settings_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ensure_domain_settings_body_t ensure_domain_settings_body_t;

#include "domain_config_input.h"
#include "ensure_domain_settings_body_admin_user.h"



typedef struct ensure_domain_settings_body_t {
    char *fqdn; // string
    char *name; // string
    double cores; //numeric
    char *password; // string
    char *password_if_empty; // string
    struct domain_config_input_t *config; //model
    struct ensure_domain_settings_body_admin_user_t *admin_user; //model

    int _library_owned; // Is the library responsible for freeing this object?
} ensure_domain_settings_body_t;

__attribute__((deprecated)) ensure_domain_settings_body_t *ensure_domain_settings_body_create(
    char *fqdn,
    char *name,
    double cores,
    char *password,
    char *password_if_empty,
    domain_config_input_t *config,
    ensure_domain_settings_body_admin_user_t *admin_user
);

void ensure_domain_settings_body_free(ensure_domain_settings_body_t *ensure_domain_settings_body);

ensure_domain_settings_body_t *ensure_domain_settings_body_parseFromJSON(cJSON *ensure_domain_settings_bodyJSON);

cJSON *ensure_domain_settings_body_convertToJSON(ensure_domain_settings_body_t *ensure_domain_settings_body);

#endif /* _ensure_domain_settings_body_H_ */

