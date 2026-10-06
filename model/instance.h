/*
 * instance.h
 *
 * 
 */

#ifndef _instance_H_
#define _instance_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instance_t instance_t;

#include "created_by.h"
#include "instance_agent_state.h"
#include "instance_boot_options.h"
#include "instance_console.h"
#include "instance_hyper_trace_state.h"
#include "instance_interface_status.h"
#include "instance_netdump_state.h"
#include "instance_netmon_state.h"
#include "instance_read_only_status.h"
#include "instance_restore_status.h"
#include "instance_services.h"
#include "instance_state.h"
#include "instance_trace_state.h"
#include "instance_uefi_bootloader.h"



typedef struct instance_t {
    char *id; // string
    char *name; // string
    char *key; // string
    char *flavor; // string
    char *flavor_name; // string
    char *type; // string
    char *project; // string
    char *domain_name; // string
    corellium_api_instance_state__e state; //referenced enum
    char *state_changed; //date time
    char *started_at; //date time
    char *user_task; // string
    char *task_state; // string
    char *error; // string
    struct instance_restore_status_t *restore_status; //model
    struct instance_read_only_status_t *read_only; //model
    struct instance_boot_options_t *boot_options; //model
    char *service_ip; // string
    char *wifi_ip; // string
    char *wifi_mac; // string
    char *secondary_ip; // string
    char *port_adb; // string
    char *port_usb; // string
    char *port_gdb; // string
    char *port_sep_gdb; // string
    char *port_cons; // string
    char *port_sep_cons; // string
    char *port_sys_cons; // string
    char *port_usbmuxd; // string
    char *port_frida; // string
    char *port_sockcap; // string
    char *port_model_gw; // string
    list_t *consoles; //nonprimitive container
    list_t *interfaces; //nonprimitive container
    struct instance_services_t *services; //model
    int panicked; //boolean
    char *created; //date time
    char *model; // string
    char *fw_package; // string
    char *os_version; // string
    char *os_build; // string
    struct instance_agent_state_t *agent; //model
    struct instance_netmon_state_t *net_mon; //model
    struct instance_netdump_state_t *net_dump; //model
    struct instance_trace_state_t *core_trace; //model
    struct instance_hyper_trace_state_t *hyper_trace; //model
    char *expose_port; // string
    int fault; //boolean
    list_t *patches; //primitive container
    struct created_by_t *created_by; //model
    struct instance_uefi_bootloader_t *uefi_bootloader; //model
    double orientation; //numeric
    int mast; //boolean
    int wan_access; //boolean
    int has_corelliumd; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} instance_t;

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
);

void instance_free(instance_t *instance);

instance_t *instance_parseFromJSON(cJSON *instanceJSON);

cJSON *instance_convertToJSON(instance_t *instance);

#endif /* _instance_H_ */

