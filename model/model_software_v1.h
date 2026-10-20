/*
 * model_software_v1.h
 *
 * 
 */

#ifndef _model_software_v1_H_
#define _model_software_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct model_software_v1_t model_software_v1_t;

#include "firmware_v1.h"



typedef struct model_software_v1_t {
    char *name; // string
    char *board_config; // string
    char *platform; // string
    double cpid; //numeric
    double bdid; //numeric
    list_t *firmwares; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} model_software_v1_t;

__attribute__((deprecated)) model_software_v1_t *model_software_v1_create(
    char *name,
    char *board_config,
    char *platform,
    double cpid,
    double bdid,
    list_t *firmwares
);

void model_software_v1_free(model_software_v1_t *model_software_v1);

model_software_v1_t *model_software_v1_parseFromJSON(cJSON *model_software_v1JSON);

cJSON *model_software_v1_convertToJSON(model_software_v1_t *model_software_v1);

#endif /* _model_software_v1_H_ */

