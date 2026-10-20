/*
 * project_settings_v1.h
 *
 * 
 */

#ifndef _project_settings_v1_H_
#define _project_settings_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct project_settings_v1_t project_settings_v1_t;




typedef struct project_settings_v1_t {
    double version; //numeric
    int internet_access; //boolean
    char *connection; // string
    int dhcp; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} project_settings_v1_t;

__attribute__((deprecated)) project_settings_v1_t *project_settings_v1_create(
    double version,
    int internet_access,
    char *connection,
    int dhcp
);

void project_settings_v1_free(project_settings_v1_t *project_settings_v1);

project_settings_v1_t *project_settings_v1_parseFromJSON(cJSON *project_settings_v1JSON);

cJSON *project_settings_v1_convertToJSON(project_settings_v1_t *project_settings_v1);

#endif /* _project_settings_v1_H_ */

