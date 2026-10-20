/*
 * register_service_body.h
 *
 * 
 */

#ifndef _register_service_body_H_
#define _register_service_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct register_service_body_t register_service_body_t;

#include "service_endpoint_schema.h"



typedef struct register_service_body_t {
    char *password; // string
    char *node_id; // string
    char *address; // string
    char *service_name; // string
    list_t *endpoints; //nonprimitive container
    char *identity_key; // string
    char *ca_cert; // string
    char *cert_fingerprint; // string

    int _library_owned; // Is the library responsible for freeing this object?
} register_service_body_t;

__attribute__((deprecated)) register_service_body_t *register_service_body_create(
    char *password,
    char *node_id,
    char *address,
    char *service_name,
    list_t *endpoints,
    char *identity_key,
    char *ca_cert,
    char *cert_fingerprint
);

void register_service_body_free(register_service_body_t *register_service_body);

register_service_body_t *register_service_body_parseFromJSON(cJSON *register_service_bodyJSON);

cJSON *register_service_body_convertToJSON(register_service_body_t *register_service_body);

#endif /* _register_service_body_H_ */

