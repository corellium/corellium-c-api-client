/*
 * web_player_allowed_domains.h
 *
 * 
 */

#ifndef _web_player_allowed_domains_H_
#define _web_player_allowed_domains_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct web_player_allowed_domains_t web_player_allowed_domains_t;




typedef struct web_player_allowed_domains_t {
    list_t *allowed_domains; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} web_player_allowed_domains_t;

__attribute__((deprecated)) web_player_allowed_domains_t *web_player_allowed_domains_create(
    list_t *allowed_domains
);

void web_player_allowed_domains_free(web_player_allowed_domains_t *web_player_allowed_domains);

web_player_allowed_domains_t *web_player_allowed_domains_parseFromJSON(cJSON *web_player_allowed_domainsJSON);

cJSON *web_player_allowed_domains_convertToJSON(web_player_allowed_domains_t *web_player_allowed_domains);

#endif /* _web_player_allowed_domains_H_ */

