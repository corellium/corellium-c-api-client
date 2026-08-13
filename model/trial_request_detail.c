#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "trial_request_detail.h"


char* trial_request_detail_billing_type_ToString(corellium_api_trial_request_detail_BILLINGTYPE_e billing_type) {
    char* billing_typeArray[] =  { "NULL", "prepaid", "usage", "metered", "credit", "cores_metered" };
    return billing_typeArray[billing_type];
}

corellium_api_trial_request_detail_BILLINGTYPE_e trial_request_detail_billing_type_FromString(char* billing_type){
    int stringToReturn = 0;
    char *billing_typeArray[] =  { "NULL", "prepaid", "usage", "metered", "credit", "cores_metered" };
    size_t sizeofArray = sizeof(billing_typeArray) / sizeof(billing_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(billing_type, billing_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}
char* trial_request_detail_organization_type_ToString(corellium_api_trial_request_detail_ORGANIZATIONTYPE_e organization_type) {
    char* organization_typeArray[] =  { "NULL", "individual", "enterprise", "" };
    return organization_typeArray[organization_type];
}

corellium_api_trial_request_detail_ORGANIZATIONTYPE_e trial_request_detail_organization_type_FromString(char* organization_type){
    int stringToReturn = 0;
    char *organization_typeArray[] =  { "NULL", "individual", "enterprise", "" };
    size_t sizeofArray = sizeof(organization_typeArray) / sizeof(organization_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(organization_type, organization_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}
char* trial_request_detail_grant_method_ToString(corellium_api_trial_request_detail_GRANTMETHOD_e grant_method) {
    char* grant_methodArray[] =  { "NULL", "sales", "auto", "" };
    return grant_methodArray[grant_method];
}

corellium_api_trial_request_detail_GRANTMETHOD_e trial_request_detail_grant_method_FromString(char* grant_method){
    int stringToReturn = 0;
    char *grant_methodArray[] =  { "NULL", "sales", "auto", "" };
    size_t sizeofArray = sizeof(grant_methodArray) / sizeof(grant_methodArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(grant_method, grant_methodArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static trial_request_detail_t *trial_request_detail_create_internal(
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
    ) {
    trial_request_detail_t *trial_request_detail_local_var = malloc(sizeof(trial_request_detail_t));
    if (!trial_request_detail_local_var) {
        return NULL;
    }
    trial_request_detail_local_var->identifier = identifier;
    trial_request_detail_local_var->metadata = metadata;
    trial_request_detail_local_var->organization = organization;
    trial_request_detail_local_var->devices = devices;
    trial_request_detail_local_var->use_cases = use_cases;
    trial_request_detail_local_var->email = email;
    trial_request_detail_local_var->name = name;
    trial_request_detail_local_var->billing_type = billing_type;
    trial_request_detail_local_var->billing_backend = billing_backend;
    trial_request_detail_local_var->billing_id = billing_id;
    trial_request_detail_local_var->product_id = product_id;
    trial_request_detail_local_var->code = code;
    trial_request_detail_local_var->enterprise = enterprise;
    trial_request_detail_local_var->granted = granted;
    trial_request_detail_local_var->phone = phone;
    trial_request_detail_local_var->country = country;
    trial_request_detail_local_var->organization_type = organization_type;
    trial_request_detail_local_var->industry = industry;
    trial_request_detail_local_var->role = role;
    trial_request_detail_local_var->solution = solution;
    trial_request_detail_local_var->domain = domain;
    trial_request_detail_local_var->started_at = started_at;
    trial_request_detail_local_var->granted_at = granted_at;
    trial_request_detail_local_var->denied_at = denied_at;
    trial_request_detail_local_var->plan_name = plan_name;
    trial_request_detail_local_var->ends_at = ends_at;
    trial_request_detail_local_var->grant_method = grant_method;
    trial_request_detail_local_var->duration = duration;
    trial_request_detail_local_var->trial_units = trial_units;
    trial_request_detail_local_var->created_at = created_at;
    trial_request_detail_local_var->updated_at = updated_at;

    trial_request_detail_local_var->_library_owned = 1;
    return trial_request_detail_local_var;
}

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
    ) {
    return trial_request_detail_create_internal (
        identifier,
        metadata,
        organization,
        devices,
        use_cases,
        email,
        name,
        billing_type,
        billing_backend,
        billing_id,
        product_id,
        code,
        enterprise,
        granted,
        phone,
        country,
        organization_type,
        industry,
        role,
        solution,
        domain,
        started_at,
        granted_at,
        denied_at,
        plan_name,
        ends_at,
        grant_method,
        duration,
        trial_units,
        created_at,
        updated_at
        );
}

void trial_request_detail_free(trial_request_detail_t *trial_request_detail) {
    if(NULL == trial_request_detail){
        return ;
    }
    if(trial_request_detail->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "trial_request_detail_free");
        return ;
    }
    listEntry_t *listEntry;
    if (trial_request_detail->identifier) {
        free(trial_request_detail->identifier);
        trial_request_detail->identifier = NULL;
    }
    if (trial_request_detail->metadata) {
        object_free(trial_request_detail->metadata);
        trial_request_detail->metadata = NULL;
    }
    if (trial_request_detail->organization) {
        trial_request_detail_organization_free(trial_request_detail->organization);
        trial_request_detail->organization = NULL;
    }
    if (trial_request_detail->devices) {
        list_ForEach(listEntry, trial_request_detail->devices) {
            object_free(listEntry->data);
        }
        list_freeList(trial_request_detail->devices);
        trial_request_detail->devices = NULL;
    }
    if (trial_request_detail->use_cases) {
        list_ForEach(listEntry, trial_request_detail->use_cases) {
            object_free(listEntry->data);
        }
        list_freeList(trial_request_detail->use_cases);
        trial_request_detail->use_cases = NULL;
    }
    if (trial_request_detail->email) {
        free(trial_request_detail->email);
        trial_request_detail->email = NULL;
    }
    if (trial_request_detail->name) {
        free(trial_request_detail->name);
        trial_request_detail->name = NULL;
    }
    if (trial_request_detail->billing_backend) {
        free(trial_request_detail->billing_backend);
        trial_request_detail->billing_backend = NULL;
    }
    if (trial_request_detail->billing_id) {
        free(trial_request_detail->billing_id);
        trial_request_detail->billing_id = NULL;
    }
    if (trial_request_detail->product_id) {
        free(trial_request_detail->product_id);
        trial_request_detail->product_id = NULL;
    }
    if (trial_request_detail->code) {
        free(trial_request_detail->code);
        trial_request_detail->code = NULL;
    }
    if (trial_request_detail->phone) {
        free(trial_request_detail->phone);
        trial_request_detail->phone = NULL;
    }
    if (trial_request_detail->country) {
        free(trial_request_detail->country);
        trial_request_detail->country = NULL;
    }
    if (trial_request_detail->industry) {
        free(trial_request_detail->industry);
        trial_request_detail->industry = NULL;
    }
    if (trial_request_detail->role) {
        free(trial_request_detail->role);
        trial_request_detail->role = NULL;
    }
    if (trial_request_detail->solution) {
        free(trial_request_detail->solution);
        trial_request_detail->solution = NULL;
    }
    if (trial_request_detail->domain) {
        free(trial_request_detail->domain);
        trial_request_detail->domain = NULL;
    }
    if (trial_request_detail->started_at) {
        free(trial_request_detail->started_at);
        trial_request_detail->started_at = NULL;
    }
    if (trial_request_detail->granted_at) {
        free(trial_request_detail->granted_at);
        trial_request_detail->granted_at = NULL;
    }
    if (trial_request_detail->denied_at) {
        free(trial_request_detail->denied_at);
        trial_request_detail->denied_at = NULL;
    }
    if (trial_request_detail->plan_name) {
        free(trial_request_detail->plan_name);
        trial_request_detail->plan_name = NULL;
    }
    if (trial_request_detail->ends_at) {
        free(trial_request_detail->ends_at);
        trial_request_detail->ends_at = NULL;
    }
    if (trial_request_detail->created_at) {
        free(trial_request_detail->created_at);
        trial_request_detail->created_at = NULL;
    }
    if (trial_request_detail->updated_at) {
        free(trial_request_detail->updated_at);
        trial_request_detail->updated_at = NULL;
    }
    free(trial_request_detail);
}

cJSON *trial_request_detail_convertToJSON(trial_request_detail_t *trial_request_detail) {
    cJSON *item = cJSON_CreateObject();

    // trial_request_detail->identifier
    if (!trial_request_detail->identifier) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "identifier", trial_request_detail->identifier) == NULL) {
    goto fail; //String
    }


    // trial_request_detail->metadata
    if(trial_request_detail->metadata) {
    cJSON *metadata_object = object_convertToJSON(trial_request_detail->metadata);
    if(metadata_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // trial_request_detail->organization
    if(trial_request_detail->organization) {
    cJSON *organization_local_JSON = trial_request_detail_organization_convertToJSON(trial_request_detail->organization);
    if(organization_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "organization", organization_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // trial_request_detail->devices
    if(trial_request_detail->devices) {
    cJSON *devices = cJSON_AddArrayToObject(item, "devices");
    if(devices == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *devicesListEntry;
    if (trial_request_detail->devices) {
    list_ForEach(devicesListEntry, trial_request_detail->devices) {
    cJSON *itemLocal = object_convertToJSON(devicesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(devices, itemLocal);
    }
    }
    }


    // trial_request_detail->use_cases
    if(trial_request_detail->use_cases) {
    cJSON *use_cases = cJSON_AddArrayToObject(item, "useCases");
    if(use_cases == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *use_casesListEntry;
    if (trial_request_detail->use_cases) {
    list_ForEach(use_casesListEntry, trial_request_detail->use_cases) {
    cJSON *itemLocal = object_convertToJSON(use_casesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(use_cases, itemLocal);
    }
    }
    }


    // trial_request_detail->email
    if (!trial_request_detail->email) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "email", trial_request_detail->email) == NULL) {
    goto fail; //String
    }


    // trial_request_detail->name
    if (!trial_request_detail->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", trial_request_detail->name) == NULL) {
    goto fail; //String
    }


    // trial_request_detail->billing_type
    if (corellium_api_trial_request_detail_BILLINGTYPE_NULL == trial_request_detail->billing_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "billingType", trial_request_detail_billing_type_ToString(trial_request_detail->billing_type)) == NULL)
    {
    goto fail; //Enum
    }


    // trial_request_detail->billing_backend
    if(trial_request_detail->billing_backend) {
    if(cJSON_AddStringToObject(item, "billingBackend", trial_request_detail->billing_backend) == NULL) {
    goto fail; //String
    }
    }


    // trial_request_detail->billing_id
    if(trial_request_detail->billing_id) {
    if(cJSON_AddStringToObject(item, "billingId", trial_request_detail->billing_id) == NULL) {
    goto fail; //String
    }
    }


    // trial_request_detail->product_id
    if(trial_request_detail->product_id) {
    if(cJSON_AddStringToObject(item, "productId", trial_request_detail->product_id) == NULL) {
    goto fail; //String
    }
    }


    // trial_request_detail->code
    if (!trial_request_detail->code) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "code", trial_request_detail->code) == NULL) {
    goto fail; //String
    }


    // trial_request_detail->enterprise
    if (!trial_request_detail->enterprise) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "enterprise", trial_request_detail->enterprise) == NULL) {
    goto fail; //Bool
    }


    // trial_request_detail->granted
    if (!trial_request_detail->granted) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "granted", trial_request_detail->granted) == NULL) {
    goto fail; //Bool
    }


    // trial_request_detail->phone
    if(trial_request_detail->phone) {
    if(cJSON_AddStringToObject(item, "phone", trial_request_detail->phone) == NULL) {
    goto fail; //String
    }
    }


    // trial_request_detail->country
    if(trial_request_detail->country) {
    if(cJSON_AddStringToObject(item, "country", trial_request_detail->country) == NULL) {
    goto fail; //String
    }
    }


    // trial_request_detail->organization_type
    if(trial_request_detail->organization_type != corellium_api_trial_request_detail_ORGANIZATIONTYPE_NULL) {
    if(cJSON_AddStringToObject(item, "organizationType", trial_request_detail_organization_type_ToString(trial_request_detail->organization_type)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // trial_request_detail->industry
    if(trial_request_detail->industry) {
    if(cJSON_AddStringToObject(item, "industry", trial_request_detail->industry) == NULL) {
    goto fail; //String
    }
    }


    // trial_request_detail->role
    if(trial_request_detail->role) {
    if(cJSON_AddStringToObject(item, "role", trial_request_detail->role) == NULL) {
    goto fail; //String
    }
    }


    // trial_request_detail->solution
    if(trial_request_detail->solution) {
    if(cJSON_AddStringToObject(item, "solution", trial_request_detail->solution) == NULL) {
    goto fail; //String
    }
    }


    // trial_request_detail->domain
    if(trial_request_detail->domain) {
    if(cJSON_AddStringToObject(item, "domain", trial_request_detail->domain) == NULL) {
    goto fail; //String
    }
    }


    // trial_request_detail->started_at
    if(trial_request_detail->started_at) {
    if(cJSON_AddStringToObject(item, "startedAt", trial_request_detail->started_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // trial_request_detail->granted_at
    if(trial_request_detail->granted_at) {
    if(cJSON_AddStringToObject(item, "grantedAt", trial_request_detail->granted_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // trial_request_detail->denied_at
    if(trial_request_detail->denied_at) {
    if(cJSON_AddStringToObject(item, "deniedAt", trial_request_detail->denied_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // trial_request_detail->plan_name
    if(trial_request_detail->plan_name) {
    if(cJSON_AddStringToObject(item, "planName", trial_request_detail->plan_name) == NULL) {
    goto fail; //String
    }
    }


    // trial_request_detail->ends_at
    if(trial_request_detail->ends_at) {
    if(cJSON_AddStringToObject(item, "endsAt", trial_request_detail->ends_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // trial_request_detail->grant_method
    if(trial_request_detail->grant_method != corellium_api_trial_request_detail_GRANTMETHOD_NULL) {
    if(cJSON_AddStringToObject(item, "grantMethod", trial_request_detail_grant_method_ToString(trial_request_detail->grant_method)) == NULL)
    {
    goto fail; //Enum
    }
    }


    // trial_request_detail->duration
    if(trial_request_detail->duration) {
    if(cJSON_AddNumberToObject(item, "duration", trial_request_detail->duration) == NULL) {
    goto fail; //Numeric
    }
    }


    // trial_request_detail->trial_units
    if(trial_request_detail->trial_units) {
    if(cJSON_AddNumberToObject(item, "trialUnits", trial_request_detail->trial_units) == NULL) {
    goto fail; //Numeric
    }
    }


    // trial_request_detail->created_at
    if (!trial_request_detail->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "createdAt", trial_request_detail->created_at) == NULL) {
    goto fail; //Date-Time
    }


    // trial_request_detail->updated_at
    if (!trial_request_detail->updated_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "updatedAt", trial_request_detail->updated_at) == NULL) {
    goto fail; //Date-Time
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

trial_request_detail_t *trial_request_detail_parseFromJSON(cJSON *trial_request_detailJSON){

    trial_request_detail_t *trial_request_detail_local_var = NULL;

    // define the local variable for trial_request_detail->organization
    trial_request_detail_organization_t *organization_local_nonprim = NULL;

    // define the local list for trial_request_detail->devices
    list_t *devicesList = NULL;

    // define the local list for trial_request_detail->use_cases
    list_t *use_casesList = NULL;

    // trial_request_detail->identifier
    cJSON *identifier = cJSON_GetObjectItemCaseSensitive(trial_request_detailJSON, "identifier");
    if (cJSON_IsNull(identifier)) {
        identifier = NULL;
    }
    if (!identifier) {
        goto end;
    }

    
    if(!cJSON_IsString(identifier))
    {
    goto end; //String
    }

    // trial_request_detail->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(trial_request_detailJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    object_t *metadata_local_object = NULL;
    if (metadata) { 
    metadata_local_object = object_parseFromJSON(metadata); //object
    }

    // trial_request_detail->organization
    cJSON *organization = cJSON_GetObjectItemCaseSensitive(trial_request_detailJSON, "organization");
    if (cJSON_IsNull(organization)) {
        organization = NULL;
    }
    if (organization) { 
    organization_local_nonprim = trial_request_detail_organization_parseFromJSON(organization); //nonprimitive
    }

    // trial_request_detail->devices
    cJSON *devices = cJSON_GetObjectItemCaseSensitive(trial_request_detailJSON, "devices");
    if (cJSON_IsNull(devices)) {
        devices = NULL;
    }
    if (devices) { 
    cJSON *devices_local_nonprimitive = NULL;
    if(!cJSON_IsArray(devices)){
        goto end; //nonprimitive container
    }

    devicesList = list_createList();

    cJSON_ArrayForEach(devices_local_nonprimitive,devices )
    {
        if(!cJSON_IsObject(devices_local_nonprimitive)){
            goto end;
        }
        object_t *devicesItem = object_parseFromJSON(devices_local_nonprimitive);

        list_addElement(devicesList, devicesItem);
    }
    }

    // trial_request_detail->use_cases
    cJSON *use_cases = cJSON_GetObjectItemCaseSensitive(trial_request_detailJSON, "useCases");
    if (cJSON_IsNull(use_cases)) {
        use_cases = NULL;
    }
    if (use_cases) { 
    cJSON *use_cases_local_nonprimitive = NULL;
    if(!cJSON_IsArray(use_cases)){
        goto end; //nonprimitive container
    }

    use_casesList = list_createList();

    cJSON_ArrayForEach(use_cases_local_nonprimitive,use_cases )
    {
        if(!cJSON_IsObject(use_cases_local_nonprimitive)){
            goto end;
        }
        object_t *use_casesItem = object_parseFromJSON(use_cases_local_nonprimitive);

        list_addElement(use_casesList, use_casesItem);
    }
    }

    // trial_request_detail->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(trial_request_detailJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (!email) {
        goto end;
    }

    
    if(!cJSON_IsString(email))
    {
    goto end; //String
    }

    // trial_request_detail->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(trial_request_detailJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // trial_request_detail->billing_type
    cJSON *billing_type = cJSON_GetObjectItemCaseSensitive(trial_request_detailJSON, "billingType");
    if (cJSON_IsNull(billing_type)) {
        billing_type = NULL;
    }
    if (!billing_type) {
        goto end;
    }

    corellium_api_trial_request_detail_BILLINGTYPE_e billing_typeVariable;
    
    if(!cJSON_IsString(billing_type))
    {
    goto end; //Enum
    }
    billing_typeVariable = trial_request_detail_billing_type_FromString(billing_type->valuestring);

    // trial_request_detail->billing_backend
    cJSON *billing_backend = cJSON_GetObjectItemCaseSensitive(trial_request_detailJSON, "billingBackend");
    if (cJSON_IsNull(billing_backend)) {
        billing_backend = NULL;
    }
    if (billing_backend) { 
    if(!cJSON_IsString(billing_backend) && !cJSON_IsNull(billing_backend))
    {
    goto end; //String
    }
    }

    // trial_request_detail->billing_id
    cJSON *billing_id = cJSON_GetObjectItemCaseSensitive(trial_request_detailJSON, "billingId");
    if (cJSON_IsNull(billing_id)) {
        billing_id = NULL;
    }
    if (billing_id) { 
    if(!cJSON_IsString(billing_id) && !cJSON_IsNull(billing_id))
    {
    goto end; //String
    }
    }

    // trial_request_detail->product_id
    cJSON *product_id = cJSON_GetObjectItemCaseSensitive(trial_request_detailJSON, "productId");
    if (cJSON_IsNull(product_id)) {
        product_id = NULL;
    }
    if (product_id) { 
    if(!cJSON_IsString(product_id) && !cJSON_IsNull(product_id))
    {
    goto end; //String
    }
    }

    // trial_request_detail->code
    cJSON *code = cJSON_GetObjectItemCaseSensitive(trial_request_detailJSON, "code");
    if (cJSON_IsNull(code)) {
        code = NULL;
    }
    if (!code) {
        goto end;
    }

    
    if(!cJSON_IsString(code))
    {
    goto end; //String
    }

    // trial_request_detail->enterprise
    cJSON *enterprise = cJSON_GetObjectItemCaseSensitive(trial_request_detailJSON, "enterprise");
    if (cJSON_IsNull(enterprise)) {
        enterprise = NULL;
    }
    if (!enterprise) {
        goto end;
    }

    
    if(!cJSON_IsBool(enterprise))
    {
    goto end; //Bool
    }

    // trial_request_detail->granted
    cJSON *granted = cJSON_GetObjectItemCaseSensitive(trial_request_detailJSON, "granted");
    if (cJSON_IsNull(granted)) {
        granted = NULL;
    }
    if (!granted) {
        goto end;
    }

    
    if(!cJSON_IsBool(granted))
    {
    goto end; //Bool
    }

    // trial_request_detail->phone
    cJSON *phone = cJSON_GetObjectItemCaseSensitive(trial_request_detailJSON, "phone");
    if (cJSON_IsNull(phone)) {
        phone = NULL;
    }
    if (phone) { 
    if(!cJSON_IsString(phone) && !cJSON_IsNull(phone))
    {
    goto end; //String
    }
    }

    // trial_request_detail->country
    cJSON *country = cJSON_GetObjectItemCaseSensitive(trial_request_detailJSON, "country");
    if (cJSON_IsNull(country)) {
        country = NULL;
    }
    if (country) { 
    if(!cJSON_IsString(country) && !cJSON_IsNull(country))
    {
    goto end; //String
    }
    }

    // trial_request_detail->organization_type
    cJSON *organization_type = cJSON_GetObjectItemCaseSensitive(trial_request_detailJSON, "organizationType");
    if (cJSON_IsNull(organization_type)) {
        organization_type = NULL;
    }
    corellium_api_trial_request_detail_ORGANIZATIONTYPE_e organization_typeVariable;
    if (organization_type) { 
    if(!cJSON_IsString(organization_type))
    {
    goto end; //Enum
    }
    organization_typeVariable = trial_request_detail_organization_type_FromString(organization_type->valuestring);
    }

    // trial_request_detail->industry
    cJSON *industry = cJSON_GetObjectItemCaseSensitive(trial_request_detailJSON, "industry");
    if (cJSON_IsNull(industry)) {
        industry = NULL;
    }
    if (industry) { 
    if(!cJSON_IsString(industry) && !cJSON_IsNull(industry))
    {
    goto end; //String
    }
    }

    // trial_request_detail->role
    cJSON *role = cJSON_GetObjectItemCaseSensitive(trial_request_detailJSON, "role");
    if (cJSON_IsNull(role)) {
        role = NULL;
    }
    if (role) { 
    if(!cJSON_IsString(role) && !cJSON_IsNull(role))
    {
    goto end; //String
    }
    }

    // trial_request_detail->solution
    cJSON *solution = cJSON_GetObjectItemCaseSensitive(trial_request_detailJSON, "solution");
    if (cJSON_IsNull(solution)) {
        solution = NULL;
    }
    if (solution) { 
    if(!cJSON_IsString(solution) && !cJSON_IsNull(solution))
    {
    goto end; //String
    }
    }

    // trial_request_detail->domain
    cJSON *domain = cJSON_GetObjectItemCaseSensitive(trial_request_detailJSON, "domain");
    if (cJSON_IsNull(domain)) {
        domain = NULL;
    }
    if (domain) { 
    if(!cJSON_IsString(domain) && !cJSON_IsNull(domain))
    {
    goto end; //String
    }
    }

    // trial_request_detail->started_at
    cJSON *started_at = cJSON_GetObjectItemCaseSensitive(trial_request_detailJSON, "startedAt");
    if (cJSON_IsNull(started_at)) {
        started_at = NULL;
    }
    if (started_at) { 
    if(!cJSON_IsString(started_at) && !cJSON_IsNull(started_at))
    {
    goto end; //DateTime
    }
    }

    // trial_request_detail->granted_at
    cJSON *granted_at = cJSON_GetObjectItemCaseSensitive(trial_request_detailJSON, "grantedAt");
    if (cJSON_IsNull(granted_at)) {
        granted_at = NULL;
    }
    if (granted_at) { 
    if(!cJSON_IsString(granted_at) && !cJSON_IsNull(granted_at))
    {
    goto end; //DateTime
    }
    }

    // trial_request_detail->denied_at
    cJSON *denied_at = cJSON_GetObjectItemCaseSensitive(trial_request_detailJSON, "deniedAt");
    if (cJSON_IsNull(denied_at)) {
        denied_at = NULL;
    }
    if (denied_at) { 
    if(!cJSON_IsString(denied_at) && !cJSON_IsNull(denied_at))
    {
    goto end; //DateTime
    }
    }

    // trial_request_detail->plan_name
    cJSON *plan_name = cJSON_GetObjectItemCaseSensitive(trial_request_detailJSON, "planName");
    if (cJSON_IsNull(plan_name)) {
        plan_name = NULL;
    }
    if (plan_name) { 
    if(!cJSON_IsString(plan_name) && !cJSON_IsNull(plan_name))
    {
    goto end; //String
    }
    }

    // trial_request_detail->ends_at
    cJSON *ends_at = cJSON_GetObjectItemCaseSensitive(trial_request_detailJSON, "endsAt");
    if (cJSON_IsNull(ends_at)) {
        ends_at = NULL;
    }
    if (ends_at) { 
    if(!cJSON_IsString(ends_at) && !cJSON_IsNull(ends_at))
    {
    goto end; //DateTime
    }
    }

    // trial_request_detail->grant_method
    cJSON *grant_method = cJSON_GetObjectItemCaseSensitive(trial_request_detailJSON, "grantMethod");
    if (cJSON_IsNull(grant_method)) {
        grant_method = NULL;
    }
    corellium_api_trial_request_detail_GRANTMETHOD_e grant_methodVariable;
    if (grant_method) { 
    if(!cJSON_IsString(grant_method))
    {
    goto end; //Enum
    }
    grant_methodVariable = trial_request_detail_grant_method_FromString(grant_method->valuestring);
    }

    // trial_request_detail->duration
    cJSON *duration = cJSON_GetObjectItemCaseSensitive(trial_request_detailJSON, "duration");
    if (cJSON_IsNull(duration)) {
        duration = NULL;
    }
    if (duration) { 
    if(!cJSON_IsNumber(duration))
    {
    goto end; //Numeric
    }
    }

    // trial_request_detail->trial_units
    cJSON *trial_units = cJSON_GetObjectItemCaseSensitive(trial_request_detailJSON, "trialUnits");
    if (cJSON_IsNull(trial_units)) {
        trial_units = NULL;
    }
    if (trial_units) { 
    if(!cJSON_IsNumber(trial_units))
    {
    goto end; //Numeric
    }
    }

    // trial_request_detail->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(trial_request_detailJSON, "createdAt");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (!created_at) {
        goto end;
    }

    
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //DateTime
    }

    // trial_request_detail->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(trial_request_detailJSON, "updatedAt");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (!updated_at) {
        goto end;
    }

    
    if(!cJSON_IsString(updated_at) && !cJSON_IsNull(updated_at))
    {
    goto end; //DateTime
    }


    trial_request_detail_local_var = trial_request_detail_create_internal (
        strdup(identifier->valuestring),
        metadata ? metadata_local_object : NULL,
        organization ? organization_local_nonprim : NULL,
        devices ? devicesList : NULL,
        use_cases ? use_casesList : NULL,
        strdup(email->valuestring),
        strdup(name->valuestring),
        billing_typeVariable,
        billing_backend && !cJSON_IsNull(billing_backend) ? strdup(billing_backend->valuestring) : NULL,
        billing_id && !cJSON_IsNull(billing_id) ? strdup(billing_id->valuestring) : NULL,
        product_id && !cJSON_IsNull(product_id) ? strdup(product_id->valuestring) : NULL,
        strdup(code->valuestring),
        enterprise->valueint,
        granted->valueint,
        phone && !cJSON_IsNull(phone) ? strdup(phone->valuestring) : NULL,
        country && !cJSON_IsNull(country) ? strdup(country->valuestring) : NULL,
        organization_type ? organization_typeVariable : corellium_api_trial_request_detail_ORGANIZATIONTYPE_NULL,
        industry && !cJSON_IsNull(industry) ? strdup(industry->valuestring) : NULL,
        role && !cJSON_IsNull(role) ? strdup(role->valuestring) : NULL,
        solution && !cJSON_IsNull(solution) ? strdup(solution->valuestring) : NULL,
        domain && !cJSON_IsNull(domain) ? strdup(domain->valuestring) : NULL,
        started_at && !cJSON_IsNull(started_at) ? strdup(started_at->valuestring) : NULL,
        granted_at && !cJSON_IsNull(granted_at) ? strdup(granted_at->valuestring) : NULL,
        denied_at && !cJSON_IsNull(denied_at) ? strdup(denied_at->valuestring) : NULL,
        plan_name && !cJSON_IsNull(plan_name) ? strdup(plan_name->valuestring) : NULL,
        ends_at && !cJSON_IsNull(ends_at) ? strdup(ends_at->valuestring) : NULL,
        grant_method ? grant_methodVariable : corellium_api_trial_request_detail_GRANTMETHOD_NULL,
        duration ? duration->valuedouble : 0,
        trial_units ? trial_units->valuedouble : 0,
        strdup(created_at->valuestring),
        strdup(updated_at->valuestring)
        );

    return trial_request_detail_local_var;
end:
    if (organization_local_nonprim) {
        trial_request_detail_organization_free(organization_local_nonprim);
        organization_local_nonprim = NULL;
    }
    if (devicesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, devicesList) {
            object_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(devicesList);
        devicesList = NULL;
    }
    if (use_casesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, use_casesList) {
            object_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(use_casesList);
        use_casesList = NULL;
    }
    return NULL;

}
