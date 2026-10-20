/*
 * assessment_history.h
 *
 * 
 */

#ifndef _assessment_history_H_
#define _assessment_history_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct assessment_history_t assessment_history_t;

#include "assessment_history_results_inner.h"



typedef struct assessment_history_t {
    list_t *results; //nonprimitive container
    double count; //numeric
    double total; //numeric
    double limit; //numeric
    double offset; //numeric
    int has_more; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} assessment_history_t;

__attribute__((deprecated)) assessment_history_t *assessment_history_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
);

void assessment_history_free(assessment_history_t *assessment_history);

assessment_history_t *assessment_history_parseFromJSON(cJSON *assessment_historyJSON);

cJSON *assessment_history_convertToJSON(assessment_history_t *assessment_history);

#endif /* _assessment_history_H_ */

