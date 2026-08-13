/*
 * insufficient_storage_error_v1.h
 *
 * 
 */

#ifndef _insufficient_storage_error_v1_H_
#define _insufficient_storage_error_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct insufficient_storage_error_v1_t insufficient_storage_error_v1_t;




typedef struct insufficient_storage_error_v1_t {
    char *error_id; // string
    char *error; // string
    double total; //numeric
    double available; //numeric
    double required; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} insufficient_storage_error_v1_t;

__attribute__((deprecated)) insufficient_storage_error_v1_t *insufficient_storage_error_v1_create(
    char *error_id,
    char *error,
    double total,
    double available,
    double required
);

void insufficient_storage_error_v1_free(insufficient_storage_error_v1_t *insufficient_storage_error_v1);

insufficient_storage_error_v1_t *insufficient_storage_error_v1_parseFromJSON(cJSON *insufficient_storage_error_v1JSON);

cJSON *insufficient_storage_error_v1_convertToJSON(insufficient_storage_error_v1_t *insufficient_storage_error_v1);

#endif /* _insufficient_storage_error_v1_H_ */

