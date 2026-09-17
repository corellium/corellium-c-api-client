/*
 * model_firmware_springboard_snapshot_volumes_inner.h
 *
 * 
 */

#ifndef _model_firmware_springboard_snapshot_volumes_inner_H_
#define _model_firmware_springboard_snapshot_volumes_inner_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct model_firmware_springboard_snapshot_volumes_inner_t model_firmware_springboard_snapshot_volumes_inner_t;




typedef struct model_firmware_springboard_snapshot_volumes_inner_t {
    double nand; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} model_firmware_springboard_snapshot_volumes_inner_t;

__attribute__((deprecated)) model_firmware_springboard_snapshot_volumes_inner_t *model_firmware_springboard_snapshot_volumes_inner_create(
    double nand
);

void model_firmware_springboard_snapshot_volumes_inner_free(model_firmware_springboard_snapshot_volumes_inner_t *model_firmware_springboard_snapshot_volumes_inner);

model_firmware_springboard_snapshot_volumes_inner_t *model_firmware_springboard_snapshot_volumes_inner_parseFromJSON(cJSON *model_firmware_springboard_snapshot_volumes_innerJSON);

cJSON *model_firmware_springboard_snapshot_volumes_inner_convertToJSON(model_firmware_springboard_snapshot_volumes_inner_t *model_firmware_springboard_snapshot_volumes_inner);

#endif /* _model_firmware_springboard_snapshot_volumes_inner_H_ */

