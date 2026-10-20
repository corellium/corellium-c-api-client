#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_trial_request_body.h"


char* create_trial_request_body_type_ToString(corellium_api_create_trial_request_body_TYPE_e type) {
    char* typeArray[] =  { "NULL", "individual", "enterprise" };
    return typeArray[type];
}

corellium_api_create_trial_request_body_TYPE_e create_trial_request_body_type_FromString(char* type){
    int stringToReturn = 0;
    char *typeArray[] =  { "NULL", "individual", "enterprise" };
    size_t sizeofArray = sizeof(typeArray) / sizeof(typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(type, typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static create_trial_request_body_t *create_trial_request_body_create_internal(
    char *email,
    char *name,
    char *phone,
    char *country,
    corellium_api_create_trial_request_body_TYPE_e type,
    char *company,
    char *industry,
    char *role,
    char *solution,
    char *product_id
    ) {
    create_trial_request_body_t *create_trial_request_body_local_var = malloc(sizeof(create_trial_request_body_t));
    if (!create_trial_request_body_local_var) {
        return NULL;
    }
    create_trial_request_body_local_var->email = email;
    create_trial_request_body_local_var->name = name;
    create_trial_request_body_local_var->phone = phone;
    create_trial_request_body_local_var->country = country;
    create_trial_request_body_local_var->type = type;
    create_trial_request_body_local_var->company = company;
    create_trial_request_body_local_var->industry = industry;
    create_trial_request_body_local_var->role = role;
    create_trial_request_body_local_var->solution = solution;
    create_trial_request_body_local_var->product_id = product_id;

    create_trial_request_body_local_var->_library_owned = 1;
    return create_trial_request_body_local_var;
}

__attribute__((deprecated)) create_trial_request_body_t *create_trial_request_body_create(
    char *email,
    char *name,
    char *phone,
    char *country,
    corellium_api_create_trial_request_body_TYPE_e type,
    char *company,
    char *industry,
    char *role,
    char *solution,
    char *product_id
    ) {
    return create_trial_request_body_create_internal (
        email,
        name,
        phone,
        country,
        type,
        company,
        industry,
        role,
        solution,
        product_id
        );
}

void create_trial_request_body_free(create_trial_request_body_t *create_trial_request_body) {
    if(NULL == create_trial_request_body){
        return ;
    }
    if(create_trial_request_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_trial_request_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (create_trial_request_body->email) {
        free(create_trial_request_body->email);
        create_trial_request_body->email = NULL;
    }
    if (create_trial_request_body->name) {
        free(create_trial_request_body->name);
        create_trial_request_body->name = NULL;
    }
    if (create_trial_request_body->phone) {
        free(create_trial_request_body->phone);
        create_trial_request_body->phone = NULL;
    }
    if (create_trial_request_body->country) {
        free(create_trial_request_body->country);
        create_trial_request_body->country = NULL;
    }
    if (create_trial_request_body->company) {
        free(create_trial_request_body->company);
        create_trial_request_body->company = NULL;
    }
    if (create_trial_request_body->industry) {
        free(create_trial_request_body->industry);
        create_trial_request_body->industry = NULL;
    }
    if (create_trial_request_body->role) {
        free(create_trial_request_body->role);
        create_trial_request_body->role = NULL;
    }
    if (create_trial_request_body->solution) {
        free(create_trial_request_body->solution);
        create_trial_request_body->solution = NULL;
    }
    if (create_trial_request_body->product_id) {
        free(create_trial_request_body->product_id);
        create_trial_request_body->product_id = NULL;
    }
    free(create_trial_request_body);
}

cJSON *create_trial_request_body_convertToJSON(create_trial_request_body_t *create_trial_request_body) {
    cJSON *item = cJSON_CreateObject();

    // create_trial_request_body->email
    if (!create_trial_request_body->email) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "email", create_trial_request_body->email) == NULL) {
    goto fail; //String
    }


    // create_trial_request_body->name
    if (!create_trial_request_body->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", create_trial_request_body->name) == NULL) {
    goto fail; //String
    }


    // create_trial_request_body->phone
    if (!create_trial_request_body->phone) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "phone", create_trial_request_body->phone) == NULL) {
    goto fail; //String
    }


    // create_trial_request_body->country
    if (!create_trial_request_body->country) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "country", create_trial_request_body->country) == NULL) {
    goto fail; //String
    }


    // create_trial_request_body->type
    if (corellium_api_create_trial_request_body_TYPE_NULL == create_trial_request_body->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", create_trial_request_body_type_ToString(create_trial_request_body->type)) == NULL)
    {
    goto fail; //Enum
    }


    // create_trial_request_body->company
    if (!create_trial_request_body->company) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "company", create_trial_request_body->company) == NULL) {
    goto fail; //String
    }


    // create_trial_request_body->industry
    if (!create_trial_request_body->industry) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "industry", create_trial_request_body->industry) == NULL) {
    goto fail; //String
    }


    // create_trial_request_body->role
    if (!create_trial_request_body->role) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "role", create_trial_request_body->role) == NULL) {
    goto fail; //String
    }


    // create_trial_request_body->solution
    if (!create_trial_request_body->solution) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "solution", create_trial_request_body->solution) == NULL) {
    goto fail; //String
    }


    // create_trial_request_body->product_id
    if (!create_trial_request_body->product_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "productId", create_trial_request_body->product_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

create_trial_request_body_t *create_trial_request_body_parseFromJSON(cJSON *create_trial_request_bodyJSON){

    create_trial_request_body_t *create_trial_request_body_local_var = NULL;

    // create_trial_request_body->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(create_trial_request_bodyJSON, "email");
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

    // create_trial_request_body->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(create_trial_request_bodyJSON, "name");
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

    // create_trial_request_body->phone
    cJSON *phone = cJSON_GetObjectItemCaseSensitive(create_trial_request_bodyJSON, "phone");
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

    // create_trial_request_body->country
    cJSON *country = cJSON_GetObjectItemCaseSensitive(create_trial_request_bodyJSON, "country");
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

    // create_trial_request_body->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(create_trial_request_bodyJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    corellium_api_create_trial_request_body_TYPE_e typeVariable;
    
    if(!cJSON_IsString(type))
    {
    goto end; //Enum
    }
    typeVariable = create_trial_request_body_type_FromString(type->valuestring);

    // create_trial_request_body->company
    cJSON *company = cJSON_GetObjectItemCaseSensitive(create_trial_request_bodyJSON, "company");
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

    // create_trial_request_body->industry
    cJSON *industry = cJSON_GetObjectItemCaseSensitive(create_trial_request_bodyJSON, "industry");
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

    // create_trial_request_body->role
    cJSON *role = cJSON_GetObjectItemCaseSensitive(create_trial_request_bodyJSON, "role");
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

    // create_trial_request_body->solution
    cJSON *solution = cJSON_GetObjectItemCaseSensitive(create_trial_request_bodyJSON, "solution");
    if (cJSON_IsNull(solution)) {
        solution = NULL;
    }
    if (!solution) {
        goto end;
    }

    
    if(!cJSON_IsString(solution))
    {
    goto end; //String
    }

    // create_trial_request_body->product_id
    cJSON *product_id = cJSON_GetObjectItemCaseSensitive(create_trial_request_bodyJSON, "productId");
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


    create_trial_request_body_local_var = create_trial_request_body_create_internal (
        strdup(email->valuestring),
        strdup(name->valuestring),
        strdup(phone->valuestring),
        strdup(country->valuestring),
        typeVariable,
        strdup(company->valuestring),
        strdup(industry->valuestring),
        strdup(role->valuestring),
        strdup(solution->valuestring),
        strdup(product_id->valuestring)
        );

    return create_trial_request_body_local_var;
end:
    return NULL;

}
