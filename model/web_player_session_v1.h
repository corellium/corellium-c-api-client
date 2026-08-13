/*
 * web_player_session_v1.h
 *
 * 
 */

#ifndef _web_player_session_v1_H_
#define _web_player_session_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct web_player_session_v1_t web_player_session_v1_t;




typedef struct web_player_session_v1_t {
    char *identifier; // string
    char *token; // string
    double expiration; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} web_player_session_v1_t;

__attribute__((deprecated)) web_player_session_v1_t *web_player_session_v1_create(
    char *identifier,
    char *token,
    double expiration
);

void web_player_session_v1_free(web_player_session_v1_t *web_player_session_v1);

web_player_session_v1_t *web_player_session_v1_parseFromJSON(cJSON *web_player_session_v1JSON);

cJSON *web_player_session_v1_convertToJSON(web_player_session_v1_t *web_player_session_v1);

#endif /* _web_player_session_v1_H_ */

