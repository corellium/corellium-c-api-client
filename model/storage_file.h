/*
 * storage_file.h
 *
 * 
 */

#ifndef _storage_file_H_
#define _storage_file_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct storage_file_t storage_file_t;


// Enum TYPE for storage_file

typedef enum  { corellium_api_storage_file_TYPE_NULL = 0, corellium_api_storage_file_TYPE_file, corellium_api_storage_file_TYPE_directory } corellium_api_storage_file_TYPE_e;

char* storage_file_type_ToString(corellium_api_storage_file_TYPE_e type);

corellium_api_storage_file_TYPE_e storage_file_type_FromString(char* type);



typedef struct storage_file_t {
    char *name; // string
    char *ext; // string
    corellium_api_storage_file_TYPE_e type; //enum
    double size; //numeric
    char *last_modified_time; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} storage_file_t;

__attribute__((deprecated)) storage_file_t *storage_file_create(
    char *name,
    char *ext,
    corellium_api_storage_file_TYPE_e type,
    double size,
    char *last_modified_time
);

void storage_file_free(storage_file_t *storage_file);

storage_file_t *storage_file_parseFromJSON(cJSON *storage_fileJSON);

cJSON *storage_file_convertToJSON(storage_file_t *storage_file);

#endif /* _storage_file_H_ */

