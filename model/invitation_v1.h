/*
 * invitation_v1.h
 *
 * 
 */

#ifndef _invitation_v1_H_
#define _invitation_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct invitation_v1_t invitation_v1_t;

#include "any_type.h"
#include "object.h"



typedef struct invitation_v1_t {
    char *identifier; // string
    char *email; // string
    object_t *settings; //object

    int _library_owned; // Is the library responsible for freeing this object?
} invitation_v1_t;

__attribute__((deprecated)) invitation_v1_t *invitation_v1_create(
    char *identifier,
    char *email,
    object_t *settings
);

void invitation_v1_free(invitation_v1_t *invitation_v1);

invitation_v1_t *invitation_v1_parseFromJSON(cJSON *invitation_v1JSON);

cJSON *invitation_v1_convertToJSON(invitation_v1_t *invitation_v1);

#endif /* _invitation_v1_H_ */

