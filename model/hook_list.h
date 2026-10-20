/*
 * hook_list.h
 *
 * 
 */

#ifndef _hook_list_H_
#define _hook_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct hook_list_t hook_list_t;

#include "hook.h"



typedef struct hook_list_t {
    list_t *results; //nonprimitive container
    double count; //numeric
    double total; //numeric
    double limit; //numeric
    double offset; //numeric
    int has_more; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} hook_list_t;

__attribute__((deprecated)) hook_list_t *hook_list_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
);

void hook_list_free(hook_list_t *hook_list);

hook_list_t *hook_list_parseFromJSON(cJSON *hook_listJSON);

cJSON *hook_list_convertToJSON(hook_list_t *hook_list);

#endif /* _hook_list_H_ */

