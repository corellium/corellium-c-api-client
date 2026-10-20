#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ipsw_filter_v3_version.h"



static ipsw_filter_v3_version_t *ipsw_filter_v3_version_create_internal(
    char *lt,
    char *le,
    char *gt,
    char *ge,
    char *eq
    ) {
    ipsw_filter_v3_version_t *ipsw_filter_v3_version_local_var = malloc(sizeof(ipsw_filter_v3_version_t));
    if (!ipsw_filter_v3_version_local_var) {
        return NULL;
    }
    ipsw_filter_v3_version_local_var->lt = lt;
    ipsw_filter_v3_version_local_var->le = le;
    ipsw_filter_v3_version_local_var->gt = gt;
    ipsw_filter_v3_version_local_var->ge = ge;
    ipsw_filter_v3_version_local_var->eq = eq;

    ipsw_filter_v3_version_local_var->_library_owned = 1;
    return ipsw_filter_v3_version_local_var;
}

__attribute__((deprecated)) ipsw_filter_v3_version_t *ipsw_filter_v3_version_create(
    char *lt,
    char *le,
    char *gt,
    char *ge,
    char *eq
    ) {
    return ipsw_filter_v3_version_create_internal (
        lt,
        le,
        gt,
        ge,
        eq
        );
}

void ipsw_filter_v3_version_free(ipsw_filter_v3_version_t *ipsw_filter_v3_version) {
    if(NULL == ipsw_filter_v3_version){
        return ;
    }
    if(ipsw_filter_v3_version->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ipsw_filter_v3_version_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ipsw_filter_v3_version->lt) {
        free(ipsw_filter_v3_version->lt);
        ipsw_filter_v3_version->lt = NULL;
    }
    if (ipsw_filter_v3_version->le) {
        free(ipsw_filter_v3_version->le);
        ipsw_filter_v3_version->le = NULL;
    }
    if (ipsw_filter_v3_version->gt) {
        free(ipsw_filter_v3_version->gt);
        ipsw_filter_v3_version->gt = NULL;
    }
    if (ipsw_filter_v3_version->ge) {
        free(ipsw_filter_v3_version->ge);
        ipsw_filter_v3_version->ge = NULL;
    }
    if (ipsw_filter_v3_version->eq) {
        free(ipsw_filter_v3_version->eq);
        ipsw_filter_v3_version->eq = NULL;
    }
    free(ipsw_filter_v3_version);
}

cJSON *ipsw_filter_v3_version_convertToJSON(ipsw_filter_v3_version_t *ipsw_filter_v3_version) {
    cJSON *item = cJSON_CreateObject();

    // ipsw_filter_v3_version->lt
    if(ipsw_filter_v3_version->lt) {
    if(cJSON_AddStringToObject(item, "lt", ipsw_filter_v3_version->lt) == NULL) {
    goto fail; //String
    }
    }


    // ipsw_filter_v3_version->le
    if(ipsw_filter_v3_version->le) {
    if(cJSON_AddStringToObject(item, "le", ipsw_filter_v3_version->le) == NULL) {
    goto fail; //String
    }
    }


    // ipsw_filter_v3_version->gt
    if(ipsw_filter_v3_version->gt) {
    if(cJSON_AddStringToObject(item, "gt", ipsw_filter_v3_version->gt) == NULL) {
    goto fail; //String
    }
    }


    // ipsw_filter_v3_version->ge
    if(ipsw_filter_v3_version->ge) {
    if(cJSON_AddStringToObject(item, "ge", ipsw_filter_v3_version->ge) == NULL) {
    goto fail; //String
    }
    }


    // ipsw_filter_v3_version->eq
    if(ipsw_filter_v3_version->eq) {
    if(cJSON_AddStringToObject(item, "eq", ipsw_filter_v3_version->eq) == NULL) {
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

ipsw_filter_v3_version_t *ipsw_filter_v3_version_parseFromJSON(cJSON *ipsw_filter_v3_versionJSON){

    ipsw_filter_v3_version_t *ipsw_filter_v3_version_local_var = NULL;

    // ipsw_filter_v3_version->lt
    cJSON *lt = cJSON_GetObjectItemCaseSensitive(ipsw_filter_v3_versionJSON, "lt");
    if (cJSON_IsNull(lt)) {
        lt = NULL;
    }
    if (lt) { 
    if(!cJSON_IsString(lt) && !cJSON_IsNull(lt))
    {
    goto end; //String
    }
    }

    // ipsw_filter_v3_version->le
    cJSON *le = cJSON_GetObjectItemCaseSensitive(ipsw_filter_v3_versionJSON, "le");
    if (cJSON_IsNull(le)) {
        le = NULL;
    }
    if (le) { 
    if(!cJSON_IsString(le) && !cJSON_IsNull(le))
    {
    goto end; //String
    }
    }

    // ipsw_filter_v3_version->gt
    cJSON *gt = cJSON_GetObjectItemCaseSensitive(ipsw_filter_v3_versionJSON, "gt");
    if (cJSON_IsNull(gt)) {
        gt = NULL;
    }
    if (gt) { 
    if(!cJSON_IsString(gt) && !cJSON_IsNull(gt))
    {
    goto end; //String
    }
    }

    // ipsw_filter_v3_version->ge
    cJSON *ge = cJSON_GetObjectItemCaseSensitive(ipsw_filter_v3_versionJSON, "ge");
    if (cJSON_IsNull(ge)) {
        ge = NULL;
    }
    if (ge) { 
    if(!cJSON_IsString(ge) && !cJSON_IsNull(ge))
    {
    goto end; //String
    }
    }

    // ipsw_filter_v3_version->eq
    cJSON *eq = cJSON_GetObjectItemCaseSensitive(ipsw_filter_v3_versionJSON, "eq");
    if (cJSON_IsNull(eq)) {
        eq = NULL;
    }
    if (eq) { 
    if(!cJSON_IsString(eq) && !cJSON_IsNull(eq))
    {
    goto end; //String
    }
    }


    ipsw_filter_v3_version_local_var = ipsw_filter_v3_version_create_internal (
        lt && !cJSON_IsNull(lt) ? strdup(lt->valuestring) : NULL,
        le && !cJSON_IsNull(le) ? strdup(le->valuestring) : NULL,
        gt && !cJSON_IsNull(gt) ? strdup(gt->valuestring) : NULL,
        ge && !cJSON_IsNull(ge) ? strdup(ge->valuestring) : NULL,
        eq && !cJSON_IsNull(eq) ? strdup(eq->valuestring) : NULL
        );

    return ipsw_filter_v3_version_local_var;
end:
    return NULL;

}
