/*
 * sslsplit_filter.h
 *
 * 
 */

#ifndef _sslsplit_filter_H_
#define _sslsplit_filter_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct sslsplit_filter_t sslsplit_filter_t;




typedef struct sslsplit_filter_t {
    int truncate_pcap; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} sslsplit_filter_t;

__attribute__((deprecated)) sslsplit_filter_t *sslsplit_filter_create(
    int truncate_pcap
);

void sslsplit_filter_free(sslsplit_filter_t *sslsplit_filter);

sslsplit_filter_t *sslsplit_filter_parseFromJSON(cJSON *sslsplit_filterJSON);

cJSON *sslsplit_filter_convertToJSON(sslsplit_filter_t *sslsplit_filter);

#endif /* _sslsplit_filter_H_ */

