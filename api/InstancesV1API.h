#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/api_error_v1.h"
#include "../model/api_not_found_error_v1.h"
#include "../model/attach_interface_request.h"
#include "../model/detach_interface_request.h"
#include "../model/gpios_state_v1.h"
#include "../model/input_response_v1.h"
#include "../model/instance_console_endpoint_v1.h"
#include "../model/instance_create_options.h"
#include "../model/instance_input_request.h"
#include "../model/instance_return.h"
#include "../model/instance_start_options.h"
#include "../model/instance_stop_options.h"
#include "../model/instance_upgrade_body_v1.h"
#include "../model/instance_v1.h"
#include "../model/media_play_body_v1.h"
#include "../model/netdump_filter.h"
#include "../model/object.h"
#include "../model/patch_instance_options.h"
#include "../model/patch_instance_read_only.h"
#include "../model/peripherals_data_v1.h"
#include "../model/restore_backup_data.h"
#include "../model/rotate_body_v1.h"
#include "../model/sslsplit_filter.h"
#include "../model/user_error_v1.h"
#include "../model/v1_set_state_body.h"
#include "../model/validation_error.h"


// Attach I/O Interface
//
// Attach an I/O interface to an I/O interconnect for the specified instance identifier.
//
void
InstancesV1API_v1AttachInstanceInterface(apiClient_t *apiClient, char *instanceId, attach_interface_request_t *attach_interface_request);


// Clear Panics
//
void
InstancesV1API_v1ClearInstancePanics(apiClient_t *apiClient, char *instanceId);


// Create Instance
//
instance_return_t*
InstancesV1API_v1CreateInstance(apiClient_t *apiClient, instance_create_options_t *instance_create_options);


// Remove Instance
//
void
InstancesV1API_v1DeleteInstance(apiClient_t *apiClient, char *instanceId);


// Detach I/O Interface
//
// Detach an I/O interface from an I/O interconnect for the specified instance identifier.
//
void
InstancesV1API_v1DetachInstanceInterface(apiClient_t *apiClient, char *instanceId, char *interfaceId, detach_interface_request_t *detach_interface_request);


// Disable an exposed port on an instance for device access.
//
void
InstancesV1API_v1DisableExposePort(apiClient_t *apiClient, char *instanceId);


// Download a netdump pcap file
//
binary_t*
InstancesV1API_v1DownloadNetdumpPcapInstances(apiClient_t *apiClient, char *instanceId);


// Download a Network Monitor pcap file
//
binary_t*
InstancesV1API_v1DownloadNetworkMonitorPcapInstances(apiClient_t *apiClient, char *instanceId);


// Enable an exposed port on an instance for device access.
//
void
InstancesV1API_v1EnableExposePort(apiClient_t *apiClient, char *instanceId);


// Get Instance
//
instance_v1_t*
InstancesV1API_v1GetInstance(apiClient_t *apiClient, char *instanceId, char *returnAttr);


// Get console websocket URL
//
instance_console_endpoint_v1_t*
InstancesV1API_v1GetInstanceConsole(apiClient_t *apiClient, char *instanceId);


// Get Console Log
//
char*
InstancesV1API_v1GetInstanceConsoleLog(apiClient_t *apiClient, char *instanceId);


// Get Instance GPIOs
//
gpios_state_v1_t*
InstancesV1API_v1GetInstanceGpios(apiClient_t *apiClient, char *instanceId);


// Get Panics
//
list_t*
InstancesV1API_v1GetInstancePanics(apiClient_t *apiClient, char *instanceId);


// Get Instance Peripherals
//
peripherals_data_v1_t*
InstancesV1API_v1GetInstancePeripherals(apiClient_t *apiClient, char *instanceId);


// Get Instance Screenshot
//
binary_t*
InstancesV1API_v1GetInstanceScreenshot(apiClient_t *apiClient, char *instanceId, char *format, double *scale);


// Get Instances
//
list_t*
InstancesV1API_v1GetInstances(apiClient_t *apiClient, char *name, char *returnAttr);


// Inject a message into an iOS VM
//
// Given a message and source phone number, place this message as an incoming SMS message on the iOS VM. For advanced usage, a raw message of bytes may be sent. In this case, the parameter should provide hex encoded bytes  (0x00 0x11 0x22 0x33 in the example below) which are sent verbatim.  The user must ensure that the body is the correct format for the underlying device stack.
//
void
InstancesV1API_v1InjectMessageInstances(apiClient_t *apiClient, char *instanceId, object_t *body);


// Start playing media
//
void
InstancesV1API_v1MediaPlay(apiClient_t *apiClient, char *instanceId, media_play_body_v1_t *media_play_body_v1);


// Stop playing media
//
void
InstancesV1API_v1MediaStop(apiClient_t *apiClient, char *instanceId);


// Update Instance
//
instance_v1_t*
InstancesV1API_v1PatchInstance(apiClient_t *apiClient, char *instanceId, patch_instance_options_t *patch_instance_options);


// Update Instance Read Only
//
instance_v1_t*
InstancesV1API_v1PatchInstanceReadOnly(apiClient_t *apiClient, char *instanceId, patch_instance_read_only_t *patch_instance_read_only);


// Pause an Instance
//
void
InstancesV1API_v1PauseInstance(apiClient_t *apiClient, char *instanceId);


// Provide Instance Input
//
// Sends a touch or button event to the VM.  - Buttons (or keys) to be held during the input are specified as an array of strings, each string must be either a single ascii character or one of the following keywords:   - VM Buttons (case-insensitive): finger, homeButton, holdButton (Power/Hold), volumeUp, volumeDown, backButton, overviewButton. ringerSwitch is not supported.   - Keyboard Buttons: again, alt, alterase, apostrophe, back, backslash, backspace, bassboost, bookmarks, bsp, calc, camera, cancel, caps, capslock, chat, close, closecd, comma, compose, computer, config, connect, copy, ctrl, cut, cyclewindows, dashboard, del, delete, deletefile, dot, down, edit, eject, ejectclose, email, end, enter, equal, esc, escape, exit, f1, f10, f11, f12, f13, f14, f15, f16, f17, f18, f19, f2, f20, f21, f22, f23, f24, f3, f4, f5, f6, f7, f8, f9, fastfwd, file, finance, find, forward, front, grave, hangeul, hanja, help, henkan, home, homepage, hp, hrgn, ins, insert, iso, k102, kp0, kp1, kp2, kp3, kp4, kp5, kp6, kp7, kp8, kp9, kpasterisk, kpcomma, kpdot, kpenter, kpequal, kpjpcomma, kpleftparen, kpminus, kpplus, kpplusminus, kprightparen, kpslash, ktkn, ktknhrgn, left, leftalt, leftbrace, leftctrl, leftmeta, leftshift, linefeed, macro, mail, menu, meta, minus, move, msdos, muhenkan, mute, new, next, numlock, open, pagedown, pageup, paste, pause, pausecd, pgdn, pgup, phone, play, playcd, playpause, power, previous, print, prog1, prog2, prog3, prog4, props, question, record, redo, refresh, return, rewind, right, rightalt, rightbrace, rightctrl, rightmeta, rightshift, ro, rotate, scale, screenlock, scrolldown, scrolllock, scrollup, search, semicolon, sendfile, setup, shift, shop, slash, sleep, sound, space, sport, stop, stopcd, suspend, sysrq, tab, undo, up, voldown, volup, wakeup, www, xfer, yen, zkhk
//
input_response_v1_t*
InstancesV1API_v1PostInstanceInput(apiClient_t *apiClient, char *instanceId, list_t *instance_input_request);


// Reboot an Instance
//
void
InstancesV1API_v1RebootInstance(apiClient_t *apiClient, char *instanceId);


// Restore backup
//
void
InstancesV1API_v1RestoreBackup(apiClient_t *apiClient, char *instanceId, restore_backup_data_t *restore_backup_data);


// Rotate device to specified orientation
//
// Rotate device to orientation.  Accepted orientations: 1. Portrait 2. Portrait vertically inverted (up-side-down) 3. Landscape with top of the device to the left 4. Landscape with top of the device to the right
//
void
InstancesV1API_v1RotateInstance(apiClient_t *apiClient, char *instanceId, rotate_body_v1_t *rotate_body_v1);


// Set Instance GPIOs
//
gpios_state_v1_t*
InstancesV1API_v1SetInstanceGpios(apiClient_t *apiClient, char *instanceId, gpios_state_v1_t *gpios_state_v1);


// Set Instance Peripherals
//
peripherals_data_v1_t*
InstancesV1API_v1SetInstancePeripherals(apiClient_t *apiClient, char *instanceId, peripherals_data_v1_t *peripherals_data_v1);


// Set state of Instance
//
void
InstancesV1API_v1SetInstanceState(apiClient_t *apiClient, char *instanceId, v1_set_state_body_t *v1_set_state_body);


// Start an Instance
//
void
InstancesV1API_v1StartInstance(apiClient_t *apiClient, char *instanceId, instance_start_options_t *instance_start_options);


// Start Enhanced Network Monitor on an instance.
//
void
InstancesV1API_v1StartNetdump(apiClient_t *apiClient, char *instanceId, netdump_filter_t *netdump_filter);


// Start Network Monitor on an instance.
//
void
InstancesV1API_v1StartNetworkMonitor(apiClient_t *apiClient, char *instanceId, sslsplit_filter_t *sslsplit_filter);


// Stop an Instance
//
void
InstancesV1API_v1StopInstance(apiClient_t *apiClient, char *instanceId, instance_stop_options_t *instance_stop_options);


// Stop Enhanced Network Monitor on an instance.
//
void
InstancesV1API_v1StopNetdump(apiClient_t *apiClient, char *instanceId);


// Stop Network Monitor on an instance.
//
void
InstancesV1API_v1StopNetworkMonitor(apiClient_t *apiClient, char *instanceId);


// Unpause an Instance
//
void
InstancesV1API_v1UnpauseInstance(apiClient_t *apiClient, char *instanceId);


// Upgrade iOS version
//
void
InstancesV1API_v1UpgradeInstance(apiClient_t *apiClient, char *instanceId, instance_upgrade_body_v1_t *instance_upgrade_body_v1);


