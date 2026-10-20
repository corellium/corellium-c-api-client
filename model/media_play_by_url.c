#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "media_play_by_url.h"



static media_play_by_url_t *media_play_by_url_create_internal(
    char *url
    ) {
    media_play_by_url_t *media_play_by_url_local_var = malloc(sizeof(media_play_by_url_t));
    if (!media_play_by_url_local_var) {
        return NULL;
    }
    media_play_by_url_local_var->url = url;

    media_play_by_url_local_var->_library_owned = 1;
    return media_play_by_url_local_var;
}

__attribute__((deprecated)) media_play_by_url_t *media_play_by_url_create(
    char *url
    ) {
    return media_play_by_url_create_internal (
        url
        );
}

void media_play_by_url_free(media_play_by_url_t *media_play_by_url) {
    if(NULL == media_play_by_url){
        return ;
    }
    if(media_play_by_url->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "media_play_by_url_free");
        return ;
    }
    listEntry_t *listEntry;
    if (media_play_by_url->url) {
        free(media_play_by_url->url);
        media_play_by_url->url = NULL;
    }
    free(media_play_by_url);
}

cJSON *media_play_by_url_convertToJSON(media_play_by_url_t *media_play_by_url) {
    cJSON *item = cJSON_CreateObject();

    // media_play_by_url->url
    if (!media_play_by_url->url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "url", media_play_by_url->url) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

media_play_by_url_t *media_play_by_url_parseFromJSON(cJSON *media_play_by_urlJSON){

    media_play_by_url_t *media_play_by_url_local_var = NULL;

    // media_play_by_url->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(media_play_by_urlJSON, "url");
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


    media_play_by_url_local_var = media_play_by_url_create_internal (
        strdup(url->valuestring)
        );

    return media_play_by_url_local_var;
end:
    return NULL;

}
