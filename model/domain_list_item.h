/*
 * domain_list_item.h
 *
 * 
 */

#ifndef _domain_list_item_H_
#define _domain_list_item_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct domain_list_item_t domain_list_item_t;

#include "domain_config.h"
#include "domain_list_item_disabled.h"
#include "domain_list_item_domain_usage_inner.h"
#include "domain_list_item_projects_inner.h"
#include "domain_list_item_quotas.h"
#include "domain_list_item_subscription.h"
#include "domain_list_item_subscription_history_inner.h"
#include "domain_list_item_usage.h"
#include "domain_list_item_users_info_inner.h"



typedef struct domain_list_item_t {
    char *identifier; // string
    char *user_id; // string
    list_t *domain_usage; //nonprimitive container
    double user_count; //numeric
    list_t *users_info; //nonprimitive container
    char *domain; // string
    char *domain_name; // string
    struct domain_list_item_disabled_t *disabled; //model
    struct domain_config_t *config; //model
    struct domain_list_item_quotas_t *quotas; //model
    struct domain_list_item_usage_t *usage; //model
    double created_at; //numeric
    struct domain_list_item_subscription_t *subscription; //model
    list_t *subscription_history; //nonprimitive container
    char *plan_name; // string
    list_t *projects; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} domain_list_item_t;

__attribute__((deprecated)) domain_list_item_t *domain_list_item_create(
    char *identifier,
    char *user_id,
    list_t *domain_usage,
    double user_count,
    list_t *users_info,
    char *domain,
    char *domain_name,
    domain_list_item_disabled_t *disabled,
    domain_config_t *config,
    domain_list_item_quotas_t *quotas,
    domain_list_item_usage_t *usage,
    double created_at,
    domain_list_item_subscription_t *subscription,
    list_t *subscription_history,
    char *plan_name,
    list_t *projects
);

void domain_list_item_free(domain_list_item_t *domain_list_item);

domain_list_item_t *domain_list_item_parseFromJSON(cJSON *domain_list_itemJSON);

cJSON *domain_list_item_convertToJSON(domain_list_item_t *domain_list_item);

#endif /* _domain_list_item_H_ */

