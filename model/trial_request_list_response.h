/*
 * trial_request_list_response.h
 *
 * 
 */

#ifndef _trial_request_list_response_H_
#define _trial_request_list_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct trial_request_list_response_t trial_request_list_response_t;

#include "trial_request.h"



typedef struct trial_request_list_response_t {
    list_t *results; //nonprimitive container
    double count; //numeric
    double total; //numeric
    double limit; //numeric
    double offset; //numeric
    int has_more; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} trial_request_list_response_t;

__attribute__((deprecated)) trial_request_list_response_t *trial_request_list_response_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
);

void trial_request_list_response_free(trial_request_list_response_t *trial_request_list_response);

trial_request_list_response_t *trial_request_list_response_parseFromJSON(cJSON *trial_request_list_responseJSON);

cJSON *trial_request_list_response_convertToJSON(trial_request_list_response_t *trial_request_list_response);

#endif /* _trial_request_list_response_H_ */

