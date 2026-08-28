/*
 * assessment_status.h
 *
 * Lifecycle status of the assessment.
 */

#ifndef _assessment_status_H_
#define _assessment_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct assessment_status_t assessment_status_t;


// Enum  for assessment_status

typedef enum { corellium_api_assessment_status__NULL = 0, corellium_api_assessment_status___new, corellium_api_assessment_status__startingMonitoring, corellium_api_assessment_status__monitoring, corellium_api_assessment_status__stoppingMonitoring, corellium_api_assessment_status__readyForTesting, corellium_api_assessment_status__testing, corellium_api_assessment_status__complete, corellium_api_assessment_status__failed } corellium_api_assessment_status__e;

char* assessment_status_assessment_status_ToString(corellium_api_assessment_status__e assessment_status);

corellium_api_assessment_status__e assessment_status_assessment_status_FromString(char* assessment_status);

cJSON *assessment_status_convertToJSON(corellium_api_assessment_status__e assessment_status);

corellium_api_assessment_status__e assessment_status_parseFromJSON(cJSON *assessment_statusJSON);

#endif /* _assessment_status_H_ */

