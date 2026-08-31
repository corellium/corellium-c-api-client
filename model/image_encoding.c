#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "image_encoding.h"


char* image_encoding_image_encoding_ToString(corellium_api_image_encoding__e image_encoding) {
    char *image_encodingArray[] =  { "NULL", "plain", "encrypted" };
    return image_encodingArray[image_encoding];
}

corellium_api_image_encoding__e image_encoding_image_encoding_FromString(char* image_encoding) {
    int stringToReturn = 0;
    char *image_encodingArray[] =  { "NULL", "plain", "encrypted" };
    size_t sizeofArray = sizeof(image_encodingArray) / sizeof(image_encodingArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(image_encoding, image_encodingArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *image_encoding_convertToJSON(corellium_api_image_encoding__e image_encoding) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "image_encoding", image_encoding_image_encoding_ToString(image_encoding)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

corellium_api_image_encoding__e image_encoding_parseFromJSON(cJSON *image_encodingJSON) {
    if(!cJSON_IsString(image_encodingJSON) || (image_encodingJSON->valuestring == NULL)) {
        return 0;
    }
    return image_encoding_image_encoding_FromString(image_encodingJSON->valuestring);
}
