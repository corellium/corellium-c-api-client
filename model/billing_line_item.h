/*
 * billing_line_item.h
 *
 * 
 */

#ifndef _billing_line_item_H_
#define _billing_line_item_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct billing_line_item_t billing_line_item_t;




typedef struct billing_line_item_t {
    char *type; // string
    char *name; // string
    char *short_name; // string
    char *description; // string
    double quantity; //numeric
    double unit_cost; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} billing_line_item_t;

__attribute__((deprecated)) billing_line_item_t *billing_line_item_create(
    char *type,
    char *name,
    char *short_name,
    char *description,
    double quantity,
    double unit_cost
);

void billing_line_item_free(billing_line_item_t *billing_line_item);

billing_line_item_t *billing_line_item_parseFromJSON(cJSON *billing_line_itemJSON);

cJSON *billing_line_item_convertToJSON(billing_line_item_t *billing_line_item);

#endif /* _billing_line_item_H_ */

