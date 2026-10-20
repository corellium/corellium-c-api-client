/*
 * domain_config_input_webplayer.h
 *
 * Webplayer configuration.
 */

#ifndef _domain_config_input_webplayer_H_
#define _domain_config_input_webplayer_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct domain_config_input_webplayer_t domain_config_input_webplayer_t;




typedef struct domain_config_input_webplayer_t {
    int enabled; //boolean
    list_t *allowed_domains; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} domain_config_input_webplayer_t;

__attribute__((deprecated)) domain_config_input_webplayer_t *domain_config_input_webplayer_create(
    int enabled,
    list_t *allowed_domains
);

void domain_config_input_webplayer_free(domain_config_input_webplayer_t *domain_config_input_webplayer);

domain_config_input_webplayer_t *domain_config_input_webplayer_parseFromJSON(cJSON *domain_config_input_webplayerJSON);

cJSON *domain_config_input_webplayer_convertToJSON(domain_config_input_webplayer_t *domain_config_input_webplayer);

#endif /* _domain_config_input_webplayer_H_ */

