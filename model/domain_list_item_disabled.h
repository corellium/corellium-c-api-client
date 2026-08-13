/*
 * domain_list_item_disabled.h
 *
 * Disabled state (null if domain is active).
 */

#ifndef _domain_list_item_disabled_H_
#define _domain_list_item_disabled_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct domain_list_item_disabled_t domain_list_item_disabled_t;


// Enum TYPE for domain_list_item_disabled

typedef enum  { corellium_api_domain_list_item_disabled_TYPE_NULL = 0, corellium_api_domain_list_item_disabled_TYPE_SubscriptionCanceled, corellium_api_domain_list_item_disabled_TYPE_SubscriptionPaused, corellium_api_domain_list_item_disabled_TYPE_TrialEnded, corellium_api_domain_list_item_disabled_TYPE_PastDue, corellium_api_domain_list_item_disabled_TYPE_SubscriptionPending, corellium_api_domain_list_item_disabled_TYPE_AllocatedHoursExpended } corellium_api_domain_list_item_disabled_TYPE_e;

char* domain_list_item_disabled_type_ToString(corellium_api_domain_list_item_disabled_TYPE_e type);

corellium_api_domain_list_item_disabled_TYPE_e domain_list_item_disabled_type_FromString(char* type);



typedef struct domain_list_item_disabled_t {
    corellium_api_domain_list_item_disabled_TYPE_e type; //enum

    int _library_owned; // Is the library responsible for freeing this object?
} domain_list_item_disabled_t;

__attribute__((deprecated)) domain_list_item_disabled_t *domain_list_item_disabled_create(
    corellium_api_domain_list_item_disabled_TYPE_e type
);

void domain_list_item_disabled_free(domain_list_item_disabled_t *domain_list_item_disabled);

domain_list_item_disabled_t *domain_list_item_disabled_parseFromJSON(cJSON *domain_list_item_disabledJSON);

cJSON *domain_list_item_disabled_convertToJSON(domain_list_item_disabled_t *domain_list_item_disabled);

#endif /* _domain_list_item_disabled_H_ */

