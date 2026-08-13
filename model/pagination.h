/*
 * pagination.h
 *
 * 
 */

#ifndef _pagination_H_
#define _pagination_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct pagination_t pagination_t;




typedef struct pagination_t {
    double current_page; //numeric
    double total_pages; //numeric
    double total_items; //numeric
    double items_per_page; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} pagination_t;

__attribute__((deprecated)) pagination_t *pagination_create(
    double current_page,
    double total_pages,
    double total_items,
    double items_per_page
);

void pagination_free(pagination_t *pagination);

pagination_t *pagination_parseFromJSON(cJSON *paginationJSON);

cJSON *pagination_convertToJSON(pagination_t *pagination);

#endif /* _pagination_H_ */

