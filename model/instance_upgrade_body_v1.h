/*
 * instance_upgrade_body_v1.h
 *
 * 
 */

#ifndef _instance_upgrade_body_v1_H_
#define _instance_upgrade_body_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instance_upgrade_body_v1_t instance_upgrade_body_v1_t;




typedef struct instance_upgrade_body_v1_t {
    char *os; // string
    char *osbuild; // string

    int _library_owned; // Is the library responsible for freeing this object?
} instance_upgrade_body_v1_t;

__attribute__((deprecated)) instance_upgrade_body_v1_t *instance_upgrade_body_v1_create(
    char *os,
    char *osbuild
);

void instance_upgrade_body_v1_free(instance_upgrade_body_v1_t *instance_upgrade_body_v1);

instance_upgrade_body_v1_t *instance_upgrade_body_v1_parseFromJSON(cJSON *instance_upgrade_body_v1JSON);

cJSON *instance_upgrade_body_v1_convertToJSON(instance_upgrade_body_v1_t *instance_upgrade_body_v1);

#endif /* _instance_upgrade_body_v1_H_ */

