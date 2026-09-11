/*
 * login_result_disabled.h
 *
 * Public disable details. Present only when the domain is disabled.
 */

#ifndef _login_result_disabled_H_
#define _login_result_disabled_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct login_result_disabled_t login_result_disabled_t;




typedef struct login_result_disabled_t {
    char *type; // string
    char *disabled_at; //date time
    char *delete_instances_at; //date time
    char *cancel_date; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} login_result_disabled_t;

__attribute__((deprecated)) login_result_disabled_t *login_result_disabled_create(
    char *type,
    char *disabled_at,
    char *delete_instances_at,
    char *cancel_date
);

void login_result_disabled_free(login_result_disabled_t *login_result_disabled);

login_result_disabled_t *login_result_disabled_parseFromJSON(cJSON *login_result_disabledJSON);

cJSON *login_result_disabled_convertToJSON(login_result_disabled_t *login_result_disabled);

#endif /* _login_result_disabled_H_ */

