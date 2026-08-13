#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "assessment_history_line_item.h"



static assessment_history_line_item_t *assessment_history_line_item_create_internal(
    double date,
    double complete,
    double incomplete
    ) {
    assessment_history_line_item_t *assessment_history_line_item_local_var = malloc(sizeof(assessment_history_line_item_t));
    if (!assessment_history_line_item_local_var) {
        return NULL;
    }
    assessment_history_line_item_local_var->date = date;
    assessment_history_line_item_local_var->complete = complete;
    assessment_history_line_item_local_var->incomplete = incomplete;

    assessment_history_line_item_local_var->_library_owned = 1;
    return assessment_history_line_item_local_var;
}

__attribute__((deprecated)) assessment_history_line_item_t *assessment_history_line_item_create(
    double date,
    double complete,
    double incomplete
    ) {
    return assessment_history_line_item_create_internal (
        date,
        complete,
        incomplete
        );
}

void assessment_history_line_item_free(assessment_history_line_item_t *assessment_history_line_item) {
    if(NULL == assessment_history_line_item){
        return ;
    }
    if(assessment_history_line_item->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "assessment_history_line_item_free");
        return ;
    }
    listEntry_t *listEntry;
    free(assessment_history_line_item);
}

cJSON *assessment_history_line_item_convertToJSON(assessment_history_line_item_t *assessment_history_line_item) {
    cJSON *item = cJSON_CreateObject();

    // assessment_history_line_item->date
    if (!assessment_history_line_item->date) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "date", assessment_history_line_item->date) == NULL) {
    goto fail; //Numeric
    }


    // assessment_history_line_item->complete
    if (!assessment_history_line_item->complete) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "complete", assessment_history_line_item->complete) == NULL) {
    goto fail; //Numeric
    }


    // assessment_history_line_item->incomplete
    if (!assessment_history_line_item->incomplete) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "incomplete", assessment_history_line_item->incomplete) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

assessment_history_line_item_t *assessment_history_line_item_parseFromJSON(cJSON *assessment_history_line_itemJSON){

    assessment_history_line_item_t *assessment_history_line_item_local_var = NULL;

    // assessment_history_line_item->date
    cJSON *date = cJSON_GetObjectItemCaseSensitive(assessment_history_line_itemJSON, "date");
    if (cJSON_IsNull(date)) {
        date = NULL;
    }
    if (!date) {
        goto end;
    }

    
    if(!cJSON_IsNumber(date))
    {
    goto end; //Numeric
    }

    // assessment_history_line_item->complete
    cJSON *complete = cJSON_GetObjectItemCaseSensitive(assessment_history_line_itemJSON, "complete");
    if (cJSON_IsNull(complete)) {
        complete = NULL;
    }
    if (!complete) {
        goto end;
    }

    
    if(!cJSON_IsNumber(complete))
    {
    goto end; //Numeric
    }

    // assessment_history_line_item->incomplete
    cJSON *incomplete = cJSON_GetObjectItemCaseSensitive(assessment_history_line_itemJSON, "incomplete");
    if (cJSON_IsNull(incomplete)) {
        incomplete = NULL;
    }
    if (!incomplete) {
        goto end;
    }

    
    if(!cJSON_IsNumber(incomplete))
    {
    goto end; //Numeric
    }


    assessment_history_line_item_local_var = assessment_history_line_item_create_internal (
        date->valuedouble,
        complete->valuedouble,
        incomplete->valuedouble
        );

    return assessment_history_line_item_local_var;
end:
    return NULL;

}
