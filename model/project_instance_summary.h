/*
 * project_instance_summary.h
 *
 * 
 */

#ifndef _project_instance_summary_H_
#define _project_instance_summary_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct project_instance_summary_t project_instance_summary_t;




typedef struct project_instance_summary_t {
    char *id; // string
    char *name; // string
    char *project; // string
    char *state; // string

    int _library_owned; // Is the library responsible for freeing this object?
} project_instance_summary_t;

__attribute__((deprecated)) project_instance_summary_t *project_instance_summary_create(
    char *id,
    char *name,
    char *project,
    char *state
);

void project_instance_summary_free(project_instance_summary_t *project_instance_summary);

project_instance_summary_t *project_instance_summary_parseFromJSON(cJSON *project_instance_summaryJSON);

cJSON *project_instance_summary_convertToJSON(project_instance_summary_t *project_instance_summary);

#endif /* _project_instance_summary_H_ */

