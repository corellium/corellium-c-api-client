/*
 * service_status_request_body.h
 *
 * 
 */

#ifndef _service_status_request_body_H_
#define _service_status_request_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct service_status_request_body_t service_status_request_body_t;

#include "layout_schema.h"
#include "network_schema.h"
#include "pool_usage_schema.h"
#include "service_status_request_body_vms_inner.h"
#include "sys_info_schema.h"



typedef struct service_status_request_body_t {
    int healthy; //boolean
    char *service_name; // string
    char *address; // string
    char *hostname; // string
    char *node_id; // string
    struct sys_info_schema_t *sys_info; //model
    struct layout_schema_t *layout; //model
    list_t *vms; //nonprimitive container
    struct pool_usage_schema_t *pool_usage; //model
    char *az; // string
    struct network_schema_t *network; //model
    char *ec2_instance_type; // string
    char *op; // string

    int _library_owned; // Is the library responsible for freeing this object?
} service_status_request_body_t;

__attribute__((deprecated)) service_status_request_body_t *service_status_request_body_create(
    int healthy,
    char *service_name,
    char *address,
    char *hostname,
    char *node_id,
    sys_info_schema_t *sys_info,
    layout_schema_t *layout,
    list_t *vms,
    pool_usage_schema_t *pool_usage,
    char *az,
    network_schema_t *network,
    char *ec2_instance_type,
    char *op
);

void service_status_request_body_free(service_status_request_body_t *service_status_request_body);

service_status_request_body_t *service_status_request_body_parseFromJSON(cJSON *service_status_request_bodyJSON);

cJSON *service_status_request_body_convertToJSON(service_status_request_body_t *service_status_request_body);

#endif /* _service_status_request_body_H_ */

