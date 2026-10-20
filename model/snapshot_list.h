/*
 * snapshot_list.h
 *
 * 
 */

#ifndef _snapshot_list_H_
#define _snapshot_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct snapshot_list_t snapshot_list_t;

#include "cluster_snapshot_v1.h"



typedef struct snapshot_list_t {
    list_t *results; //nonprimitive container
    double offset; //numeric
    double limit; //numeric
    double count; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} snapshot_list_t;

__attribute__((deprecated)) snapshot_list_t *snapshot_list_create(
    list_t *results,
    double offset,
    double limit,
    double count
);

void snapshot_list_free(snapshot_list_t *snapshot_list);

snapshot_list_t *snapshot_list_parseFromJSON(cJSON *snapshot_listJSON);

cJSON *snapshot_list_convertToJSON(snapshot_list_t *snapshot_list);

#endif /* _snapshot_list_H_ */

