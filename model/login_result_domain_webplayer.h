/*
 * login_result_domain_webplayer.h
 *
 * Webplayer configuration.
 */

#ifndef _login_result_domain_webplayer_H_
#define _login_result_domain_webplayer_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct login_result_domain_webplayer_t login_result_domain_webplayer_t;




typedef struct login_result_domain_webplayer_t {
    int enabled; //boolean
    list_t *allowed_domains; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} login_result_domain_webplayer_t;

__attribute__((deprecated)) login_result_domain_webplayer_t *login_result_domain_webplayer_create(
    int enabled,
    list_t *allowed_domains
);

void login_result_domain_webplayer_free(login_result_domain_webplayer_t *login_result_domain_webplayer);

login_result_domain_webplayer_t *login_result_domain_webplayer_parseFromJSON(cJSON *login_result_domain_webplayerJSON);

cJSON *login_result_domain_webplayer_convertToJSON(login_result_domain_webplayer_t *login_result_domain_webplayer);

#endif /* _login_result_domain_webplayer_H_ */

