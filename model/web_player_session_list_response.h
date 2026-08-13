/*
 * web_player_session_list_response.h
 *
 * 
 */

#ifndef _web_player_session_list_response_H_
#define _web_player_session_list_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct web_player_session_list_response_t web_player_session_list_response_t;

#include "web_player_session.h"



typedef struct web_player_session_list_response_t {
    list_t *results; //nonprimitive container
    double count; //numeric
    double total; //numeric
    double limit; //numeric
    double offset; //numeric
    int has_more; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} web_player_session_list_response_t;

__attribute__((deprecated)) web_player_session_list_response_t *web_player_session_list_response_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
);

void web_player_session_list_response_free(web_player_session_list_response_t *web_player_session_list_response);

web_player_session_list_response_t *web_player_session_list_response_parseFromJSON(cJSON *web_player_session_list_responseJSON);

cJSON *web_player_session_list_response_convertToJSON(web_player_session_list_response_t *web_player_session_list_response);

#endif /* _web_player_session_list_response_H_ */

