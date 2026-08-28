/*
 * snapshot_sharing_type.h
 *
 * Snapshot sharing type.
 */

#ifndef _snapshot_sharing_type_H_
#define _snapshot_sharing_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct snapshot_sharing_type_t snapshot_sharing_type_t;


// Enum  for snapshot_sharing_type

typedef enum { corellium_api_snapshot_sharing_type__NULL = 0, corellium_api_snapshot_sharing_type__publicLink, corellium_api_snapshot_sharing_type__domainRestrictedLink, corellium_api_snapshot_sharing_type__passwordPublicLink, corellium_api_snapshot_sharing_type__emailInvite, corellium_api_snapshot_sharing_type__notShared } corellium_api_snapshot_sharing_type__e;

char* snapshot_sharing_type_snapshot_sharing_type_ToString(corellium_api_snapshot_sharing_type__e snapshot_sharing_type);

corellium_api_snapshot_sharing_type__e snapshot_sharing_type_snapshot_sharing_type_FromString(char* snapshot_sharing_type);

cJSON *snapshot_sharing_type_convertToJSON(corellium_api_snapshot_sharing_type__e snapshot_sharing_type);

corellium_api_snapshot_sharing_type__e snapshot_sharing_type_parseFromJSON(cJSON *snapshot_sharing_typeJSON);

#endif /* _snapshot_sharing_type_H_ */

