/*
 * image_v1.h
 *
 * 
 */

#ifndef _image_v1_H_
#define _image_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct image_v1_t image_v1_t;

#include "image_extended.h"

// Enum TYPE for image_v1

typedef enum  { corellium_api_image_v1_TYPE_NULL = 0, corellium_api_image_v1_TYPE_fwbinary, corellium_api_image_v1_TYPE_kernel, corellium_api_image_v1_TYPE_devicetree, corellium_api_image_v1_TYPE_ramdisk, corellium_api_image_v1_TYPE_loaderfile, corellium_api_image_v1_TYPE_sepfw, corellium_api_image_v1_TYPE_seprom, corellium_api_image_v1_TYPE_bootrom, corellium_api_image_v1_TYPE_llb, corellium_api_image_v1_TYPE_iboot, corellium_api_image_v1_TYPE_ibootdata, corellium_api_image_v1_TYPE_fwpackage, corellium_api_image_v1_TYPE_partition, corellium_api_image_v1_TYPE_backup, corellium_api_image_v1_TYPE_ufd } corellium_api_image_v1_TYPE_e;

char* image_v1_type_ToString(corellium_api_image_v1_TYPE_e type);

corellium_api_image_v1_TYPE_e image_v1_type_FromString(char* type);



typedef struct image_v1_t {
    char *status; // string
    char *id; // string
    char *identifier; // string
    char *name; // string
    corellium_api_image_v1_TYPE_e type; //enum
    double size; //numeric
    char *checksum; // string
    char *corellium_checksum; // string
    char *encoding; // string
    char *filename; // string
    char *uniqueid; // string
    char *project; // string
    char *instance; // string
    char *created_at; //date time
    char *updated_at; //date time
    struct image_extended_t *extended; //model

    int _library_owned; // Is the library responsible for freeing this object?
} image_v1_t;

__attribute__((deprecated)) image_v1_t *image_v1_create(
    char *status,
    char *id,
    char *identifier,
    char *name,
    corellium_api_image_v1_TYPE_e type,
    double size,
    char *checksum,
    char *corellium_checksum,
    char *encoding,
    char *filename,
    char *uniqueid,
    char *project,
    char *instance,
    char *created_at,
    char *updated_at,
    image_extended_t *extended
);

void image_v1_free(image_v1_t *image_v1);

image_v1_t *image_v1_parseFromJSON(cJSON *image_v1JSON);

cJSON *image_v1_convertToJSON(image_v1_t *image_v1);

#endif /* _image_v1_H_ */

