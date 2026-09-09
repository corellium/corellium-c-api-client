/*
 * upload_size_error.h
 *
 * 
 */

#ifndef _upload_size_error_H_
#define _upload_size_error_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct upload_size_error_t upload_size_error_t;


// Enum ERRORID for upload_size_error

typedef enum  { corellium_api_upload_size_error_ERRORID_NULL = 0, corellium_api_upload_size_error_ERRORID_UploadSizeError } corellium_api_upload_size_error_ERRORID_e;

char* upload_size_error_error_id_ToString(corellium_api_upload_size_error_ERRORID_e error_id);

corellium_api_upload_size_error_ERRORID_e upload_size_error_error_id_FromString(char* error_id);



typedef struct upload_size_error_t {
    char *error; // string
    corellium_api_upload_size_error_ERRORID_e error_id; //enum
    char *field; // string

    int _library_owned; // Is the library responsible for freeing this object?
} upload_size_error_t;

__attribute__((deprecated)) upload_size_error_t *upload_size_error_create(
    char *error,
    corellium_api_upload_size_error_ERRORID_e error_id,
    char *field
);

void upload_size_error_free(upload_size_error_t *upload_size_error);

upload_size_error_t *upload_size_error_parseFromJSON(cJSON *upload_size_errorJSON);

cJSON *upload_size_error_convertToJSON(upload_size_error_t *upload_size_error);

#endif /* _upload_size_error_H_ */

