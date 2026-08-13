#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "check_subdomain_response_v1.h"



static check_subdomain_response_v1_t *check_subdomain_response_v1_create_internal(
    int available
    ) {
    check_subdomain_response_v1_t *check_subdomain_response_v1_local_var = malloc(sizeof(check_subdomain_response_v1_t));
    if (!check_subdomain_response_v1_local_var) {
        return NULL;
    }
    check_subdomain_response_v1_local_var->available = available;

    check_subdomain_response_v1_local_var->_library_owned = 1;
    return check_subdomain_response_v1_local_var;
}

__attribute__((deprecated)) check_subdomain_response_v1_t *check_subdomain_response_v1_create(
    int available
    ) {
    return check_subdomain_response_v1_create_internal (
        available
        );
}

void check_subdomain_response_v1_free(check_subdomain_response_v1_t *check_subdomain_response_v1) {
    if(NULL == check_subdomain_response_v1){
        return ;
    }
    if(check_subdomain_response_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "check_subdomain_response_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    free(check_subdomain_response_v1);
}

cJSON *check_subdomain_response_v1_convertToJSON(check_subdomain_response_v1_t *check_subdomain_response_v1) {
    cJSON *item = cJSON_CreateObject();

    // check_subdomain_response_v1->available
    if (!check_subdomain_response_v1->available) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "available", check_subdomain_response_v1->available) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

check_subdomain_response_v1_t *check_subdomain_response_v1_parseFromJSON(cJSON *check_subdomain_response_v1JSON){

    check_subdomain_response_v1_t *check_subdomain_response_v1_local_var = NULL;

    // check_subdomain_response_v1->available
    cJSON *available = cJSON_GetObjectItemCaseSensitive(check_subdomain_response_v1JSON, "available");
    if (cJSON_IsNull(available)) {
        available = NULL;
    }
    if (!available) {
        goto end;
    }

    
    if(!cJSON_IsBool(available))
    {
    goto end; //Bool
    }


    check_subdomain_response_v1_local_var = check_subdomain_response_v1_create_internal (
        available->valueint
        );

    return check_subdomain_response_v1_local_var;
end:
    return NULL;

}
