/*
 * instance_boot_options_pongo.h
 *
 * 
 */

#ifndef _instance_boot_options_pongo_H_
#define _instance_boot_options_pongo_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instance_boot_options_pongo_t instance_boot_options_pongo_t;




typedef struct instance_boot_options_pongo_t {
    char *id; // string
    char *name; // string
    double size; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} instance_boot_options_pongo_t;

__attribute__((deprecated)) instance_boot_options_pongo_t *instance_boot_options_pongo_create(
    char *id,
    char *name,
    double size
);

void instance_boot_options_pongo_free(instance_boot_options_pongo_t *instance_boot_options_pongo);

instance_boot_options_pongo_t *instance_boot_options_pongo_parseFromJSON(cJSON *instance_boot_options_pongoJSON);

cJSON *instance_boot_options_pongo_convertToJSON(instance_boot_options_pongo_t *instance_boot_options_pongo);

#endif /* _instance_boot_options_pongo_H_ */

