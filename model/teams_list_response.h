/*
 * teams_list_response.h
 *
 * 
 */

#ifndef _teams_list_response_H_
#define _teams_list_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct teams_list_response_t teams_list_response_t;

#include "team.h"



typedef struct teams_list_response_t {
    list_t *results; //nonprimitive container
    double count; //numeric
    double total; //numeric
    double limit; //numeric
    double offset; //numeric
    int has_more; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} teams_list_response_t;

__attribute__((deprecated)) teams_list_response_t *teams_list_response_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
);

void teams_list_response_free(teams_list_response_t *teams_list_response);

teams_list_response_t *teams_list_response_parseFromJSON(cJSON *teams_list_responseJSON);

cJSON *teams_list_response_convertToJSON(teams_list_response_t *teams_list_response);

#endif /* _teams_list_response_H_ */

