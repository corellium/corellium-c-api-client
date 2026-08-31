/*
 * cluster_snapshot_metadata.h
 *
 * Snapshot metadata.
 */

#ifndef _cluster_snapshot_metadata_H_
#define _cluster_snapshot_metadata_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_snapshot_metadata_t cluster_snapshot_metadata_t;

#include "any_type.h"
#include "cluster_snapshot_metadata_boot_options.h"
#include "object.h"



typedef struct cluster_snapshot_metadata_t {
    int live; //boolean
    int fresh; //boolean
    double hw_pac; //numeric
    int springboard; //boolean
    struct cluster_snapshot_metadata_boot_options_t *boot_options; //model
    object_t *device; //object
    char *flavor; // string
    char *os_version; // string
    char *os_build; // string
    char *patches; // string
    double cpid; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_snapshot_metadata_t;

__attribute__((deprecated)) cluster_snapshot_metadata_t *cluster_snapshot_metadata_create(
    int live,
    int fresh,
    double hw_pac,
    int springboard,
    cluster_snapshot_metadata_boot_options_t *boot_options,
    object_t *device,
    char *flavor,
    char *os_version,
    char *os_build,
    char *patches,
    double cpid
);

void cluster_snapshot_metadata_free(cluster_snapshot_metadata_t *cluster_snapshot_metadata);

cluster_snapshot_metadata_t *cluster_snapshot_metadata_parseFromJSON(cJSON *cluster_snapshot_metadataJSON);

cJSON *cluster_snapshot_metadata_convertToJSON(cluster_snapshot_metadata_t *cluster_snapshot_metadata);

#endif /* _cluster_snapshot_metadata_H_ */

