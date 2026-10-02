# AssessmentsAPI

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**AssessmentsAPI_v3CreateAssessment**](AssessmentsAPI.md#AssessmentsAPI_v3CreateAssessment) | **POST** /v3/services/matrix/{instanceId}/assessments | Create an assessment.
[**AssessmentsAPI_v3CreateReportModification**](AssessmentsAPI.md#AssessmentsAPI_v3CreateReportModification) | **POST** /v3/services/matrix/{instanceId}/assessments/{assessmentId}/report-modification | Create report modifications.
[**AssessmentsAPI_v3DeleteAssessment**](AssessmentsAPI.md#AssessmentsAPI_v3DeleteAssessment) | **DELETE** /v3/services/matrix/{instanceId}/assessments/{assessmentId} | Delete an assessment.
[**AssessmentsAPI_v3DeleteReportModification**](AssessmentsAPI.md#AssessmentsAPI_v3DeleteReportModification) | **DELETE** /v3/services/matrix/{instanceId}/assessments/{assessmentId}/report-modification | Delete report modifications.
[**AssessmentsAPI_v3DownloadReport**](AssessmentsAPI.md#AssessmentsAPI_v3DownloadReport) | **GET** /v3/services/matrix/{instanceId}/assessments/{assessmentId}/download | Download an assessment report.
[**AssessmentsAPI_v3GetAssessmentById**](AssessmentsAPI.md#AssessmentsAPI_v3GetAssessmentById) | **GET** /v3/services/matrix/{instanceId}/assessments/{assessmentId} | Get an assessment by ID.
[**AssessmentsAPI_v3GetAssessmentsByInstanceId**](AssessmentsAPI.md#AssessmentsAPI_v3GetAssessmentsByInstanceId) | **GET** /v3/services/matrix/{instanceId}/instances/{targetInstanceId}/assessments | List assessments for an instance.
[**AssessmentsAPI_v3PatchAssessment**](AssessmentsAPI.md#AssessmentsAPI_v3PatchAssessment) | **PATCH** /v3/services/matrix/{instanceId}/assessments/{assessmentId} | Update an assessment status.
[**AssessmentsAPI_v3RunTests**](AssessmentsAPI.md#AssessmentsAPI_v3RunTests) | **POST** /v3/services/matrix/{instanceId}/assessments/{assessmentId}/test | Run assessment tests.
[**AssessmentsAPI_v3StartMonitoring**](AssessmentsAPI.md#AssessmentsAPI_v3StartMonitoring) | **POST** /v3/services/matrix/{instanceId}/assessments/{assessmentId}/start | Start assessment monitoring.
[**AssessmentsAPI_v3StopMonitoring**](AssessmentsAPI.md#AssessmentsAPI_v3StopMonitoring) | **POST** /v3/services/matrix/{instanceId}/assessments/{assessmentId}/stop | Stop assessment monitoring.


# **AssessmentsAPI_v3CreateAssessment**
```c
// Create an assessment.
//
// Creates a new assessment for one app on the instance. This is always the first call. It does not start recording anything; it only checks the device and saves the assessment in status `new`.  **Before you call it:** - The instance must be powered on. - The device must be jailbroken (iOS) or rooted (Android), and its model must support MATRIX (`mast: true` in `GET /v3/models`). Otherwise the request is rejected; currently this can come back as a server error rather than a 400, so check these conditions before calling. - The app must already be installed. `bundleId` is the app's identifier (for example `com.android.egg`); the app's name and version are read from the device and stored on the assessment. - Every earlier assessment on this instance must be `complete` or `failed`. Only one assessment can be in progress per instance at a time. - Android: the web interface asks for at least 4 CPU cores and 4 GB of RAM before it offers MATRIX. This API does not check those values, but with too little memory monitoring can fail with an out-of-memory error.  **Optional inputs.** `wordlistId` and `fridaScriptId` point to files you upload beforehand with `POST /v3/images`; see those fields for details.  **Response.** The new assessment's `id` and `status` (`new`). Save the `id`; every later call needs it. Next call: `v3StartMonitoring`.  **How a MATRIX assessment works.** MATRIX tests one installed app for mobile security problems (for example insecure storage, weak crypto, or sensitive data sent over the network). It first records what the app does while you use it, then runs its checks against that recording and the device, and finally produces a report. Call these operations in order:  1. `v3CreateAssessment` with the app's `bundleId`. Status: `new`. 2. `v3StartMonitoring`. Status goes `startingMonitoring`, then `monitoring`. 3. Use the app on the device through the normal display or an automation tool. Exercise the features you care about. Keep the app open. 4. `v3StopMonitoring`. Status goes `stoppingMonitoring`, then `readyForTesting`. 5. `v3RunTests`. Status goes `testing`, then `complete` or `failed`. 6. Poll `v3GetAssessmentById` every few seconds until the status is `complete` or `failed`. Testing can take several minutes. 7. `v3DownloadReport` to get the results as HTML or JSON. 8. Optional: `v3CreateReportModification` to mark findings as not applicable or change their severity.  Steps 2, 4 and 5 return as soon as the work has started. The request succeeding does not mean the step has finished; always wait for the next status before making the next call. If any step ends in `failed`, the assessment cannot continue: delete it and start again.  Create, start monitoring, stop monitoring, run tests, and delete require the instance to be powered on. Get, list, update status, download, and the report-modification calls do not.
//
assessment_id_status_t* AssessmentsAPI_v3CreateAssessment(apiClient_t *apiClient, char *instanceId, create_assessment_input_t *create_assessment_input);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | ID of the instance (virtual device) the assessment belongs to. The platform checks that you have access to this instance before the request reaches MATRIX, so use the ID of an instance in one of your projects. | 
**create_assessment_input** | **[create_assessment_input_t](create_assessment_input.md) \*** |  | 

### Return type

[assessment_id_status_t](assessment_id_status.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AssessmentsAPI_v3CreateReportModification**
```c
// Create report modifications.
//
// Adjusts findings in a finished report, for example to record that a failure does not apply to your app. The assessment must have status `complete`. Your changes are stored separately from the original report. Saving them immediately recalculates the assessment's `results` counts and score. The HTML download shows the adjusted findings; the JSON download contains the original report plus a `modifications` array.  Send an array. Each item names a check with `checkId` (as shown in the report) and one `property` to change: - `outcome`: set `value` to `na` to mark the check \"not applicable\", or `fail` to undo that. - `severity`: set `value` to a different severity level for the check. - `evidence_<n>` (for example `evidence_0`): set `suppressed` to `true` to hide the n-th piece of evidence for the check, or `false` to show it again. Do not send `value`.  The response has one entry per item, saying whether it was applied or why it was ignored. To undo a change, use `v3DeleteReportModification`.
//
list_t* AssessmentsAPI_v3CreateReportModification(apiClient_t *apiClient, char *instanceId, char *assessmentId, list_t *report_modification_input);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | ID of the instance (virtual device) the assessment belongs to. The platform checks that you have access to this instance before the request reaches MATRIX, so use the ID of an instance in one of your projects. | 
**assessmentId** | **char \*** | Identifier of the assessment. | 
**report_modification_input** | **[list_t](report_modification_input.md) \*** |  | 

### Return type

[list_t](report_modification_result.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AssessmentsAPI_v3DeleteAssessment**
```c
// Delete an assessment.
//
// Permanently deletes an assessment and the data that belongs to it: - the assessment record, - the generated report, - the wordlist file it used (if any), - the monitoring data MATRIX recorded for this app, - temporary MATRIX files on the device.  The Frida script file, if one was used, is **not** deleted; remove it yourself with `DELETE /v3/images/{imageId}` if you no longer need it.  The instance must be powered on, because MATRIX removes its files from the device. Delete a `failed` assessment before creating a new one for the same instance. Unlike most v3 delete endpoints, an unknown `assessmentId` returns 404 rather than 204.
//
void AssessmentsAPI_v3DeleteAssessment(apiClient_t *apiClient, char *instanceId, char *assessmentId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | ID of the instance (virtual device) the assessment belongs to. The platform checks that you have access to this instance before the request reaches MATRIX, so use the ID of an instance in one of your projects. | 
**assessmentId** | **char \*** | Identifier of the assessment. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AssessmentsAPI_v3DeleteReportModification**
```c
// Delete report modifications.
//
// Undoes report changes made with `v3CreateReportModification`, so the affected findings return to their original values. The assessment must have status `complete`. Send an array of `{ checkId, property }` items that identify the changes to remove. The response has one entry per item saying whether it was removed.
//
list_t* AssessmentsAPI_v3DeleteReportModification(apiClient_t *apiClient, char *instanceId, char *assessmentId, list_t *delete_modification_input);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | ID of the instance (virtual device) the assessment belongs to. The platform checks that you have access to this instance before the request reaches MATRIX, so use the ID of an instance in one of your projects. | 
**assessmentId** | **char \*** | Identifier of the assessment. | 
**delete_modification_input** | **[list_t](delete_modification_input.md) \*** |  | 

### Return type

[list_t](report_modification_result.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AssessmentsAPI_v3DownloadReport**
```c
// Download an assessment report.
//
// Downloads the full report of a finished assessment. The assessment must have status `complete`; otherwise the request fails with 400.  Choose the format with `format`: - `html` (default): a single, self-contained HTML page for people to read. Save it with an `.html` extension and open it in a browser. - `json`: the report data for programs, plus an `activity` array (up to 100 recent events for the assessment) and a `modifications` array listing the changes made with `v3CreateReportModification`. The report data itself is the original, unmodified result; apply the entries in `modifications` yourself if your program needs the adjusted view.  The HTML report applies your modifications when it is generated, so download again after changing findings. The instance does not need to be powered on.
//
char* AssessmentsAPI_v3DownloadReport(apiClient_t *apiClient, char *instanceId, char *assessmentId, char *format);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | ID of the instance (virtual device) the assessment belongs to. The platform checks that you have access to this instance before the request reaches MATRIX, so use the ID of an instance in one of your projects. | 
**assessmentId** | **char \*** | Identifier of the assessment. | 
**format** | **char \*** | Report download format. Defaults to \&quot;html\&quot;. | [optional] 

### Return type

char*



### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: text/html, application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AssessmentsAPI_v3GetAssessmentById**
```c
// Get an assessment by ID.
//
// Returns everything known about one assessment. Use it to: - **Wait for a step to finish.** Poll after `v3StartMonitoring`, `v3StopMonitoring` and `v3RunTests`, and check `status` before making the next call. - **Find out why it failed.** When `status` is `failed`, `error` may contain a short reason. - **Read a summary of the results.** Once `status` is `complete`, `results` holds the pass/fail counts and the MATRIX score, and `reportId` is set. Use `v3DownloadReport` for the full findings.  Returns 404 if no assessment has this ID.
//
assessment_t* AssessmentsAPI_v3GetAssessmentById(apiClient_t *apiClient, char *instanceId, char *assessmentId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | ID of the instance (virtual device) the assessment belongs to. The platform checks that you have access to this instance before the request reaches MATRIX, so use the ID of an instance in one of your projects. | 
**assessmentId** | **char \*** | Identifier of the assessment. | 

### Return type

[assessment_t](assessment.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AssessmentsAPI_v3GetAssessmentsByInstanceId**
```c
// List assessments for an instance.
//
// Lists the assessments for an instance, one page at a time. Use it to find earlier assessments, check whether one is still running before creating a new one, or build a history view.  **Paging.** Returns at most `limit` assessments (default 100), skipping the first `offset` (default 0). `total` is the number of assessments that match your filters; keep increasing `offset` by `limit` until `offset` is at least `total`.  **Sorting and filtering.** Results are newest first unless you set `sort`. Filters such as `status`, `name` and `createdAt` can be combined; only assessments matching all of them are returned.
//
paginated_assessments_t* AssessmentsAPI_v3GetAssessmentsByInstanceId(apiClient_t *apiClient, char *instanceId, char *targetInstanceId, double *limit, double *offset, char *sort, char *name, char *version, char *status, char *createdBy, char *wordlist, char *frida, char *corelliumVersion, char *createdAt);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | ID of the instance (virtual device) the assessment belongs to. The platform checks that you have access to this instance before the request reaches MATRIX, so use the ID of an instance in one of your projects. | 
**targetInstanceId** | **char \*** | ID of the instance whose assessments you want to list. Set this to the same value as &#x60;instanceId&#x60;; the path contains the ID twice only because of how the MATRIX service is routed. | 
**limit** | **double \*** | Maximum number of assessments to return. Defaults to 100. | [optional] [default to 100]
**offset** | **double \*** | Number of assessments to skip before returning results. Defaults to 0. | [optional] [default to 0]
**sort** | **char \*** | Comma-separated fields to order by; prefix a field with \&quot;-\&quot; for descending. Allowed fields: createdAt, status, name, version, score, wordlist, frida, corelliumVersion. Defaults to \&quot;-createdAt\&quot;. | [optional] 
**name** | **char \*** | Filter by app name (exact match). | [optional] 
**version** | **char \*** | Filter by app version (exact match). | [optional] 
**status** | **char \*** | Filter by assessment status. | [optional] 
**createdBy** | **char \*** | Filter by the user ID that created the assessment. | [optional] 
**wordlist** | **char \*** | Filter by wordlist name. Use \&quot;None\&quot; to return assessments without a wordlist. | [optional] 
**frida** | **char \*** | Filter by Frida script name. Use \&quot;None\&quot; to return assessments without a Frida script. | [optional] 
**corelliumVersion** | **char \*** | Filter by Corellium version (exact match). | [optional] 
**createdAt** | **char \*** | Filter by test date. Accepts a single date (MM/DD/YYYY), a range (MM/DD/YYYY-MM/DD/YYYY), or a comma-separated list of dates and ranges. Dates are matched inclusive of the full day in UTC. | [optional] 

### Return type

[paginated_assessments_t](paginated_assessments.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AssessmentsAPI_v3PatchAssessment**
```c
// Update an assessment status.
//
// Sets the assessment's `status` field directly. **Most clients should never call this.** `v3StartMonitoring`, `v3StopMonitoring` and `v3RunTests` change the status for you and also do the actual work; this call only changes the stored value.  The server does not check that the new status is a valid next step, and changing it does not start or stop any monitoring or testing. Setting a status by hand can leave an assessment claiming to be in a state it is not really in. Returns the updated assessment, or 404 if no assessment has this ID.
//
assessment_t* AssessmentsAPI_v3PatchAssessment(apiClient_t *apiClient, char *instanceId, char *assessmentId, update_assessment_input_t *update_assessment_input);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | ID of the instance (virtual device) the assessment belongs to. The platform checks that you have access to this instance before the request reaches MATRIX, so use the ID of an instance in one of your projects. | 
**assessmentId** | **char \*** | Identifier of the assessment. | 
**update_assessment_input** | **[update_assessment_input_t](update_assessment_input.md) \*** |  | 

### Return type

[assessment_t](assessment.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AssessmentsAPI_v3RunTests**
```c
// Run assessment tests.
//
// Runs the MATRIX security checks (step 5). Call it once the status is `readyForTesting`. The instance must be powered on and must stay on until testing finishes.  The checks run in the background and can take several minutes. This call returns right away with the status `testing`. Poll `v3GetAssessmentById` until it is `complete` (then call `v3DownloadReport`) or `failed`.  **Running only some checks.** The request body is optional; with no body every applicable check runs. To narrow it down, set `grep` to text or a regular expression. A check runs if the pattern matches its check ID, its group ID or its category ID. For example `masvs-storage` runs every storage check and `masvs-storage-2-android-8` runs one check. Set `invert` to `true` to run every check except the matching ones.
//
assessment_id_status_t* AssessmentsAPI_v3RunTests(apiClient_t *apiClient, char *instanceId, char *assessmentId, test_assessment_input_t *test_assessment_input);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | ID of the instance (virtual device) the assessment belongs to. The platform checks that you have access to this instance before the request reaches MATRIX, so use the ID of an instance in one of your projects. | 
**assessmentId** | **char \*** | Identifier of the assessment. | 
**test_assessment_input** | **[test_assessment_input_t](test_assessment_input.md) \*** |  | [optional] 

### Return type

[assessment_id_status_t](assessment_id_status.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AssessmentsAPI_v3StartMonitoring**
```c
// Start assessment monitoring.
//
// Starts recording what the app does (step 2). Call it after `v3CreateAssessment`, when the assessment's status is `new`. The instance must be powered on.  MATRIX attaches to the app in the background, which can take a while. This call returns 204 as soon as that work has started, with the status set to `startingMonitoring`. Poll `v3GetAssessmentById`: - `monitoring`: recording has begun. Now use the app on the device. Go through the features you want tested: sign in, open screens, enter and save data, make network requests. MATRIX can only report on behavior it observed. Keep the app open until you stop monitoring. - `failed`: see `error`. Common causes are too little device RAM and the app failing to launch.  When you have finished using the app, call `v3StopMonitoring`.
//
void AssessmentsAPI_v3StartMonitoring(apiClient_t *apiClient, char *instanceId, char *assessmentId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | ID of the instance (virtual device) the assessment belongs to. The platform checks that you have access to this instance before the request reaches MATRIX, so use the ID of an instance in one of your projects. | 
**assessmentId** | **char \*** | Identifier of the assessment. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AssessmentsAPI_v3StopMonitoring**
```c
// Stop assessment monitoring.
//
// Stops recording (step 4). Call it once the status is `monitoring` and you have finished using the app. The instance must be powered on.  MATRIX detaches from the app and saves what it recorded in the background. This call returns 204 as soon as that has started, with the status set to `stoppingMonitoring`. Poll `v3GetAssessmentById` until the status is `readyForTesting`, then call `v3RunTests`. If it becomes `failed`, check `error`.
//
void AssessmentsAPI_v3StopMonitoring(apiClient_t *apiClient, char *instanceId, char *assessmentId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | ID of the instance (virtual device) the assessment belongs to. The platform checks that you have access to this instance before the request reaches MATRIX, so use the ID of an instance in one of your projects. | 
**assessmentId** | **char \*** | Identifier of the assessment. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

