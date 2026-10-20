/*
 * domain_config_trial_extension.h
 *
 * 
 */

#ifndef _domain_config_trial_extension_H_
#define _domain_config_trial_extension_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct domain_config_trial_extension_t domain_config_trial_extension_t;




typedef struct domain_config_trial_extension_t {
    double duration; //numeric
    char *reason; // string
    int denied; //boolean
    char *denied_reason; // string

    int _library_owned; // Is the library responsible for freeing this object?
} domain_config_trial_extension_t;

__attribute__((deprecated)) domain_config_trial_extension_t *domain_config_trial_extension_create(
    double duration,
    char *reason,
    int denied,
    char *denied_reason
);

void domain_config_trial_extension_free(domain_config_trial_extension_t *domain_config_trial_extension);

domain_config_trial_extension_t *domain_config_trial_extension_parseFromJSON(cJSON *domain_config_trial_extensionJSON);

cJSON *domain_config_trial_extension_convertToJSON(domain_config_trial_extension_t *domain_config_trial_extension);

#endif /* _domain_config_trial_extension_H_ */

