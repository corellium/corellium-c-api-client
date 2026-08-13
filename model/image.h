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


// Enum TYPE for image

typedef enum  { corellium_api_image_TYPE_NULL = 0, corellium_api_image_TYPE_fwbinary, corellium_api_image_TYPE_fwpackage, corellium_api_image_TYPE_iotfirmware, corellium_api_image_TYPE_kernel, corellium_api_image_TYPE_devicetree, corellium_api_image_TYPE_ramdisk, corellium_api_image_TYPE_loaderfile, corellium_api_image_TYPE_media, corellium_api_image_TYPE_sepfw, corellium_api_image_TYPE_seprom, corellium_api_image_TYPE_bootrom, corellium_api_image_TYPE_llb, corellium_api_image_TYPE_iboot, corellium_api_image_TYPE_ibootdata, corellium_api_image_TYPE_fw, corellium_api_image_TYPE_fwasset, corellium_api_image_TYPE_partition, corellium_api_image_TYPE_extension, corellium_api_image_TYPE_vmfile, corellium_api_image_TYPE_backup, corellium_api_image_TYPE_activity_export, corellium_api_image_TYPE_ufd, corellium_api_image_TYPE_clbi, corellium_api_image_TYPE_pongo, corellium_api_image_TYPE_mast_report, corellium_api_image_TYPE_mast_frida } corellium_api_image_TYPE_e;

char* image_type_ToString(corellium_api_image_TYPE_e type);

corellium_api_image_TYPE_e image_type_FromString(char* type);

// Enum ENCODING for image

typedef enum  { corellium_api_image_ENCODING_NULL = 0, corellium_api_image_ENCODING_plain, corellium_api_image_ENCODING_encrypted } corellium_api_image_ENCODING_e;

char* image_encoding_ToString(corellium_api_image_ENCODING_e encoding);

corellium_api_image_ENCODING_e image_encoding_FromString(char* encoding);



typedef struct image_t {
    char *status; // string
    char *id; // string
    char *name; // string
    corellium_api_image_TYPE_e type; //enum
    double size; //numeric
    char *checksum; // string
    char *corellium_checksum; // string
    corellium_api_image_ENCODING_e encoding; //enum
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
    corellium_api_image_TYPE_e type,
    double size,
    char *checksum,
    char *corellium_checksum,
    corellium_api_image_ENCODING_e encoding,
    char *project,
    char *instance,
    char *created_at,
    char *updated_at
);

void image_free(image_t *image);

image_t *image_parseFromJSON(cJSON *imageJSON);

cJSON *image_convertToJSON(image_t *image);

#endif /* _image_H_ */

