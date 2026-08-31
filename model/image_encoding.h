/*
 * image_encoding.h
 *
 * How the file is stored. Absent for generated artifacts.
 */

#ifndef _image_encoding_H_
#define _image_encoding_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct image_encoding_t image_encoding_t;


// Enum  for image_encoding

typedef enum { corellium_api_image_encoding__NULL = 0, corellium_api_image_encoding__plain, corellium_api_image_encoding__encrypted } corellium_api_image_encoding__e;

char* image_encoding_image_encoding_ToString(corellium_api_image_encoding__e image_encoding);

corellium_api_image_encoding__e image_encoding_image_encoding_FromString(char* image_encoding);

cJSON *image_encoding_convertToJSON(corellium_api_image_encoding__e image_encoding);

corellium_api_image_encoding__e image_encoding_parseFromJSON(cJSON *image_encodingJSON);

#endif /* _image_encoding_H_ */

