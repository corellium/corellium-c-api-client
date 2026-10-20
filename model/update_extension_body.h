/*
 * update_extension_body.h
 *
 * 
 */

#ifndef _update_extension_body_H_
#define _update_extension_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct update_extension_body_t update_extension_body_t;




typedef struct update_extension_body_t {
    int enabled; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} update_extension_body_t;

__attribute__((deprecated)) update_extension_body_t *update_extension_body_create(
    int enabled
);

void update_extension_body_free(update_extension_body_t *update_extension_body);

update_extension_body_t *update_extension_body_parseFromJSON(cJSON *update_extension_bodyJSON);

cJSON *update_extension_body_convertToJSON(update_extension_body_t *update_extension_body);

#endif /* _update_extension_body_H_ */

