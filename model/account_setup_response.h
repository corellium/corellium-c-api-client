/*
 * account_setup_response.h
 *
 * 
 */

#ifndef _account_setup_response_H_
#define _account_setup_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct account_setup_response_t account_setup_response_t;




typedef struct account_setup_response_t {
    int success; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} account_setup_response_t;

__attribute__((deprecated)) account_setup_response_t *account_setup_response_create(
    int success
);

void account_setup_response_free(account_setup_response_t *account_setup_response);

account_setup_response_t *account_setup_response_parseFromJSON(cJSON *account_setup_responseJSON);

cJSON *account_setup_response_convertToJSON(account_setup_response_t *account_setup_response);

#endif /* _account_setup_response_H_ */

