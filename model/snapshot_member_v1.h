/*
 * snapshot_member_v1.h
 *
 * 
 */

#ifndef _snapshot_member_v1_H_
#define _snapshot_member_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct snapshot_member_v1_t snapshot_member_v1_t;




typedef struct snapshot_member_v1_t {
    char *email; // string
    double invite_sent_at; //numeric
    double shared_on; //numeric
    char *user_id; // string
    char *label; // string

    int _library_owned; // Is the library responsible for freeing this object?
} snapshot_member_v1_t;

__attribute__((deprecated)) snapshot_member_v1_t *snapshot_member_v1_create(
    char *email,
    double invite_sent_at,
    double shared_on,
    char *user_id,
    char *label
);

void snapshot_member_v1_free(snapshot_member_v1_t *snapshot_member_v1);

snapshot_member_v1_t *snapshot_member_v1_parseFromJSON(cJSON *snapshot_member_v1JSON);

cJSON *snapshot_member_v1_convertToJSON(snapshot_member_v1_t *snapshot_member_v1);

#endif /* _snapshot_member_v1_H_ */

