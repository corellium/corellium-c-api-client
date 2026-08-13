/*
 * list_instance_snapshots_response.h
 *
 * 
 */

#ifndef _list_instance_snapshots_response_H_
#define _list_instance_snapshots_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct list_instance_snapshots_response_t list_instance_snapshots_response_t;

#include "snapshot.h"



typedef struct list_instance_snapshots_response_t {
    list_t *results; //nonprimitive container
    double count; //numeric
    double total; //numeric
    double limit; //numeric
    double offset; //numeric
    int has_more; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} list_instance_snapshots_response_t;

__attribute__((deprecated)) list_instance_snapshots_response_t *list_instance_snapshots_response_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
);

void list_instance_snapshots_response_free(list_instance_snapshots_response_t *list_instance_snapshots_response);

list_instance_snapshots_response_t *list_instance_snapshots_response_parseFromJSON(cJSON *list_instance_snapshots_responseJSON);

cJSON *list_instance_snapshots_response_convertToJSON(list_instance_snapshots_response_t *list_instance_snapshots_response);

#endif /* _list_instance_snapshots_response_H_ */

