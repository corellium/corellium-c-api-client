/*
 * extension_list.h
 *
 * 
 */

#ifndef _extension_list_H_
#define _extension_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct extension_list_t extension_list_t;

#include "extension.h"



typedef struct extension_list_t {
    list_t *results; //nonprimitive container
    double count; //numeric
    double total; //numeric
    double limit; //numeric
    double offset; //numeric
    int has_more; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} extension_list_t;

__attribute__((deprecated)) extension_list_t *extension_list_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
);

void extension_list_free(extension_list_t *extension_list);

extension_list_t *extension_list_parseFromJSON(cJSON *extension_listJSON);

cJSON *extension_list_convertToJSON(extension_list_t *extension_list);

#endif /* _extension_list_H_ */

