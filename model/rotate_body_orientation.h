/*
 * rotate_body_orientation.h
 *
 * Desired orientation. 1&#x3D;Portrait, 2&#x3D;Portrait inverted, 3&#x3D;Landscape (top left), 4&#x3D;Landscape (top right).
 */

#ifndef _rotate_body_orientation_H_
#define _rotate_body_orientation_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct rotate_body_orientation_t rotate_body_orientation_t;




typedef struct rotate_body_orientation_t {

    int _library_owned; // Is the library responsible for freeing this object?
} rotate_body_orientation_t;

__attribute__((deprecated)) rotate_body_orientation_t *rotate_body_orientation_create(
);

void rotate_body_orientation_free(rotate_body_orientation_t *rotate_body_orientation);

rotate_body_orientation_t *rotate_body_orientation_parseFromJSON(cJSON *rotate_body_orientationJSON);

cJSON *rotate_body_orientation_convertToJSON(rotate_body_orientation_t *rotate_body_orientation);

#endif /* _rotate_body_orientation_H_ */

