#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "assessment_format.h"


char* assessment_format_assessment_format_ToString(corellium_api_assessment_format__e assessment_format) {
    char *assessment_formatArray[] =  { "NULL", "json", "html" };
    return assessment_formatArray[assessment_format];
}

corellium_api_assessment_format__e assessment_format_assessment_format_FromString(char* assessment_format) {
    int stringToReturn = 0;
    char *assessment_formatArray[] =  { "NULL", "json", "html" };
    size_t sizeofArray = sizeof(assessment_formatArray) / sizeof(assessment_formatArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(assessment_format, assessment_formatArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *assessment_format_convertToJSON(corellium_api_assessment_format__e assessment_format) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "assessment_format", assessment_format_assessment_format_ToString(assessment_format)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

corellium_api_assessment_format__e assessment_format_parseFromJSON(cJSON *assessment_formatJSON) {
    if(!cJSON_IsString(assessment_formatJSON) || (assessment_formatJSON->valuestring == NULL)) {
        return 0;
    }
    return assessment_format_assessment_format_FromString(assessment_formatJSON->valuestring);
}
