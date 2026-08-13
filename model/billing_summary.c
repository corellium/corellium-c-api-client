#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "billing_summary.h"



static billing_summary_t *billing_summary_create_internal(
    billing_summary_pending_usage_based_t *pending_usage_based
    ) {
    billing_summary_t *billing_summary_local_var = malloc(sizeof(billing_summary_t));
    if (!billing_summary_local_var) {
        return NULL;
    }
    billing_summary_local_var->pending_usage_based = pending_usage_based;

    billing_summary_local_var->_library_owned = 1;
    return billing_summary_local_var;
}

__attribute__((deprecated)) billing_summary_t *billing_summary_create(
    billing_summary_pending_usage_based_t *pending_usage_based
    ) {
    return billing_summary_create_internal (
        pending_usage_based
        );
}

void billing_summary_free(billing_summary_t *billing_summary) {
    if(NULL == billing_summary){
        return ;
    }
    if(billing_summary->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "billing_summary_free");
        return ;
    }
    listEntry_t *listEntry;
    if (billing_summary->pending_usage_based) {
        billing_summary_pending_usage_based_free(billing_summary->pending_usage_based);
        billing_summary->pending_usage_based = NULL;
    }
    free(billing_summary);
}

cJSON *billing_summary_convertToJSON(billing_summary_t *billing_summary) {
    cJSON *item = cJSON_CreateObject();

    // billing_summary->pending_usage_based
    if(billing_summary->pending_usage_based) {
    cJSON *pending_usage_based_local_JSON = billing_summary_pending_usage_based_convertToJSON(billing_summary->pending_usage_based);
    if(pending_usage_based_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "pendingUsageBased", pending_usage_based_local_JSON);
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

billing_summary_t *billing_summary_parseFromJSON(cJSON *billing_summaryJSON){

    billing_summary_t *billing_summary_local_var = NULL;

    // define the local variable for billing_summary->pending_usage_based
    billing_summary_pending_usage_based_t *pending_usage_based_local_nonprim = NULL;

    // billing_summary->pending_usage_based
    cJSON *pending_usage_based = cJSON_GetObjectItemCaseSensitive(billing_summaryJSON, "pendingUsageBased");
    if (cJSON_IsNull(pending_usage_based)) {
        pending_usage_based = NULL;
    }
    if (pending_usage_based) { 
    pending_usage_based_local_nonprim = billing_summary_pending_usage_based_parseFromJSON(pending_usage_based); //nonprimitive
    }


    billing_summary_local_var = billing_summary_create_internal (
        pending_usage_based ? pending_usage_based_local_nonprim : NULL
        );

    return billing_summary_local_var;
end:
    if (pending_usage_based_local_nonprim) {
        billing_summary_pending_usage_based_free(pending_usage_based_local_nonprim);
        pending_usage_based_local_nonprim = NULL;
    }
    return NULL;

}
