/*
 * kernel_thread_v1.h
 *
 * 
 */

#ifndef _kernel_thread_v1_H_
#define _kernel_thread_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct kernel_thread_v1_t kernel_thread_v1_t;




typedef struct kernel_thread_v1_t {
    char *kernel_id; // string
    double tid; //numeric
    list_t *stack; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} kernel_thread_v1_t;

__attribute__((deprecated)) kernel_thread_v1_t *kernel_thread_v1_create(
    char *kernel_id,
    double tid,
    list_t *stack
);

void kernel_thread_v1_free(kernel_thread_v1_t *kernel_thread_v1);

kernel_thread_v1_t *kernel_thread_v1_parseFromJSON(cJSON *kernel_thread_v1JSON);

cJSON *kernel_thread_v1_convertToJSON(kernel_thread_v1_t *kernel_thread_v1);

#endif /* _kernel_thread_v1_H_ */

