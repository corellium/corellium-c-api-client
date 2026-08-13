/*
 * load_extension_body.h
 *
 * 
 */

#ifndef _load_extension_body_H_
#define _load_extension_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct load_extension_body_t load_extension_body_t;




typedef struct load_extension_body_t {
    char *image_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} load_extension_body_t;

__attribute__((deprecated)) load_extension_body_t *load_extension_body_create(
    char *image_id
);

void load_extension_body_free(load_extension_body_t *load_extension_body);

load_extension_body_t *load_extension_body_parseFromJSON(cJSON *load_extension_bodyJSON);

cJSON *load_extension_body_convertToJSON(load_extension_body_t *load_extension_body);

#endif /* _load_extension_body_H_ */

