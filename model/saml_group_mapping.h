/*
 * saml_group_mapping.h
 *
 * 
 */

#ifndef _saml_group_mapping_H_
#define _saml_group_mapping_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct saml_group_mapping_t saml_group_mapping_t;




typedef struct saml_group_mapping_t {
    char *group_name; // string
    char *role; // string
    char *team; // string

    int _library_owned; // Is the library responsible for freeing this object?
} saml_group_mapping_t;

__attribute__((deprecated)) saml_group_mapping_t *saml_group_mapping_create(
    char *group_name,
    char *role,
    char *team
);

void saml_group_mapping_free(saml_group_mapping_t *saml_group_mapping);

saml_group_mapping_t *saml_group_mapping_parseFromJSON(cJSON *saml_group_mappingJSON);

cJSON *saml_group_mapping_convertToJSON(saml_group_mapping_t *saml_group_mapping);

#endif /* _saml_group_mapping_H_ */

