/*
 * project_key_v1.h
 *
 * 
 */

#ifndef _project_key_v1_H_
#define _project_key_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct project_key_v1_t project_key_v1_t;


// Enum KIND for project_key_v1

typedef enum  { corellium_api_project_key_v1_KIND_NULL = 0, corellium_api_project_key_v1_KIND_ssh, corellium_api_project_key_v1_KIND_adb } corellium_api_project_key_v1_KIND_e;

char* project_key_v1_kind_ToString(corellium_api_project_key_v1_KIND_e kind);

corellium_api_project_key_v1_KIND_e project_key_v1_kind_FromString(char* kind);



typedef struct project_key_v1_t {
    char *identifier; // string
    corellium_api_project_key_v1_KIND_e kind; //enum
    char *project; // string
    char *key; // string
    char *fingerprint; // string
    char *updated_at; //date time
    char *created_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} project_key_v1_t;

__attribute__((deprecated)) project_key_v1_t *project_key_v1_create(
    char *identifier,
    corellium_api_project_key_v1_KIND_e kind,
    char *project,
    char *key,
    char *fingerprint,
    char *updated_at,
    char *created_at
);

void project_key_v1_free(project_key_v1_t *project_key_v1);

project_key_v1_t *project_key_v1_parseFromJSON(cJSON *project_key_v1JSON);

cJSON *project_key_v1_convertToJSON(project_key_v1_t *project_key_v1);

#endif /* _project_key_v1_H_ */

