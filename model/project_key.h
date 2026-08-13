/*
 * project_key.h
 *
 * 
 */

#ifndef _project_key_H_
#define _project_key_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct project_key_t project_key_t;


// Enum KIND for project_key

typedef enum  { corellium_api_project_key_KIND_NULL = 0, corellium_api_project_key_KIND_ssh, corellium_api_project_key_KIND_adb } corellium_api_project_key_KIND_e;

char* project_key_kind_ToString(corellium_api_project_key_KIND_e kind);

corellium_api_project_key_KIND_e project_key_kind_FromString(char* kind);



typedef struct project_key_t {
    corellium_api_project_key_KIND_e kind; //enum
    char *label; // string
    char *key; // string
    char *id; // string
    char *project; // string
    char *fingerprint; // string
    char *created_at; //date time
    char *updated_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} project_key_t;

__attribute__((deprecated)) project_key_t *project_key_create(
    corellium_api_project_key_KIND_e kind,
    char *label,
    char *key,
    char *id,
    char *project,
    char *fingerprint,
    char *created_at,
    char *updated_at
);

void project_key_free(project_key_t *project_key);

project_key_t *project_key_parseFromJSON(cJSON *project_keyJSON);

cJSON *project_key_convertToJSON(project_key_t *project_key);

#endif /* _project_key_H_ */

