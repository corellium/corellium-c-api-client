/*
 * assessment_bundle.h
 *
 * 
 */

#ifndef _assessment_bundle_H_
#define _assessment_bundle_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct assessment_bundle_t assessment_bundle_t;




typedef struct assessment_bundle_t {
    char *id; // string
    char *name; // string
    char *version; // string

    int _library_owned; // Is the library responsible for freeing this object?
} assessment_bundle_t;

__attribute__((deprecated)) assessment_bundle_t *assessment_bundle_create(
    char *id,
    char *name,
    char *version
);

void assessment_bundle_free(assessment_bundle_t *assessment_bundle);

assessment_bundle_t *assessment_bundle_parseFromJSON(cJSON *assessment_bundleJSON);

cJSON *assessment_bundle_convertToJSON(assessment_bundle_t *assessment_bundle);

#endif /* _assessment_bundle_H_ */

