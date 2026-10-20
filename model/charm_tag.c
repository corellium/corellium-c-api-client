#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "charm_tag.h"


char* charm_tag_charm_tag_ToString(corellium_api_charm_tag__e charm_tag) {
    char *charm_tagArray[] =  { "NULL", "kalloc", "gpu", "no-keyboard", "nodevmode", "sep-cons-ext", "iboot-jailbreak", "llb-jailbreak", "rom-jailbreak", "noappaslr", "nodyldaslr", "objdetect" };
    return charm_tagArray[charm_tag];
}

corellium_api_charm_tag__e charm_tag_charm_tag_FromString(char* charm_tag) {
    int stringToReturn = 0;
    char *charm_tagArray[] =  { "NULL", "kalloc", "gpu", "no-keyboard", "nodevmode", "sep-cons-ext", "iboot-jailbreak", "llb-jailbreak", "rom-jailbreak", "noappaslr", "nodyldaslr", "objdetect" };
    size_t sizeofArray = sizeof(charm_tagArray) / sizeof(charm_tagArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(charm_tag, charm_tagArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *charm_tag_convertToJSON(corellium_api_charm_tag__e charm_tag) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "charm_tag", charm_tag_charm_tag_ToString(charm_tag)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

corellium_api_charm_tag__e charm_tag_parseFromJSON(cJSON *charm_tagJSON) {
    if(!cJSON_IsString(charm_tagJSON) || (charm_tagJSON->valuestring == NULL)) {
        return 0;
    }
    return charm_tag_charm_tag_FromString(charm_tagJSON->valuestring);
}
