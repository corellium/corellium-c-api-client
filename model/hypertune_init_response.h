/*
 * hypertune_init_response.h
 *
 * 
 */

#ifndef _hypertune_init_response_H_
#define _hypertune_init_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct hypertune_init_response_t hypertune_init_response_t;

#include "any_type.h"
#include "object.h"



typedef struct hypertune_init_response_t {
    double commit_id; //numeric
    char *hash; // string
    object_t *reduced_expression; //object
    object_t *splits; //object
    object_t *commit_config; //object

    int _library_owned; // Is the library responsible for freeing this object?
} hypertune_init_response_t;

__attribute__((deprecated)) hypertune_init_response_t *hypertune_init_response_create(
    double commit_id,
    char *hash,
    object_t *reduced_expression,
    object_t *splits,
    object_t *commit_config
);

void hypertune_init_response_free(hypertune_init_response_t *hypertune_init_response);

hypertune_init_response_t *hypertune_init_response_parseFromJSON(cJSON *hypertune_init_responseJSON);

cJSON *hypertune_init_response_convertToJSON(hypertune_init_response_t *hypertune_init_response);

#endif /* _hypertune_init_response_H_ */

