#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hypertune_hash_response.h"



static hypertune_hash_response_t *hypertune_hash_response_create_internal(
    char *hash
    ) {
    hypertune_hash_response_t *hypertune_hash_response_local_var = malloc(sizeof(hypertune_hash_response_t));
    if (!hypertune_hash_response_local_var) {
        return NULL;
    }
    hypertune_hash_response_local_var->hash = hash;

    hypertune_hash_response_local_var->_library_owned = 1;
    return hypertune_hash_response_local_var;
}

__attribute__((deprecated)) hypertune_hash_response_t *hypertune_hash_response_create(
    char *hash
    ) {
    return hypertune_hash_response_create_internal (
        hash
        );
}

void hypertune_hash_response_free(hypertune_hash_response_t *hypertune_hash_response) {
    if(NULL == hypertune_hash_response){
        return ;
    }
    if(hypertune_hash_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "hypertune_hash_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (hypertune_hash_response->hash) {
        free(hypertune_hash_response->hash);
        hypertune_hash_response->hash = NULL;
    }
    free(hypertune_hash_response);
}

cJSON *hypertune_hash_response_convertToJSON(hypertune_hash_response_t *hypertune_hash_response) {
    cJSON *item = cJSON_CreateObject();

    // hypertune_hash_response->hash
    if (!hypertune_hash_response->hash) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "hash", hypertune_hash_response->hash) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

hypertune_hash_response_t *hypertune_hash_response_parseFromJSON(cJSON *hypertune_hash_responseJSON){

    hypertune_hash_response_t *hypertune_hash_response_local_var = NULL;

    // hypertune_hash_response->hash
    cJSON *hash = cJSON_GetObjectItemCaseSensitive(hypertune_hash_responseJSON, "hash");
    if (cJSON_IsNull(hash)) {
        hash = NULL;
    }
    if (!hash) {
        goto end;
    }

    
    if(!cJSON_IsString(hash))
    {
    goto end; //String
    }


    hypertune_hash_response_local_var = hypertune_hash_response_create_internal (
        strdup(hash->valuestring)
        );

    return hypertune_hash_response_local_var;
end:
    return NULL;

}
