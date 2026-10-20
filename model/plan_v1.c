#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "plan_v1.h"



static plan_v1_t *plan_v1_create_internal(
    char *plan_id,
    char *name
    ) {
    plan_v1_t *plan_v1_local_var = malloc(sizeof(plan_v1_t));
    if (!plan_v1_local_var) {
        return NULL;
    }
    plan_v1_local_var->plan_id = plan_id;
    plan_v1_local_var->name = name;

    plan_v1_local_var->_library_owned = 1;
    return plan_v1_local_var;
}

__attribute__((deprecated)) plan_v1_t *plan_v1_create(
    char *plan_id,
    char *name
    ) {
    return plan_v1_create_internal (
        plan_id,
        name
        );
}

void plan_v1_free(plan_v1_t *plan_v1) {
    if(NULL == plan_v1){
        return ;
    }
    if(plan_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "plan_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (plan_v1->plan_id) {
        free(plan_v1->plan_id);
        plan_v1->plan_id = NULL;
    }
    if (plan_v1->name) {
        free(plan_v1->name);
        plan_v1->name = NULL;
    }
    free(plan_v1);
}

cJSON *plan_v1_convertToJSON(plan_v1_t *plan_v1) {
    cJSON *item = cJSON_CreateObject();

    // plan_v1->plan_id
    if(plan_v1->plan_id) {
    if(cJSON_AddStringToObject(item, "planId", plan_v1->plan_id) == NULL) {
    goto fail; //String
    }
    }


    // plan_v1->name
    if(plan_v1->name) {
    if(cJSON_AddStringToObject(item, "name", plan_v1->name) == NULL) {
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

plan_v1_t *plan_v1_parseFromJSON(cJSON *plan_v1JSON){

    plan_v1_t *plan_v1_local_var = NULL;

    // plan_v1->plan_id
    cJSON *plan_id = cJSON_GetObjectItemCaseSensitive(plan_v1JSON, "planId");
    if (cJSON_IsNull(plan_id)) {
        plan_id = NULL;
    }
    if (plan_id) { 
    if(!cJSON_IsString(plan_id) && !cJSON_IsNull(plan_id))
    {
    goto end; //String
    }
    }

    // plan_v1->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(plan_v1JSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }


    plan_v1_local_var = plan_v1_create_internal (
        plan_id && !cJSON_IsNull(plan_id) ? strdup(plan_id->valuestring) : NULL,
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL
        );

    return plan_v1_local_var;
end:
    return NULL;

}
