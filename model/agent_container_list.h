/*
 * agent_container_list.h
 *
 * 
 */

#ifndef _agent_container_list_H_
#define _agent_container_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct agent_container_list_t agent_container_list_t;

#include "agent_container.h"



typedef struct agent_container_list_t {
    list_t *containers; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} agent_container_list_t;

__attribute__((deprecated)) agent_container_list_t *agent_container_list_create(
    list_t *containers
);

void agent_container_list_free(agent_container_list_t *agent_container_list);

agent_container_list_t *agent_container_list_parseFromJSON(cJSON *agent_container_listJSON);

cJSON *agent_container_list_convertToJSON(agent_container_list_t *agent_container_list);

#endif /* _agent_container_list_H_ */

