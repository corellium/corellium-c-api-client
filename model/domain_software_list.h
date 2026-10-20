/*
 * domain_software_list.h
 *
 * 
 */

#ifndef _domain_software_list_H_
#define _domain_software_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct domain_software_list_t domain_software_list_t;

#include "domain_software.h"



typedef struct domain_software_list_t {
    list_t *results; //nonprimitive container
    double count; //numeric
    double total; //numeric
    double limit; //numeric
    double offset; //numeric
    int has_more; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} domain_software_list_t;

__attribute__((deprecated)) domain_software_list_t *domain_software_list_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
);

void domain_software_list_free(domain_software_list_t *domain_software_list);

domain_software_list_t *domain_software_list_parseFromJSON(cJSON *domain_software_listJSON);

cJSON *domain_software_list_convertToJSON(domain_software_list_t *domain_software_list);

#endif /* _domain_software_list_H_ */

