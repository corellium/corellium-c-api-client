#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "insufficient_storage_error_v1.h"



static insufficient_storage_error_v1_t *insufficient_storage_error_v1_create_internal(
    char *error_id,
    char *error,
    double total,
    double available,
    double required
    ) {
    insufficient_storage_error_v1_t *insufficient_storage_error_v1_local_var = malloc(sizeof(insufficient_storage_error_v1_t));
    if (!insufficient_storage_error_v1_local_var) {
        return NULL;
    }
    insufficient_storage_error_v1_local_var->error_id = error_id;
    insufficient_storage_error_v1_local_var->error = error;
    insufficient_storage_error_v1_local_var->total = total;
    insufficient_storage_error_v1_local_var->available = available;
    insufficient_storage_error_v1_local_var->required = required;

    insufficient_storage_error_v1_local_var->_library_owned = 1;
    return insufficient_storage_error_v1_local_var;
}

__attribute__((deprecated)) insufficient_storage_error_v1_t *insufficient_storage_error_v1_create(
    char *error_id,
    char *error,
    double total,
    double available,
    double required
    ) {
    return insufficient_storage_error_v1_create_internal (
        error_id,
        error,
        total,
        available,
        required
        );
}

void insufficient_storage_error_v1_free(insufficient_storage_error_v1_t *insufficient_storage_error_v1) {
    if(NULL == insufficient_storage_error_v1){
        return ;
    }
    if(insufficient_storage_error_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "insufficient_storage_error_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (insufficient_storage_error_v1->error_id) {
        free(insufficient_storage_error_v1->error_id);
        insufficient_storage_error_v1->error_id = NULL;
    }
    if (insufficient_storage_error_v1->error) {
        free(insufficient_storage_error_v1->error);
        insufficient_storage_error_v1->error = NULL;
    }
    free(insufficient_storage_error_v1);
}

cJSON *insufficient_storage_error_v1_convertToJSON(insufficient_storage_error_v1_t *insufficient_storage_error_v1) {
    cJSON *item = cJSON_CreateObject();

    // insufficient_storage_error_v1->error_id
    if(insufficient_storage_error_v1->error_id) {
    if(cJSON_AddStringToObject(item, "errorID", insufficient_storage_error_v1->error_id) == NULL) {
    goto fail; //String
    }
    }


    // insufficient_storage_error_v1->error
    if(insufficient_storage_error_v1->error) {
    if(cJSON_AddStringToObject(item, "error", insufficient_storage_error_v1->error) == NULL) {
    goto fail; //String
    }
    }


    // insufficient_storage_error_v1->total
    if(insufficient_storage_error_v1->total) {
    if(cJSON_AddNumberToObject(item, "total", insufficient_storage_error_v1->total) == NULL) {
    goto fail; //Numeric
    }
    }


    // insufficient_storage_error_v1->available
    if(insufficient_storage_error_v1->available) {
    if(cJSON_AddNumberToObject(item, "available", insufficient_storage_error_v1->available) == NULL) {
    goto fail; //Numeric
    }
    }


    // insufficient_storage_error_v1->required
    if (!insufficient_storage_error_v1->required) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "required", insufficient_storage_error_v1->required) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

insufficient_storage_error_v1_t *insufficient_storage_error_v1_parseFromJSON(cJSON *insufficient_storage_error_v1JSON){

    insufficient_storage_error_v1_t *insufficient_storage_error_v1_local_var = NULL;

    // insufficient_storage_error_v1->error_id
    cJSON *error_id = cJSON_GetObjectItemCaseSensitive(insufficient_storage_error_v1JSON, "errorID");
    if (cJSON_IsNull(error_id)) {
        error_id = NULL;
    }
    if (error_id) { 
    if(!cJSON_IsString(error_id) && !cJSON_IsNull(error_id))
    {
    goto end; //String
    }
    }

    // insufficient_storage_error_v1->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(insufficient_storage_error_v1JSON, "error");
    if (cJSON_IsNull(error)) {
        error = NULL;
    }
    if (error) { 
    if(!cJSON_IsString(error) && !cJSON_IsNull(error))
    {
    goto end; //String
    }
    }

    // insufficient_storage_error_v1->total
    cJSON *total = cJSON_GetObjectItemCaseSensitive(insufficient_storage_error_v1JSON, "total");
    if (cJSON_IsNull(total)) {
        total = NULL;
    }
    if (total) { 
    if(!cJSON_IsNumber(total))
    {
    goto end; //Numeric
    }
    }

    // insufficient_storage_error_v1->available
    cJSON *available = cJSON_GetObjectItemCaseSensitive(insufficient_storage_error_v1JSON, "available");
    if (cJSON_IsNull(available)) {
        available = NULL;
    }
    if (available) { 
    if(!cJSON_IsNumber(available))
    {
    goto end; //Numeric
    }
    }

    // insufficient_storage_error_v1->required
    cJSON *required = cJSON_GetObjectItemCaseSensitive(insufficient_storage_error_v1JSON, "required");
    if (cJSON_IsNull(required)) {
        required = NULL;
    }
    if (!required) {
        goto end;
    }

    
    if(!cJSON_IsNumber(required))
    {
    goto end; //Numeric
    }


    insufficient_storage_error_v1_local_var = insufficient_storage_error_v1_create_internal (
        error_id && !cJSON_IsNull(error_id) ? strdup(error_id->valuestring) : NULL,
        error && !cJSON_IsNull(error) ? strdup(error->valuestring) : NULL,
        total ? total->valuedouble : 0,
        available ? available->valuedouble : 0,
        required->valuedouble
        );

    return insufficient_storage_error_v1_local_var;
end:
    return NULL;

}
