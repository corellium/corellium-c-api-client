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
// Creates a new MATRIX assessment for the instance. Existing assessments must be complete or failed and the instance must be powered on.
//
assessment_id_status_t* AssessmentsAPI_v3CreateAssessment(apiClient_t *apiClient, char *instanceId, create_assessment_input_t *create_assessment_input);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Identifier of the instance, supplied as the MATRIX service-proxy path segment. | 
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
// Applies one or more modifications (outcome, severity, or evidence suppression) to a completed assessment report.
//
list_t* AssessmentsAPI_v3CreateReportModification(apiClient_t *apiClient, char *instanceId, char *assessmentId, list_t *report_modification_input);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Identifier of the instance, supplied as the MATRIX service-proxy path segment. | 
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
// Deletes an assessment. The instance must be powered on.
//
void AssessmentsAPI_v3DeleteAssessment(apiClient_t *apiClient, char *instanceId, char *assessmentId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Identifier of the instance, supplied as the MATRIX service-proxy path segment. | 
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
// Removes one or more previously applied report modifications from a completed assessment.
//
list_t* AssessmentsAPI_v3DeleteReportModification(apiClient_t *apiClient, char *instanceId, char *assessmentId, list_t *delete_modification_input);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Identifier of the instance, supplied as the MATRIX service-proxy path segment. | 
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
// Downloads the rendered assessment report. The assessment must be complete and have a generated report.
//
char* AssessmentsAPI_v3DownloadReport(apiClient_t *apiClient, char *instanceId, char *assessmentId, char *format);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Identifier of the instance, supplied as the MATRIX service-proxy path segment. | 
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
// Returns the full assessment record.
//
assessment_t* AssessmentsAPI_v3GetAssessmentById(apiClient_t *apiClient, char *instanceId, char *assessmentId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Identifier of the instance, supplied as the MATRIX service-proxy path segment. | 
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
// Returns a paginated list of assessments for the given instance.
//
paginated_assessments_t* AssessmentsAPI_v3GetAssessmentsByInstanceId(apiClient_t *apiClient, char *instanceId, char *targetInstanceId, double *limit, double *offset, char *sort, char *name, char *version, char *status, char *createdBy, char *wordlist, char *frida, char *corelliumVersion, char *createdAt);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Identifier of the instance, supplied as the MATRIX service-proxy path segment. | 
**targetInstanceId** | **char \*** | Identifier of the instance whose assessments are listed. | 
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
// Updates the lifecycle status of an assessment.
//
assessment_t* AssessmentsAPI_v3PatchAssessment(apiClient_t *apiClient, char *instanceId, char *assessmentId, update_assessment_input_t *update_assessment_input);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Identifier of the instance, supplied as the MATRIX service-proxy path segment. | 
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
// Executes the MATRIX checks for an assessment. The assessment must have status \"readyForTesting\" and the instance must be powered on.
//
assessment_id_status_t* AssessmentsAPI_v3RunTests(apiClient_t *apiClient, char *instanceId, char *assessmentId, test_assessment_input_t *test_assessment_input);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Identifier of the instance, supplied as the MATRIX service-proxy path segment. | 
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
// Begins device monitoring for an assessment. The assessment must have status \"new\" and the instance must be powered on.
//
void AssessmentsAPI_v3StartMonitoring(apiClient_t *apiClient, char *instanceId, char *assessmentId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Identifier of the instance, supplied as the MATRIX service-proxy path segment. | 
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
// Stops device monitoring for an assessment. The assessment must have status \"monitoring\" and the instance must be powered on.
//
void AssessmentsAPI_v3StopMonitoring(apiClient_t *apiClient, char *instanceId, char *assessmentId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | Identifier of the instance, supplied as the MATRIX service-proxy path segment. | 
**assessmentId** | **char \*** | Identifier of the assessment. | 

### Return type

void

### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

