#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/activity_export_status.h"
#include "../model/activity_export_task_list.h"
#include "../model/activity_list_response.h"
#include "../model/api_error.h"
#include "../model/api_not_found_error.h"
#include "../model/create_activity_export_body.h"
#include "../model/create_activity_export_response.h"
#include "../model/user_error_response.h"


// Start activity export
//
// **Required role:** Domain administrator.  Starts building a file of activity records for download, for audits or offline analysis. Requires a domain administrator and the user-logging license feature (403 otherwise).  Choose the file format with the `Accept` header: `application/json` or `text/csv` (any other value returns 400). The body takes the same filters as `v3ListActivities`, but the export is not paginated: it contains every matching record.  **Workflow:** 1. `v3CreateActivityExport` (this call). Returns 201 with an `id` like `activity-export/<UUID>`. 2. Poll `v3GetActivityExportStatus` with the `<UUID>` part until `status` is `complete`. 3. `v3DownloadActivity` with the same UUID to get the file.
//
create_activity_export_response_t*
ActivityAPI_v3CreateActivityExport(apiClient_t *apiClient, char *accept, create_activity_export_body_t *create_activity_export_body);


// Download activity for a given task
//
// **Required role:** Domain administrator.  Downloads the file produced by a finished activity export, as JSON or CSV depending on the format you asked for. Pass the UUID part of the export `id`. Returns 404 if the file is not ready or does not exist; check `v3GetActivityExportStatus` first. Requires a domain administrator and the user-logging license feature.
//
binary_t*
ActivityAPI_v3DownloadActivity(apiClient_t *apiClient, char *taskId);


// Get export task status
//
// **Required role:** Domain administrator.  Returns the status of an activity export started with `v3CreateActivityExport`. Pass the UUID part of the export `id`. Poll until `status` is `complete`, then call `v3DownloadActivity`. Finished tasks are cleaned up, so a task that no longer exists is reported as `complete`. Requires a domain administrator and the user-logging license feature.
//
activity_export_status_t*
ActivityAPI_v3GetActivityExportStatus(apiClient_t *apiClient, char *taskId);


// Get all export tasks for user
//
// **Required role:** Domain administrator.  Lists the activity exports you have started, with each one's status and the filters it used. Requires a domain administrator and the user-logging license feature. Results are paginated with `limit` and `offset`.
//
activity_export_task_list_t*
ActivityAPI_v3GetActivityExportTasks(apiClient_t *apiClient, double *limit, double *offset);


// Get resource activities
//
// Returns the activity log: a record of what happened in your domain, such as devices created, started and deleted, users signing in, and settings changed, with who did it and when. You only see events your role allows. Filter by device, project, user, time range or free text, and page with `limit` and `offset`. For a full download of many records, use `v3CreateActivityExport` instead.
//
activity_list_response_t*
ActivityAPI_v3ListActivities(apiClient_t *apiClient, char *resource, double *limit, double *offset, char *orderBy, char *instanceId, char *projectId, char *actor, char *search, char to, char from);


