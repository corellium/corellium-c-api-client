/*
 * agent_frida_run_body.h
 *
 * 
 */

#ifndef _agent_frida_run_body_H_
#define _agent_frida_run_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct agent_frida_run_body_t agent_frida_run_body_t;




typedef struct agent_frida_run_body_t {
    char *target_pid; // string
    char *target_name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} agent_frida_run_body_t;

__attribute__((deprecated)) agent_frida_run_body_t *agent_frida_run_body_create(
    char *target_pid,
    char *target_name
);

void agent_frida_run_body_free(agent_frida_run_body_t *agent_frida_run_body);

agent_frida_run_body_t *agent_frida_run_body_parseFromJSON(cJSON *agent_frida_run_bodyJSON);

cJSON *agent_frida_run_body_convertToJSON(agent_frida_run_body_t *agent_frida_run_body);

#endif /* _agent_frida_run_body_H_ */

