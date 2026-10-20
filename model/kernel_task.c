#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "kernel_task.h"



static kernel_task_t *kernel_task_create_internal(
    char *kernel_id,
    char *name,
    double process_id,
    list_t *threads
    ) {
    kernel_task_t *kernel_task_local_var = malloc(sizeof(kernel_task_t));
    if (!kernel_task_local_var) {
        return NULL;
    }
    kernel_task_local_var->kernel_id = kernel_id;
    kernel_task_local_var->name = name;
    kernel_task_local_var->process_id = process_id;
    kernel_task_local_var->threads = threads;

    kernel_task_local_var->_library_owned = 1;
    return kernel_task_local_var;
}

__attribute__((deprecated)) kernel_task_t *kernel_task_create(
    char *kernel_id,
    char *name,
    double process_id,
    list_t *threads
    ) {
    return kernel_task_create_internal (
        kernel_id,
        name,
        process_id,
        threads
        );
}

void kernel_task_free(kernel_task_t *kernel_task) {
    if(NULL == kernel_task){
        return ;
    }
    if(kernel_task->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "kernel_task_free");
        return ;
    }
    listEntry_t *listEntry;
    if (kernel_task->kernel_id) {
        free(kernel_task->kernel_id);
        kernel_task->kernel_id = NULL;
    }
    if (kernel_task->name) {
        free(kernel_task->name);
        kernel_task->name = NULL;
    }
    if (kernel_task->threads) {
        list_ForEach(listEntry, kernel_task->threads) {
            kernel_thread_free(listEntry->data);
        }
        list_freeList(kernel_task->threads);
        kernel_task->threads = NULL;
    }
    free(kernel_task);
}

cJSON *kernel_task_convertToJSON(kernel_task_t *kernel_task) {
    cJSON *item = cJSON_CreateObject();

    // kernel_task->kernel_id
    if (!kernel_task->kernel_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kernelId", kernel_task->kernel_id) == NULL) {
    goto fail; //String
    }


    // kernel_task->name
    if (!kernel_task->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", kernel_task->name) == NULL) {
    goto fail; //String
    }


    // kernel_task->process_id
    if (!kernel_task->process_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "processId", kernel_task->process_id) == NULL) {
    goto fail; //Numeric
    }


    // kernel_task->threads
    if (!kernel_task->threads) {
        goto fail;
    }
    cJSON *threads = cJSON_AddArrayToObject(item, "threads");
    if(threads == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *threadsListEntry;
    if (kernel_task->threads) {
    list_ForEach(threadsListEntry, kernel_task->threads) {
    cJSON *itemLocal = kernel_thread_convertToJSON(threadsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(threads, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

kernel_task_t *kernel_task_parseFromJSON(cJSON *kernel_taskJSON){

    kernel_task_t *kernel_task_local_var = NULL;

    // define the local list for kernel_task->threads
    list_t *threadsList = NULL;

    // kernel_task->kernel_id
    cJSON *kernel_id = cJSON_GetObjectItemCaseSensitive(kernel_taskJSON, "kernelId");
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

    // kernel_task->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(kernel_taskJSON, "name");
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

    // kernel_task->process_id
    cJSON *process_id = cJSON_GetObjectItemCaseSensitive(kernel_taskJSON, "processId");
    if (cJSON_IsNull(process_id)) {
        process_id = NULL;
    }
    if (!process_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(process_id))
    {
    goto end; //Numeric
    }

    // kernel_task->threads
    cJSON *threads = cJSON_GetObjectItemCaseSensitive(kernel_taskJSON, "threads");
    if (cJSON_IsNull(threads)) {
        threads = NULL;
    }
    if (!threads) {
        goto end;
    }

    
    cJSON *threads_local_nonprimitive = NULL;
    if(!cJSON_IsArray(threads)){
        goto end; //nonprimitive container
    }

    threadsList = list_createList();

    cJSON_ArrayForEach(threads_local_nonprimitive,threads )
    {
        if(!cJSON_IsObject(threads_local_nonprimitive)){
            goto end;
        }
        kernel_thread_t *threadsItem = kernel_thread_parseFromJSON(threads_local_nonprimitive);

        list_addElement(threadsList, threadsItem);
    }


    kernel_task_local_var = kernel_task_create_internal (
        strdup(kernel_id->valuestring),
        strdup(name->valuestring),
        process_id->valuedouble,
        threadsList
        );

    return kernel_task_local_var;
end:
    if (threadsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, threadsList) {
            kernel_thread_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(threadsList);
        threadsList = NULL;
    }
    return NULL;

}
