/*
 * model_partition.h
 *
 * 
 */

#ifndef _model_partition_H_
#define _model_partition_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct model_partition_t model_partition_t;




typedef struct model_partition_t {
    char *name; // string
    double block_size; //numeric
    double blocks; //numeric
    double blocks_min; //numeric
    double blocks_max; //numeric
    double blocks_step; //numeric
    list_t *block_values; //primitive container
    int user_uploaded; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} model_partition_t;

__attribute__((deprecated)) model_partition_t *model_partition_create(
    char *name,
    double block_size,
    double blocks,
    double blocks_min,
    double blocks_max,
    double blocks_step,
    list_t *block_values,
    int user_uploaded
);

void model_partition_free(model_partition_t *model_partition);

model_partition_t *model_partition_parseFromJSON(cJSON *model_partitionJSON);

cJSON *model_partition_convertToJSON(model_partition_t *model_partition);

#endif /* _model_partition_H_ */

