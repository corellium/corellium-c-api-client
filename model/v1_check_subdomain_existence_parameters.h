/*
 * v1_check_subdomain_existence_parameters.h
 *
 * 
 */

#ifndef _v1_check_subdomain_existence_parameters_H_
#define _v1_check_subdomain_existence_parameters_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_check_subdomain_existence_parameters_t v1_check_subdomain_existence_parameters_t;




typedef struct v1_check_subdomain_existence_parameters_t {
    char *domain; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_check_subdomain_existence_parameters_t;

__attribute__((deprecated)) v1_check_subdomain_existence_parameters_t *v1_check_subdomain_existence_parameters_create(
    char *domain
);

void v1_check_subdomain_existence_parameters_free(v1_check_subdomain_existence_parameters_t *v1_check_subdomain_existence_parameters);

v1_check_subdomain_existence_parameters_t *v1_check_subdomain_existence_parameters_parseFromJSON(cJSON *v1_check_subdomain_existence_parametersJSON);

cJSON *v1_check_subdomain_existence_parameters_convertToJSON(v1_check_subdomain_existence_parameters_t *v1_check_subdomain_existence_parameters);

#endif /* _v1_check_subdomain_existence_parameters_H_ */

