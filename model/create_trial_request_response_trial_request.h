/*
 * create_trial_request_response_trial_request.h
 *
 * Created trial request info.
 */

#ifndef _create_trial_request_response_trial_request_H_
#define _create_trial_request_response_trial_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_trial_request_response_trial_request_t create_trial_request_response_trial_request_t;




typedef struct create_trial_request_response_trial_request_t {
    char *identifier; // string
    char *email; // string
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} create_trial_request_response_trial_request_t;

__attribute__((deprecated)) create_trial_request_response_trial_request_t *create_trial_request_response_trial_request_create(
    char *identifier,
    char *email,
    char *name
);

void create_trial_request_response_trial_request_free(create_trial_request_response_trial_request_t *create_trial_request_response_trial_request);

create_trial_request_response_trial_request_t *create_trial_request_response_trial_request_parseFromJSON(cJSON *create_trial_request_response_trial_requestJSON);

cJSON *create_trial_request_response_trial_request_convertToJSON(create_trial_request_response_trial_request_t *create_trial_request_response_trial_request);

#endif /* _create_trial_request_response_trial_request_H_ */

