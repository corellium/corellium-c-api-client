#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_config_package_config_flavor_filters_inner.h"



static cluster_config_package_config_flavor_filters_inner_t *cluster_config_package_config_flavor_filters_inner_create_internal(
    cluster_config_package_config_flavor_filters_inner_filter_t *filter,
    cluster_config_package_config_flavor_filters_inner_apply_t *apply
    ) {
    cluster_config_package_config_flavor_filters_inner_t *cluster_config_package_config_flavor_filters_inner_local_var = malloc(sizeof(cluster_config_package_config_flavor_filters_inner_t));
    if (!cluster_config_package_config_flavor_filters_inner_local_var) {
        return NULL;
    }
    cluster_config_package_config_flavor_filters_inner_local_var->filter = filter;
    cluster_config_package_config_flavor_filters_inner_local_var->apply = apply;

    cluster_config_package_config_flavor_filters_inner_local_var->_library_owned = 1;
    return cluster_config_package_config_flavor_filters_inner_local_var;
}

__attribute__((deprecated)) cluster_config_package_config_flavor_filters_inner_t *cluster_config_package_config_flavor_filters_inner_create(
    cluster_config_package_config_flavor_filters_inner_filter_t *filter,
    cluster_config_package_config_flavor_filters_inner_apply_t *apply
    ) {
    return cluster_config_package_config_flavor_filters_inner_create_internal (
        filter,
        apply
        );
}

void cluster_config_package_config_flavor_filters_inner_free(cluster_config_package_config_flavor_filters_inner_t *cluster_config_package_config_flavor_filters_inner) {
    if(NULL == cluster_config_package_config_flavor_filters_inner){
        return ;
    }
    if(cluster_config_package_config_flavor_filters_inner->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_config_package_config_flavor_filters_inner_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cluster_config_package_config_flavor_filters_inner->filter) {
        cluster_config_package_config_flavor_filters_inner_filter_free(cluster_config_package_config_flavor_filters_inner->filter);
        cluster_config_package_config_flavor_filters_inner->filter = NULL;
    }
    if (cluster_config_package_config_flavor_filters_inner->apply) {
        cluster_config_package_config_flavor_filters_inner_apply_free(cluster_config_package_config_flavor_filters_inner->apply);
        cluster_config_package_config_flavor_filters_inner->apply = NULL;
    }
    free(cluster_config_package_config_flavor_filters_inner);
}

cJSON *cluster_config_package_config_flavor_filters_inner_convertToJSON(cluster_config_package_config_flavor_filters_inner_t *cluster_config_package_config_flavor_filters_inner) {
    cJSON *item = cJSON_CreateObject();

    // cluster_config_package_config_flavor_filters_inner->filter
    if(cluster_config_package_config_flavor_filters_inner->filter) {
    cJSON *filter_local_JSON = cluster_config_package_config_flavor_filters_inner_filter_convertToJSON(cluster_config_package_config_flavor_filters_inner->filter);
    if(filter_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "filter", filter_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // cluster_config_package_config_flavor_filters_inner->apply
    if(cluster_config_package_config_flavor_filters_inner->apply) {
    cJSON *apply_local_JSON = cluster_config_package_config_flavor_filters_inner_apply_convertToJSON(cluster_config_package_config_flavor_filters_inner->apply);
    if(apply_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "apply", apply_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

cluster_config_package_config_flavor_filters_inner_t *cluster_config_package_config_flavor_filters_inner_parseFromJSON(cJSON *cluster_config_package_config_flavor_filters_innerJSON){

    cluster_config_package_config_flavor_filters_inner_t *cluster_config_package_config_flavor_filters_inner_local_var = NULL;

    // define the local variable for cluster_config_package_config_flavor_filters_inner->filter
    cluster_config_package_config_flavor_filters_inner_filter_t *filter_local_nonprim = NULL;

    // define the local variable for cluster_config_package_config_flavor_filters_inner->apply
    cluster_config_package_config_flavor_filters_inner_apply_t *apply_local_nonprim = NULL;

    // cluster_config_package_config_flavor_filters_inner->filter
    cJSON *filter = cJSON_GetObjectItemCaseSensitive(cluster_config_package_config_flavor_filters_innerJSON, "filter");
    if (cJSON_IsNull(filter)) {
        filter = NULL;
    }
    if (filter) { 
    filter_local_nonprim = cluster_config_package_config_flavor_filters_inner_filter_parseFromJSON(filter); //nonprimitive
    }

    // cluster_config_package_config_flavor_filters_inner->apply
    cJSON *apply = cJSON_GetObjectItemCaseSensitive(cluster_config_package_config_flavor_filters_innerJSON, "apply");
    if (cJSON_IsNull(apply)) {
        apply = NULL;
    }
    if (apply) { 
    apply_local_nonprim = cluster_config_package_config_flavor_filters_inner_apply_parseFromJSON(apply); //nonprimitive
    }


    cluster_config_package_config_flavor_filters_inner_local_var = cluster_config_package_config_flavor_filters_inner_create_internal (
        filter ? filter_local_nonprim : NULL,
        apply ? apply_local_nonprim : NULL
        );

    return cluster_config_package_config_flavor_filters_inner_local_var;
end:
    if (filter_local_nonprim) {
        cluster_config_package_config_flavor_filters_inner_filter_free(filter_local_nonprim);
        filter_local_nonprim = NULL;
    }
    if (apply_local_nonprim) {
        cluster_config_package_config_flavor_filters_inner_apply_free(apply_local_nonprim);
        apply_local_nonprim = NULL;
    }
    return NULL;

}
