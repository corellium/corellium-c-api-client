/*
 * media_play_by_image.h
 *
 * 
 */

#ifndef _media_play_by_image_H_
#define _media_play_by_image_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct media_play_by_image_t media_play_by_image_t;




typedef struct media_play_by_image_t {
    char *image_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} media_play_by_image_t;

__attribute__((deprecated)) media_play_by_image_t *media_play_by_image_create(
    char *image_id
);

void media_play_by_image_free(media_play_by_image_t *media_play_by_image);

media_play_by_image_t *media_play_by_image_parseFromJSON(cJSON *media_play_by_imageJSON);

cJSON *media_play_by_image_convertToJSON(media_play_by_image_t *media_play_by_image);

#endif /* _media_play_by_image_H_ */

