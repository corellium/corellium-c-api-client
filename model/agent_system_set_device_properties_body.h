/*
 * agent_system_set_device_properties_body.h
 *
 * 
 */

#ifndef _agent_system_set_device_properties_body_H_
#define _agent_system_set_device_properties_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct agent_system_set_device_properties_body_t agent_system_set_device_properties_body_t;




typedef struct agent_system_set_device_properties_body_t {
    char *model_id; // string
    char *manufacturer_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} agent_system_set_device_properties_body_t;

__attribute__((deprecated)) agent_system_set_device_properties_body_t *agent_system_set_device_properties_body_create(
    char *model_id,
    char *manufacturer_id
);

void agent_system_set_device_properties_body_free(agent_system_set_device_properties_body_t *agent_system_set_device_properties_body);

agent_system_set_device_properties_body_t *agent_system_set_device_properties_body_parseFromJSON(cJSON *agent_system_set_device_properties_bodyJSON);

cJSON *agent_system_set_device_properties_body_convertToJSON(agent_system_set_device_properties_body_t *agent_system_set_device_properties_body);

#endif /* _agent_system_set_device_properties_body_H_ */

