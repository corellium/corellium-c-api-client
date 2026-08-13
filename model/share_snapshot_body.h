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


// Enum SHARINGTYPE for share_snapshot_body

typedef enum  { corellium_api_share_snapshot_body_SHARINGTYPE_NULL = 0, corellium_api_share_snapshot_body_SHARINGTYPE_publicLink, corellium_api_share_snapshot_body_SHARINGTYPE_domainRestrictedLink, corellium_api_share_snapshot_body_SHARINGTYPE_passwordPublicLink, corellium_api_share_snapshot_body_SHARINGTYPE_emailInvite, corellium_api_share_snapshot_body_SHARINGTYPE_notShared } corellium_api_share_snapshot_body_SHARINGTYPE_e;

char* share_snapshot_body_sharing_type_ToString(corellium_api_share_snapshot_body_SHARINGTYPE_e sharing_type);

corellium_api_share_snapshot_body_SHARINGTYPE_e share_snapshot_body_sharing_type_FromString(char* sharing_type);



typedef struct share_snapshot_body_t {
    corellium_api_share_snapshot_body_SHARINGTYPE_e sharing_type; //enum
    char *password; // string

    int _library_owned; // Is the library responsible for freeing this object?
} share_snapshot_body_t;

__attribute__((deprecated)) share_snapshot_body_t *share_snapshot_body_create(
    corellium_api_share_snapshot_body_SHARINGTYPE_e sharing_type,
    char *password
);

void share_snapshot_body_free(share_snapshot_body_t *share_snapshot_body);

share_snapshot_body_t *share_snapshot_body_parseFromJSON(cJSON *share_snapshot_bodyJSON);

cJSON *share_snapshot_body_convertToJSON(share_snapshot_body_t *share_snapshot_body);

#endif /* _share_snapshot_body_H_ */

