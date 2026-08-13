/*
 * domain_list_item_subscription_history_inner.h
 *
 * 
 */

#ifndef _domain_list_item_subscription_history_inner_H_
#define _domain_list_item_subscription_history_inner_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct domain_list_item_subscription_history_inner_t domain_list_item_subscription_history_inner_t;

#include "domain_list_item_subscription_history_inner_administrator.h"



typedef struct domain_list_item_subscription_history_inner_t {
    char *plan_name; // string
    char *plan_start; //date time
    char *plan_end; //date time
    char *status; // string
    struct domain_list_item_subscription_history_inner_administrator_t *administrator; //model
    char *stripe_link; // string

    int _library_owned; // Is the library responsible for freeing this object?
} domain_list_item_subscription_history_inner_t;

__attribute__((deprecated)) domain_list_item_subscription_history_inner_t *domain_list_item_subscription_history_inner_create(
    char *plan_name,
    char *plan_start,
    char *plan_end,
    char *status,
    domain_list_item_subscription_history_inner_administrator_t *administrator,
    char *stripe_link
);

void domain_list_item_subscription_history_inner_free(domain_list_item_subscription_history_inner_t *domain_list_item_subscription_history_inner);

domain_list_item_subscription_history_inner_t *domain_list_item_subscription_history_inner_parseFromJSON(cJSON *domain_list_item_subscription_history_innerJSON);

cJSON *domain_list_item_subscription_history_inner_convertToJSON(domain_list_item_subscription_history_inner_t *domain_list_item_subscription_history_inner);

#endif /* _domain_list_item_subscription_history_inner_H_ */

