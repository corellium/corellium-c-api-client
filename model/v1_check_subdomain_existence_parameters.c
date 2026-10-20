#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_check_subdomain_existence_parameters.h"



static v1_check_subdomain_existence_parameters_t *v1_check_subdomain_existence_parameters_create_internal(
    char *domain
    ) {
    v1_check_subdomain_existence_parameters_t *v1_check_subdomain_existence_parameters_local_var = malloc(sizeof(v1_check_subdomain_existence_parameters_t));
    if (!v1_check_subdomain_existence_parameters_local_var) {
        return NULL;
    }
    v1_check_subdomain_existence_parameters_local_var->domain = domain;

    v1_check_subdomain_existence_parameters_local_var->_library_owned = 1;
    return v1_check_subdomain_existence_parameters_local_var;
}

__attribute__((deprecated)) v1_check_subdomain_existence_parameters_t *v1_check_subdomain_existence_parameters_create(
    char *domain
    ) {
    return v1_check_subdomain_existence_parameters_create_internal (
        domain
        );
}

void v1_check_subdomain_existence_parameters_free(v1_check_subdomain_existence_parameters_t *v1_check_subdomain_existence_parameters) {
    if(NULL == v1_check_subdomain_existence_parameters){
        return ;
    }
    if(v1_check_subdomain_existence_parameters->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_check_subdomain_existence_parameters_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_check_subdomain_existence_parameters->domain) {
        free(v1_check_subdomain_existence_parameters->domain);
        v1_check_subdomain_existence_parameters->domain = NULL;
    }
    free(v1_check_subdomain_existence_parameters);
}

cJSON *v1_check_subdomain_existence_parameters_convertToJSON(v1_check_subdomain_existence_parameters_t *v1_check_subdomain_existence_parameters) {
    cJSON *item = cJSON_CreateObject();

    // v1_check_subdomain_existence_parameters->domain
    if (!v1_check_subdomain_existence_parameters->domain) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "domain", v1_check_subdomain_existence_parameters->domain) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_check_subdomain_existence_parameters_t *v1_check_subdomain_existence_parameters_parseFromJSON(cJSON *v1_check_subdomain_existence_parametersJSON){

    v1_check_subdomain_existence_parameters_t *v1_check_subdomain_existence_parameters_local_var = NULL;

    // v1_check_subdomain_existence_parameters->domain
    cJSON *domain = cJSON_GetObjectItemCaseSensitive(v1_check_subdomain_existence_parametersJSON, "domain");
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


    v1_check_subdomain_existence_parameters_local_var = v1_check_subdomain_existence_parameters_create_internal (
        strdup(domain->valuestring)
        );

    return v1_check_subdomain_existence_parameters_local_var;
end:
    return NULL;

}
