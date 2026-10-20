/*
 * create_image_body.h
 *
 * 
 */

#ifndef _create_image_body_H_
#define _create_image_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_image_body_t create_image_body_t;

#include "image_encoding.h"
#include "image_type.h"



typedef struct create_image_body_t {
    corellium_api_image_type__e type; //referenced enum
    corellium_api_image_encoding__e encoding; //referenced enum
    int encapsulated; //boolean
    char *name; // string
    char *full_path; // string
    char *project_id; // string
    char *instance_id; // string
    binary_t* file; //binary

    int _library_owned; // Is the library responsible for freeing this object?
} create_image_body_t;

__attribute__((deprecated)) create_image_body_t *create_image_body_create(
    corellium_api_image_type__e type,
    corellium_api_image_encoding__e encoding,
    int encapsulated,
    char *name,
    char *full_path,
    char *project_id,
    char *instance_id,
    binary_t* file
);

void create_image_body_free(create_image_body_t *create_image_body);

create_image_body_t *create_image_body_parseFromJSON(cJSON *create_image_bodyJSON);

cJSON *create_image_body_convertToJSON(create_image_body_t *create_image_body);

#endif /* _create_image_body_H_ */

