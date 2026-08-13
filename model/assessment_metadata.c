#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "assessment_metadata.h"



static assessment_metadata_t *assessment_metadata_create_internal(
    char *corellium_version
    ) {
    assessment_metadata_t *assessment_metadata_local_var = malloc(sizeof(assessment_metadata_t));
    if (!assessment_metadata_local_var) {
        return NULL;
    }
    assessment_metadata_local_var->corellium_version = corellium_version;

    assessment_metadata_local_var->_library_owned = 1;
    return assessment_metadata_local_var;
}

__attribute__((deprecated)) assessment_metadata_t *assessment_metadata_create(
    char *corellium_version
    ) {
    return assessment_metadata_create_internal (
        corellium_version
        );
}

void assessment_metadata_free(assessment_metadata_t *assessment_metadata) {
    if(NULL == assessment_metadata){
        return ;
    }
    if(assessment_metadata->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "assessment_metadata_free");
        return ;
    }
    listEntry_t *listEntry;
    if (assessment_metadata->corellium_version) {
        free(assessment_metadata->corellium_version);
        assessment_metadata->corellium_version = NULL;
    }
    free(assessment_metadata);
}

cJSON *assessment_metadata_convertToJSON(assessment_metadata_t *assessment_metadata) {
    cJSON *item = cJSON_CreateObject();

    // assessment_metadata->corellium_version
    if(assessment_metadata->corellium_version) {
    if(cJSON_AddStringToObject(item, "corelliumVersion", assessment_metadata->corellium_version) == NULL) {
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

assessment_metadata_t *assessment_metadata_parseFromJSON(cJSON *assessment_metadataJSON){

    assessment_metadata_t *assessment_metadata_local_var = NULL;

    // assessment_metadata->corellium_version
    cJSON *corellium_version = cJSON_GetObjectItemCaseSensitive(assessment_metadataJSON, "corelliumVersion");
    if (cJSON_IsNull(corellium_version)) {
        corellium_version = NULL;
    }
    if (corellium_version) { 
    if(!cJSON_IsString(corellium_version) && !cJSON_IsNull(corellium_version))
    {
    goto end; //String
    }
    }


    assessment_metadata_local_var = assessment_metadata_create_internal (
        corellium_version && !cJSON_IsNull(corellium_version) ? strdup(corellium_version->valuestring) : NULL
        );

    return assessment_metadata_local_var;
end:
    return NULL;

}
