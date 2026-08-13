/*
 * proxy_config.h
 *
 * Represents a Proxy configuration object.
 */

#ifndef _proxy_config_H_
#define _proxy_config_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct proxy_config_t proxy_config_t;




typedef struct proxy_config_t {
    double device_port; //numeric
    int first_available; //boolean
    int expose; //boolean
    double router_port; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} proxy_config_t;

__attribute__((deprecated)) proxy_config_t *proxy_config_create(
    double device_port,
    int first_available,
    int expose,
    double router_port
);

void proxy_config_free(proxy_config_t *proxy_config);

proxy_config_t *proxy_config_parseFromJSON(cJSON *proxy_configJSON);

cJSON *proxy_config_convertToJSON(proxy_config_t *proxy_config);

#endif /* _proxy_config_H_ */

