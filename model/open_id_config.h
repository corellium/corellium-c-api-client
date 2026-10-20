/*
 * open_id_config.h
 *
 * 
 */

#ifndef _open_id_config_H_
#define _open_id_config_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct open_id_config_t open_id_config_t;




typedef struct open_id_config_t {
    char *discovery_url; // string
    char *client_id; // string
    char *client_secret; // string
    int invited_only; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} open_id_config_t;

__attribute__((deprecated)) open_id_config_t *open_id_config_create(
    char *discovery_url,
    char *client_id,
    char *client_secret,
    int invited_only
);

void open_id_config_free(open_id_config_t *open_id_config);

open_id_config_t *open_id_config_parseFromJSON(cJSON *open_id_configJSON);

cJSON *open_id_config_convertToJSON(open_id_config_t *open_id_config);

#endif /* _open_id_config_H_ */

