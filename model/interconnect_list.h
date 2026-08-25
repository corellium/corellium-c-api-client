/*
 * interconnect_list.h
 *
 * 
 */

#ifndef _interconnect_list_H_
#define _interconnect_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct interconnect_list_t interconnect_list_t;

#include "interconnect.h"



typedef struct interconnect_list_t {
    list_t *results; //nonprimitive container
    double count; //numeric
    double total; //numeric
    double limit; //numeric
    double offset; //numeric
    int has_more; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} interconnect_list_t;

__attribute__((deprecated)) interconnect_list_t *interconnect_list_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
);

void interconnect_list_free(interconnect_list_t *interconnect_list);

interconnect_list_t *interconnect_list_parseFromJSON(cJSON *interconnect_listJSON);

cJSON *interconnect_list_convertToJSON(interconnect_list_t *interconnect_list);

#endif /* _interconnect_list_H_ */

