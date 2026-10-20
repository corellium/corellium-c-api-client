#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "web_player_features.h"



static web_player_features_t *web_player_features_create_internal(
    int apps,
    int connect,
    int console,
    int coretrace,
    int device_control,
    int device_delete,
    int files,
    int frida,
    int images,
    int messaging,
    int netmon,
    int network,
    int port_forwarding,
    int power_management,
    int profile,
    int sensors,
    int settings,
    int snapshots,
    int strace,
    int system
    ) {
    web_player_features_t *web_player_features_local_var = malloc(sizeof(web_player_features_t));
    if (!web_player_features_local_var) {
        return NULL;
    }
    web_player_features_local_var->apps = apps;
    web_player_features_local_var->connect = connect;
    web_player_features_local_var->console = console;
    web_player_features_local_var->coretrace = coretrace;
    web_player_features_local_var->device_control = device_control;
    web_player_features_local_var->device_delete = device_delete;
    web_player_features_local_var->files = files;
    web_player_features_local_var->frida = frida;
    web_player_features_local_var->images = images;
    web_player_features_local_var->messaging = messaging;
    web_player_features_local_var->netmon = netmon;
    web_player_features_local_var->network = network;
    web_player_features_local_var->port_forwarding = port_forwarding;
    web_player_features_local_var->power_management = power_management;
    web_player_features_local_var->profile = profile;
    web_player_features_local_var->sensors = sensors;
    web_player_features_local_var->settings = settings;
    web_player_features_local_var->snapshots = snapshots;
    web_player_features_local_var->strace = strace;
    web_player_features_local_var->system = system;

    web_player_features_local_var->_library_owned = 1;
    return web_player_features_local_var;
}

__attribute__((deprecated)) web_player_features_t *web_player_features_create(
    int apps,
    int connect,
    int console,
    int coretrace,
    int device_control,
    int device_delete,
    int files,
    int frida,
    int images,
    int messaging,
    int netmon,
    int network,
    int port_forwarding,
    int power_management,
    int profile,
    int sensors,
    int settings,
    int snapshots,
    int strace,
    int system
    ) {
    return web_player_features_create_internal (
        apps,
        connect,
        console,
        coretrace,
        device_control,
        device_delete,
        files,
        frida,
        images,
        messaging,
        netmon,
        network,
        port_forwarding,
        power_management,
        profile,
        sensors,
        settings,
        snapshots,
        strace,
        system
        );
}

void web_player_features_free(web_player_features_t *web_player_features) {
    if(NULL == web_player_features){
        return ;
    }
    if(web_player_features->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "web_player_features_free");
        return ;
    }
    listEntry_t *listEntry;
    free(web_player_features);
}

cJSON *web_player_features_convertToJSON(web_player_features_t *web_player_features) {
    cJSON *item = cJSON_CreateObject();

    // web_player_features->apps
    if(web_player_features->apps) {
    if(cJSON_AddBoolToObject(item, "apps", web_player_features->apps) == NULL) {
    goto fail; //Bool
    }
    }


    // web_player_features->connect
    if(web_player_features->connect) {
    if(cJSON_AddBoolToObject(item, "connect", web_player_features->connect) == NULL) {
    goto fail; //Bool
    }
    }


    // web_player_features->console
    if(web_player_features->console) {
    if(cJSON_AddBoolToObject(item, "console", web_player_features->console) == NULL) {
    goto fail; //Bool
    }
    }


    // web_player_features->coretrace
    if(web_player_features->coretrace) {
    if(cJSON_AddBoolToObject(item, "coretrace", web_player_features->coretrace) == NULL) {
    goto fail; //Bool
    }
    }


    // web_player_features->device_control
    if(web_player_features->device_control) {
    if(cJSON_AddBoolToObject(item, "deviceControl", web_player_features->device_control) == NULL) {
    goto fail; //Bool
    }
    }


    // web_player_features->device_delete
    if(web_player_features->device_delete) {
    if(cJSON_AddBoolToObject(item, "deviceDelete", web_player_features->device_delete) == NULL) {
    goto fail; //Bool
    }
    }


    // web_player_features->files
    if(web_player_features->files) {
    if(cJSON_AddBoolToObject(item, "files", web_player_features->files) == NULL) {
    goto fail; //Bool
    }
    }


    // web_player_features->frida
    if(web_player_features->frida) {
    if(cJSON_AddBoolToObject(item, "frida", web_player_features->frida) == NULL) {
    goto fail; //Bool
    }
    }


    // web_player_features->images
    if(web_player_features->images) {
    if(cJSON_AddBoolToObject(item, "images", web_player_features->images) == NULL) {
    goto fail; //Bool
    }
    }


    // web_player_features->messaging
    if(web_player_features->messaging) {
    if(cJSON_AddBoolToObject(item, "messaging", web_player_features->messaging) == NULL) {
    goto fail; //Bool
    }
    }


    // web_player_features->netmon
    if(web_player_features->netmon) {
    if(cJSON_AddBoolToObject(item, "netmon", web_player_features->netmon) == NULL) {
    goto fail; //Bool
    }
    }


    // web_player_features->network
    if(web_player_features->network) {
    if(cJSON_AddBoolToObject(item, "network", web_player_features->network) == NULL) {
    goto fail; //Bool
    }
    }


    // web_player_features->port_forwarding
    if(web_player_features->port_forwarding) {
    if(cJSON_AddBoolToObject(item, "portForwarding", web_player_features->port_forwarding) == NULL) {
    goto fail; //Bool
    }
    }


    // web_player_features->power_management
    if(web_player_features->power_management) {
    if(cJSON_AddBoolToObject(item, "powerManagement", web_player_features->power_management) == NULL) {
    goto fail; //Bool
    }
    }


    // web_player_features->profile
    if(web_player_features->profile) {
    if(cJSON_AddBoolToObject(item, "profile", web_player_features->profile) == NULL) {
    goto fail; //Bool
    }
    }


    // web_player_features->sensors
    if(web_player_features->sensors) {
    if(cJSON_AddBoolToObject(item, "sensors", web_player_features->sensors) == NULL) {
    goto fail; //Bool
    }
    }


    // web_player_features->settings
    if(web_player_features->settings) {
    if(cJSON_AddBoolToObject(item, "settings", web_player_features->settings) == NULL) {
    goto fail; //Bool
    }
    }


    // web_player_features->snapshots
    if(web_player_features->snapshots) {
    if(cJSON_AddBoolToObject(item, "snapshots", web_player_features->snapshots) == NULL) {
    goto fail; //Bool
    }
    }


    // web_player_features->strace
    if(web_player_features->strace) {
    if(cJSON_AddBoolToObject(item, "strace", web_player_features->strace) == NULL) {
    goto fail; //Bool
    }
    }


    // web_player_features->system
    if(web_player_features->system) {
    if(cJSON_AddBoolToObject(item, "system", web_player_features->system) == NULL) {
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

web_player_features_t *web_player_features_parseFromJSON(cJSON *web_player_featuresJSON){

    web_player_features_t *web_player_features_local_var = NULL;

    // web_player_features->apps
    cJSON *apps = cJSON_GetObjectItemCaseSensitive(web_player_featuresJSON, "apps");
    if (cJSON_IsNull(apps)) {
        apps = NULL;
    }
    if (apps) { 
    if(!cJSON_IsBool(apps))
    {
    goto end; //Bool
    }
    }

    // web_player_features->connect
    cJSON *connect = cJSON_GetObjectItemCaseSensitive(web_player_featuresJSON, "connect");
    if (cJSON_IsNull(connect)) {
        connect = NULL;
    }
    if (connect) { 
    if(!cJSON_IsBool(connect))
    {
    goto end; //Bool
    }
    }

    // web_player_features->console
    cJSON *console = cJSON_GetObjectItemCaseSensitive(web_player_featuresJSON, "console");
    if (cJSON_IsNull(console)) {
        console = NULL;
    }
    if (console) { 
    if(!cJSON_IsBool(console))
    {
    goto end; //Bool
    }
    }

    // web_player_features->coretrace
    cJSON *coretrace = cJSON_GetObjectItemCaseSensitive(web_player_featuresJSON, "coretrace");
    if (cJSON_IsNull(coretrace)) {
        coretrace = NULL;
    }
    if (coretrace) { 
    if(!cJSON_IsBool(coretrace))
    {
    goto end; //Bool
    }
    }

    // web_player_features->device_control
    cJSON *device_control = cJSON_GetObjectItemCaseSensitive(web_player_featuresJSON, "deviceControl");
    if (cJSON_IsNull(device_control)) {
        device_control = NULL;
    }
    if (device_control) { 
    if(!cJSON_IsBool(device_control))
    {
    goto end; //Bool
    }
    }

    // web_player_features->device_delete
    cJSON *device_delete = cJSON_GetObjectItemCaseSensitive(web_player_featuresJSON, "deviceDelete");
    if (cJSON_IsNull(device_delete)) {
        device_delete = NULL;
    }
    if (device_delete) { 
    if(!cJSON_IsBool(device_delete))
    {
    goto end; //Bool
    }
    }

    // web_player_features->files
    cJSON *files = cJSON_GetObjectItemCaseSensitive(web_player_featuresJSON, "files");
    if (cJSON_IsNull(files)) {
        files = NULL;
    }
    if (files) { 
    if(!cJSON_IsBool(files))
    {
    goto end; //Bool
    }
    }

    // web_player_features->frida
    cJSON *frida = cJSON_GetObjectItemCaseSensitive(web_player_featuresJSON, "frida");
    if (cJSON_IsNull(frida)) {
        frida = NULL;
    }
    if (frida) { 
    if(!cJSON_IsBool(frida))
    {
    goto end; //Bool
    }
    }

    // web_player_features->images
    cJSON *images = cJSON_GetObjectItemCaseSensitive(web_player_featuresJSON, "images");
    if (cJSON_IsNull(images)) {
        images = NULL;
    }
    if (images) { 
    if(!cJSON_IsBool(images))
    {
    goto end; //Bool
    }
    }

    // web_player_features->messaging
    cJSON *messaging = cJSON_GetObjectItemCaseSensitive(web_player_featuresJSON, "messaging");
    if (cJSON_IsNull(messaging)) {
        messaging = NULL;
    }
    if (messaging) { 
    if(!cJSON_IsBool(messaging))
    {
    goto end; //Bool
    }
    }

    // web_player_features->netmon
    cJSON *netmon = cJSON_GetObjectItemCaseSensitive(web_player_featuresJSON, "netmon");
    if (cJSON_IsNull(netmon)) {
        netmon = NULL;
    }
    if (netmon) { 
    if(!cJSON_IsBool(netmon))
    {
    goto end; //Bool
    }
    }

    // web_player_features->network
    cJSON *network = cJSON_GetObjectItemCaseSensitive(web_player_featuresJSON, "network");
    if (cJSON_IsNull(network)) {
        network = NULL;
    }
    if (network) { 
    if(!cJSON_IsBool(network))
    {
    goto end; //Bool
    }
    }

    // web_player_features->port_forwarding
    cJSON *port_forwarding = cJSON_GetObjectItemCaseSensitive(web_player_featuresJSON, "portForwarding");
    if (cJSON_IsNull(port_forwarding)) {
        port_forwarding = NULL;
    }
    if (port_forwarding) { 
    if(!cJSON_IsBool(port_forwarding))
    {
    goto end; //Bool
    }
    }

    // web_player_features->power_management
    cJSON *power_management = cJSON_GetObjectItemCaseSensitive(web_player_featuresJSON, "powerManagement");
    if (cJSON_IsNull(power_management)) {
        power_management = NULL;
    }
    if (power_management) { 
    if(!cJSON_IsBool(power_management))
    {
    goto end; //Bool
    }
    }

    // web_player_features->profile
    cJSON *profile = cJSON_GetObjectItemCaseSensitive(web_player_featuresJSON, "profile");
    if (cJSON_IsNull(profile)) {
        profile = NULL;
    }
    if (profile) { 
    if(!cJSON_IsBool(profile))
    {
    goto end; //Bool
    }
    }

    // web_player_features->sensors
    cJSON *sensors = cJSON_GetObjectItemCaseSensitive(web_player_featuresJSON, "sensors");
    if (cJSON_IsNull(sensors)) {
        sensors = NULL;
    }
    if (sensors) { 
    if(!cJSON_IsBool(sensors))
    {
    goto end; //Bool
    }
    }

    // web_player_features->settings
    cJSON *settings = cJSON_GetObjectItemCaseSensitive(web_player_featuresJSON, "settings");
    if (cJSON_IsNull(settings)) {
        settings = NULL;
    }
    if (settings) { 
    if(!cJSON_IsBool(settings))
    {
    goto end; //Bool
    }
    }

    // web_player_features->snapshots
    cJSON *snapshots = cJSON_GetObjectItemCaseSensitive(web_player_featuresJSON, "snapshots");
    if (cJSON_IsNull(snapshots)) {
        snapshots = NULL;
    }
    if (snapshots) { 
    if(!cJSON_IsBool(snapshots))
    {
    goto end; //Bool
    }
    }

    // web_player_features->strace
    cJSON *strace = cJSON_GetObjectItemCaseSensitive(web_player_featuresJSON, "strace");
    if (cJSON_IsNull(strace)) {
        strace = NULL;
    }
    if (strace) { 
    if(!cJSON_IsBool(strace))
    {
    goto end; //Bool
    }
    }

    // web_player_features->system
    cJSON *system = cJSON_GetObjectItemCaseSensitive(web_player_featuresJSON, "system");
    if (cJSON_IsNull(system)) {
        system = NULL;
    }
    if (system) { 
    if(!cJSON_IsBool(system))
    {
    goto end; //Bool
    }
    }


    web_player_features_local_var = web_player_features_create_internal (
        apps ? apps->valueint : 0,
        connect ? connect->valueint : 0,
        console ? console->valueint : 0,
        coretrace ? coretrace->valueint : 0,
        device_control ? device_control->valueint : 0,
        device_delete ? device_delete->valueint : 0,
        files ? files->valueint : 0,
        frida ? frida->valueint : 0,
        images ? images->valueint : 0,
        messaging ? messaging->valueint : 0,
        netmon ? netmon->valueint : 0,
        network ? network->valueint : 0,
        port_forwarding ? port_forwarding->valueint : 0,
        power_management ? power_management->valueint : 0,
        profile ? profile->valueint : 0,
        sensors ? sensors->valueint : 0,
        settings ? settings->valueint : 0,
        snapshots ? snapshots->valueint : 0,
        strace ? strace->valueint : 0,
        system ? system->valueint : 0
        );

    return web_player_features_local_var;
end:
    return NULL;

}
