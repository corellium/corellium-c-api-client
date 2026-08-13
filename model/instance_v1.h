/*
 * instance_v1.h
 *
 * 
 */

#ifndef _instance_v1_H_
#define _instance_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instance_v1_t instance_v1_t;

#include "created_by.h"
#include "instance_agent_state_v1.h"
#include "instance_boot_options_v1.h"
#include "instance_console_v1.h"
#include "instance_hyper_trace_state_v1.h"
#include "instance_netdump_state_v1.h"
#include "instance_netmon_state_v1.h"
#include "instance_read_only_status_v1.h"
#include "instance_restore_status_v1.h"
#include "instance_services_v1.h"
#include "instance_state_v1.h"
#include "instance_trace_state_v1.h"



typedef struct instance_v1_t {
    char *id; // string
    char *name; // string
    char *key; // string
    char *flavor; // string
    char *flavor_name; // string
    char *type; // string
    char *project; // string
    char *domain_name; // string
    corellium_api_instance_state_v1__e state; //referenced enum
    char *state_changed; //date time
    char *started_at; //date time
    char *user_task; // string
    char *task_state; // string
    char *error; // string
    struct instance_restore_status_v1_t *restore_status; //model
    struct instance_read_only_status_v1_t *read_only; //model
    struct instance_boot_options_v1_t *boot_options; //model
    char *service_ip; // string
    char *wifi_ip; // string
    char *wifi_mac; // string
    char *secondary_ip; // string
    double port_adb; //numeric
    double port_usb; //numeric
    double port_gdb; //numeric
    double port_sep_gdb; //numeric
    double port_cons; //numeric
    double port_sep_cons; //numeric
    double port_sys_cons; //numeric
    double port_usbmuxd; //numeric
    double port_frida; //numeric
    double port_sockcap; //numeric
    double port_model_gw; //numeric
    list_t *consoles; //nonprimitive container
    struct instance_services_v1_t *services; //model
    int panicked; //boolean
    char *created; //date time
    char *model; // string
    char *fwpackage; // string
    char *os; // string
    char *osbuild; // string
    struct instance_agent_state_v1_t *agent; //model
    struct instance_netmon_state_v1_t *netmon; //model
    struct instance_netdump_state_v1_t *netdump; //model
    struct instance_trace_state_v1_t *core_trace; //model
    struct instance_hyper_trace_state_v1_t *hyper_trace; //model
    char *expose_port; // string
    int fault; //boolean
    list_t *patches; //primitive container
    struct created_by_t *created_by; //model
    int uefi_bootloader; //boolean
    double orientation; //numeric
    int mast; //boolean
    int wan_access; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} instance_v1_t;

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
);

void instance_v1_free(instance_v1_t *instance_v1);

instance_v1_t *instance_v1_parseFromJSON(cJSON *instance_v1JSON);

cJSON *instance_v1_convertToJSON(instance_v1_t *instance_v1);

#endif /* _instance_v1_H_ */

