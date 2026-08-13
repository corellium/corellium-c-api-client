#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "agreed_ack_v1.h"



static agreed_ack_v1_t *agreed_ack_v1_create_internal(
    char *agreed_to_terms
    ) {
    agreed_ack_v1_t *agreed_ack_v1_local_var = malloc(sizeof(agreed_ack_v1_t));
    if (!agreed_ack_v1_local_var) {
        return NULL;
    }
    agreed_ack_v1_local_var->agreed_to_terms = agreed_to_terms;

    agreed_ack_v1_local_var->_library_owned = 1;
    return agreed_ack_v1_local_var;
}

__attribute__((deprecated)) agreed_ack_v1_t *agreed_ack_v1_create(
    char *agreed_to_terms
    ) {
    return agreed_ack_v1_create_internal (
        agreed_to_terms
        );
}

void agreed_ack_v1_free(agreed_ack_v1_t *agreed_ack_v1) {
    if(NULL == agreed_ack_v1){
        return ;
    }
    if(agreed_ack_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "agreed_ack_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (agreed_ack_v1->agreed_to_terms) {
        free(agreed_ack_v1->agreed_to_terms);
        agreed_ack_v1->agreed_to_terms = NULL;
    }
    free(agreed_ack_v1);
}

cJSON *agreed_ack_v1_convertToJSON(agreed_ack_v1_t *agreed_ack_v1) {
    cJSON *item = cJSON_CreateObject();

    // agreed_ack_v1->agreed_to_terms
    if(agreed_ack_v1->agreed_to_terms) {
    if(cJSON_AddStringToObject(item, "agreedToTerms", agreed_ack_v1->agreed_to_terms) == NULL) {
    goto fail; //Date-Time
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

agreed_ack_v1_t *agreed_ack_v1_parseFromJSON(cJSON *agreed_ack_v1JSON){

    agreed_ack_v1_t *agreed_ack_v1_local_var = NULL;

    // agreed_ack_v1->agreed_to_terms
    cJSON *agreed_to_terms = cJSON_GetObjectItemCaseSensitive(agreed_ack_v1JSON, "agreedToTerms");
    if (cJSON_IsNull(agreed_to_terms)) {
        agreed_to_terms = NULL;
    }
    if (agreed_to_terms) { 
    if(!cJSON_IsString(agreed_to_terms) && !cJSON_IsNull(agreed_to_terms))
    {
    goto end; //DateTime
    }
    }


    agreed_ack_v1_local_var = agreed_ack_v1_create_internal (
        agreed_to_terms && !cJSON_IsNull(agreed_to_terms) ? strdup(agreed_to_terms->valuestring) : NULL
        );

    return agreed_ack_v1_local_var;
end:
    return NULL;

}
