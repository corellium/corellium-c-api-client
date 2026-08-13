/*
 * instance_create_options.h
 *
 * 
 */

#ifndef _instance_create_options_H_
#define _instance_create_options_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instance_create_options_t instance_create_options_t;




typedef struct instance_create_options_t {
    char *shared_snapshot; // string
    char *shared_snapshot_password; // string
    char *name; // string
    char *key; // string
    char *flavor; // string
    char *project; // string
    char *os; // string
    char *osbuild; // string
    list_t *patches; //primitive container
    char *fwpackage; // string
    char *orig_fw_package_url; // string
    int encrypt; //boolean
    char *wifi_mac; // string
    int wan_access; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} instance_create_options_t;

__attribute__((deprecated)) instance_create_options_t *instance_create_options_create(
    char *shared_snapshot,
    char *shared_snapshot_password,
    char *name,
    char *key,
    char *flavor,
    char *project,
    char *os,
    char *osbuild,
    list_t *patches,
    char *fwpackage,
    char *orig_fw_package_url,
    int encrypt,
    char *wifi_mac,
    int wan_access
);

void instance_create_options_free(instance_create_options_t *instance_create_options);

instance_create_options_t *instance_create_options_parseFromJSON(cJSON *instance_create_optionsJSON);

cJSON *instance_create_options_convertToJSON(instance_create_options_t *instance_create_options);

#endif /* _instance_create_options_H_ */

