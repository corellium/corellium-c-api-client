#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instance.h"



static instance_t *instance_create_internal(
    char *id,
    char *name,
    char *key,
    char *flavor,
    char *flavor_name,
    char *type,
    char *project,
    char *domain_name,
    corellium_api_instance_state__e state,
    char *state_changed,
    char *started_at,
    char *user_task,
    char *task_state,
    char *error,
    instance_restore_status_t *restore_status,
    instance_read_only_status_t *read_only,
    instance_boot_options_t *boot_options,
    char *service_ip,
    char *wifi_ip,
    char *wifi_mac,
    char *secondary_ip,
    char *port_adb,
    char *port_usb,
    char *port_gdb,
    char *port_sep_gdb,
    char *port_cons,
    char *port_sep_cons,
    char *port_sys_cons,
    char *port_usbmuxd,
    char *port_frida,
    char *port_sockcap,
    char *port_model_gw,
    list_t *consoles,
    list_t *interfaces,
    instance_services_t *services,
    int panicked,
    char *created,
    char *model,
    char *fw_package,
    char *os_version,
    char *os_build,
    instance_agent_state_t *agent,
    instance_netmon_state_t *net_mon,
    instance_netdump_state_t *net_dump,
    instance_trace_state_t *core_trace,
    instance_hyper_trace_state_t *hyper_trace,
    char *expose_port,
    int fault,
    list_t *patches,
    created_by_t *created_by,
    instance_uefi_bootloader_t *uefi_bootloader,
    double orientation,
    int mast,
    int wan_access,
    int has_corelliumd
    ) {
    instance_t *instance_local_var = malloc(sizeof(instance_t));
    if (!instance_local_var) {
        return NULL;
    }
    instance_local_var->id = id;
    instance_local_var->name = name;
    instance_local_var->key = key;
    instance_local_var->flavor = flavor;
    instance_local_var->flavor_name = flavor_name;
    instance_local_var->type = type;
    instance_local_var->project = project;
    instance_local_var->domain_name = domain_name;
    instance_local_var->state = state;
    instance_local_var->state_changed = state_changed;
    instance_local_var->started_at = started_at;
    instance_local_var->user_task = user_task;
    instance_local_var->task_state = task_state;
    instance_local_var->error = error;
    instance_local_var->restore_status = restore_status;
    instance_local_var->read_only = read_only;
    instance_local_var->boot_options = boot_options;
    instance_local_var->service_ip = service_ip;
    instance_local_var->wifi_ip = wifi_ip;
    instance_local_var->wifi_mac = wifi_mac;
    instance_local_var->secondary_ip = secondary_ip;
    instance_local_var->port_adb = port_adb;
    instance_local_var->port_usb = port_usb;
    instance_local_var->port_gdb = port_gdb;
    instance_local_var->port_sep_gdb = port_sep_gdb;
    instance_local_var->port_cons = port_cons;
    instance_local_var->port_sep_cons = port_sep_cons;
    instance_local_var->port_sys_cons = port_sys_cons;
    instance_local_var->port_usbmuxd = port_usbmuxd;
    instance_local_var->port_frida = port_frida;
    instance_local_var->port_sockcap = port_sockcap;
    instance_local_var->port_model_gw = port_model_gw;
    instance_local_var->consoles = consoles;
    instance_local_var->interfaces = interfaces;
    instance_local_var->services = services;
    instance_local_var->panicked = panicked;
    instance_local_var->created = created;
    instance_local_var->model = model;
    instance_local_var->fw_package = fw_package;
    instance_local_var->os_version = os_version;
    instance_local_var->os_build = os_build;
    instance_local_var->agent = agent;
    instance_local_var->net_mon = net_mon;
    instance_local_var->net_dump = net_dump;
    instance_local_var->core_trace = core_trace;
    instance_local_var->hyper_trace = hyper_trace;
    instance_local_var->expose_port = expose_port;
    instance_local_var->fault = fault;
    instance_local_var->patches = patches;
    instance_local_var->created_by = created_by;
    instance_local_var->uefi_bootloader = uefi_bootloader;
    instance_local_var->orientation = orientation;
    instance_local_var->mast = mast;
    instance_local_var->wan_access = wan_access;
    instance_local_var->has_corelliumd = has_corelliumd;

    instance_local_var->_library_owned = 1;
    return instance_local_var;
}

__attribute__((deprecated)) instance_t *instance_create(
    char *id,
    char *name,
    char *key,
    char *flavor,
    char *flavor_name,
    char *type,
    char *project,
    char *domain_name,
    corellium_api_instance_state__e state,
    char *state_changed,
    char *started_at,
    char *user_task,
    char *task_state,
    char *error,
    instance_restore_status_t *restore_status,
    instance_read_only_status_t *read_only,
    instance_boot_options_t *boot_options,
    char *service_ip,
    char *wifi_ip,
    char *wifi_mac,
    char *secondary_ip,
    char *port_adb,
    char *port_usb,
    char *port_gdb,
    char *port_sep_gdb,
    char *port_cons,
    char *port_sep_cons,
    char *port_sys_cons,
    char *port_usbmuxd,
    char *port_frida,
    char *port_sockcap,
    char *port_model_gw,
    list_t *consoles,
    list_t *interfaces,
    instance_services_t *services,
    int panicked,
    char *created,
    char *model,
    char *fw_package,
    char *os_version,
    char *os_build,
    instance_agent_state_t *agent,
    instance_netmon_state_t *net_mon,
    instance_netdump_state_t *net_dump,
    instance_trace_state_t *core_trace,
    instance_hyper_trace_state_t *hyper_trace,
    char *expose_port,
    int fault,
    list_t *patches,
    created_by_t *created_by,
    instance_uefi_bootloader_t *uefi_bootloader,
    double orientation,
    int mast,
    int wan_access,
    int has_corelliumd
    ) {
    return instance_create_internal (
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
        interfaces,
        services,
        panicked,
        created,
        model,
        fw_package,
        os_version,
        os_build,
        agent,
        net_mon,
        net_dump,
        core_trace,
        hyper_trace,
        expose_port,
        fault,
        patches,
        created_by,
        uefi_bootloader,
        orientation,
        mast,
        wan_access,
        has_corelliumd
        );
}

void instance_free(instance_t *instance) {
    if(NULL == instance){
        return ;
    }
    if(instance->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "instance_free");
        return ;
    }
    listEntry_t *listEntry;
    if (instance->id) {
        free(instance->id);
        instance->id = NULL;
    }
    if (instance->name) {
        free(instance->name);
        instance->name = NULL;
    }
    if (instance->key) {
        free(instance->key);
        instance->key = NULL;
    }
    if (instance->flavor) {
        free(instance->flavor);
        instance->flavor = NULL;
    }
    if (instance->flavor_name) {
        free(instance->flavor_name);
        instance->flavor_name = NULL;
    }
    if (instance->type) {
        free(instance->type);
        instance->type = NULL;
    }
    if (instance->project) {
        free(instance->project);
        instance->project = NULL;
    }
    if (instance->domain_name) {
        free(instance->domain_name);
        instance->domain_name = NULL;
    }
    if (instance->state_changed) {
        free(instance->state_changed);
        instance->state_changed = NULL;
    }
    if (instance->started_at) {
        free(instance->started_at);
        instance->started_at = NULL;
    }
    if (instance->user_task) {
        free(instance->user_task);
        instance->user_task = NULL;
    }
    if (instance->task_state) {
        free(instance->task_state);
        instance->task_state = NULL;
    }
    if (instance->error) {
        free(instance->error);
        instance->error = NULL;
    }
    if (instance->restore_status) {
        instance_restore_status_free(instance->restore_status);
        instance->restore_status = NULL;
    }
    if (instance->read_only) {
        instance_read_only_status_free(instance->read_only);
        instance->read_only = NULL;
    }
    if (instance->boot_options) {
        instance_boot_options_free(instance->boot_options);
        instance->boot_options = NULL;
    }
    if (instance->service_ip) {
        free(instance->service_ip);
        instance->service_ip = NULL;
    }
    if (instance->wifi_ip) {
        free(instance->wifi_ip);
        instance->wifi_ip = NULL;
    }
    if (instance->wifi_mac) {
        free(instance->wifi_mac);
        instance->wifi_mac = NULL;
    }
    if (instance->secondary_ip) {
        free(instance->secondary_ip);
        instance->secondary_ip = NULL;
    }
    if (instance->port_adb) {
        free(instance->port_adb);
        instance->port_adb = NULL;
    }
    if (instance->port_usb) {
        free(instance->port_usb);
        instance->port_usb = NULL;
    }
    if (instance->port_gdb) {
        free(instance->port_gdb);
        instance->port_gdb = NULL;
    }
    if (instance->port_sep_gdb) {
        free(instance->port_sep_gdb);
        instance->port_sep_gdb = NULL;
    }
    if (instance->port_cons) {
        free(instance->port_cons);
        instance->port_cons = NULL;
    }
    if (instance->port_sep_cons) {
        free(instance->port_sep_cons);
        instance->port_sep_cons = NULL;
    }
    if (instance->port_sys_cons) {
        free(instance->port_sys_cons);
        instance->port_sys_cons = NULL;
    }
    if (instance->port_usbmuxd) {
        free(instance->port_usbmuxd);
        instance->port_usbmuxd = NULL;
    }
    if (instance->port_frida) {
        free(instance->port_frida);
        instance->port_frida = NULL;
    }
    if (instance->port_sockcap) {
        free(instance->port_sockcap);
        instance->port_sockcap = NULL;
    }
    if (instance->port_model_gw) {
        free(instance->port_model_gw);
        instance->port_model_gw = NULL;
    }
    if (instance->consoles) {
        list_ForEach(listEntry, instance->consoles) {
            instance_console_free(listEntry->data);
        }
        list_freeList(instance->consoles);
        instance->consoles = NULL;
    }
    if (instance->interfaces) {
        list_ForEach(listEntry, instance->interfaces) {
            instance_interface_status_free(listEntry->data);
        }
        list_freeList(instance->interfaces);
        instance->interfaces = NULL;
    }
    if (instance->services) {
        instance_services_free(instance->services);
        instance->services = NULL;
    }
    if (instance->created) {
        free(instance->created);
        instance->created = NULL;
    }
    if (instance->model) {
        free(instance->model);
        instance->model = NULL;
    }
    if (instance->fw_package) {
        free(instance->fw_package);
        instance->fw_package = NULL;
    }
    if (instance->os_version) {
        free(instance->os_version);
        instance->os_version = NULL;
    }
    if (instance->os_build) {
        free(instance->os_build);
        instance->os_build = NULL;
    }
    if (instance->agent) {
        instance_agent_state_free(instance->agent);
        instance->agent = NULL;
    }
    if (instance->net_mon) {
        instance_netmon_state_free(instance->net_mon);
        instance->net_mon = NULL;
    }
    if (instance->net_dump) {
        instance_netdump_state_free(instance->net_dump);
        instance->net_dump = NULL;
    }
    if (instance->core_trace) {
        instance_trace_state_free(instance->core_trace);
        instance->core_trace = NULL;
    }
    if (instance->hyper_trace) {
        instance_hyper_trace_state_free(instance->hyper_trace);
        instance->hyper_trace = NULL;
    }
    if (instance->expose_port) {
        free(instance->expose_port);
        instance->expose_port = NULL;
    }
    if (instance->patches) {
        list_ForEach(listEntry, instance->patches) {
            free(listEntry->data);
        }
        list_freeList(instance->patches);
        instance->patches = NULL;
    }
    if (instance->created_by) {
        created_by_free(instance->created_by);
        instance->created_by = NULL;
    }
    if (instance->uefi_bootloader) {
        instance_uefi_bootloader_free(instance->uefi_bootloader);
        instance->uefi_bootloader = NULL;
    }
    free(instance);
}

cJSON *instance_convertToJSON(instance_t *instance) {
    cJSON *item = cJSON_CreateObject();

    // instance->id
    if (!instance->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", instance->id) == NULL) {
    goto fail; //String
    }


    // instance->name
    if (!instance->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", instance->name) == NULL) {
    goto fail; //String
    }


    // instance->key
    if (!instance->key) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "key", instance->key) == NULL) {
    goto fail; //String
    }


    // instance->flavor
    if (!instance->flavor) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "flavor", instance->flavor) == NULL) {
    goto fail; //String
    }


    // instance->flavor_name
    if(instance->flavor_name) {
    if(cJSON_AddStringToObject(item, "flavorName", instance->flavor_name) == NULL) {
    goto fail; //String
    }
    }


    // instance->type
    if (!instance->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", instance->type) == NULL) {
    goto fail; //String
    }


    // instance->project
    if (!instance->project) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "project", instance->project) == NULL) {
    goto fail; //String
    }


    // instance->domain_name
    if(instance->domain_name) {
    if(cJSON_AddStringToObject(item, "domainName", instance->domain_name) == NULL) {
    goto fail; //String
    }
    }


    // instance->state
    if (corellium_api_instance_state__NULL == instance->state) {
        goto fail;
    }
    cJSON *state_local_JSON = instance_state_convertToJSON(instance->state);
    if(state_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "state", state_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // instance->state_changed
    if(instance->state_changed) {
    if(cJSON_AddStringToObject(item, "stateChanged", instance->state_changed) == NULL) {
    goto fail; //Date-Time
    }
    }


    // instance->started_at
    if(instance->started_at) {
    if(cJSON_AddStringToObject(item, "startedAt", instance->started_at) == NULL) {
    goto fail; //Date-Time
    }
    }


    // instance->user_task
    if(instance->user_task) {
    if(cJSON_AddStringToObject(item, "userTask", instance->user_task) == NULL) {
    goto fail; //String
    }
    }


    // instance->task_state
    if(instance->task_state) {
    if(cJSON_AddStringToObject(item, "taskState", instance->task_state) == NULL) {
    goto fail; //String
    }
    }


    // instance->error
    if(instance->error) {
    if(cJSON_AddStringToObject(item, "error", instance->error) == NULL) {
    goto fail; //String
    }
    }


    // instance->restore_status
    if(instance->restore_status) {
    cJSON *restore_status_local_JSON = instance_restore_status_convertToJSON(instance->restore_status);
    if(restore_status_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "restoreStatus", restore_status_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // instance->read_only
    if(instance->read_only) {
    cJSON *read_only_local_JSON = instance_read_only_status_convertToJSON(instance->read_only);
    if(read_only_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "readOnly", read_only_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // instance->boot_options
    if(instance->boot_options) {
    cJSON *boot_options_local_JSON = instance_boot_options_convertToJSON(instance->boot_options);
    if(boot_options_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "bootOptions", boot_options_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // instance->service_ip
    if(instance->service_ip) {
    if(cJSON_AddStringToObject(item, "serviceIp", instance->service_ip) == NULL) {
    goto fail; //String
    }
    }


    // instance->wifi_ip
    if(instance->wifi_ip) {
    if(cJSON_AddStringToObject(item, "wifiIp", instance->wifi_ip) == NULL) {
    goto fail; //String
    }
    }


    // instance->wifi_mac
    if(instance->wifi_mac) {
    if(cJSON_AddStringToObject(item, "wifiMac", instance->wifi_mac) == NULL) {
    goto fail; //String
    }
    }


    // instance->secondary_ip
    if(instance->secondary_ip) {
    if(cJSON_AddStringToObject(item, "secondaryIp", instance->secondary_ip) == NULL) {
    goto fail; //String
    }
    }


    // instance->port_adb
    if(instance->port_adb) {
    if(cJSON_AddStringToObject(item, "portAdb", instance->port_adb) == NULL) {
    goto fail; //String
    }
    }


    // instance->port_usb
    if(instance->port_usb) {
    if(cJSON_AddStringToObject(item, "portUsb", instance->port_usb) == NULL) {
    goto fail; //String
    }
    }


    // instance->port_gdb
    if(instance->port_gdb) {
    if(cJSON_AddStringToObject(item, "portGdb", instance->port_gdb) == NULL) {
    goto fail; //String
    }
    }


    // instance->port_sep_gdb
    if(instance->port_sep_gdb) {
    if(cJSON_AddStringToObject(item, "portSepGdb", instance->port_sep_gdb) == NULL) {
    goto fail; //String
    }
    }


    // instance->port_cons
    if(instance->port_cons) {
    if(cJSON_AddStringToObject(item, "portCons", instance->port_cons) == NULL) {
    goto fail; //String
    }
    }


    // instance->port_sep_cons
    if(instance->port_sep_cons) {
    if(cJSON_AddStringToObject(item, "portSepCons", instance->port_sep_cons) == NULL) {
    goto fail; //String
    }
    }


    // instance->port_sys_cons
    if(instance->port_sys_cons) {
    if(cJSON_AddStringToObject(item, "portSysCons", instance->port_sys_cons) == NULL) {
    goto fail; //String
    }
    }


    // instance->port_usbmuxd
    if(instance->port_usbmuxd) {
    if(cJSON_AddStringToObject(item, "portUsbmuxd", instance->port_usbmuxd) == NULL) {
    goto fail; //String
    }
    }


    // instance->port_frida
    if(instance->port_frida) {
    if(cJSON_AddStringToObject(item, "portFrida", instance->port_frida) == NULL) {
    goto fail; //String
    }
    }


    // instance->port_sockcap
    if(instance->port_sockcap) {
    if(cJSON_AddStringToObject(item, "portSockcap", instance->port_sockcap) == NULL) {
    goto fail; //String
    }
    }


    // instance->port_model_gw
    if(instance->port_model_gw) {
    if(cJSON_AddStringToObject(item, "portModelGw", instance->port_model_gw) == NULL) {
    goto fail; //String
    }
    }


    // instance->consoles
    if(instance->consoles) {
    cJSON *consoles = cJSON_AddArrayToObject(item, "consoles");
    if(consoles == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *consolesListEntry;
    if (instance->consoles) {
    list_ForEach(consolesListEntry, instance->consoles) {
    cJSON *itemLocal = instance_console_convertToJSON(consolesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(consoles, itemLocal);
    }
    }
    }


    // instance->interfaces
    if(instance->interfaces) {
    cJSON *interfaces = cJSON_AddArrayToObject(item, "interfaces");
    if(interfaces == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *interfacesListEntry;
    if (instance->interfaces) {
    list_ForEach(interfacesListEntry, instance->interfaces) {
    cJSON *itemLocal = instance_interface_status_convertToJSON(interfacesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(interfaces, itemLocal);
    }
    }
    }


    // instance->services
    if(instance->services) {
    cJSON *services_local_JSON = instance_services_convertToJSON(instance->services);
    if(services_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "services", services_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // instance->panicked
    if(instance->panicked) {
    if(cJSON_AddBoolToObject(item, "panicked", instance->panicked) == NULL) {
    goto fail; //Bool
    }
    }


    // instance->created
    if (!instance->created) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "created", instance->created) == NULL) {
    goto fail; //Date-Time
    }


    // instance->model
    if(instance->model) {
    if(cJSON_AddStringToObject(item, "model", instance->model) == NULL) {
    goto fail; //String
    }
    }


    // instance->fw_package
    if(instance->fw_package) {
    if(cJSON_AddStringToObject(item, "fwPackage", instance->fw_package) == NULL) {
    goto fail; //String
    }
    }


    // instance->os_version
    if(instance->os_version) {
    if(cJSON_AddStringToObject(item, "osVersion", instance->os_version) == NULL) {
    goto fail; //String
    }
    }


    // instance->os_build
    if(instance->os_build) {
    if(cJSON_AddStringToObject(item, "osBuild", instance->os_build) == NULL) {
    goto fail; //String
    }
    }


    // instance->agent
    if(instance->agent) {
    cJSON *agent_local_JSON = instance_agent_state_convertToJSON(instance->agent);
    if(agent_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "agent", agent_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // instance->net_mon
    if(instance->net_mon) {
    cJSON *net_mon_local_JSON = instance_netmon_state_convertToJSON(instance->net_mon);
    if(net_mon_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "netMon", net_mon_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // instance->net_dump
    if(instance->net_dump) {
    cJSON *net_dump_local_JSON = instance_netdump_state_convertToJSON(instance->net_dump);
    if(net_dump_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "netDump", net_dump_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // instance->core_trace
    if(instance->core_trace) {
    cJSON *core_trace_local_JSON = instance_trace_state_convertToJSON(instance->core_trace);
    if(core_trace_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "coreTrace", core_trace_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // instance->hyper_trace
    if(instance->hyper_trace) {
    cJSON *hyper_trace_local_JSON = instance_hyper_trace_state_convertToJSON(instance->hyper_trace);
    if(hyper_trace_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "hyperTrace", hyper_trace_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // instance->expose_port
    if(instance->expose_port) {
    if(cJSON_AddStringToObject(item, "exposePort", instance->expose_port) == NULL) {
    goto fail; //String
    }
    }


    // instance->fault
    if(instance->fault) {
    if(cJSON_AddBoolToObject(item, "fault", instance->fault) == NULL) {
    goto fail; //Bool
    }
    }


    // instance->patches
    if(instance->patches) {
    cJSON *patches = cJSON_AddArrayToObject(item, "patches");
    if(patches == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *patchesListEntry;
    list_ForEach(patchesListEntry, instance->patches) {
    if(cJSON_AddStringToObject(patches, "", patchesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // instance->created_by
    if(instance->created_by) {
    cJSON *created_by_local_JSON = created_by_convertToJSON(instance->created_by);
    if(created_by_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "createdBy", created_by_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // instance->uefi_bootloader
    if(instance->uefi_bootloader) {
    cJSON *uefi_bootloader_local_JSON = instance_uefi_bootloader_convertToJSON(instance->uefi_bootloader);
    if(uefi_bootloader_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "uefiBootloader", uefi_bootloader_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // instance->orientation
    if(instance->orientation) {
    if(cJSON_AddNumberToObject(item, "orientation", instance->orientation) == NULL) {
    goto fail; //Numeric
    }
    }


    // instance->mast
    if(instance->mast) {
    if(cJSON_AddBoolToObject(item, "mast", instance->mast) == NULL) {
    goto fail; //Bool
    }
    }


    // instance->wan_access
    if(instance->wan_access) {
    if(cJSON_AddBoolToObject(item, "wanAccess", instance->wan_access) == NULL) {
    goto fail; //Bool
    }
    }


    // instance->has_corelliumd
    if(instance->has_corelliumd) {
    if(cJSON_AddBoolToObject(item, "hasCorelliumd", instance->has_corelliumd) == NULL) {
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

instance_t *instance_parseFromJSON(cJSON *instanceJSON){

    instance_t *instance_local_var = NULL;

    // define the local variable for instance->state
    corellium_api_instance_state__e state_local_nonprim = 0;

    // define the local variable for instance->restore_status
    instance_restore_status_t *restore_status_local_nonprim = NULL;

    // define the local variable for instance->read_only
    instance_read_only_status_t *read_only_local_nonprim = NULL;

    // define the local variable for instance->boot_options
    instance_boot_options_t *boot_options_local_nonprim = NULL;

    // define the local list for instance->consoles
    list_t *consolesList = NULL;

    // define the local list for instance->interfaces
    list_t *interfacesList = NULL;

    // define the local variable for instance->services
    instance_services_t *services_local_nonprim = NULL;

    // define the local variable for instance->agent
    instance_agent_state_t *agent_local_nonprim = NULL;

    // define the local variable for instance->net_mon
    instance_netmon_state_t *net_mon_local_nonprim = NULL;

    // define the local variable for instance->net_dump
    instance_netdump_state_t *net_dump_local_nonprim = NULL;

    // define the local variable for instance->core_trace
    instance_trace_state_t *core_trace_local_nonprim = NULL;

    // define the local variable for instance->hyper_trace
    instance_hyper_trace_state_t *hyper_trace_local_nonprim = NULL;

    // define the local list for instance->patches
    list_t *patchesList = NULL;

    // define the local variable for instance->created_by
    created_by_t *created_by_local_nonprim = NULL;

    // define the local variable for instance->uefi_bootloader
    instance_uefi_bootloader_t *uefi_bootloader_local_nonprim = NULL;

    // instance->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(instanceJSON, "id");
    if (cJSON_IsNull(id)) {
        id = NULL;
    }
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // instance->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(instanceJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // instance->key
    cJSON *key = cJSON_GetObjectItemCaseSensitive(instanceJSON, "key");
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

    // instance->flavor
    cJSON *flavor = cJSON_GetObjectItemCaseSensitive(instanceJSON, "flavor");
    if (cJSON_IsNull(flavor)) {
        flavor = NULL;
    }
    if (!flavor) {
        goto end;
    }

    
    if(!cJSON_IsString(flavor))
    {
    goto end; //String
    }

    // instance->flavor_name
    cJSON *flavor_name = cJSON_GetObjectItemCaseSensitive(instanceJSON, "flavorName");
    if (cJSON_IsNull(flavor_name)) {
        flavor_name = NULL;
    }
    if (flavor_name) { 
    if(!cJSON_IsString(flavor_name) && !cJSON_IsNull(flavor_name))
    {
    goto end; //String
    }
    }

    // instance->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(instanceJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }

    // instance->project
    cJSON *project = cJSON_GetObjectItemCaseSensitive(instanceJSON, "project");
    if (cJSON_IsNull(project)) {
        project = NULL;
    }
    if (!project) {
        goto end;
    }

    
    if(!cJSON_IsString(project))
    {
    goto end; //String
    }

    // instance->domain_name
    cJSON *domain_name = cJSON_GetObjectItemCaseSensitive(instanceJSON, "domainName");
    if (cJSON_IsNull(domain_name)) {
        domain_name = NULL;
    }
    if (domain_name) { 
    if(!cJSON_IsString(domain_name) && !cJSON_IsNull(domain_name))
    {
    goto end; //String
    }
    }

    // instance->state
    cJSON *state = cJSON_GetObjectItemCaseSensitive(instanceJSON, "state");
    if (cJSON_IsNull(state)) {
        state = NULL;
    }
    if (!state) {
        goto end;
    }

    
    state_local_nonprim = instance_state_parseFromJSON(state); //custom

    // instance->state_changed
    cJSON *state_changed = cJSON_GetObjectItemCaseSensitive(instanceJSON, "stateChanged");
    if (cJSON_IsNull(state_changed)) {
        state_changed = NULL;
    }
    if (state_changed) { 
    if(!cJSON_IsString(state_changed) && !cJSON_IsNull(state_changed))
    {
    goto end; //DateTime
    }
    }

    // instance->started_at
    cJSON *started_at = cJSON_GetObjectItemCaseSensitive(instanceJSON, "startedAt");
    if (cJSON_IsNull(started_at)) {
        started_at = NULL;
    }
    if (started_at) { 
    if(!cJSON_IsString(started_at) && !cJSON_IsNull(started_at))
    {
    goto end; //DateTime
    }
    }

    // instance->user_task
    cJSON *user_task = cJSON_GetObjectItemCaseSensitive(instanceJSON, "userTask");
    if (cJSON_IsNull(user_task)) {
        user_task = NULL;
    }
    if (user_task) { 
    if(!cJSON_IsString(user_task) && !cJSON_IsNull(user_task))
    {
    goto end; //String
    }
    }

    // instance->task_state
    cJSON *task_state = cJSON_GetObjectItemCaseSensitive(instanceJSON, "taskState");
    if (cJSON_IsNull(task_state)) {
        task_state = NULL;
    }
    if (task_state) { 
    if(!cJSON_IsString(task_state) && !cJSON_IsNull(task_state))
    {
    goto end; //String
    }
    }

    // instance->error
    cJSON *error = cJSON_GetObjectItemCaseSensitive(instanceJSON, "error");
    if (cJSON_IsNull(error)) {
        error = NULL;
    }
    if (error) { 
    if(!cJSON_IsString(error) && !cJSON_IsNull(error))
    {
    goto end; //String
    }
    }

    // instance->restore_status
    cJSON *restore_status = cJSON_GetObjectItemCaseSensitive(instanceJSON, "restoreStatus");
    if (cJSON_IsNull(restore_status)) {
        restore_status = NULL;
    }
    if (restore_status) { 
    restore_status_local_nonprim = instance_restore_status_parseFromJSON(restore_status); //nonprimitive
    }

    // instance->read_only
    cJSON *read_only = cJSON_GetObjectItemCaseSensitive(instanceJSON, "readOnly");
    if (cJSON_IsNull(read_only)) {
        read_only = NULL;
    }
    if (read_only) { 
    read_only_local_nonprim = instance_read_only_status_parseFromJSON(read_only); //nonprimitive
    }

    // instance->boot_options
    cJSON *boot_options = cJSON_GetObjectItemCaseSensitive(instanceJSON, "bootOptions");
    if (cJSON_IsNull(boot_options)) {
        boot_options = NULL;
    }
    if (boot_options) { 
    boot_options_local_nonprim = instance_boot_options_parseFromJSON(boot_options); //nonprimitive
    }

    // instance->service_ip
    cJSON *service_ip = cJSON_GetObjectItemCaseSensitive(instanceJSON, "serviceIp");
    if (cJSON_IsNull(service_ip)) {
        service_ip = NULL;
    }
    if (service_ip) { 
    if(!cJSON_IsString(service_ip) && !cJSON_IsNull(service_ip))
    {
    goto end; //String
    }
    }

    // instance->wifi_ip
    cJSON *wifi_ip = cJSON_GetObjectItemCaseSensitive(instanceJSON, "wifiIp");
    if (cJSON_IsNull(wifi_ip)) {
        wifi_ip = NULL;
    }
    if (wifi_ip) { 
    if(!cJSON_IsString(wifi_ip) && !cJSON_IsNull(wifi_ip))
    {
    goto end; //String
    }
    }

    // instance->wifi_mac
    cJSON *wifi_mac = cJSON_GetObjectItemCaseSensitive(instanceJSON, "wifiMac");
    if (cJSON_IsNull(wifi_mac)) {
        wifi_mac = NULL;
    }
    if (wifi_mac) { 
    if(!cJSON_IsString(wifi_mac) && !cJSON_IsNull(wifi_mac))
    {
    goto end; //String
    }
    }

    // instance->secondary_ip
    cJSON *secondary_ip = cJSON_GetObjectItemCaseSensitive(instanceJSON, "secondaryIp");
    if (cJSON_IsNull(secondary_ip)) {
        secondary_ip = NULL;
    }
    if (secondary_ip) { 
    if(!cJSON_IsString(secondary_ip) && !cJSON_IsNull(secondary_ip))
    {
    goto end; //String
    }
    }

    // instance->port_adb
    cJSON *port_adb = cJSON_GetObjectItemCaseSensitive(instanceJSON, "portAdb");
    if (cJSON_IsNull(port_adb)) {
        port_adb = NULL;
    }
    if (port_adb) { 
    if(!cJSON_IsString(port_adb) && !cJSON_IsNull(port_adb))
    {
    goto end; //String
    }
    }

    // instance->port_usb
    cJSON *port_usb = cJSON_GetObjectItemCaseSensitive(instanceJSON, "portUsb");
    if (cJSON_IsNull(port_usb)) {
        port_usb = NULL;
    }
    if (port_usb) { 
    if(!cJSON_IsString(port_usb) && !cJSON_IsNull(port_usb))
    {
    goto end; //String
    }
    }

    // instance->port_gdb
    cJSON *port_gdb = cJSON_GetObjectItemCaseSensitive(instanceJSON, "portGdb");
    if (cJSON_IsNull(port_gdb)) {
        port_gdb = NULL;
    }
    if (port_gdb) { 
    if(!cJSON_IsString(port_gdb) && !cJSON_IsNull(port_gdb))
    {
    goto end; //String
    }
    }

    // instance->port_sep_gdb
    cJSON *port_sep_gdb = cJSON_GetObjectItemCaseSensitive(instanceJSON, "portSepGdb");
    if (cJSON_IsNull(port_sep_gdb)) {
        port_sep_gdb = NULL;
    }
    if (port_sep_gdb) { 
    if(!cJSON_IsString(port_sep_gdb) && !cJSON_IsNull(port_sep_gdb))
    {
    goto end; //String
    }
    }

    // instance->port_cons
    cJSON *port_cons = cJSON_GetObjectItemCaseSensitive(instanceJSON, "portCons");
    if (cJSON_IsNull(port_cons)) {
        port_cons = NULL;
    }
    if (port_cons) { 
    if(!cJSON_IsString(port_cons) && !cJSON_IsNull(port_cons))
    {
    goto end; //String
    }
    }

    // instance->port_sep_cons
    cJSON *port_sep_cons = cJSON_GetObjectItemCaseSensitive(instanceJSON, "portSepCons");
    if (cJSON_IsNull(port_sep_cons)) {
        port_sep_cons = NULL;
    }
    if (port_sep_cons) { 
    if(!cJSON_IsString(port_sep_cons) && !cJSON_IsNull(port_sep_cons))
    {
    goto end; //String
    }
    }

    // instance->port_sys_cons
    cJSON *port_sys_cons = cJSON_GetObjectItemCaseSensitive(instanceJSON, "portSysCons");
    if (cJSON_IsNull(port_sys_cons)) {
        port_sys_cons = NULL;
    }
    if (port_sys_cons) { 
    if(!cJSON_IsString(port_sys_cons) && !cJSON_IsNull(port_sys_cons))
    {
    goto end; //String
    }
    }

    // instance->port_usbmuxd
    cJSON *port_usbmuxd = cJSON_GetObjectItemCaseSensitive(instanceJSON, "portUsbmuxd");
    if (cJSON_IsNull(port_usbmuxd)) {
        port_usbmuxd = NULL;
    }
    if (port_usbmuxd) { 
    if(!cJSON_IsString(port_usbmuxd) && !cJSON_IsNull(port_usbmuxd))
    {
    goto end; //String
    }
    }

    // instance->port_frida
    cJSON *port_frida = cJSON_GetObjectItemCaseSensitive(instanceJSON, "portFrida");
    if (cJSON_IsNull(port_frida)) {
        port_frida = NULL;
    }
    if (port_frida) { 
    if(!cJSON_IsString(port_frida) && !cJSON_IsNull(port_frida))
    {
    goto end; //String
    }
    }

    // instance->port_sockcap
    cJSON *port_sockcap = cJSON_GetObjectItemCaseSensitive(instanceJSON, "portSockcap");
    if (cJSON_IsNull(port_sockcap)) {
        port_sockcap = NULL;
    }
    if (port_sockcap) { 
    if(!cJSON_IsString(port_sockcap) && !cJSON_IsNull(port_sockcap))
    {
    goto end; //String
    }
    }

    // instance->port_model_gw
    cJSON *port_model_gw = cJSON_GetObjectItemCaseSensitive(instanceJSON, "portModelGw");
    if (cJSON_IsNull(port_model_gw)) {
        port_model_gw = NULL;
    }
    if (port_model_gw) { 
    if(!cJSON_IsString(port_model_gw) && !cJSON_IsNull(port_model_gw))
    {
    goto end; //String
    }
    }

    // instance->consoles
    cJSON *consoles = cJSON_GetObjectItemCaseSensitive(instanceJSON, "consoles");
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
        instance_console_t *consolesItem = instance_console_parseFromJSON(consoles_local_nonprimitive);

        list_addElement(consolesList, consolesItem);
    }
    }

    // instance->interfaces
    cJSON *interfaces = cJSON_GetObjectItemCaseSensitive(instanceJSON, "interfaces");
    if (cJSON_IsNull(interfaces)) {
        interfaces = NULL;
    }
    if (interfaces) { 
    cJSON *interfaces_local_nonprimitive = NULL;
    if(!cJSON_IsArray(interfaces)){
        goto end; //nonprimitive container
    }

    interfacesList = list_createList();

    cJSON_ArrayForEach(interfaces_local_nonprimitive,interfaces )
    {
        if(!cJSON_IsObject(interfaces_local_nonprimitive)){
            goto end;
        }
        instance_interface_status_t *interfacesItem = instance_interface_status_parseFromJSON(interfaces_local_nonprimitive);

        list_addElement(interfacesList, interfacesItem);
    }
    }

    // instance->services
    cJSON *services = cJSON_GetObjectItemCaseSensitive(instanceJSON, "services");
    if (cJSON_IsNull(services)) {
        services = NULL;
    }
    if (services) { 
    services_local_nonprim = instance_services_parseFromJSON(services); //nonprimitive
    }

    // instance->panicked
    cJSON *panicked = cJSON_GetObjectItemCaseSensitive(instanceJSON, "panicked");
    if (cJSON_IsNull(panicked)) {
        panicked = NULL;
    }
    if (panicked) { 
    if(!cJSON_IsBool(panicked))
    {
    goto end; //Bool
    }
    }

    // instance->created
    cJSON *created = cJSON_GetObjectItemCaseSensitive(instanceJSON, "created");
    if (cJSON_IsNull(created)) {
        created = NULL;
    }
    if (!created) {
        goto end;
    }

    
    if(!cJSON_IsString(created) && !cJSON_IsNull(created))
    {
    goto end; //DateTime
    }

    // instance->model
    cJSON *model = cJSON_GetObjectItemCaseSensitive(instanceJSON, "model");
    if (cJSON_IsNull(model)) {
        model = NULL;
    }
    if (model) { 
    if(!cJSON_IsString(model) && !cJSON_IsNull(model))
    {
    goto end; //String
    }
    }

    // instance->fw_package
    cJSON *fw_package = cJSON_GetObjectItemCaseSensitive(instanceJSON, "fwPackage");
    if (cJSON_IsNull(fw_package)) {
        fw_package = NULL;
    }
    if (fw_package) { 
    if(!cJSON_IsString(fw_package) && !cJSON_IsNull(fw_package))
    {
    goto end; //String
    }
    }

    // instance->os_version
    cJSON *os_version = cJSON_GetObjectItemCaseSensitive(instanceJSON, "osVersion");
    if (cJSON_IsNull(os_version)) {
        os_version = NULL;
    }
    if (os_version) { 
    if(!cJSON_IsString(os_version) && !cJSON_IsNull(os_version))
    {
    goto end; //String
    }
    }

    // instance->os_build
    cJSON *os_build = cJSON_GetObjectItemCaseSensitive(instanceJSON, "osBuild");
    if (cJSON_IsNull(os_build)) {
        os_build = NULL;
    }
    if (os_build) { 
    if(!cJSON_IsString(os_build) && !cJSON_IsNull(os_build))
    {
    goto end; //String
    }
    }

    // instance->agent
    cJSON *agent = cJSON_GetObjectItemCaseSensitive(instanceJSON, "agent");
    if (cJSON_IsNull(agent)) {
        agent = NULL;
    }
    if (agent) { 
    agent_local_nonprim = instance_agent_state_parseFromJSON(agent); //nonprimitive
    }

    // instance->net_mon
    cJSON *net_mon = cJSON_GetObjectItemCaseSensitive(instanceJSON, "netMon");
    if (cJSON_IsNull(net_mon)) {
        net_mon = NULL;
    }
    if (net_mon) { 
    net_mon_local_nonprim = instance_netmon_state_parseFromJSON(net_mon); //nonprimitive
    }

    // instance->net_dump
    cJSON *net_dump = cJSON_GetObjectItemCaseSensitive(instanceJSON, "netDump");
    if (cJSON_IsNull(net_dump)) {
        net_dump = NULL;
    }
    if (net_dump) { 
    net_dump_local_nonprim = instance_netdump_state_parseFromJSON(net_dump); //nonprimitive
    }

    // instance->core_trace
    cJSON *core_trace = cJSON_GetObjectItemCaseSensitive(instanceJSON, "coreTrace");
    if (cJSON_IsNull(core_trace)) {
        core_trace = NULL;
    }
    if (core_trace) { 
    core_trace_local_nonprim = instance_trace_state_parseFromJSON(core_trace); //nonprimitive
    }

    // instance->hyper_trace
    cJSON *hyper_trace = cJSON_GetObjectItemCaseSensitive(instanceJSON, "hyperTrace");
    if (cJSON_IsNull(hyper_trace)) {
        hyper_trace = NULL;
    }
    if (hyper_trace) { 
    hyper_trace_local_nonprim = instance_hyper_trace_state_parseFromJSON(hyper_trace); //nonprimitive
    }

    // instance->expose_port
    cJSON *expose_port = cJSON_GetObjectItemCaseSensitive(instanceJSON, "exposePort");
    if (cJSON_IsNull(expose_port)) {
        expose_port = NULL;
    }
    if (expose_port) { 
    if(!cJSON_IsString(expose_port) && !cJSON_IsNull(expose_port))
    {
    goto end; //String
    }
    }

    // instance->fault
    cJSON *fault = cJSON_GetObjectItemCaseSensitive(instanceJSON, "fault");
    if (cJSON_IsNull(fault)) {
        fault = NULL;
    }
    if (fault) { 
    if(!cJSON_IsBool(fault))
    {
    goto end; //Bool
    }
    }

    // instance->patches
    cJSON *patches = cJSON_GetObjectItemCaseSensitive(instanceJSON, "patches");
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

    // instance->created_by
    cJSON *created_by = cJSON_GetObjectItemCaseSensitive(instanceJSON, "createdBy");
    if (cJSON_IsNull(created_by)) {
        created_by = NULL;
    }
    if (created_by) { 
    created_by_local_nonprim = created_by_parseFromJSON(created_by); //nonprimitive
    }

    // instance->uefi_bootloader
    cJSON *uefi_bootloader = cJSON_GetObjectItemCaseSensitive(instanceJSON, "uefiBootloader");
    if (cJSON_IsNull(uefi_bootloader)) {
        uefi_bootloader = NULL;
    }
    if (uefi_bootloader) { 
    uefi_bootloader_local_nonprim = instance_uefi_bootloader_parseFromJSON(uefi_bootloader); //nonprimitive
    }

    // instance->orientation
    cJSON *orientation = cJSON_GetObjectItemCaseSensitive(instanceJSON, "orientation");
    if (cJSON_IsNull(orientation)) {
        orientation = NULL;
    }
    if (orientation) { 
    if(!cJSON_IsNumber(orientation))
    {
    goto end; //Numeric
    }
    }

    // instance->mast
    cJSON *mast = cJSON_GetObjectItemCaseSensitive(instanceJSON, "mast");
    if (cJSON_IsNull(mast)) {
        mast = NULL;
    }
    if (mast) { 
    if(!cJSON_IsBool(mast))
    {
    goto end; //Bool
    }
    }

    // instance->wan_access
    cJSON *wan_access = cJSON_GetObjectItemCaseSensitive(instanceJSON, "wanAccess");
    if (cJSON_IsNull(wan_access)) {
        wan_access = NULL;
    }
    if (wan_access) { 
    if(!cJSON_IsBool(wan_access))
    {
    goto end; //Bool
    }
    }

    // instance->has_corelliumd
    cJSON *has_corelliumd = cJSON_GetObjectItemCaseSensitive(instanceJSON, "hasCorelliumd");
    if (cJSON_IsNull(has_corelliumd)) {
        has_corelliumd = NULL;
    }
    if (has_corelliumd) { 
    if(!cJSON_IsBool(has_corelliumd))
    {
    goto end; //Bool
    }
    }


    instance_local_var = instance_create_internal (
        strdup(id->valuestring),
        strdup(name->valuestring),
        strdup(key->valuestring),
        strdup(flavor->valuestring),
        flavor_name && !cJSON_IsNull(flavor_name) ? strdup(flavor_name->valuestring) : NULL,
        strdup(type->valuestring),
        strdup(project->valuestring),
        domain_name && !cJSON_IsNull(domain_name) ? strdup(domain_name->valuestring) : NULL,
        state_local_nonprim,
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
        port_adb && !cJSON_IsNull(port_adb) ? strdup(port_adb->valuestring) : NULL,
        port_usb && !cJSON_IsNull(port_usb) ? strdup(port_usb->valuestring) : NULL,
        port_gdb && !cJSON_IsNull(port_gdb) ? strdup(port_gdb->valuestring) : NULL,
        port_sep_gdb && !cJSON_IsNull(port_sep_gdb) ? strdup(port_sep_gdb->valuestring) : NULL,
        port_cons && !cJSON_IsNull(port_cons) ? strdup(port_cons->valuestring) : NULL,
        port_sep_cons && !cJSON_IsNull(port_sep_cons) ? strdup(port_sep_cons->valuestring) : NULL,
        port_sys_cons && !cJSON_IsNull(port_sys_cons) ? strdup(port_sys_cons->valuestring) : NULL,
        port_usbmuxd && !cJSON_IsNull(port_usbmuxd) ? strdup(port_usbmuxd->valuestring) : NULL,
        port_frida && !cJSON_IsNull(port_frida) ? strdup(port_frida->valuestring) : NULL,
        port_sockcap && !cJSON_IsNull(port_sockcap) ? strdup(port_sockcap->valuestring) : NULL,
        port_model_gw && !cJSON_IsNull(port_model_gw) ? strdup(port_model_gw->valuestring) : NULL,
        consoles ? consolesList : NULL,
        interfaces ? interfacesList : NULL,
        services ? services_local_nonprim : NULL,
        panicked ? panicked->valueint : 0,
        strdup(created->valuestring),
        model && !cJSON_IsNull(model) ? strdup(model->valuestring) : NULL,
        fw_package && !cJSON_IsNull(fw_package) ? strdup(fw_package->valuestring) : NULL,
        os_version && !cJSON_IsNull(os_version) ? strdup(os_version->valuestring) : NULL,
        os_build && !cJSON_IsNull(os_build) ? strdup(os_build->valuestring) : NULL,
        agent ? agent_local_nonprim : NULL,
        net_mon ? net_mon_local_nonprim : NULL,
        net_dump ? net_dump_local_nonprim : NULL,
        core_trace ? core_trace_local_nonprim : NULL,
        hyper_trace ? hyper_trace_local_nonprim : NULL,
        expose_port && !cJSON_IsNull(expose_port) ? strdup(expose_port->valuestring) : NULL,
        fault ? fault->valueint : 0,
        patches ? patchesList : NULL,
        created_by ? created_by_local_nonprim : NULL,
        uefi_bootloader ? uefi_bootloader_local_nonprim : NULL,
        orientation ? orientation->valuedouble : 0,
        mast ? mast->valueint : 0,
        wan_access ? wan_access->valueint : 0,
        has_corelliumd ? has_corelliumd->valueint : 0
        );

    return instance_local_var;
end:
    if (state_local_nonprim) {
        state_local_nonprim = 0;
    }
    if (restore_status_local_nonprim) {
        instance_restore_status_free(restore_status_local_nonprim);
        restore_status_local_nonprim = NULL;
    }
    if (read_only_local_nonprim) {
        instance_read_only_status_free(read_only_local_nonprim);
        read_only_local_nonprim = NULL;
    }
    if (boot_options_local_nonprim) {
        instance_boot_options_free(boot_options_local_nonprim);
        boot_options_local_nonprim = NULL;
    }
    if (consolesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, consolesList) {
            instance_console_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(consolesList);
        consolesList = NULL;
    }
    if (interfacesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, interfacesList) {
            instance_interface_status_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(interfacesList);
        interfacesList = NULL;
    }
    if (services_local_nonprim) {
        instance_services_free(services_local_nonprim);
        services_local_nonprim = NULL;
    }
    if (agent_local_nonprim) {
        instance_agent_state_free(agent_local_nonprim);
        agent_local_nonprim = NULL;
    }
    if (net_mon_local_nonprim) {
        instance_netmon_state_free(net_mon_local_nonprim);
        net_mon_local_nonprim = NULL;
    }
    if (net_dump_local_nonprim) {
        instance_netdump_state_free(net_dump_local_nonprim);
        net_dump_local_nonprim = NULL;
    }
    if (core_trace_local_nonprim) {
        instance_trace_state_free(core_trace_local_nonprim);
        core_trace_local_nonprim = NULL;
    }
    if (hyper_trace_local_nonprim) {
        instance_hyper_trace_state_free(hyper_trace_local_nonprim);
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
    if (uefi_bootloader_local_nonprim) {
        instance_uefi_bootloader_free(uefi_bootloader_local_nonprim);
        uefi_bootloader_local_nonprim = NULL;
    }
    return NULL;

}
