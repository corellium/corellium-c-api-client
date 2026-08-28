/*
 * assessment_id_status.h
 *
 * 
 */

#ifndef _assessment_id_status_H_
#define _assessment_id_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct assessment_id_status_t assessment_id_status_t;

#include "assessment_status.h"



typedef struct assessment_id_status_t {
    char *id; // string
    corellium_api_assessment_status__e status; //referenced enum

    int _library_owned; // Is the library responsible for freeing this object?
} assessment_id_status_t;

__attribute__((deprecated)) assessment_id_status_t *assessment_id_status_create(
    char *id,
    corellium_api_assessment_status__e status
);

void assessment_id_status_free(assessment_id_status_t *assessment_id_status);

assessment_id_status_t *assessment_id_status_parseFromJSON(cJSON *assessment_id_statusJSON);

cJSON *assessment_id_status_convertToJSON(assessment_id_status_t *assessment_id_status);

#endif /* _assessment_id_status_H_ */

