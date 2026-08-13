/*
 * service_endpoint_schema.h
 *
 * 
 */

#ifndef _service_endpoint_schema_H_
#define _service_endpoint_schema_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct service_endpoint_schema_t service_endpoint_schema_t;




typedef struct service_endpoint_schema_t {
    char *service_name; // string
    char *path; // string
    char *method; // string
    list_t *permissions; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} service_endpoint_schema_t;

__attribute__((deprecated)) service_endpoint_schema_t *service_endpoint_schema_create(
    char *service_name,
    char *path,
    char *method,
    list_t *permissions
);

void service_endpoint_schema_free(service_endpoint_schema_t *service_endpoint_schema);

service_endpoint_schema_t *service_endpoint_schema_parseFromJSON(cJSON *service_endpoint_schemaJSON);

cJSON *service_endpoint_schema_convertToJSON(service_endpoint_schema_t *service_endpoint_schema);

#endif /* _service_endpoint_schema_H_ */

