/*
 * billing_summary.h
 *
 * 
 */

#ifndef _billing_summary_H_
#define _billing_summary_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct billing_summary_t billing_summary_t;

#include "billing_summary_pending_usage_based.h"



typedef struct billing_summary_t {
    struct billing_summary_pending_usage_based_t *pending_usage_based; //model

    int _library_owned; // Is the library responsible for freeing this object?
} billing_summary_t;

__attribute__((deprecated)) billing_summary_t *billing_summary_create(
    billing_summary_pending_usage_based_t *pending_usage_based
);

void billing_summary_free(billing_summary_t *billing_summary);

billing_summary_t *billing_summary_parseFromJSON(cJSON *billing_summaryJSON);

cJSON *billing_summary_convertToJSON(billing_summary_t *billing_summary);

#endif /* _billing_summary_H_ */

