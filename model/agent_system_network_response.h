/*
 * agent_system_network_response.h
 *
 * 
 */

#ifndef _agent_system_network_response_H_
#define _agent_system_network_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct agent_system_network_response_t agent_system_network_response_t;




typedef struct agent_system_network_response_t {
    char *value; // string

    int _library_owned; // Is the library responsible for freeing this object?
} agent_system_network_response_t;

__attribute__((deprecated)) agent_system_network_response_t *agent_system_network_response_create(
    char *value
);

void agent_system_network_response_free(agent_system_network_response_t *agent_system_network_response);

agent_system_network_response_t *agent_system_network_response_parseFromJSON(cJSON *agent_system_network_responseJSON);

cJSON *agent_system_network_response_convertToJSON(agent_system_network_response_t *agent_system_network_response);

#endif /* _agent_system_network_response_H_ */

