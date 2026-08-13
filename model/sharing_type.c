#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sharing_type.h"


char* sharing_type_sharing_type_ToString(corellium_api_sharing_type__e sharing_type) {
    char *sharing_typeArray[] =  { "NULL", "publicLink", "domainRestrictedLink", "passwordPublicLink", "emailInvite" };
    return sharing_typeArray[sharing_type];
}

corellium_api_sharing_type__e sharing_type_sharing_type_FromString(char* sharing_type) {
    int stringToReturn = 0;
    char *sharing_typeArray[] =  { "NULL", "publicLink", "domainRestrictedLink", "passwordPublicLink", "emailInvite" };
    size_t sizeofArray = sizeof(sharing_typeArray) / sizeof(sharing_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(sharing_type, sharing_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *sharing_type_convertToJSON(corellium_api_sharing_type__e sharing_type) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "sharing_type", sharing_type_sharing_type_ToString(sharing_type)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

corellium_api_sharing_type__e sharing_type_parseFromJSON(cJSON *sharing_typeJSON) {
    if(!cJSON_IsString(sharing_typeJSON) || (sharing_typeJSON->valuestring == NULL)) {
        return 0;
    }
    return sharing_type_sharing_type_FromString(sharing_typeJSON->valuestring);
}
