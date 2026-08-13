#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "allowed_firmware_schema.h"



static allowed_firmware_schema_t *allowed_firmware_schema_create_internal(
    char *version,
    char *build_id
    ) {
    allowed_firmware_schema_t *allowed_firmware_schema_local_var = malloc(sizeof(allowed_firmware_schema_t));
    if (!allowed_firmware_schema_local_var) {
        return NULL;
    }
    allowed_firmware_schema_local_var->version = version;
    allowed_firmware_schema_local_var->build_id = build_id;

    allowed_firmware_schema_local_var->_library_owned = 1;
    return allowed_firmware_schema_local_var;
}

__attribute__((deprecated)) allowed_firmware_schema_t *allowed_firmware_schema_create(
    char *version,
    char *build_id
    ) {
    return allowed_firmware_schema_create_internal (
        version,
        build_id
        );
}

void allowed_firmware_schema_free(allowed_firmware_schema_t *allowed_firmware_schema) {
    if(NULL == allowed_firmware_schema){
        return ;
    }
    if(allowed_firmware_schema->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "allowed_firmware_schema_free");
        return ;
    }
    listEntry_t *listEntry;
    if (allowed_firmware_schema->version) {
        free(allowed_firmware_schema->version);
        allowed_firmware_schema->version = NULL;
    }
    if (allowed_firmware_schema->build_id) {
        free(allowed_firmware_schema->build_id);
        allowed_firmware_schema->build_id = NULL;
    }
    free(allowed_firmware_schema);
}

cJSON *allowed_firmware_schema_convertToJSON(allowed_firmware_schema_t *allowed_firmware_schema) {
    cJSON *item = cJSON_CreateObject();

    // allowed_firmware_schema->version
    if (!allowed_firmware_schema->version) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "version", allowed_firmware_schema->version) == NULL) {
    goto fail; //String
    }


    // allowed_firmware_schema->build_id
    if (!allowed_firmware_schema->build_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "buildId", allowed_firmware_schema->build_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

allowed_firmware_schema_t *allowed_firmware_schema_parseFromJSON(cJSON *allowed_firmware_schemaJSON){

    allowed_firmware_schema_t *allowed_firmware_schema_local_var = NULL;

    // allowed_firmware_schema->version
    cJSON *version = cJSON_GetObjectItemCaseSensitive(allowed_firmware_schemaJSON, "version");
    if (cJSON_IsNull(version)) {
        version = NULL;
    }
    if (!version) {
        goto end;
    }

    
    if(!cJSON_IsString(version))
    {
    goto end; //String
    }

    // allowed_firmware_schema->build_id
    cJSON *build_id = cJSON_GetObjectItemCaseSensitive(allowed_firmware_schemaJSON, "buildId");
    if (cJSON_IsNull(build_id)) {
        build_id = NULL;
    }
    if (!build_id) {
        goto end;
    }

    
    if(!cJSON_IsString(build_id))
    {
    goto end; //String
    }


    allowed_firmware_schema_local_var = allowed_firmware_schema_create_internal (
        strdup(version->valuestring),
        strdup(build_id->valuestring)
        );

    return allowed_firmware_schema_local_var;
end:
    return NULL;

}
