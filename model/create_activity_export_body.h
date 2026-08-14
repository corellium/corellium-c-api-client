/*
 * create_activity_export_body.h
 *
 * 
 */

#ifndef _create_activity_export_body_H_
#define _create_activity_export_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_activity_export_body_t create_activity_export_body_t;

#include "any_type.h"
#include "object.h"



typedef struct create_activity_export_body_t {
    object_t *resource; //object
    double offset; //numeric
    char *order_by; // string
    char *instance_id; // string
    char *project_id; // string
    char *actor; // string
    char *search; // string
    char *to; //date time
    char *from; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} create_activity_export_body_t;

__attribute__((deprecated)) create_activity_export_body_t *create_activity_export_body_create(
    object_t *resource,
    double offset,
    char *order_by,
    char *instance_id,
    char *project_id,
    char *actor,
    char *search,
    char *to,
    char *from
);

void create_activity_export_body_free(create_activity_export_body_t *create_activity_export_body);

create_activity_export_body_t *create_activity_export_body_parseFromJSON(cJSON *create_activity_export_bodyJSON);

cJSON *create_activity_export_body_convertToJSON(create_activity_export_body_t *create_activity_export_body);

#endif /* _create_activity_export_body_H_ */

