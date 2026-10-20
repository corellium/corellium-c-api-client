/*
 * project_config.h
 *
 * Project configuration.
 */

#ifndef _project_config_H_
#define _project_config_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct project_config_t project_config_t;




typedef struct project_config_t {
    double color; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} project_config_t;

__attribute__((deprecated)) project_config_t *project_config_create(
    double color
);

void project_config_free(project_config_t *project_config);

project_config_t *project_config_parseFromJSON(cJSON *project_configJSON);

cJSON *project_config_convertToJSON(project_config_t *project_config);

#endif /* _project_config_H_ */

