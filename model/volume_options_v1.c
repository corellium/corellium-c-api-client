#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "volume_options_v1.h"



static volume_options_v1_t *volume_options_v1_create_internal(
    double blocks,
    char *name
    ) {
    volume_options_v1_t *volume_options_v1_local_var = malloc(sizeof(volume_options_v1_t));
    if (!volume_options_v1_local_var) {
        return NULL;
    }
    volume_options_v1_local_var->blocks = blocks;
    volume_options_v1_local_var->name = name;

    volume_options_v1_local_var->_library_owned = 1;
    return volume_options_v1_local_var;
}

__attribute__((deprecated)) volume_options_v1_t *volume_options_v1_create(
    double blocks,
    char *name
    ) {
    return volume_options_v1_create_internal (
        blocks,
        name
        );
}

void volume_options_v1_free(volume_options_v1_t *volume_options_v1) {
    if(NULL == volume_options_v1){
        return ;
    }
    if(volume_options_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "volume_options_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (volume_options_v1->name) {
        free(volume_options_v1->name);
        volume_options_v1->name = NULL;
    }
    free(volume_options_v1);
}

cJSON *volume_options_v1_convertToJSON(volume_options_v1_t *volume_options_v1) {
    cJSON *item = cJSON_CreateObject();

    // volume_options_v1->blocks
    if(volume_options_v1->blocks) {
    if(cJSON_AddNumberToObject(item, "blocks", volume_options_v1->blocks) == NULL) {
    goto fail; //Numeric
    }
    }


    // volume_options_v1->name
    if(volume_options_v1->name) {
    if(cJSON_AddStringToObject(item, "name", volume_options_v1->name) == NULL) {
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

volume_options_v1_t *volume_options_v1_parseFromJSON(cJSON *volume_options_v1JSON){

    volume_options_v1_t *volume_options_v1_local_var = NULL;

    // volume_options_v1->blocks
    cJSON *blocks = cJSON_GetObjectItemCaseSensitive(volume_options_v1JSON, "blocks");
    if (cJSON_IsNull(blocks)) {
        blocks = NULL;
    }
    if (blocks) { 
    if(!cJSON_IsNumber(blocks))
    {
    goto end; //Numeric
    }
    }

    // volume_options_v1->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(volume_options_v1JSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }


    volume_options_v1_local_var = volume_options_v1_create_internal (
        blocks ? blocks->valuedouble : 0,
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL
        );

    return volume_options_v1_local_var;
end:
    return NULL;

}
