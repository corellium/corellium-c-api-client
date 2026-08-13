/*
 * domain_list_item_subscription_history_inner_administrator.h
 *
 * Administrator who manages this subscription.
 */

#ifndef _domain_list_item_subscription_history_inner_administrator_H_
#define _domain_list_item_subscription_history_inner_administrator_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct domain_list_item_subscription_history_inner_administrator_t domain_list_item_subscription_history_inner_administrator_t;




typedef struct domain_list_item_subscription_history_inner_administrator_t {
    char *name; // string
    char *email; // string

    int _library_owned; // Is the library responsible for freeing this object?
} domain_list_item_subscription_history_inner_administrator_t;

__attribute__((deprecated)) domain_list_item_subscription_history_inner_administrator_t *domain_list_item_subscription_history_inner_administrator_create(
    char *name,
    char *email
);

void domain_list_item_subscription_history_inner_administrator_free(domain_list_item_subscription_history_inner_administrator_t *domain_list_item_subscription_history_inner_administrator);

domain_list_item_subscription_history_inner_administrator_t *domain_list_item_subscription_history_inner_administrator_parseFromJSON(cJSON *domain_list_item_subscription_history_inner_administratorJSON);

cJSON *domain_list_item_subscription_history_inner_administrator_convertToJSON(domain_list_item_subscription_history_inner_administrator_t *domain_list_item_subscription_history_inner_administrator);

#endif /* _domain_list_item_subscription_history_inner_administrator_H_ */

