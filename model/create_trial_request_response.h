/*
 * create_trial_request_response.h
 *
 * 
 */

#ifndef _create_trial_request_response_H_
#define _create_trial_request_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_trial_request_response_t create_trial_request_response_t;

#include "create_trial_request_response_trial_request.h"



typedef struct create_trial_request_response_t {
    struct create_trial_request_response_trial_request_t *trial_request; //model

    int _library_owned; // Is the library responsible for freeing this object?
} create_trial_request_response_t;

__attribute__((deprecated)) create_trial_request_response_t *create_trial_request_response_create(
    create_trial_request_response_trial_request_t *trial_request
);

void create_trial_request_response_free(create_trial_request_response_t *create_trial_request_response);

create_trial_request_response_t *create_trial_request_response_parseFromJSON(cJSON *create_trial_request_responseJSON);

cJSON *create_trial_request_response_convertToJSON(create_trial_request_response_t *create_trial_request_response);

#endif /* _create_trial_request_response_H_ */

