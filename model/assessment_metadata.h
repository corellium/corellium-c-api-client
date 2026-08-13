/*
 * assessment_metadata.h
 *
 * Assessment metadata, or null if unset.
 */

#ifndef _assessment_metadata_H_
#define _assessment_metadata_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct assessment_metadata_t assessment_metadata_t;




typedef struct assessment_metadata_t {
    char *corellium_version; // string

    int _library_owned; // Is the library responsible for freeing this object?
} assessment_metadata_t;

__attribute__((deprecated)) assessment_metadata_t *assessment_metadata_create(
    char *corellium_version
);

void assessment_metadata_free(assessment_metadata_t *assessment_metadata);

assessment_metadata_t *assessment_metadata_parseFromJSON(cJSON *assessment_metadataJSON);

cJSON *assessment_metadata_convertToJSON(assessment_metadata_t *assessment_metadata);

#endif /* _assessment_metadata_H_ */

