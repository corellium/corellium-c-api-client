/*
 * instance_services_v1.h
 *
 * 
 */

#ifndef _instance_services_v1_H_
#define _instance_services_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instance_services_v1_t instance_services_v1_t;

#include "vpn_definition_v1.h"



typedef struct instance_services_v1_t {
    struct vpn_definition_v1_t *vpn; //model

    int _library_owned; // Is the library responsible for freeing this object?
} instance_services_v1_t;

__attribute__((deprecated)) instance_services_v1_t *instance_services_v1_create(
    vpn_definition_v1_t *vpn
);

void instance_services_v1_free(instance_services_v1_t *instance_services_v1);

instance_services_v1_t *instance_services_v1_parseFromJSON(cJSON *instance_services_v1JSON);

cJSON *instance_services_v1_convertToJSON(instance_services_v1_t *instance_services_v1);

#endif /* _instance_services_v1_H_ */

