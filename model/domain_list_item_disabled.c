#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "domain_list_item_disabled.h"


char* domain_list_item_disabled_type_ToString(corellium_api_domain_list_item_disabled_TYPE_e type) {
    char* typeArray[] =  { "NULL", "SubscriptionCanceled", "SubscriptionPaused", "TrialEnded", "PastDue", "SubscriptionPending", "AllocatedHoursExpended" };
    return typeArray[type];
}

corellium_api_domain_list_item_disabled_TYPE_e domain_list_item_disabled_type_FromString(char* type){
    int stringToReturn = 0;
    char *typeArray[] =  { "NULL", "SubscriptionCanceled", "SubscriptionPaused", "TrialEnded", "PastDue", "SubscriptionPending", "AllocatedHoursExpended" };
    size_t sizeofArray = sizeof(typeArray) / sizeof(typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(type, typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static domain_list_item_disabled_t *domain_list_item_disabled_create_internal(
    corellium_api_domain_list_item_disabled_TYPE_e type
    ) {
    domain_list_item_disabled_t *domain_list_item_disabled_local_var = malloc(sizeof(domain_list_item_disabled_t));
    if (!domain_list_item_disabled_local_var) {
        return NULL;
    }
    domain_list_item_disabled_local_var->type = type;

    domain_list_item_disabled_local_var->_library_owned = 1;
    return domain_list_item_disabled_local_var;
}

__attribute__((deprecated)) domain_list_item_disabled_t *domain_list_item_disabled_create(
    corellium_api_domain_list_item_disabled_TYPE_e type
    ) {
    return domain_list_item_disabled_create_internal (
        type
        );
}

void domain_list_item_disabled_free(domain_list_item_disabled_t *domain_list_item_disabled) {
    if(NULL == domain_list_item_disabled){
        return ;
    }
    if(domain_list_item_disabled->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "domain_list_item_disabled_free");
        return ;
    }
    listEntry_t *listEntry;
    free(domain_list_item_disabled);
}

cJSON *domain_list_item_disabled_convertToJSON(domain_list_item_disabled_t *domain_list_item_disabled) {
    cJSON *item = cJSON_CreateObject();

    // domain_list_item_disabled->type
    if (corellium_api_domain_list_item_disabled_TYPE_NULL == domain_list_item_disabled->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", domain_list_item_disabled_type_ToString(domain_list_item_disabled->type)) == NULL)
    {
    goto fail; //Enum
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

domain_list_item_disabled_t *domain_list_item_disabled_parseFromJSON(cJSON *domain_list_item_disabledJSON){

    domain_list_item_disabled_t *domain_list_item_disabled_local_var = NULL;

    // domain_list_item_disabled->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(domain_list_item_disabledJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    corellium_api_domain_list_item_disabled_TYPE_e typeVariable;
    
    if(!cJSON_IsString(type))
    {
    goto end; //Enum
    }
    typeVariable = domain_list_item_disabled_type_FromString(type->valuestring);


    domain_list_item_disabled_local_var = domain_list_item_disabled_create_internal (
        typeVariable
        );

    return domain_list_item_disabled_local_var;
end:
    return NULL;

}
