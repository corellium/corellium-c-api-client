/*
 * patch_user_body.h
 *
 * 
 */

#ifndef _patch_user_body_H_
#define _patch_user_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct patch_user_body_t patch_user_body_t;

#include "any_type.h"
#include "object.h"



typedef struct patch_user_body_t {
    char *name; // string
    char *label; // string
    char *email; // string
    int cluster_administrator; //boolean
    char *password; // string
    object_t *misc; //object
    int administrator; //boolean
    char *agreed_to_terms; // string
    int totp_enabled; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} patch_user_body_t;

__attribute__((deprecated)) patch_user_body_t *patch_user_body_create(
    char *name,
    char *label,
    char *email,
    int cluster_administrator,
    char *password,
    object_t *misc,
    int administrator,
    char *agreed_to_terms,
    int totp_enabled
);

void patch_user_body_free(patch_user_body_t *patch_user_body);

patch_user_body_t *patch_user_body_parseFromJSON(cJSON *patch_user_bodyJSON);

cJSON *patch_user_body_convertToJSON(patch_user_body_t *patch_user_body);

#endif /* _patch_user_body_H_ */

