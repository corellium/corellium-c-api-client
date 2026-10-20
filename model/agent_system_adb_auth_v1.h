/*
 * agent_system_adb_auth_v1.h
 *
 * 
 */

#ifndef _agent_system_adb_auth_v1_H_
#define _agent_system_adb_auth_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct agent_system_adb_auth_v1_t agent_system_adb_auth_v1_t;




typedef struct agent_system_adb_auth_v1_t {
    int enabled; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} agent_system_adb_auth_v1_t;

__attribute__((deprecated)) agent_system_adb_auth_v1_t *agent_system_adb_auth_v1_create(
    int enabled
);

void agent_system_adb_auth_v1_free(agent_system_adb_auth_v1_t *agent_system_adb_auth_v1);

agent_system_adb_auth_v1_t *agent_system_adb_auth_v1_parseFromJSON(cJSON *agent_system_adb_auth_v1JSON);

cJSON *agent_system_adb_auth_v1_convertToJSON(agent_system_adb_auth_v1_t *agent_system_adb_auth_v1);

#endif /* _agent_system_adb_auth_v1_H_ */

