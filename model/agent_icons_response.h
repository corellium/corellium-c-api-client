/*
 * agent_icons_response.h
 *
 * 
 */

#ifndef _agent_icons_response_H_
#define _agent_icons_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct agent_icons_response_t agent_icons_response_t;

#include "any_type.h"
#include "object.h"



typedef struct agent_icons_response_t {
    int success; //boolean
    double id; //numeric
    object_t *icons; //object

    int _library_owned; // Is the library responsible for freeing this object?
} agent_icons_response_t;

__attribute__((deprecated)) agent_icons_response_t *agent_icons_response_create(
    int success,
    double id,
    object_t *icons
);

void agent_icons_response_free(agent_icons_response_t *agent_icons_response);

agent_icons_response_t *agent_icons_response_parseFromJSON(cJSON *agent_icons_responseJSON);

cJSON *agent_icons_response_convertToJSON(agent_icons_response_t *agent_icons_response);

#endif /* _agent_icons_response_H_ */

