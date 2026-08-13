/*
 * shared_snapshots_info_schema.h
 *
 * 
 */

#ifndef _shared_snapshots_info_schema_H_
#define _shared_snapshots_info_schema_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct shared_snapshots_info_schema_t shared_snapshots_info_schema_t;

#include "snapshot_owner_schema.h"
#include "snapshot_sharing.h"
#include "snapshot_status_schema.h"

// Enum SHARINGTYPE for shared_snapshots_info_schema

typedef enum  { corellium_api_shared_snapshots_info_schema_SHARINGTYPE_NULL = 0, corellium_api_shared_snapshots_info_schema_SHARINGTYPE_publicLink, corellium_api_shared_snapshots_info_schema_SHARINGTYPE_domainRestrictedLink, corellium_api_shared_snapshots_info_schema_SHARINGTYPE_passwordPublicLink, corellium_api_shared_snapshots_info_schema_SHARINGTYPE_emailInvite, corellium_api_shared_snapshots_info_schema_SHARINGTYPE_notShared } corellium_api_shared_snapshots_info_schema_SHARINGTYPE_e;

char* shared_snapshots_info_schema_sharing_type_ToString(corellium_api_shared_snapshots_info_schema_SHARINGTYPE_e sharing_type);

corellium_api_shared_snapshots_info_schema_SHARINGTYPE_e shared_snapshots_info_schema_sharing_type_FromString(char* sharing_type);



typedef struct shared_snapshots_info_schema_t {
    char *shared_on; //date time
    char *shared_with_member; // string
    corellium_api_shared_snapshots_info_schema_SHARINGTYPE_e sharing_type; //enum
    struct snapshot_owner_schema_t *shared_by; //model
    char *id; // string
    double date; //numeric
    double hw_pac; //numeric
    char *instance; // string
    int live; //boolean
    int local; //boolean
    char *model; // string
    char *type; // string
    char *name; // string
    struct snapshot_status_schema_t *status; //model
    int fresh; //boolean
    struct snapshot_sharing_t *sharing; //model

    int _library_owned; // Is the library responsible for freeing this object?
} shared_snapshots_info_schema_t;

__attribute__((deprecated)) shared_snapshots_info_schema_t *shared_snapshots_info_schema_create(
    char *shared_on,
    char *shared_with_member,
    corellium_api_shared_snapshots_info_schema_SHARINGTYPE_e sharing_type,
    snapshot_owner_schema_t *shared_by,
    char *id,
    double date,
    double hw_pac,
    char *instance,
    int live,
    int local,
    char *model,
    char *type,
    char *name,
    snapshot_status_schema_t *status,
    int fresh,
    snapshot_sharing_t *sharing
);

void shared_snapshots_info_schema_free(shared_snapshots_info_schema_t *shared_snapshots_info_schema);

shared_snapshots_info_schema_t *shared_snapshots_info_schema_parseFromJSON(cJSON *shared_snapshots_info_schemaJSON);

cJSON *shared_snapshots_info_schema_convertToJSON(shared_snapshots_info_schema_t *shared_snapshots_info_schema);

#endif /* _shared_snapshots_info_schema_H_ */

