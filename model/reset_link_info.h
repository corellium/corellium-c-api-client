/*
 * reset_link_info.h
 *
 * 
 */

#ifndef _reset_link_info_H_
#define _reset_link_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct reset_link_info_t reset_link_info_t;




typedef struct reset_link_info_t {
    char *user_id; // string
    char *username; // string
    char *domain; // string

    int _library_owned; // Is the library responsible for freeing this object?
} reset_link_info_t;

__attribute__((deprecated)) reset_link_info_t *reset_link_info_create(
    char *user_id,
    char *username,
    char *domain
);

void reset_link_info_free(reset_link_info_t *reset_link_info);

reset_link_info_t *reset_link_info_parseFromJSON(cJSON *reset_link_infoJSON);

cJSON *reset_link_info_convertToJSON(reset_link_info_t *reset_link_info);

#endif /* _reset_link_info_H_ */

