/*
 * create_trial_request_body.h
 *
 * 
 */

#ifndef _create_trial_request_body_H_
#define _create_trial_request_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_trial_request_body_t create_trial_request_body_t;


// Enum TYPE for create_trial_request_body

typedef enum  { corellium_api_create_trial_request_body_TYPE_NULL = 0, corellium_api_create_trial_request_body_TYPE_individual, corellium_api_create_trial_request_body_TYPE_enterprise } corellium_api_create_trial_request_body_TYPE_e;

char* create_trial_request_body_type_ToString(corellium_api_create_trial_request_body_TYPE_e type);

corellium_api_create_trial_request_body_TYPE_e create_trial_request_body_type_FromString(char* type);



typedef struct create_trial_request_body_t {
    char *email; // string
    char *name; // string
    char *phone; // string
    char *country; // string
    corellium_api_create_trial_request_body_TYPE_e type; //enum
    char *company; // string
    char *industry; // string
    char *role; // string
    char *solution; // string
    char *product_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} create_trial_request_body_t;

__attribute__((deprecated)) create_trial_request_body_t *create_trial_request_body_create(
    char *email,
    char *name,
    char *phone,
    char *country,
    corellium_api_create_trial_request_body_TYPE_e type,
    char *company,
    char *industry,
    char *role,
    char *solution,
    char *product_id
);

void create_trial_request_body_free(create_trial_request_body_t *create_trial_request_body);

create_trial_request_body_t *create_trial_request_body_parseFromJSON(cJSON *create_trial_request_bodyJSON);

cJSON *create_trial_request_body_convertToJSON(create_trial_request_body_t *create_trial_request_body);

#endif /* _create_trial_request_body_H_ */

