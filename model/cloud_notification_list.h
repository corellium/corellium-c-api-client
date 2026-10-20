/*
 * cloud_notification_list.h
 *
 * 
 */

#ifndef _cloud_notification_list_H_
#define _cloud_notification_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cloud_notification_list_t cloud_notification_list_t;

#include "cloud_notification_item.h"



typedef struct cloud_notification_list_t {
    list_t *results; //nonprimitive container
    double count; //numeric
    double total; //numeric
    double limit; //numeric
    double offset; //numeric
    int has_more; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} cloud_notification_list_t;

__attribute__((deprecated)) cloud_notification_list_t *cloud_notification_list_create(
    list_t *results,
    double count,
    double total,
    double limit,
    double offset,
    int has_more
);

void cloud_notification_list_free(cloud_notification_list_t *cloud_notification_list);

cloud_notification_list_t *cloud_notification_list_parseFromJSON(cJSON *cloud_notification_listJSON);

cJSON *cloud_notification_list_convertToJSON(cloud_notification_list_t *cloud_notification_list);

#endif /* _cloud_notification_list_H_ */

