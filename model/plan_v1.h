/*
 * plan_v1.h
 *
 * 
 */

#ifndef _plan_v1_H_
#define _plan_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct plan_v1_t plan_v1_t;




typedef struct plan_v1_t {
    char *plan_id; // string
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} plan_v1_t;

__attribute__((deprecated)) plan_v1_t *plan_v1_create(
    char *plan_id,
    char *name
);

void plan_v1_free(plan_v1_t *plan_v1);

plan_v1_t *plan_v1_parseFromJSON(cJSON *plan_v1JSON);

cJSON *plan_v1_convertToJSON(plan_v1_t *plan_v1);

#endif /* _plan_v1_H_ */

