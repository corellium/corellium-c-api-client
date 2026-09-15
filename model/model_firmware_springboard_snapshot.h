/*
 * model_firmware_springboard_snapshot.h
 *
 * Rapid-start snapshot taken at first springboard for this build, if one exists. Lists the storage sizes a snapshot was captured at; divide a size by a partition block size to get the block counts rapid start can be created with.
 */

#ifndef _model_firmware_springboard_snapshot_H_
#define _model_firmware_springboard_snapshot_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct model_firmware_springboard_snapshot_t model_firmware_springboard_snapshot_t;

#include "model_firmware_springboard_snapshot_volumes_inner.h"



typedef struct model_firmware_springboard_snapshot_t {
    list_t *volumes; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} model_firmware_springboard_snapshot_t;

__attribute__((deprecated)) model_firmware_springboard_snapshot_t *model_firmware_springboard_snapshot_create(
    list_t *volumes
);

void model_firmware_springboard_snapshot_free(model_firmware_springboard_snapshot_t *model_firmware_springboard_snapshot);

model_firmware_springboard_snapshot_t *model_firmware_springboard_snapshot_parseFromJSON(cJSON *model_firmware_springboard_snapshotJSON);

cJSON *model_firmware_springboard_snapshot_convertToJSON(model_firmware_springboard_snapshot_t *model_firmware_springboard_snapshot);

#endif /* _model_firmware_springboard_snapshot_H_ */

