#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/activity_download.h"
#include "../model/activity_export_tasks_list.h"
#include "../model/activity_list_response.h"
#include "../model/api_error.h"
#include "../model/api_not_found_error.h"
#include "../model/create_activity_export_body.h"
#include "../model/user_error.h"
#include "../model/v3_create_activity_export_201_response.h"
#include "../model/v3_get_activity_export_status_200_response.h"


// Start activity export
//
// **Required role:** Domain administrator.  Start activity export.
//
v3_create_activity_export_201_response_t*
ActivityAPI_v3CreateActivityExport(apiClient_t *apiClient, char *accept, create_activity_export_body_t *create_activity_export_body);


// Download activity for a given task
//
// **Required role:** Domain administrator.  Download activity for a given task.
//
activity_download_t*
ActivityAPI_v3DownloadActivity(apiClient_t *apiClient, char *taskId);


// Get export task status
//
// **Required role:** Domain administrator.  Get export task status.
//
v3_get_activity_export_status_200_response_t*
ActivityAPI_v3GetActivityExportStatus(apiClient_t *apiClient, char *taskId);


// Get all export tasks for user
//
// **Required role:** Domain administrator.  Get all export tasks for user.
//
activity_export_tasks_list_t*
ActivityAPI_v3GetActivityExportTasks(apiClient_t *apiClient, double *limit, double *offset);


// Get resource activities
//
activity_list_response_t*
ActivityAPI_v3ListActivities(apiClient_t *apiClient, char *resource, double *limit, double *offset, char *orderBy, char *instanceId, char *projectId, char *actor, char *search, char to, char from);


