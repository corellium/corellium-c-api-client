#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "image_type.h"


char* image_type_image_type_ToString(corellium_api_image_type__e image_type) {
    char *image_typeArray[] =  { "NULL", "fwbinary", "fwpackage", "iotfirmware", "kernel", "devicetree", "ramdisk", "loaderfile", "media", "sepfw", "seprom", "bootrom", "llb", "iboot", "ibootdata", "fw", "fwasset", "partition", "extension", "vmfile", "backup", "activity-export", "ufd", "clbi", "pongo", "mast-report", "mast-frida", "mast-wordlist" };
    return image_typeArray[image_type];
}

corellium_api_image_type__e image_type_image_type_FromString(char* image_type) {
    int stringToReturn = 0;
    char *image_typeArray[] =  { "NULL", "fwbinary", "fwpackage", "iotfirmware", "kernel", "devicetree", "ramdisk", "loaderfile", "media", "sepfw", "seprom", "bootrom", "llb", "iboot", "ibootdata", "fw", "fwasset", "partition", "extension", "vmfile", "backup", "activity-export", "ufd", "clbi", "pongo", "mast-report", "mast-frida", "mast-wordlist" };
    size_t sizeofArray = sizeof(image_typeArray) / sizeof(image_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(image_type, image_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *image_type_convertToJSON(corellium_api_image_type__e image_type) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "image_type", image_type_image_type_ToString(image_type)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

corellium_api_image_type__e image_type_parseFromJSON(cJSON *image_typeJSON) {
    if(!cJSON_IsString(image_typeJSON) || (image_typeJSON->valuestring == NULL)) {
        return 0;
    }
    return image_type_image_type_FromString(image_typeJSON->valuestring);
}
