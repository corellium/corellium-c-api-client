/*
 * activity_download.h
 *
 * 
 */

#ifndef _activity_download_H_
#define _activity_download_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct activity_download_t activity_download_t;

#include "activity.h"
#include "activity_query_options.h"



typedef struct activity_download_t {
    list_t *data; //nonprimitive container
    struct activity_query_options_t *filters; //model

    int _library_owned; // Is the library responsible for freeing this object?
} activity_download_t;

__attribute__((deprecated)) activity_download_t *activity_download_create(
    list_t *data,
    activity_query_options_t *filters
);

void activity_download_free(activity_download_t *activity_download);

activity_download_t *activity_download_parseFromJSON(cJSON *activity_downloadJSON);

cJSON *activity_download_convertToJSON(activity_download_t *activity_download);

#endif /* _activity_download_H_ */

