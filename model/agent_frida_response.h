/*
 * agent_frida_response.h
 *
 * 
 */

#ifndef _agent_frida_response_H_
#define _agent_frida_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct agent_frida_response_t agent_frida_response_t;




typedef struct agent_frida_response_t {
    double id; //numeric
    int success; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} agent_frida_response_t;

__attribute__((deprecated)) agent_frida_response_t *agent_frida_response_create(
    double id,
    int success
);

void agent_frida_response_free(agent_frida_response_t *agent_frida_response);

agent_frida_response_t *agent_frida_response_parseFromJSON(cJSON *agent_frida_responseJSON);

cJSON *agent_frida_response_convertToJSON(agent_frida_response_t *agent_frida_response);

#endif /* _agent_frida_response_H_ */

