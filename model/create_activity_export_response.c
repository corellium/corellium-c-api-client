#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_activity_export_response.h"



static create_activity_export_response_t *create_activity_export_response_create_internal(
    char *id
    ) {
    create_activity_export_response_t *create_activity_export_response_local_var = malloc(sizeof(create_activity_export_response_t));
    if (!create_activity_export_response_local_var) {
        return NULL;
    }
    create_activity_export_response_local_var->id = id;

    create_activity_export_response_local_var->_library_owned = 1;
    return create_activity_export_response_local_var;
}

__attribute__((deprecated)) create_activity_export_response_t *create_activity_export_response_create(
    char *id
    ) {
    return create_activity_export_response_create_internal (
        id
        );
}

void create_activity_export_response_free(create_activity_export_response_t *create_activity_export_response) {
    if(NULL == create_activity_export_response){
        return ;
    }
    if(create_activity_export_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_activity_export_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (create_activity_export_response->id) {
        free(create_activity_export_response->id);
        create_activity_export_response->id = NULL;
    }
    free(create_activity_export_response);
}

cJSON *create_activity_export_response_convertToJSON(create_activity_export_response_t *create_activity_export_response) {
    cJSON *item = cJSON_CreateObject();

    // create_activity_export_response->id
    if (!create_activity_export_response->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", create_activity_export_response->id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

create_activity_export_response_t *create_activity_export_response_parseFromJSON(cJSON *create_activity_export_responseJSON){

    create_activity_export_response_t *create_activity_export_response_local_var = NULL;

    // create_activity_export_response->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(create_activity_export_responseJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }


    create_activity_export_response_local_var = create_activity_export_response_create_internal (
        strdup(id->valuestring)
        );

    return create_activity_export_response_local_var;
end:
    return NULL;

}
