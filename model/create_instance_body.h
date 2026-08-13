/*
 * create_instance_body.h
 *
 * 
 */

#ifndef _create_instance_body_H_
#define _create_instance_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_instance_body_t create_instance_body_t;

#include "any_type.h"
#include "instance_boot_options.h"
#include "object.h"
#include "volume_options.h"



typedef struct create_instance_body_t {
    char *shared_snapshot; // string
    char *shared_snapshot_password; // string
    char *name; // string
    char *key; // string
    char *flavor; // string
    char *project_id; // string
    char *os_version; // string
    char *os_build; // string
    list_t *patches; //primitive container
    object_t *fw_package; //object
    char *original_firmware_package_url; // string
    int encrypt; //boolean
    char *wifi_mac; // string
    int wan_access; //boolean
    struct volume_options_t *volume; //model
    char *snapshot; // string
    struct instance_boot_options_t *boot_options; //model
    int sbs; //boolean
    list_t *charm_boot_args; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} create_instance_body_t;

__attribute__((deprecated)) create_instance_body_t *create_instance_body_create(
    char *shared_snapshot,
    char *shared_snapshot_password,
    char *name,
    char *key,
    char *flavor,
    char *project_id,
    char *os_version,
    char *os_build,
    list_t *patches,
    object_t *fw_package,
    char *original_firmware_package_url,
    int encrypt,
    char *wifi_mac,
    int wan_access,
    volume_options_t *volume,
    char *snapshot,
    instance_boot_options_t *boot_options,
    int sbs,
    list_t *charm_boot_args
);

void create_instance_body_free(create_instance_body_t *create_instance_body);

create_instance_body_t *create_instance_body_parseFromJSON(cJSON *create_instance_bodyJSON);

cJSON *create_instance_body_convertToJSON(create_instance_body_t *create_instance_body);

#endif /* _create_instance_body_H_ */

