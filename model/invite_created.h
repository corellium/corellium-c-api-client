/*
 * invite_created.h
 *
 * 
 */

#ifndef _invite_created_H_
#define _invite_created_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct invite_created_t invite_created_t;

#include "any_type.h"
#include "object.h"



typedef struct invite_created_t {
    char *id; // string
    char *email; // string
    object_t *settings; //object

    int _library_owned; // Is the library responsible for freeing this object?
} invite_created_t;

__attribute__((deprecated)) invite_created_t *invite_created_create(
    char *id,
    char *email,
    object_t *settings
);

void invite_created_free(invite_created_t *invite_created);

invite_created_t *invite_created_parseFromJSON(cJSON *invite_createdJSON);

cJSON *invite_created_convertToJSON(invite_created_t *invite_created);

#endif /* _invite_created_H_ */

