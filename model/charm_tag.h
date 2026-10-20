/*
 * charm_tag.h
 *
 * A valid charm boot tag.
 */

#ifndef _charm_tag_H_
#define _charm_tag_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct charm_tag_t charm_tag_t;


// Enum  for charm_tag

typedef enum { corellium_api_charm_tag__NULL = 0, corellium_api_charm_tag__kalloc, corellium_api_charm_tag__gpu, corellium_api_charm_tag__no_keyboard, corellium_api_charm_tag__nodevmode, corellium_api_charm_tag__sep_cons_ext, corellium_api_charm_tag__iboot_jailbreak, corellium_api_charm_tag__llb_jailbreak, corellium_api_charm_tag__rom_jailbreak, corellium_api_charm_tag__noappaslr, corellium_api_charm_tag__nodyldaslr, corellium_api_charm_tag__objdetect } corellium_api_charm_tag__e;

char* charm_tag_charm_tag_ToString(corellium_api_charm_tag__e charm_tag);

corellium_api_charm_tag__e charm_tag_charm_tag_FromString(char* charm_tag);

cJSON *charm_tag_convertToJSON(corellium_api_charm_tag__e charm_tag);

corellium_api_charm_tag__e charm_tag_parseFromJSON(cJSON *charm_tagJSON);

#endif /* _charm_tag_H_ */

