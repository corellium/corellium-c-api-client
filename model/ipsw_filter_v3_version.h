/*
 * ipsw_filter_v3_version.h
 *
 * Version constraint.
 */

#ifndef _ipsw_filter_v3_version_H_
#define _ipsw_filter_v3_version_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ipsw_filter_v3_version_t ipsw_filter_v3_version_t;




typedef struct ipsw_filter_v3_version_t {
    char *lt; // string
    char *le; // string
    char *gt; // string
    char *ge; // string
    char *eq; // string

    int _library_owned; // Is the library responsible for freeing this object?
} ipsw_filter_v3_version_t;

__attribute__((deprecated)) ipsw_filter_v3_version_t *ipsw_filter_v3_version_create(
    char *lt,
    char *le,
    char *gt,
    char *ge,
    char *eq
);

void ipsw_filter_v3_version_free(ipsw_filter_v3_version_t *ipsw_filter_v3_version);

ipsw_filter_v3_version_t *ipsw_filter_v3_version_parseFromJSON(cJSON *ipsw_filter_v3_versionJSON);

cJSON *ipsw_filter_v3_version_convertToJSON(ipsw_filter_v3_version_t *ipsw_filter_v3_version);

#endif /* _ipsw_filter_v3_version_H_ */

