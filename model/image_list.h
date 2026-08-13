/*
 * image_list.h
 *
 * 
 */

#ifndef _image_list_H_
#define _image_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct image_list_t image_list_t;

#include "image.h"



typedef struct image_list_t {
    list_t *results; //nonprimitive container
    double count; //numeric
    double total; //numeric
    double limit; //numeric
    double offset; //numeric
    int has_more; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} image_list_t;

__attribute__((deprecated)) image_list_t *image_list_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
);

void image_list_free(image_list_t *image_list);

image_list_t *image_list_parseFromJSON(cJSON *image_listJSON);

cJSON *image_list_convertToJSON(image_list_t *image_list);

#endif /* _image_list_H_ */

