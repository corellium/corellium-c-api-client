/*
 * assessment_frida_script.h
 *
 * Frida script used during the assessment, or null if none.
 */

#ifndef _assessment_frida_script_H_
#define _assessment_frida_script_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct assessment_frida_script_t assessment_frida_script_t;




typedef struct assessment_frida_script_t {
    char *id; // string
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} assessment_frida_script_t;

__attribute__((deprecated)) assessment_frida_script_t *assessment_frida_script_create(
    char *id,
    char *name
);

void assessment_frida_script_free(assessment_frida_script_t *assessment_frida_script);

assessment_frida_script_t *assessment_frida_script_parseFromJSON(cJSON *assessment_frida_scriptJSON);

cJSON *assessment_frida_script_convertToJSON(assessment_frida_script_t *assessment_frida_script);

#endif /* _assessment_frida_script_H_ */

