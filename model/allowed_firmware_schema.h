/*
 * allowed_firmware_schema.h
 *
 * 
 */

#ifndef _allowed_firmware_schema_H_
#define _allowed_firmware_schema_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct allowed_firmware_schema_t allowed_firmware_schema_t;




typedef struct allowed_firmware_schema_t {
    char *version; // string
    char *build_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} allowed_firmware_schema_t;

__attribute__((deprecated)) allowed_firmware_schema_t *allowed_firmware_schema_create(
    char *version,
    char *build_id
);

void allowed_firmware_schema_free(allowed_firmware_schema_t *allowed_firmware_schema);

allowed_firmware_schema_t *allowed_firmware_schema_parseFromJSON(cJSON *allowed_firmware_schemaJSON);

cJSON *allowed_firmware_schema_convertToJSON(allowed_firmware_schema_t *allowed_firmware_schema);

#endif /* _allowed_firmware_schema_H_ */

