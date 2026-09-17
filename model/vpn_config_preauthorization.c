#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "vpn_config_preauthorization.h"



static vpn_config_preauthorization_t *vpn_config_preauthorization_create_internal(
    char *token
    ) {
    vpn_config_preauthorization_t *vpn_config_preauthorization_local_var = malloc(sizeof(vpn_config_preauthorization_t));
    if (!vpn_config_preauthorization_local_var) {
        return NULL;
    }
    vpn_config_preauthorization_local_var->token = token;

    vpn_config_preauthorization_local_var->_library_owned = 1;
    return vpn_config_preauthorization_local_var;
}

__attribute__((deprecated)) vpn_config_preauthorization_t *vpn_config_preauthorization_create(
    char *token
    ) {
    return vpn_config_preauthorization_create_internal (
        token
        );
}

void vpn_config_preauthorization_free(vpn_config_preauthorization_t *vpn_config_preauthorization) {
    if(NULL == vpn_config_preauthorization){
        return ;
    }
    if(vpn_config_preauthorization->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "vpn_config_preauthorization_free");
        return ;
    }
    listEntry_t *listEntry;
    if (vpn_config_preauthorization->token) {
        free(vpn_config_preauthorization->token);
        vpn_config_preauthorization->token = NULL;
    }
    free(vpn_config_preauthorization);
}

cJSON *vpn_config_preauthorization_convertToJSON(vpn_config_preauthorization_t *vpn_config_preauthorization) {
    cJSON *item = cJSON_CreateObject();

    // vpn_config_preauthorization->token
    if (!vpn_config_preauthorization->token) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "token", vpn_config_preauthorization->token) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

vpn_config_preauthorization_t *vpn_config_preauthorization_parseFromJSON(cJSON *vpn_config_preauthorizationJSON){

    vpn_config_preauthorization_t *vpn_config_preauthorization_local_var = NULL;

    // vpn_config_preauthorization->token
    cJSON *token = cJSON_GetObjectItemCaseSensitive(vpn_config_preauthorizationJSON, "token");
    if (cJSON_IsNull(token)) {
        token = NULL;
    }
    if (!token) {
        goto end;
    }

    
    if(!cJSON_IsString(token))
    {
    goto end; //String
    }


    vpn_config_preauthorization_local_var = vpn_config_preauthorization_create_internal (
        strdup(token->valuestring)
        );

    return vpn_config_preauthorization_local_var;
end:
    return NULL;

}
