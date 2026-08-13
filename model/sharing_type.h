/*
 * sharing_type.h
 *
 * Snapshot sharing type.
 */

#ifndef _sharing_type_H_
#define _sharing_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct sharing_type_t sharing_type_t;


// Enum  for sharing_type

typedef enum { corellium_api_sharing_type__NULL = 0, corellium_api_sharing_type__publicLink, corellium_api_sharing_type__domainRestrictedLink, corellium_api_sharing_type__passwordPublicLink, corellium_api_sharing_type__emailInvite } corellium_api_sharing_type__e;

char* sharing_type_sharing_type_ToString(corellium_api_sharing_type__e sharing_type);

corellium_api_sharing_type__e sharing_type_sharing_type_FromString(char* sharing_type);

cJSON *sharing_type_convertToJSON(corellium_api_sharing_type__e sharing_type);

corellium_api_sharing_type__e sharing_type_parseFromJSON(cJSON *sharing_typeJSON);

#endif /* _sharing_type_H_ */

