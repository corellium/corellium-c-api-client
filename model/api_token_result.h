/*
 * api_token_result.h
 *
 * 
 */

#ifndef _api_token_result_H_
#define _api_token_result_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct api_token_result_t api_token_result_t;




typedef struct api_token_result_t {
    char *api_token; // string

    int _library_owned; // Is the library responsible for freeing this object?
} api_token_result_t;

__attribute__((deprecated)) api_token_result_t *api_token_result_create(
    char *api_token
);

void api_token_result_free(api_token_result_t *api_token_result);

api_token_result_t *api_token_result_parseFromJSON(cJSON *api_token_resultJSON);

cJSON *api_token_result_convertToJSON(api_token_result_t *api_token_result);

#endif /* _api_token_result_H_ */

