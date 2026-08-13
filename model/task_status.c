#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "task_status.h"


char* task_status_task_status_ToString(corellium_api_task_status__e task_status) {
    char *task_statusArray[] =  { "NULL", "in-progress", "complete", "error", "" };
    return task_statusArray[task_status];
}

corellium_api_task_status__e task_status_task_status_FromString(char* task_status) {
    int stringToReturn = 0;
    char *task_statusArray[] =  { "NULL", "in-progress", "complete", "error", "" };
    size_t sizeofArray = sizeof(task_statusArray) / sizeof(task_statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(task_status, task_statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *task_status_convertToJSON(corellium_api_task_status__e task_status) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "task_status", task_status_task_status_ToString(task_status)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

corellium_api_task_status__e task_status_parseFromJSON(cJSON *task_statusJSON) {
    if(!cJSON_IsString(task_statusJSON) || (task_statusJSON->valuestring == NULL)) {
        return 0;
    }
    return task_status_task_status_FromString(task_statusJSON->valuestring);
}
