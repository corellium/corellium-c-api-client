#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "snapshot_member_schema.h"



static snapshot_member_schema_t *snapshot_member_schema_create_internal(
    char *email,
    char *invite_sent_at,
    char *shared_on,
    char *user_id,
    char *name
    ) {
    snapshot_member_schema_t *snapshot_member_schema_local_var = malloc(sizeof(snapshot_member_schema_t));
    if (!snapshot_member_schema_local_var) {
        return NULL;
    }
    snapshot_member_schema_local_var->email = email;
    snapshot_member_schema_local_var->invite_sent_at = invite_sent_at;
    snapshot_member_schema_local_var->shared_on = shared_on;
    snapshot_member_schema_local_var->user_id = user_id;
    snapshot_member_schema_local_var->name = name;

    snapshot_member_schema_local_var->_library_owned = 1;
    return snapshot_member_schema_local_var;
}

__attribute__((deprecated)) snapshot_member_schema_t *snapshot_member_schema_create(
    char *email,
    char *invite_sent_at,
    char *shared_on,
    char *user_id,
    char *name
    ) {
    return snapshot_member_schema_create_internal (
        email,
        invite_sent_at,
        shared_on,
        user_id,
        name
        );
}

void snapshot_member_schema_free(snapshot_member_schema_t *snapshot_member_schema) {
    if(NULL == snapshot_member_schema){
        return ;
    }
    if(snapshot_member_schema->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "snapshot_member_schema_free");
        return ;
    }
    listEntry_t *listEntry;
    if (snapshot_member_schema->email) {
        free(snapshot_member_schema->email);
        snapshot_member_schema->email = NULL;
    }
    if (snapshot_member_schema->invite_sent_at) {
        free(snapshot_member_schema->invite_sent_at);
        snapshot_member_schema->invite_sent_at = NULL;
    }
    if (snapshot_member_schema->shared_on) {
        free(snapshot_member_schema->shared_on);
        snapshot_member_schema->shared_on = NULL;
    }
    if (snapshot_member_schema->user_id) {
        free(snapshot_member_schema->user_id);
        snapshot_member_schema->user_id = NULL;
    }
    if (snapshot_member_schema->name) {
        free(snapshot_member_schema->name);
        snapshot_member_schema->name = NULL;
    }
    free(snapshot_member_schema);
}

cJSON *snapshot_member_schema_convertToJSON(snapshot_member_schema_t *snapshot_member_schema) {
    cJSON *item = cJSON_CreateObject();

    // snapshot_member_schema->email
    if (!snapshot_member_schema->email) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "email", snapshot_member_schema->email) == NULL) {
    goto fail; //String
    }


    // snapshot_member_schema->invite_sent_at
    if(snapshot_member_schema->invite_sent_at) {
    if(cJSON_AddStringToObject(item, "inviteSentAt", snapshot_member_schema->invite_sent_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // snapshot_member_schema->shared_on
    if(snapshot_member_schema->shared_on) {
    if(cJSON_AddStringToObject(item, "sharedOn", snapshot_member_schema->shared_on) == NULL) {
    goto fail; //Date-Time
    }
    }


    // snapshot_member_schema->user_id
    if(snapshot_member_schema->user_id) {
    if(cJSON_AddStringToObject(item, "userId", snapshot_member_schema->user_id) == NULL) {
    goto fail; //String
    }
    }


    // snapshot_member_schema->name
    if(snapshot_member_schema->name) {
    if(cJSON_AddStringToObject(item, "name", snapshot_member_schema->name) == NULL) {
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

snapshot_member_schema_t *snapshot_member_schema_parseFromJSON(cJSON *snapshot_member_schemaJSON){

    snapshot_member_schema_t *snapshot_member_schema_local_var = NULL;

    // snapshot_member_schema->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(snapshot_member_schemaJSON, "email");
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

    // snapshot_member_schema->invite_sent_at
    cJSON *invite_sent_at = cJSON_GetObjectItemCaseSensitive(snapshot_member_schemaJSON, "inviteSentAt");
    if (cJSON_IsNull(invite_sent_at)) {
        invite_sent_at = NULL;
    }
    if (invite_sent_at) { 
    if(!cJSON_IsString(invite_sent_at) && !cJSON_IsNull(invite_sent_at))
    {
    goto end; //DateTime
    }
    }

    // snapshot_member_schema->shared_on
    cJSON *shared_on = cJSON_GetObjectItemCaseSensitive(snapshot_member_schemaJSON, "sharedOn");
    if (cJSON_IsNull(shared_on)) {
        shared_on = NULL;
    }
    if (shared_on) { 
    if(!cJSON_IsString(shared_on) && !cJSON_IsNull(shared_on))
    {
    goto end; //DateTime
    }
    }

    // snapshot_member_schema->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(snapshot_member_schemaJSON, "userId");
    if (cJSON_IsNull(user_id)) {
        user_id = NULL;
    }
    if (user_id) { 
    if(!cJSON_IsString(user_id) && !cJSON_IsNull(user_id))
    {
    goto end; //String
    }
    }

    // snapshot_member_schema->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(snapshot_member_schemaJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }


    snapshot_member_schema_local_var = snapshot_member_schema_create_internal (
        strdup(email->valuestring),
        invite_sent_at && !cJSON_IsNull(invite_sent_at) ? strdup(invite_sent_at->valuestring) : NULL,
        shared_on && !cJSON_IsNull(shared_on) ? strdup(shared_on->valuestring) : NULL,
        user_id && !cJSON_IsNull(user_id) ? strdup(user_id->valuestring) : NULL,
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL
        );

    return snapshot_member_schema_local_var;
end:
    return NULL;

}
