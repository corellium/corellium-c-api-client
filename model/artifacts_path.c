#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "artifacts_path.h"



static artifacts_path_t *artifacts_path_create_internal(
    char *path
    ) {
    artifacts_path_t *artifacts_path_local_var = malloc(sizeof(artifacts_path_t));
    if (!artifacts_path_local_var) {
        return NULL;
    }
    artifacts_path_local_var->path = path;

    artifacts_path_local_var->_library_owned = 1;
    return artifacts_path_local_var;
}

__attribute__((deprecated)) artifacts_path_t *artifacts_path_create(
    char *path
    ) {
    return artifacts_path_create_internal (
        path
        );
}

void artifacts_path_free(artifacts_path_t *artifacts_path) {
    if(NULL == artifacts_path){
        return ;
    }
    if(artifacts_path->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "artifacts_path_free");
        return ;
    }
    listEntry_t *listEntry;
    if (artifacts_path->path) {
        free(artifacts_path->path);
        artifacts_path->path = NULL;
    }
    free(artifacts_path);
}

cJSON *artifacts_path_convertToJSON(artifacts_path_t *artifacts_path) {
    cJSON *item = cJSON_CreateObject();

    // artifacts_path->path
    if (!artifacts_path->path) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "path", artifacts_path->path) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

artifacts_path_t *artifacts_path_parseFromJSON(cJSON *artifacts_pathJSON){

    artifacts_path_t *artifacts_path_local_var = NULL;

    // artifacts_path->path
    cJSON *path = cJSON_GetObjectItemCaseSensitive(artifacts_pathJSON, "path");
    if (cJSON_IsNull(path)) {
        path = NULL;
    }
    if (!path) {
        goto end;
    }

    
    if(!cJSON_IsString(path))
    {
    goto end; //String
    }


    artifacts_path_local_var = artifacts_path_create_internal (
        strdup(path->valuestring)
        );

    return artifacts_path_local_var;
end:
    return NULL;

}
