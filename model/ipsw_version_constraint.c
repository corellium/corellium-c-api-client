#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ipsw_version_constraint.h"



static ipsw_version_constraint_t *ipsw_version_constraint_create_internal(
    char *lt,
    char *le,
    char *gt,
    char *ge,
    char *eq
    ) {
    ipsw_version_constraint_t *ipsw_version_constraint_local_var = malloc(sizeof(ipsw_version_constraint_t));
    if (!ipsw_version_constraint_local_var) {
        return NULL;
    }
    ipsw_version_constraint_local_var->lt = lt;
    ipsw_version_constraint_local_var->le = le;
    ipsw_version_constraint_local_var->gt = gt;
    ipsw_version_constraint_local_var->ge = ge;
    ipsw_version_constraint_local_var->eq = eq;

    ipsw_version_constraint_local_var->_library_owned = 1;
    return ipsw_version_constraint_local_var;
}

__attribute__((deprecated)) ipsw_version_constraint_t *ipsw_version_constraint_create(
    char *lt,
    char *le,
    char *gt,
    char *ge,
    char *eq
    ) {
    return ipsw_version_constraint_create_internal (
        lt,
        le,
        gt,
        ge,
        eq
        );
}

void ipsw_version_constraint_free(ipsw_version_constraint_t *ipsw_version_constraint) {
    if(NULL == ipsw_version_constraint){
        return ;
    }
    if(ipsw_version_constraint->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ipsw_version_constraint_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ipsw_version_constraint->lt) {
        free(ipsw_version_constraint->lt);
        ipsw_version_constraint->lt = NULL;
    }
    if (ipsw_version_constraint->le) {
        free(ipsw_version_constraint->le);
        ipsw_version_constraint->le = NULL;
    }
    if (ipsw_version_constraint->gt) {
        free(ipsw_version_constraint->gt);
        ipsw_version_constraint->gt = NULL;
    }
    if (ipsw_version_constraint->ge) {
        free(ipsw_version_constraint->ge);
        ipsw_version_constraint->ge = NULL;
    }
    if (ipsw_version_constraint->eq) {
        free(ipsw_version_constraint->eq);
        ipsw_version_constraint->eq = NULL;
    }
    free(ipsw_version_constraint);
}

cJSON *ipsw_version_constraint_convertToJSON(ipsw_version_constraint_t *ipsw_version_constraint) {
    cJSON *item = cJSON_CreateObject();

    // ipsw_version_constraint->lt
    if(ipsw_version_constraint->lt) {
    if(cJSON_AddStringToObject(item, "lt", ipsw_version_constraint->lt) == NULL) {
    goto fail; //String
    }
    }


    // ipsw_version_constraint->le
    if(ipsw_version_constraint->le) {
    if(cJSON_AddStringToObject(item, "le", ipsw_version_constraint->le) == NULL) {
    goto fail; //String
    }
    }


    // ipsw_version_constraint->gt
    if(ipsw_version_constraint->gt) {
    if(cJSON_AddStringToObject(item, "gt", ipsw_version_constraint->gt) == NULL) {
    goto fail; //String
    }
    }


    // ipsw_version_constraint->ge
    if(ipsw_version_constraint->ge) {
    if(cJSON_AddStringToObject(item, "ge", ipsw_version_constraint->ge) == NULL) {
    goto fail; //String
    }
    }


    // ipsw_version_constraint->eq
    if(ipsw_version_constraint->eq) {
    if(cJSON_AddStringToObject(item, "eq", ipsw_version_constraint->eq) == NULL) {
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

ipsw_version_constraint_t *ipsw_version_constraint_parseFromJSON(cJSON *ipsw_version_constraintJSON){

    ipsw_version_constraint_t *ipsw_version_constraint_local_var = NULL;

    // ipsw_version_constraint->lt
    cJSON *lt = cJSON_GetObjectItemCaseSensitive(ipsw_version_constraintJSON, "lt");
    if (cJSON_IsNull(lt)) {
        lt = NULL;
    }
    if (lt) { 
    if(!cJSON_IsString(lt) && !cJSON_IsNull(lt))
    {
    goto end; //String
    }
    }

    // ipsw_version_constraint->le
    cJSON *le = cJSON_GetObjectItemCaseSensitive(ipsw_version_constraintJSON, "le");
    if (cJSON_IsNull(le)) {
        le = NULL;
    }
    if (le) { 
    if(!cJSON_IsString(le) && !cJSON_IsNull(le))
    {
    goto end; //String
    }
    }

    // ipsw_version_constraint->gt
    cJSON *gt = cJSON_GetObjectItemCaseSensitive(ipsw_version_constraintJSON, "gt");
    if (cJSON_IsNull(gt)) {
        gt = NULL;
    }
    if (gt) { 
    if(!cJSON_IsString(gt) && !cJSON_IsNull(gt))
    {
    goto end; //String
    }
    }

    // ipsw_version_constraint->ge
    cJSON *ge = cJSON_GetObjectItemCaseSensitive(ipsw_version_constraintJSON, "ge");
    if (cJSON_IsNull(ge)) {
        ge = NULL;
    }
    if (ge) { 
    if(!cJSON_IsString(ge) && !cJSON_IsNull(ge))
    {
    goto end; //String
    }
    }

    // ipsw_version_constraint->eq
    cJSON *eq = cJSON_GetObjectItemCaseSensitive(ipsw_version_constraintJSON, "eq");
    if (cJSON_IsNull(eq)) {
        eq = NULL;
    }
    if (eq) { 
    if(!cJSON_IsString(eq) && !cJSON_IsNull(eq))
    {
    goto end; //String
    }
    }


    ipsw_version_constraint_local_var = ipsw_version_constraint_create_internal (
        lt && !cJSON_IsNull(lt) ? strdup(lt->valuestring) : NULL,
        le && !cJSON_IsNull(le) ? strdup(le->valuestring) : NULL,
        gt && !cJSON_IsNull(gt) ? strdup(gt->valuestring) : NULL,
        ge && !cJSON_IsNull(ge) ? strdup(ge->valuestring) : NULL,
        eq && !cJSON_IsNull(eq) ? strdup(eq->valuestring) : NULL
        );

    return ipsw_version_constraint_local_var;
end:
    return NULL;

}
