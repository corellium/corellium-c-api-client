/*
 * firmware_list.h
 *
 * 
 */

#ifndef _firmware_list_H_
#define _firmware_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct firmware_list_t firmware_list_t;

#include "firmware.h"



typedef struct firmware_list_t {
    list_t *results; //nonprimitive container
    double count; //numeric
    double total; //numeric
    double limit; //numeric
    double offset; //numeric
    int has_more; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} firmware_list_t;

__attribute__((deprecated)) firmware_list_t *firmware_list_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
);

void firmware_list_free(firmware_list_t *firmware_list);

firmware_list_t *firmware_list_parseFromJSON(cJSON *firmware_listJSON);

cJSON *firmware_list_convertToJSON(firmware_list_t *firmware_list);

#endif /* _firmware_list_H_ */

