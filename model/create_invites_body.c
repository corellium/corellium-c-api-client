#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_invites_body.h"



static create_invites_body_t *create_invites_body_create_internal(
    list_t *email,
    int resend,
    create_invites_body_settings_t *settings
    ) {
    create_invites_body_t *create_invites_body_local_var = malloc(sizeof(create_invites_body_t));
    if (!create_invites_body_local_var) {
        return NULL;
    }
    create_invites_body_local_var->email = email;
    create_invites_body_local_var->resend = resend;
    create_invites_body_local_var->settings = settings;

    create_invites_body_local_var->_library_owned = 1;
    return create_invites_body_local_var;
}

__attribute__((deprecated)) create_invites_body_t *create_invites_body_create(
    list_t *email,
    int resend,
    create_invites_body_settings_t *settings
    ) {
    return create_invites_body_create_internal (
        email,
        resend,
        settings
        );
}

void create_invites_body_free(create_invites_body_t *create_invites_body) {
    if(NULL == create_invites_body){
        return ;
    }
    if(create_invites_body->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "create_invites_body_free");
        return ;
    }
    listEntry_t *listEntry;
    if (create_invites_body->email) {
        list_ForEach(listEntry, create_invites_body->email) {
            free(listEntry->data);
        }
        list_freeList(create_invites_body->email);
        create_invites_body->email = NULL;
    }
    if (create_invites_body->settings) {
        create_invites_body_settings_free(create_invites_body->settings);
        create_invites_body->settings = NULL;
    }
    free(create_invites_body);
}

cJSON *create_invites_body_convertToJSON(create_invites_body_t *create_invites_body) {
    cJSON *item = cJSON_CreateObject();

    // create_invites_body->email
    if (!create_invites_body->email) {
        goto fail;
    }
    cJSON *email = cJSON_AddArrayToObject(item, "email");
    if(email == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *emailListEntry;
    list_ForEach(emailListEntry, create_invites_body->email) {
    if(cJSON_AddStringToObject(email, "", emailListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // create_invites_body->resend
    if(create_invites_body->resend) {
    if(cJSON_AddBoolToObject(item, "resend", create_invites_body->resend) == NULL) {
    goto fail; //Bool
    }
    }


    // create_invites_body->settings
    if(create_invites_body->settings) {
    cJSON *settings_local_JSON = create_invites_body_settings_convertToJSON(create_invites_body->settings);
    if(settings_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "settings", settings_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

create_invites_body_t *create_invites_body_parseFromJSON(cJSON *create_invites_bodyJSON){

    create_invites_body_t *create_invites_body_local_var = NULL;

    // define the local list for create_invites_body->email
    list_t *emailList = NULL;

    // define the local variable for create_invites_body->settings
    create_invites_body_settings_t *settings_local_nonprim = NULL;

    // create_invites_body->email
    cJSON *email = cJSON_GetObjectItemCaseSensitive(create_invites_bodyJSON, "email");
    if (cJSON_IsNull(email)) {
        email = NULL;
    }
    if (!email) {
        goto end;
    }

    
    cJSON *email_local = NULL;
    if(!cJSON_IsArray(email)) {
        goto end;//primitive container
    }
    emailList = list_createList();

    cJSON_ArrayForEach(email_local, email)
    {
        if(!cJSON_IsString(email_local))
        {
            goto end;
        }
        list_addElement(emailList , strdup(email_local->valuestring));
    }

    // create_invites_body->resend
    cJSON *resend = cJSON_GetObjectItemCaseSensitive(create_invites_bodyJSON, "resend");
    if (cJSON_IsNull(resend)) {
        resend = NULL;
    }
    if (resend) { 
    if(!cJSON_IsBool(resend))
    {
    goto end; //Bool
    }
    }

    // create_invites_body->settings
    cJSON *settings = cJSON_GetObjectItemCaseSensitive(create_invites_bodyJSON, "settings");
    if (cJSON_IsNull(settings)) {
        settings = NULL;
    }
    if (settings) { 
    settings_local_nonprim = create_invites_body_settings_parseFromJSON(settings); //nonprimitive
    }


    create_invites_body_local_var = create_invites_body_create_internal (
        emailList,
        resend ? resend->valueint : 0,
        settings ? settings_local_nonprim : NULL
        );

    return create_invites_body_local_var;
end:
    if (emailList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, emailList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(emailList);
        emailList = NULL;
    }
    if (settings_local_nonprim) {
        create_invites_body_settings_free(settings_local_nonprim);
        settings_local_nonprim = NULL;
    }
    return NULL;

}
