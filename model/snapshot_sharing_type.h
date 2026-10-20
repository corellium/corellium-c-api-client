/*
 * snapshot_sharing_type.h
 *
 * Who can use a shared snapshot: - &#x60;publicLink&#x60;: anyone who has the access code. - &#x60;domainRestrictedLink&#x60;: only signed-in users in the owner&#39;s domain who have the access code. - &#x60;passwordPublicLink&#x60;: anyone who has the access code and the password. - &#x60;emailInvite&#x60;: only the people listed as members (see &#x60;v3SetSnapshotPermissions&#x60;). - &#x60;notShared&#x60;: sharing is turned off.  Each type must also be allowed by your domain&#39;s snapshot sharing settings (&#x60;PATCH /v3/domain&#x60;); a type that is not allowed is refused with 403.
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

