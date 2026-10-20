#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "kernel_thread_v1.h"



static kernel_thread_v1_t *kernel_thread_v1_create_internal(
    char *kernel_id,
    double tid,
    list_t *stack
    ) {
    kernel_thread_v1_t *kernel_thread_v1_local_var = malloc(sizeof(kernel_thread_v1_t));
    if (!kernel_thread_v1_local_var) {
        return NULL;
    }
    kernel_thread_v1_local_var->kernel_id = kernel_id;
    kernel_thread_v1_local_var->tid = tid;
    kernel_thread_v1_local_var->stack = stack;

    kernel_thread_v1_local_var->_library_owned = 1;
    return kernel_thread_v1_local_var;
}

__attribute__((deprecated)) kernel_thread_v1_t *kernel_thread_v1_create(
    char *kernel_id,
    double tid,
    list_t *stack
    ) {
    return kernel_thread_v1_create_internal (
        kernel_id,
        tid,
        stack
        );
}

void kernel_thread_v1_free(kernel_thread_v1_t *kernel_thread_v1) {
    if(NULL == kernel_thread_v1){
        return ;
    }
    if(kernel_thread_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "kernel_thread_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (kernel_thread_v1->kernel_id) {
        free(kernel_thread_v1->kernel_id);
        kernel_thread_v1->kernel_id = NULL;
    }
    if (kernel_thread_v1->stack) {
        list_ForEach(listEntry, kernel_thread_v1->stack) {
            free(listEntry->data);
        }
        list_freeList(kernel_thread_v1->stack);
        kernel_thread_v1->stack = NULL;
    }
    free(kernel_thread_v1);
}

cJSON *kernel_thread_v1_convertToJSON(kernel_thread_v1_t *kernel_thread_v1) {
    cJSON *item = cJSON_CreateObject();

    // kernel_thread_v1->kernel_id
    if(kernel_thread_v1->kernel_id) {
    if(cJSON_AddStringToObject(item, "kernelId", kernel_thread_v1->kernel_id) == NULL) {
    goto fail; //String
    }
    }


    // kernel_thread_v1->tid
    if(kernel_thread_v1->tid) {
    if(cJSON_AddNumberToObject(item, "tid", kernel_thread_v1->tid) == NULL) {
    goto fail; //Numeric
    }
    }


    // kernel_thread_v1->stack
    if(kernel_thread_v1->stack) {
    cJSON *stack = cJSON_AddArrayToObject(item, "stack");
    if(stack == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *stackListEntry;
    list_ForEach(stackListEntry, kernel_thread_v1->stack) {
    if(cJSON_AddStringToObject(stack, "", stackListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

kernel_thread_v1_t *kernel_thread_v1_parseFromJSON(cJSON *kernel_thread_v1JSON){

    kernel_thread_v1_t *kernel_thread_v1_local_var = NULL;

    // define the local list for kernel_thread_v1->stack
    list_t *stackList = NULL;

    // kernel_thread_v1->kernel_id
    cJSON *kernel_id = cJSON_GetObjectItemCaseSensitive(kernel_thread_v1JSON, "kernelId");
    if (cJSON_IsNull(kernel_id)) {
        kernel_id = NULL;
    }
    if (kernel_id) { 
    if(!cJSON_IsString(kernel_id) && !cJSON_IsNull(kernel_id))
    {
    goto end; //String
    }
    }

    // kernel_thread_v1->tid
    cJSON *tid = cJSON_GetObjectItemCaseSensitive(kernel_thread_v1JSON, "tid");
    if (cJSON_IsNull(tid)) {
        tid = NULL;
    }
    if (tid) { 
    if(!cJSON_IsNumber(tid))
    {
    goto end; //Numeric
    }
    }

    // kernel_thread_v1->stack
    cJSON *stack = cJSON_GetObjectItemCaseSensitive(kernel_thread_v1JSON, "stack");
    if (cJSON_IsNull(stack)) {
        stack = NULL;
    }
    if (stack) { 
    cJSON *stack_local = NULL;
    if(!cJSON_IsArray(stack)) {
        goto end;//primitive container
    }
    stackList = list_createList();

    cJSON_ArrayForEach(stack_local, stack)
    {
        if(!cJSON_IsString(stack_local))
        {
            goto end;
        }
        list_addElement(stackList , strdup(stack_local->valuestring));
    }
    }


    kernel_thread_v1_local_var = kernel_thread_v1_create_internal (
        kernel_id && !cJSON_IsNull(kernel_id) ? strdup(kernel_id->valuestring) : NULL,
        tid ? tid->valuedouble : 0,
        stack ? stackList : NULL
        );

    return kernel_thread_v1_local_var;
end:
    if (stackList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, stackList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(stackList);
        stackList = NULL;
    }
    return NULL;

}
