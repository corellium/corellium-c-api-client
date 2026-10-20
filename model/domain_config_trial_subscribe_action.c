#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "domain_config_trial_subscribe_action.h"



static domain_config_trial_subscribe_action_t *domain_config_trial_subscribe_action_create_internal(
    char *action
    ) {
    domain_config_trial_subscribe_action_t *domain_config_trial_subscribe_action_local_var = malloc(sizeof(domain_config_trial_subscribe_action_t));
    if (!domain_config_trial_subscribe_action_local_var) {
        return NULL;
    }
    domain_config_trial_subscribe_action_local_var->action = action;

    domain_config_trial_subscribe_action_local_var->_library_owned = 1;
    return domain_config_trial_subscribe_action_local_var;
}

__attribute__((deprecated)) domain_config_trial_subscribe_action_t *domain_config_trial_subscribe_action_create(
    char *action
    ) {
    return domain_config_trial_subscribe_action_create_internal (
        action
        );
}

void domain_config_trial_subscribe_action_free(domain_config_trial_subscribe_action_t *domain_config_trial_subscribe_action) {
    if(NULL == domain_config_trial_subscribe_action){
        return ;
    }
    if(domain_config_trial_subscribe_action->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "domain_config_trial_subscribe_action_free");
        return ;
    }
    listEntry_t *listEntry;
    if (domain_config_trial_subscribe_action->action) {
        free(domain_config_trial_subscribe_action->action);
        domain_config_trial_subscribe_action->action = NULL;
    }
    free(domain_config_trial_subscribe_action);
}

cJSON *domain_config_trial_subscribe_action_convertToJSON(domain_config_trial_subscribe_action_t *domain_config_trial_subscribe_action) {
    cJSON *item = cJSON_CreateObject();

    // domain_config_trial_subscribe_action->action
    if (!domain_config_trial_subscribe_action->action) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "action", domain_config_trial_subscribe_action->action) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

domain_config_trial_subscribe_action_t *domain_config_trial_subscribe_action_parseFromJSON(cJSON *domain_config_trial_subscribe_actionJSON){

    domain_config_trial_subscribe_action_t *domain_config_trial_subscribe_action_local_var = NULL;

    // domain_config_trial_subscribe_action->action
    cJSON *action = cJSON_GetObjectItemCaseSensitive(domain_config_trial_subscribe_actionJSON, "action");
    if (cJSON_IsNull(action)) {
        action = NULL;
    }
    if (!action) {
        goto end;
    }

    
    if(!cJSON_IsString(action))
    {
    goto end; //String
    }


    domain_config_trial_subscribe_action_local_var = domain_config_trial_subscribe_action_create_internal (
        strdup(action->valuestring)
        );

    return domain_config_trial_subscribe_action_local_var;
end:
    return NULL;

}
