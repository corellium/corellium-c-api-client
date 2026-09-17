/*
 * vpn_config_preauthorization.h
 *
 * 
 */

#ifndef _vpn_config_preauthorization_H_
#define _vpn_config_preauthorization_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct vpn_config_preauthorization_t vpn_config_preauthorization_t;




typedef struct vpn_config_preauthorization_t {
    char *token; // string

    int _library_owned; // Is the library responsible for freeing this object?
} vpn_config_preauthorization_t;

__attribute__((deprecated)) vpn_config_preauthorization_t *vpn_config_preauthorization_create(
    char *token
);

void vpn_config_preauthorization_free(vpn_config_preauthorization_t *vpn_config_preauthorization);

vpn_config_preauthorization_t *vpn_config_preauthorization_parseFromJSON(cJSON *vpn_config_preauthorizationJSON);

cJSON *vpn_config_preauthorization_convertToJSON(vpn_config_preauthorization_t *vpn_config_preauthorization);

#endif /* _vpn_config_preauthorization_H_ */

