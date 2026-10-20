/*
 * insufficient_storage_error.h
 *
 * 
 */

#ifndef _insufficient_storage_error_H_
#define _insufficient_storage_error_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct insufficient_storage_error_t insufficient_storage_error_t;


// Enum ERRORID for insufficient_storage_error

typedef enum  { corellium_api_insufficient_storage_error_ERRORID_NULL = 0, corellium_api_insufficient_storage_error_ERRORID_InsufficientStorage } corellium_api_insufficient_storage_error_ERRORID_e;

char* insufficient_storage_error_error_id_ToString(corellium_api_insufficient_storage_error_ERRORID_e error_id);

corellium_api_insufficient_storage_error_ERRORID_e insufficient_storage_error_error_id_FromString(char* error_id);



typedef struct insufficient_storage_error_t {
    char *error; // string
    corellium_api_insufficient_storage_error_ERRORID_e error_id; //enum
    double total; //numeric
    double available; //numeric
    double required; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} insufficient_storage_error_t;

__attribute__((deprecated)) insufficient_storage_error_t *insufficient_storage_error_create(
    char *error,
    corellium_api_insufficient_storage_error_ERRORID_e error_id,
    double total,
    double available,
    double required
);

void insufficient_storage_error_free(insufficient_storage_error_t *insufficient_storage_error);

insufficient_storage_error_t *insufficient_storage_error_parseFromJSON(cJSON *insufficient_storage_errorJSON);

cJSON *insufficient_storage_error_convertToJSON(insufficient_storage_error_t *insufficient_storage_error);

#endif /* _insufficient_storage_error_H_ */

