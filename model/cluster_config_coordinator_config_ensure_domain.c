#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_config_coordinator_config_ensure_domain.h"



static cluster_config_coordinator_config_ensure_domain_t *cluster_config_coordinator_config_ensure_domain_create_internal(
    char *domain,
    char *domain_name,
    cluster_config_coordinator_config_ensure_domain_quotas_t *quotas,
    cluster_config_coordinator_config_ensure_domain_properties_t *properties,
    char *admin_password_hash,
    int admin_user_cloud_administrator,
    int is_individual_aggregate
    ) {
    cluster_config_coordinator_config_ensure_domain_t *cluster_config_coordinator_config_ensure_domain_local_var = malloc(sizeof(cluster_config_coordinator_config_ensure_domain_t));
    if (!cluster_config_coordinator_config_ensure_domain_local_var) {
        return NULL;
    }
    cluster_config_coordinator_config_ensure_domain_local_var->domain = domain;
    cluster_config_coordinator_config_ensure_domain_local_var->domain_name = domain_name;
    cluster_config_coordinator_config_ensure_domain_local_var->quotas = quotas;
    cluster_config_coordinator_config_ensure_domain_local_var->properties = properties;
    cluster_config_coordinator_config_ensure_domain_local_var->admin_password_hash = admin_password_hash;
    cluster_config_coordinator_config_ensure_domain_local_var->admin_user_cloud_administrator = admin_user_cloud_administrator;
    cluster_config_coordinator_config_ensure_domain_local_var->is_individual_aggregate = is_individual_aggregate;

    cluster_config_coordinator_config_ensure_domain_local_var->_library_owned = 1;
    return cluster_config_coordinator_config_ensure_domain_local_var;
}

__attribute__((deprecated)) cluster_config_coordinator_config_ensure_domain_t *cluster_config_coordinator_config_ensure_domain_create(
    char *domain,
    char *domain_name,
    cluster_config_coordinator_config_ensure_domain_quotas_t *quotas,
    cluster_config_coordinator_config_ensure_domain_properties_t *properties,
    char *admin_password_hash,
    int admin_user_cloud_administrator,
    int is_individual_aggregate
    ) {
    return cluster_config_coordinator_config_ensure_domain_create_internal (
        domain,
        domain_name,
        quotas,
        properties,
        admin_password_hash,
        admin_user_cloud_administrator,
        is_individual_aggregate
        );
}

void cluster_config_coordinator_config_ensure_domain_free(cluster_config_coordinator_config_ensure_domain_t *cluster_config_coordinator_config_ensure_domain) {
    if(NULL == cluster_config_coordinator_config_ensure_domain){
        return ;
    }
    if(cluster_config_coordinator_config_ensure_domain->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_config_coordinator_config_ensure_domain_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cluster_config_coordinator_config_ensure_domain->domain) {
        free(cluster_config_coordinator_config_ensure_domain->domain);
        cluster_config_coordinator_config_ensure_domain->domain = NULL;
    }
    if (cluster_config_coordinator_config_ensure_domain->domain_name) {
        free(cluster_config_coordinator_config_ensure_domain->domain_name);
        cluster_config_coordinator_config_ensure_domain->domain_name = NULL;
    }
    if (cluster_config_coordinator_config_ensure_domain->quotas) {
        cluster_config_coordinator_config_ensure_domain_quotas_free(cluster_config_coordinator_config_ensure_domain->quotas);
        cluster_config_coordinator_config_ensure_domain->quotas = NULL;
    }
    if (cluster_config_coordinator_config_ensure_domain->properties) {
        cluster_config_coordinator_config_ensure_domain_properties_free(cluster_config_coordinator_config_ensure_domain->properties);
        cluster_config_coordinator_config_ensure_domain->properties = NULL;
    }
    if (cluster_config_coordinator_config_ensure_domain->admin_password_hash) {
        free(cluster_config_coordinator_config_ensure_domain->admin_password_hash);
        cluster_config_coordinator_config_ensure_domain->admin_password_hash = NULL;
    }
    free(cluster_config_coordinator_config_ensure_domain);
}

cJSON *cluster_config_coordinator_config_ensure_domain_convertToJSON(cluster_config_coordinator_config_ensure_domain_t *cluster_config_coordinator_config_ensure_domain) {
    cJSON *item = cJSON_CreateObject();

    // cluster_config_coordinator_config_ensure_domain->domain
    if (!cluster_config_coordinator_config_ensure_domain->domain) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "domain", cluster_config_coordinator_config_ensure_domain->domain) == NULL) {
    goto fail; //String
    }


    // cluster_config_coordinator_config_ensure_domain->domain_name
    if (!cluster_config_coordinator_config_ensure_domain->domain_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "domainName", cluster_config_coordinator_config_ensure_domain->domain_name) == NULL) {
    goto fail; //String
    }


    // cluster_config_coordinator_config_ensure_domain->quotas
    if (!cluster_config_coordinator_config_ensure_domain->quotas) {
        goto fail;
    }
    cJSON *quotas_local_JSON = cluster_config_coordinator_config_ensure_domain_quotas_convertToJSON(cluster_config_coordinator_config_ensure_domain->quotas);
    if(quotas_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "quotas", quotas_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // cluster_config_coordinator_config_ensure_domain->properties
    if (!cluster_config_coordinator_config_ensure_domain->properties) {
        goto fail;
    }
    cJSON *properties_local_JSON = cluster_config_coordinator_config_ensure_domain_properties_convertToJSON(cluster_config_coordinator_config_ensure_domain->properties);
    if(properties_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "properties", properties_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // cluster_config_coordinator_config_ensure_domain->admin_password_hash
    if (!cluster_config_coordinator_config_ensure_domain->admin_password_hash) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "adminPasswordHash", cluster_config_coordinator_config_ensure_domain->admin_password_hash) == NULL) {
    goto fail; //String
    }


    // cluster_config_coordinator_config_ensure_domain->admin_user_cloud_administrator
    if (!cluster_config_coordinator_config_ensure_domain->admin_user_cloud_administrator) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "adminUserCloudAdministrator", cluster_config_coordinator_config_ensure_domain->admin_user_cloud_administrator) == NULL) {
    goto fail; //Bool
    }


    // cluster_config_coordinator_config_ensure_domain->is_individual_aggregate
    if (!cluster_config_coordinator_config_ensure_domain->is_individual_aggregate) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "isIndividualAggregate", cluster_config_coordinator_config_ensure_domain->is_individual_aggregate) == NULL) {
    goto fail; //Bool
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

cluster_config_coordinator_config_ensure_domain_t *cluster_config_coordinator_config_ensure_domain_parseFromJSON(cJSON *cluster_config_coordinator_config_ensure_domainJSON){

    cluster_config_coordinator_config_ensure_domain_t *cluster_config_coordinator_config_ensure_domain_local_var = NULL;

    // define the local variable for cluster_config_coordinator_config_ensure_domain->quotas
    cluster_config_coordinator_config_ensure_domain_quotas_t *quotas_local_nonprim = NULL;

    // define the local variable for cluster_config_coordinator_config_ensure_domain->properties
    cluster_config_coordinator_config_ensure_domain_properties_t *properties_local_nonprim = NULL;

    // cluster_config_coordinator_config_ensure_domain->domain
    cJSON *domain = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_config_ensure_domainJSON, "domain");
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

    // cluster_config_coordinator_config_ensure_domain->domain_name
    cJSON *domain_name = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_config_ensure_domainJSON, "domainName");
    if (cJSON_IsNull(domain_name)) {
        domain_name = NULL;
    }
    if (!domain_name) {
        goto end;
    }

    
    if(!cJSON_IsString(domain_name))
    {
    goto end; //String
    }

    // cluster_config_coordinator_config_ensure_domain->quotas
    cJSON *quotas = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_config_ensure_domainJSON, "quotas");
    if (cJSON_IsNull(quotas)) {
        quotas = NULL;
    }
    if (!quotas) {
        goto end;
    }

    
    quotas_local_nonprim = cluster_config_coordinator_config_ensure_domain_quotas_parseFromJSON(quotas); //nonprimitive

    // cluster_config_coordinator_config_ensure_domain->properties
    cJSON *properties = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_config_ensure_domainJSON, "properties");
    if (cJSON_IsNull(properties)) {
        properties = NULL;
    }
    if (!properties) {
        goto end;
    }

    
    properties_local_nonprim = cluster_config_coordinator_config_ensure_domain_properties_parseFromJSON(properties); //nonprimitive

    // cluster_config_coordinator_config_ensure_domain->admin_password_hash
    cJSON *admin_password_hash = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_config_ensure_domainJSON, "adminPasswordHash");
    if (cJSON_IsNull(admin_password_hash)) {
        admin_password_hash = NULL;
    }
    if (!admin_password_hash) {
        goto end;
    }

    
    if(!cJSON_IsString(admin_password_hash))
    {
    goto end; //String
    }

    // cluster_config_coordinator_config_ensure_domain->admin_user_cloud_administrator
    cJSON *admin_user_cloud_administrator = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_config_ensure_domainJSON, "adminUserCloudAdministrator");
    if (cJSON_IsNull(admin_user_cloud_administrator)) {
        admin_user_cloud_administrator = NULL;
    }
    if (!admin_user_cloud_administrator) {
        goto end;
    }

    
    if(!cJSON_IsBool(admin_user_cloud_administrator))
    {
    goto end; //Bool
    }

    // cluster_config_coordinator_config_ensure_domain->is_individual_aggregate
    cJSON *is_individual_aggregate = cJSON_GetObjectItemCaseSensitive(cluster_config_coordinator_config_ensure_domainJSON, "isIndividualAggregate");
    if (cJSON_IsNull(is_individual_aggregate)) {
        is_individual_aggregate = NULL;
    }
    if (!is_individual_aggregate) {
        goto end;
    }

    
    if(!cJSON_IsBool(is_individual_aggregate))
    {
    goto end; //Bool
    }


    cluster_config_coordinator_config_ensure_domain_local_var = cluster_config_coordinator_config_ensure_domain_create_internal (
        strdup(domain->valuestring),
        strdup(domain_name->valuestring),
        quotas_local_nonprim,
        properties_local_nonprim,
        strdup(admin_password_hash->valuestring),
        admin_user_cloud_administrator->valueint,
        is_individual_aggregate->valueint
        );

    return cluster_config_coordinator_config_ensure_domain_local_var;
end:
    if (quotas_local_nonprim) {
        cluster_config_coordinator_config_ensure_domain_quotas_free(quotas_local_nonprim);
        quotas_local_nonprim = NULL;
    }
    if (properties_local_nonprim) {
        cluster_config_coordinator_config_ensure_domain_properties_free(properties_local_nonprim);
        properties_local_nonprim = NULL;
    }
    return NULL;

}
