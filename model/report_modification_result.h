/*
 * report_modification_result.h
 *
 * 
 */

#ifndef _report_modification_result_H_
#define _report_modification_result_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct report_modification_result_t report_modification_result_t;


// Enum STATUS for report_modification_result

typedef enum  { corellium_api_report_modification_result_STATUS_NULL = 0, corellium_api_report_modification_result_STATUS_inserted, corellium_api_report_modification_result_STATUS_deleted, corellium_api_report_modification_result_STATUS_updated, corellium_api_report_modification_result_STATUS_ignored, corellium_api_report_modification_result_STATUS_errored } corellium_api_report_modification_result_STATUS_e;

char* report_modification_result_status_ToString(corellium_api_report_modification_result_STATUS_e status);

corellium_api_report_modification_result_STATUS_e report_modification_result_status_FromString(char* status);



typedef struct report_modification_result_t {
    char *check_id; // string
    char *property; // string
    corellium_api_report_modification_result_STATUS_e status; //enum
    char *error; // string

    int _library_owned; // Is the library responsible for freeing this object?
} report_modification_result_t;

__attribute__((deprecated)) report_modification_result_t *report_modification_result_create(
    char *check_id,
    char *property,
    corellium_api_report_modification_result_STATUS_e status,
    char *error
);

void report_modification_result_free(report_modification_result_t *report_modification_result);

report_modification_result_t *report_modification_result_parseFromJSON(cJSON *report_modification_resultJSON);

cJSON *report_modification_result_convertToJSON(report_modification_result_t *report_modification_result);

#endif /* _report_modification_result_H_ */

