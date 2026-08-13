/*
 * task_status.h
 *
 * Current task status.
 */

#ifndef _task_status_H_
#define _task_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct task_status_t task_status_t;


// Enum  for task_status

typedef enum { corellium_api_task_status__NULL = 0, corellium_api_task_status__in_progress, corellium_api_task_status__complete, corellium_api_task_status__error } corellium_api_task_status__e;

char* task_status_task_status_ToString(corellium_api_task_status__e task_status);

corellium_api_task_status__e task_status_task_status_FromString(char* task_status);

cJSON *task_status_convertToJSON(corellium_api_task_status__e task_status);

corellium_api_task_status__e task_status_parseFromJSON(cJSON *task_statusJSON);

#endif /* _task_status_H_ */

