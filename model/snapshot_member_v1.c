#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "snapshot_member_v1.h"



static snapshot_member_v1_t *snapshot_member_v1_create_internal(
    char *email,
    double invite_sent_at,
    double shared_on,
    char *user_id,
    char *label
    ) {
    snapshot_member_v1_t *snapshot_member_v1_local_var = malloc(sizeof(snapshot_member_v1_t));
    if (!snapshot_member_v1_local_var) {
        return NULL;
    }
    snapshot_member_v1_local_var->email = email;
    snapshot_member_v1_local_var->invite_sent_at = invite_sent_at;
    snapshot_member_v1_local_var->shared_on = shared_on;
    snapshot_member_v1_local_var->user_id = user_id;
    snapshot_member_v1_local_var->label = label;

    snapshot_member_v1_local_var->_library_owned = 1;
    return snapshot_member_v1_local_var;
}

__attribute__((deprecated)) snapshot_member_v1_t *snapshot_member_v1_create(
    char *email,
    double invite_sent_at,
    double shared_on,
    char *user_id,
    char *label
    ) {
    return snapshot_member_v1_create_internal (
        email,
        invite_sent_at,
        shared_on,
        user_id,
        label
        );
}

void snapshot_member_v1_free(snapshot_member_v1_t *snapshot_member_v1) {
    if(NULL == snapshot_member_v1){
        return ;
    }
    if(snapshot_member_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "snapshot_member_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (snapshot_member_v1->email) {
        free(snapshot_member_v1->email);
        snapshot_member_v1->email = NULL;
    }
    if (snapshot_member_v1->user_id) {
        free(snapshot_member_v1->user_id);
        snapshot_member_v1->user_id = NULL;
    }
    if (snapshot_member_v1->label) {
        free(snapshot_member_v1->label);
        snapshot_member_v1->label = NULL;
    }
    free(snapshot_member_v1);
}

cJSON *snapshot_member_v1_convertToJSON(snapshot_member_v1_t *snapshot_member_v1) {
    cJSON *item = cJSON_CreateObject();

    // snapshot_member_v1->email
    if (!snapshot_member_v1->email) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "email", snapshot_member_v1->email) == NULL) {
    goto fail; //String
    }


    // snapshot_member_v1->invite_sent_at
    if (!snapshot_member_v1->invite_sent_at) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "inviteSentAt", snapshot_member_v1->invite_sent_at) == NULL) {
    goto fail; //Numeric
    }


    // snapshot_member_v1->shared_on
    if (!snapshot_member_v1->shared_on) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "sharedOn", snapshot_member_v1->shared_on) == NULL) {
    goto fail; //Numeric
    }


    // snapshot_member_v1->user_id
    if(snapshot_member_v1->user_id) {
    if(cJSON_AddStringToObject(item, "userId", snapshot_member_v1->user_id) == NULL) {
    goto fail; //String
    }
    }


    // snapshot_member_v1->label
    if(snapshot_member_v1->label) {
    if(cJSON_AddStringToObject(item, "label", snapshot_member_v1->label) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

snapshot_member_v1_t *snapshot_member_v1_parseFromJSON(cJSON *snapshot_member_v1JSON){

    snapshot_member_v1_t *snapshot_member_v1_local_var = NULL;

    // snapshot_member_v1->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(snapshot_member_v1JSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (!email) {
        goto end;
    }

    
    if(!cJSON_IsString(email))
    {
    goto end; //String
    }

    // snapshot_member_v1->invite_sent_at
    cJSON *invite_sent_at = cJSON_GetObjectItemCaseSensitive(snapshot_member_v1JSON, "inviteSentAt");
    if (cJSON_IsNull(invite_sent_at)) {
        invite_sent_at = NULL;
    }
    if (!invite_sent_at) {
        goto end;
    }

    
    if(!cJSON_IsNumber(invite_sent_at))
    {
    goto end; //Numeric
    }

    // snapshot_member_v1->shared_on
    cJSON *shared_on = cJSON_GetObjectItemCaseSensitive(snapshot_member_v1JSON, "sharedOn");
    if (cJSON_IsNull(shared_on)) {
        shared_on = NULL;
    }
    if (!shared_on) {
        goto end;
    }

    
    if(!cJSON_IsNumber(shared_on))
    {
    goto end; //Numeric
    }

    // snapshot_member_v1->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(snapshot_member_v1JSON, "userId");
    if (cJSON_IsNull(user_id)) {
        user_id = NULL;
    }
    if (user_id) { 
    if(!cJSON_IsString(user_id) && !cJSON_IsNull(user_id))
    {
    goto end; //String
    }
    }

    // snapshot_member_v1->label
    cJSON *label = cJSON_GetObjectItemCaseSensitive(snapshot_member_v1JSON, "label");
    if (cJSON_IsNull(label)) {
        label = NULL;
    }
    if (label) { 
    if(!cJSON_IsString(label) && !cJSON_IsNull(label))
    {
    goto end; //String
    }
    }


    snapshot_member_v1_local_var = snapshot_member_v1_create_internal (
        strdup(email->valuestring),
        invite_sent_at->valuedouble,
        shared_on->valuedouble,
        user_id && !cJSON_IsNull(user_id) ? strdup(user_id->valuestring) : NULL,
        label && !cJSON_IsNull(label) ? strdup(label->valuestring) : NULL
        );

    return snapshot_member_v1_local_var;
end:
    return NULL;

}
