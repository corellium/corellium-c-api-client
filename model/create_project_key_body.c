#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_project_key_body.h"


char* create_project_key_body_kind_ToString(corellium_api_create_project_key_body_KIND_e kind) {
    char* kindArray[] =  { "NULL", "ssh", "adb" };
    return kindArray[kind];
}

corellium_api_create_project_key_body_KIND_e create_project_key_body_kind_FromString(char* kind){
    int stringToReturn = 0;
    char *kindArray[] =  { "NULL", "ssh", "adb" };
    size_t sizeofArray = sizeof(kindArray) / sizeof(kindArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(kind, kindArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static create_project_key_body_t *create_project_key_body_create_internal(
    corellium_api_create_project_key_body_KIND_e kind,
    char *label,
    char *key
    ) {
    create_project_key_body_t *create_project_key_body_local_var = malloc(sizeof(create_project_key_body_t));
    if (!create_project_key_body_local_var) {
        return NULL;
    }
    create_project_key_body_local_var->kind = kind;
    create_project_key_body_local_var->label = label;
    create_project_key_body_local_var->key = key;

    create_project_key_body_local_var->_library_owned = 1;
    return create_project_key_body_local_var;
}

__attribute__((deprecated)) create_project_key_body_t *create_project_key_body_create(
    corellium_api_create_project_key_body_KIND_e kind,
    char *label,
    char *key
    ) {
    return create_project_key_body_create_internal (
        kind,
        label,
        key
        );
}

void create_project_key_body_free(create_project_key_body_t *create_project_key_body) {
    if(NULL == create_project_key_body){
        return ;
    }
    if(create_project_key_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_project_key_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (create_project_key_body->label) {
        free(create_project_key_body->label);
        create_project_key_body->label = NULL;
    }
    if (create_project_key_body->key) {
        free(create_project_key_body->key);
        create_project_key_body->key = NULL;
    }
    free(create_project_key_body);
}

cJSON *create_project_key_body_convertToJSON(create_project_key_body_t *create_project_key_body) {
    cJSON *item = cJSON_CreateObject();

    // create_project_key_body->kind
    if (corellium_api_create_project_key_body_KIND_NULL == create_project_key_body->kind) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kind", create_project_key_body_kind_ToString(create_project_key_body->kind)) == NULL)
    {
    goto fail; //Enum
    }


    // create_project_key_body->label
    if(create_project_key_body->label) {
    if(cJSON_AddStringToObject(item, "label", create_project_key_body->label) == NULL) {
    goto fail; //String
    }
    }


    // create_project_key_body->key
    if (!create_project_key_body->key) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "key", create_project_key_body->key) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

create_project_key_body_t *create_project_key_body_parseFromJSON(cJSON *create_project_key_bodyJSON){

    create_project_key_body_t *create_project_key_body_local_var = NULL;

    // create_project_key_body->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(create_project_key_bodyJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (!kind) {
        goto end;
    }

    corellium_api_create_project_key_body_KIND_e kindVariable;
    
    if(!cJSON_IsString(kind))
    {
    goto end; //Enum
    }
    kindVariable = create_project_key_body_kind_FromString(kind->valuestring);

    // create_project_key_body->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(create_project_key_bodyJSON, "label");
    if (cJSON_IsNull(label)) {
        label = NULL;
    }
    if (label) { 
    if(!cJSON_IsString(label) && !cJSON_IsNull(label))
    {
    goto end; //String
    }
    }

    // create_project_key_body->key
    cJSON *key = cJSON_GetObjectItemCaseSensitive(create_project_key_bodyJSON, "key");
    if (cJSON_IsNull(key)) {
        key = NULL;
    }
    if (!key) {
        goto end;
    }

    
    if(!cJSON_IsString(key))
    {
    goto end; //String
    }


    create_project_key_body_local_var = create_project_key_body_create_internal (
        kindVariable,
        label && !cJSON_IsNull(label) ? strdup(label->valuestring) : NULL,
        strdup(key->valuestring)
        );

    return create_project_key_body_local_var;
end:
    return NULL;

}
