/*
 * cloud_notification_item.h
 *
 * 
 */

#ifndef _cloud_notification_item_H_
#define _cloud_notification_item_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cloud_notification_item_t cloud_notification_item_t;

#include "any_type.h"
#include "object.h"



typedef struct cloud_notification_item_t {
    char *identifier; // string
    int admin_only; //boolean
    int quiet; //boolean
    char *scope; // string
    double level; //numeric
    char *title; // string
    char *message; // string
    object_t *metadata; //object
    char *created_at; //date time
    char *updated_at; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} cloud_notification_item_t;

__attribute__((deprecated)) cloud_notification_item_t *cloud_notification_item_create(
    char *identifier,
    int admin_only,
    int quiet,
    char *scope,
    double level,
    char *title,
    char *message,
    object_t *metadata,
    char *created_at,
    char *updated_at
);

void cloud_notification_item_free(cloud_notification_item_t *cloud_notification_item);

cloud_notification_item_t *cloud_notification_item_parseFromJSON(cJSON *cloud_notification_itemJSON);

cJSON *cloud_notification_item_convertToJSON(cloud_notification_item_t *cloud_notification_item);

#endif /* _cloud_notification_item_H_ */

