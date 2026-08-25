#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "interconnect_protocol.h"


char* interconnect_protocol_interconnect_protocol_ToString(corellium_api_interconnect_protocol__e interconnect_protocol) {
    char *interconnect_protocolArray[] =  { "NULL", "can", "uart", "i2c", "spi", "gpio", "usbh", "eth" };
    return interconnect_protocolArray[interconnect_protocol];
}

corellium_api_interconnect_protocol__e interconnect_protocol_interconnect_protocol_FromString(char* interconnect_protocol) {
    int stringToReturn = 0;
    char *interconnect_protocolArray[] =  { "NULL", "can", "uart", "i2c", "spi", "gpio", "usbh", "eth" };
    size_t sizeofArray = sizeof(interconnect_protocolArray) / sizeof(interconnect_protocolArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(interconnect_protocol, interconnect_protocolArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *interconnect_protocol_convertToJSON(corellium_api_interconnect_protocol__e interconnect_protocol) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "interconnect_protocol", interconnect_protocol_interconnect_protocol_ToString(interconnect_protocol)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

corellium_api_interconnect_protocol__e interconnect_protocol_parseFromJSON(cJSON *interconnect_protocolJSON) {
    if(!cJSON_IsString(interconnect_protocolJSON) || (interconnect_protocolJSON->valuestring == NULL)) {
        return 0;
    }
    return interconnect_protocol_interconnect_protocol_FromString(interconnect_protocolJSON->valuestring);
}
