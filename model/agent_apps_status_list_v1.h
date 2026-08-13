/*
 * agent_apps_status_list_v1.h
 *
 * 
 */

#ifndef _agent_apps_status_list_v1_H_
#define _agent_apps_status_list_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct agent_apps_status_list_v1_t agent_apps_status_list_v1_t;

#include "agent_app_status_v1.h"



typedef struct agent_apps_status_list_v1_t {
    list_t *apps; //nonprimitive container
    char *frontmost; // string

    int _library_owned; // Is the library responsible for freeing this object?
} agent_apps_status_list_v1_t;

__attribute__((deprecated)) agent_apps_status_list_v1_t *agent_apps_status_list_v1_create(
    list_t *apps,
    char *frontmost
);

void agent_apps_status_list_v1_free(agent_apps_status_list_v1_t *agent_apps_status_list_v1);

agent_apps_status_list_v1_t *agent_apps_status_list_v1_parseFromJSON(cJSON *agent_apps_status_list_v1JSON);

cJSON *agent_apps_status_list_v1_convertToJSON(agent_apps_status_list_v1_t *agent_apps_status_list_v1);

#endif /* _agent_apps_status_list_v1_H_ */

