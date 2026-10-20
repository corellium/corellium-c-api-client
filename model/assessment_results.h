/*
 * assessment_results.h
 *
 * Aggregated check results, or null if the assessment has not produced results.
 */

#ifndef _assessment_results_H_
#define _assessment_results_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct assessment_results_t assessment_results_t;




typedef struct assessment_results_t {
    double pass; //numeric
    double fail; //numeric
    double error; //numeric
    double info; //numeric
    double na; //numeric
    double artifact; //numeric
    double score; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} assessment_results_t;

__attribute__((deprecated)) assessment_results_t *assessment_results_create(
    double pass,
    double fail,
    double error,
    double info,
    double na,
    double artifact,
    double score
);

void assessment_results_free(assessment_results_t *assessment_results);

assessment_results_t *assessment_results_parseFromJSON(cJSON *assessment_resultsJSON);

cJSON *assessment_results_convertToJSON(assessment_results_t *assessment_results);

#endif /* _assessment_results_H_ */

