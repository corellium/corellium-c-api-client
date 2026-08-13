/*
 * update_domain_settings_response_settings.h
 *
 * Applied domain settings.
 */

#ifndef _update_domain_settings_response_settings_H_
#define _update_domain_settings_response_settings_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct update_domain_settings_response_settings_t update_domain_settings_response_settings_t;




typedef struct update_domain_settings_response_settings_t {
    int totp_required; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} update_domain_settings_response_settings_t;

__attribute__((deprecated)) update_domain_settings_response_settings_t *update_domain_settings_response_settings_create(
    int totp_required
);

void update_domain_settings_response_settings_free(update_domain_settings_response_settings_t *update_domain_settings_response_settings);

update_domain_settings_response_settings_t *update_domain_settings_response_settings_parseFromJSON(cJSON *update_domain_settings_response_settingsJSON);

cJSON *update_domain_settings_response_settings_convertToJSON(update_domain_settings_response_settings_t *update_domain_settings_response_settings);

#endif /* _update_domain_settings_response_settings_H_ */

