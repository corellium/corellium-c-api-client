/*
 * message_body_any_of.h
 *
 * 
 */

#ifndef _message_body_any_of_H_
#define _message_body_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct message_body_any_of_t message_body_any_of_t;




typedef struct message_body_any_of_t {
    char *number; // string
    char *message; // string

    int _library_owned; // Is the library responsible for freeing this object?
} message_body_any_of_t;

__attribute__((deprecated)) message_body_any_of_t *message_body_any_of_create(
    char *number,
    char *message
);

void message_body_any_of_free(message_body_any_of_t *message_body_any_of);

message_body_any_of_t *message_body_any_of_parseFromJSON(cJSON *message_body_any_ofJSON);

cJSON *message_body_any_of_convertToJSON(message_body_any_of_t *message_body_any_of);

#endif /* _message_body_any_of_H_ */

