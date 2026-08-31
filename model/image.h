/*
 * image.h
 *
 * 
 */

#ifndef _image_H_
#define _image_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct image_t image_t;

#include "image_encoding.h"
#include "image_type.h"



typedef struct image_t {
    char *status; // string
    char *id; // string
    char *name; // string
    corellium_api_image_type__e type; //referenced enum
    double size; //numeric
    char *checksum; // string
    char *corellium_checksum; // string
    corellium_api_image_encoding__e encoding; //referenced enum
    char *project; // string
    char *instance; // string
    char *created_at; //date time
    char *updated_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} image_t;

__attribute__((deprecated)) image_t *image_create(
    char *status,
    char *id,
    char *name,
    corellium_api_image_type__e type,
    double size,
    char *checksum,
    char *corellium_checksum,
    corellium_api_image_encoding__e encoding,
    char *project,
    char *instance,
    char *created_at,
    char *updated_at
);

void image_free(image_t *image);

image_t *image_parseFromJSON(cJSON *imageJSON);

cJSON *image_convertToJSON(image_t *image);

#endif /* _image_H_ */

