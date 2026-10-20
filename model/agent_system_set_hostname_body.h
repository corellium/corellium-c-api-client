/*
 * agent_system_set_hostname_body.h
 *
 * 
 */

#ifndef _agent_system_set_hostname_body_H_
#define _agent_system_set_hostname_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct agent_system_set_hostname_body_t agent_system_set_hostname_body_t;




typedef struct agent_system_set_hostname_body_t {
    char *hostname; // string

    int _library_owned; // Is the library responsible for freeing this object?
} agent_system_set_hostname_body_t;

__attribute__((deprecated)) agent_system_set_hostname_body_t *agent_system_set_hostname_body_create(
    char *hostname
);

void agent_system_set_hostname_body_free(agent_system_set_hostname_body_t *agent_system_set_hostname_body);

agent_system_set_hostname_body_t *agent_system_set_hostname_body_parseFromJSON(cJSON *agent_system_set_hostname_bodyJSON);

cJSON *agent_system_set_hostname_body_convertToJSON(agent_system_set_hostname_body_t *agent_system_set_hostname_body);

#endif /* _agent_system_set_hostname_body_H_ */

