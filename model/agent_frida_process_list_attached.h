/*
 * agent_frida_process_list_attached.h
 *
 * The process Frida is currently attached to, if any.
 */

#ifndef _agent_frida_process_list_attached_H_
#define _agent_frida_process_list_attached_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct agent_frida_process_list_attached_t agent_frida_process_list_attached_t;




typedef struct agent_frida_process_list_attached_t {
    char *target_name; // string
    double target_pid; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} agent_frida_process_list_attached_t;

__attribute__((deprecated)) agent_frida_process_list_attached_t *agent_frida_process_list_attached_create(
    char *target_name,
    double target_pid
);

void agent_frida_process_list_attached_free(agent_frida_process_list_attached_t *agent_frida_process_list_attached);

agent_frida_process_list_attached_t *agent_frida_process_list_attached_parseFromJSON(cJSON *agent_frida_process_list_attachedJSON);

cJSON *agent_frida_process_list_attached_convertToJSON(agent_frida_process_list_attached_t *agent_frida_process_list_attached);

#endif /* _agent_frida_process_list_attached_H_ */

