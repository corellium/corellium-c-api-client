#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "share_snapshot_body.h"


char* share_snapshot_body_sharing_type_ToString(corellium_api_share_snapshot_body_SHARINGTYPE_e sharing_type) {
    char* sharing_typeArray[] =  { "NULL", "publicLink", "domainRestrictedLink", "passwordPublicLink", "emailInvite", "notShared" };
    return sharing_typeArray[sharing_type];
}

corellium_api_share_snapshot_body_SHARINGTYPE_e share_snapshot_body_sharing_type_FromString(char* sharing_type){
    int stringToReturn = 0;
    char *sharing_typeArray[] =  { "NULL", "publicLink", "domainRestrictedLink", "passwordPublicLink", "emailInvite", "notShared" };
    size_t sizeofArray = sizeof(sharing_typeArray) / sizeof(sharing_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(sharing_type, sharing_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

static share_snapshot_body_t *share_snapshot_body_create_internal(
    corellium_api_share_snapshot_body_SHARINGTYPE_e sharing_type,
    char *password
    ) {
    share_snapshot_body_t *share_snapshot_body_local_var = malloc(sizeof(share_snapshot_body_t));
    if (!share_snapshot_body_local_var) {
        return NULL;
    }
    share_snapshot_body_local_var->sharing_type = sharing_type;
    share_snapshot_body_local_var->password = password;

    share_snapshot_body_local_var->_library_owned = 1;
    return share_snapshot_body_local_var;
}

__attribute__((deprecated)) share_snapshot_body_t *share_snapshot_body_create(
    corellium_api_share_snapshot_body_SHARINGTYPE_e sharing_type,
    char *password
    ) {
    return share_snapshot_body_create_internal (
        sharing_type,
        password
        );
}

void share_snapshot_body_free(share_snapshot_body_t *share_snapshot_body) {
    if(NULL == share_snapshot_body){
        return ;
    }
    if(share_snapshot_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "share_snapshot_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (share_snapshot_body->password) {
        free(share_snapshot_body->password);
        share_snapshot_body->password = NULL;
    }
    free(share_snapshot_body);
}

cJSON *share_snapshot_body_convertToJSON(share_snapshot_body_t *share_snapshot_body) {
    cJSON *item = cJSON_CreateObject();

    // share_snapshot_body->sharing_type
    if (corellium_api_share_snapshot_body_SHARINGTYPE_NULL == share_snapshot_body->sharing_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sharingType", share_snapshot_body_sharing_type_ToString(share_snapshot_body->sharing_type)) == NULL)
    {
    goto fail; //Enum
    }


    // share_snapshot_body->password
    if(share_snapshot_body->password) {
    if(cJSON_AddStringToObject(item, "password", share_snapshot_body->password) == NULL) {
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

share_snapshot_body_t *share_snapshot_body_parseFromJSON(cJSON *share_snapshot_bodyJSON){

    share_snapshot_body_t *share_snapshot_body_local_var = NULL;

    // share_snapshot_body->sharing_type
    cJSON *sharing_type = cJSON_GetObjectItemCaseSensitive(share_snapshot_bodyJSON, "sharingType");
    if (cJSON_IsNull(sharing_type)) {
        sharing_type = NULL;
    }
    if (!sharing_type) {
        goto end;
    }

    corellium_api_share_snapshot_body_SHARINGTYPE_e sharing_typeVariable;
    
    if(!cJSON_IsString(sharing_type))
    {
    goto end; //Enum
    }
    sharing_typeVariable = share_snapshot_body_sharing_type_FromString(sharing_type->valuestring);

    // share_snapshot_body->password
    cJSON *password = cJSON_GetObjectItemCaseSensitive(share_snapshot_bodyJSON, "password");
    if (cJSON_IsNull(password)) {
        password = NULL;
    }
    if (password) { 
    if(!cJSON_IsString(password) && !cJSON_IsNull(password))
    {
    goto end; //String
    }
    }


    share_snapshot_body_local_var = share_snapshot_body_create_internal (
        sharing_typeVariable,
        password && !cJSON_IsNull(password) ? strdup(password->valuestring) : NULL
        );

    return share_snapshot_body_local_var;
end:
    return NULL;

}
