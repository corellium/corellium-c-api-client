#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_config_package_config_flavor_filters_inner_filter.h"



static cluster_config_package_config_flavor_filters_inner_filter_t *cluster_config_package_config_flavor_filters_inner_filter_create_internal(
    char *license,
    char *type
    ) {
    cluster_config_package_config_flavor_filters_inner_filter_t *cluster_config_package_config_flavor_filters_inner_filter_local_var = malloc(sizeof(cluster_config_package_config_flavor_filters_inner_filter_t));
    if (!cluster_config_package_config_flavor_filters_inner_filter_local_var) {
        return NULL;
    }
    cluster_config_package_config_flavor_filters_inner_filter_local_var->license = license;
    cluster_config_package_config_flavor_filters_inner_filter_local_var->type = type;

    cluster_config_package_config_flavor_filters_inner_filter_local_var->_library_owned = 1;
    return cluster_config_package_config_flavor_filters_inner_filter_local_var;
}

__attribute__((deprecated)) cluster_config_package_config_flavor_filters_inner_filter_t *cluster_config_package_config_flavor_filters_inner_filter_create(
    char *license,
    char *type
    ) {
    return cluster_config_package_config_flavor_filters_inner_filter_create_internal (
        license,
        type
        );
}

void cluster_config_package_config_flavor_filters_inner_filter_free(cluster_config_package_config_flavor_filters_inner_filter_t *cluster_config_package_config_flavor_filters_inner_filter) {
    if(NULL == cluster_config_package_config_flavor_filters_inner_filter){
        return ;
    }
    if(cluster_config_package_config_flavor_filters_inner_filter->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_config_package_config_flavor_filters_inner_filter_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cluster_config_package_config_flavor_filters_inner_filter->license) {
        free(cluster_config_package_config_flavor_filters_inner_filter->license);
        cluster_config_package_config_flavor_filters_inner_filter->license = NULL;
    }
    if (cluster_config_package_config_flavor_filters_inner_filter->type) {
        free(cluster_config_package_config_flavor_filters_inner_filter->type);
        cluster_config_package_config_flavor_filters_inner_filter->type = NULL;
    }
    free(cluster_config_package_config_flavor_filters_inner_filter);
}

cJSON *cluster_config_package_config_flavor_filters_inner_filter_convertToJSON(cluster_config_package_config_flavor_filters_inner_filter_t *cluster_config_package_config_flavor_filters_inner_filter) {
    cJSON *item = cJSON_CreateObject();

    // cluster_config_package_config_flavor_filters_inner_filter->license
    if(cluster_config_package_config_flavor_filters_inner_filter->license) {
    if(cJSON_AddStringToObject(item, "license", cluster_config_package_config_flavor_filters_inner_filter->license) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config_package_config_flavor_filters_inner_filter->type
    if(cluster_config_package_config_flavor_filters_inner_filter->type) {
    if(cJSON_AddStringToObject(item, "type", cluster_config_package_config_flavor_filters_inner_filter->type) == NULL) {
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

cluster_config_package_config_flavor_filters_inner_filter_t *cluster_config_package_config_flavor_filters_inner_filter_parseFromJSON(cJSON *cluster_config_package_config_flavor_filters_inner_filterJSON){

    cluster_config_package_config_flavor_filters_inner_filter_t *cluster_config_package_config_flavor_filters_inner_filter_local_var = NULL;

    // cluster_config_package_config_flavor_filters_inner_filter->license
    cJSON *license = cJSON_GetObjectItemCaseSensitive(cluster_config_package_config_flavor_filters_inner_filterJSON, "license");
    if (cJSON_IsNull(license)) {
        license = NULL;
    }
    if (license) { 
    if(!cJSON_IsString(license) && !cJSON_IsNull(license))
    {
    goto end; //String
    }
    }

    // cluster_config_package_config_flavor_filters_inner_filter->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(cluster_config_package_config_flavor_filters_inner_filterJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }


    cluster_config_package_config_flavor_filters_inner_filter_local_var = cluster_config_package_config_flavor_filters_inner_filter_create_internal (
        license && !cJSON_IsNull(license) ? strdup(license->valuestring) : NULL,
        type && !cJSON_IsNull(type) ? strdup(type->valuestring) : NULL
        );

    return cluster_config_package_config_flavor_filters_inner_filter_local_var;
end:
    return NULL;

}
