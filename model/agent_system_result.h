/*
 * agent_system_result.h
 *
 * 
 */

#ifndef _agent_system_result_H_
#define _agent_system_result_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct agent_system_result_t agent_system_result_t;




typedef struct agent_system_result_t {
    double id; //numeric
    int success; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} agent_system_result_t;

__attribute__((deprecated)) agent_system_result_t *agent_system_result_create(
    double id,
    int success
);

void agent_system_result_free(agent_system_result_t *agent_system_result);

agent_system_result_t *agent_system_result_parseFromJSON(cJSON *agent_system_resultJSON);

cJSON *agent_system_result_convertToJSON(agent_system_result_t *agent_system_result);

#endif /* _agent_system_result_H_ */

