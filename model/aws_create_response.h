/*
 * aws_create_response.h
 *
 * 
 */

#ifndef _aws_create_response_H_
#define _aws_create_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct aws_create_response_t aws_create_response_t;




typedef struct aws_create_response_t {
    int ready; //boolean
    int is_authed; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} aws_create_response_t;

__attribute__((deprecated)) aws_create_response_t *aws_create_response_create(
    int ready,
    int is_authed
);

void aws_create_response_free(aws_create_response_t *aws_create_response);

aws_create_response_t *aws_create_response_parseFromJSON(cJSON *aws_create_responseJSON);

cJSON *aws_create_response_convertToJSON(aws_create_response_t *aws_create_response);

#endif /* _aws_create_response_H_ */

