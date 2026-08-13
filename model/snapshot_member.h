/*
 * snapshot_member.h
 *
 * 
 */

#ifndef _snapshot_member_H_
#define _snapshot_member_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct snapshot_member_t snapshot_member_t;




typedef struct snapshot_member_t {
    char *email; // string
    double invite_sent_at; //numeric
    double shared_on; //numeric
    char *user_id; // string
    char *label; // string

    int _library_owned; // Is the library responsible for freeing this object?
} snapshot_member_t;

__attribute__((deprecated)) snapshot_member_t *snapshot_member_create(
    char *email,
    double invite_sent_at,
    double shared_on,
    char *user_id,
    char *label
);

void snapshot_member_free(snapshot_member_t *snapshot_member);

snapshot_member_t *snapshot_member_parseFromJSON(cJSON *snapshot_memberJSON);

cJSON *snapshot_member_convertToJSON(snapshot_member_t *snapshot_member);

#endif /* _snapshot_member_H_ */

