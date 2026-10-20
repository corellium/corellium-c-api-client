/*
 * web_player_features.h
 *
 * Which parts of the device interface the viewer may use, for example &#x60;apps&#x60;, &#x60;files&#x60; or &#x60;console&#x60;. Only features set to true are available in the session.
 */

#ifndef _web_player_features_H_
#define _web_player_features_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct web_player_features_t web_player_features_t;




typedef struct web_player_features_t {
    int apps; //boolean
    int connect; //boolean
    int console; //boolean
    int coretrace; //boolean
    int device_control; //boolean
    int device_delete; //boolean
    int files; //boolean
    int frida; //boolean
    int images; //boolean
    int messaging; //boolean
    int netmon; //boolean
    int network; //boolean
    int port_forwarding; //boolean
    int power_management; //boolean
    int profile; //boolean
    int sensors; //boolean
    int settings; //boolean
    int snapshots; //boolean
    int strace; //boolean
    int system; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} web_player_features_t;

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
);

void web_player_features_free(web_player_features_t *web_player_features);

web_player_features_t *web_player_features_parseFromJSON(cJSON *web_player_featuresJSON);

cJSON *web_player_features_convertToJSON(web_player_features_t *web_player_features);

#endif /* _web_player_features_H_ */

