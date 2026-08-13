#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "assessment_wordlist.h"



static assessment_wordlist_t *assessment_wordlist_create_internal(
    char *id,
    char *name
    ) {
    assessment_wordlist_t *assessment_wordlist_local_var = malloc(sizeof(assessment_wordlist_t));
    if (!assessment_wordlist_local_var) {
        return NULL;
    }
    assessment_wordlist_local_var->id = id;
    assessment_wordlist_local_var->name = name;

    assessment_wordlist_local_var->_library_owned = 1;
    return assessment_wordlist_local_var;
}

__attribute__((deprecated)) assessment_wordlist_t *assessment_wordlist_create(
    char *id,
    char *name
    ) {
    return assessment_wordlist_create_internal (
        id,
        name
        );
}

void assessment_wordlist_free(assessment_wordlist_t *assessment_wordlist) {
    if(NULL == assessment_wordlist){
        return ;
    }
    if(assessment_wordlist->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "assessment_wordlist_free");
        return ;
    }
    listEntry_t *listEntry;
    if (assessment_wordlist->id) {
        free(assessment_wordlist->id);
        assessment_wordlist->id = NULL;
    }
    if (assessment_wordlist->name) {
        free(assessment_wordlist->name);
        assessment_wordlist->name = NULL;
    }
    free(assessment_wordlist);
}

cJSON *assessment_wordlist_convertToJSON(assessment_wordlist_t *assessment_wordlist) {
    cJSON *item = cJSON_CreateObject();

    // assessment_wordlist->id
    if (!assessment_wordlist->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", assessment_wordlist->id) == NULL) {
    goto fail; //String
    }


    // assessment_wordlist->name
    if (!assessment_wordlist->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", assessment_wordlist->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

assessment_wordlist_t *assessment_wordlist_parseFromJSON(cJSON *assessment_wordlistJSON){

    assessment_wordlist_t *assessment_wordlist_local_var = NULL;

    // assessment_wordlist->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(assessment_wordlistJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // assessment_wordlist->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(assessment_wordlistJSON, "name");
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


    assessment_wordlist_local_var = assessment_wordlist_create_internal (
        strdup(id->valuestring),
        strdup(name->valuestring)
        );

    return assessment_wordlist_local_var;
end:
    return NULL;

}
