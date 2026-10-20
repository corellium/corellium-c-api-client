/*
 * web_player_created_session.h
 *
 * 
 */

#ifndef _web_player_created_session_H_
#define _web_player_created_session_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct web_player_created_session_t web_player_created_session_t;

#include "web_player_session_domain.h"



typedef struct web_player_created_session_t {
    char *identifier; // string
    char *token; // string
    char *expiration; //date time
    struct web_player_session_domain_t *domain; //model
    double time; //numeric
    int disabled; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} web_player_created_session_t;

__attribute__((deprecated)) web_player_created_session_t *web_player_created_session_create(
    char *identifier,
    char *token,
    char *expiration,
    web_player_session_domain_t *domain,
    double time,
    int disabled
);

void web_player_created_session_free(web_player_created_session_t *web_player_created_session);

web_player_created_session_t *web_player_created_session_parseFromJSON(cJSON *web_player_created_sessionJSON);

cJSON *web_player_created_session_convertToJSON(web_player_created_session_t *web_player_created_session);

#endif /* _web_player_created_session_H_ */

