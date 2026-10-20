#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "media_play_body_v1.h"



static media_play_body_v1_t *media_play_body_v1_create_internal(
    char *image_id,
    char *url
    ) {
    media_play_body_v1_t *media_play_body_v1_local_var = malloc(sizeof(media_play_body_v1_t));
    if (!media_play_body_v1_local_var) {
        return NULL;
    }
    media_play_body_v1_local_var->image_id = image_id;
    media_play_body_v1_local_var->url = url;

    media_play_body_v1_local_var->_library_owned = 1;
    return media_play_body_v1_local_var;
}

__attribute__((deprecated)) media_play_body_v1_t *media_play_body_v1_create(
    char *image_id,
    char *url
    ) {
    return media_play_body_v1_create_internal (
        image_id,
        url
        );
}

void media_play_body_v1_free(media_play_body_v1_t *media_play_body_v1) {
    if(NULL == media_play_body_v1){
        return ;
    }
    if(media_play_body_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "media_play_body_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (media_play_body_v1->image_id) {
        free(media_play_body_v1->image_id);
        media_play_body_v1->image_id = NULL;
    }
    if (media_play_body_v1->url) {
        free(media_play_body_v1->url);
        media_play_body_v1->url = NULL;
    }
    free(media_play_body_v1);
}

cJSON *media_play_body_v1_convertToJSON(media_play_body_v1_t *media_play_body_v1) {
    cJSON *item = cJSON_CreateObject();

    // media_play_body_v1->image_id
    if(media_play_body_v1->image_id) {
    if(cJSON_AddStringToObject(item, "imageId", media_play_body_v1->image_id) == NULL) {
    goto fail; //String
    }
    }


    // media_play_body_v1->url
    if(media_play_body_v1->url) {
    if(cJSON_AddStringToObject(item, "url", media_play_body_v1->url) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

media_play_body_v1_t *media_play_body_v1_parseFromJSON(cJSON *media_play_body_v1JSON){

    media_play_body_v1_t *media_play_body_v1_local_var = NULL;

    // media_play_body_v1->image_id
    cJSON *image_id = cJSON_GetObjectItemCaseSensitive(media_play_body_v1JSON, "imageId");
    if (cJSON_IsNull(image_id)) {
        image_id = NULL;
    }
    if (image_id) { 
    if(!cJSON_IsString(image_id) && !cJSON_IsNull(image_id))
    {
    goto end; //String
    }
    }

    // media_play_body_v1->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(media_play_body_v1JSON, "url");
    if (cJSON_IsNull(url)) {
        url = NULL;
    }
    if (url) { 
    if(!cJSON_IsString(url) && !cJSON_IsNull(url))
    {
    goto end; //String
    }
    }


    media_play_body_v1_local_var = media_play_body_v1_create_internal (
        image_id && !cJSON_IsNull(image_id) ? strdup(image_id->valuestring) : NULL,
        url && !cJSON_IsNull(url) ? strdup(url->valuestring) : NULL
        );

    return media_play_body_v1_local_var;
end:
    return NULL;

}
