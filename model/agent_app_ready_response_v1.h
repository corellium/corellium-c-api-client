/*
 * agent_app_ready_response_v1.h
 *
 * 
 */

#ifndef _agent_app_ready_response_v1_H_
#define _agent_app_ready_response_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct agent_app_ready_response_v1_t agent_app_ready_response_v1_t;




typedef struct agent_app_ready_response_v1_t {
    int ready; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} agent_app_ready_response_v1_t;

__attribute__((deprecated)) agent_app_ready_response_v1_t *agent_app_ready_response_v1_create(
    int ready
);

void agent_app_ready_response_v1_free(agent_app_ready_response_v1_t *agent_app_ready_response_v1);

agent_app_ready_response_v1_t *agent_app_ready_response_v1_parseFromJSON(cJSON *agent_app_ready_response_v1JSON);

cJSON *agent_app_ready_response_v1_convertToJSON(agent_app_ready_response_v1_t *agent_app_ready_response_v1);

#endif /* _agent_app_ready_response_v1_H_ */

