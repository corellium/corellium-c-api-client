/*
 * message_body_any_of_1.h
 *
 * 
 */

#ifndef _message_body_any_of_1_H_
#define _message_body_any_of_1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct message_body_any_of_1_t message_body_any_of_1_t;




typedef struct message_body_any_of_1_t {
    char *raw; // string

    int _library_owned; // Is the library responsible for freeing this object?
} message_body_any_of_1_t;

__attribute__((deprecated)) message_body_any_of_1_t *message_body_any_of_1_create(
    char *raw
);

void message_body_any_of_1_free(message_body_any_of_1_t *message_body_any_of_1);

message_body_any_of_1_t *message_body_any_of_1_parseFromJSON(cJSON *message_body_any_of_1JSON);

cJSON *message_body_any_of_1_convertToJSON(message_body_any_of_1_t *message_body_any_of_1);

#endif /* _message_body_any_of_1_H_ */

