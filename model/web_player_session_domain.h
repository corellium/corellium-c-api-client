/*
 * web_player_session_domain.h
 *
 * Domain configuration for the session.
 */

#ifndef _web_player_session_domain_H_
#define _web_player_session_domain_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct web_player_session_domain_t web_player_session_domain_t;




typedef struct web_player_session_domain_t {
    char *name; // string
    char *label; // string
    char *terms_policy; // string
    double cores; //numeric
    int individual; //boolean
    int totp_required; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} web_player_session_domain_t;

__attribute__((deprecated)) web_player_session_domain_t *web_player_session_domain_create(
    char *name,
    char *label,
    char *terms_policy,
    double cores,
    int individual,
    int totp_required
);

void web_player_session_domain_free(web_player_session_domain_t *web_player_session_domain);

web_player_session_domain_t *web_player_session_domain_parseFromJSON(cJSON *web_player_session_domainJSON);

cJSON *web_player_session_domain_convertToJSON(web_player_session_domain_t *web_player_session_domain);

#endif /* _web_player_session_domain_H_ */

