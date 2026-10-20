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


// Connect an I/O interface
//
// Connects one of this device's I/O interfaces (for example a GPIO bank, `gpio/0`) to an I/O interconnect, a virtual wire that links interfaces on different devices so they can signal each other. Create the interconnect first with the Interconnects endpoints. Requires the configurable I/O license feature (403 otherwise).
//
void
InstancesAPI_v3AttachInstanceInterface(apiClient_t *apiClient, char *instanceId, attach_interface_body_t *attach_interface_body);


// Clear kernel panics
//
// Deletes the recorded kernel panics for this device, so the next `v3GetInstancePanics` shows only new ones. An unknown `instanceId` is a successful no-op that returns 204.
//
void
InstancesAPI_v3ClearInstancePanics(apiClient_t *apiClient, char *instanceId);


// Create a device
//
// Creates a new virtual device (instance) in a project. This returns quickly with the new `id` and `state: \"creating\"`; the device is then built in the background, which can take several minutes. Poll `v3GetInstanceState` (or `v3GetInstance`) until the state is `on` before using it. If it becomes `error`, read the instance's `error` field.  **Minimum request:** `projectId`, `flavor`, and `osVersion` and/or `osBuild`.  **Typical steps:** 1. `GET /v3/models`: pick a model and note its `flavor`, allowed cores, and memory. 2. `GET /v3/models/{model}/software`: pick a build and note its `osVersion` and `osBuild`. 3. `POST /v3/instances` with `{ \"projectId\", \"flavor\", \"osVersion\", \"osBuild\" }`. Add `name` so you can find it later, and `bootOptions` (for example `cores`, `ram`) to change the defaults. 4. Poll the state until `on`.  **How the operating system is chosen.** With both `osVersion` and `osBuild`, that exact build is used. With only `osBuild`, the build with that ID is used. With only `osVersion`, the newest build of that version is used. To boot your own firmware file instead, set `fwPackage`.  Some options need license features (for example creating devices from custom firmware, or custom model definitions via `charmBootArgs`); using one your license lacks returns 403.
//
create_instance_response_t*
InstancesAPI_v3CreateInstance(apiClient_t *apiClient, create_instance_body_t *create_instance_body);


// Remove Instance
//
// Removes the instance. Deletion is asynchronous: the call schedules the teardown and returns 204 immediately, while the instance remains visible in a `deleting` state until teardown completes.  An `instanceId` that does not exist also returns 204. The API cannot tell a call with an invalid ID apart from a second call made to confirm an earlier delete succeeded, so both succeed. Repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing. A repeat therefore returns 204 both while the record is still present in the `deleting` state and after it has disappeared.
//
void
InstancesAPI_v3DeleteInstance(apiClient_t *apiClient, char *instanceId);


// Disconnect an I/O interface
//
// Disconnects one of this device's I/O interfaces from an I/O interconnect. Requires the configurable I/O license feature.  Deletes are idempotent: an unknown instance, interconnect or interface, including one that was already detached, is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing.
//
void
InstancesAPI_v3DetachInstanceInterface(apiClient_t *apiClient, char *instanceId, char *interfaceId, detach_interface_body_t *detach_interface_body);


// Stop exposing the device port
//
// Turns off the exposed port enabled with `v3EnableExposePort`. Runs as a background task on the device; returns 204 once it is scheduled.
//
void
InstancesAPI_v3DisableExposePort(apiClient_t *apiClient, char *instanceId);


// Download the Enhanced Network Monitor capture
//
// Downloads the packets recorded by Enhanced Network Monitor (see `v3StartNetdump`) as a pcapng file, which packet analyzers such as Wireshark open directly. Requires the Enhanced Network Monitor feature (403 otherwise).
//
binary_t*
InstancesAPI_v3DownloadNetdumpPcap(apiClient_t *apiClient, char *instanceId);


// Download the Network Monitor capture
//
// Downloads the traffic recorded by Network Monitor (see `v3StartNetworkMonitor`) as a pcap file. Save it with a `.pcap` extension and open it in a packet analyzer such as Wireshark. Download while monitoring runs or after stopping it.
//
binary_t*
InstancesAPI_v3DownloadNetworkMonitorPcap(apiClient_t *apiClient, char *instanceId);


// Expose the device port
//
// Turns on the exposed port for this device, for device access. This runs as a background task on the device; returns 204 once it is scheduled. Undo with `v3DisableExposePort`.
//
void
InstancesAPI_v3EnableExposePort(apiClient_t *apiClient, char *instanceId);


// Get a device
//
// Returns everything about one device: its name, model, operating system, state, boot options, network details and consoles. Use `state` to see whether it is ready, and `error` to see why it failed. Pass `returnAttr` to get only some fields.
//
instance_t*
InstancesAPI_v3GetInstance(apiClient_t *apiClient, char *instanceId, char *returnAttr);


// Get console websocket URL
//
// Get console WebSocket URL.  Instances can have more than one console. To connect to a specific console: 1. Call Get Instance and read the `consoles` array. 2. Take the `id` of the console you want and remove the `port-` prefix (e.g. `port-uart7-cons` becomes `uart7-cons`). 3. Pass that value as the `type` query parameter (e.g. `?type=uart7-cons`).  If `type` is omitted, the default console (`cons`) is used. Some models have no default console and require `type`.
//
instance_console_endpoint_t*
InstancesAPI_v3GetInstanceConsole(apiClient_t *apiClient, char *instanceId, char *type);


// Read the console log
//
// Returns the text output of the device's main console (serial output from boot messages, the kernel and system services) as plain text. Useful for seeing why a device will not boot. For a live, interactive console, use `v3GetInstanceConsole` instead.
//
char*
InstancesAPI_v3GetInstanceConsoleLog(apiClient_t *apiClient, char *instanceId);


// Read board LEDs, buttons and switches
//
// Returns the current state of the simulated LEDs, buttons and switches (GPIO pins) on an IoT or embedded board model, for example whether an LED your firmware drives is lit. The device must be running. Phone models do not have these, and the request fails for them. See `GpiosState` for the format.
//
gpios_state_t*
InstancesAPI_v3GetInstanceGpios(apiClient_t *apiClient, char *instanceId);


// Get image upload status
//
// Checks the progress of a chunked upload made with `v3PutInstanceImageUpload`, or downloads the finished file. With chunk parameters (`resumableChunkNumber` and friends) it returns 200 if that chunk is already stored and 204 if it still needs to be sent; without them it downloads the image file.
//
binary_t*
InstancesAPI_v3GetInstanceImageUpload(apiClient_t *apiClient, char *instance, char *type, char *imageId, char *name, double *resumableChunkNumber);


// List kernel panics
//
// Returns the kernel panics (crashes of the operating system itself) recorded on this device, as a list of panic records. An empty list means none have happened since the last clear. Clear them with `v3ClearInstancePanics`.
//
list_t*
InstancesAPI_v3GetInstancePanics(apiClient_t *apiClient, char *instanceId);


// Read simulated sensors
//
// Returns the current values of the device's simulated sensors and hardware: motion (accelerometer, gyroscope, compass), environment (temperature, light, pressure, humidity, proximity), GPS location, battery, and biometric bypass. Only values the device reports are included; a missing field does not mean zero. See `PeripheralsData`.
//
peripherals_data_t*
InstancesAPI_v3GetInstancePeripherals(apiClient_t *apiClient, char *instanceId);


// Get the SSH quick-connect command
//
// Returns a ready-to-paste SSH command for connecting to this device, as a JSON string. Run it in a terminal on a computer that can reach the device, for example one connected with the project VPN (`GET /v3/projects/{projectId}/vpnconfig/{format}`).
//
char*
InstancesAPI_v3GetInstanceQuickConnectCommand(apiClient_t *apiClient, char *instanceId);


// Take a screenshot
//
// Captures what the device's screen shows right now and returns it as an image. Choose the file type in the path: `screenshot.png` or `screenshot.jpeg`. Use `scale` to shrink it: `scale=2` returns half the width and height, `scale=4` a quarter; the default 1 is full size. The device must be running.
//
binary_t*
InstancesAPI_v3GetInstanceScreenshot(apiClient_t *apiClient, char *instanceId, char *format, double *scale);


// Get a device's state
//
// Returns only the device's current state (for example `creating`, `on`, `off`), as a bare JSON string. This is the call to poll while waiting for a device to finish creating, starting, stopping or rebooting. See `InstanceState` for what each value means.
//
corellium_api_instance_state__e
InstancesAPI_v3GetInstanceState(apiClient_t *apiClient, char *instanceId, char *returnAttr);


// Send an SMS message to an iOS device
//
// Delivers a text message to an iOS device as if it arrived over the cellular network, so apps see a normal incoming SMS. Useful for testing one-time-password and verification-code flows. Send either `number` (the sender's phone number) and `message` (the text), or `raw` with the message bytes in hexadecimal for low-level testing. The device must be running.
//
void
InstancesAPI_v3InjectMessage(apiClient_t *apiClient, char *instanceId, message_body_t *message_body);


// Get a kernel download token
//
// Returns a short-lived token that authorizes downloading this device's kernel file without an `Authorization` header, for loading into a disassembler or debugger. Download with `GET /v1/preauthed/{token}/{filename}`. The token works only for this device's kernel and expires when your current session token expires.
//
token_t*
InstancesAPI_v3KernelPreauthorize(apiClient_t *apiClient, char *instanceId);


// List Instances
//
// Lists the devices (instances) you can access across your projects. Results are paginated with `limit` and `offset`; use `name` to find a device by name. To list only one project's devices, use `GET /v3/projects/{projectId}/instances`.
//
instance_list_t*
InstancesAPI_v3ListInstances(apiClient_t *apiClient, double *limit, double *offset, char *name, char *returnAttr);


// Play a video or audio file into the device
//
// Plays a media file into the device, so apps receive it as if it came from the device's camera (video) and microphone (audio). Use it to test camera or scanning features, for example feeding a QR code video to an app. Open the camera app on the device to see it.  Give exactly one source: `imageId` of a `media` image you uploaded with `POST /v3/images`, or a `url` the platform can download the file from. Returns 204 once playback starts. Call `v3MediaStop` to stop it.
//
void
InstancesAPI_v3MediaPlay(apiClient_t *apiClient, char *instanceId, media_play_body_t *media_play_body);


// Stop playing media
//
// Stops media started with `v3MediaPlay`.
//
void
InstancesAPI_v3MediaStop(apiClient_t *apiClient, char *instanceId);


// Change device settings
//
// Changes a device's settings. Send only the fields you want to change: `name` (the label shown in lists), `bootOptions` (for example `cores`, `ram`, boot arguments), `proxy` (which device ports are forwarded, and whether they are reachable from outside the project), and `straceFilter` (which processes CoreTrace records, by name, process ID or thread ID; see `v3ListThreads`). Returns the updated device. This call does not turn the device on or off; use `v3StartInstance`, `v3StopInstance`, `v3RebootInstance`, `v3PauseInstance` and `v3UnpauseInstance` for that.
//
instance_t*
InstancesAPI_v3PatchInstance(apiClient_t *apiClient, char *instanceId, patch_instance_body_t *patch_instance_body);


// Update Instance Read Only
//
// Turns read-only mode on or off for the device. Returns the updated device.
//
instance_t*
InstancesAPI_v3PatchInstanceReadOnly(apiClient_t *apiClient, char *instanceId, patch_instance_read_only_body_t *patch_instance_read_only_body);


// Pause a device
//
// Freezes a running device in place without shutting it down: it stops executing but keeps its memory and state, so `v3UnpauseInstance` resumes it exactly where it stopped. The state becomes `paused`.
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
// Uploads one chunk of a file attached to this device, using the same resumable protocol as `PUT /v3/images/{imageId}/file`. You choose the image ID (a new random UUID) and the image record is created on the first chunk; `type` and `name` in the path set the image type and name. Because the image is attached to the device, it replaces any image of the same `type` already attached (for `partition`, only the one with the same `name`), and it is deleted when the device is deleted. The web interface uses this route, for example to replace a kernel. For your own code, `POST /v3/images` with `instanceId` followed by `PUT /v3/images/{imageId}/file` is easier to follow. Returns 200 with an empty object for each stored chunk.
//
object_t*
InstancesAPI_v3PutInstanceImageUpload(apiClient_t *apiClient, char *instance, char *type, char *imageId, char *name, binary_t* body, double *resumableChunkNumber, double *resumableChunkSize, double *resumableCurrentChunkSize, double *resumableTotalSize, double *resumableTotalChunks, char *corelliumChecksum, char *flavor, char *x_corellium_image_encoding, int *x_corellium_image_encapsulated, double *x_corellium_total_file_size, char *x_corellium_image_password);


// Restart a device
//
// Restarts a running device. Returns 204 once the reboot is accepted; the state becomes `rebooting` and then `on`. Poll `v3GetInstanceState` to see when it is back.
//
void
InstancesAPI_v3RebootInstance(apiClient_t *apiClient, char *instanceId);


// Restore a backup onto a device
//
// Restores the backup attached to this device, replacing the device's data with the backup's contents. First attach the backup file by uploading it with `POST /v3/images` using `type: \"backup\"` and `instanceId` set to this device. Returns 204 once the restore has been scheduled; it runs in the background, so poll `v3GetInstanceState` until the device settles.  Supply `password` if the backup is encrypted. Fails with 404 if no backup is attached. Requires the backup-restore license feature (403 otherwise).
//
void
InstancesAPI_v3RestoreBackup(apiClient_t *apiClient, char *instanceId, restore_backup_body_t *restore_backup_body);


// Rotate the device
//
// Turns the device to a new orientation, as if you rotated the phone in your hand; apps receive the rotation event. `orientation` is 1 = portrait, 2 = portrait upside down, 3 = landscape (top of device on the left), 4 = landscape (top of device on the right).
//
void
InstancesAPI_v3RotateInstance(apiClient_t *apiClient, char *instanceId, rotate_body_t *rotate_body);


// Press board buttons or flip switches
//
// Sets the state of the simulated buttons and switches (GPIO pins) on an IoT or embedded board model, as if you pressed a button or flipped a switch on real hardware; your firmware sees the change. Send the full bank layout you got from `v3GetInstanceGpios`, with the bits you want changed. Returns the state after the change. The device must be running.
//
gpios_state_t*
InstancesAPI_v3SetInstanceGpios(apiClient_t *apiClient, char *instanceId, gpios_state_t *gpios_state);


// Change simulated sensors
//
// Changes what the device's simulated sensors report to apps, for example to fake a GPS location, a low battery, or a tilt. Send only the fields you want to change. The new values are saved with the device and then the current readings are returned.  A field is applied only if its feature is enabled for the device (motion, environment, location, battery, biometric bypass); values for disabled features are ignored silently, so check the response. `biometricPass: 1` makes fingerprint and face checks succeed.
//
peripherals_data_t*
InstancesAPI_v3SetInstancePeripherals(apiClient_t *apiClient, char *instanceId, peripherals_data_t *peripherals_data);


// Turn a device on
//
// Turns on a device that is `off`. Returns 204 as soon as the start is accepted; the device then boots in the background. Poll `v3GetInstanceState` until it is `on`. Returns 409 if the device is already on.  **Starting paused (`paused: true`).** The device is powered on but no code runs until you call `v3UnpauseInstance` or resume it from a debugger. This is the standard way to debug a device from its very first instruction, for example custom or IoT firmware, or code that runs early in boot: 1. Upload your firmware and create the device (or stop an existing one). 2. `v3StartInstance` with `{ \"paused\": true }`. 3. Connect your debugger (for example GDB) to the device's debug port, shown in the device's connection details. 4. Load symbols from your firmware or kernel file, set breakpoints, or load code into memory. 5. Continue execution from the debugger (`c` in GDB).  Once a debugger is attached, pause and resume from the debugger rather than with `v3PauseInstance` / `v3UnpauseInstance`: GDB expects to control pausing itself, and pausing through the API can confuse its session.  **Network monitoring (`sockCap: true`).** Starts the device with process network monitoring enabled, so network activity can be attributed to the processes that made it.
//
void
InstancesAPI_v3StartInstance(apiClient_t *apiClient, char *instanceId, start_instance_body_t *start_instance_body);


// Start Enhanced Network Monitor
//
// Starts Enhanced Network Monitor on this device. It captures raw network packets, and every filter in the body is optional: limit the capture to certain ports, protocols, hosts, or process names to keep it small. Download it with `v3DownloadNetdumpPcap`. Requires the Enhanced Network Monitor feature (403 otherwise).
//
void
InstancesAPI_v3StartNetdump(apiClient_t *apiClient, char *instanceId, enable_netdump_body_t *enable_netdump_body);


// Start Network Monitor
//
// Starts Network Monitor on this device. It records the device's network traffic, including HTTPS traffic decrypted by intercepting its encryption, so you can see what apps send and receive. Download the capture as a pcap file (open it with Wireshark) with `v3DownloadNetworkMonitorPcap`. Apps that pin their certificates may refuse the intercepted connections. Requires the Network Monitor license feature (403 otherwise).
//
void
InstancesAPI_v3StartNetworkMonitor(apiClient_t *apiClient, char *instanceId, enable_sslsplit_body_t *enable_sslsplit_body);


// Turn a device off
//
// Turns a running device off. By default (`soft: true`) the operating system is asked to shut down cleanly. Send `{ \"soft\": false }` to force an immediate stop instead; use it when a clean shutdown does not finish. Returns 204 once the stop is accepted; poll `v3GetInstanceState` until it is `off`. Returns 409 if the device is already off. A stopped device keeps its storage and can be turned on again with `v3StartInstance`.
//
void
InstancesAPI_v3StopInstance(apiClient_t *apiClient, char *instanceId, stop_instance_body_t *stop_instance_body);


// Stop Enhanced Network Monitor
//
// Stops Enhanced Network Monitor on this device. The capture so far can still be downloaded with `v3DownloadNetdumpPcap`.
//
void
InstancesAPI_v3StopNetdump(apiClient_t *apiClient, char *instanceId);


// Stop Network Monitor
//
// Stops Network Monitor on this device. The capture so far can still be downloaded with `v3DownloadNetworkMonitorPcap`. Requires the Network Monitor license feature.
//
void
InstancesAPI_v3StopNetworkMonitor(apiClient_t *apiClient, char *instanceId);


// Resume a paused device
//
// Resumes a device that was paused with `v3PauseInstance`, or started with `paused: true`. It continues from exactly where it stopped.
//
void
InstancesAPI_v3UnpauseInstance(apiClient_t *apiClient, char *instanceId);


// Upgrade the iOS version
//
// Upgrades an iOS device to a newer iOS version while keeping it as the same device. Returns 202 with `state: \"updating\"` once accepted; the upgrade runs in the background, so poll `v3GetInstanceState` until it is `on`. Pick the version from `GET /v3/models/{model}/software`. Use `osVersion`; the old `os` field is rejected. Requires the OS update license feature (403 otherwise).
//
instance_upgrade_response_t*
InstancesAPI_v3UpgradeInstance(apiClient_t *apiClient, char *instanceId, instance_upgrade_body_t *instance_upgrade_body);


// Check a device connection token
//
// Checks whether a connection token issued for this device is still valid. Returns 204 if it is. This call needs no `Authorization` header; the token in the body is what is checked.
//
void
InstancesAPI_v3ValidateInstanceToken(apiClient_t *apiClient, char *instanceId, token_validate_body_t *token_validate_body);


