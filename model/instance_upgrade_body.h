/*
 * instance_upgrade_body.h
 *
 * 
 */

#ifndef _instance_upgrade_body_H_
#define _instance_upgrade_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instance_upgrade_body_t instance_upgrade_body_t;




typedef struct instance_upgrade_body_t {
    char *os_version; // string
    char *os_build; // string
    char *image_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} instance_upgrade_body_t;

__attribute__((deprecated)) instance_upgrade_body_t *instance_upgrade_body_create(
    char *os_version,
    char *os_build,
    char *image_id
);

void instance_upgrade_body_free(instance_upgrade_body_t *instance_upgrade_body);

instance_upgrade_body_t *instance_upgrade_body_parseFromJSON(cJSON *instance_upgrade_bodyJSON);

cJSON *instance_upgrade_body_convertToJSON(instance_upgrade_body_t *instance_upgrade_body);

#endif /* _instance_upgrade_body_H_ */

