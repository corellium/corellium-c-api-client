/*
 * cluster_snapshot.h
 *
 * 
 */

#ifndef _cluster_snapshot_H_
#define _cluster_snapshot_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cluster_snapshot_t cluster_snapshot_t;

#include "cluster_snapshot_metadata.h"
#include "cluster_snapshot_status.h"

// Enum TYPE for cluster_snapshot

typedef enum  { corellium_api_cluster_snapshot_TYPE_NULL = 0, corellium_api_cluster_snapshot_TYPE_iscsi, corellium_api_cluster_snapshot_TYPE_local, corellium_api_cluster_snapshot_TYPE_s3 } corellium_api_cluster_snapshot_TYPE_e;

char* cluster_snapshot_type_ToString(corellium_api_cluster_snapshot_TYPE_e type);

corellium_api_cluster_snapshot_TYPE_e cluster_snapshot_type_FromString(char* type);



typedef struct cluster_snapshot_t {
    char *id; // string
    char *name; // string
    char *volume; // string
    char *instance; // string
    struct cluster_snapshot_status_t *status; //model
    corellium_api_cluster_snapshot_TYPE_e type; //enum
    char *compute_node; // string
    struct cluster_snapshot_metadata_t *metadata; //model
    char *created_at; //date time
    char *updated_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} cluster_snapshot_t;

__attribute__((deprecated)) cluster_snapshot_t *cluster_snapshot_create(
    char *id,
    char *name,
    char *volume,
    char *instance,
    cluster_snapshot_status_t *status,
    corellium_api_cluster_snapshot_TYPE_e type,
    char *compute_node,
    cluster_snapshot_metadata_t *metadata,
    char *created_at,
    char *updated_at
);

void cluster_snapshot_free(cluster_snapshot_t *cluster_snapshot);

cluster_snapshot_t *cluster_snapshot_parseFromJSON(cJSON *cluster_snapshotJSON);

cJSON *cluster_snapshot_convertToJSON(cluster_snapshot_t *cluster_snapshot);

#endif /* _cluster_snapshot_H_ */

