#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sslsplit_filter.h"



static sslsplit_filter_t *sslsplit_filter_create_internal(
    int truncate_pcap
    ) {
    sslsplit_filter_t *sslsplit_filter_local_var = malloc(sizeof(sslsplit_filter_t));
    if (!sslsplit_filter_local_var) {
        return NULL;
    }
    sslsplit_filter_local_var->truncate_pcap = truncate_pcap;

    sslsplit_filter_local_var->_library_owned = 1;
    return sslsplit_filter_local_var;
}

__attribute__((deprecated)) sslsplit_filter_t *sslsplit_filter_create(
    int truncate_pcap
    ) {
    return sslsplit_filter_create_internal (
        truncate_pcap
        );
}

void sslsplit_filter_free(sslsplit_filter_t *sslsplit_filter) {
    if(NULL == sslsplit_filter){
        return ;
    }
    if(sslsplit_filter->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "sslsplit_filter_free");
        return ;
    }
    listEntry_t *listEntry;
    free(sslsplit_filter);
}

cJSON *sslsplit_filter_convertToJSON(sslsplit_filter_t *sslsplit_filter) {
    cJSON *item = cJSON_CreateObject();

    // sslsplit_filter->truncate_pcap
    if(sslsplit_filter->truncate_pcap) {
    if(cJSON_AddBoolToObject(item, "truncatePcap", sslsplit_filter->truncate_pcap) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

sslsplit_filter_t *sslsplit_filter_parseFromJSON(cJSON *sslsplit_filterJSON){

    sslsplit_filter_t *sslsplit_filter_local_var = NULL;

    // sslsplit_filter->truncate_pcap
    cJSON *truncate_pcap = cJSON_GetObjectItemCaseSensitive(sslsplit_filterJSON, "truncatePcap");
    if (cJSON_IsNull(truncate_pcap)) {
        truncate_pcap = NULL;
    }
    if (truncate_pcap) { 
    if(!cJSON_IsBool(truncate_pcap))
    {
    goto end; //Bool
    }
    }


    sslsplit_filter_local_var = sslsplit_filter_create_internal (
        truncate_pcap ? truncate_pcap->valueint : 0
        );

    return sslsplit_filter_local_var;
end:
    return NULL;

}
