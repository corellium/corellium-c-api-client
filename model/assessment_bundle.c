#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "assessment_bundle.h"



static assessment_bundle_t *assessment_bundle_create_internal(
    char *id,
    char *name,
    char *version
    ) {
    assessment_bundle_t *assessment_bundle_local_var = malloc(sizeof(assessment_bundle_t));
    if (!assessment_bundle_local_var) {
        return NULL;
    }
    assessment_bundle_local_var->id = id;
    assessment_bundle_local_var->name = name;
    assessment_bundle_local_var->version = version;

    assessment_bundle_local_var->_library_owned = 1;
    return assessment_bundle_local_var;
}

__attribute__((deprecated)) assessment_bundle_t *assessment_bundle_create(
    char *id,
    char *name,
    char *version
    ) {
    return assessment_bundle_create_internal (
        id,
        name,
        version
        );
}

void assessment_bundle_free(assessment_bundle_t *assessment_bundle) {
    if(NULL == assessment_bundle){
        return ;
    }
    if(assessment_bundle->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "assessment_bundle_free");
        return ;
    }
    listEntry_t *listEntry;
    if (assessment_bundle->id) {
        free(assessment_bundle->id);
        assessment_bundle->id = NULL;
    }
    if (assessment_bundle->name) {
        free(assessment_bundle->name);
        assessment_bundle->name = NULL;
    }
    if (assessment_bundle->version) {
        free(assessment_bundle->version);
        assessment_bundle->version = NULL;
    }
    free(assessment_bundle);
}

cJSON *assessment_bundle_convertToJSON(assessment_bundle_t *assessment_bundle) {
    cJSON *item = cJSON_CreateObject();

    // assessment_bundle->id
    if (!assessment_bundle->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", assessment_bundle->id) == NULL) {
    goto fail; //String
    }


    // assessment_bundle->name
    if (!assessment_bundle->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", assessment_bundle->name) == NULL) {
    goto fail; //String
    }


    // assessment_bundle->version
    if (!assessment_bundle->version) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "version", assessment_bundle->version) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

assessment_bundle_t *assessment_bundle_parseFromJSON(cJSON *assessment_bundleJSON){

    assessment_bundle_t *assessment_bundle_local_var = NULL;

    // assessment_bundle->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(assessment_bundleJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // assessment_bundle->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(assessment_bundleJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // assessment_bundle->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(assessment_bundleJSON, "version");
    if (cJSON_IsNull(version)) {
        version = NULL;
    }
    if (!version) {
        goto end;
    }

    
    if(!cJSON_IsString(version))
    {
    goto end; //String
    }


    assessment_bundle_local_var = assessment_bundle_create_internal (
        strdup(id->valuestring),
        strdup(name->valuestring),
        strdup(version->valuestring)
        );

    return assessment_bundle_local_var;
end:
    return NULL;

}
