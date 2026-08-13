#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "domain_config_trial.h"



static domain_config_trial_t *domain_config_trial_create_internal(
    double start,
    double end,
    domain_config_trial_end_action_t *end_action,
    domain_config_trial_subscribe_action_t *subscribe_action,
    domain_config_trial_extension_t *extension
    ) {
    domain_config_trial_t *domain_config_trial_local_var = malloc(sizeof(domain_config_trial_t));
    if (!domain_config_trial_local_var) {
        return NULL;
    }
    domain_config_trial_local_var->start = start;
    domain_config_trial_local_var->end = end;
    domain_config_trial_local_var->end_action = end_action;
    domain_config_trial_local_var->subscribe_action = subscribe_action;
    domain_config_trial_local_var->extension = extension;

    domain_config_trial_local_var->_library_owned = 1;
    return domain_config_trial_local_var;
}

__attribute__((deprecated)) domain_config_trial_t *domain_config_trial_create(
    double start,
    double end,
    domain_config_trial_end_action_t *end_action,
    domain_config_trial_subscribe_action_t *subscribe_action,
    domain_config_trial_extension_t *extension
    ) {
    return domain_config_trial_create_internal (
        start,
        end,
        end_action,
        subscribe_action,
        extension
        );
}

void domain_config_trial_free(domain_config_trial_t *domain_config_trial) {
    if(NULL == domain_config_trial){
        return ;
    }
    if(domain_config_trial->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "domain_config_trial_free");
        return ;
    }
    listEntry_t *listEntry;
    if (domain_config_trial->end_action) {
        domain_config_trial_end_action_free(domain_config_trial->end_action);
        domain_config_trial->end_action = NULL;
    }
    if (domain_config_trial->subscribe_action) {
        domain_config_trial_subscribe_action_free(domain_config_trial->subscribe_action);
        domain_config_trial->subscribe_action = NULL;
    }
    if (domain_config_trial->extension) {
        domain_config_trial_extension_free(domain_config_trial->extension);
        domain_config_trial->extension = NULL;
    }
    free(domain_config_trial);
}

cJSON *domain_config_trial_convertToJSON(domain_config_trial_t *domain_config_trial) {
    cJSON *item = cJSON_CreateObject();

    // domain_config_trial->start
    if(domain_config_trial->start) {
    if(cJSON_AddNumberToObject(item, "start", domain_config_trial->start) == NULL) {
    goto fail; //Numeric
    }
    }


    // domain_config_trial->end
    if(domain_config_trial->end) {
    if(cJSON_AddNumberToObject(item, "end", domain_config_trial->end) == NULL) {
    goto fail; //Numeric
    }
    }


    // domain_config_trial->end_action
    if(domain_config_trial->end_action) {
    cJSON *end_action_local_JSON = domain_config_trial_end_action_convertToJSON(domain_config_trial->end_action);
    if(end_action_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "end_action", end_action_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // domain_config_trial->subscribe_action
    if(domain_config_trial->subscribe_action) {
    cJSON *subscribe_action_local_JSON = domain_config_trial_subscribe_action_convertToJSON(domain_config_trial->subscribe_action);
    if(subscribe_action_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "subscribe_action", subscribe_action_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // domain_config_trial->extension
    if(domain_config_trial->extension) {
    cJSON *extension_local_JSON = domain_config_trial_extension_convertToJSON(domain_config_trial->extension);
    if(extension_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "extension", extension_local_JSON);
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

domain_config_trial_t *domain_config_trial_parseFromJSON(cJSON *domain_config_trialJSON){

    domain_config_trial_t *domain_config_trial_local_var = NULL;

    // define the local variable for domain_config_trial->end_action
    domain_config_trial_end_action_t *end_action_local_nonprim = NULL;

    // define the local variable for domain_config_trial->subscribe_action
    domain_config_trial_subscribe_action_t *subscribe_action_local_nonprim = NULL;

    // define the local variable for domain_config_trial->extension
    domain_config_trial_extension_t *extension_local_nonprim = NULL;

    // domain_config_trial->start
    cJSON *start = cJSON_GetObjectItemCaseSensitive(domain_config_trialJSON, "start");
    if (cJSON_IsNull(start)) {
        start = NULL;
    }
    if (start) { 
    if(!cJSON_IsNumber(start))
    {
    goto end; //Numeric
    }
    }

    // domain_config_trial->end
    cJSON *end = cJSON_GetObjectItemCaseSensitive(domain_config_trialJSON, "end");
    if (cJSON_IsNull(end)) {
        end = NULL;
    }
    if (end) { 
    if(!cJSON_IsNumber(end))
    {
    goto end; //Numeric
    }
    }

    // domain_config_trial->end_action
    cJSON *end_action = cJSON_GetObjectItemCaseSensitive(domain_config_trialJSON, "end_action");
    if (cJSON_IsNull(end_action)) {
        end_action = NULL;
    }
    if (end_action) { 
    end_action_local_nonprim = domain_config_trial_end_action_parseFromJSON(end_action); //nonprimitive
    }

    // domain_config_trial->subscribe_action
    cJSON *subscribe_action = cJSON_GetObjectItemCaseSensitive(domain_config_trialJSON, "subscribe_action");
    if (cJSON_IsNull(subscribe_action)) {
        subscribe_action = NULL;
    }
    if (subscribe_action) { 
    subscribe_action_local_nonprim = domain_config_trial_subscribe_action_parseFromJSON(subscribe_action); //nonprimitive
    }

    // domain_config_trial->extension
    cJSON *extension = cJSON_GetObjectItemCaseSensitive(domain_config_trialJSON, "extension");
    if (cJSON_IsNull(extension)) {
        extension = NULL;
    }
    if (extension) { 
    extension_local_nonprim = domain_config_trial_extension_parseFromJSON(extension); //nonprimitive
    }


    domain_config_trial_local_var = domain_config_trial_create_internal (
        start ? start->valuedouble : 0,
        end ? end->valuedouble : 0,
        end_action ? end_action_local_nonprim : NULL,
        subscribe_action ? subscribe_action_local_nonprim : NULL,
        extension ? extension_local_nonprim : NULL
        );

    return domain_config_trial_local_var;
end:
    if (end_action_local_nonprim) {
        domain_config_trial_end_action_free(end_action_local_nonprim);
        end_action_local_nonprim = NULL;
    }
    if (subscribe_action_local_nonprim) {
        domain_config_trial_subscribe_action_free(subscribe_action_local_nonprim);
        subscribe_action_local_nonprim = NULL;
    }
    if (extension_local_nonprim) {
        domain_config_trial_extension_free(extension_local_nonprim);
        extension_local_nonprim = NULL;
    }
    return NULL;

}
