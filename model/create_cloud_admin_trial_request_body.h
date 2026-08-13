/*
 * create_cloud_admin_trial_request_body.h
 *
 * 
 */

#ifndef _create_cloud_admin_trial_request_body_H_
#define _create_cloud_admin_trial_request_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_cloud_admin_trial_request_body_t create_cloud_admin_trial_request_body_t;




typedef struct create_cloud_admin_trial_request_body_t {
    char *email; // string
    char *name; // string
    char *phone; // string
    char *country; // string
    char *company; // string
    char *industry; // string
    char *role; // string
    char *solution; // string
    char *product_id; // string
    int granted; //boolean
    double number_of_apps; //numeric
    double team_size; //numeric
    int send_email; //boolean
    double duration; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} create_cloud_admin_trial_request_body_t;

__attribute__((deprecated)) create_cloud_admin_trial_request_body_t *create_cloud_admin_trial_request_body_create(
    char *email,
    char *name,
    char *phone,
    char *country,
    char *company,
    char *industry,
    char *role,
    char *solution,
    char *product_id,
    int granted,
    double number_of_apps,
    double team_size,
    int send_email,
    double duration
);

void create_cloud_admin_trial_request_body_free(create_cloud_admin_trial_request_body_t *create_cloud_admin_trial_request_body);

create_cloud_admin_trial_request_body_t *create_cloud_admin_trial_request_body_parseFromJSON(cJSON *create_cloud_admin_trial_request_bodyJSON);

cJSON *create_cloud_admin_trial_request_body_convertToJSON(create_cloud_admin_trial_request_body_t *create_cloud_admin_trial_request_body);

#endif /* _create_cloud_admin_trial_request_body_H_ */

