/*
 * kernel_task_v1.h
 *
 * 
 */

#ifndef _kernel_task_v1_H_
#define _kernel_task_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct kernel_task_v1_t kernel_task_v1_t;

#include "kernel_thread_v1.h"



typedef struct kernel_task_v1_t {
    char *kernel_id; // string
    char *name; // string
    double pid; //numeric
    list_t *threads; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} kernel_task_v1_t;

__attribute__((deprecated)) kernel_task_v1_t *kernel_task_v1_create(
    char *kernel_id,
    char *name,
    double pid,
    list_t *threads
);

void kernel_task_v1_free(kernel_task_v1_t *kernel_task_v1);

kernel_task_v1_t *kernel_task_v1_parseFromJSON(cJSON *kernel_task_v1JSON);

cJSON *kernel_task_v1_convertToJSON(kernel_task_v1_t *kernel_task_v1);

#endif /* _kernel_task_v1_H_ */

