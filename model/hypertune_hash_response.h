/*
 * hypertune_hash_response.h
 *
 * 
 */

#ifndef _hypertune_hash_response_H_
#define _hypertune_hash_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct hypertune_hash_response_t hypertune_hash_response_t;




typedef struct hypertune_hash_response_t {
    char *hash; // string

    int _library_owned; // Is the library responsible for freeing this object?
} hypertune_hash_response_t;

__attribute__((deprecated)) hypertune_hash_response_t *hypertune_hash_response_create(
    char *hash
);

void hypertune_hash_response_free(hypertune_hash_response_t *hypertune_hash_response);

hypertune_hash_response_t *hypertune_hash_response_parseFromJSON(cJSON *hypertune_hash_responseJSON);

cJSON *hypertune_hash_response_convertToJSON(hypertune_hash_response_t *hypertune_hash_response);

#endif /* _hypertune_hash_response_H_ */

