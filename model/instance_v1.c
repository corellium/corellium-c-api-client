#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instance_v1.h"



static instance_v1_t *instance_v1_create_internal(
    char *id,
    char *name,
    char *key,
    char *flavor,
    char *flavor_name,
    char *type,
    char *project,
    char *domain_name,
    corellium_api_instance_state_v1__e state,
    char *state_changed,
    char *started_at,
    char *user_task,
    char *task_state,
    char *error,
    instance_restore_status_v1_t *restore_status,
    instance_read_only_status_v1_t *read_only,
    instance_boot_options_v1_t *boot_options,
    char *service_ip,
    char *wifi_ip,
    char *wifi_mac,
    char *secondary_ip,
    double port_adb,
    double port_usb,
    double port_gdb,
    double port_sep_gdb,
    double port_cons,
    double port_sep_cons,
    double port_sys_cons,
    double port_usbmuxd,
    double port_frida,
    double port_sockcap,
    double port_model_gw,
    list_t *consoles,
    instance_services_v1_t *services,
    int panicked,
    char *created,
    char *model,
    char *fwpackage,
    char *os,
    char *osbuild,
    instance_agent_state_v1_t *agent,
    instance_netmon_state_v1_t *netmon,
    instance_netdump_state_v1_t *netdump,
    instance_trace_state_v1_t *core_trace,
    instance_hyper_trace_state_v1_t *hyper_trace,
    char *expose_port,
    int fault,
    list_t *patches,
    created_by_t *created_by,
    int uefi_bootloader,
    double orientation,
    int mast,
    int wan_access
    ) {
    instance_v1_t *instance_v1_local_var = malloc(sizeof(instance_v1_t));
    if (!instance_v1_local_var) {
        return NULL;
    }
    instance_v1_local_var->id = id;
    instance_v1_local_var->name = name;
    instance_v1_local_var->key = key;
    instance_v1_local_var->flavor = flavor;
    instance_v1_local_var->flavor_name = flavor_name;
    instance_v1_local_var->type = type;
    instance_v1_local_var->project = project;
    instance_v1_local_var->domain_name = domain_name;
    instance_v1_local_var->state = state;
    instance_v1_local_var->state_changed = state_changed;
    instance_v1_local_var->started_at = started_at;
    instance_v1_local_var->user_task = user_task;
    instance_v1_local_var->task_state = task_state;
    instance_v1_local_var->error = error;
    instance_v1_local_var->restore_status = restore_status;
    instance_v1_local_var->read_only = read_only;
    instance_v1_local_var->boot_options = boot_options;
    instance_v1_local_var->service_ip = service_ip;
    instance_v1_local_var->wifi_ip = wifi_ip;
    instance_v1_local_var->wifi_mac = wifi_mac;
    instance_v1_local_var->secondary_ip = secondary_ip;
    instance_v1_local_var->port_adb = port_adb;
    instance_v1_local_var->port_usb = port_usb;
    instance_v1_local_var->port_gdb = port_gdb;
    instance_v1_local_var->port_sep_gdb = port_sep_gdb;
    instance_v1_local_var->port_cons = port_cons;
    instance_v1_local_var->port_sep_cons = port_sep_cons;
    instance_v1_local_var->port_sys_cons = port_sys_cons;
    instance_v1_local_var->port_usbmuxd = port_usbmuxd;
    instance_v1_local_var->port_frida = port_frida;
    instance_v1_local_var->port_sockcap = port_sockcap;
    instance_v1_local_var->port_model_gw = port_model_gw;
    instance_v1_local_var->consoles = consoles;
    instance_v1_local_var->services = services;
    instance_v1_local_var->panicked = panicked;
    instance_v1_local_var->created = created;
    instance_v1_local_var->model = model;
    instance_v1_local_var->fwpackage = fwpackage;
    instance_v1_local_var->os = os;
    instance_v1_local_var->osbuild = osbuild;
    instance_v1_local_var->agent = agent;
    instance_v1_local_var->netmon = netmon;
    instance_v1_local_var->netdump = netdump;
    instance_v1_local_var->core_trace = core_trace;
    instance_v1_local_var->hyper_trace = hyper_trace;
    instance_v1_local_var->expose_port = expose_port;
    instance_v1_local_var->fault = fault;
    instance_v1_local_var->patches = patches;
    instance_v1_local_var->created_by = created_by;
    instance_v1_local_var->uefi_bootloader = uefi_bootloader;
    instance_v1_local_var->orientation = orientation;
    instance_v1_local_var->mast = mast;
    instance_v1_local_var->wan_access = wan_access;

    instance_v1_local_var->_library_owned = 1;
    return instance_v1_local_var;
}

__attribute__((deprecated)) instance_v1_t *instance_v1_create(
    char *id,
    char *name,
    char *key,
    char *flavor,
    char *flavor_name,
    char *type,
    char *project,
    char *domain_name,
    corellium_api_instance_state_v1__e state,
    char *state_changed,
    char *started_at,
    char *user_task,
    char *task_state,
    char *error,
    instance_restore_status_v1_t *restore_status,
    instance_read_only_status_v1_t *read_only,
    instance_boot_options_v1_t *boot_options,
    char *service_ip,
    char *wifi_ip,
    char *wifi_mac,
    char *secondary_ip,
    double port_adb,
    double port_usb,
    double port_gdb,
    double port_sep_gdb,
    double port_cons,
    double port_sep_cons,
    double port_sys_cons,
    double port_usbmuxd,
    double port_frida,
    double port_sockcap,
    double port_model_gw,
    list_t *consoles,
    instance_services_v1_t *services,
    int panicked,
    char *created,
    char *model,
    char *fwpackage,
    char *os,
    char *osbuild,
    instance_agent_state_v1_t *agent,
    instance_netmon_state_v1_t *netmon,
    instance_netdump_state_v1_t *netdump,
    instance_trace_state_v1_t *core_trace,
    instance_hyper_trace_state_v1_t *hyper_trace,
    char *expose_port,
    int fault,
    list_t *patches,
    created_by_t *created_by,
    int uefi_bootloader,
    double orientation,
    int mast,
    int wan_access
    ) {
    return instance_v1_create_internal (
        id,
        name,
        key,
        flavor,
        flavor_name,
        type,
        project,
        domain_name,
        state,
        state_changed,
        started_at,
        user_task,
        task_state,
        error,
        restore_status,
        read_only,
        boot_options,
        service_ip,
        wifi_ip,
        wifi_mac,
        secondary_ip,
        port_adb,
        port_usb,
        port_gdb,
        port_sep_gdb,
        port_cons,
        port_sep_cons,
        port_sys_cons,
        port_usbmuxd,
        port_frida,
        port_sockcap,
        port_model_gw,
        consoles,
        services,
        panicked,
        created,
        model,
        fwpackage,
        os,
        osbuild,
        agent,
        netmon,
        netdump,
        core_trace,
        hyper_trace,
        expose_port,
        fault,
        patches,
        created_by,
        uefi_bootloader,
        orientation,
        mast,
        wan_access
        );
}

void instance_v1_free(instance_v1_t *instance_v1) {
    if(NULL == instance_v1){
        return ;
    }
    if(instance_v1->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "instance_v1_free");
        return ;
    }
    listEntry_t *listEntry;
    if (instance_v1->id) {
        free(instance_v1->id);
        instance_v1->id = NULL;
    }
    if (instance_v1->name) {
        free(instance_v1->name);
        instance_v1->name = NULL;
    }
    if (instance_v1->key) {
        free(instance_v1->key);
        instance_v1->key = NULL;
    }
    if (instance_v1->flavor) {
        free(instance_v1->flavor);
        instance_v1->flavor = NULL;
    }
    if (instance_v1->flavor_name) {
        free(instance_v1->flavor_name);
        instance_v1->flavor_name = NULL;
    }
    if (instance_v1->type) {
        free(instance_v1->type);
        instance_v1->type = NULL;
    }
    if (instance_v1->project) {
        free(instance_v1->project);
        instance_v1->project = NULL;
    }
    if (instance_v1->domain_name) {
        free(instance_v1->domain_name);
        instance_v1->domain_name = NULL;
    }
    if (instance_v1->state_changed) {
        free(instance_v1->state_changed);
        instance_v1->state_changed = NULL;
    }
    if (instance_v1->started_at) {
        free(instance_v1->started_at);
        instance_v1->started_at = NULL;
    }
    if (instance_v1->user_task) {
        free(instance_v1->user_task);
        instance_v1->user_task = NULL;
    }
    if (instance_v1->task_state) {
        free(instance_v1->task_state);
        instance_v1->task_state = NULL;
    }
    if (instance_v1->error) {
        free(instance_v1->error);
        instance_v1->error = NULL;
    }
    if (instance_v1->restore_status) {
        instance_restore_status_v1_free(instance_v1->restore_status);
        instance_v1->restore_status = NULL;
    }
    if (instance_v1->read_only) {
        instance_read_only_status_v1_free(instance_v1->read_only);
        instance_v1->read_only = NULL;
    }
    if (instance_v1->boot_options) {
        instance_boot_options_v1_free(instance_v1->boot_options);
        instance_v1->boot_options = NULL;
    }
    if (instance_v1->service_ip) {
        free(instance_v1->service_ip);
        instance_v1->service_ip = NULL;
    }
    if (instance_v1->wifi_ip) {
        free(instance_v1->wifi_ip);
        instance_v1->wifi_ip = NULL;
    }
    if (instance_v1->wifi_mac) {
        free(instance_v1->wifi_mac);
        instance_v1->wifi_mac = NULL;
    }
    if (instance_v1->secondary_ip) {
        free(instance_v1->secondary_ip);
        instance_v1->secondary_ip = NULL;
    }
    if (instance_v1->consoles) {
        list_ForEach(listEntry, instance_v1->consoles) {
            instance_console_v1_free(listEntry->data);
        }
        list_freeList(instance_v1->consoles);
        instance_v1->consoles = NULL;
    }
    if (instance_v1->services) {
        instance_services_v1_free(instance_v1->services);
        instance_v1->services = NULL;
    }
    if (instance_v1->created) {
        free(instance_v1->created);
        instance_v1->created = NULL;
    }
    if (instance_v1->model) {
        free(instance_v1->model);
        instance_v1->model = NULL;
    }
    if (instance_v1->fwpackage) {
        free(instance_v1->fwpackage);
        instance_v1->fwpackage = NULL;
    }
    if (instance_v1->os) {
        free(instance_v1->os);
        instance_v1->os = NULL;
    }
    if (instance_v1->osbuild) {
        free(instance_v1->osbuild);
        instance_v1->osbuild = NULL;
    }
    if (instance_v1->agent) {
        instance_agent_state_v1_free(instance_v1->agent);
        instance_v1->agent = NULL;
    }
    if (instance_v1->netmon) {
        instance_netmon_state_v1_free(instance_v1->netmon);
        instance_v1->netmon = NULL;
    }
    if (instance_v1->netdump) {
        instance_netdump_state_v1_free(instance_v1->netdump);
        instance_v1->netdump = NULL;
    }
    if (instance_v1->core_trace) {
        instance_trace_state_v1_free(instance_v1->core_trace);
        instance_v1->core_trace = NULL;
    }
    if (instance_v1->hyper_trace) {
        instance_hyper_trace_state_v1_free(instance_v1->hyper_trace);
        instance_v1->hyper_trace = NULL;
    }
    if (instance_v1->expose_port) {
        free(instance_v1->expose_port);
        instance_v1->expose_port = NULL;
    }
    if (instance_v1->patches) {
        list_ForEach(listEntry, instance_v1->patches) {
            free(listEntry->data);
        }
        list_freeList(instance_v1->patches);
        instance_v1->patches = NULL;
    }
    if (instance_v1->created_by) {
        created_by_free(instance_v1->created_by);
        instance_v1->created_by = NULL;
    }
    free(instance_v1);
}

cJSON *instance_v1_convertToJSON(instance_v1_t *instance_v1) {
    cJSON *item = cJSON_CreateObject();

    // instance_v1->id
    if(instance_v1->id) {
    if(cJSON_AddStringToObject(item, "id", instance_v1->id) == NULL) {
    goto fail; //String
    }
    }


    // instance_v1->name
    if(instance_v1->name) {
    if(cJSON_AddStringToObject(item, "name", instance_v1->name) == NULL) {
    goto fail; //String
    }
    }


    // instance_v1->key
    if(instance_v1->key) {
    if(cJSON_AddStringToObject(item, "key", instance_v1->key) == NULL) {
    goto fail; //String
    }
    }


    // instance_v1->flavor
    if(instance_v1->flavor) {
    if(cJSON_AddStringToObject(item, "flavor", instance_v1->flavor) == NULL) {
    goto fail; //String
    }
    }


    // instance_v1->flavor_name
    if(instance_v1->flavor_name) {
    if(cJSON_AddStringToObject(item, "flavorName", instance_v1->flavor_name) == NULL) {
    goto fail; //String
    }
    }


    // instance_v1->type
    if(instance_v1->type) {
    if(cJSON_AddStringToObject(item, "type", instance_v1->type) == NULL) {
    goto fail; //String
    }
    }


    // instance_v1->project
    if(instance_v1->project) {
    if(cJSON_AddStringToObject(item, "project", instance_v1->project) == NULL) {
    goto fail; //String
    }
    }


    // instance_v1->domain_name
    if(instance_v1->domain_name) {
    if(cJSON_AddStringToObject(item, "domainName", instance_v1->domain_name) == NULL) {
    goto fail; //String
    }
    }


    // instance_v1->state
    if(instance_v1->state != corellium_api_instance_state_v1__NULL) {
    cJSON *state_local_JSON = instance_state_v1_convertToJSON(instance_v1->state);
    if(state_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "state", state_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }


    // instance_v1->state_changed
    if(instance_v1->state_changed) {
    if(cJSON_AddStringToObject(item, "stateChanged", instance_v1->state_changed) == NULL) {
    goto fail; //Date-Time
    }
    }


    // instance_v1->started_at
    if(instance_v1->started_at) {
    if(cJSON_AddStringToObject(item, "startedAt", instance_v1->started_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // instance_v1->user_task
    if(instance_v1->user_task) {
    if(cJSON_AddStringToObject(item, "userTask", instance_v1->user_task) == NULL) {
    goto fail; //String
    }
    }


    // instance_v1->task_state
    if(instance_v1->task_state) {
    if(cJSON_AddStringToObject(item, "taskState", instance_v1->task_state) == NULL) {
    goto fail; //String
    }
    }


    // instance_v1->error
    if(instance_v1->error) {
    if(cJSON_AddStringToObject(item, "error", instance_v1->error) == NULL) {
    goto fail; //String
    }
    }


    // instance_v1->restore_status
    if(instance_v1->restore_status) {
    cJSON *restore_status_local_JSON = instance_restore_status_v1_convertToJSON(instance_v1->restore_status);
    if(restore_status_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "restoreStatus", restore_status_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // instance_v1->read_only
    if(instance_v1->read_only) {
    cJSON *read_only_local_JSON = instance_read_only_status_v1_convertToJSON(instance_v1->read_only);
    if(read_only_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "readOnly", read_only_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // instance_v1->boot_options
    if(instance_v1->boot_options) {
    cJSON *boot_options_local_JSON = instance_boot_options_v1_convertToJSON(instance_v1->boot_options);
    if(boot_options_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "bootOptions", boot_options_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // instance_v1->service_ip
    if(instance_v1->service_ip) {
    if(cJSON_AddStringToObject(item, "serviceIp", instance_v1->service_ip) == NULL) {
    goto fail; //String
    }
    }


    // instance_v1->wifi_ip
    if(instance_v1->wifi_ip) {
    if(cJSON_AddStringToObject(item, "wifiIp", instance_v1->wifi_ip) == NULL) {
    goto fail; //String
    }
    }


    // instance_v1->wifi_mac
    if(instance_v1->wifi_mac) {
    if(cJSON_AddStringToObject(item, "wifiMac", instance_v1->wifi_mac) == NULL) {
    goto fail; //String
    }
    }


    // instance_v1->secondary_ip
    if(instance_v1->secondary_ip) {
    if(cJSON_AddStringToObject(item, "secondaryIp", instance_v1->secondary_ip) == NULL) {
    goto fail; //String
    }
    }


    // instance_v1->port_adb
    if(instance_v1->port_adb) {
    if(cJSON_AddNumberToObject(item, "port-adb", instance_v1->port_adb) == NULL) {
    goto fail; //Numeric
    }
    }


    // instance_v1->port_usb
    if(instance_v1->port_usb) {
    if(cJSON_AddNumberToObject(item, "port-usb", instance_v1->port_usb) == NULL) {
    goto fail; //Numeric
    }
    }


    // instance_v1->port_gdb
    if(instance_v1->port_gdb) {
    if(cJSON_AddNumberToObject(item, "port-gdb", instance_v1->port_gdb) == NULL) {
    goto fail; //Numeric
    }
    }


    // instance_v1->port_sep_gdb
    if(instance_v1->port_sep_gdb) {
    if(cJSON_AddNumberToObject(item, "port-sep-gdb", instance_v1->port_sep_gdb) == NULL) {
    goto fail; //Numeric
    }
    }


    // instance_v1->port_cons
    if(instance_v1->port_cons) {
    if(cJSON_AddNumberToObject(item, "port-cons", instance_v1->port_cons) == NULL) {
    goto fail; //Numeric
    }
    }


    // instance_v1->port_sep_cons
    if(instance_v1->port_sep_cons) {
    if(cJSON_AddNumberToObject(item, "port-sep-cons", instance_v1->port_sep_cons) == NULL) {
    goto fail; //Numeric
    }
    }


    // instance_v1->port_sys_cons
    if(instance_v1->port_sys_cons) {
    if(cJSON_AddNumberToObject(item, "port-sys-cons", instance_v1->port_sys_cons) == NULL) {
    goto fail; //Numeric
    }
    }


    // instance_v1->port_usbmuxd
    if(instance_v1->port_usbmuxd) {
    if(cJSON_AddNumberToObject(item, "port-usbmuxd", instance_v1->port_usbmuxd) == NULL) {
    goto fail; //Numeric
    }
    }


    // instance_v1->port_frida
    if(instance_v1->port_frida) {
    if(cJSON_AddNumberToObject(item, "port-frida", instance_v1->port_frida) == NULL) {
    goto fail; //Numeric
    }
    }


    // instance_v1->port_sockcap
    if(instance_v1->port_sockcap) {
    if(cJSON_AddNumberToObject(item, "port-sockcap", instance_v1->port_sockcap) == NULL) {
    goto fail; //Numeric
    }
    }


    // instance_v1->port_model_gw
    if(instance_v1->port_model_gw) {
    if(cJSON_AddNumberToObject(item, "port-model-gw", instance_v1->port_model_gw) == NULL) {
    goto fail; //Numeric
    }
    }


    // instance_v1->consoles
    if(instance_v1->consoles) {
    cJSON *consoles = cJSON_AddArrayToObject(item, "consoles");
    if(consoles == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *consolesListEntry;
    if (instance_v1->consoles) {
    list_ForEach(consolesListEntry, instance_v1->consoles) {
    cJSON *itemLocal = instance_console_v1_convertToJSON(consolesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(consoles, itemLocal);
    }
    }
    }


    // instance_v1->services
    if(instance_v1->services) {
    cJSON *services_local_JSON = instance_services_v1_convertToJSON(instance_v1->services);
    if(services_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "services", services_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // instance_v1->panicked
    if(instance_v1->panicked) {
    if(cJSON_AddBoolToObject(item, "panicked", instance_v1->panicked) == NULL) {
    goto fail; //Bool
    }
    }


    // instance_v1->created
    if(instance_v1->created) {
    if(cJSON_AddStringToObject(item, "created", instance_v1->created) == NULL) {
    goto fail; //Date-Time
    }
    }


    // instance_v1->model
    if(instance_v1->model) {
    if(cJSON_AddStringToObject(item, "model", instance_v1->model) == NULL) {
    goto fail; //String
    }
    }


    // instance_v1->fwpackage
    if(instance_v1->fwpackage) {
    if(cJSON_AddStringToObject(item, "fwpackage", instance_v1->fwpackage) == NULL) {
    goto fail; //String
    }
    }


    // instance_v1->os
    if(instance_v1->os) {
    if(cJSON_AddStringToObject(item, "os", instance_v1->os) == NULL) {
    goto fail; //String
    }
    }


    // instance_v1->osbuild
    if(instance_v1->osbuild) {
    if(cJSON_AddStringToObject(item, "osbuild", instance_v1->osbuild) == NULL) {
    goto fail; //String
    }
    }


    // instance_v1->agent
    if(instance_v1->agent) {
    cJSON *agent_local_JSON = instance_agent_state_v1_convertToJSON(instance_v1->agent);
    if(agent_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "agent", agent_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // instance_v1->netmon
    if(instance_v1->netmon) {
    cJSON *netmon_local_JSON = instance_netmon_state_v1_convertToJSON(instance_v1->netmon);
    if(netmon_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "netmon", netmon_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // instance_v1->netdump
    if(instance_v1->netdump) {
    cJSON *netdump_local_JSON = instance_netdump_state_v1_convertToJSON(instance_v1->netdump);
    if(netdump_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "netdump", netdump_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // instance_v1->core_trace
    if(instance_v1->core_trace) {
    cJSON *core_trace_local_JSON = instance_trace_state_v1_convertToJSON(instance_v1->core_trace);
    if(core_trace_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "coreTrace", core_trace_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // instance_v1->hyper_trace
    if(instance_v1->hyper_trace) {
    cJSON *hyper_trace_local_JSON = instance_hyper_trace_state_v1_convertToJSON(instance_v1->hyper_trace);
    if(hyper_trace_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "hyperTrace", hyper_trace_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // instance_v1->expose_port
    if(instance_v1->expose_port) {
    if(cJSON_AddStringToObject(item, "exposePort", instance_v1->expose_port) == NULL) {
    goto fail; //String
    }
    }


    // instance_v1->fault
    if(instance_v1->fault) {
    if(cJSON_AddBoolToObject(item, "fault", instance_v1->fault) == NULL) {
    goto fail; //Bool
    }
    }


    // instance_v1->patches
    if(instance_v1->patches) {
    cJSON *patches = cJSON_AddArrayToObject(item, "patches");
    if(patches == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *patchesListEntry;
    list_ForEach(patchesListEntry, instance_v1->patches) {
    if(cJSON_AddStringToObject(patches, "", patchesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // instance_v1->created_by
    if(instance_v1->created_by) {
    cJSON *created_by_local_JSON = created_by_convertToJSON(instance_v1->created_by);
    if(created_by_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "createdBy", created_by_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // instance_v1->uefi_bootloader
    if(instance_v1->uefi_bootloader) {
    if(cJSON_AddBoolToObject(item, "uefiBootloader", instance_v1->uefi_bootloader) == NULL) {
    goto fail; //Bool
    }
    }


    // instance_v1->orientation
    if(instance_v1->orientation) {
    if(cJSON_AddNumberToObject(item, "orientation", instance_v1->orientation) == NULL) {
    goto fail; //Numeric
    }
    }


    // instance_v1->mast
    if(instance_v1->mast) {
    if(cJSON_AddBoolToObject(item, "mast", instance_v1->mast) == NULL) {
    goto fail; //Bool
    }
    }


    // instance_v1->wan_access
    if(instance_v1->wan_access) {
    if(cJSON_AddBoolToObject(item, "wanAccess", instance_v1->wan_access) == NULL) {
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

instance_v1_t *instance_v1_parseFromJSON(cJSON *instance_v1JSON){

    instance_v1_t *instance_v1_local_var = NULL;

    // define the local variable for instance_v1->state
    corellium_api_instance_state_v1__e state_local_nonprim = 0;

    // define the local variable for instance_v1->restore_status
    instance_restore_status_v1_t *restore_status_local_nonprim = NULL;

    // define the local variable for instance_v1->read_only
    instance_read_only_status_v1_t *read_only_local_nonprim = NULL;

    // define the local variable for instance_v1->boot_options
    instance_boot_options_v1_t *boot_options_local_nonprim = NULL;

    // define the local list for instance_v1->consoles
    list_t *consolesList = NULL;

    // define the local variable for instance_v1->services
    instance_services_v1_t *services_local_nonprim = NULL;

    // define the local variable for instance_v1->agent
    instance_agent_state_v1_t *agent_local_nonprim = NULL;

    // define the local variable for instance_v1->netmon
    instance_netmon_state_v1_t *netmon_local_nonprim = NULL;

    // define the local variable for instance_v1->netdump
    instance_netdump_state_v1_t *netdump_local_nonprim = NULL;

    // define the local variable for instance_v1->core_trace
    instance_trace_state_v1_t *core_trace_local_nonprim = NULL;

    // define the local variable for instance_v1->hyper_trace
    instance_hyper_trace_state_v1_t *hyper_trace_local_nonprim = NULL;

    // define the local list for instance_v1->patches
    list_t *patchesList = NULL;

    // define the local variable for instance_v1->created_by
    created_by_t *created_by_local_nonprim = NULL;

    // instance_v1->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (id) { 
    if(!cJSON_IsString(id) && !cJSON_IsNull(id))
    {
    goto end; //String
    }
    }

    // instance_v1->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // instance_v1->key
    cJSON *key = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "key");
    if (cJSON_IsNull(key)) {
        key = NULL;
    }
    if (key) { 
    if(!cJSON_IsString(key) && !cJSON_IsNull(key))
    {
    goto end; //String
    }
    }

    // instance_v1->flavor
    cJSON *flavor = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "flavor");
    if (cJSON_IsNull(flavor)) {
        flavor = NULL;
    }
    if (flavor) { 
    if(!cJSON_IsString(flavor) && !cJSON_IsNull(flavor))
    {
    goto end; //String
    }
    }

    // instance_v1->flavor_name
    cJSON *flavor_name = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "flavorName");
    if (cJSON_IsNull(flavor_name)) {
        flavor_name = NULL;
    }
    if (flavor_name) { 
    if(!cJSON_IsString(flavor_name) && !cJSON_IsNull(flavor_name))
    {
    goto end; //String
    }
    }

    // instance_v1->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }

    // instance_v1->project
    cJSON *project = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "project");
    if (cJSON_IsNull(project)) {
        project = NULL;
    }
    if (project) { 
    if(!cJSON_IsString(project) && !cJSON_IsNull(project))
    {
    goto end; //String
    }
    }

    // instance_v1->domain_name
    cJSON *domain_name = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "domainName");
    if (cJSON_IsNull(domain_name)) {
        domain_name = NULL;
    }
    if (domain_name) { 
    if(!cJSON_IsString(domain_name) && !cJSON_IsNull(domain_name))
    {
    goto end; //String
    }
    }

    // instance_v1->state
    cJSON *state = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "state");
    if (cJSON_IsNull(state)) {
        state = NULL;
    }
    if (state) { 
    state_local_nonprim = instance_state_v1_parseFromJSON(state); //custom
    }

    // instance_v1->state_changed
    cJSON *state_changed = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "stateChanged");
    if (cJSON_IsNull(state_changed)) {
        state_changed = NULL;
    }
    if (state_changed) { 
    if(!cJSON_IsString(state_changed) && !cJSON_IsNull(state_changed))
    {
    goto end; //DateTime
    }
    }

    // instance_v1->started_at
    cJSON *started_at = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "startedAt");
    if (cJSON_IsNull(started_at)) {
        started_at = NULL;
    }
    if (started_at) { 
    if(!cJSON_IsString(started_at) && !cJSON_IsNull(started_at))
    {
    goto end; //DateTime
    }
    }

    // instance_v1->user_task
    cJSON *user_task = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "userTask");
    if (cJSON_IsNull(user_task)) {
        user_task = NULL;
    }
    if (user_task) { 
    if(!cJSON_IsString(user_task) && !cJSON_IsNull(user_task))
    {
    goto end; //String
    }
    }

    // instance_v1->task_state
    cJSON *task_state = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "taskState");
    if (cJSON_IsNull(task_state)) {
        task_state = NULL;
    }
    if (task_state) { 
    if(!cJSON_IsString(task_state) && !cJSON_IsNull(task_state))
    {
    goto end; //String
    }
    }

    // instance_v1->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "error");
    if (cJSON_IsNull(error)) {
        error = NULL;
    }
    if (error) { 
    if(!cJSON_IsString(error) && !cJSON_IsNull(error))
    {
    goto end; //String
    }
    }

    // instance_v1->restore_status
    cJSON *restore_status = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "restoreStatus");
    if (cJSON_IsNull(restore_status)) {
        restore_status = NULL;
    }
    if (restore_status) { 
    restore_status_local_nonprim = instance_restore_status_v1_parseFromJSON(restore_status); //nonprimitive
    }

    // instance_v1->read_only
    cJSON *read_only = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "readOnly");
    if (cJSON_IsNull(read_only)) {
        read_only = NULL;
    }
    if (read_only) { 
    read_only_local_nonprim = instance_read_only_status_v1_parseFromJSON(read_only); //nonprimitive
    }

    // instance_v1->boot_options
    cJSON *boot_options = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "bootOptions");
    if (cJSON_IsNull(boot_options)) {
        boot_options = NULL;
    }
    if (boot_options) { 
    boot_options_local_nonprim = instance_boot_options_v1_parseFromJSON(boot_options); //nonprimitive
    }

    // instance_v1->service_ip
    cJSON *service_ip = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "serviceIp");
    if (cJSON_IsNull(service_ip)) {
        service_ip = NULL;
    }
    if (service_ip) { 
    if(!cJSON_IsString(service_ip) && !cJSON_IsNull(service_ip))
    {
    goto end; //String
    }
    }

    // instance_v1->wifi_ip
    cJSON *wifi_ip = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "wifiIp");
    if (cJSON_IsNull(wifi_ip)) {
        wifi_ip = NULL;
    }
    if (wifi_ip) { 
    if(!cJSON_IsString(wifi_ip) && !cJSON_IsNull(wifi_ip))
    {
    goto end; //String
    }
    }

    // instance_v1->wifi_mac
    cJSON *wifi_mac = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "wifiMac");
    if (cJSON_IsNull(wifi_mac)) {
        wifi_mac = NULL;
    }
    if (wifi_mac) { 
    if(!cJSON_IsString(wifi_mac) && !cJSON_IsNull(wifi_mac))
    {
    goto end; //String
    }
    }

    // instance_v1->secondary_ip
    cJSON *secondary_ip = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "secondaryIp");
    if (cJSON_IsNull(secondary_ip)) {
        secondary_ip = NULL;
    }
    if (secondary_ip) { 
    if(!cJSON_IsString(secondary_ip) && !cJSON_IsNull(secondary_ip))
    {
    goto end; //String
    }
    }

    // instance_v1->port_adb
    cJSON *port_adb = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "port-adb");
    if (cJSON_IsNull(port_adb)) {
        port_adb = NULL;
    }
    if (port_adb) { 
    if(!cJSON_IsNumber(port_adb))
    {
    goto end; //Numeric
    }
    }

    // instance_v1->port_usb
    cJSON *port_usb = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "port-usb");
    if (cJSON_IsNull(port_usb)) {
        port_usb = NULL;
    }
    if (port_usb) { 
    if(!cJSON_IsNumber(port_usb))
    {
    goto end; //Numeric
    }
    }

    // instance_v1->port_gdb
    cJSON *port_gdb = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "port-gdb");
    if (cJSON_IsNull(port_gdb)) {
        port_gdb = NULL;
    }
    if (port_gdb) { 
    if(!cJSON_IsNumber(port_gdb))
    {
    goto end; //Numeric
    }
    }

    // instance_v1->port_sep_gdb
    cJSON *port_sep_gdb = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "port-sep-gdb");
    if (cJSON_IsNull(port_sep_gdb)) {
        port_sep_gdb = NULL;
    }
    if (port_sep_gdb) { 
    if(!cJSON_IsNumber(port_sep_gdb))
    {
    goto end; //Numeric
    }
    }

    // instance_v1->port_cons
    cJSON *port_cons = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "port-cons");
    if (cJSON_IsNull(port_cons)) {
        port_cons = NULL;
    }
    if (port_cons) { 
    if(!cJSON_IsNumber(port_cons))
    {
    goto end; //Numeric
    }
    }

    // instance_v1->port_sep_cons
    cJSON *port_sep_cons = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "port-sep-cons");
    if (cJSON_IsNull(port_sep_cons)) {
        port_sep_cons = NULL;
    }
    if (port_sep_cons) { 
    if(!cJSON_IsNumber(port_sep_cons))
    {
    goto end; //Numeric
    }
    }

    // instance_v1->port_sys_cons
    cJSON *port_sys_cons = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "port-sys-cons");
    if (cJSON_IsNull(port_sys_cons)) {
        port_sys_cons = NULL;
    }
    if (port_sys_cons) { 
    if(!cJSON_IsNumber(port_sys_cons))
    {
    goto end; //Numeric
    }
    }

    // instance_v1->port_usbmuxd
    cJSON *port_usbmuxd = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "port-usbmuxd");
    if (cJSON_IsNull(port_usbmuxd)) {
        port_usbmuxd = NULL;
    }
    if (port_usbmuxd) { 
    if(!cJSON_IsNumber(port_usbmuxd))
    {
    goto end; //Numeric
    }
    }

    // instance_v1->port_frida
    cJSON *port_frida = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "port-frida");
    if (cJSON_IsNull(port_frida)) {
        port_frida = NULL;
    }
    if (port_frida) { 
    if(!cJSON_IsNumber(port_frida))
    {
    goto end; //Numeric
    }
    }

    // instance_v1->port_sockcap
    cJSON *port_sockcap = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "port-sockcap");
    if (cJSON_IsNull(port_sockcap)) {
        port_sockcap = NULL;
    }
    if (port_sockcap) { 
    if(!cJSON_IsNumber(port_sockcap))
    {
    goto end; //Numeric
    }
    }

    // instance_v1->port_model_gw
    cJSON *port_model_gw = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "port-model-gw");
    if (cJSON_IsNull(port_model_gw)) {
        port_model_gw = NULL;
    }
    if (port_model_gw) { 
    if(!cJSON_IsNumber(port_model_gw))
    {
    goto end; //Numeric
    }
    }

    // instance_v1->consoles
    cJSON *consoles = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "consoles");
    if (cJSON_IsNull(consoles)) {
        consoles = NULL;
    }
    if (consoles) { 
    cJSON *consoles_local_nonprimitive = NULL;
    if(!cJSON_IsArray(consoles)){
        goto end; //nonprimitive container
    }

    consolesList = list_createList();

    cJSON_ArrayForEach(consoles_local_nonprimitive,consoles )
    {
        if(!cJSON_IsObject(consoles_local_nonprimitive)){
            goto end;
        }
        instance_console_v1_t *consolesItem = instance_console_v1_parseFromJSON(consoles_local_nonprimitive);

        list_addElement(consolesList, consolesItem);
    }
    }

    // instance_v1->services
    cJSON *services = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "services");
    if (cJSON_IsNull(services)) {
        services = NULL;
    }
    if (services) { 
    services_local_nonprim = instance_services_v1_parseFromJSON(services); //nonprimitive
    }

    // instance_v1->panicked
    cJSON *panicked = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "panicked");
    if (cJSON_IsNull(panicked)) {
        panicked = NULL;
    }
    if (panicked) { 
    if(!cJSON_IsBool(panicked))
    {
    goto end; //Bool
    }
    }

    // instance_v1->created
    cJSON *created = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "created");
    if (cJSON_IsNull(created)) {
        created = NULL;
    }
    if (created) { 
    if(!cJSON_IsString(created) && !cJSON_IsNull(created))
    {
    goto end; //DateTime
    }
    }

    // instance_v1->model
    cJSON *model = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "model");
    if (cJSON_IsNull(model)) {
        model = NULL;
    }
    if (model) { 
    if(!cJSON_IsString(model) && !cJSON_IsNull(model))
    {
    goto end; //String
    }
    }

    // instance_v1->fwpackage
    cJSON *fwpackage = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "fwpackage");
    if (cJSON_IsNull(fwpackage)) {
        fwpackage = NULL;
    }
    if (fwpackage) { 
    if(!cJSON_IsString(fwpackage) && !cJSON_IsNull(fwpackage))
    {
    goto end; //String
    }
    }

    // instance_v1->os
    cJSON *os = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "os");
    if (cJSON_IsNull(os)) {
        os = NULL;
    }
    if (os) { 
    if(!cJSON_IsString(os) && !cJSON_IsNull(os))
    {
    goto end; //String
    }
    }

    // instance_v1->osbuild
    cJSON *osbuild = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "osbuild");
    if (cJSON_IsNull(osbuild)) {
        osbuild = NULL;
    }
    if (osbuild) { 
    if(!cJSON_IsString(osbuild) && !cJSON_IsNull(osbuild))
    {
    goto end; //String
    }
    }

    // instance_v1->agent
    cJSON *agent = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "agent");
    if (cJSON_IsNull(agent)) {
        agent = NULL;
    }
    if (agent) { 
    agent_local_nonprim = instance_agent_state_v1_parseFromJSON(agent); //nonprimitive
    }

    // instance_v1->netmon
    cJSON *netmon = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "netmon");
    if (cJSON_IsNull(netmon)) {
        netmon = NULL;
    }
    if (netmon) { 
    netmon_local_nonprim = instance_netmon_state_v1_parseFromJSON(netmon); //nonprimitive
    }

    // instance_v1->netdump
    cJSON *netdump = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "netdump");
    if (cJSON_IsNull(netdump)) {
        netdump = NULL;
    }
    if (netdump) { 
    netdump_local_nonprim = instance_netdump_state_v1_parseFromJSON(netdump); //nonprimitive
    }

    // instance_v1->core_trace
    cJSON *core_trace = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "coreTrace");
    if (cJSON_IsNull(core_trace)) {
        core_trace = NULL;
    }
    if (core_trace) { 
    core_trace_local_nonprim = instance_trace_state_v1_parseFromJSON(core_trace); //nonprimitive
    }

    // instance_v1->hyper_trace
    cJSON *hyper_trace = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "hyperTrace");
    if (cJSON_IsNull(hyper_trace)) {
        hyper_trace = NULL;
    }
    if (hyper_trace) { 
    hyper_trace_local_nonprim = instance_hyper_trace_state_v1_parseFromJSON(hyper_trace); //nonprimitive
    }

    // instance_v1->expose_port
    cJSON *expose_port = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "exposePort");
    if (cJSON_IsNull(expose_port)) {
        expose_port = NULL;
    }
    if (expose_port) { 
    if(!cJSON_IsString(expose_port) && !cJSON_IsNull(expose_port))
    {
    goto end; //String
    }
    }

    // instance_v1->fault
    cJSON *fault = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "fault");
    if (cJSON_IsNull(fault)) {
        fault = NULL;
    }
    if (fault) { 
    if(!cJSON_IsBool(fault))
    {
    goto end; //Bool
    }
    }

    // instance_v1->patches
    cJSON *patches = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "patches");
    if (cJSON_IsNull(patches)) {
        patches = NULL;
    }
    if (patches) { 
    cJSON *patches_local = NULL;
    if(!cJSON_IsArray(patches)) {
        goto end;//primitive container
    }
    patchesList = list_createList();

    cJSON_ArrayForEach(patches_local, patches)
    {
        if(!cJSON_IsString(patches_local))
        {
            goto end;
        }
        list_addElement(patchesList , strdup(patches_local->valuestring));
    }
    }

    // instance_v1->created_by
    cJSON *created_by = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "createdBy");
    if (cJSON_IsNull(created_by)) {
        created_by = NULL;
    }
    if (created_by) { 
    created_by_local_nonprim = created_by_parseFromJSON(created_by); //nonprimitive
    }

    // instance_v1->uefi_bootloader
    cJSON *uefi_bootloader = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "uefiBootloader");
    if (cJSON_IsNull(uefi_bootloader)) {
        uefi_bootloader = NULL;
    }
    if (uefi_bootloader) { 
    if(!cJSON_IsBool(uefi_bootloader))
    {
    goto end; //Bool
    }
    }

    // instance_v1->orientation
    cJSON *orientation = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "orientation");
    if (cJSON_IsNull(orientation)) {
        orientation = NULL;
    }
    if (orientation) { 
    if(!cJSON_IsNumber(orientation))
    {
    goto end; //Numeric
    }
    }

    // instance_v1->mast
    cJSON *mast = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "mast");
    if (cJSON_IsNull(mast)) {
        mast = NULL;
    }
    if (mast) { 
    if(!cJSON_IsBool(mast))
    {
    goto end; //Bool
    }
    }

    // instance_v1->wan_access
    cJSON *wan_access = cJSON_GetObjectItemCaseSensitive(instance_v1JSON, "wanAccess");
    if (cJSON_IsNull(wan_access)) {
        wan_access = NULL;
    }
    if (wan_access) { 
    if(!cJSON_IsBool(wan_access))
    {
    goto end; //Bool
    }
    }


    instance_v1_local_var = instance_v1_create_internal (
        id && !cJSON_IsNull(id) ? strdup(id->valuestring) : NULL,
        name && !cJSON_IsNull(name) ? strdup(name->valuestring) : NULL,
        key && !cJSON_IsNull(key) ? strdup(key->valuestring) : NULL,
        flavor && !cJSON_IsNull(flavor) ? strdup(flavor->valuestring) : NULL,
        flavor_name && !cJSON_IsNull(flavor_name) ? strdup(flavor_name->valuestring) : NULL,
        type && !cJSON_IsNull(type) ? strdup(type->valuestring) : NULL,
        project && !cJSON_IsNull(project) ? strdup(project->valuestring) : NULL,
        domain_name && !cJSON_IsNull(domain_name) ? strdup(domain_name->valuestring) : NULL,
        state ? state_local_nonprim : 0,
        state_changed && !cJSON_IsNull(state_changed) ? strdup(state_changed->valuestring) : NULL,
        started_at && !cJSON_IsNull(started_at) ? strdup(started_at->valuestring) : NULL,
        user_task && !cJSON_IsNull(user_task) ? strdup(user_task->valuestring) : NULL,
        task_state && !cJSON_IsNull(task_state) ? strdup(task_state->valuestring) : NULL,
        error && !cJSON_IsNull(error) ? strdup(error->valuestring) : NULL,
        restore_status ? restore_status_local_nonprim : NULL,
        read_only ? read_only_local_nonprim : NULL,
        boot_options ? boot_options_local_nonprim : NULL,
        service_ip && !cJSON_IsNull(service_ip) ? strdup(service_ip->valuestring) : NULL,
        wifi_ip && !cJSON_IsNull(wifi_ip) ? strdup(wifi_ip->valuestring) : NULL,
        wifi_mac && !cJSON_IsNull(wifi_mac) ? strdup(wifi_mac->valuestring) : NULL,
        secondary_ip && !cJSON_IsNull(secondary_ip) ? strdup(secondary_ip->valuestring) : NULL,
        port_adb ? port_adb->valuedouble : 0,
        port_usb ? port_usb->valuedouble : 0,
        port_gdb ? port_gdb->valuedouble : 0,
        port_sep_gdb ? port_sep_gdb->valuedouble : 0,
        port_cons ? port_cons->valuedouble : 0,
        port_sep_cons ? port_sep_cons->valuedouble : 0,
        port_sys_cons ? port_sys_cons->valuedouble : 0,
        port_usbmuxd ? port_usbmuxd->valuedouble : 0,
        port_frida ? port_frida->valuedouble : 0,
        port_sockcap ? port_sockcap->valuedouble : 0,
        port_model_gw ? port_model_gw->valuedouble : 0,
        consoles ? consolesList : NULL,
        services ? services_local_nonprim : NULL,
        panicked ? panicked->valueint : 0,
        created && !cJSON_IsNull(created) ? strdup(created->valuestring) : NULL,
        model && !cJSON_IsNull(model) ? strdup(model->valuestring) : NULL,
        fwpackage && !cJSON_IsNull(fwpackage) ? strdup(fwpackage->valuestring) : NULL,
        os && !cJSON_IsNull(os) ? strdup(os->valuestring) : NULL,
        osbuild && !cJSON_IsNull(osbuild) ? strdup(osbuild->valuestring) : NULL,
        agent ? agent_local_nonprim : NULL,
        netmon ? netmon_local_nonprim : NULL,
        netdump ? netdump_local_nonprim : NULL,
        core_trace ? core_trace_local_nonprim : NULL,
        hyper_trace ? hyper_trace_local_nonprim : NULL,
        expose_port && !cJSON_IsNull(expose_port) ? strdup(expose_port->valuestring) : NULL,
        fault ? fault->valueint : 0,
        patches ? patchesList : NULL,
        created_by ? created_by_local_nonprim : NULL,
        uefi_bootloader ? uefi_bootloader->valueint : 0,
        orientation ? orientation->valuedouble : 0,
        mast ? mast->valueint : 0,
        wan_access ? wan_access->valueint : 0
        );

    return instance_v1_local_var;
end:
    if (state_local_nonprim) {
        state_local_nonprim = 0;
    }
    if (restore_status_local_nonprim) {
        instance_restore_status_v1_free(restore_status_local_nonprim);
        restore_status_local_nonprim = NULL;
    }
    if (read_only_local_nonprim) {
        instance_read_only_status_v1_free(read_only_local_nonprim);
        read_only_local_nonprim = NULL;
    }
    if (boot_options_local_nonprim) {
        instance_boot_options_v1_free(boot_options_local_nonprim);
        boot_options_local_nonprim = NULL;
    }
    if (consolesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, consolesList) {
            instance_console_v1_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(consolesList);
        consolesList = NULL;
    }
    if (services_local_nonprim) {
        instance_services_v1_free(services_local_nonprim);
        services_local_nonprim = NULL;
    }
    if (agent_local_nonprim) {
        instance_agent_state_v1_free(agent_local_nonprim);
        agent_local_nonprim = NULL;
    }
    if (netmon_local_nonprim) {
        instance_netmon_state_v1_free(netmon_local_nonprim);
        netmon_local_nonprim = NULL;
    }
    if (netdump_local_nonprim) {
        instance_netdump_state_v1_free(netdump_local_nonprim);
        netdump_local_nonprim = NULL;
    }
    if (core_trace_local_nonprim) {
        instance_trace_state_v1_free(core_trace_local_nonprim);
        core_trace_local_nonprim = NULL;
    }
    if (hyper_trace_local_nonprim) {
        instance_hyper_trace_state_v1_free(hyper_trace_local_nonprim);
        hyper_trace_local_nonprim = NULL;
    }
    if (patchesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, patchesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(patchesList);
        patchesList = NULL;
    }
    if (created_by_local_nonprim) {
        created_by_free(created_by_local_nonprim);
        created_by_local_nonprim = NULL;
    }
    return NULL;

}
