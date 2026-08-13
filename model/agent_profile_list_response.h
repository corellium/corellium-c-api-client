/*
 * agent_profile_list_response.h
 *
 * 
 */

#ifndef _agent_profile_list_response_H_
#define _agent_profile_list_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct agent_profile_list_response_t agent_profile_list_response_t;




typedef struct agent_profile_list_response_t {
    list_t *profiles; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} agent_profile_list_response_t;

__attribute__((deprecated)) agent_profile_list_response_t *agent_profile_list_response_create(
    list_t *profiles
);

void agent_profile_list_response_free(agent_profile_list_response_t *agent_profile_list_response);

agent_profile_list_response_t *agent_profile_list_response_parseFromJSON(cJSON *agent_profile_list_responseJSON);

cJSON *agent_profile_list_response_convertToJSON(agent_profile_list_response_t *agent_profile_list_response);

#endif /* _agent_profile_list_response_H_ */

