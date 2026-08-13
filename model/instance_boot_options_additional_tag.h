/*
 * instance_boot_options_additional_tag.h
 *
 * ### Instance Boot Option * kalloc: Enable kalloc/kfree trace access via GDB (Enterprise only) * gpu: Enable cloud GPU acceleration (Extra costs incurred, cloud only) * no-keyboard: Enable keyboard passthrough from web interface * nodevmode: Disable developer mode on iOS16 and greater * sep-cons-ext: Patch SEPOS to print debug messages to console * iboot-jailbreak: Patch iBoot to disable signature checks * llb-jailbreak: Patch LLB to disable signature checks * rom-jailbreak: Patch BootROM to disable signature checks
 */

#ifndef _instance_boot_options_additional_tag_H_
#define _instance_boot_options_additional_tag_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instance_boot_options_additional_tag_t instance_boot_options_additional_tag_t;


// Enum  for instance_boot_options_additional_tag

typedef enum { corellium_api_instance_boot_options_additional_tag__NULL = 0, corellium_api_instance_boot_options_additional_tag__kalloc, corellium_api_instance_boot_options_additional_tag__gpu, corellium_api_instance_boot_options_additional_tag__no_keyboard, corellium_api_instance_boot_options_additional_tag__nodevmode, corellium_api_instance_boot_options_additional_tag__sep_cons_ext, corellium_api_instance_boot_options_additional_tag__iboot_jailbreak, corellium_api_instance_boot_options_additional_tag__llb_jailbreak, corellium_api_instance_boot_options_additional_tag__rom_jailbreak } corellium_api_instance_boot_options_additional_tag__e;

char* instance_boot_options_additional_tag_instance_boot_options_additional_tag_ToString(corellium_api_instance_boot_options_additional_tag__e instance_boot_options_additional_tag);

corellium_api_instance_boot_options_additional_tag__e instance_boot_options_additional_tag_instance_boot_options_additional_tag_FromString(char* instance_boot_options_additional_tag);

cJSON *instance_boot_options_additional_tag_convertToJSON(corellium_api_instance_boot_options_additional_tag__e instance_boot_options_additional_tag);

corellium_api_instance_boot_options_additional_tag__e instance_boot_options_additional_tag_parseFromJSON(cJSON *instance_boot_options_additional_tagJSON);

#endif /* _instance_boot_options_additional_tag_H_ */

