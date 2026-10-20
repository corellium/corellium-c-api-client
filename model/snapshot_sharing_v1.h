/*
 * snapshot_sharing_v1.h
 *
 * 
 */

#ifndef _snapshot_sharing_v1_H_
#define _snapshot_sharing_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct snapshot_sharing_v1_t snapshot_sharing_v1_t;

#include "snapshot_member_v1.h"
#include "snapshot_owner_v1.h"

// Enum SHARINGTYPE for snapshot_sharing_v1

typedef enum  { corellium_api_snapshot_sharing_v1_SHARINGTYPE_NULL = 0, corellium_api_snapshot_sharing_v1_SHARINGTYPE_publicLink, corellium_api_snapshot_sharing_v1_SHARINGTYPE_domainRestrictedLink, corellium_api_snapshot_sharing_v1_SHARINGTYPE_passwordPublicLink, corellium_api_snapshot_sharing_v1_SHARINGTYPE_emailInvite } corellium_api_snapshot_sharing_v1_SHARINGTYPE_e;

char* snapshot_sharing_v1_sharing_type_ToString(corellium_api_snapshot_sharing_v1_SHARINGTYPE_e sharing_type);

corellium_api_snapshot_sharing_v1_SHARINGTYPE_e snapshot_sharing_v1_sharing_type_FromString(char* sharing_type);



typedef struct snapshot_sharing_v1_t {
    corellium_api_snapshot_sharing_v1_SHARINGTYPE_e sharing_type; //enum
    struct snapshot_owner_v1_t *shared_by; //model
    list_t *members; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} snapshot_sharing_v1_t;

__attribute__((deprecated)) snapshot_sharing_v1_t *snapshot_sharing_v1_create(
    corellium_api_snapshot_sharing_v1_SHARINGTYPE_e sharing_type,
    snapshot_owner_v1_t *shared_by,
    list_t *members
);

void snapshot_sharing_v1_free(snapshot_sharing_v1_t *snapshot_sharing_v1);

snapshot_sharing_v1_t *snapshot_sharing_v1_parseFromJSON(cJSON *snapshot_sharing_v1JSON);

cJSON *snapshot_sharing_v1_convertToJSON(snapshot_sharing_v1_t *snapshot_sharing_v1);

#endif /* _snapshot_sharing_v1_H_ */

