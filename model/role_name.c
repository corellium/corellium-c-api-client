#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "role_name.h"


char* role_name_role_name_ToString(corellium_api_role_name__e role_name) {
    char *role_nameArray[] =  { "NULL", "admin", "member" };
    return role_nameArray[role_name];
}

corellium_api_role_name__e role_name_role_name_FromString(char* role_name) {
    int stringToReturn = 0;
    char *role_nameArray[] =  { "NULL", "admin", "member" };
    size_t sizeofArray = sizeof(role_nameArray) / sizeof(role_nameArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(role_name, role_nameArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *role_name_convertToJSON(corellium_api_role_name__e role_name) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "role_name", role_name_role_name_ToString(role_name)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

corellium_api_role_name__e role_name_parseFromJSON(cJSON *role_nameJSON) {
    if(!cJSON_IsString(role_nameJSON) || (role_nameJSON->valuestring == NULL)) {
        return 0;
    }
    return role_name_role_name_FromString(role_nameJSON->valuestring);
}
