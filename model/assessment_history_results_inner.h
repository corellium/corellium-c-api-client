/*
 * assessment_history_results_inner.h
 *
 * 
 */

#ifndef _assessment_history_results_inner_H_
#define _assessment_history_results_inner_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct assessment_history_results_inner_t assessment_history_results_inner_t;




typedef struct assessment_history_results_inner_t {
    char *date; // string
    double complete; //numeric
    double incomplete; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} assessment_history_results_inner_t;

__attribute__((deprecated)) assessment_history_results_inner_t *assessment_history_results_inner_create(
    char *date,
    double complete,
    double incomplete
);

void assessment_history_results_inner_free(assessment_history_results_inner_t *assessment_history_results_inner);

assessment_history_results_inner_t *assessment_history_results_inner_parseFromJSON(cJSON *assessment_history_results_innerJSON);

cJSON *assessment_history_results_inner_convertToJSON(assessment_history_results_inner_t *assessment_history_results_inner);

#endif /* _assessment_history_results_inner_H_ */

