/*
 * bit.h
 *
 * Bit value
 */

#ifndef _bit_H_
#define _bit_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct bit_t bit_t;


// Enum  for bit

typedef enum { corellium_api_bit__NULL = 0, corellium_api_bit___0, corellium_api_bit___1 } corellium_api_bit__e;

char* bit_bit_ToString(corellium_api_bit__e bit);

corellium_api_bit__e bit_bit_FromString(char* bit);

cJSON *bit_convertToJSON(corellium_api_bit__e bit);

corellium_api_bit__e bit_parseFromJSON(cJSON *bitJSON);

#endif /* _bit_H_ */

