#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/activity_export_dto.h"
#include "../model/activity_export_response.h"
#include "../model/activity_list.h"
#include "../model/activity_request.h"
#include "../model/api_error_v1.h"
#include "../model/api_not_found_error_v1.h"
#include "../model/user_error_v1.h"


// Start activity export
//
activity_export_response_t*
ActivityV1API_v1ActivityExport(apiClient_t *apiClient, activity_export_dto_t *activity_export_dto);


// Get resource activities
//
activity_list_t*
ActivityV1API_v1ActivityList(apiClient_t *apiClient, activity_request_t *request);


// Download activity
//
// Download activity for a given task
//
activity_list_t*
ActivityV1API_v1DownloadActivity(apiClient_t *apiClient, char *taskId);


// Get export task status
//
activity_list_t*
ActivityV1API_v1GetActivityExportStatus(apiClient_t *apiClient, char *taskId);


// Get all export tasks for user
//
activity_list_t*
ActivityV1API_v1GetActivityExportTasks(apiClient_t *apiClient);


