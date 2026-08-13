/*
 * instance_boot_options_pongo_v1.h
 *
 * 
 */

#ifndef _instance_boot_options_pongo_v1_H_
#define _instance_boot_options_pongo_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instance_boot_options_pongo_v1_t instance_boot_options_pongo_v1_t;




typedef struct instance_boot_options_pongo_v1_t {
    char *id; // string
    char *name; // string
    double size; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} instance_boot_options_pongo_v1_t;

__attribute__((deprecated)) instance_boot_options_pongo_v1_t *instance_boot_options_pongo_v1_create(
    char *id,
    char *name,
    double size
);

void instance_boot_options_pongo_v1_free(instance_boot_options_pongo_v1_t *instance_boot_options_pongo_v1);

instance_boot_options_pongo_v1_t *instance_boot_options_pongo_v1_parseFromJSON(cJSON *instance_boot_options_pongo_v1JSON);

cJSON *instance_boot_options_pongo_v1_convertToJSON(instance_boot_options_pongo_v1_t *instance_boot_options_pongo_v1);

#endif /* _instance_boot_options_pongo_v1_H_ */

