/*
 * agent_temp_file_response.h
 *
 * 
 */

#ifndef _agent_temp_file_response_H_
#define _agent_temp_file_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct agent_temp_file_response_t agent_temp_file_response_t;




typedef struct agent_temp_file_response_t {
    char *path; // string

    int _library_owned; // Is the library responsible for freeing this object?
} agent_temp_file_response_t;

__attribute__((deprecated)) agent_temp_file_response_t *agent_temp_file_response_create(
    char *path
);

void agent_temp_file_response_free(agent_temp_file_response_t *agent_temp_file_response);

agent_temp_file_response_t *agent_temp_file_response_parseFromJSON(cJSON *agent_temp_file_responseJSON);

cJSON *agent_temp_file_response_convertToJSON(agent_temp_file_response_t *agent_temp_file_response);

#endif /* _agent_temp_file_response_H_ */

