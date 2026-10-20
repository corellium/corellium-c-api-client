/*
 * activity_export_dto.h
 *
 * 
 */

#ifndef _activity_export_dto_H_
#define _activity_export_dto_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct activity_export_dto_t activity_export_dto_t;




typedef struct activity_export_dto_t {
    char *resource; // string
    char *order_by; // string
    char *instance; // string
    char *project; // string
    char *actor; // string
    char *search; // string
    char *to; // string
    char *from; // string

    int _library_owned; // Is the library responsible for freeing this object?
} activity_export_dto_t;

__attribute__((deprecated)) activity_export_dto_t *activity_export_dto_create(
    char *resource,
    char *order_by,
    char *instance,
    char *project,
    char *actor,
    char *search,
    char *to,
    char *from
);

void activity_export_dto_free(activity_export_dto_t *activity_export_dto);

activity_export_dto_t *activity_export_dto_parseFromJSON(cJSON *activity_export_dtoJSON);

cJSON *activity_export_dto_convertToJSON(activity_export_dto_t *activity_export_dto);

#endif /* _activity_export_dto_H_ */

