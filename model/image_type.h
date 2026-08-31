/*
 * image_type.h
 *
 * Image type.
 */

#ifndef _image_type_H_
#define _image_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct image_type_t image_type_t;


// Enum  for image_type

typedef enum { corellium_api_image_type__NULL = 0, corellium_api_image_type__fwbinary, corellium_api_image_type__fwpackage, corellium_api_image_type__iotfirmware, corellium_api_image_type__kernel, corellium_api_image_type__devicetree, corellium_api_image_type__ramdisk, corellium_api_image_type__loaderfile, corellium_api_image_type__media, corellium_api_image_type__sepfw, corellium_api_image_type__seprom, corellium_api_image_type__bootrom, corellium_api_image_type__llb, corellium_api_image_type__iboot, corellium_api_image_type__ibootdata, corellium_api_image_type__fw, corellium_api_image_type__fwasset, corellium_api_image_type__partition, corellium_api_image_type__extension, corellium_api_image_type__vmfile, corellium_api_image_type__backup, corellium_api_image_type__activity_export, corellium_api_image_type__ufd, corellium_api_image_type__clbi, corellium_api_image_type__pongo, corellium_api_image_type__mast_report, corellium_api_image_type__mast_frida } corellium_api_image_type__e;

char* image_type_image_type_ToString(corellium_api_image_type__e image_type);

corellium_api_image_type__e image_type_image_type_FromString(char* image_type);

cJSON *image_type_convertToJSON(corellium_api_image_type__e image_type);

corellium_api_image_type__e image_type_parseFromJSON(cJSON *image_typeJSON);

#endif /* _image_type_H_ */

