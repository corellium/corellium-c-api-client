#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "assessment_id_status.h"



static assessment_id_status_t *assessment_id_status_create_internal(
    char *id,
    corellium_api_assessment_status__e status
    ) {
    assessment_id_status_t *assessment_id_status_local_var = malloc(sizeof(assessment_id_status_t));
    if (!assessment_id_status_local_var) {
        return NULL;
    }
    assessment_id_status_local_var->id = id;
    assessment_id_status_local_var->status = status;

    assessment_id_status_local_var->_library_owned = 1;
    return assessment_id_status_local_var;
}

__attribute__((deprecated)) assessment_id_status_t *assessment_id_status_create(
    char *id,
    corellium_api_assessment_status__e status
    ) {
    return assessment_id_status_create_internal (
        id,
        status
        );
}

void assessment_id_status_free(assessment_id_status_t *assessment_id_status) {
    if(NULL == assessment_id_status){
        return ;
    }
    if(assessment_id_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "assessment_id_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (assessment_id_status->id) {
        free(assessment_id_status->id);
        assessment_id_status->id = NULL;
    }
    free(assessment_id_status);
}

cJSON *assessment_id_status_convertToJSON(assessment_id_status_t *assessment_id_status) {
    cJSON *item = cJSON_CreateObject();

    // assessment_id_status->id
    if (!assessment_id_status->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", assessment_id_status->id) == NULL) {
    goto fail; //String
    }


    // assessment_id_status->status
    if (corellium_api_assessment_status__NULL == assessment_id_status->status) {
        goto fail;
    }
    cJSON *status_local_JSON = assessment_status_convertToJSON(assessment_id_status->status);
    if(status_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

assessment_id_status_t *assessment_id_status_parseFromJSON(cJSON *assessment_id_statusJSON){

    assessment_id_status_t *assessment_id_status_local_var = NULL;

    // define the local variable for assessment_id_status->status
    corellium_api_assessment_status__e status_local_nonprim = 0;

    // assessment_id_status->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(assessment_id_statusJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // assessment_id_status->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(assessment_id_statusJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    status_local_nonprim = assessment_status_parseFromJSON(status); //custom


    assessment_id_status_local_var = assessment_id_status_create_internal (
        strdup(id->valuestring),
        status_local_nonprim
        );

    return assessment_id_status_local_var;
end:
    if (status_local_nonprim) {
        status_local_nonprim = 0;
    }
    return NULL;

}
