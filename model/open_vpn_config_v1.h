/*
 * open_vpn_config_v1.h
 *
 * 
 */

#ifndef _open_vpn_config_v1_H_
#define _open_vpn_config_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct open_vpn_config_v1_t open_vpn_config_v1_t;




typedef struct open_vpn_config_v1_t {
    char *username; // string
    char *password; // string
    char *config; // string

    int _library_owned; // Is the library responsible for freeing this object?
} open_vpn_config_v1_t;

__attribute__((deprecated)) open_vpn_config_v1_t *open_vpn_config_v1_create(
    char *username,
    char *password,
    char *config
);

void open_vpn_config_v1_free(open_vpn_config_v1_t *open_vpn_config_v1);

open_vpn_config_v1_t *open_vpn_config_v1_parseFromJSON(cJSON *open_vpn_config_v1JSON);

cJSON *open_vpn_config_v1_convertToJSON(open_vpn_config_v1_t *open_vpn_config_v1);

#endif /* _open_vpn_config_v1_H_ */

