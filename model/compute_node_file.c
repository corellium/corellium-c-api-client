#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "compute_node_file.h"



static compute_node_file_t *compute_node_file_create_internal(
    char *path,
    double size,
    char *mtime
    ) {
    compute_node_file_t *compute_node_file_local_var = malloc(sizeof(compute_node_file_t));
    if (!compute_node_file_local_var) {
        return NULL;
    }
    compute_node_file_local_var->path = path;
    compute_node_file_local_var->size = size;
    compute_node_file_local_var->mtime = mtime;

    compute_node_file_local_var->_library_owned = 1;
    return compute_node_file_local_var;
}

__attribute__((deprecated)) compute_node_file_t *compute_node_file_create(
    char *path,
    double size,
    char *mtime
    ) {
    return compute_node_file_create_internal (
        path,
        size,
        mtime
        );
}

void compute_node_file_free(compute_node_file_t *compute_node_file) {
    if(NULL == compute_node_file){
        return ;
    }
    if(compute_node_file->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "compute_node_file_free");
        return ;
    }
    listEntry_t *listEntry;
    if (compute_node_file->path) {
        free(compute_node_file->path);
        compute_node_file->path = NULL;
    }
    if (compute_node_file->mtime) {
        free(compute_node_file->mtime);
        compute_node_file->mtime = NULL;
    }
    free(compute_node_file);
}

cJSON *compute_node_file_convertToJSON(compute_node_file_t *compute_node_file) {
    cJSON *item = cJSON_CreateObject();

    // compute_node_file->path
    if (!compute_node_file->path) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "path", compute_node_file->path) == NULL) {
    goto fail; //String
    }


    // compute_node_file->size
    if (!compute_node_file->size) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "size", compute_node_file->size) == NULL) {
    goto fail; //Numeric
    }


    // compute_node_file->mtime
    if (!compute_node_file->mtime) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "mtime", compute_node_file->mtime) == NULL) {
    goto fail; //Date-Time
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

compute_node_file_t *compute_node_file_parseFromJSON(cJSON *compute_node_fileJSON){

    compute_node_file_t *compute_node_file_local_var = NULL;

    // compute_node_file->path
    cJSON *path = cJSON_GetObjectItemCaseSensitive(compute_node_fileJSON, "path");
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

    // compute_node_file->size
    cJSON *size = cJSON_GetObjectItemCaseSensitive(compute_node_fileJSON, "size");
    if (cJSON_IsNull(size)) {
        size = NULL;
    }
    if (!size) {
        goto end;
    }

    
    if(!cJSON_IsNumber(size))
    {
    goto end; //Numeric
    }

    // compute_node_file->mtime
    cJSON *mtime = cJSON_GetObjectItemCaseSensitive(compute_node_fileJSON, "mtime");
    if (cJSON_IsNull(mtime)) {
        mtime = NULL;
    }
    if (!mtime) {
        goto end;
    }

    
    if(!cJSON_IsString(mtime) && !cJSON_IsNull(mtime))
    {
    goto end; //DateTime
    }


    compute_node_file_local_var = compute_node_file_create_internal (
        strdup(path->valuestring),
        size->valuedouble,
        strdup(mtime->valuestring)
        );

    return compute_node_file_local_var;
end:
    return NULL;

}
