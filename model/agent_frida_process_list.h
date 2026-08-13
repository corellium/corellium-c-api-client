/*
 * agent_frida_process_list.h
 *
 * 
 */

#ifndef _agent_frida_process_list_H_
#define _agent_frida_process_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct agent_frida_process_list_t agent_frida_process_list_t;

#include "agent_frida_process_list_attached.h"



typedef struct agent_frida_process_list_t {
    int success; //boolean
    double exit_status; //numeric
    char *output; // string
    struct agent_frida_process_list_attached_t *attached; //model

    int _library_owned; // Is the library responsible for freeing this object?
} agent_frida_process_list_t;

__attribute__((deprecated)) agent_frida_process_list_t *agent_frida_process_list_create(
    int success,
    double exit_status,
    char *output,
    agent_frida_process_list_attached_t *attached
);

void agent_frida_process_list_free(agent_frida_process_list_t *agent_frida_process_list);

agent_frida_process_list_t *agent_frida_process_list_parseFromJSON(cJSON *agent_frida_process_listJSON);

cJSON *agent_frida_process_list_convertToJSON(agent_frida_process_list_t *agent_frida_process_list);

#endif /* _agent_frida_process_list_H_ */

