# AssessmentsV1API

All URIs are relative to *https://app.corellium.com/api*

Method | HTTP request | Description
------------- | ------------- | -------------
[**AssessmentsV1API_v1CreateAssessment**](AssessmentsV1API.md#AssessmentsV1API_v1CreateAssessment) | **POST** /v1/services/matrix/{instanceId}/assessments | Create an assessment.
[**AssessmentsV1API_v1CreateReportModification**](AssessmentsV1API.md#AssessmentsV1API_v1CreateReportModification) | **POST** /v1/services/matrix/{instanceId}/assessments/{assessmentId}/report-modification | Create report modifications.
[**AssessmentsV1API_v1DeleteAssessment**](AssessmentsV1API.md#AssessmentsV1API_v1DeleteAssessment) | **DELETE** /v1/services/matrix/{instanceId}/assessments/{assessmentId} | Delete an assessment.
[**AssessmentsV1API_v1DeleteReportModification**](AssessmentsV1API.md#AssessmentsV1API_v1DeleteReportModification) | **DELETE** /v1/services/matrix/{instanceId}/assessments/{assessmentId}/report-modification | Delete report modifications.
[**AssessmentsV1API_v1DownloadReport**](AssessmentsV1API.md#AssessmentsV1API_v1DownloadReport) | **GET** /v1/services/matrix/{instanceId}/assessments/{assessmentId}/download | Download an assessment report.
[**AssessmentsV1API_v1GetAssessmentById**](AssessmentsV1API.md#AssessmentsV1API_v1GetAssessmentById) | **GET** /v1/services/matrix/{instanceId}/assessments/{assessmentId} | Get an assessment by ID.
[**AssessmentsV1API_v1GetAssessmentsByInstanceId**](AssessmentsV1API.md#AssessmentsV1API_v1GetAssessmentsByInstanceId) | **GET** /v1/services/matrix/{instanceId}/instances/{targetInstanceId}/assessments | List assessments for an instance.
[**AssessmentsV1API_v1PatchAssessment**](AssessmentsV1API.md#AssessmentsV1API_v1PatchAssessment) | **PATCH** /v1/services/matrix/{instanceId}/assessments/{assessmentId} | Update an assessment status.
[**AssessmentsV1API_v1RunTests**](AssessmentsV1API.md#AssessmentsV1API_v1RunTests) | **POST** /v1/services/matrix/{instanceId}/assessments/{assessmentId}/test | Run assessment tests.
[**AssessmentsV1API_v1StartMonitoring**](AssessmentsV1API.md#AssessmentsV1API_v1StartMonitoring) | **POST** /v1/services/matrix/{instanceId}/assessments/{assessmentId}/start | Start assessment monitoring.
[**AssessmentsV1API_v1StopMonitoring**](AssessmentsV1API.md#AssessmentsV1API_v1StopMonitoring) | **POST** /v1/services/matrix/{instanceId}/assessments/{assessmentId}/stop | Stop assessment monitoring.


# **AssessmentsV1API_v1CreateAssessment**
```c
// Create an assessment.
//
// Creates a new MATRIX assessment for the instance. Existing assessments must be complete or failed and the instance must be powered on.
//
assessment_id_status_t* AssessmentsV1API_v1CreateAssessment(apiClient_t *apiClient, char *instanceId, create_assessment_input_t *create_assessment_input);
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

# **AssessmentsV1API_v1CreateReportModification**
```c
// Create report modifications.
//
// Applies one or more modifications (outcome, severity, or evidence suppression) to a completed assessment report.
//
list_t* AssessmentsV1API_v1CreateReportModification(apiClient_t *apiClient, char *instanceId, char *assessmentId, list_t *report_modification_input);
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

# **AssessmentsV1API_v1DeleteAssessment**
```c
// Delete an assessment.
//
// Deletes an assessment. The instance must be powered on.
//
void AssessmentsV1API_v1DeleteAssessment(apiClient_t *apiClient, char *instanceId, char *assessmentId);
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

# **AssessmentsV1API_v1DeleteReportModification**
```c
// Delete report modifications.
//
// Removes one or more previously applied report modifications from a completed assessment.
//
list_t* AssessmentsV1API_v1DeleteReportModification(apiClient_t *apiClient, char *instanceId, char *assessmentId, list_t *delete_modification_input);
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

# **AssessmentsV1API_v1DownloadReport**
```c
// Download an assessment report.
//
// Downloads the rendered assessment report. The assessment must be complete and have a generated report.
//
char* AssessmentsV1API_v1DownloadReport(apiClient_t *apiClient, char *instanceId, char *assessmentId, char *format);
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

# **AssessmentsV1API_v1GetAssessmentById**
```c
// Get an assessment by ID.
//
// Returns the full assessment record.
//
assessment_t* AssessmentsV1API_v1GetAssessmentById(apiClient_t *apiClient, char *instanceId, char *assessmentId);
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

# **AssessmentsV1API_v1GetAssessmentsByInstanceId**
```c
// List assessments for an instance.
//
// Returns a list of assessments for the given instance.
//
list_t* AssessmentsV1API_v1GetAssessmentsByInstanceId(apiClient_t *apiClient, char *instanceId, char *targetInstanceId);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**instanceId** | **char \*** | ID of the instance (virtual device) the assessment belongs to. The platform checks that you have access to this instance before the request reaches MATRIX, so use the ID of an instance in one of your projects. | 
**targetInstanceId** | **char \*** | ID of the instance whose assessments you want to list. Set this to the same value as &#x60;instanceId&#x60;; the path contains the ID twice only because of how the MATRIX service is routed. | 

### Return type

[list_t](assessment.md) *


### Authorization

[BearerAuth](../README.md#BearerAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AssessmentsV1API_v1PatchAssessment**
```c
// Update an assessment status.
//
// Updates the lifecycle status of an assessment.
//
assessment_t* AssessmentsV1API_v1PatchAssessment(apiClient_t *apiClient, char *instanceId, char *assessmentId, update_assessment_input_t *update_assessment_input);
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

# **AssessmentsV1API_v1RunTests**
```c
// Run assessment tests.
//
// Executes the MATRIX checks for an assessment. The assessment must have status \"readyForTesting\" and the instance must be powered on.
//
assessment_id_status_t* AssessmentsV1API_v1RunTests(apiClient_t *apiClient, char *instanceId, char *assessmentId, test_assessment_input_t *test_assessment_input);
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

# **AssessmentsV1API_v1StartMonitoring**
```c
// Start assessment monitoring.
//
// Begins device monitoring for an assessment. The assessment must have status \"new\" and the instance must be powered on.
//
void AssessmentsV1API_v1StartMonitoring(apiClient_t *apiClient, char *instanceId, char *assessmentId);
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

# **AssessmentsV1API_v1StopMonitoring**
```c
// Stop assessment monitoring.
//
// Stops device monitoring for an assessment. The assessment must have status \"monitoring\" and the instance must be powered on.
//
void AssessmentsV1API_v1StopMonitoring(apiClient_t *apiClient, char *instanceId, char *assessmentId);
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

