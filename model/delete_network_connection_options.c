#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "delete_network_connection_options.h"



static delete_network_connection_options_t *delete_network_connection_options_create_internal(
    int force
    ) {
    delete_network_connection_options_t *delete_network_connection_options_local_var = malloc(sizeof(delete_network_connection_options_t));
    if (!delete_network_connection_options_local_var) {
        return NULL;
    }
    delete_network_connection_options_local_var->force = force;

    delete_network_connection_options_local_var->_library_owned = 1;
    return delete_network_connection_options_local_var;
}

__attribute__((deprecated)) delete_network_connection_options_t *delete_network_connection_options_create(
    int force
    ) {
    return delete_network_connection_options_create_internal (
        force
        );
}

void delete_network_connection_options_free(delete_network_connection_options_t *delete_network_connection_options) {
    if(NULL == delete_network_connection_options){
        return ;
    }
    if(delete_network_connection_options->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "delete_network_connection_options_free");
        return ;
    }
    listEntry_t *listEntry;
    free(delete_network_connection_options);
}

cJSON *delete_network_connection_options_convertToJSON(delete_network_connection_options_t *delete_network_connection_options) {
    cJSON *item = cJSON_CreateObject();

    // delete_network_connection_options->force
    if(delete_network_connection_options->force) {
    if(cJSON_AddBoolToObject(item, "force", delete_network_connection_options->force) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

delete_network_connection_options_t *delete_network_connection_options_parseFromJSON(cJSON *delete_network_connection_optionsJSON){

    delete_network_connection_options_t *delete_network_connection_options_local_var = NULL;

    // delete_network_connection_options->force
    cJSON *force = cJSON_GetObjectItemCaseSensitive(delete_network_connection_optionsJSON, "force");
    if (cJSON_IsNull(force)) {
        force = NULL;
    }
    if (force) { 
    if(!cJSON_IsBool(force))
    {
    goto end; //Bool
    }
    }


    delete_network_connection_options_local_var = delete_network_connection_options_create_internal (
        force ? force->valueint : 0
        );

    return delete_network_connection_options_local_var;
end:
    return NULL;

}
