/*
 * agent_container_health.h
 *
 * 
 */

#ifndef _agent_container_health_H_
#define _agent_container_health_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct agent_container_health_t agent_container_health_t;




typedef struct agent_container_health_t {
    int healthy; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} agent_container_health_t;

__attribute__((deprecated)) agent_container_health_t *agent_container_health_create(
    int healthy
);

void agent_container_health_free(agent_container_health_t *agent_container_health);

agent_container_health_t *agent_container_health_parseFromJSON(cJSON *agent_container_healthJSON);

cJSON *agent_container_health_convertToJSON(agent_container_health_t *agent_container_health);

#endif /* _agent_container_health_H_ */

