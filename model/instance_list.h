/*
 * instance_list.h
 *
 * 
 */

#ifndef _instance_list_H_
#define _instance_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instance_list_t instance_list_t;

#include "instance.h"



typedef struct instance_list_t {
    list_t *results; //nonprimitive container
    double count; //numeric
    double total; //numeric
    double limit; //numeric
    double offset; //numeric
    int has_more; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} instance_list_t;

__attribute__((deprecated)) instance_list_t *instance_list_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
);

void instance_list_free(instance_list_t *instance_list);

instance_list_t *instance_list_parseFromJSON(cJSON *instance_listJSON);

cJSON *instance_list_convertToJSON(instance_list_t *instance_list);

#endif /* _instance_list_H_ */

