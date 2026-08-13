/*
 * assessment_severity_counts.h
 *
 * Snapshot of available check counts by severity, or null if unset.
 */

#ifndef _assessment_severity_counts_H_
#define _assessment_severity_counts_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct assessment_severity_counts_t assessment_severity_counts_t;




typedef struct assessment_severity_counts_t {
    double high; //numeric
    double medium; //numeric
    double low; //numeric
    double info; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} assessment_severity_counts_t;

__attribute__((deprecated)) assessment_severity_counts_t *assessment_severity_counts_create(
    double high,
    double medium,
    double low,
    double info
);

void assessment_severity_counts_free(assessment_severity_counts_t *assessment_severity_counts);

assessment_severity_counts_t *assessment_severity_counts_parseFromJSON(cJSON *assessment_severity_countsJSON);

cJSON *assessment_severity_counts_convertToJSON(assessment_severity_counts_t *assessment_severity_counts);

#endif /* _assessment_severity_counts_H_ */

