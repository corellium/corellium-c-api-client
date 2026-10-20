#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_config_coordinator_config_ensure_domain_properties.h"



static cluster_config_coordinator_config_ensure_domain_properties_t *cluster_config_coordinator_config_ensure_domain_properties_create_internal(
    char *license_type,
    int android,
    int no_ios
    ) {
    cluster_config_coordinator_config_ensure_domain_properties_t *cluster_config_coordinator_config_ensure_domain_properties_local_var = malloc(sizeof(cluster_config_coordinator_config_ensure_domain_properties_t));
    if (!cluster_config_coordinator_config_ensure_domain_properties_local_var) {
        return NULL;
    }
    cluster_config_coordinator_config_ensure_domain_properties_local_var->license_type = license_type;
    cluster_config_coordinator_config_ensure_domain_properties_local_var->android = android;
    cluster_config_coordinator_config_ensure_domain_properties_local_var->no_ios = no_ios;

    cluster_config_coordinator_config_ensure_domain_properties_local_var->_library_owned = 1;
    return cluster_config_coordinator_config_ensure_domain_properties_local_var;
}

__attribute__((deprecated)) cluster_config_coordinator_config_ensure_domain_properties_t *cluster_config_coordinator_config_ensure_domain_properties_create(
    char *license_type,
    int android,
    int no_ios
    ) {
    return cluster_config_coordinator_config_ensure_domain_properties_create_internal (
        license_type,
        android,
        no_ios
        );
}

void cluster_config_coordinator_config_ensure_domain_properties_free(cluster_config_coordinator_config_ensure_domain_properties_t *cluster_config_coordinator_config_ensure_domain_properties) {
    if(NULL == cluster_config_coordinator_config_ensure_domain_properties){
        return ;
    }
    if(cluster_config_coordinator_config_ensure_domain_properties->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_config_coordinator_config_ensure_domain_properties_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cluster_config_coordinator_config_ensure_domain_properties->license_type) {
        free(cluster_config_coordinator_config_ensure_domain_properties->license_type);
        cluster_config_coordinator_config_ensure_domain_properties->license_type = NULL;
    }
    free(cluster_config_coordinator_config_ensure_domain_properties);
}

cJSON *cluster_config_coordinator_config_ensure_domain_properties_convertToJSON(cluster_config_coordinator_config_ensure_domain_properties_t *cluster_config_coordinator_config_ensure_domain_properties) {
    cJSON *item = cJSON_CreateObject();

    // cluster_config_coordinator_config_ensure_domain_properties->license_type
    if (!cluster_config_coordinator_config_ensure_domain_properties->license_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "licenseType", cluster_config_coordinator_config_ensure_domain_properties->license_type) == NULL) {
    goto fail; //String
    }


    // cluster_config_coordinator_config_ensure_domain_properties->android
    if (!cluster_config_coordinator_config_ensure_domain_properties->android) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "android", cluster_config_coordinator_config_ensure_domain_properties->android) == NULL) {
    goto fail; //Bool
    }


    // cluster_config_coordinator_config_ensure_domain_properties->no_ios
    if (!cluster_config_coordinator_config_ensure_domain_properties->no_ios) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "noIOS", cluster_config_coordinator_config_ensure_domain_properties->no_ios) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

cluster_config_coordinator_config_ensure_domain_properties_t *cluster_config_coordinator_config_ensure_domain_properties_parseFromJSON(cJSON *cluster_config_coordinator_config_ensure_domain_propertiesJSON){

    cluster_config_coordinator_config_ensure_domain_properties_t *cluster_config_coordinator_config_ensure_domain_properties_local_var = NULL;

    // cluster_config_coordinator_config_ensure_domain_properties->license_type
    cJSON *license_type = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_config_ensure_domain_propertiesJSON, "licenseType");
    if (cJSON_IsNull(license_type)) {
        license_type = NULL;
    }
    if (!license_type) {
        goto end;
    }

    
    if(!cJSON_IsString(license_type))
    {
    goto end; //String
    }

    // cluster_config_coordinator_config_ensure_domain_properties->android
    cJSON *android = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_config_ensure_domain_propertiesJSON, "android");
    if (cJSON_IsNull(android)) {
        android = NULL;
    }
    if (!android) {
        goto end;
    }

    
    if(!cJSON_IsBool(android))
    {
    goto end; //Bool
    }

    // cluster_config_coordinator_config_ensure_domain_properties->no_ios
    cJSON *no_ios = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_config_ensure_domain_propertiesJSON, "noIOS");
    if (cJSON_IsNull(no_ios)) {
        no_ios = NULL;
    }
    if (!no_ios) {
        goto end;
    }

    
    if(!cJSON_IsBool(no_ios))
    {
    goto end; //Bool
    }


    cluster_config_coordinator_config_ensure_domain_properties_local_var = cluster_config_coordinator_config_ensure_domain_properties_create_internal (
        strdup(license_type->valuestring),
        android->valueint,
        no_ios->valueint
        );

    return cluster_config_coordinator_config_ensure_domain_properties_local_var;
end:
    return NULL;

}
