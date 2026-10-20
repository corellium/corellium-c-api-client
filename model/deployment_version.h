/*
 * deployment_version.h
 *
 * Version and build identity of the running deployment.
 */

#ifndef _deployment_version_H_
#define _deployment_version_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct deployment_version_t deployment_version_t;




typedef struct deployment_version_t {
    char *product_version; // string
    char *coordinator_version; // string
    char *build_commit; // string
    char *build_date; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} deployment_version_t;

__attribute__((deprecated)) deployment_version_t *deployment_version_create(
    char *product_version,
    char *coordinator_version,
    char *build_commit,
    char *build_date
);

void deployment_version_free(deployment_version_t *deployment_version);

deployment_version_t *deployment_version_parseFromJSON(cJSON *deployment_versionJSON);

cJSON *deployment_version_convertToJSON(deployment_version_t *deployment_version);

#endif /* _deployment_version_H_ */

