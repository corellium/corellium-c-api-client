/*
 * extension_flavor.h
 *
 * 
 */

#ifndef _extension_flavor_H_
#define _extension_flavor_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct extension_flavor_t extension_flavor_t;




typedef struct extension_flavor_t {
    char *type; // string
    char *flavor; // string
    char *flavor_id; // string
    char *product; // string
    double cores; //numeric
    double ram; //numeric
    int supports_gdb; //boolean
    int supports_serial_console; //boolean
    int supports_preset_boot_options; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} extension_flavor_t;

__attribute__((deprecated)) extension_flavor_t *extension_flavor_create(
    char *type,
    char *flavor,
    char *flavor_id,
    char *product,
    double cores,
    double ram,
    int supports_gdb,
    int supports_serial_console,
    int supports_preset_boot_options
);

void extension_flavor_free(extension_flavor_t *extension_flavor);

extension_flavor_t *extension_flavor_parseFromJSON(cJSON *extension_flavorJSON);

cJSON *extension_flavor_convertToJSON(extension_flavor_t *extension_flavor);

#endif /* _extension_flavor_H_ */

