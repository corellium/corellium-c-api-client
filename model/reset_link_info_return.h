/*
 * reset_link_info_return.h
 *
 * 
 */

#ifndef _reset_link_info_return_H_
#define _reset_link_info_return_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct reset_link_info_return_t reset_link_info_return_t;




typedef struct reset_link_info_return_t {
    char *user_id; // string
    char *username; // string
    char *domain; // string

    int _library_owned; // Is the library responsible for freeing this object?
} reset_link_info_return_t;

__attribute__((deprecated)) reset_link_info_return_t *reset_link_info_return_create(
    char *user_id,
    char *username,
    char *domain
);

void reset_link_info_return_free(reset_link_info_return_t *reset_link_info_return);

reset_link_info_return_t *reset_link_info_return_parseFromJSON(cJSON *reset_link_info_returnJSON);

cJSON *reset_link_info_return_convertToJSON(reset_link_info_return_t *reset_link_info_return);

#endif /* _reset_link_info_return_H_ */

