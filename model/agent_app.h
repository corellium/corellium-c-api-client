/*
 * agent_app.h
 *
 * 
 */

#ifndef _agent_app_H_
#define _agent_app_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct agent_app_t agent_app_t;




typedef struct agent_app_t {
    list_t *tags; //primitive container
    int running; //boolean
    double disk_usage; //numeric
    double date; //numeric
    char *application_type; // string
    char *name; // string
    char *bundle_id; // string
    char *bundle_path; // string
    char *bundle_data_path; // string
    int is_launchable; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} agent_app_t;

__attribute__((deprecated)) agent_app_t *agent_app_create(
    list_t *tags,
    int running,
    double disk_usage,
    double date,
    char *application_type,
    char *name,
    char *bundle_id,
    char *bundle_path,
    char *bundle_data_path,
    int is_launchable
);

void agent_app_free(agent_app_t *agent_app);

agent_app_t *agent_app_parseFromJSON(cJSON *agent_appJSON);

cJSON *agent_app_convertToJSON(agent_app_t *agent_app);

#endif /* _agent_app_H_ */

