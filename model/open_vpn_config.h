/*
 * open_vpn_config.h
 *
 * 
 */

#ifndef _open_vpn_config_H_
#define _open_vpn_config_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct open_vpn_config_t open_vpn_config_t;




typedef struct open_vpn_config_t {
    char *username; // string
    char *password; // string
    char *config; // string

    int _library_owned; // Is the library responsible for freeing this object?
} open_vpn_config_t;

__attribute__((deprecated)) open_vpn_config_t *open_vpn_config_create(
    char *username,
    char *password,
    char *config
);

void open_vpn_config_free(open_vpn_config_t *open_vpn_config);

open_vpn_config_t *open_vpn_config_parseFromJSON(cJSON *open_vpn_configJSON);

cJSON *open_vpn_config_convertToJSON(open_vpn_config_t *open_vpn_config);

#endif /* _open_vpn_config_H_ */

