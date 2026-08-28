/*
 * assessment.h
 *
 * 
 */

#ifndef _assessment_H_
#define _assessment_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct assessment_t assessment_t;

#include "assessment_bundle.h"
#include "assessment_frida_script.h"
#include "assessment_metadata.h"
#include "assessment_results.h"
#include "assessment_severity_counts.h"
#include "assessment_status.h"
#include "assessment_wordlist.h"



typedef struct assessment_t {
    char *id; // string
    corellium_api_assessment_status__e status; //referenced enum
    char *instance_id; // string
    struct assessment_bundle_t *bundle; //model
    struct assessment_wordlist_t *wordlist; //model
    struct assessment_frida_script_t *frida_script; //model
    char *report_id; // string
    struct assessment_results_t *results; //model
    struct assessment_metadata_t *metadata; //model
    struct assessment_severity_counts_t *severity_counts; //model
    char *error; // string
    char *created_by; // string
    char *created_at; //date time
    char *updated_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} assessment_t;

__attribute__((deprecated)) assessment_t *assessment_create(
    char *id,
    corellium_api_assessment_status__e status,
    char *instance_id,
    assessment_bundle_t *bundle,
    assessment_wordlist_t *wordlist,
    assessment_frida_script_t *frida_script,
    char *report_id,
    assessment_results_t *results,
    assessment_metadata_t *metadata,
    assessment_severity_counts_t *severity_counts,
    char *error,
    char *created_by,
    char *created_at,
    char *updated_at
);

void assessment_free(assessment_t *assessment);

assessment_t *assessment_parseFromJSON(cJSON *assessmentJSON);

cJSON *assessment_convertToJSON(assessment_t *assessment);

#endif /* _assessment_H_ */

