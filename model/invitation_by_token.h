/*
 * invitation_by_token.h
 *
 * 
 */

#ifndef _invitation_by_token_H_
#define _invitation_by_token_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct invitation_by_token_t invitation_by_token_t;

#include "invite_settings.h"



typedef struct invitation_by_token_t {
    char *id; // string
    char *email; // string
    char *domain; // string
    char *display_name; // string
    int terms_agreement_required; //boolean
    struct invite_settings_t *settings; //model

    int _library_owned; // Is the library responsible for freeing this object?
} invitation_by_token_t;

__attribute__((deprecated)) invitation_by_token_t *invitation_by_token_create(
    char *id,
    char *email,
    char *domain,
    char *display_name,
    int terms_agreement_required,
    invite_settings_t *settings
);

void invitation_by_token_free(invitation_by_token_t *invitation_by_token);

invitation_by_token_t *invitation_by_token_parseFromJSON(cJSON *invitation_by_tokenJSON);

cJSON *invitation_by_token_convertToJSON(invitation_by_token_t *invitation_by_token);

#endif /* _invitation_by_token_H_ */

