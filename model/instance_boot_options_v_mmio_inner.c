#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instance_boot_options_v_mmio_inner.h"



static instance_boot_options_v_mmio_inner_t *instance_boot_options_v_mmio_inner_create_internal(
    char *start,
    char *size,
    char *irq
    ) {
    instance_boot_options_v_mmio_inner_t *instance_boot_options_v_mmio_inner_local_var = malloc(sizeof(instance_boot_options_v_mmio_inner_t));
    if (!instance_boot_options_v_mmio_inner_local_var) {
        return NULL;
    }
    instance_boot_options_v_mmio_inner_local_var->start = start;
    instance_boot_options_v_mmio_inner_local_var->size = size;
    instance_boot_options_v_mmio_inner_local_var->irq = irq;

    instance_boot_options_v_mmio_inner_local_var->_library_owned = 1;
    return instance_boot_options_v_mmio_inner_local_var;
}

__attribute__((deprecated)) instance_boot_options_v_mmio_inner_t *instance_boot_options_v_mmio_inner_create(
    char *start,
    char *size,
    char *irq
    ) {
    return instance_boot_options_v_mmio_inner_create_internal (
        start,
        size,
        irq
        );
}

void instance_boot_options_v_mmio_inner_free(instance_boot_options_v_mmio_inner_t *instance_boot_options_v_mmio_inner) {
    if(NULL == instance_boot_options_v_mmio_inner){
        return ;
    }
    if(instance_boot_options_v_mmio_inner->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "instance_boot_options_v_mmio_inner_free");
        return ;
    }
    listEntry_t *listEntry;
    if (instance_boot_options_v_mmio_inner->start) {
        free(instance_boot_options_v_mmio_inner->start);
        instance_boot_options_v_mmio_inner->start = NULL;
    }
    if (instance_boot_options_v_mmio_inner->size) {
        free(instance_boot_options_v_mmio_inner->size);
        instance_boot_options_v_mmio_inner->size = NULL;
    }
    if (instance_boot_options_v_mmio_inner->irq) {
        free(instance_boot_options_v_mmio_inner->irq);
        instance_boot_options_v_mmio_inner->irq = NULL;
    }
    free(instance_boot_options_v_mmio_inner);
}

cJSON *instance_boot_options_v_mmio_inner_convertToJSON(instance_boot_options_v_mmio_inner_t *instance_boot_options_v_mmio_inner) {
    cJSON *item = cJSON_CreateObject();

    // instance_boot_options_v_mmio_inner->start
    if (!instance_boot_options_v_mmio_inner->start) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "start", instance_boot_options_v_mmio_inner->start) == NULL) {
    goto fail; //String
    }


    // instance_boot_options_v_mmio_inner->size
    if (!instance_boot_options_v_mmio_inner->size) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "size", instance_boot_options_v_mmio_inner->size) == NULL) {
    goto fail; //String
    }


    // instance_boot_options_v_mmio_inner->irq
    if (!instance_boot_options_v_mmio_inner->irq) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "irq", instance_boot_options_v_mmio_inner->irq) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

instance_boot_options_v_mmio_inner_t *instance_boot_options_v_mmio_inner_parseFromJSON(cJSON *instance_boot_options_v_mmio_innerJSON){

    instance_boot_options_v_mmio_inner_t *instance_boot_options_v_mmio_inner_local_var = NULL;

    // instance_boot_options_v_mmio_inner->start
    cJSON *start = cJSON_GetObjectItemCaseSensitive(instance_boot_options_v_mmio_innerJSON, "start");
    if (cJSON_IsNull(start)) {
        start = NULL;
    }
    if (!start) {
        goto end;
    }

    
    if(!cJSON_IsString(start))
    {
    goto end; //String
    }

    // instance_boot_options_v_mmio_inner->size
    cJSON *size = cJSON_GetObjectItemCaseSensitive(instance_boot_options_v_mmio_innerJSON, "size");
    if (cJSON_IsNull(size)) {
        size = NULL;
    }
    if (!size) {
        goto end;
    }

    
    if(!cJSON_IsString(size))
    {
    goto end; //String
    }

    // instance_boot_options_v_mmio_inner->irq
    cJSON *irq = cJSON_GetObjectItemCaseSensitive(instance_boot_options_v_mmio_innerJSON, "irq");
    if (cJSON_IsNull(irq)) {
        irq = NULL;
    }
    if (!irq) {
        goto end;
    }

    
    if(!cJSON_IsString(irq))
    {
    goto end; //String
    }


    instance_boot_options_v_mmio_inner_local_var = instance_boot_options_v_mmio_inner_create_internal (
        strdup(start->valuestring),
        strdup(size->valuestring),
        strdup(irq->valuestring)
        );

    return instance_boot_options_v_mmio_inner_local_var;
end:
    return NULL;

}
