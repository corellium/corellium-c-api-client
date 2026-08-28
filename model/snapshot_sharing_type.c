#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "snapshot_sharing_type.h"


char* snapshot_sharing_type_snapshot_sharing_type_ToString(corellium_api_snapshot_sharing_type__e snapshot_sharing_type) {
    char *snapshot_sharing_typeArray[] =  { "NULL", "publicLink", "domainRestrictedLink", "passwordPublicLink", "emailInvite", "notShared" };
    return snapshot_sharing_typeArray[snapshot_sharing_type];
}

corellium_api_snapshot_sharing_type__e snapshot_sharing_type_snapshot_sharing_type_FromString(char* snapshot_sharing_type) {
    int stringToReturn = 0;
    char *snapshot_sharing_typeArray[] =  { "NULL", "publicLink", "domainRestrictedLink", "passwordPublicLink", "emailInvite", "notShared" };
    size_t sizeofArray = sizeof(snapshot_sharing_typeArray) / sizeof(snapshot_sharing_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(snapshot_sharing_type, snapshot_sharing_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *snapshot_sharing_type_convertToJSON(corellium_api_snapshot_sharing_type__e snapshot_sharing_type) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "snapshot_sharing_type", snapshot_sharing_type_snapshot_sharing_type_ToString(snapshot_sharing_type)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

corellium_api_snapshot_sharing_type__e snapshot_sharing_type_parseFromJSON(cJSON *snapshot_sharing_typeJSON) {
    if(!cJSON_IsString(snapshot_sharing_typeJSON) || (snapshot_sharing_typeJSON->valuestring == NULL)) {
        return 0;
    }
    return snapshot_sharing_type_snapshot_sharing_type_FromString(snapshot_sharing_typeJSON->valuestring);
}
