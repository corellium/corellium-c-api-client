/*
 * billing_summary_pending_usage_based.h
 *
 * Pending usage-based bill report. Null unless the domain bills by usage.
 */

#ifndef _billing_summary_pending_usage_based_H_
#define _billing_summary_pending_usage_based_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct billing_summary_pending_usage_based_t billing_summary_pending_usage_based_t;

#include "billing_line_item.h"



typedef struct billing_summary_pending_usage_based_t {
    double last_bill_date; //numeric
    double next_bill_date; //numeric
    double billing_threshold; //numeric
    char *total; // string
    list_t *line_items; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} billing_summary_pending_usage_based_t;

__attribute__((deprecated)) billing_summary_pending_usage_based_t *billing_summary_pending_usage_based_create(
    double last_bill_date,
    double next_bill_date,
    double billing_threshold,
    char *total,
    list_t *line_items
);

void billing_summary_pending_usage_based_free(billing_summary_pending_usage_based_t *billing_summary_pending_usage_based);

billing_summary_pending_usage_based_t *billing_summary_pending_usage_based_parseFromJSON(cJSON *billing_summary_pending_usage_basedJSON);

cJSON *billing_summary_pending_usage_based_convertToJSON(billing_summary_pending_usage_based_t *billing_summary_pending_usage_based);

#endif /* _billing_summary_pending_usage_based_H_ */

