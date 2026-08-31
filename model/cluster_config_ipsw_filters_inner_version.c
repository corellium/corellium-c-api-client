#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_config_ipsw_filters_inner_version.h"



static cluster_config_ipsw_filters_inner_version_t *cluster_config_ipsw_filters_inner_version_create_internal(
    char *lt,
    char *gt,
    char *le,
    char *ge,
    char *eq
    ) {
    cluster_config_ipsw_filters_inner_version_t *cluster_config_ipsw_filters_inner_version_local_var = malloc(sizeof(cluster_config_ipsw_filters_inner_version_t));
    if (!cluster_config_ipsw_filters_inner_version_local_var) {
        return NULL;
    }
    cluster_config_ipsw_filters_inner_version_local_var->lt = lt;
    cluster_config_ipsw_filters_inner_version_local_var->gt = gt;
    cluster_config_ipsw_filters_inner_version_local_var->le = le;
    cluster_config_ipsw_filters_inner_version_local_var->ge = ge;
    cluster_config_ipsw_filters_inner_version_local_var->eq = eq;

    cluster_config_ipsw_filters_inner_version_local_var->_library_owned = 1;
    return cluster_config_ipsw_filters_inner_version_local_var;
}

__attribute__((deprecated)) cluster_config_ipsw_filters_inner_version_t *cluster_config_ipsw_filters_inner_version_create(
    char *lt,
    char *gt,
    char *le,
    char *ge,
    char *eq
    ) {
    return cluster_config_ipsw_filters_inner_version_create_internal (
        lt,
        gt,
        le,
        ge,
        eq
        );
}

void cluster_config_ipsw_filters_inner_version_free(cluster_config_ipsw_filters_inner_version_t *cluster_config_ipsw_filters_inner_version) {
    if(NULL == cluster_config_ipsw_filters_inner_version){
        return ;
    }
    if(cluster_config_ipsw_filters_inner_version->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_config_ipsw_filters_inner_version_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cluster_config_ipsw_filters_inner_version->lt) {
        free(cluster_config_ipsw_filters_inner_version->lt);
        cluster_config_ipsw_filters_inner_version->lt = NULL;
    }
    if (cluster_config_ipsw_filters_inner_version->gt) {
        free(cluster_config_ipsw_filters_inner_version->gt);
        cluster_config_ipsw_filters_inner_version->gt = NULL;
    }
    if (cluster_config_ipsw_filters_inner_version->le) {
        free(cluster_config_ipsw_filters_inner_version->le);
        cluster_config_ipsw_filters_inner_version->le = NULL;
    }
    if (cluster_config_ipsw_filters_inner_version->ge) {
        free(cluster_config_ipsw_filters_inner_version->ge);
        cluster_config_ipsw_filters_inner_version->ge = NULL;
    }
    if (cluster_config_ipsw_filters_inner_version->eq) {
        free(cluster_config_ipsw_filters_inner_version->eq);
        cluster_config_ipsw_filters_inner_version->eq = NULL;
    }
    free(cluster_config_ipsw_filters_inner_version);
}

cJSON *cluster_config_ipsw_filters_inner_version_convertToJSON(cluster_config_ipsw_filters_inner_version_t *cluster_config_ipsw_filters_inner_version) {
    cJSON *item = cJSON_CreateObject();

    // cluster_config_ipsw_filters_inner_version->lt
    if(cluster_config_ipsw_filters_inner_version->lt) {
    if(cJSON_AddStringToObject(item, "lt", cluster_config_ipsw_filters_inner_version->lt) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config_ipsw_filters_inner_version->gt
    if(cluster_config_ipsw_filters_inner_version->gt) {
    if(cJSON_AddStringToObject(item, "gt", cluster_config_ipsw_filters_inner_version->gt) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config_ipsw_filters_inner_version->le
    if(cluster_config_ipsw_filters_inner_version->le) {
    if(cJSON_AddStringToObject(item, "le", cluster_config_ipsw_filters_inner_version->le) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config_ipsw_filters_inner_version->ge
    if(cluster_config_ipsw_filters_inner_version->ge) {
    if(cJSON_AddStringToObject(item, "ge", cluster_config_ipsw_filters_inner_version->ge) == NULL) {
    goto fail; //String
    }
    }


    // cluster_config_ipsw_filters_inner_version->eq
    if(cluster_config_ipsw_filters_inner_version->eq) {
    if(cJSON_AddStringToObject(item, "eq", cluster_config_ipsw_filters_inner_version->eq) == NULL) {
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

cluster_config_ipsw_filters_inner_version_t *cluster_config_ipsw_filters_inner_version_parseFromJSON(cJSON *cluster_config_ipsw_filters_inner_versionJSON){

    cluster_config_ipsw_filters_inner_version_t *cluster_config_ipsw_filters_inner_version_local_var = NULL;

    // cluster_config_ipsw_filters_inner_version->lt
    cJSON *lt = cJSON_GetObjectItemCaseSensitive(cluster_config_ipsw_filters_inner_versionJSON, "lt");
    if (cJSON_IsNull(lt)) {
        lt = NULL;
    }
    if (lt) { 
    if(!cJSON_IsString(lt) && !cJSON_IsNull(lt))
    {
    goto end; //String
    }
    }

    // cluster_config_ipsw_filters_inner_version->gt
    cJSON *gt = cJSON_GetObjectItemCaseSensitive(cluster_config_ipsw_filters_inner_versionJSON, "gt");
    if (cJSON_IsNull(gt)) {
        gt = NULL;
    }
    if (gt) { 
    if(!cJSON_IsString(gt) && !cJSON_IsNull(gt))
    {
    goto end; //String
    }
    }

    // cluster_config_ipsw_filters_inner_version->le
    cJSON *le = cJSON_GetObjectItemCaseSensitive(cluster_config_ipsw_filters_inner_versionJSON, "le");
    if (cJSON_IsNull(le)) {
        le = NULL;
    }
    if (le) { 
    if(!cJSON_IsString(le) && !cJSON_IsNull(le))
    {
    goto end; //String
    }
    }

    // cluster_config_ipsw_filters_inner_version->ge
    cJSON *ge = cJSON_GetObjectItemCaseSensitive(cluster_config_ipsw_filters_inner_versionJSON, "ge");
    if (cJSON_IsNull(ge)) {
        ge = NULL;
    }
    if (ge) { 
    if(!cJSON_IsString(ge) && !cJSON_IsNull(ge))
    {
    goto end; //String
    }
    }

    // cluster_config_ipsw_filters_inner_version->eq
    cJSON *eq = cJSON_GetObjectItemCaseSensitive(cluster_config_ipsw_filters_inner_versionJSON, "eq");
    if (cJSON_IsNull(eq)) {
        eq = NULL;
    }
    if (eq) { 
    if(!cJSON_IsString(eq) && !cJSON_IsNull(eq))
    {
    goto end; //String
    }
    }


    cluster_config_ipsw_filters_inner_version_local_var = cluster_config_ipsw_filters_inner_version_create_internal (
        lt && !cJSON_IsNull(lt) ? strdup(lt->valuestring) : NULL,
        gt && !cJSON_IsNull(gt) ? strdup(gt->valuestring) : NULL,
        le && !cJSON_IsNull(le) ? strdup(le->valuestring) : NULL,
        ge && !cJSON_IsNull(ge) ? strdup(ge->valuestring) : NULL,
        eq && !cJSON_IsNull(eq) ? strdup(eq->valuestring) : NULL
        );

    return cluster_config_ipsw_filters_inner_version_local_var;
end:
    return NULL;

}
