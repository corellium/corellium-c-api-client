#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "report_modification_input.h"



static report_modification_input_t *report_modification_input_create_internal(
    char *check_id,
    object_t *property,
    int suppressed,
    char *value
    ) {
    report_modification_input_t *report_modification_input_local_var = malloc(sizeof(report_modification_input_t));
    if (!report_modification_input_local_var) {
        return NULL;
    }
    report_modification_input_local_var->check_id = check_id;
    report_modification_input_local_var->property = property;
    report_modification_input_local_var->suppressed = suppressed;
    report_modification_input_local_var->value = value;

    report_modification_input_local_var->_library_owned = 1;
    return report_modification_input_local_var;
}

__attribute__((deprecated)) report_modification_input_t *report_modification_input_create(
    char *check_id,
    object_t *property,
    int suppressed,
    char *value
    ) {
    return report_modification_input_create_internal (
        check_id,
        property,
        suppressed,
        value
        );
}

void report_modification_input_free(report_modification_input_t *report_modification_input) {
    if(NULL == report_modification_input){
        return ;
    }
    if(report_modification_input->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "report_modification_input_free");
        return ;
    }
    listEntry_t *listEntry;
    if (report_modification_input->check_id) {
        free(report_modification_input->check_id);
        report_modification_input->check_id = NULL;
    }
    if (report_modification_input->property) {
        object_free(report_modification_input->property);
        report_modification_input->property = NULL;
    }
    if (report_modification_input->value) {
        free(report_modification_input->value);
        report_modification_input->value = NULL;
    }
    free(report_modification_input);
}

cJSON *report_modification_input_convertToJSON(report_modification_input_t *report_modification_input) {
    cJSON *item = cJSON_CreateObject();

    // report_modification_input->check_id
    if (!report_modification_input->check_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "checkId", report_modification_input->check_id) == NULL) {
    goto fail; //String
    }


    // report_modification_input->property
    if (!report_modification_input->property) {
        goto fail;
    }
    cJSON *property_object = object_convertToJSON(report_modification_input->property);
    if(property_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "property", property_object);
    if(item->child == NULL) {
    goto fail;
    }


    // report_modification_input->suppressed
    if(report_modification_input->suppressed) {
    if(cJSON_AddBoolToObject(item, "suppressed", report_modification_input->suppressed) == NULL) {
    goto fail; //Bool
    }
    }


    // report_modification_input->value
    if(report_modification_input->value) {
    if(cJSON_AddStringToObject(item, "value", report_modification_input->value) == NULL) {
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

report_modification_input_t *report_modification_input_parseFromJSON(cJSON *report_modification_inputJSON){

    report_modification_input_t *report_modification_input_local_var = NULL;

    // report_modification_input->check_id
    cJSON *check_id = cJSON_GetObjectItemCaseSensitive(report_modification_inputJSON, "checkId");
    if (cJSON_IsNull(check_id)) {
        check_id = NULL;
    }
    if (!check_id) {
        goto end;
    }

    
    if(!cJSON_IsString(check_id))
    {
    goto end; //String
    }

    // report_modification_input->property
    cJSON *property = cJSON_GetObjectItemCaseSensitive(report_modification_inputJSON, "property");
    if (cJSON_IsNull(property)) {
        property = NULL;
    }
    if (!property) {
        goto end;
    }

    object_t *property_local_object = NULL;
    
    property_local_object = object_parseFromJSON(property); //object

    // report_modification_input->suppressed
    cJSON *suppressed = cJSON_GetObjectItemCaseSensitive(report_modification_inputJSON, "suppressed");
    if (cJSON_IsNull(suppressed)) {
        suppressed = NULL;
    }
    if (suppressed) { 
    if(!cJSON_IsBool(suppressed))
    {
    goto end; //Bool
    }
    }

    // report_modification_input->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(report_modification_inputJSON, "value");
    if (cJSON_IsNull(value)) {
        value = NULL;
    }
    if (value) { 
    if(!cJSON_IsString(value) && !cJSON_IsNull(value))
    {
    goto end; //String
    }
    }


    report_modification_input_local_var = report_modification_input_create_internal (
        strdup(check_id->valuestring),
        property_local_object,
        suppressed ? suppressed->valueint : 0,
        value && !cJSON_IsNull(value) ? strdup(value->valuestring) : NULL
        );

    return report_modification_input_local_var;
end:
    return NULL;

}
