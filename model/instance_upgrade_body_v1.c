#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instance_upgrade_body_v1.h"



static instance_upgrade_body_v1_t *instance_upgrade_body_v1_create_internal(
    char *os,
    char *osbuild
    ) {
    instance_upgrade_body_v1_t *instance_upgrade_body_v1_local_var = malloc(sizeof(instance_upgrade_body_v1_t));
    if (!instance_upgrade_body_v1_local_var) {
        return NULL;
    }
    instance_upgrade_body_v1_local_var->os = os;
    instance_upgrade_body_v1_local_var->osbuild = osbuild;

    instance_upgrade_body_v1_local_var->_library_owned = 1;
    return instance_upgrade_body_v1_local_var;
}

__attribute__((deprecated)) instance_upgrade_body_v1_t *instance_upgrade_body_v1_create(
    char *os,
    char *osbuild
    ) {
    return instance_upgrade_body_v1_create_internal (
        os,
        osbuild
        );
}

void instance_upgrade_body_v1_free(instance_upgrade_body_v1_t *instance_upgrade_body_v1) {
    if(NULL == instance_upgrade_body_v1){
        return ;
    }
    if(instance_upgrade_body_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "instance_upgrade_body_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (instance_upgrade_body_v1->os) {
        free(instance_upgrade_body_v1->os);
        instance_upgrade_body_v1->os = NULL;
    }
    if (instance_upgrade_body_v1->osbuild) {
        free(instance_upgrade_body_v1->osbuild);
        instance_upgrade_body_v1->osbuild = NULL;
    }
    free(instance_upgrade_body_v1);
}

cJSON *instance_upgrade_body_v1_convertToJSON(instance_upgrade_body_v1_t *instance_upgrade_body_v1) {
    cJSON *item = cJSON_CreateObject();

    // instance_upgrade_body_v1->os
    if (!instance_upgrade_body_v1->os) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "os", instance_upgrade_body_v1->os) == NULL) {
    goto fail; //String
    }


    // instance_upgrade_body_v1->osbuild
    if(instance_upgrade_body_v1->osbuild) {
    if(cJSON_AddStringToObject(item, "osbuild", instance_upgrade_body_v1->osbuild) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

instance_upgrade_body_v1_t *instance_upgrade_body_v1_parseFromJSON(cJSON *instance_upgrade_body_v1JSON){

    instance_upgrade_body_v1_t *instance_upgrade_body_v1_local_var = NULL;

    // instance_upgrade_body_v1->os
    cJSON *os = cJSON_GetObjectItemCaseSensitive(instance_upgrade_body_v1JSON, "os");
    if (cJSON_IsNull(os)) {
        os = NULL;
    }
    if (!os) {
        goto end;
    }

    
    if(!cJSON_IsString(os))
    {
    goto end; //String
    }

    // instance_upgrade_body_v1->osbuild
    cJSON *osbuild = cJSON_GetObjectItemCaseSensitive(instance_upgrade_body_v1JSON, "osbuild");
    if (cJSON_IsNull(osbuild)) {
        osbuild = NULL;
    }
    if (osbuild) { 
    if(!cJSON_IsString(osbuild) && !cJSON_IsNull(osbuild))
    {
    goto end; //String
    }
    }


    instance_upgrade_body_v1_local_var = instance_upgrade_body_v1_create_internal (
        strdup(os->valuestring),
        osbuild && !cJSON_IsNull(osbuild) ? strdup(osbuild->valuestring) : NULL
        );

    return instance_upgrade_body_v1_local_var;
end:
    return NULL;

}
