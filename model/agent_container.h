/*
 * agent_container.h
 *
 * 
 */

#ifndef _agent_container_H_
#define _agent_container_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct agent_container_t agent_container_t;




typedef struct agent_container_t {
    char *autostart; // string
    char *groups; // string
    char *ipv4; // string
    char *ipv6; // string
    char *name; // string
    char *pid; // string
    char *ram; // string
    char *state; // string
    char *swap; // string
    char *unprivileged; // string

    int _library_owned; // Is the library responsible for freeing this object?
} agent_container_t;

__attribute__((deprecated)) agent_container_t *agent_container_create(
    char *autostart,
    char *groups,
    char *ipv4,
    char *ipv6,
    char *name,
    char *pid,
    char *ram,
    char *state,
    char *swap,
    char *unprivileged
);

void agent_container_free(agent_container_t *agent_container);

agent_container_t *agent_container_parseFromJSON(cJSON *agent_containerJSON);

cJSON *agent_container_convertToJSON(agent_container_t *agent_container);

#endif /* _agent_container_H_ */

