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


// Enum TYPE for create_image_body

typedef enum  { corellium_api_create_image_body_TYPE_NULL = 0, corellium_api_create_image_body_TYPE_fwbinary, corellium_api_create_image_body_TYPE_fwpackage, corellium_api_create_image_body_TYPE_iotfirmware, corellium_api_create_image_body_TYPE_kernel, corellium_api_create_image_body_TYPE_devicetree, corellium_api_create_image_body_TYPE_ramdisk, corellium_api_create_image_body_TYPE_loaderfile, corellium_api_create_image_body_TYPE_media, corellium_api_create_image_body_TYPE_sepfw, corellium_api_create_image_body_TYPE_seprom, corellium_api_create_image_body_TYPE_bootrom, corellium_api_create_image_body_TYPE_llb, corellium_api_create_image_body_TYPE_iboot, corellium_api_create_image_body_TYPE_ibootdata, corellium_api_create_image_body_TYPE_fw, corellium_api_create_image_body_TYPE_fwasset, corellium_api_create_image_body_TYPE_partition, corellium_api_create_image_body_TYPE_extension, corellium_api_create_image_body_TYPE_vmfile, corellium_api_create_image_body_TYPE_backup, corellium_api_create_image_body_TYPE_activity_export, corellium_api_create_image_body_TYPE_ufd, corellium_api_create_image_body_TYPE_clbi, corellium_api_create_image_body_TYPE_pongo, corellium_api_create_image_body_TYPE_mast_report, corellium_api_create_image_body_TYPE_mast_frida } corellium_api_create_image_body_TYPE_e;

char* create_image_body_type_ToString(corellium_api_create_image_body_TYPE_e type);

corellium_api_create_image_body_TYPE_e create_image_body_type_FromString(char* type);

// Enum ENCODING for create_image_body

typedef enum  { corellium_api_create_image_body_ENCODING_NULL = 0, corellium_api_create_image_body_ENCODING_plain, corellium_api_create_image_body_ENCODING_encrypted } corellium_api_create_image_body_ENCODING_e;

char* create_image_body_encoding_ToString(corellium_api_create_image_body_ENCODING_e encoding);

corellium_api_create_image_body_ENCODING_e create_image_body_encoding_FromString(char* encoding);



typedef struct create_image_body_t {
    corellium_api_create_image_body_TYPE_e type; //enum
    corellium_api_create_image_body_ENCODING_e encoding; //enum
    int encapsulated; //boolean
    char *name; // string
    char *full_path; // string
    char *project_id; // string
    char *instance_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} create_image_body_t;

__attribute__((deprecated)) create_image_body_t *create_image_body_create(
    corellium_api_create_image_body_TYPE_e type,
    corellium_api_create_image_body_ENCODING_e encoding,
    int encapsulated,
    char *name,
    char *full_path,
    char *project_id,
    char *instance_id
);

void create_image_body_free(create_image_body_t *create_image_body);

create_image_body_t *create_image_body_parseFromJSON(cJSON *create_image_bodyJSON);

cJSON *create_image_body_convertToJSON(create_image_body_t *create_image_body);

#endif /* _create_image_body_H_ */

