/*
 * agent_error_v1.h
 *
 * 
 */

#ifndef _agent_error_v1_H_
#define _agent_error_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct agent_error_v1_t agent_error_v1_t;

#include "any_type.h"
#include "object.h"

// Enum ERRORID for agent_error_v1

typedef enum  { corellium_api_agent_error_v1_ERRORID_NULL = 0, corellium_api_agent_error_v1_ERRORID_AgentError } corellium_api_agent_error_v1_ERRORID_e;

char* agent_error_v1_error_id_ToString(corellium_api_agent_error_v1_ERRORID_e error_id);

corellium_api_agent_error_v1_ERRORID_e agent_error_v1_error_id_FromString(char* error_id);



typedef struct agent_error_v1_t {
    char *error; // string
    corellium_api_agent_error_v1_ERRORID_e error_id; //enum
    object_t *original_error; //object

    int _library_owned; // Is the library responsible for freeing this object?
} agent_error_v1_t;

__attribute__((deprecated)) agent_error_v1_t *agent_error_v1_create(
    char *error,
    corellium_api_agent_error_v1_ERRORID_e error_id,
    object_t *original_error
);

void agent_error_v1_free(agent_error_v1_t *agent_error_v1);

agent_error_v1_t *agent_error_v1_parseFromJSON(cJSON *agent_error_v1JSON);

cJSON *agent_error_v1_convertToJSON(agent_error_v1_t *agent_error_v1);

#endif /* _agent_error_v1_H_ */

