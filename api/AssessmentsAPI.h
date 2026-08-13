#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/assessment.h"
#include "../model/assessment_id_status.h"
#include "../model/create_assessment_input.h"
#include "../model/delete_modification_input.h"
#include "../model/matrix_error.h"
#include "../model/paginated_assessments.h"
#include "../model/report_modification_input.h"
#include "../model/report_modification_result.h"
#include "../model/test_assessment_input.h"
#include "../model/update_assessment_input.h"


// Create an assessment.
//
// Creates a new MATRIX assessment for the instance. Existing assessments must be complete or failed and the instance must be powered on.
//
assessment_id_status_t*
AssessmentsAPI_v3CreateAssessment(apiClient_t *apiClient, char *instanceId, create_assessment_input_t *create_assessment_input);


// Create report modifications.
//
// Applies one or more modifications (outcome, severity, or evidence suppression) to a completed assessment report.
//
list_t*
AssessmentsAPI_v3CreateReportModification(apiClient_t *apiClient, char *instanceId, char *assessmentId, list_t *report_modification_input);


// Delete an assessment.
//
// Deletes an assessment. The instance must be powered on.
//
void
AssessmentsAPI_v3DeleteAssessment(apiClient_t *apiClient, char *instanceId, char *assessmentId);


// Delete report modifications.
//
// Removes one or more previously applied report modifications from a completed assessment.
//
list_t*
AssessmentsAPI_v3DeleteReportModification(apiClient_t *apiClient, char *instanceId, char *assessmentId, list_t *delete_modification_input);


// Download an assessment report.
//
// Downloads the rendered assessment report. The assessment must be complete and have a generated report.
//
char*
AssessmentsAPI_v3DownloadReport(apiClient_t *apiClient, char *instanceId, char *assessmentId, char *format);


// Get an assessment by ID.
//
// Returns the full assessment record.
//
assessment_t*
AssessmentsAPI_v3GetAssessmentById(apiClient_t *apiClient, char *instanceId, char *assessmentId);


// List assessments for an instance.
//
// Returns a paginated list of assessments for the given instance.
//
paginated_assessments_t*
AssessmentsAPI_v3GetAssessmentsByInstanceId(apiClient_t *apiClient, char *instanceId, char *targetInstanceId, double *limit, double *offset);


// Update an assessment status.
//
// Updates the lifecycle status of an assessment.
//
assessment_t*
AssessmentsAPI_v3PatchAssessment(apiClient_t *apiClient, char *instanceId, char *assessmentId, update_assessment_input_t *update_assessment_input);


// Run assessment tests.
//
// Executes the MATRIX checks for an assessment. The assessment must have status \"readyForTesting\" and the instance must be powered on.
//
assessment_id_status_t*
AssessmentsAPI_v3RunTests(apiClient_t *apiClient, char *instanceId, char *assessmentId, test_assessment_input_t *test_assessment_input);


// Start assessment monitoring.
//
// Begins device monitoring for an assessment. The assessment must have status \"new\" and the instance must be powered on.
//
void
AssessmentsAPI_v3StartMonitoring(apiClient_t *apiClient, char *instanceId, char *assessmentId);


// Stop assessment monitoring.
//
// Stops device monitoring for an assessment. The assessment must have status \"monitoring\" and the instance must be powered on.
//
void
AssessmentsAPI_v3StopMonitoring(apiClient_t *apiClient, char *instanceId, char *assessmentId);


