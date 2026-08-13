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


// Enum STATUS for assessment_id_status

typedef enum  { corellium_api_assessment_id_status_STATUS_NULL = 0, corellium_api_assessment_id_status_STATUS__new, corellium_api_assessment_id_status_STATUS_startingMonitoring, corellium_api_assessment_id_status_STATUS_monitoring, corellium_api_assessment_id_status_STATUS_stoppingMonitoring, corellium_api_assessment_id_status_STATUS_readyForTesting, corellium_api_assessment_id_status_STATUS_testing, corellium_api_assessment_id_status_STATUS_complete, corellium_api_assessment_id_status_STATUS_failed } corellium_api_assessment_id_status_STATUS_e;

char* assessment_id_status_status_ToString(corellium_api_assessment_id_status_STATUS_e status);

corellium_api_assessment_id_status_STATUS_e assessment_id_status_status_FromString(char* status);



typedef struct assessment_id_status_t {
    char *id; // string
    corellium_api_assessment_id_status_STATUS_e status; //enum

    int _library_owned; // Is the library responsible for freeing this object?
} assessment_id_status_t;

__attribute__((deprecated)) assessment_id_status_t *assessment_id_status_create(
    char *id,
    corellium_api_assessment_id_status_STATUS_e status
);

void assessment_id_status_free(assessment_id_status_t *assessment_id_status);

assessment_id_status_t *assessment_id_status_parseFromJSON(cJSON *assessment_id_statusJSON);

cJSON *assessment_id_status_convertToJSON(assessment_id_status_t *assessment_id_status);

#endif /* _assessment_id_status_H_ */

