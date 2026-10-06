#ifndef instance_TEST
#define instance_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define instance_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/instance.h"
instance_t* instantiate_instance(int include_optional);

#include "test_instance_restore_status.c"
#include "test_instance_read_only_status.c"
#include "test_instance_boot_options.c"
#include "test_instance_services.c"
#include "test_instance_agent_state.c"
#include "test_instance_netmon_state.c"
#include "test_instance_netdump_state.c"
#include "test_instance_trace_state.c"
#include "test_instance_hyper_trace_state.c"
#include "test_created_by.c"
#include "test_instance_uefi_bootloader.c"


instance_t* instantiate_instance(int include_optional) {
  instance_t* instance = NULL;
  if (include_optional) {
    instance = instance_create(
      "f7f9832a-f824-416f-a5ea-4adfe34754b5",
      "My iPhone 13 Pro",
      "<redacted>",
      "iphone13p",
      "iPhone 13 Pro",
      "ios",
      "1c41b1bc-4f53-48a8-b690-ad30611e1960",
      "acme-corp",
      corellium_api_instance__on,
      "2026-03-16T08:22:19Z",
      "2026-03-16T08:22:19Z",
      "snapshot",
      "none",
      "Failed to start instance: insufficient capacity",
       // false, not to have infinite recursion
      instantiate_instance_restore_status(0),
       // false, not to have infinite recursion
      instantiate_instance_read_only_status(0),
       // false, not to have infinite recursion
      instantiate_instance_boot_options(0),
      "10.0.10.5",
      "192.168.1.50",
      "02:00:00:aa:bb:cc",
      "192.168.1.51",
      "5555",
      "2222",
      "5039",
      "5040",
      "2000",
      "2001",
      "2002",
      "2003",
      "27042",
      "2004",
      "2005",
      list_createList(),
      list_createList(),
       // false, not to have infinite recursion
      instantiate_instance_services(0),
      false,
      "2026-03-14T09:12:47Z",
      "d63ap",
      "https://example.com/firmware.ipsw",
      "17.5",
      "21F79",
       // false, not to have infinite recursion
      instantiate_instance_agent_state(0),
       // false, not to have infinite recursion
      instantiate_instance_netmon_state(0),
       // false, not to have infinite recursion
      instantiate_instance_netdump_state(0),
       // false, not to have infinite recursion
      instantiate_instance_trace_state(0),
       // false, not to have infinite recursion
      instantiate_instance_hyper_trace_state(0),
      "8080",
      false,
      ["jailbroken"],
       // false, not to have infinite recursion
      instantiate_created_by(0),
       // false, not to have infinite recursion
      instantiate_instance_uefi_bootloader(0),
      1,
      true,
      true,
      true
    );
  } else {
    instance = instance_create(
      "f7f9832a-f824-416f-a5ea-4adfe34754b5",
      "My iPhone 13 Pro",
      "<redacted>",
      "iphone13p",
      "iPhone 13 Pro",
      "ios",
      "1c41b1bc-4f53-48a8-b690-ad30611e1960",
      "acme-corp",
      corellium_api_instance__on,
      "2026-03-16T08:22:19Z",
      "2026-03-16T08:22:19Z",
      "snapshot",
      "none",
      "Failed to start instance: insufficient capacity",
      NULL,
      NULL,
      NULL,
      "10.0.10.5",
      "192.168.1.50",
      "02:00:00:aa:bb:cc",
      "192.168.1.51",
      "5555",
      "2222",
      "5039",
      "5040",
      "2000",
      "2001",
      "2002",
      "2003",
      "27042",
      "2004",
      "2005",
      list_createList(),
      list_createList(),
      NULL,
      false,
      "2026-03-14T09:12:47Z",
      "d63ap",
      "https://example.com/firmware.ipsw",
      "17.5",
      "21F79",
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      "8080",
      false,
      ["jailbroken"],
      NULL,
      NULL,
      1,
      true,
      true,
      true
    );
  }

  return instance;
}


#ifdef instance_MAIN

void test_instance(int include_optional) {
    instance_t* instance_1 = instantiate_instance(include_optional);

	cJSON* jsoninstance_1 = instance_convertToJSON(instance_1);
	printf("instance :\n%s\n", cJSON_Print(jsoninstance_1));
	instance_t* instance_2 = instance_parseFromJSON(jsoninstance_1);
	cJSON* jsoninstance_2 = instance_convertToJSON(instance_2);
	printf("repeating instance:\n%s\n", cJSON_Print(jsoninstance_2));
}

int main() {
  test_instance(1);
  test_instance(0);

  printf("Hello world \n");
  return 0;
}

#endif // instance_MAIN
#endif // instance_TEST
