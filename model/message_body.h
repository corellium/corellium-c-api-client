/*
 * message_body.h
 *
 * 
 */

#ifndef _message_body_H_
#define _message_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct message_body_t message_body_t;

#include "message_body_any_of.h"
#include "message_body_any_of_1.h"



typedef struct message_body_t {
    char *number; // string
    char *message; // string
    char *raw; // string

    int _library_owned; // Is the library responsible for freeing this object?
} message_body_t;

__attribute__((deprecated)) message_body_t *message_body_create(
    char *number,
    char *message,
    char *raw
);

void message_body_free(message_body_t *message_body);

message_body_t *message_body_parseFromJSON(cJSON *message_bodyJSON);

cJSON *message_body_convertToJSON(message_body_t *message_body);

#endif /* _message_body_H_ */

