/*
 * domain_list_item_projects_inner_instances_inner_images_inner.h
 *
 * 
 */

#ifndef _domain_list_item_projects_inner_instances_inner_images_inner_H_
#define _domain_list_item_projects_inner_instances_inner_images_inner_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct domain_list_item_projects_inner_instances_inner_images_inner_t domain_list_item_projects_inner_instances_inner_images_inner_t;




typedef struct domain_list_item_projects_inner_instances_inner_images_inner_t {
    char *identifier; // string
    char *type; // string
    char *name; // string
    double size; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} domain_list_item_projects_inner_instances_inner_images_inner_t;

__attribute__((deprecated)) domain_list_item_projects_inner_instances_inner_images_inner_t *domain_list_item_projects_inner_instances_inner_images_inner_create(
    char *identifier,
    char *type,
    char *name,
    double size
);

void domain_list_item_projects_inner_instances_inner_images_inner_free(domain_list_item_projects_inner_instances_inner_images_inner_t *domain_list_item_projects_inner_instances_inner_images_inner);

domain_list_item_projects_inner_instances_inner_images_inner_t *domain_list_item_projects_inner_instances_inner_images_inner_parseFromJSON(cJSON *domain_list_item_projects_inner_instances_inner_images_innerJSON);

cJSON *domain_list_item_projects_inner_instances_inner_images_inner_convertToJSON(domain_list_item_projects_inner_instances_inner_images_inner_t *domain_list_item_projects_inner_instances_inner_images_inner);

#endif /* _domain_list_item_projects_inner_instances_inner_images_inner_H_ */

