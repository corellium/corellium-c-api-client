#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "trial_request.h"



static trial_request_t *trial_request_create_internal(
    char *email,
    char *name,
    char *billing_type,
    char *billing_id,
    char *code,
    int enterprise,
    int granted,
    char *phone,
    char *country,
    char *organization,
    char *organization_type,
    object_t *metadata,
    double created_at,
    double updated_at,
    char *display_status
    ) {
    trial_request_t *trial_request_local_var = malloc(sizeof(trial_request_t));
    if (!trial_request_local_var) {
        return NULL;
    }
    trial_request_local_var->email = email;
    trial_request_local_var->name = name;
    trial_request_local_var->billing_type = billing_type;
    trial_request_local_var->billing_id = billing_id;
    trial_request_local_var->code = code;
    trial_request_local_var->enterprise = enterprise;
    trial_request_local_var->granted = granted;
    trial_request_local_var->phone = phone;
    trial_request_local_var->country = country;
    trial_request_local_var->organization = organization;
    trial_request_local_var->organization_type = organization_type;
    trial_request_local_var->metadata = metadata;
    trial_request_local_var->created_at = created_at;
    trial_request_local_var->updated_at = updated_at;
    trial_request_local_var->display_status = display_status;

    trial_request_local_var->_library_owned = 1;
    return trial_request_local_var;
}

__attribute__((deprecated)) trial_request_t *trial_request_create(
    char *email,
    char *name,
    char *billing_type,
    char *billing_id,
    char *code,
    int enterprise,
    int granted,
    char *phone,
    char *country,
    char *organization,
    char *organization_type,
    object_t *metadata,
    double created_at,
    double updated_at,
    char *display_status
    ) {
    return trial_request_create_internal (
        email,
        name,
        billing_type,
        billing_id,
        code,
        enterprise,
        granted,
        phone,
        country,
        organization,
        organization_type,
        metadata,
        created_at,
        updated_at,
        display_status
        );
}

void trial_request_free(trial_request_t *trial_request) {
    if(NULL == trial_request){
        return ;
    }
    if(trial_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "trial_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (trial_request->email) {
        free(trial_request->email);
        trial_request->email = NULL;
    }
    if (trial_request->name) {
        free(trial_request->name);
        trial_request->name = NULL;
    }
    if (trial_request->billing_type) {
        free(trial_request->billing_type);
        trial_request->billing_type = NULL;
    }
    if (trial_request->billing_id) {
        free(trial_request->billing_id);
        trial_request->billing_id = NULL;
    }
    if (trial_request->code) {
        free(trial_request->code);
        trial_request->code = NULL;
    }
    if (trial_request->phone) {
        free(trial_request->phone);
        trial_request->phone = NULL;
    }
    if (trial_request->country) {
        free(trial_request->country);
        trial_request->country = NULL;
    }
    if (trial_request->organization) {
        free(trial_request->organization);
        trial_request->organization = NULL;
    }
    if (trial_request->organization_type) {
        free(trial_request->organization_type);
        trial_request->organization_type = NULL;
    }
    if (trial_request->metadata) {
        object_free(trial_request->metadata);
        trial_request->metadata = NULL;
    }
    if (trial_request->display_status) {
        free(trial_request->display_status);
        trial_request->display_status = NULL;
    }
    free(trial_request);
}

cJSON *trial_request_convertToJSON(trial_request_t *trial_request) {
    cJSON *item = cJSON_CreateObject();

    // trial_request->email
    if (!trial_request->email) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "email", trial_request->email) == NULL) {
    goto fail; //String
    }


    // trial_request->name
    if(trial_request->name) {
    if(cJSON_AddStringToObject(item, "name", trial_request->name) == NULL) {
    goto fail; //String
    }
    }


    // trial_request->billing_type
    if(trial_request->billing_type) {
    if(cJSON_AddStringToObject(item, "billingType", trial_request->billing_type) == NULL) {
    goto fail; //String
    }
    }


    // trial_request->billing_id
    if(trial_request->billing_id) {
    if(cJSON_AddStringToObject(item, "billingId", trial_request->billing_id) == NULL) {
    goto fail; //String
    }
    }


    // trial_request->code
    if(trial_request->code) {
    if(cJSON_AddStringToObject(item, "code", trial_request->code) == NULL) {
    goto fail; //String
    }
    }


    // trial_request->enterprise
    if (!trial_request->enterprise) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "enterprise", trial_request->enterprise) == NULL) {
    goto fail; //Bool
    }


    // trial_request->granted
    if(trial_request->granted) {
    if(cJSON_AddBoolToObject(item, "granted", trial_request->granted) == NULL) {
    goto fail; //Bool
    }
    }


    // trial_request->phone
    if(trial_request->phone) {
    if(cJSON_AddStringToObject(item, "phone", trial_request->phone) == NULL) {
    goto fail; //String
    }
    }


    // trial_request->country
    if(trial_request->country) {
    if(cJSON_AddStringToObject(item, "country", trial_request->country) == NULL) {
    goto fail; //String
    }
    }


    // trial_request->organization
    if(trial_request->organization) {
    if(cJSON_AddStringToObject(item, "organization", trial_request->organization) == NULL) {
    goto fail; //String
    }
    }


    // trial_request->organization_type
    if(trial_request->organization_type) {
    if(cJSON_AddStringToObject(item, "organizationType", trial_request->organization_type) == NULL) {
    goto fail; //String
    }
    }


    // trial_request->metadata
    if(trial_request->metadata) {
    cJSON *metadata_object = object_convertToJSON(trial_request->metadata);
    if(metadata_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // trial_request->created_at
    if (!trial_request->created_at) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "createdAt", trial_request->created_at) == NULL) {
    goto fail; //Numeric
    }


    // trial_request->updated_at
    if (!trial_request->updated_at) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "updatedAt", trial_request->updated_at) == NULL) {
    goto fail; //Numeric
    }


    // trial_request->display_status
    if (!trial_request->display_status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "displayStatus", trial_request->display_status) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

trial_request_t *trial_request_parseFromJSON(cJSON *trial_requestJSON){

    trial_request_t *trial_request_local_var = NULL;

    // trial_request->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(trial_requestJSON, "email");
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

    // trial_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(trial_requestJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // trial_request->billing_type
    cJSON *billing_type = cJSON_GetObjectItemCaseSensitive(trial_requestJSON, "billingType");
    if (cJSON_IsNull(billing_type)) {
        billing_type = NULL;
    }
    if (billing_type) { 
    if(!cJSON_IsString(billing_type) && !cJSON_IsNull(billing_type))
    {
    goto end; //String
    }
    }

    // trial_request->billing_id
    cJSON *billing_id = cJSON_GetObjectItemCaseSensitive(trial_requestJSON, "billingId");
    if (cJSON_IsNull(billing_id)) {
        billing_id = NULL;
    }
    if (billing_id) { 
    if(!cJSON_IsString(billing_id) && !cJSON_IsNull(billing_id))
    {
    goto end; //String
    }
    }

    // trial_request->code
    cJSON *code = cJSON_GetObjectItemCaseSensitive(trial_requestJSON, "code");
    if (cJSON_IsNull(code)) {
        code = NULL;
    }
    if (code) { 
    if(!cJSON_IsString(code) && !cJSON_IsNull(code))
    {
    goto end; //String
    }
    }

    // trial_request->enterprise
    cJSON *enterprise = cJSON_GetObjectItemCaseSensitive(trial_requestJSON, "enterprise");
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

    // trial_request->granted
    cJSON *granted = cJSON_GetObjectItemCaseSensitive(trial_requestJSON, "granted");
    if (cJSON_IsNull(granted)) {
        granted = NULL;
    }
    if (granted) { 
    if(!cJSON_IsBool(granted))
    {
    goto end; //Bool
    }
    }

    // trial_request->phone
    cJSON *phone = cJSON_GetObjectItemCaseSensitive(trial_requestJSON, "phone");
    if (cJSON_IsNull(phone)) {
        phone = NULL;
    }
    if (phone) { 
    if(!cJSON_IsString(phone) && !cJSON_IsNull(phone))
    {
    goto end; //String
    }
    }

    // trial_request->country
    cJSON *country = cJSON_GetObjectItemCaseSensitive(trial_requestJSON, "country");
    if (cJSON_IsNull(country)) {
        country = NULL;
    }
    if (country) { 
    if(!cJSON_IsString(country) && !cJSON_IsNull(country))
    {
    goto end; //String
    }
    }

    // trial_request->organization
    cJSON *organization = cJSON_GetObjectItemCaseSensitive(trial_requestJSON, "organization");
    if (cJSON_IsNull(organization)) {
        organization = NULL;
    }
    if (organization) { 
    if(!cJSON_IsString(organization) && !cJSON_IsNull(organization))
    {
    goto end; //String
    }
    }

    // trial_request->organization_type
    cJSON *organization_type = cJSON_GetObjectItemCaseSensitive(trial_requestJSON, "organizationType");
    if (cJSON_IsNull(organization_type)) {
        organization_type = NULL;
    }
    if (organization_type) { 
    if(!cJSON_IsString(organization_type) && !cJSON_IsNull(organization_type))
    {
    goto end; //String
    }
    }

    // trial_request->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(trial_requestJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    object_t *metadata_local_object = NULL;
    if (metadata) { 
    metadata_local_object = object_parseFromJSON(metadata); //object
    }

    // trial_request->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(trial_requestJSON, "createdAt");
    if (cJSON_IsNull(created_at)) {
        created_at = NULL;
    }
    if (!created_at) {
        goto end;
    }

    
    if(!cJSON_IsNumber(created_at))
    {
    goto end; //Numeric
    }

    // trial_request->updated_at
    cJSON *updated_at = cJSON_GetObjectItemCaseSensitive(trial_requestJSON, "updatedAt");
    if (cJSON_IsNull(updated_at)) {
        updated_at = NULL;
    }
    if (!updated_at) {
        goto end;
    }

    
    if(!cJSON_IsNumber(updated_at))
    {
    goto end; //Numeric
    }

    // trial_request->display_status
    cJSON *display_status = cJSON_GetObjectItemCaseSensitive(trial_requestJSON, "displayStatus");
    if (cJSON_IsNull(display_status)) {
        display_status = NULL;
    }
    if (!display_status) {
        goto end;
    }

    
    if(!cJSON_IsString(display_status))
    {
    goto end; //String
    }


    trial_request_local_var = trial_request_create_internal (
        strdup(email->valuestring),
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        billing_type && !cJSON_IsNull(billing_type) ? strdup(billing_type->valuestring) : NULL,
        billing_id && !cJSON_IsNull(billing_id) ? strdup(billing_id->valuestring) : NULL,
        code && !cJSON_IsNull(code) ? strdup(code->valuestring) : NULL,
        enterprise->valueint,
        granted ? granted->valueint : 0,
        phone && !cJSON_IsNull(phone) ? strdup(phone->valuestring) : NULL,
        country && !cJSON_IsNull(country) ? strdup(country->valuestring) : NULL,
        organization && !cJSON_IsNull(organization) ? strdup(organization->valuestring) : NULL,
        organization_type && !cJSON_IsNull(organization_type) ? strdup(organization_type->valuestring) : NULL,
        metadata ? metadata_local_object : NULL,
        created_at->valuedouble,
        updated_at->valuedouble,
        strdup(display_status->valuestring)
        );

    return trial_request_local_var;
end:
    return NULL;

}
