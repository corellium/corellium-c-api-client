/*
 * patch_domain_body_webplayer.h
 *
 * Web player settings.
 */

#ifndef _patch_domain_body_webplayer_H_
#define _patch_domain_body_webplayer_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct patch_domain_body_webplayer_t patch_domain_body_webplayer_t;




typedef struct patch_domain_body_webplayer_t {
    list_t *allowed_domains; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} patch_domain_body_webplayer_t;

__attribute__((deprecated)) patch_domain_body_webplayer_t *patch_domain_body_webplayer_create(
    list_t *allowed_domains
);

void patch_domain_body_webplayer_free(patch_domain_body_webplayer_t *patch_domain_body_webplayer);

patch_domain_body_webplayer_t *patch_domain_body_webplayer_parseFromJSON(cJSON *patch_domain_body_webplayerJSON);

cJSON *patch_domain_body_webplayer_convertToJSON(patch_domain_body_webplayer_t *patch_domain_body_webplayer);

#endif /* _patch_domain_body_webplayer_H_ */

