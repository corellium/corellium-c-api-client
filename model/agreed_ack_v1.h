/*
 * agreed_ack_v1.h
 *
 * 
 */

#ifndef _agreed_ack_v1_H_
#define _agreed_ack_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct agreed_ack_v1_t agreed_ack_v1_t;




typedef struct agreed_ack_v1_t {
    char *agreed_to_terms; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} agreed_ack_v1_t;

__attribute__((deprecated)) agreed_ack_v1_t *agreed_ack_v1_create(
    char *agreed_to_terms
);

void agreed_ack_v1_free(agreed_ack_v1_t *agreed_ack_v1);

agreed_ack_v1_t *agreed_ack_v1_parseFromJSON(cJSON *agreed_ack_v1JSON);

cJSON *agreed_ack_v1_convertToJSON(agreed_ack_v1_t *agreed_ack_v1);

#endif /* _agreed_ack_v1_H_ */

