#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "portal_session.h"



static portal_session_t *portal_session_create_internal(
    char *url
    ) {
    portal_session_t *portal_session_local_var = malloc(sizeof(portal_session_t));
    if (!portal_session_local_var) {
        return NULL;
    }
    portal_session_local_var->url = url;

    portal_session_local_var->_library_owned = 1;
    return portal_session_local_var;
}

__attribute__((deprecated)) portal_session_t *portal_session_create(
    char *url
    ) {
    return portal_session_create_internal (
        url
        );
}

void portal_session_free(portal_session_t *portal_session) {
    if(NULL == portal_session){
        return ;
    }
    if(portal_session->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "portal_session_free");
        return ;
    }
    listEntry_t *listEntry;
    if (portal_session->url) {
        free(portal_session->url);
        portal_session->url = NULL;
    }
    free(portal_session);
}

cJSON *portal_session_convertToJSON(portal_session_t *portal_session) {
    cJSON *item = cJSON_CreateObject();

    // portal_session->url
    if (!portal_session->url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "url", portal_session->url) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

portal_session_t *portal_session_parseFromJSON(cJSON *portal_sessionJSON){

    portal_session_t *portal_session_local_var = NULL;

    // portal_session->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(portal_sessionJSON, "url");
    if (cJSON_IsNull(url)) {
        url = NULL;
    }
    if (!url) {
        goto end;
    }

    
    if(!cJSON_IsString(url))
    {
    goto end; //String
    }


    portal_session_local_var = portal_session_create_internal (
        strdup(url->valuestring)
        );

    return portal_session_local_var;
end:
    return NULL;

}
