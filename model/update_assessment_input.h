/*
 * update_assessment_input.h
 *
 * 
 */

#ifndef _update_assessment_input_H_
#define _update_assessment_input_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct update_assessment_input_t update_assessment_input_t;


// Enum STATUS for update_assessment_input

typedef enum  { corellium_api_update_assessment_input_STATUS_NULL = 0, corellium_api_update_assessment_input_STATUS__new, corellium_api_update_assessment_input_STATUS_startingMonitoring, corellium_api_update_assessment_input_STATUS_monitoring, corellium_api_update_assessment_input_STATUS_stoppingMonitoring, corellium_api_update_assessment_input_STATUS_readyForTesting, corellium_api_update_assessment_input_STATUS_testing, corellium_api_update_assessment_input_STATUS_complete, corellium_api_update_assessment_input_STATUS_failed } corellium_api_update_assessment_input_STATUS_e;

char* update_assessment_input_status_ToString(corellium_api_update_assessment_input_STATUS_e status);

corellium_api_update_assessment_input_STATUS_e update_assessment_input_status_FromString(char* status);



typedef struct update_assessment_input_t {
    corellium_api_update_assessment_input_STATUS_e status; //enum

    int _library_owned; // Is the library responsible for freeing this object?
} update_assessment_input_t;

__attribute__((deprecated)) update_assessment_input_t *update_assessment_input_create(
    corellium_api_update_assessment_input_STATUS_e status
);

void update_assessment_input_free(update_assessment_input_t *update_assessment_input);

update_assessment_input_t *update_assessment_input_parseFromJSON(cJSON *update_assessment_inputJSON);

cJSON *update_assessment_input_convertToJSON(update_assessment_input_t *update_assessment_input);

#endif /* _update_assessment_input_H_ */

