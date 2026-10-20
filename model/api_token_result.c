#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "api_token_result.h"



static api_token_result_t *api_token_result_create_internal(
    char *api_token
    ) {
    api_token_result_t *api_token_result_local_var = malloc(sizeof(api_token_result_t));
    if (!api_token_result_local_var) {
        return NULL;
    }
    api_token_result_local_var->api_token = api_token;

    api_token_result_local_var->_library_owned = 1;
    return api_token_result_local_var;
}

__attribute__((deprecated)) api_token_result_t *api_token_result_create(
    char *api_token
    ) {
    return api_token_result_create_internal (
        api_token
        );
}

void api_token_result_free(api_token_result_t *api_token_result) {
    if(NULL == api_token_result){
        return ;
    }
    if(api_token_result->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "api_token_result_free");
        return ;
    }
    listEntry_t *listEntry;
    if (api_token_result->api_token) {
        free(api_token_result->api_token);
        api_token_result->api_token = NULL;
    }
    free(api_token_result);
}

cJSON *api_token_result_convertToJSON(api_token_result_t *api_token_result) {
    cJSON *item = cJSON_CreateObject();

    // api_token_result->api_token
    if (!api_token_result->api_token) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "apiToken", api_token_result->api_token) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

api_token_result_t *api_token_result_parseFromJSON(cJSON *api_token_resultJSON){

    api_token_result_t *api_token_result_local_var = NULL;

    // api_token_result->api_token
    cJSON *api_token = cJSON_GetObjectItemCaseSensitive(api_token_resultJSON, "apiToken");
    if (cJSON_IsNull(api_token)) {
        api_token = NULL;
    }
    if (!api_token) {
        goto end;
    }

    
    if(!cJSON_IsString(api_token))
    {
    goto end; //String
    }


    api_token_result_local_var = api_token_result_create_internal (
        strdup(api_token->valuestring)
        );

    return api_token_result_local_var;
end:
    return NULL;

}
