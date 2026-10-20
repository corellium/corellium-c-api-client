/*
 * flavor_frame.h
 *
 * Frame geometry and metadata for the flavor.
 */

#ifndef _flavor_frame_H_
#define _flavor_frame_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct flavor_frame_t flavor_frame_t;

#include "flavor_frame_dimensions.h"
#include "flavor_frame_home.h"
#include "flavor_frame_inner.h"



typedef struct flavor_frame_t {
    char *url; // string
    double width; //numeric
    double height; //numeric
    struct flavor_frame_inner_t *inner; //model
    struct flavor_frame_home_t *home; //model
    struct flavor_frame_dimensions_t *dimensions; //model
    double scale; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} flavor_frame_t;

__attribute__((deprecated)) flavor_frame_t *flavor_frame_create(
    char *url,
    double width,
    double height,
    flavor_frame_inner_t *inner,
    flavor_frame_home_t *home,
    flavor_frame_dimensions_t *dimensions,
    double scale
);

void flavor_frame_free(flavor_frame_t *flavor_frame);

flavor_frame_t *flavor_frame_parseFromJSON(cJSON *flavor_frameJSON);

cJSON *flavor_frame_convertToJSON(flavor_frame_t *flavor_frame);

#endif /* _flavor_frame_H_ */

