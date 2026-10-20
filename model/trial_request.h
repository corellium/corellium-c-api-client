/*
 * trial_request.h
 *
 * 
 */

#ifndef _trial_request_H_
#define _trial_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct trial_request_t trial_request_t;

#include "any_type.h"
#include "object.h"



typedef struct trial_request_t {
    char *email; // string
    char *name; // string
    char *billing_type; // string
    char *billing_id; // string
    char *code; // string
    int enterprise; //boolean
    int granted; //boolean
    char *phone; // string
    char *country; // string
    char *organization; // string
    char *organization_type; // string
    object_t *metadata; //object
    double created_at; //numeric
    double updated_at; //numeric
    char *display_status; // string

    int _library_owned; // Is the library responsible for freeing this object?
} trial_request_t;

__attribute__((deprecated)) trial_request_t *trial_request_create(
    char *email,
    char *name,
    char *billing_type,
    char *billing_id,
    char *code,
    int enterprise,
    int granted,
    char *phone,
    char *country,
    char *organization,
    char *organization_type,
    object_t *metadata,
    double created_at,
    double updated_at,
    char *display_status
);

void trial_request_free(trial_request_t *trial_request);

trial_request_t *trial_request_parseFromJSON(cJSON *trial_requestJSON);

cJSON *trial_request_convertToJSON(trial_request_t *trial_request);

#endif /* _trial_request_H_ */

