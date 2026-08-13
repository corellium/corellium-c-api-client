/*
 * create_web_player_session_body.h
 *
 * 
 */

#ifndef _create_web_player_session_body_H_
#define _create_web_player_session_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_web_player_session_body_t create_web_player_session_body_t;

#include "web_player_features.h"



typedef struct create_web_player_session_body_t {
    char *project_id; // string
    char *instance_id; // string
    double expires_in; //numeric
    struct web_player_features_t *features; //model
    char *client_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} create_web_player_session_body_t;

__attribute__((deprecated)) create_web_player_session_body_t *create_web_player_session_body_create(
    char *project_id,
    char *instance_id,
    double expires_in,
    web_player_features_t *features,
    char *client_id
);

void create_web_player_session_body_free(create_web_player_session_body_t *create_web_player_session_body);

create_web_player_session_body_t *create_web_player_session_body_parseFromJSON(cJSON *create_web_player_session_bodyJSON);

cJSON *create_web_player_session_body_convertToJSON(create_web_player_session_body_t *create_web_player_session_body);

#endif /* _create_web_player_session_body_H_ */

