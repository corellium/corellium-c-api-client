/*
 * domain_list_item_domain_usage_inner.h
 *
 * 
 */

#ifndef _domain_list_item_domain_usage_inner_H_
#define _domain_list_item_domain_usage_inner_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct domain_list_item_domain_usage_inner_t domain_list_item_domain_usage_inner_t;




typedef struct domain_list_item_domain_usage_inner_t {
    char *domain; // string
    char *month; //date
    double hours; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} domain_list_item_domain_usage_inner_t;

__attribute__((deprecated)) domain_list_item_domain_usage_inner_t *domain_list_item_domain_usage_inner_create(
    char *domain,
    char *month,
    double hours
);

void domain_list_item_domain_usage_inner_free(domain_list_item_domain_usage_inner_t *domain_list_item_domain_usage_inner);

domain_list_item_domain_usage_inner_t *domain_list_item_domain_usage_inner_parseFromJSON(cJSON *domain_list_item_domain_usage_innerJSON);

cJSON *domain_list_item_domain_usage_inner_convertToJSON(domain_list_item_domain_usage_inner_t *domain_list_item_domain_usage_inner);

#endif /* _domain_list_item_domain_usage_inner_H_ */

