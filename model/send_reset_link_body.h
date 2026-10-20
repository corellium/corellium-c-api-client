/*
 * send_reset_link_body.h
 *
 * 
 */

#ifndef _send_reset_link_body_H_
#define _send_reset_link_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct send_reset_link_body_t send_reset_link_body_t;




typedef struct send_reset_link_body_t {
    char *email; // string

    int _library_owned; // Is the library responsible for freeing this object?
} send_reset_link_body_t;

__attribute__((deprecated)) send_reset_link_body_t *send_reset_link_body_create(
    char *email
);

void send_reset_link_body_free(send_reset_link_body_t *send_reset_link_body);

send_reset_link_body_t *send_reset_link_body_parseFromJSON(cJSON *send_reset_link_bodyJSON);

cJSON *send_reset_link_body_convertToJSON(send_reset_link_body_t *send_reset_link_body);

#endif /* _send_reset_link_body_H_ */

