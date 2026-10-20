/*
 * restore_backup_body.h
 *
 * 
 */

#ifndef _restore_backup_body_H_
#define _restore_backup_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct restore_backup_body_t restore_backup_body_t;




typedef struct restore_backup_body_t {
    char *password; // string

    int _library_owned; // Is the library responsible for freeing this object?
} restore_backup_body_t;

__attribute__((deprecated)) restore_backup_body_t *restore_backup_body_create(
    char *password
);

void restore_backup_body_free(restore_backup_body_t *restore_backup_body);

restore_backup_body_t *restore_backup_body_parseFromJSON(cJSON *restore_backup_bodyJSON);

cJSON *restore_backup_body_convertToJSON(restore_backup_body_t *restore_backup_body);

#endif /* _restore_backup_body_H_ */

