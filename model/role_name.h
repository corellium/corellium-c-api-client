/*
 * role_name.h
 *
 * Role identifier.
 */

#ifndef _role_name_H_
#define _role_name_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct role_name_t role_name_t;


// Enum  for role_name

typedef enum { corellium_api_role_name__NULL = 0, corellium_api_role_name__admin, corellium_api_role_name__member } corellium_api_role_name__e;

char* role_name_role_name_ToString(corellium_api_role_name__e role_name);

corellium_api_role_name__e role_name_role_name_FromString(char* role_name);

cJSON *role_name_convertToJSON(corellium_api_role_name__e role_name);

corellium_api_role_name__e role_name_parseFromJSON(cJSON *role_nameJSON);

#endif /* _role_name_H_ */

