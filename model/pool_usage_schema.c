#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pool_usage_schema.h"



static pool_usage_schema_t *pool_usage_schema_create_internal(
    double used,
    double size,
    double free,
    double lv_count
    ) {
    pool_usage_schema_t *pool_usage_schema_local_var = malloc(sizeof(pool_usage_schema_t));
    if (!pool_usage_schema_local_var) {
        return NULL;
    }
    pool_usage_schema_local_var->used = used;
    pool_usage_schema_local_var->size = size;
    pool_usage_schema_local_var->free = free;
    pool_usage_schema_local_var->lv_count = lv_count;

    pool_usage_schema_local_var->_library_owned = 1;
    return pool_usage_schema_local_var;
}

__attribute__((deprecated)) pool_usage_schema_t *pool_usage_schema_create(
    double used,
    double size,
    double free,
    double lv_count
    ) {
    return pool_usage_schema_create_internal (
        used,
        size,
        free,
        lv_count
        );
}

void pool_usage_schema_free(pool_usage_schema_t *pool_usage_schema) {
    if(NULL == pool_usage_schema){
        return ;
    }
    if(pool_usage_schema->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "pool_usage_schema_free");
        return ;
    }
    listEntry_t *listEntry;
    free(pool_usage_schema);
}

cJSON *pool_usage_schema_convertToJSON(pool_usage_schema_t *pool_usage_schema) {
    cJSON *item = cJSON_CreateObject();

    // pool_usage_schema->used
    if(pool_usage_schema->used) {
    if(cJSON_AddNumberToObject(item, "used", pool_usage_schema->used) == NULL) {
    goto fail; //Numeric
    }
    }


    // pool_usage_schema->size
    if(pool_usage_schema->size) {
    if(cJSON_AddNumberToObject(item, "size", pool_usage_schema->size) == NULL) {
    goto fail; //Numeric
    }
    }


    // pool_usage_schema->free
    if(pool_usage_schema->free) {
    if(cJSON_AddNumberToObject(item, "free", pool_usage_schema->free) == NULL) {
    goto fail; //Numeric
    }
    }


    // pool_usage_schema->lv_count
    if(pool_usage_schema->lv_count) {
    if(cJSON_AddNumberToObject(item, "lvCount", pool_usage_schema->lv_count) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

pool_usage_schema_t *pool_usage_schema_parseFromJSON(cJSON *pool_usage_schemaJSON){

    pool_usage_schema_t *pool_usage_schema_local_var = NULL;

    // pool_usage_schema->used
    cJSON *used = cJSON_GetObjectItemCaseSensitive(pool_usage_schemaJSON, "used");
    if (cJSON_IsNull(used)) {
        used = NULL;
    }
    if (used) { 
    if(!cJSON_IsNumber(used))
    {
    goto end; //Numeric
    }
    }

    // pool_usage_schema->size
    cJSON *size = cJSON_GetObjectItemCaseSensitive(pool_usage_schemaJSON, "size");
    if (cJSON_IsNull(size)) {
        size = NULL;
    }
    if (size) { 
    if(!cJSON_IsNumber(size))
    {
    goto end; //Numeric
    }
    }

    // pool_usage_schema->free
    cJSON *free = cJSON_GetObjectItemCaseSensitive(pool_usage_schemaJSON, "free");
    if (cJSON_IsNull(free)) {
        free = NULL;
    }
    if (free) { 
    if(!cJSON_IsNumber(free))
    {
    goto end; //Numeric
    }
    }

    // pool_usage_schema->lv_count
    cJSON *lv_count = cJSON_GetObjectItemCaseSensitive(pool_usage_schemaJSON, "lvCount");
    if (cJSON_IsNull(lv_count)) {
        lv_count = NULL;
    }
    if (lv_count) { 
    if(!cJSON_IsNumber(lv_count))
    {
    goto end; //Numeric
    }
    }


    pool_usage_schema_local_var = pool_usage_schema_create_internal (
        used ? used->valuedouble : 0,
        size ? size->valuedouble : 0,
        free ? free->valuedouble : 0,
        lv_count ? lv_count->valuedouble : 0
        );

    return pool_usage_schema_local_var;
end:
    return NULL;

}
