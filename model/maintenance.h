/*
 * maintenance.h
 *
 * 
 */

#ifndef _maintenance_H_
#define _maintenance_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct maintenance_t maintenance_t;




typedef struct maintenance_t {
    char *message; // string
    char *header; // string

    int _library_owned; // Is the library responsible for freeing this object?
} maintenance_t;

__attribute__((deprecated)) maintenance_t *maintenance_create(
    char *message,
    char *header
);

void maintenance_free(maintenance_t *maintenance);

maintenance_t *maintenance_parseFromJSON(cJSON *maintenanceJSON);

cJSON *maintenance_convertToJSON(maintenance_t *maintenance);

#endif /* _maintenance_H_ */

