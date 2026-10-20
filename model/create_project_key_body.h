/*
 * create_project_key_body.h
 *
 * 
 */

#ifndef _create_project_key_body_H_
#define _create_project_key_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_project_key_body_t create_project_key_body_t;


// Enum KIND for create_project_key_body

typedef enum  { corellium_api_create_project_key_body_KIND_NULL = 0, corellium_api_create_project_key_body_KIND_ssh, corellium_api_create_project_key_body_KIND_adb } corellium_api_create_project_key_body_KIND_e;

char* create_project_key_body_kind_ToString(corellium_api_create_project_key_body_KIND_e kind);

corellium_api_create_project_key_body_KIND_e create_project_key_body_kind_FromString(char* kind);



typedef struct create_project_key_body_t {
    corellium_api_create_project_key_body_KIND_e kind; //enum
    char *label; // string
    char *key; // string

    int _library_owned; // Is the library responsible for freeing this object?
} create_project_key_body_t;

__attribute__((deprecated)) create_project_key_body_t *create_project_key_body_create(
    corellium_api_create_project_key_body_KIND_e kind,
    char *label,
    char *key
);

void create_project_key_body_free(create_project_key_body_t *create_project_key_body);

create_project_key_body_t *create_project_key_body_parseFromJSON(cJSON *create_project_key_bodyJSON);

cJSON *create_project_key_body_convertToJSON(create_project_key_body_t *create_project_key_body);

#endif /* _create_project_key_body_H_ */

