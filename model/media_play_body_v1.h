/*
 * media_play_body_v1.h
 *
 * 
 */

#ifndef _media_play_body_v1_H_
#define _media_play_body_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct media_play_body_v1_t media_play_body_v1_t;




typedef struct media_play_body_v1_t {
    char *image_id; // string
    char *url; // string

    int _library_owned; // Is the library responsible for freeing this object?
} media_play_body_v1_t;

__attribute__((deprecated)) media_play_body_v1_t *media_play_body_v1_create(
    char *image_id,
    char *url
);

void media_play_body_v1_free(media_play_body_v1_t *media_play_body_v1);

media_play_body_v1_t *media_play_body_v1_parseFromJSON(cJSON *media_play_body_v1JSON);

cJSON *media_play_body_v1_convertToJSON(media_play_body_v1_t *media_play_body_v1);

#endif /* _media_play_body_v1_H_ */

