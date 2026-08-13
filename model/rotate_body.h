/*
 * rotate_body.h
 *
 * 
 */

#ifndef _rotate_body_H_
#define _rotate_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct rotate_body_t rotate_body_t;

#include "rotate_body_orientation.h"



typedef struct rotate_body_t {
    struct rotate_body_orientation_t *orientation; //model

    int _library_owned; // Is the library responsible for freeing this object?
} rotate_body_t;

__attribute__((deprecated)) rotate_body_t *rotate_body_create(
    rotate_body_orientation_t *orientation
);

void rotate_body_free(rotate_body_t *rotate_body);

rotate_body_t *rotate_body_parseFromJSON(cJSON *rotate_bodyJSON);

cJSON *rotate_body_convertToJSON(rotate_body_t *rotate_body);

#endif /* _rotate_body_H_ */

