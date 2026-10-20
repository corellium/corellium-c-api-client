#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "volume_options.h"



static volume_options_t *volume_options_create_internal(
    double blocks,
    char *name
    ) {
    volume_options_t *volume_options_local_var = malloc(sizeof(volume_options_t));
    if (!volume_options_local_var) {
        return NULL;
    }
    volume_options_local_var->blocks = blocks;
    volume_options_local_var->name = name;

    volume_options_local_var->_library_owned = 1;
    return volume_options_local_var;
}

__attribute__((deprecated)) volume_options_t *volume_options_create(
    double blocks,
    char *name
    ) {
    return volume_options_create_internal (
        blocks,
        name
        );
}

void volume_options_free(volume_options_t *volume_options) {
    if(NULL == volume_options){
        return ;
    }
    if(volume_options->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "volume_options_free");
        return ;
    }
    listEntry_t *listEntry;
    if (volume_options->name) {
        free(volume_options->name);
        volume_options->name = NULL;
    }
    free(volume_options);
}

cJSON *volume_options_convertToJSON(volume_options_t *volume_options) {
    cJSON *item = cJSON_CreateObject();

    // volume_options->blocks
    if (!volume_options->blocks) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "blocks", volume_options->blocks) == NULL) {
    goto fail; //Numeric
    }


    // volume_options->name
    if (!volume_options->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", volume_options->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

volume_options_t *volume_options_parseFromJSON(cJSON *volume_optionsJSON){

    volume_options_t *volume_options_local_var = NULL;

    // volume_options->blocks
    cJSON *blocks = cJSON_GetObjectItemCaseSensitive(volume_optionsJSON, "blocks");
    if (cJSON_IsNull(blocks)) {
        blocks = NULL;
    }
    if (!blocks) {
        goto end;
    }

    
    if(!cJSON_IsNumber(blocks))
    {
    goto end; //Numeric
    }

    // volume_options->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(volume_optionsJSON, "name");
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


    volume_options_local_var = volume_options_create_internal (
        blocks->valuedouble,
        strdup(name->valuestring)
        );

    return volume_options_local_var;
end:
    return NULL;

}
