/*
 * user_error_item.h
 *
 * 
 */

#ifndef _user_error_item_H_
#define _user_error_item_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct user_error_item_t user_error_item_t;


// Enum ERRORID for user_error_item

typedef enum  { corellium_api_user_error_item_ERRORID_NULL = 0, corellium_api_user_error_item_ERRORID_UserError } corellium_api_user_error_item_ERRORID_e;

char* user_error_item_error_id_ToString(corellium_api_user_error_item_ERRORID_e error_id);

corellium_api_user_error_item_ERRORID_e user_error_item_error_id_FromString(char* error_id);



typedef struct user_error_item_t {
    char *error; // string
    corellium_api_user_error_item_ERRORID_e error_id; //enum
    char *field; // string
    char *validator; // string
    list_t *project_ids; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} user_error_item_t;

__attribute__((deprecated)) user_error_item_t *user_error_item_create(
    char *error,
    corellium_api_user_error_item_ERRORID_e error_id,
    char *field,
    char *validator,
    list_t *project_ids
);

void user_error_item_free(user_error_item_t *user_error_item);

user_error_item_t *user_error_item_parseFromJSON(cJSON *user_error_itemJSON);

cJSON *user_error_item_convertToJSON(user_error_item_t *user_error_item);

#endif /* _user_error_item_H_ */

