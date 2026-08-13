/*
 * model.h
 *
 * 
 */

#ifndef _model_H_
#define _model_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct model_t model_t;

#include "model_quotas.h"



typedef struct model_t {
    char *type; // string
    char *flavor; // string
    char *description; // string
    char *model; // string
    char *board_config; // string
    char *platform; // string
    double cpid; //numeric
    double bdid; //numeric
    int peripherals; //boolean
    struct model_quotas_t *quotas; //model

    int _library_owned; // Is the library responsible for freeing this object?
} model_t;

__attribute__((deprecated)) model_t *model_create(
    char *type,
    char *flavor,
    char *description,
    char *model,
    char *board_config,
    char *platform,
    double cpid,
    double bdid,
    int peripherals,
    model_quotas_t *quotas
);

void model_free(model_t *model);

model_t *model_parseFromJSON(cJSON *modelJSON);

cJSON *model_convertToJSON(model_t *model);

#endif /* _model_H_ */

