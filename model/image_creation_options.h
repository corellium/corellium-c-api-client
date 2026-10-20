/*
 * image_creation_options.h
 *
 * 
 */

#ifndef _image_creation_options_H_
#define _image_creation_options_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct image_creation_options_t image_creation_options_t;


// Enum ENCODING for image_creation_options

typedef enum  { corellium_api_image_creation_options_ENCODING_NULL = 0, corellium_api_image_creation_options_ENCODING_plain, corellium_api_image_creation_options_ENCODING_encrypted } corellium_api_image_creation_options_ENCODING_e;

char* image_creation_options_encoding_ToString(corellium_api_image_creation_options_ENCODING_e encoding);

corellium_api_image_creation_options_ENCODING_e image_creation_options_encoding_FromString(char* encoding);



typedef struct image_creation_options_t {
    char *type; // string
    corellium_api_image_creation_options_ENCODING_e encoding; //enum
    int encapsulated; //boolean
    char *name; // string
    char *full_path; // string
    char *project; // string
    char *instance; // string
    binary_t* file; //binary

    int _library_owned; // Is the library responsible for freeing this object?
} image_creation_options_t;

__attribute__((deprecated)) image_creation_options_t *image_creation_options_create(
    char *type,
    corellium_api_image_creation_options_ENCODING_e encoding,
    int encapsulated,
    char *name,
    char *full_path,
    char *project,
    char *instance,
    binary_t* file
);

void image_creation_options_free(image_creation_options_t *image_creation_options);

image_creation_options_t *image_creation_options_parseFromJSON(cJSON *image_creation_optionsJSON);

cJSON *image_creation_options_convertToJSON(image_creation_options_t *image_creation_options);

#endif /* _image_creation_options_H_ */

