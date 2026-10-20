#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "media_play_by_image.h"



static media_play_by_image_t *media_play_by_image_create_internal(
    char *image_id
    ) {
    media_play_by_image_t *media_play_by_image_local_var = malloc(sizeof(media_play_by_image_t));
    if (!media_play_by_image_local_var) {
        return NULL;
    }
    media_play_by_image_local_var->image_id = image_id;

    media_play_by_image_local_var->_library_owned = 1;
    return media_play_by_image_local_var;
}

__attribute__((deprecated)) media_play_by_image_t *media_play_by_image_create(
    char *image_id
    ) {
    return media_play_by_image_create_internal (
        image_id
        );
}

void media_play_by_image_free(media_play_by_image_t *media_play_by_image) {
    if(NULL == media_play_by_image){
        return ;
    }
    if(media_play_by_image->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "media_play_by_image_free");
        return ;
    }
    listEntry_t *listEntry;
    if (media_play_by_image->image_id) {
        free(media_play_by_image->image_id);
        media_play_by_image->image_id = NULL;
    }
    free(media_play_by_image);
}

cJSON *media_play_by_image_convertToJSON(media_play_by_image_t *media_play_by_image) {
    cJSON *item = cJSON_CreateObject();

    // media_play_by_image->image_id
    if (!media_play_by_image->image_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "imageId", media_play_by_image->image_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

media_play_by_image_t *media_play_by_image_parseFromJSON(cJSON *media_play_by_imageJSON){

    media_play_by_image_t *media_play_by_image_local_var = NULL;

    // media_play_by_image->image_id
    cJSON *image_id = cJSON_GetObjectItemCaseSensitive(media_play_by_imageJSON, "imageId");
    if (cJSON_IsNull(image_id)) {
        image_id = NULL;
    }
    if (!image_id) {
        goto end;
    }

    
    if(!cJSON_IsString(image_id))
    {
    goto end; //String
    }


    media_play_by_image_local_var = media_play_by_image_create_internal (
        strdup(image_id->valuestring)
        );

    return media_play_by_image_local_var;
end:
    return NULL;

}
