#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "domain_config_input_trial.h"



static domain_config_input_trial_t *domain_config_input_trial_create_internal(
    double start,
    double end
    ) {
    domain_config_input_trial_t *domain_config_input_trial_local_var = malloc(sizeof(domain_config_input_trial_t));
    if (!domain_config_input_trial_local_var) {
        return NULL;
    }
    domain_config_input_trial_local_var->start = start;
    domain_config_input_trial_local_var->end = end;

    domain_config_input_trial_local_var->_library_owned = 1;
    return domain_config_input_trial_local_var;
}

__attribute__((deprecated)) domain_config_input_trial_t *domain_config_input_trial_create(
    double start,
    double end
    ) {
    return domain_config_input_trial_create_internal (
        start,
        end
        );
}

void domain_config_input_trial_free(domain_config_input_trial_t *domain_config_input_trial) {
    if(NULL == domain_config_input_trial){
        return ;
    }
    if(domain_config_input_trial->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "domain_config_input_trial_free");
        return ;
    }
    listEntry_t *listEntry;
    free(domain_config_input_trial);
}

cJSON *domain_config_input_trial_convertToJSON(domain_config_input_trial_t *domain_config_input_trial) {
    cJSON *item = cJSON_CreateObject();

    // domain_config_input_trial->start
    if (!domain_config_input_trial->start) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "start", domain_config_input_trial->start) == NULL) {
    goto fail; //Numeric
    }


    // domain_config_input_trial->end
    if (!domain_config_input_trial->end) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "end", domain_config_input_trial->end) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

domain_config_input_trial_t *domain_config_input_trial_parseFromJSON(cJSON *domain_config_input_trialJSON){

    domain_config_input_trial_t *domain_config_input_trial_local_var = NULL;

    // domain_config_input_trial->start
    cJSON *start = cJSON_GetObjectItemCaseSensitive(domain_config_input_trialJSON, "start");
    if (cJSON_IsNull(start)) {
        start = NULL;
    }
    if (!start) {
        goto end;
    }

    
    if(!cJSON_IsNumber(start))
    {
    goto end; //Numeric
    }

    // domain_config_input_trial->end
    cJSON *end = cJSON_GetObjectItemCaseSensitive(domain_config_input_trialJSON, "end");
    if (cJSON_IsNull(end)) {
        end = NULL;
    }
    if (!end) {
        goto end;
    }

    
    if(!cJSON_IsNumber(end))
    {
    goto end; //Numeric
    }


    domain_config_input_trial_local_var = domain_config_input_trial_create_internal (
        start->valuedouble,
        end->valuedouble
        );

    return domain_config_input_trial_local_var;
end:
    return NULL;

}
