/*
 * domain_info.h
 *
 * 
 */

#ifndef _domain_info_H_
#define _domain_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct domain_info_t domain_info_t;

#include "domain_info_domain_info.h"



typedef struct domain_info_t {
    struct domain_info_domain_info_t *domain_info; //model

    int _library_owned; // Is the library responsible for freeing this object?
} domain_info_t;

__attribute__((deprecated)) domain_info_t *domain_info_create(
    domain_info_domain_info_t *domain_info
);

void domain_info_free(domain_info_t *domain_info);

domain_info_t *domain_info_parseFromJSON(cJSON *domain_infoJSON);

cJSON *domain_info_convertToJSON(domain_info_t *domain_info);

#endif /* _domain_info_H_ */

