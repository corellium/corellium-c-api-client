/*
 * get_reset_link_info_body.h
 *
 * 
 */

#ifndef _get_reset_link_info_body_H_
#define _get_reset_link_info_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_reset_link_info_body_t get_reset_link_info_body_t;




typedef struct get_reset_link_info_body_t {
    char *token; // string

    int _library_owned; // Is the library responsible for freeing this object?
} get_reset_link_info_body_t;

__attribute__((deprecated)) get_reset_link_info_body_t *get_reset_link_info_body_create(
    char *token
);

void get_reset_link_info_body_free(get_reset_link_info_body_t *get_reset_link_info_body);

get_reset_link_info_body_t *get_reset_link_info_body_parseFromJSON(cJSON *get_reset_link_info_bodyJSON);

cJSON *get_reset_link_info_body_convertToJSON(get_reset_link_info_body_t *get_reset_link_info_body);

#endif /* _get_reset_link_info_body_H_ */

