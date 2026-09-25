#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/any_type.h"
#include "../model/api_conflict_error.h"
#include "../model/api_error.h"
#include "../model/api_not_found_error.h"
#include "../model/attach_interface_body.h"
#include "../model/create_instance_body.h"
#include "../model/create_instance_response.h"
#include "../model/detach_interface_body.h"
#include "../model/enable_netdump_body.h"
#include "../model/enable_sslsplit_body.h"
#include "../model/gpios_state.h"
#include "../model/input_response.h"
#include "../model/instance.h"
#include "../model/instance_console_endpoint.h"
#include "../model/instance_input_body.h"
#include "../model/instance_list.h"
#include "../model/instance_state.h"
#include "../model/instance_upgrade_body.h"
#include "../model/instance_upgrade_response.h"
#include "../model/insufficient_storage_error.h"
#include "../model/media_play_body.h"
#include "../model/message_body.h"
#include "../model/object.h"
#include "../model/patch_instance_body.h"
#include "../model/patch_instance_read_only_body.h"
#include "../model/peripherals_data.h"
#include "../model/restore_backup_body.h"
#include "../model/rotate_body.h"
#include "../model/start_instance_body.h"
#include "../model/stop_instance_body.h"
#include "../model/token.h"
#include "../model/token_validate_body.h"
#include "../model/user_error_response.h"


// Attach I/O Interface
//
// Attach an I/O interface to an I/O interconnect for the specified instance identifier.
//
void
InstancesAPI_v3AttachInstanceInterface(apiClient_t *apiClient, char *instanceId, attach_interface_body_t *attach_interface_body);


// Clear Panics
//
void
InstancesAPI_v3ClearInstancePanics(apiClient_t *apiClient, char *instanceId);


// Create Instance
//
create_instance_response_t*
InstancesAPI_v3CreateInstance(apiClient_t *apiClient, create_instance_body_t *create_instance_body);


// Remove Instance
//
void
InstancesAPI_v3DeleteInstance(apiClient_t *apiClient, char *instanceId);


// Detach I/O Interface
//
// Detach an I/O interface from an I/O interconnect for the specified instance identifier.
//
void
InstancesAPI_v3DetachInstanceInterface(apiClient_t *apiClient, char *instanceId, char *interfaceId, detach_interface_body_t *detach_interface_body);


// Disable an exposed port on an instance for device access.
//
void
InstancesAPI_v3DisableExposePort(apiClient_t *apiClient, char *instanceId);


// Download a netdump pcap file
//
binary_t*
InstancesAPI_v3DownloadNetdumpPcap(apiClient_t *apiClient, char *instanceId);


// Download a Network Monitor pcap file
//
// Downloads the Network Monitor capture for the instance as a pcap file.
//
binary_t*
InstancesAPI_v3DownloadNetworkMonitorPcap(apiClient_t *apiClient, char *instanceId);


// Enable an exposed port on an instance for device access.
//
void
InstancesAPI_v3EnableExposePort(apiClient_t *apiClient, char *instanceId);


// Get Instance
//
instance_t*
InstancesAPI_v3GetInstance(apiClient_t *apiClient, char *instanceId, char *returnAttr);


// Get console websocket URL
//
instance_console_endpoint_t*
InstancesAPI_v3GetInstanceConsole(apiClient_t *apiClient, char *instanceId);


// Get Console Log
//
char*
InstancesAPI_v3GetInstanceConsoleLog(apiClient_t *apiClient, char *instanceId);


// Get Instance GPIOs
//
gpios_state_t*
InstancesAPI_v3GetInstanceGpios(apiClient_t *apiClient, char *instanceId);


// Get image upload status
//
// Check resumable upload status for an instance image or download the image file.
//
binary_t*
InstancesAPI_v3GetInstanceImageUpload(apiClient_t *apiClient, char *instance, char *type, char *imageId, char *name, double *resumableChunkNumber);


// Get Panics
//
list_t*
InstancesAPI_v3GetInstancePanics(apiClient_t *apiClient, char *instanceId);


// Get Instance Peripherals
//
peripherals_data_t*
InstancesAPI_v3GetInstancePeripherals(apiClient_t *apiClient, char *instanceId);


// Recommended SSH Command for Quick Connect
//
char*
InstancesAPI_v3GetInstanceQuickConnectCommand(apiClient_t *apiClient, char *instanceId);


// Get Instance Screenshot
//
binary_t*
InstancesAPI_v3GetInstanceScreenshot(apiClient_t *apiClient, char *instanceId, char *format, double *scale);


// Get state of Instance
//
corellium_api_instance_state__e
InstancesAPI_v3GetInstanceState(apiClient_t *apiClient, char *instanceId, char *returnAttr);


// Inject a message into an iOS VM
//
// Given a message and source phone number, place this message as an incoming SMS message on the iOS VM. A raw hex-encoded message body may also be sent.
//
void
InstancesAPI_v3InjectMessage(apiClient_t *apiClient, char *instanceId, message_body_t *message_body);


// Pre-authorize a kernel download
//
// Pre-authorize a kernel download. Returns a token that authorizes the kernel download request.
//
token_t*
InstancesAPI_v3KernelPreauthorize(apiClient_t *apiClient, char *instanceId);


// List Instances
//
instance_list_t*
InstancesAPI_v3ListInstances(apiClient_t *apiClient, double *limit, double *offset, char *name, char *returnAttr);


// Start playing media
//
void
InstancesAPI_v3MediaPlay(apiClient_t *apiClient, char *instanceId, media_play_body_t *media_play_body);


// Stop playing media
//
void
InstancesAPI_v3MediaStop(apiClient_t *apiClient, char *instanceId);


// Update Instance
//
// Update instance configuration such as name, boot options, and proxy settings. To change an instance run state, use the start, stop, reboot, pause, and unpause action endpoints.
//
instance_t*
InstancesAPI_v3PatchInstance(apiClient_t *apiClient, char *instanceId, patch_instance_body_t *patch_instance_body);


// Update Instance Read Only
//
// Updates the read-only state of the instance.
//
instance_t*
InstancesAPI_v3PatchInstanceReadOnly(apiClient_t *apiClient, char *instanceId, patch_instance_read_only_body_t *patch_instance_read_only_body);


// Pause an Instance
//
void
InstancesAPI_v3PauseInstance(apiClient_t *apiClient, char *instanceId);


// Provide Instance Input
//
// Sends a touch or button event to the VM. Events in the request array are processed in order.  Each element of the request array is one of: - **TouchInputRequest** – holds buttons (or keys) and/or touches at a screen position.   - Set `buttons` to `[\"finger\"]` to press down and `[]` to release all buttons.   - Omit `buttons` to leave the current press state unchanged.   - `position` is an array of per-finger `[x, y]` coordinates. May be omitted for button-only input. - **TouchCurveInputRequest** – animates a drag/swipe from `start` to `end` over `duration` ms.   - Optional `bezierPoints` shape the path; omit for a straight-line drag. - **TextInputRequest** – types the given text.  Buttons (or keys) accepted by `buttons` / `startButtons` / `endButtons` are an array of strings, each either a single ASCII character or one of the following keywords: - VM buttons (case-insensitive): `finger`, `homeButton`, `holdButton` (Power/Hold),   `volumeUp`, `volumeDown`, `backButton`, `overviewButton`. `ringerSwitch` is not supported. - Keyboard key names: `again`, `alt`, `alterase`, `apostrophe`, `back`, `backslash`, `backspace`,   `bassboost`, `bookmarks`, `bsp`, `calc`, `camera`, `cancel`, `caps`, `capslock`, `chat`, `close`,   `closecd`, `comma`, `compose`, `computer`, `config`, `connect`, `copy`, `ctrl`, `cut`,   `cyclewindows`, `dashboard`, `del`, `delete`, `deletefile`, `dot`, `down`, `edit`, `eject`,   `ejectclose`, `email`, `end`, `enter`, `equal`, `esc`, `escape`, `exit`, `f1`–`f24`, `fastfwd`,   `file`, `finance`, `find`, `forward`, `front`, `grave`, `hangeul`, `hanja`, `help`,   `henkan`, `home`, `homepage`, `hp`, `hrgn`, `ins`, `insert`, `iso`, `k102`, `kp0`–`kp9`,   `kpasterisk`, `kpcomma`, `kpdot`, `kpenter`, `kpequal`, `kpjpcomma`, `kpleftparen`, `kpminus`,   `kpplus`, `kpplusminus`, `kprightparen`, `kpslash`, `ktkn`, `ktknhrgn`, `left`, `leftalt`,   `leftbrace`, `leftctrl`, `leftmeta`, `leftshift`, `linefeed`, `macro`, `mail`, `menu`, `meta`,   `minus`, `move`, `msdos`, `muhenkan`, `mute`, `new`, `next`, `numlock`, `open`, `pagedown`,   `pageup`, `paste`, `pause`, `pausecd`, `pgdn`, `pgup`, `phone`, `play`, `playcd`, `playpause`,   `power`, `previous`, `print`, `prog1`–`prog4`, `props`, `question`, `record`, `redo`, `refresh`,   `return`, `rewind`, `right`, `rightalt`, `rightbrace`, `rightctrl`, `rightmeta`, `rightshift`,   `ro`, `rotate`, `scale`, `screenlock`, `scrolldown`, `scrolllock`, `scrollup`, `search`,   `semicolon`, `sendfile`, `setup`, `shift`, `shop`, `slash`, `sleep`, `sound`, `space`, `sport`,   `stop`, `stopcd`, `suspend`, `sysrq`, `tab`, `undo`, `up`, `voldown`, `volup`, `wakeup`, `www`,   `xfer`, `yen`, `zkhk`.  Use `finger:1` to press the fingerprint sensor (see the `fingerprint` example).
//
input_response_t*
InstancesAPI_v3PostInstanceInput(apiClient_t *apiClient, char *instanceId, list_t *instance_input_body);


// Upload image chunk
//
// Upload a chunk of an instance image using the resumable upload protocol. Creates the image record on the first chunk if it does not yet exist.
//
object_t*
InstancesAPI_v3PutInstanceImageUpload(apiClient_t *apiClient, char *instance, char *type, char *imageId, char *name, binary_t* body, double *resumableChunkNumber, double *resumableChunkSize, double *resumableCurrentChunkSize, double *resumableTotalSize, double *resumableTotalChunks, char *corelliumChecksum, char *flavor, char *x_corellium_image_encoding, int *x_corellium_image_encapsulated, double *x_corellium_total_file_size, char *x_corellium_image_password);


// Reboot an Instance
//
void
InstancesAPI_v3RebootInstance(apiClient_t *apiClient, char *instanceId);


// Restore backup
//
void
InstancesAPI_v3RestoreBackup(apiClient_t *apiClient, char *instanceId, restore_backup_body_t *restore_backup_body);


// Rotate device to specified orientation
//
// Rotate device to orientation. 1=Portrait, 2=Portrait inverted, 3=Landscape (top left), 4=Landscape (top right).
//
void
InstancesAPI_v3RotateInstance(apiClient_t *apiClient, char *instanceId, rotate_body_t *rotate_body);


// Set Instance GPIOs
//
gpios_state_t*
InstancesAPI_v3SetInstanceGpios(apiClient_t *apiClient, char *instanceId, gpios_state_t *gpios_state);


// Update Instance Peripherals
//
peripherals_data_t*
InstancesAPI_v3SetInstancePeripherals(apiClient_t *apiClient, char *instanceId, peripherals_data_t *peripherals_data);


// Start an Instance
//
void
InstancesAPI_v3StartInstance(apiClient_t *apiClient, char *instanceId, start_instance_body_t *start_instance_body);


// Start Enhanced Network Monitor on an instance.
//
void
InstancesAPI_v3StartNetdump(apiClient_t *apiClient, char *instanceId, enable_netdump_body_t *enable_netdump_body);


// Start Network Monitor on an instance.
//
void
InstancesAPI_v3StartNetworkMonitor(apiClient_t *apiClient, char *instanceId, enable_sslsplit_body_t *enable_sslsplit_body);


// Stop an Instance
//
void
InstancesAPI_v3StopInstance(apiClient_t *apiClient, char *instanceId, stop_instance_body_t *stop_instance_body);


// Stop Enhanced Network Monitor on an instance.
//
void
InstancesAPI_v3StopNetdump(apiClient_t *apiClient, char *instanceId);


// Stop Network Monitor on an instance.
//
void
InstancesAPI_v3StopNetworkMonitor(apiClient_t *apiClient, char *instanceId);


// Unpause an Instance
//
void
InstancesAPI_v3UnpauseInstance(apiClient_t *apiClient, char *instanceId);


// Upgrade iOS version
//
instance_upgrade_response_t*
InstancesAPI_v3UpgradeInstance(apiClient_t *apiClient, char *instanceId, instance_upgrade_body_t *instance_upgrade_body);


// Validate instance token
//
// Validates a connection token for the instance.
//
void
InstancesAPI_v3ValidateInstanceToken(apiClient_t *apiClient, char *instanceId, token_validate_body_t *token_validate_body);


