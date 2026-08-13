#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "auth_provider_type.h"



static auth_provider_type_t *auth_provider_type_create_internal(
    char *provider_type,
    object_t *schema
    ) {
    auth_provider_type_t *auth_provider_type_local_var = malloc(sizeof(auth_provider_type_t));
    if (!auth_provider_type_local_var) {
        return NULL;
    }
    auth_provider_type_local_var->provider_type = provider_type;
    auth_provider_type_local_var->schema = schema;

    auth_provider_type_local_var->_library_owned = 1;
    return auth_provider_type_local_var;
}

__attribute__((deprecated)) auth_provider_type_t *auth_provider_type_create(
    char *provider_type,
    object_t *schema
    ) {
    return auth_provider_type_create_internal (
        provider_type,
        schema
        );
}

void auth_provider_type_free(auth_provider_type_t *auth_provider_type) {
    if(NULL == auth_provider_type){
        return ;
    }
    if(auth_provider_type->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "auth_provider_type_free");
        return ;
    }
    listEntry_t *listEntry;
    if (auth_provider_type->provider_type) {
        free(auth_provider_type->provider_type);
        auth_provider_type->provider_type = NULL;
    }
    if (auth_provider_type->schema) {
        object_free(auth_provider_type->schema);
        auth_provider_type->schema = NULL;
    }
    free(auth_provider_type);
}

cJSON *auth_provider_type_convertToJSON(auth_provider_type_t *auth_provider_type) {
    cJSON *item = cJSON_CreateObject();

    // auth_provider_type->provider_type
    if (!auth_provider_type->provider_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "providerType", auth_provider_type->provider_type) == NULL) {
    goto fail; //String
    }


    // auth_provider_type->schema
    if (!auth_provider_type->schema) {
        goto fail;
    }
    cJSON *schema_object = object_convertToJSON(auth_provider_type->schema);
    if(schema_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "schema", schema_object);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

auth_provider_type_t *auth_provider_type_parseFromJSON(cJSON *auth_provider_typeJSON){

    auth_provider_type_t *auth_provider_type_local_var = NULL;

    // auth_provider_type->provider_type
    cJSON *provider_type = cJSON_GetObjectItemCaseSensitive(auth_provider_typeJSON, "providerType");
    if (cJSON_IsNull(provider_type)) {
        provider_type = NULL;
    }
    if (!provider_type) {
        goto end;
    }

    
    if(!cJSON_IsString(provider_type))
    {
    goto end; //String
    }

    // auth_provider_type->schema
    cJSON *schema = cJSON_GetObjectItemCaseSensitive(auth_provider_typeJSON, "schema");
    if (cJSON_IsNull(schema)) {
        schema = NULL;
    }
    if (!schema) {
        goto end;
    }

    object_t *schema_local_object = NULL;
    
    schema_local_object = object_parseFromJSON(schema); //object


    auth_provider_type_local_var = auth_provider_type_create_internal (
        strdup(provider_type->valuestring),
        schema_local_object
        );

    return auth_provider_type_local_var;
end:
    return NULL;

}
