/*
 * update_domain_settings_response_webplayer.h
 *
 * Applied web player settings.
 */

#ifndef _update_domain_settings_response_webplayer_H_
#define _update_domain_settings_response_webplayer_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct update_domain_settings_response_webplayer_t update_domain_settings_response_webplayer_t;




typedef struct update_domain_settings_response_webplayer_t {
    list_t *allowed_domains; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} update_domain_settings_response_webplayer_t;

__attribute__((deprecated)) update_domain_settings_response_webplayer_t *update_domain_settings_response_webplayer_create(
    list_t *allowed_domains
);

void update_domain_settings_response_webplayer_free(update_domain_settings_response_webplayer_t *update_domain_settings_response_webplayer);

update_domain_settings_response_webplayer_t *update_domain_settings_response_webplayer_parseFromJSON(cJSON *update_domain_settings_response_webplayerJSON);

cJSON *update_domain_settings_response_webplayer_convertToJSON(update_domain_settings_response_webplayer_t *update_domain_settings_response_webplayer);

#endif /* _update_domain_settings_response_webplayer_H_ */

