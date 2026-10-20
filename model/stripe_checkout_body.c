#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "stripe_checkout_body.h"



static stripe_checkout_body_t *stripe_checkout_body_create_internal(
    int terms_of_service,
    char *email,
    char *name,
    char *domain,
    double cores,
    char *license_type,
    int existing_domain,
    char *price_id,
    char *coupon_code
    ) {
    stripe_checkout_body_t *stripe_checkout_body_local_var = malloc(sizeof(stripe_checkout_body_t));
    if (!stripe_checkout_body_local_var) {
        return NULL;
    }
    stripe_checkout_body_local_var->terms_of_service = terms_of_service;
    stripe_checkout_body_local_var->email = email;
    stripe_checkout_body_local_var->name = name;
    stripe_checkout_body_local_var->domain = domain;
    stripe_checkout_body_local_var->cores = cores;
    stripe_checkout_body_local_var->license_type = license_type;
    stripe_checkout_body_local_var->existing_domain = existing_domain;
    stripe_checkout_body_local_var->price_id = price_id;
    stripe_checkout_body_local_var->coupon_code = coupon_code;

    stripe_checkout_body_local_var->_library_owned = 1;
    return stripe_checkout_body_local_var;
}

__attribute__((deprecated)) stripe_checkout_body_t *stripe_checkout_body_create(
    int terms_of_service,
    char *email,
    char *name,
    char *domain,
    double cores,
    char *license_type,
    int existing_domain,
    char *price_id,
    char *coupon_code
    ) {
    return stripe_checkout_body_create_internal (
        terms_of_service,
        email,
        name,
        domain,
        cores,
        license_type,
        existing_domain,
        price_id,
        coupon_code
        );
}

void stripe_checkout_body_free(stripe_checkout_body_t *stripe_checkout_body) {
    if(NULL == stripe_checkout_body){
        return ;
    }
    if(stripe_checkout_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "stripe_checkout_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (stripe_checkout_body->email) {
        free(stripe_checkout_body->email);
        stripe_checkout_body->email = NULL;
    }
    if (stripe_checkout_body->name) {
        free(stripe_checkout_body->name);
        stripe_checkout_body->name = NULL;
    }
    if (stripe_checkout_body->domain) {
        free(stripe_checkout_body->domain);
        stripe_checkout_body->domain = NULL;
    }
    if (stripe_checkout_body->license_type) {
        free(stripe_checkout_body->license_type);
        stripe_checkout_body->license_type = NULL;
    }
    if (stripe_checkout_body->price_id) {
        free(stripe_checkout_body->price_id);
        stripe_checkout_body->price_id = NULL;
    }
    if (stripe_checkout_body->coupon_code) {
        free(stripe_checkout_body->coupon_code);
        stripe_checkout_body->coupon_code = NULL;
    }
    free(stripe_checkout_body);
}

cJSON *stripe_checkout_body_convertToJSON(stripe_checkout_body_t *stripe_checkout_body) {
    cJSON *item = cJSON_CreateObject();

    // stripe_checkout_body->terms_of_service
    if (!stripe_checkout_body->terms_of_service) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "termsOfService", stripe_checkout_body->terms_of_service) == NULL) {
    goto fail; //Bool
    }


    // stripe_checkout_body->email
    if (!stripe_checkout_body->email) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "email", stripe_checkout_body->email) == NULL) {
    goto fail; //String
    }


    // stripe_checkout_body->name
    if (!stripe_checkout_body->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", stripe_checkout_body->name) == NULL) {
    goto fail; //String
    }


    // stripe_checkout_body->domain
    if (!stripe_checkout_body->domain) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "domain", stripe_checkout_body->domain) == NULL) {
    goto fail; //String
    }


    // stripe_checkout_body->cores
    if (!stripe_checkout_body->cores) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "cores", stripe_checkout_body->cores) == NULL) {
    goto fail; //Numeric
    }


    // stripe_checkout_body->license_type
    if (!stripe_checkout_body->license_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "licenseType", stripe_checkout_body->license_type) == NULL) {
    goto fail; //String
    }


    // stripe_checkout_body->existing_domain
    if (!stripe_checkout_body->existing_domain) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "existingDomain", stripe_checkout_body->existing_domain) == NULL) {
    goto fail; //Bool
    }


    // stripe_checkout_body->price_id
    if (!stripe_checkout_body->price_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "priceId", stripe_checkout_body->price_id) == NULL) {
    goto fail; //String
    }


    // stripe_checkout_body->coupon_code
    if(stripe_checkout_body->coupon_code) {
    if(cJSON_AddStringToObject(item, "couponCode", stripe_checkout_body->coupon_code) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

stripe_checkout_body_t *stripe_checkout_body_parseFromJSON(cJSON *stripe_checkout_bodyJSON){

    stripe_checkout_body_t *stripe_checkout_body_local_var = NULL;

    // stripe_checkout_body->terms_of_service
    cJSON *terms_of_service = cJSON_GetObjectItemCaseSensitive(stripe_checkout_bodyJSON, "termsOfService");
    if (cJSON_IsNull(terms_of_service)) {
        terms_of_service = NULL;
    }
    if (!terms_of_service) {
        goto end;
    }

    
    if(!cJSON_IsBool(terms_of_service))
    {
    goto end; //Bool
    }

    // stripe_checkout_body->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(stripe_checkout_bodyJSON, "email");
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

    // stripe_checkout_body->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(stripe_checkout_bodyJSON, "name");
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

    // stripe_checkout_body->domain
    cJSON *domain = cJSON_GetObjectItemCaseSensitive(stripe_checkout_bodyJSON, "domain");
    if (cJSON_IsNull(domain)) {
        domain = NULL;
    }
    if (!domain) {
        goto end;
    }

    
    if(!cJSON_IsString(domain))
    {
    goto end; //String
    }

    // stripe_checkout_body->cores
    cJSON *cores = cJSON_GetObjectItemCaseSensitive(stripe_checkout_bodyJSON, "cores");
    if (cJSON_IsNull(cores)) {
        cores = NULL;
    }
    if (!cores) {
        goto end;
    }

    
    if(!cJSON_IsNumber(cores))
    {
    goto end; //Numeric
    }

    // stripe_checkout_body->license_type
    cJSON *license_type = cJSON_GetObjectItemCaseSensitive(stripe_checkout_bodyJSON, "licenseType");
    if (cJSON_IsNull(license_type)) {
        license_type = NULL;
    }
    if (!license_type) {
        goto end;
    }

    
    if(!cJSON_IsString(license_type))
    {
    goto end; //String
    }

    // stripe_checkout_body->existing_domain
    cJSON *existing_domain = cJSON_GetObjectItemCaseSensitive(stripe_checkout_bodyJSON, "existingDomain");
    if (cJSON_IsNull(existing_domain)) {
        existing_domain = NULL;
    }
    if (!existing_domain) {
        goto end;
    }

    
    if(!cJSON_IsBool(existing_domain))
    {
    goto end; //Bool
    }

    // stripe_checkout_body->price_id
    cJSON *price_id = cJSON_GetObjectItemCaseSensitive(stripe_checkout_bodyJSON, "priceId");
    if (cJSON_IsNull(price_id)) {
        price_id = NULL;
    }
    if (!price_id) {
        goto end;
    }

    
    if(!cJSON_IsString(price_id))
    {
    goto end; //String
    }

    // stripe_checkout_body->coupon_code
    cJSON *coupon_code = cJSON_GetObjectItemCaseSensitive(stripe_checkout_bodyJSON, "couponCode");
    if (cJSON_IsNull(coupon_code)) {
        coupon_code = NULL;
    }
    if (coupon_code) { 
    if(!cJSON_IsString(coupon_code) && !cJSON_IsNull(coupon_code))
    {
    goto end; //String
    }
    }


    stripe_checkout_body_local_var = stripe_checkout_body_create_internal (
        terms_of_service->valueint,
        strdup(email->valuestring),
        strdup(name->valuestring),
        strdup(domain->valuestring),
        cores->valuedouble,
        strdup(license_type->valuestring),
        existing_domain->valueint,
        strdup(price_id->valuestring),
        coupon_code && !cJSON_IsNull(coupon_code) ? strdup(coupon_code->valuestring) : NULL
        );

    return stripe_checkout_body_local_var;
end:
    return NULL;

}
