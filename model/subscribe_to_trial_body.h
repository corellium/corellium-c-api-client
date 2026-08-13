/*
 * subscribe_to_trial_body.h
 *
 * 
 */

#ifndef _subscribe_to_trial_body_H_
#define _subscribe_to_trial_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct subscribe_to_trial_body_t subscribe_to_trial_body_t;




typedef struct subscribe_to_trial_body_t {
    char *trial_request_code; // string
    char *password; // string
    int terms_of_service; //boolean
    char *enterprise_domain_name; // string
    int sso; //boolean
    char *email; // string
    char *name; // string
    char *federated_user_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} subscribe_to_trial_body_t;

__attribute__((deprecated)) subscribe_to_trial_body_t *subscribe_to_trial_body_create(
    char *trial_request_code,
    char *password,
    int terms_of_service,
    char *enterprise_domain_name,
    int sso,
    char *email,
    char *name,
    char *federated_user_id
);

void subscribe_to_trial_body_free(subscribe_to_trial_body_t *subscribe_to_trial_body);

subscribe_to_trial_body_t *subscribe_to_trial_body_parseFromJSON(cJSON *subscribe_to_trial_bodyJSON);

cJSON *subscribe_to_trial_body_convertToJSON(subscribe_to_trial_body_t *subscribe_to_trial_body);

#endif /* _subscribe_to_trial_body_H_ */

