/*
 * network_connection_provider_pagination_result.h
 *
 * Network Connection Provider Pagination Result
 */

#ifndef _network_connection_provider_pagination_result_H_
#define _network_connection_provider_pagination_result_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct network_connection_provider_pagination_result_t network_connection_provider_pagination_result_t;

#include "network_connection_provider.h"



typedef struct network_connection_provider_pagination_result_t {
    double total; //numeric
    double count; //numeric
    double limit; //numeric
    double offset; //numeric
    list_t *results; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} network_connection_provider_pagination_result_t;

__attribute__((deprecated)) network_connection_provider_pagination_result_t *network_connection_provider_pagination_result_create(
    double total,
    double count,
    double limit,
    double offset,
    list_t *results
);

void network_connection_provider_pagination_result_free(network_connection_provider_pagination_result_t *network_connection_provider_pagination_result);

network_connection_provider_pagination_result_t *network_connection_provider_pagination_result_parseFromJSON(cJSON *network_connection_provider_pagination_resultJSON);

cJSON *network_connection_provider_pagination_result_convertToJSON(network_connection_provider_pagination_result_t *network_connection_provider_pagination_result);

#endif /* _network_connection_provider_pagination_result_H_ */

