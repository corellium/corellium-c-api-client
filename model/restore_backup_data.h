/*
 * restore_backup_data.h
 *
 * 
 */

#ifndef _restore_backup_data_H_
#define _restore_backup_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct restore_backup_data_t restore_backup_data_t;




typedef struct restore_backup_data_t {
    char *password; // string

    int _library_owned; // Is the library responsible for freeing this object?
} restore_backup_data_t;

__attribute__((deprecated)) restore_backup_data_t *restore_backup_data_create(
    char *password
);

void restore_backup_data_free(restore_backup_data_t *restore_backup_data);

restore_backup_data_t *restore_backup_data_parseFromJSON(cJSON *restore_backup_dataJSON);

cJSON *restore_backup_data_convertToJSON(restore_backup_data_t *restore_backup_data);

#endif /* _restore_backup_data_H_ */

