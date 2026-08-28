#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "snapshot_owner_schema.h"



static snapshot_owner_schema_t *snapshot_owner_schema_create_internal(
    char *name,
    char *email
    ) {
    snapshot_owner_schema_t *snapshot_owner_schema_local_var = malloc(sizeof(snapshot_owner_schema_t));
    if (!snapshot_owner_schema_local_var) {
        return NULL;
    }
    snapshot_owner_schema_local_var->name = name;
    snapshot_owner_schema_local_var->email = email;

    snapshot_owner_schema_local_var->_library_owned = 1;
    return snapshot_owner_schema_local_var;
}

__attribute__((deprecated)) snapshot_owner_schema_t *snapshot_owner_schema_create(
    char *name,
    char *email
    ) {
    return snapshot_owner_schema_create_internal (
        name,
        email
        );
}

void snapshot_owner_schema_free(snapshot_owner_schema_t *snapshot_owner_schema) {
    if(NULL == snapshot_owner_schema){
        return ;
    }
    if(snapshot_owner_schema->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "snapshot_owner_schema_free");
        return ;
    }
    listEntry_t *listEntry;
    if (snapshot_owner_schema->name) {
        free(snapshot_owner_schema->name);
        snapshot_owner_schema->name = NULL;
    }
    if (snapshot_owner_schema->email) {
        free(snapshot_owner_schema->email);
        snapshot_owner_schema->email = NULL;
    }
    free(snapshot_owner_schema);
}

cJSON *snapshot_owner_schema_convertToJSON(snapshot_owner_schema_t *snapshot_owner_schema) {
    cJSON *item = cJSON_CreateObject();

    // snapshot_owner_schema->name
    if (!snapshot_owner_schema->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", snapshot_owner_schema->name) == NULL) {
    goto fail; //String
    }


    // snapshot_owner_schema->email
    if (!snapshot_owner_schema->email) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "email", snapshot_owner_schema->email) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

snapshot_owner_schema_t *snapshot_owner_schema_parseFromJSON(cJSON *snapshot_owner_schemaJSON){

    snapshot_owner_schema_t *snapshot_owner_schema_local_var = NULL;

    // snapshot_owner_schema->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(snapshot_owner_schemaJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // snapshot_owner_schema->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(snapshot_owner_schemaJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (!email) {
        goto end;
    }

    
    if(!cJSON_IsString(email))
    {
    goto end; //String
    }


    snapshot_owner_schema_local_var = snapshot_owner_schema_create_internal (
        strdup(name->valuestring),
        strdup(email->valuestring)
        );

    return snapshot_owner_schema_local_var;
end:
    return NULL;

}
