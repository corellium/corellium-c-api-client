/*
 * interconnect_protocol.h
 *
 * The protocol used by the interconnect.
 */

#ifndef _interconnect_protocol_H_
#define _interconnect_protocol_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct interconnect_protocol_t interconnect_protocol_t;


// Enum  for interconnect_protocol

typedef enum { corellium_api_interconnect_protocol__NULL = 0, corellium_api_interconnect_protocol__can, corellium_api_interconnect_protocol__uart, corellium_api_interconnect_protocol__i2c, corellium_api_interconnect_protocol__spi, corellium_api_interconnect_protocol__gpio, corellium_api_interconnect_protocol__usbh, corellium_api_interconnect_protocol__eth } corellium_api_interconnect_protocol__e;

char* interconnect_protocol_interconnect_protocol_ToString(corellium_api_interconnect_protocol__e interconnect_protocol);

corellium_api_interconnect_protocol__e interconnect_protocol_interconnect_protocol_FromString(char* interconnect_protocol);

cJSON *interconnect_protocol_convertToJSON(corellium_api_interconnect_protocol__e interconnect_protocol);

corellium_api_interconnect_protocol__e interconnect_protocol_parseFromJSON(cJSON *interconnect_protocolJSON);

#endif /* _interconnect_protocol_H_ */

