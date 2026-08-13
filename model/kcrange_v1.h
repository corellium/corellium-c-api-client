/*
 * kcrange_v1.h
 *
 * 
 */

#ifndef _kcrange_v1_H_
#define _kcrange_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct kcrange_v1_t kcrange_v1_t;




typedef struct kcrange_v1_t {
    char *kext; // string
    list_t *range; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} kcrange_v1_t;

__attribute__((deprecated)) kcrange_v1_t *kcrange_v1_create(
    char *kext,
    list_t *range
);

void kcrange_v1_free(kcrange_v1_t *kcrange_v1);

kcrange_v1_t *kcrange_v1_parseFromJSON(cJSON *kcrange_v1JSON);

cJSON *kcrange_v1_convertToJSON(kcrange_v1_t *kcrange_v1);

#endif /* _kcrange_v1_H_ */

