/*
 * share_snapshot_body.h
 *
 * 
 */

#ifndef _share_snapshot_body_H_
#define _share_snapshot_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct share_snapshot_body_t share_snapshot_body_t;

#include "snapshot_sharing_type.h"



typedef struct share_snapshot_body_t {
    corellium_api_snapshot_sharing_type__e sharing_type; //referenced enum
    char *password; // string

    int _library_owned; // Is the library responsible for freeing this object?
} share_snapshot_body_t;

__attribute__((deprecated)) share_snapshot_body_t *share_snapshot_body_create(
    corellium_api_snapshot_sharing_type__e sharing_type,
    char *password
);

void share_snapshot_body_free(share_snapshot_body_t *share_snapshot_body);

share_snapshot_body_t *share_snapshot_body_parseFromJSON(cJSON *share_snapshot_bodyJSON);

cJSON *share_snapshot_body_convertToJSON(share_snapshot_body_t *share_snapshot_body);

#endif /* _share_snapshot_body_H_ */

