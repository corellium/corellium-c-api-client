#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "kernel_thread.h"



static kernel_thread_t *kernel_thread_create_internal(
    char *kernel_id,
    double task_id,
    list_t *stack
    ) {
    kernel_thread_t *kernel_thread_local_var = malloc(sizeof(kernel_thread_t));
    if (!kernel_thread_local_var) {
        return NULL;
    }
    kernel_thread_local_var->kernel_id = kernel_id;
    kernel_thread_local_var->task_id = task_id;
    kernel_thread_local_var->stack = stack;

    kernel_thread_local_var->_library_owned = 1;
    return kernel_thread_local_var;
}

__attribute__((deprecated)) kernel_thread_t *kernel_thread_create(
    char *kernel_id,
    double task_id,
    list_t *stack
    ) {
    return kernel_thread_create_internal (
        kernel_id,
        task_id,
        stack
        );
}

void kernel_thread_free(kernel_thread_t *kernel_thread) {
    if(NULL == kernel_thread){
        return ;
    }
    if(kernel_thread->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "kernel_thread_free");
        return ;
    }
    listEntry_t *listEntry;
    if (kernel_thread->kernel_id) {
        free(kernel_thread->kernel_id);
        kernel_thread->kernel_id = NULL;
    }
    if (kernel_thread->stack) {
        list_ForEach(listEntry, kernel_thread->stack) {
            free(listEntry->data);
        }
        list_freeList(kernel_thread->stack);
        kernel_thread->stack = NULL;
    }
    free(kernel_thread);
}

cJSON *kernel_thread_convertToJSON(kernel_thread_t *kernel_thread) {
    cJSON *item = cJSON_CreateObject();

    // kernel_thread->kernel_id
    if (!kernel_thread->kernel_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kernelId", kernel_thread->kernel_id) == NULL) {
    goto fail; //String
    }


    // kernel_thread->task_id
    if (!kernel_thread->task_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "taskId", kernel_thread->task_id) == NULL) {
    goto fail; //Numeric
    }


    // kernel_thread->stack
    if (!kernel_thread->stack) {
        goto fail;
    }
    cJSON *stack = cJSON_AddArrayToObject(item, "stack");
    if(stack == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *stackListEntry;
    list_ForEach(stackListEntry, kernel_thread->stack) {
    if(cJSON_AddStringToObject(stack, "", stackListEntry->data) == NULL)
    {
        goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

kernel_thread_t *kernel_thread_parseFromJSON(cJSON *kernel_threadJSON){

    kernel_thread_t *kernel_thread_local_var = NULL;

    // define the local list for kernel_thread->stack
    list_t *stackList = NULL;

    // kernel_thread->kernel_id
    cJSON *kernel_id = cJSON_GetObjectItemCaseSensitive(kernel_threadJSON, "kernelId");
    if (cJSON_IsNull(kernel_id)) {
        kernel_id = NULL;
    }
    if (!kernel_id) {
        goto end;
    }

    
    if(!cJSON_IsString(kernel_id))
    {
    goto end; //String
    }

    // kernel_thread->task_id
    cJSON *task_id = cJSON_GetObjectItemCaseSensitive(kernel_threadJSON, "taskId");
    if (cJSON_IsNull(task_id)) {
        task_id = NULL;
    }
    if (!task_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(task_id))
    {
    goto end; //Numeric
    }

    // kernel_thread->stack
    cJSON *stack = cJSON_GetObjectItemCaseSensitive(kernel_threadJSON, "stack");
    if (cJSON_IsNull(stack)) {
        stack = NULL;
    }
    if (!stack) {
        goto end;
    }

    
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


    kernel_thread_local_var = kernel_thread_create_internal (
        strdup(kernel_id->valuestring),
        task_id->valuedouble,
        stackList
        );

    return kernel_thread_local_var;
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
