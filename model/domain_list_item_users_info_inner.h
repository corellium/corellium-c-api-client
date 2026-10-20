/*
 * domain_list_item_users_info_inner.h
 *
 * 
 */

#ifndef _domain_list_item_users_info_inner_H_
#define _domain_list_item_users_info_inner_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct domain_list_item_users_info_inner_t domain_list_item_users_info_inner_t;




typedef struct domain_list_item_users_info_inner_t {
    char *id; // string
    char *label; // string
    char *name; // string
    char *email; // string
    int administrator; //boolean
    int cluster_administrator; //boolean
    char *last_login; //date time
    double teams; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} domain_list_item_users_info_inner_t;

__attribute__((deprecated)) domain_list_item_users_info_inner_t *domain_list_item_users_info_inner_create(
    char *id,
    char *label,
    char *name,
    char *email,
    int administrator,
    int cluster_administrator,
    char *last_login,
    double teams
);

void domain_list_item_users_info_inner_free(domain_list_item_users_info_inner_t *domain_list_item_users_info_inner);

domain_list_item_users_info_inner_t *domain_list_item_users_info_inner_parseFromJSON(cJSON *domain_list_item_users_info_innerJSON);

cJSON *domain_list_item_users_info_inner_convertToJSON(domain_list_item_users_info_inner_t *domain_list_item_users_info_inner);

#endif /* _domain_list_item_users_info_inner_H_ */

