/*
 * instance_console.h
 *
 * 
 */

#ifndef _instance_console_H_
#define _instance_console_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instance_console_t instance_console_t;




typedef struct instance_console_t {
    char *name; // string
    char *id; // string
    char *port; // string
    char *hash; // string
    char *info; // string

    int _library_owned; // Is the library responsible for freeing this object?
} instance_console_t;

__attribute__((deprecated)) instance_console_t *instance_console_create(
    char *name,
    char *id,
    char *port,
    char *hash,
    char *info
);

void instance_console_free(instance_console_t *instance_console);

instance_console_t *instance_console_parseFromJSON(cJSON *instance_consoleJSON);

cJSON *instance_console_convertToJSON(instance_console_t *instance_console);

#endif /* _instance_console_H_ */

