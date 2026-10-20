#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_cloud_admin_trial_request_body.h"



static create_cloud_admin_trial_request_body_t *create_cloud_admin_trial_request_body_create_internal(
    char *email,
    char *name,
    char *phone,
    char *country,
    char *company,
    char *industry,
    char *role,
    char *solution,
    char *product_id,
    int granted,
    double number_of_apps,
    double team_size,
    int send_email,
    double duration
    ) {
    create_cloud_admin_trial_request_body_t *create_cloud_admin_trial_request_body_local_var = malloc(sizeof(create_cloud_admin_trial_request_body_t));
    if (!create_cloud_admin_trial_request_body_local_var) {
        return NULL;
    }
    create_cloud_admin_trial_request_body_local_var->email = email;
    create_cloud_admin_trial_request_body_local_var->name = name;
    create_cloud_admin_trial_request_body_local_var->phone = phone;
    create_cloud_admin_trial_request_body_local_var->country = country;
    create_cloud_admin_trial_request_body_local_var->company = company;
    create_cloud_admin_trial_request_body_local_var->industry = industry;
    create_cloud_admin_trial_request_body_local_var->role = role;
    create_cloud_admin_trial_request_body_local_var->solution = solution;
    create_cloud_admin_trial_request_body_local_var->product_id = product_id;
    create_cloud_admin_trial_request_body_local_var->granted = granted;
    create_cloud_admin_trial_request_body_local_var->number_of_apps = number_of_apps;
    create_cloud_admin_trial_request_body_local_var->team_size = team_size;
    create_cloud_admin_trial_request_body_local_var->send_email = send_email;
    create_cloud_admin_trial_request_body_local_var->duration = duration;

    create_cloud_admin_trial_request_body_local_var->_library_owned = 1;
    return create_cloud_admin_trial_request_body_local_var;
}

__attribute__((deprecated)) create_cloud_admin_trial_request_body_t *create_cloud_admin_trial_request_body_create(
    char *email,
    char *name,
    char *phone,
    char *country,
    char *company,
    char *industry,
    char *role,
    char *solution,
    char *product_id,
    int granted,
    double number_of_apps,
    double team_size,
    int send_email,
    double duration
    ) {
    return create_cloud_admin_trial_request_body_create_internal (
        email,
        name,
        phone,
        country,
        company,
        industry,
        role,
        solution,
        product_id,
        granted,
        number_of_apps,
        team_size,
        send_email,
        duration
        );
}

void create_cloud_admin_trial_request_body_free(create_cloud_admin_trial_request_body_t *create_cloud_admin_trial_request_body) {
    if(NULL == create_cloud_admin_trial_request_body){
        return ;
    }
    if(create_cloud_admin_trial_request_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_cloud_admin_trial_request_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (create_cloud_admin_trial_request_body->email) {
        free(create_cloud_admin_trial_request_body->email);
        create_cloud_admin_trial_request_body->email = NULL;
    }
    if (create_cloud_admin_trial_request_body->name) {
        free(create_cloud_admin_trial_request_body->name);
        create_cloud_admin_trial_request_body->name = NULL;
    }
    if (create_cloud_admin_trial_request_body->phone) {
        free(create_cloud_admin_trial_request_body->phone);
        create_cloud_admin_trial_request_body->phone = NULL;
    }
    if (create_cloud_admin_trial_request_body->country) {
        free(create_cloud_admin_trial_request_body->country);
        create_cloud_admin_trial_request_body->country = NULL;
    }
    if (create_cloud_admin_trial_request_body->company) {
        free(create_cloud_admin_trial_request_body->company);
        create_cloud_admin_trial_request_body->company = NULL;
    }
    if (create_cloud_admin_trial_request_body->industry) {
        free(create_cloud_admin_trial_request_body->industry);
        create_cloud_admin_trial_request_body->industry = NULL;
    }
    if (create_cloud_admin_trial_request_body->role) {
        free(create_cloud_admin_trial_request_body->role);
        create_cloud_admin_trial_request_body->role = NULL;
    }
    if (create_cloud_admin_trial_request_body->solution) {
        free(create_cloud_admin_trial_request_body->solution);
        create_cloud_admin_trial_request_body->solution = NULL;
    }
    if (create_cloud_admin_trial_request_body->product_id) {
        free(create_cloud_admin_trial_request_body->product_id);
        create_cloud_admin_trial_request_body->product_id = NULL;
    }
    free(create_cloud_admin_trial_request_body);
}

cJSON *create_cloud_admin_trial_request_body_convertToJSON(create_cloud_admin_trial_request_body_t *create_cloud_admin_trial_request_body) {
    cJSON *item = cJSON_CreateObject();

    // create_cloud_admin_trial_request_body->email
    if (!create_cloud_admin_trial_request_body->email) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "email", create_cloud_admin_trial_request_body->email) == NULL) {
    goto fail; //String
    }


    // create_cloud_admin_trial_request_body->name
    if (!create_cloud_admin_trial_request_body->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", create_cloud_admin_trial_request_body->name) == NULL) {
    goto fail; //String
    }


    // create_cloud_admin_trial_request_body->phone
    if (!create_cloud_admin_trial_request_body->phone) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "phone", create_cloud_admin_trial_request_body->phone) == NULL) {
    goto fail; //String
    }


    // create_cloud_admin_trial_request_body->country
    if (!create_cloud_admin_trial_request_body->country) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "country", create_cloud_admin_trial_request_body->country) == NULL) {
    goto fail; //String
    }


    // create_cloud_admin_trial_request_body->company
    if (!create_cloud_admin_trial_request_body->company) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "company", create_cloud_admin_trial_request_body->company) == NULL) {
    goto fail; //String
    }


    // create_cloud_admin_trial_request_body->industry
    if (!create_cloud_admin_trial_request_body->industry) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "industry", create_cloud_admin_trial_request_body->industry) == NULL) {
    goto fail; //String
    }


    // create_cloud_admin_trial_request_body->role
    if (!create_cloud_admin_trial_request_body->role) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "role", create_cloud_admin_trial_request_body->role) == NULL) {
    goto fail; //String
    }


    // create_cloud_admin_trial_request_body->solution
    if(create_cloud_admin_trial_request_body->solution) {
    if(cJSON_AddStringToObject(item, "solution", create_cloud_admin_trial_request_body->solution) == NULL) {
    goto fail; //String
    }
    }


    // create_cloud_admin_trial_request_body->product_id
    if (!create_cloud_admin_trial_request_body->product_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "productId", create_cloud_admin_trial_request_body->product_id) == NULL) {
    goto fail; //String
    }


    // create_cloud_admin_trial_request_body->granted
    if(create_cloud_admin_trial_request_body->granted) {
    if(cJSON_AddBoolToObject(item, "granted", create_cloud_admin_trial_request_body->granted) == NULL) {
    goto fail; //Bool
    }
    }


    // create_cloud_admin_trial_request_body->number_of_apps
    if(create_cloud_admin_trial_request_body->number_of_apps) {
    if(cJSON_AddNumberToObject(item, "numberOfApps", create_cloud_admin_trial_request_body->number_of_apps) == NULL) {
    goto fail; //Numeric
    }
    }


    // create_cloud_admin_trial_request_body->team_size
    if(create_cloud_admin_trial_request_body->team_size) {
    if(cJSON_AddNumberToObject(item, "teamSize", create_cloud_admin_trial_request_body->team_size) == NULL) {
    goto fail; //Numeric
    }
    }


    // create_cloud_admin_trial_request_body->send_email
    if(create_cloud_admin_trial_request_body->send_email) {
    if(cJSON_AddBoolToObject(item, "sendEmail", create_cloud_admin_trial_request_body->send_email) == NULL) {
    goto fail; //Bool
    }
    }


    // create_cloud_admin_trial_request_body->duration
    if(create_cloud_admin_trial_request_body->duration) {
    if(cJSON_AddNumberToObject(item, "duration", create_cloud_admin_trial_request_body->duration) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

create_cloud_admin_trial_request_body_t *create_cloud_admin_trial_request_body_parseFromJSON(cJSON *create_cloud_admin_trial_request_bodyJSON){

    create_cloud_admin_trial_request_body_t *create_cloud_admin_trial_request_body_local_var = NULL;

    // create_cloud_admin_trial_request_body->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(create_cloud_admin_trial_request_bodyJSON, "email");
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

    // create_cloud_admin_trial_request_body->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(create_cloud_admin_trial_request_bodyJSON, "name");
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

    // create_cloud_admin_trial_request_body->phone
    cJSON *phone = cJSON_GetObjectItemCaseSensitive(create_cloud_admin_trial_request_bodyJSON, "phone");
    if (cJSON_IsNull(phone)) {
        phone = NULL;
    }
    if (!phone) {
        goto end;
    }

    
    if(!cJSON_IsString(phone))
    {
    goto end; //String
    }

    // create_cloud_admin_trial_request_body->country
    cJSON *country = cJSON_GetObjectItemCaseSensitive(create_cloud_admin_trial_request_bodyJSON, "country");
    if (cJSON_IsNull(country)) {
        country = NULL;
    }
    if (!country) {
        goto end;
    }

    
    if(!cJSON_IsString(country))
    {
    goto end; //String
    }

    // create_cloud_admin_trial_request_body->company
    cJSON *company = cJSON_GetObjectItemCaseSensitive(create_cloud_admin_trial_request_bodyJSON, "company");
    if (cJSON_IsNull(company)) {
        company = NULL;
    }
    if (!company) {
        goto end;
    }

    
    if(!cJSON_IsString(company))
    {
    goto end; //String
    }

    // create_cloud_admin_trial_request_body->industry
    cJSON *industry = cJSON_GetObjectItemCaseSensitive(create_cloud_admin_trial_request_bodyJSON, "industry");
    if (cJSON_IsNull(industry)) {
        industry = NULL;
    }
    if (!industry) {
        goto end;
    }

    
    if(!cJSON_IsString(industry))
    {
    goto end; //String
    }

    // create_cloud_admin_trial_request_body->role
    cJSON *role = cJSON_GetObjectItemCaseSensitive(create_cloud_admin_trial_request_bodyJSON, "role");
    if (cJSON_IsNull(role)) {
        role = NULL;
    }
    if (!role) {
        goto end;
    }

    
    if(!cJSON_IsString(role))
    {
    goto end; //String
    }

    // create_cloud_admin_trial_request_body->solution
    cJSON *solution = cJSON_GetObjectItemCaseSensitive(create_cloud_admin_trial_request_bodyJSON, "solution");
    if (cJSON_IsNull(solution)) {
        solution = NULL;
    }
    if (solution) { 
    if(!cJSON_IsString(solution) && !cJSON_IsNull(solution))
    {
    goto end; //String
    }
    }

    // create_cloud_admin_trial_request_body->product_id
    cJSON *product_id = cJSON_GetObjectItemCaseSensitive(create_cloud_admin_trial_request_bodyJSON, "productId");
    if (cJSON_IsNull(product_id)) {
        product_id = NULL;
    }
    if (!product_id) {
        goto end;
    }

    
    if(!cJSON_IsString(product_id))
    {
    goto end; //String
    }

    // create_cloud_admin_trial_request_body->granted
    cJSON *granted = cJSON_GetObjectItemCaseSensitive(create_cloud_admin_trial_request_bodyJSON, "granted");
    if (cJSON_IsNull(granted)) {
        granted = NULL;
    }
    if (granted) { 
    if(!cJSON_IsBool(granted))
    {
    goto end; //Bool
    }
    }

    // create_cloud_admin_trial_request_body->number_of_apps
    cJSON *number_of_apps = cJSON_GetObjectItemCaseSensitive(create_cloud_admin_trial_request_bodyJSON, "numberOfApps");
    if (cJSON_IsNull(number_of_apps)) {
        number_of_apps = NULL;
    }
    if (number_of_apps) { 
    if(!cJSON_IsNumber(number_of_apps))
    {
    goto end; //Numeric
    }
    }

    // create_cloud_admin_trial_request_body->team_size
    cJSON *team_size = cJSON_GetObjectItemCaseSensitive(create_cloud_admin_trial_request_bodyJSON, "teamSize");
    if (cJSON_IsNull(team_size)) {
        team_size = NULL;
    }
    if (team_size) { 
    if(!cJSON_IsNumber(team_size))
    {
    goto end; //Numeric
    }
    }

    // create_cloud_admin_trial_request_body->send_email
    cJSON *send_email = cJSON_GetObjectItemCaseSensitive(create_cloud_admin_trial_request_bodyJSON, "sendEmail");
    if (cJSON_IsNull(send_email)) {
        send_email = NULL;
    }
    if (send_email) { 
    if(!cJSON_IsBool(send_email))
    {
    goto end; //Bool
    }
    }

    // create_cloud_admin_trial_request_body->duration
    cJSON *duration = cJSON_GetObjectItemCaseSensitive(create_cloud_admin_trial_request_bodyJSON, "duration");
    if (cJSON_IsNull(duration)) {
        duration = NULL;
    }
    if (duration) { 
    if(!cJSON_IsNumber(duration))
    {
    goto end; //Numeric
    }
    }


    create_cloud_admin_trial_request_body_local_var = create_cloud_admin_trial_request_body_create_internal (
        strdup(email->valuestring),
        strdup(name->valuestring),
        strdup(phone->valuestring),
        strdup(country->valuestring),
        strdup(company->valuestring),
        strdup(industry->valuestring),
        strdup(role->valuestring),
        solution && !cJSON_IsNull(solution) ? strdup(solution->valuestring) : NULL,
        strdup(product_id->valuestring),
        granted ? granted->valueint : 0,
        number_of_apps ? number_of_apps->valuedouble : 0,
        team_size ? team_size->valuedouble : 0,
        send_email ? send_email->valueint : 0,
        duration ? duration->valuedouble : 0
        );

    return create_cloud_admin_trial_request_body_local_var;
end:
    return NULL;

}
