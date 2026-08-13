/*
 * config_response_maintenance.h
 *
 * Maintenance details when the server is undergoing maintenance; null/absent otherwise.
 */

#ifndef _config_response_maintenance_H_
#define _config_response_maintenance_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct config_response_maintenance_t config_response_maintenance_t;




typedef struct config_response_maintenance_t {
    char *message; // string
    char *header; // string

    int _library_owned; // Is the library responsible for freeing this object?
} config_response_maintenance_t;

__attribute__((deprecated)) config_response_maintenance_t *config_response_maintenance_create(
    char *message,
    char *header
);

void config_response_maintenance_free(config_response_maintenance_t *config_response_maintenance);

config_response_maintenance_t *config_response_maintenance_parseFromJSON(cJSON *config_response_maintenanceJSON);

cJSON *config_response_maintenance_convertToJSON(config_response_maintenance_t *config_response_maintenance);

#endif /* _config_response_maintenance_H_ */

