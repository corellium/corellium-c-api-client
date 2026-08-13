#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "trial_request_detail_organization.h"



static trial_request_detail_organization_t *trial_request_detail_organization_create_internal(
    char *name,
    char *country
    ) {
    trial_request_detail_organization_t *trial_request_detail_organization_local_var = malloc(sizeof(trial_request_detail_organization_t));
    if (!trial_request_detail_organization_local_var) {
        return NULL;
    }
    trial_request_detail_organization_local_var->name = name;
    trial_request_detail_organization_local_var->country = country;

    trial_request_detail_organization_local_var->_library_owned = 1;
    return trial_request_detail_organization_local_var;
}

__attribute__((deprecated)) trial_request_detail_organization_t *trial_request_detail_organization_create(
    char *name,
    char *country
    ) {
    return trial_request_detail_organization_create_internal (
        name,
        country
        );
}

void trial_request_detail_organization_free(trial_request_detail_organization_t *trial_request_detail_organization) {
    if(NULL == trial_request_detail_organization){
        return ;
    }
    if(trial_request_detail_organization->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "trial_request_detail_organization_free");
        return ;
    }
    listEntry_t *listEntry;
    if (trial_request_detail_organization->name) {
        free(trial_request_detail_organization->name);
        trial_request_detail_organization->name = NULL;
    }
    if (trial_request_detail_organization->country) {
        free(trial_request_detail_organization->country);
        trial_request_detail_organization->country = NULL;
    }
    free(trial_request_detail_organization);
}

cJSON *trial_request_detail_organization_convertToJSON(trial_request_detail_organization_t *trial_request_detail_organization) {
    cJSON *item = cJSON_CreateObject();

    // trial_request_detail_organization->name
    if(trial_request_detail_organization->name) {
    if(cJSON_AddStringToObject(item, "name", trial_request_detail_organization->name) == NULL) {
    goto fail; //String
    }
    }


    // trial_request_detail_organization->country
    if(trial_request_detail_organization->country) {
    if(cJSON_AddStringToObject(item, "country", trial_request_detail_organization->country) == NULL) {
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

trial_request_detail_organization_t *trial_request_detail_organization_parseFromJSON(cJSON *trial_request_detail_organizationJSON){

    trial_request_detail_organization_t *trial_request_detail_organization_local_var = NULL;

    // trial_request_detail_organization->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(trial_request_detail_organizationJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // trial_request_detail_organization->country
    cJSON *country = cJSON_GetObjectItemCaseSensitive(trial_request_detail_organizationJSON, "country");
    if (cJSON_IsNull(country)) {
        country = NULL;
    }
    if (country) { 
    if(!cJSON_IsString(country) && !cJSON_IsNull(country))
    {
    goto end; //String
    }
    }


    trial_request_detail_organization_local_var = trial_request_detail_organization_create_internal (
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        country && !cJSON_IsNull(country) ? strdup(country->valuestring) : NULL
        );

    return trial_request_detail_organization_local_var;
end:
    return NULL;

}
