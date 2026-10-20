#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "assessment_status.h"


char* assessment_status_assessment_status_ToString(corellium_api_assessment_status__e assessment_status) {
    char *assessment_statusArray[] =  { "NULL", "new", "startingMonitoring", "monitoring", "stoppingMonitoring", "readyForTesting", "testing", "complete", "failed" };
    return assessment_statusArray[assessment_status];
}

corellium_api_assessment_status__e assessment_status_assessment_status_FromString(char* assessment_status) {
    int stringToReturn = 0;
    char *assessment_statusArray[] =  { "NULL", "new", "startingMonitoring", "monitoring", "stoppingMonitoring", "readyForTesting", "testing", "complete", "failed" };
    size_t sizeofArray = sizeof(assessment_statusArray) / sizeof(assessment_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(assessment_status, assessment_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *assessment_status_convertToJSON(corellium_api_assessment_status__e assessment_status) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "assessment_status", assessment_status_assessment_status_ToString(assessment_status)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

corellium_api_assessment_status__e assessment_status_parseFromJSON(cJSON *assessment_statusJSON) {
    if(!cJSON_IsString(assessment_statusJSON) || (assessment_statusJSON->valuestring == NULL)) {
        return 0;
    }
    return assessment_status_assessment_status_FromString(assessment_statusJSON->valuestring);
}
