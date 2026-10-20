/*
 * flavor_frame_home.h
 *
 * Home button hit area within the frame.
 */

#ifndef _flavor_frame_home_H_
#define _flavor_frame_home_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct flavor_frame_home_t flavor_frame_home_t;




typedef struct flavor_frame_home_t {
    double top; //numeric
    double left; //numeric
    double width; //numeric
    double height; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} flavor_frame_home_t;

__attribute__((deprecated)) flavor_frame_home_t *flavor_frame_home_create(
    double top,
    double left,
    double width,
    double height
);

void flavor_frame_home_free(flavor_frame_home_t *flavor_frame_home);

flavor_frame_home_t *flavor_frame_home_parseFromJSON(cJSON *flavor_frame_homeJSON);

cJSON *flavor_frame_home_convertToJSON(flavor_frame_home_t *flavor_frame_home);

#endif /* _flavor_frame_home_H_ */

