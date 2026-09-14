/*
 * saml_user_attribute_mapping.h
 *
 * 
 */

#ifndef _saml_user_attribute_mapping_H_
#define _saml_user_attribute_mapping_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct saml_user_attribute_mapping_t saml_user_attribute_mapping_t;




typedef struct saml_user_attribute_mapping_t {
    char *username; // string
    char *email; // string
    char *first_name; // string
    char *last_name; // string
    char *group; // string

    int _library_owned; // Is the library responsible for freeing this object?
} saml_user_attribute_mapping_t;

__attribute__((deprecated)) saml_user_attribute_mapping_t *saml_user_attribute_mapping_create(
    char *username,
    char *email,
    char *first_name,
    char *last_name,
    char *group
);

void saml_user_attribute_mapping_free(saml_user_attribute_mapping_t *saml_user_attribute_mapping);

saml_user_attribute_mapping_t *saml_user_attribute_mapping_parseFromJSON(cJSON *saml_user_attribute_mappingJSON);

cJSON *saml_user_attribute_mapping_convertToJSON(saml_user_attribute_mapping_t *saml_user_attribute_mapping);

#endif /* _saml_user_attribute_mapping_H_ */

