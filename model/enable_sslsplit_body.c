#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "enable_sslsplit_body.h"



static enable_sslsplit_body_t *enable_sslsplit_body_create_internal(
    int truncate_pcap
    ) {
    enable_sslsplit_body_t *enable_sslsplit_body_local_var = malloc(sizeof(enable_sslsplit_body_t));
    if (!enable_sslsplit_body_local_var) {
        return NULL;
    }
    enable_sslsplit_body_local_var->truncate_pcap = truncate_pcap;

    enable_sslsplit_body_local_var->_library_owned = 1;
    return enable_sslsplit_body_local_var;
}

__attribute__((deprecated)) enable_sslsplit_body_t *enable_sslsplit_body_create(
    int truncate_pcap
    ) {
    return enable_sslsplit_body_create_internal (
        truncate_pcap
        );
}

void enable_sslsplit_body_free(enable_sslsplit_body_t *enable_sslsplit_body) {
    if(NULL == enable_sslsplit_body){
        return ;
    }
    if(enable_sslsplit_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "enable_sslsplit_body_free");
        return ;
    }
    listEntry_t *listEntry;
    free(enable_sslsplit_body);
}

cJSON *enable_sslsplit_body_convertToJSON(enable_sslsplit_body_t *enable_sslsplit_body) {
    cJSON *item = cJSON_CreateObject();

    // enable_sslsplit_body->truncate_pcap
    if(enable_sslsplit_body->truncate_pcap) {
    if(cJSON_AddBoolToObject(item, "truncatePcap", enable_sslsplit_body->truncate_pcap) == NULL) {
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

enable_sslsplit_body_t *enable_sslsplit_body_parseFromJSON(cJSON *enable_sslsplit_bodyJSON){

    enable_sslsplit_body_t *enable_sslsplit_body_local_var = NULL;

    // enable_sslsplit_body->truncate_pcap
    cJSON *truncate_pcap = cJSON_GetObjectItemCaseSensitive(enable_sslsplit_bodyJSON, "truncatePcap");
    if (cJSON_IsNull(truncate_pcap)) {
        truncate_pcap = NULL;
    }
    if (truncate_pcap) { 
    if(!cJSON_IsBool(truncate_pcap))
    {
    goto end; //Bool
    }
    }


    enable_sslsplit_body_local_var = enable_sslsplit_body_create_internal (
        truncate_pcap ? truncate_pcap->valueint : 0
        );

    return enable_sslsplit_body_local_var;
end:
    return NULL;

}
