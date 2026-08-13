/*
 * ipsw_version_constraint.h
 *
 * 
 */

#ifndef _ipsw_version_constraint_H_
#define _ipsw_version_constraint_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ipsw_version_constraint_t ipsw_version_constraint_t;




typedef struct ipsw_version_constraint_t {
    char *lt; // string
    char *le; // string
    char *gt; // string
    char *ge; // string
    char *eq; // string

    int _library_owned; // Is the library responsible for freeing this object?
} ipsw_version_constraint_t;

__attribute__((deprecated)) ipsw_version_constraint_t *ipsw_version_constraint_create(
    char *lt,
    char *le,
    char *gt,
    char *ge,
    char *eq
);

void ipsw_version_constraint_free(ipsw_version_constraint_t *ipsw_version_constraint);

ipsw_version_constraint_t *ipsw_version_constraint_parseFromJSON(cJSON *ipsw_version_constraintJSON);

cJSON *ipsw_version_constraint_convertToJSON(ipsw_version_constraint_t *ipsw_version_constraint);

#endif /* _ipsw_version_constraint_H_ */

