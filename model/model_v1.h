/*
 * model_v1.h
 *
 * 
 */

#ifndef _model_v1_H_
#define _model_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct model_v1_t model_v1_t;




typedef struct model_v1_t {
    char *type; // string
    char *name; // string
    char *flavor; // string
    char *description; // string
    char *model; // string
    char *board_config; // string
    char *platform; // string
    double cpid; //numeric
    double bdid; //numeric
    int peripherals; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} model_v1_t;

__attribute__((deprecated)) model_v1_t *model_v1_create(
    char *type,
    char *name,
    char *flavor,
    char *description,
    char *model,
    char *board_config,
    char *platform,
    double cpid,
    double bdid,
    int peripherals
);

void model_v1_free(model_v1_t *model_v1);

model_v1_t *model_v1_parseFromJSON(cJSON *model_v1JSON);

cJSON *model_v1_convertToJSON(model_v1_t *model_v1);

#endif /* _model_v1_H_ */

