/*
 * agent_remote_it_status.h
 *
 * 
 */

#ifndef _agent_remote_it_status_H_
#define _agent_remote_it_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct agent_remote_it_status_t agent_remote_it_status_t;


// Enum REMOTEITSTATUS for agent_remote_it_status

typedef enum  { corellium_api_agent_remote_it_status_REMOTEITSTATUS_NULL = 0, corellium_api_agent_remote_it_status_REMOTEITSTATUS_unknown, corellium_api_agent_remote_it_status_REMOTEITSTATUS_installed, corellium_api_agent_remote_it_status_REMOTEITSTATUS_uninstalled, corellium_api_agent_remote_it_status_REMOTEITSTATUS_installing, corellium_api_agent_remote_it_status_REMOTEITSTATUS_uninstalling, corellium_api_agent_remote_it_status_REMOTEITSTATUS_registered } corellium_api_agent_remote_it_status_REMOTEITSTATUS_e;

char* agent_remote_it_status_remote_it_status_ToString(corellium_api_agent_remote_it_status_REMOTEITSTATUS_e remote_it_status);

corellium_api_agent_remote_it_status_REMOTEITSTATUS_e agent_remote_it_status_remote_it_status_FromString(char* remote_it_status);



typedef struct agent_remote_it_status_t {
    corellium_api_agent_remote_it_status_REMOTEITSTATUS_e remote_it_status; //enum
    char *claim_code; // string

    int _library_owned; // Is the library responsible for freeing this object?
} agent_remote_it_status_t;

__attribute__((deprecated)) agent_remote_it_status_t *agent_remote_it_status_create(
    corellium_api_agent_remote_it_status_REMOTEITSTATUS_e remote_it_status,
    char *claim_code
);

void agent_remote_it_status_free(agent_remote_it_status_t *agent_remote_it_status);

agent_remote_it_status_t *agent_remote_it_status_parseFromJSON(cJSON *agent_remote_it_statusJSON);

cJSON *agent_remote_it_status_convertToJSON(agent_remote_it_status_t *agent_remote_it_status);

#endif /* _agent_remote_it_status_H_ */

