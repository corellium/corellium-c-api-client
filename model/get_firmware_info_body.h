/*
 * get_firmware_info_body.h
 *
 * 
 */

#ifndef _get_firmware_info_body_H_
#define _get_firmware_info_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct get_firmware_info_body_t get_firmware_info_body_t;




typedef struct get_firmware_info_body_t {
    char *password; // string
    int extended; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} get_firmware_info_body_t;

__attribute__((deprecated)) get_firmware_info_body_t *get_firmware_info_body_create(
    char *password,
    int extended
);

void get_firmware_info_body_free(get_firmware_info_body_t *get_firmware_info_body);

get_firmware_info_body_t *get_firmware_info_body_parseFromJSON(cJSON *get_firmware_info_bodyJSON);

cJSON *get_firmware_info_body_convertToJSON(get_firmware_info_body_t *get_firmware_info_body);

#endif /* _get_firmware_info_body_H_ */

