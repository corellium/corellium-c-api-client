/*
 * enable_sslsplit_body.h
 *
 * 
 */

#ifndef _enable_sslsplit_body_H_
#define _enable_sslsplit_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct enable_sslsplit_body_t enable_sslsplit_body_t;




typedef struct enable_sslsplit_body_t {
    int truncate_pcap; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} enable_sslsplit_body_t;

__attribute__((deprecated)) enable_sslsplit_body_t *enable_sslsplit_body_create(
    int truncate_pcap
);

void enable_sslsplit_body_free(enable_sslsplit_body_t *enable_sslsplit_body);

enable_sslsplit_body_t *enable_sslsplit_body_parseFromJSON(cJSON *enable_sslsplit_bodyJSON);

cJSON *enable_sslsplit_body_convertToJSON(enable_sslsplit_body_t *enable_sslsplit_body);

#endif /* _enable_sslsplit_body_H_ */

