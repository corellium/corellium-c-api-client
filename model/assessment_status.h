/*
 * assessment_status.h
 *
 * Where the assessment is in its lifecycle. In the normal workflow, statuses ending in \&quot;ing\&quot; are temporary: background work moves the assessment on by itself, so poll &#x60;v3GetAssessmentById&#x60; to see the next status. (&#x60;v3PatchAssessment&#x60; can overwrite the status directly; do not use it to drive the workflow.)  - &#x60;new&#x60;: created by &#x60;v3CreateAssessment&#x60;. Nothing is being watched yet. Next call: &#x60;v3StartMonitoring&#x60;. - &#x60;startingMonitoring&#x60;: MATRIX is attaching to the app. Moves to &#x60;monitoring&#x60; when ready, or &#x60;failed&#x60;. - &#x60;monitoring&#x60;: MATRIX is recording what the app does. Use the app on the device now (log in, open screens, enter data). Next call: &#x60;v3StopMonitoring&#x60;. - &#x60;stoppingMonitoring&#x60;: MATRIX is detaching and saving what it recorded. Moves to &#x60;readyForTesting&#x60;, or &#x60;failed&#x60;. - &#x60;readyForTesting&#x60;: recording is finished. Next call: &#x60;v3RunTests&#x60;. - &#x60;testing&#x60;: the security checks are running. Moves to &#x60;complete&#x60; or &#x60;failed&#x60;. - &#x60;complete&#x60;: the report is ready. You can download it and adjust its findings. - &#x60;failed&#x60;: the assessment stopped. It cannot be resumed; delete it and create a new one. See the &#x60;error&#x60; field.
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

