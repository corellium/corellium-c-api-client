#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cluster_config_net_mon_ca.h"



static cluster_config_net_mon_ca_t *cluster_config_net_mon_ca_create_internal(
    char *certificate,
    char *key,
    char *subject_hash2
    ) {
    cluster_config_net_mon_ca_t *cluster_config_net_mon_ca_local_var = malloc(sizeof(cluster_config_net_mon_ca_t));
    if (!cluster_config_net_mon_ca_local_var) {
        return NULL;
    }
    cluster_config_net_mon_ca_local_var->certificate = certificate;
    cluster_config_net_mon_ca_local_var->key = key;
    cluster_config_net_mon_ca_local_var->subject_hash2 = subject_hash2;

    cluster_config_net_mon_ca_local_var->_library_owned = 1;
    return cluster_config_net_mon_ca_local_var;
}

__attribute__((deprecated)) cluster_config_net_mon_ca_t *cluster_config_net_mon_ca_create(
    char *certificate,
    char *key,
    char *subject_hash2
    ) {
    return cluster_config_net_mon_ca_create_internal (
        certificate,
        key,
        subject_hash2
        );
}

void cluster_config_net_mon_ca_free(cluster_config_net_mon_ca_t *cluster_config_net_mon_ca) {
    if(NULL == cluster_config_net_mon_ca){
        return ;
    }
    if(cluster_config_net_mon_ca->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cluster_config_net_mon_ca_free");
        return ;
    }
    listEntry_t *listEntry;
    if (cluster_config_net_mon_ca->certificate) {
        free(cluster_config_net_mon_ca->certificate);
        cluster_config_net_mon_ca->certificate = NULL;
    }
    if (cluster_config_net_mon_ca->key) {
        free(cluster_config_net_mon_ca->key);
        cluster_config_net_mon_ca->key = NULL;
    }
    if (cluster_config_net_mon_ca->subject_hash2) {
        free(cluster_config_net_mon_ca->subject_hash2);
        cluster_config_net_mon_ca->subject_hash2 = NULL;
    }
    free(cluster_config_net_mon_ca);
}

cJSON *cluster_config_net_mon_ca_convertToJSON(cluster_config_net_mon_ca_t *cluster_config_net_mon_ca) {
    cJSON *item = cJSON_CreateObject();

    // cluster_config_net_mon_ca->certificate
    if (!cluster_config_net_mon_ca->certificate) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "certificate", cluster_config_net_mon_ca->certificate) == NULL) {
    goto fail; //String
    }


    // cluster_config_net_mon_ca->key
    if (!cluster_config_net_mon_ca->key) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "key", cluster_config_net_mon_ca->key) == NULL) {
    goto fail; //String
    }


    // cluster_config_net_mon_ca->subject_hash2
    if (!cluster_config_net_mon_ca->subject_hash2) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "subjectHash2", cluster_config_net_mon_ca->subject_hash2) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

cluster_config_net_mon_ca_t *cluster_config_net_mon_ca_parseFromJSON(cJSON *cluster_config_net_mon_caJSON){

    cluster_config_net_mon_ca_t *cluster_config_net_mon_ca_local_var = NULL;

    // cluster_config_net_mon_ca->certificate
    cJSON *certificate = cJSON_GetObjectItemCaseSensitive(cluster_config_net_mon_caJSON, "certificate");
    if (cJSON_IsNull(certificate)) {
        certificate = NULL;
    }
    if (!certificate) {
        goto end;
    }

    
    if(!cJSON_IsString(certificate))
    {
    goto end; //String
    }

    // cluster_config_net_mon_ca->key
    cJSON *key = cJSON_GetObjectItemCaseSensitive(cluster_config_net_mon_caJSON, "key");
    if (cJSON_IsNull(key)) {
        key = NULL;
    }
    if (!key) {
        goto end;
    }

    
    if(!cJSON_IsString(key))
    {
    goto end; //String
    }

    // cluster_config_net_mon_ca->subject_hash2
    cJSON *subject_hash2 = cJSON_GetObjectItemCaseSensitive(cluster_config_net_mon_caJSON, "subjectHash2");
    if (cJSON_IsNull(subject_hash2)) {
        subject_hash2 = NULL;
    }
    if (!subject_hash2) {
        goto end;
    }

    
    if(!cJSON_IsString(subject_hash2))
    {
    goto end; //String
    }


    cluster_config_net_mon_ca_local_var = cluster_config_net_mon_ca_create_internal (
        strdup(certificate->valuestring),
        strdup(key->valuestring),
        strdup(subject_hash2->valuestring)
        );

    return cluster_config_net_mon_ca_local_var;
end:
    return NULL;

}
