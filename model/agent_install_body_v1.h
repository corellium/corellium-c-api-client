/*
 * agent_install_body_v1.h
 *
 * 
 */

#ifndef _agent_install_body_v1_H_
#define _agent_install_body_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct agent_install_body_v1_t agent_install_body_v1_t;




typedef struct agent_install_body_v1_t {
    char *path; // string

    int _library_owned; // Is the library responsible for freeing this object?
} agent_install_body_v1_t;

__attribute__((deprecated)) agent_install_body_v1_t *agent_install_body_v1_create(
    char *path
);

void agent_install_body_v1_free(agent_install_body_v1_t *agent_install_body_v1);

agent_install_body_v1_t *agent_install_body_v1_parseFromJSON(cJSON *agent_install_body_v1JSON);

cJSON *agent_install_body_v1_convertToJSON(agent_install_body_v1_t *agent_install_body_v1);

#endif /* _agent_install_body_v1_H_ */

