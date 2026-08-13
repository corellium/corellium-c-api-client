#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/api_error_v1.h"
#include "../model/object.h"
#include "../model/token_v1.h"


// Log In
//
token_v1_t*
AuthenticationV1API_v1AuthLogin(apiClient_t *apiClient, object_t *body);


