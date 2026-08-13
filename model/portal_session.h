/*
 * portal_session.h
 *
 * 
 */

#ifndef _portal_session_H_
#define _portal_session_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct portal_session_t portal_session_t;




typedef struct portal_session_t {
    char *url; // string

    int _library_owned; // Is the library responsible for freeing this object?
} portal_session_t;

__attribute__((deprecated)) portal_session_t *portal_session_create(
    char *url
);

void portal_session_free(portal_session_t *portal_session);

portal_session_t *portal_session_parseFromJSON(cJSON *portal_sessionJSON);

cJSON *portal_session_convertToJSON(portal_session_t *portal_session);

#endif /* _portal_session_H_ */

