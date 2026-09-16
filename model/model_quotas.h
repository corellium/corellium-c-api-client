/*
 * model_quotas.h
 *
 * Resource quotas for this model.
 */

#ifndef _model_quotas_H_
#define _model_quotas_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct model_quotas_t model_quotas_t;




typedef struct model_quotas_t {
    double cores; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} model_quotas_t;

__attribute__((deprecated)) model_quotas_t *model_quotas_create(
    double cores
);

void model_quotas_free(model_quotas_t *model_quotas);

model_quotas_t *model_quotas_parseFromJSON(cJSON *model_quotasJSON);

cJSON *model_quotas_convertToJSON(model_quotas_t *model_quotas);

#endif /* _model_quotas_H_ */

