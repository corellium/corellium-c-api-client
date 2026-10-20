/*
 * invite_result.h
 *
 * 
 */

#ifndef _invite_result_H_
#define _invite_result_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct invite_result_t invite_result_t;

#include "invite_result_error.h"
#include "invite_result_invite.h"



typedef struct invite_result_t {
    struct invite_result_invite_t *invite; //model
    struct invite_result_error_t *error; //model

    int _library_owned; // Is the library responsible for freeing this object?
} invite_result_t;

__attribute__((deprecated)) invite_result_t *invite_result_create(
    invite_result_invite_t *invite,
    invite_result_error_t *error
);

void invite_result_free(invite_result_t *invite_result);

invite_result_t *invite_result_parseFromJSON(cJSON *invite_resultJSON);

cJSON *invite_result_convertToJSON(invite_result_t *invite_result);

#endif /* _invite_result_H_ */

