/*
 * instance_interface_status.h
 *
 * 
 */

#ifndef _instance_interface_status_H_
#define _instance_interface_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instance_interface_status_t instance_interface_status_t;


// Enum STATUS for instance_interface_status

typedef enum  { corellium_api_instance_interface_status_STATUS_NULL = 0, corellium_api_instance_interface_status_STATUS_attached, corellium_api_instance_interface_status_STATUS_detached, corellium_api_instance_interface_status_STATUS_connected } corellium_api_instance_interface_status_STATUS_e;

char* instance_interface_status_status_ToString(corellium_api_instance_interface_status_STATUS_e status);

corellium_api_instance_interface_status_STATUS_e instance_interface_status_status_FromString(char* status);



typedef struct instance_interface_status_t {
    char *interface_id; // string
    char *interconnect_id; // string
    corellium_api_instance_interface_status_STATUS_e status; //enum

    int _library_owned; // Is the library responsible for freeing this object?
} instance_interface_status_t;

__attribute__((deprecated)) instance_interface_status_t *instance_interface_status_create(
    char *interface_id,
    char *interconnect_id,
    corellium_api_instance_interface_status_STATUS_e status
);

void instance_interface_status_free(instance_interface_status_t *instance_interface_status);

instance_interface_status_t *instance_interface_status_parseFromJSON(cJSON *instance_interface_statusJSON);

cJSON *instance_interface_status_convertToJSON(instance_interface_status_t *instance_interface_status);

#endif /* _instance_interface_status_H_ */

