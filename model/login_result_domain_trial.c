#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "login_result_domain_trial.h"



static login_result_domain_trial_t *login_result_domain_trial_create_internal(
    double start,
    double end
    ) {
    login_result_domain_trial_t *login_result_domain_trial_local_var = malloc(sizeof(login_result_domain_trial_t));
    if (!login_result_domain_trial_local_var) {
        return NULL;
    }
    login_result_domain_trial_local_var->start = start;
    login_result_domain_trial_local_var->end = end;

    login_result_domain_trial_local_var->_library_owned = 1;
    return login_result_domain_trial_local_var;
}

__attribute__((deprecated)) login_result_domain_trial_t *login_result_domain_trial_create(
    double start,
    double end
    ) {
    return login_result_domain_trial_create_internal (
        start,
        end
        );
}

void login_result_domain_trial_free(login_result_domain_trial_t *login_result_domain_trial) {
    if(NULL == login_result_domain_trial){
        return ;
    }
    if(login_result_domain_trial->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "login_result_domain_trial_free");
        return ;
    }
    listEntry_t *listEntry;
    free(login_result_domain_trial);
}

cJSON *login_result_domain_trial_convertToJSON(login_result_domain_trial_t *login_result_domain_trial) {
    cJSON *item = cJSON_CreateObject();

    // login_result_domain_trial->start
    if(login_result_domain_trial->start) {
    if(cJSON_AddNumberToObject(item, "start", login_result_domain_trial->start) == NULL) {
    goto fail; //Numeric
    }
    }


    // login_result_domain_trial->end
    if(login_result_domain_trial->end) {
    if(cJSON_AddNumberToObject(item, "end", login_result_domain_trial->end) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

login_result_domain_trial_t *login_result_domain_trial_parseFromJSON(cJSON *login_result_domain_trialJSON){

    login_result_domain_trial_t *login_result_domain_trial_local_var = NULL;

    // login_result_domain_trial->start
    cJSON *start = cJSON_GetObjectItemCaseSensitive(login_result_domain_trialJSON, "start");
    if (cJSON_IsNull(start)) {
        start = NULL;
    }
    if (start) { 
    if(!cJSON_IsNumber(start))
    {
    goto end; //Numeric
    }
    }

    // login_result_domain_trial->end
    cJSON *end = cJSON_GetObjectItemCaseSensitive(login_result_domain_trialJSON, "end");
    if (cJSON_IsNull(end)) {
        end = NULL;
    }
    if (end) { 
    if(!cJSON_IsNumber(end))
    {
    goto end; //Numeric
    }
    }


    login_result_domain_trial_local_var = login_result_domain_trial_create_internal (
        start ? start->valuedouble : 0,
        end ? end->valuedouble : 0
        );

    return login_result_domain_trial_local_var;
end:
    return NULL;

}
