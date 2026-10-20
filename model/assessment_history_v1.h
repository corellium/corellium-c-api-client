/*
 * assessment_history_v1.h
 *
 * 
 */

#ifndef _assessment_history_v1_H_
#define _assessment_history_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct assessment_history_v1_t assessment_history_v1_t;

#include "assessment_history_line_item.h"



typedef struct assessment_history_v1_t {
    double total; //numeric
    double count; //numeric
    double limit; //numeric
    double offset; //numeric
    list_t *results; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} assessment_history_v1_t;

__attribute__((deprecated)) assessment_history_v1_t *assessment_history_v1_create(
    double total,
    double count,
    double limit,
    double offset,
    list_t *results
);

void assessment_history_v1_free(assessment_history_v1_t *assessment_history_v1);

assessment_history_v1_t *assessment_history_v1_parseFromJSON(cJSON *assessment_history_v1JSON);

cJSON *assessment_history_v1_convertToJSON(assessment_history_v1_t *assessment_history_v1);

#endif /* _assessment_history_v1_H_ */

