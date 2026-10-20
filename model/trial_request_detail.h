/*
 * trial_request_detail.h
 *
 * 
 */

#ifndef _trial_request_detail_H_
#define _trial_request_detail_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct trial_request_detail_t trial_request_detail_t;

#include "any_type.h"
#include "object.h"
#include "trial_request_detail_organization.h"

// Enum BILLINGTYPE for trial_request_detail

typedef enum  { corellium_api_trial_request_detail_BILLINGTYPE_NULL = 0, corellium_api_trial_request_detail_BILLINGTYPE_prepaid, corellium_api_trial_request_detail_BILLINGTYPE_usage, corellium_api_trial_request_detail_BILLINGTYPE_metered, corellium_api_trial_request_detail_BILLINGTYPE_credit, corellium_api_trial_request_detail_BILLINGTYPE_cores_metered } corellium_api_trial_request_detail_BILLINGTYPE_e;

char* trial_request_detail_billing_type_ToString(corellium_api_trial_request_detail_BILLINGTYPE_e billing_type);

corellium_api_trial_request_detail_BILLINGTYPE_e trial_request_detail_billing_type_FromString(char* billing_type);

// Enum ORGANIZATIONTYPE for trial_request_detail

typedef enum  { corellium_api_trial_request_detail_ORGANIZATIONTYPE_NULL = 0, corellium_api_trial_request_detail_ORGANIZATIONTYPE_individual, corellium_api_trial_request_detail_ORGANIZATIONTYPE_enterprise } corellium_api_trial_request_detail_ORGANIZATIONTYPE_e;

char* trial_request_detail_organization_type_ToString(corellium_api_trial_request_detail_ORGANIZATIONTYPE_e organization_type);

corellium_api_trial_request_detail_ORGANIZATIONTYPE_e trial_request_detail_organization_type_FromString(char* organization_type);

// Enum GRANTMETHOD for trial_request_detail

typedef enum  { corellium_api_trial_request_detail_GRANTMETHOD_NULL = 0, corellium_api_trial_request_detail_GRANTMETHOD_sales, corellium_api_trial_request_detail_GRANTMETHOD__auto } corellium_api_trial_request_detail_GRANTMETHOD_e;

char* trial_request_detail_grant_method_ToString(corellium_api_trial_request_detail_GRANTMETHOD_e grant_method);

corellium_api_trial_request_detail_GRANTMETHOD_e trial_request_detail_grant_method_FromString(char* grant_method);



typedef struct trial_request_detail_t {
    char *identifier; // string
    object_t *metadata; //object
    struct trial_request_detail_organization_t *organization; //model
    list_t *devices; //nonprimitive container
    list_t *use_cases; //nonprimitive container
    char *email; // string
    char *name; // string
    corellium_api_trial_request_detail_BILLINGTYPE_e billing_type; //enum
    char *billing_backend; // string
    char *billing_id; // string
    char *product_id; // string
    char *code; // string
    int enterprise; //boolean
    int granted; //boolean
    char *phone; // string
    char *country; // string
    corellium_api_trial_request_detail_ORGANIZATIONTYPE_e organization_type; //enum
    char *industry; // string
    char *role; // string
    char *solution; // string
    char *domain; // string
    char *started_at; //date time
    char *granted_at; //date time
    char *denied_at; //date time
    char *plan_name; // string
    char *ends_at; //date time
    corellium_api_trial_request_detail_GRANTMETHOD_e grant_method; //enum
    double duration; //numeric
    double trial_units; //numeric
    char *created_at; //date time
    char *updated_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} trial_request_detail_t;

__attribute__((deprecated)) trial_request_detail_t *trial_request_detail_create(
    char *identifier,
    object_t *metadata,
    trial_request_detail_organization_t *organization,
    list_t *devices,
    list_t *use_cases,
    char *email,
    char *name,
    corellium_api_trial_request_detail_BILLINGTYPE_e billing_type,
    char *billing_backend,
    char *billing_id,
    char *product_id,
    char *code,
    int enterprise,
    int granted,
    char *phone,
    char *country,
    corellium_api_trial_request_detail_ORGANIZATIONTYPE_e organization_type,
    char *industry,
    char *role,
    char *solution,
    char *domain,
    char *started_at,
    char *granted_at,
    char *denied_at,
    char *plan_name,
    char *ends_at,
    corellium_api_trial_request_detail_GRANTMETHOD_e grant_method,
    double duration,
    double trial_units,
    char *created_at,
    char *updated_at
);

void trial_request_detail_free(trial_request_detail_t *trial_request_detail);

trial_request_detail_t *trial_request_detail_parseFromJSON(cJSON *trial_request_detailJSON);

cJSON *trial_request_detail_convertToJSON(trial_request_detail_t *trial_request_detail);

#endif /* _trial_request_detail_H_ */

