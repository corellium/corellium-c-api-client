/*
 * invite_created_entry.h
 *
 * 
 */

#ifndef _invite_created_entry_H_
#define _invite_created_entry_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct invite_created_entry_t invite_created_entry_t;

#include "invite_created.h"



typedef struct invite_created_entry_t {
    struct invite_created_t *invite; //model

    int _library_owned; // Is the library responsible for freeing this object?
} invite_created_entry_t;

__attribute__((deprecated)) invite_created_entry_t *invite_created_entry_create(
    invite_created_t *invite
);

void invite_created_entry_free(invite_created_entry_t *invite_created_entry);

invite_created_entry_t *invite_created_entry_parseFromJSON(cJSON *invite_created_entryJSON);

cJSON *invite_created_entry_convertToJSON(invite_created_entry_t *invite_created_entry);

#endif /* _invite_created_entry_H_ */

