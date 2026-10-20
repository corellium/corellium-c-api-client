#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "deployment_version.h"



static deployment_version_t *deployment_version_create_internal(
    char *product_version,
    char *coordinator_version,
    char *build_commit,
    char *build_date
    ) {
    deployment_version_t *deployment_version_local_var = malloc(sizeof(deployment_version_t));
    if (!deployment_version_local_var) {
        return NULL;
    }
    deployment_version_local_var->product_version = product_version;
    deployment_version_local_var->coordinator_version = coordinator_version;
    deployment_version_local_var->build_commit = build_commit;
    deployment_version_local_var->build_date = build_date;

    deployment_version_local_var->_library_owned = 1;
    return deployment_version_local_var;
}

__attribute__((deprecated)) deployment_version_t *deployment_version_create(
    char *product_version,
    char *coordinator_version,
    char *build_commit,
    char *build_date
    ) {
    return deployment_version_create_internal (
        product_version,
        coordinator_version,
        build_commit,
        build_date
        );
}

void deployment_version_free(deployment_version_t *deployment_version) {
    if(NULL == deployment_version){
        return ;
    }
    if(deployment_version->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "deployment_version_free");
        return ;
    }
    listEntry_t *listEntry;
    if (deployment_version->product_version) {
        free(deployment_version->product_version);
        deployment_version->product_version = NULL;
    }
    if (deployment_version->coordinator_version) {
        free(deployment_version->coordinator_version);
        deployment_version->coordinator_version = NULL;
    }
    if (deployment_version->build_commit) {
        free(deployment_version->build_commit);
        deployment_version->build_commit = NULL;
    }
    if (deployment_version->build_date) {
        free(deployment_version->build_date);
        deployment_version->build_date = NULL;
    }
    free(deployment_version);
}

cJSON *deployment_version_convertToJSON(deployment_version_t *deployment_version) {
    cJSON *item = cJSON_CreateObject();

    // deployment_version->product_version
    if (!deployment_version->product_version) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "productVersion", deployment_version->product_version) == NULL) {
    goto fail; //String
    }


    // deployment_version->coordinator_version
    if(deployment_version->coordinator_version) {
    if(cJSON_AddStringToObject(item, "coordinatorVersion", deployment_version->coordinator_version) == NULL) {
    goto fail; //String
    }
    }


    // deployment_version->build_commit
    if(deployment_version->build_commit) {
    if(cJSON_AddStringToObject(item, "buildCommit", deployment_version->build_commit) == NULL) {
    goto fail; //String
    }
    }


    // deployment_version->build_date
    if(deployment_version->build_date) {
    if(cJSON_AddStringToObject(item, "buildDate", deployment_version->build_date) == NULL) {
    goto fail; //Date-Time
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

deployment_version_t *deployment_version_parseFromJSON(cJSON *deployment_versionJSON){

    deployment_version_t *deployment_version_local_var = NULL;

    // deployment_version->product_version
    cJSON *product_version = cJSON_GetObjectItemCaseSensitive(deployment_versionJSON, "productVersion");
    if (cJSON_IsNull(product_version)) {
        product_version = NULL;
    }
    if (!product_version) {
        goto end;
    }

    
    if(!cJSON_IsString(product_version))
    {
    goto end; //String
    }

    // deployment_version->coordinator_version
    cJSON *coordinator_version = cJSON_GetObjectItemCaseSensitive(deployment_versionJSON, "coordinatorVersion");
    if (cJSON_IsNull(coordinator_version)) {
        coordinator_version = NULL;
    }
    if (coordinator_version) { 
    if(!cJSON_IsString(coordinator_version) && !cJSON_IsNull(coordinator_version))
    {
    goto end; //String
    }
    }

    // deployment_version->build_commit
    cJSON *build_commit = cJSON_GetObjectItemCaseSensitive(deployment_versionJSON, "buildCommit");
    if (cJSON_IsNull(build_commit)) {
        build_commit = NULL;
    }
    if (build_commit) { 
    if(!cJSON_IsString(build_commit) && !cJSON_IsNull(build_commit))
    {
    goto end; //String
    }
    }

    // deployment_version->build_date
    cJSON *build_date = cJSON_GetObjectItemCaseSensitive(deployment_versionJSON, "buildDate");
    if (cJSON_IsNull(build_date)) {
        build_date = NULL;
    }
    if (build_date) { 
    if(!cJSON_IsString(build_date) && !cJSON_IsNull(build_date))
    {
    goto end; //DateTime
    }
    }


    deployment_version_local_var = deployment_version_create_internal (
        strdup(product_version->valuestring),
        coordinator_version && !cJSON_IsNull(coordinator_version) ? strdup(coordinator_version->valuestring) : NULL,
        build_commit && !cJSON_IsNull(build_commit) ? strdup(build_commit->valuestring) : NULL,
        build_date && !cJSON_IsNull(build_date) ? strdup(build_date->valuestring) : NULL
        );

    return deployment_version_local_var;
end:
    return NULL;

}
