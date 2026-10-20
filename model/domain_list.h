/*
 * domain_list.h
 *
 * 
 */

#ifndef _domain_list_H_
#define _domain_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct domain_list_t domain_list_t;

#include "domain_list_item.h"
#include "domain_list_usage.h"



typedef struct domain_list_t {
    double count; //numeric
    double page; //numeric
    double per_page; //numeric
    list_t *items; //nonprimitive container
    struct domain_list_usage_t *usage; //model

    int _library_owned; // Is the library responsible for freeing this object?
} domain_list_t;

__attribute__((deprecated)) domain_list_t *domain_list_create(
    double count,
    double page,
    double per_page,
    list_t *items,
    domain_list_usage_t *usage
);

void domain_list_free(domain_list_t *domain_list);

domain_list_t *domain_list_parseFromJSON(cJSON *domain_listJSON);

cJSON *domain_list_convertToJSON(domain_list_t *domain_list);

#endif /* _domain_list_H_ */

