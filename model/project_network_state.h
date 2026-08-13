/*
 * project_network_state.h
 *
 * ProjectNetworkState
 */

#ifndef _project_network_state_H_
#define _project_network_state_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct project_network_state_t project_network_state_t;

#include "any_type.h"
#include "object.h"



typedef struct project_network_state_t {
    char *state; // string
    object_t *details; //object

    int _library_owned; // Is the library responsible for freeing this object?
} project_network_state_t;

__attribute__((deprecated)) project_network_state_t *project_network_state_create(
    char *state,
    object_t *details
);

void project_network_state_free(project_network_state_t *project_network_state);

project_network_state_t *project_network_state_parseFromJSON(cJSON *project_network_stateJSON);

cJSON *project_network_state_convertToJSON(project_network_state_t *project_network_state);

#endif /* _project_network_state_H_ */

