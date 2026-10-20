/*
 * media_play_by_url.h
 *
 * 
 */

#ifndef _media_play_by_url_H_
#define _media_play_by_url_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct media_play_by_url_t media_play_by_url_t;




typedef struct media_play_by_url_t {
    char *url; // string

    int _library_owned; // Is the library responsible for freeing this object?
} media_play_by_url_t;

__attribute__((deprecated)) media_play_by_url_t *media_play_by_url_create(
    char *url
);

void media_play_by_url_free(media_play_by_url_t *media_play_by_url);

media_play_by_url_t *media_play_by_url_parseFromJSON(cJSON *media_play_by_urlJSON);

cJSON *media_play_by_url_convertToJSON(media_play_by_url_t *media_play_by_url);

#endif /* _media_play_by_url_H_ */

