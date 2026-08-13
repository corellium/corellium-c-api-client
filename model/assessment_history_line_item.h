/*
 * assessment_history_line_item.h
 *
 * 
 */

#ifndef _assessment_history_line_item_H_
#define _assessment_history_line_item_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct assessment_history_line_item_t assessment_history_line_item_t;




typedef struct assessment_history_line_item_t {
    double date; //numeric
    double complete; //numeric
    double incomplete; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} assessment_history_line_item_t;

__attribute__((deprecated)) assessment_history_line_item_t *assessment_history_line_item_create(
    double date,
    double complete,
    double incomplete
);

void assessment_history_line_item_free(assessment_history_line_item_t *assessment_history_line_item);

assessment_history_line_item_t *assessment_history_line_item_parseFromJSON(cJSON *assessment_history_line_itemJSON);

cJSON *assessment_history_line_item_convertToJSON(assessment_history_line_item_t *assessment_history_line_item);

#endif /* _assessment_history_line_item_H_ */

