/*
 * storage_file_list.h
 *
 * 
 */

#ifndef _storage_file_list_H_
#define _storage_file_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct storage_file_list_t storage_file_list_t;

#include "storage_file.h"



typedef struct storage_file_list_t {
    list_t *results; //nonprimitive container
    double count; //numeric
    double total; //numeric
    double limit; //numeric
    double offset; //numeric
    int has_more; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} storage_file_list_t;

__attribute__((deprecated)) storage_file_list_t *storage_file_list_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
);

void storage_file_list_free(storage_file_list_t *storage_file_list);

storage_file_list_t *storage_file_list_parseFromJSON(cJSON *storage_file_listJSON);

cJSON *storage_file_list_convertToJSON(storage_file_list_t *storage_file_list);

#endif /* _storage_file_list_H_ */

