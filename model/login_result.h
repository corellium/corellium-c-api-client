/*
 * login_result.h
 *
 * 
 */

#ifndef _login_result_H_
#define _login_result_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct login_result_t login_result_t;




typedef struct login_result_t {
    char *token; // string
    char *expiration; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} login_result_t;

__attribute__((deprecated)) login_result_t *login_result_create(
    char *token,
    char *expiration
);

void login_result_free(login_result_t *login_result);

login_result_t *login_result_parseFromJSON(cJSON *login_resultJSON);

cJSON *login_result_convertToJSON(login_result_t *login_result);

#endif /* _login_result_H_ */

