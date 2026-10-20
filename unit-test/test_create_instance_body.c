#ifndef create_instance_body_TEST
#define create_instance_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_instance_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_instance_body.h"
create_instance_body_t* instantiate_create_instance_body(int include_optional);

#include "test_volume_options.c"
#include "test_instance_boot_options.c"


create_instance_body_t* instantiate_create_instance_body(int include_optional) {
  create_instance_body_t* create_instance_body = NULL;
  if (include_optional) {
    create_instance_body = create_instance_body_create(
      "c67af9c0-26cd-4233-9782-436c842b60db",
      "<redacted>",
      "My iPhone 13 Pro",
      "<redacted>",
      "iphone13p",
      "1c41b1bc-4f53-48a8-b690-ad30611e1960",
      "17.5",
      "21F79",
      ["jailbroken"],
      "https://example.com/firmware.ipsw",
      "https://example.com/firmware.ipsw",
      true,
      "02:00:00:aa:bb:cc",
      true,
       // false, not to have infinite recursion
      instantiate_volume_options(0),
      "c67af9c0-26cd-4233-9782-436c842b60db",
       // false, not to have infinite recursion
      instantiate_instance_boot_options(0),
      true,
      [{"charmd":"enabled"},{"strace-file-count":2},{"supportsVideoFile":true}]
    );
  } else {
    create_instance_body = create_instance_body_create(
      "c67af9c0-26cd-4233-9782-436c842b60db",
      "<redacted>",
      "My iPhone 13 Pro",
      "<redacted>",
      "iphone13p",
      "1c41b1bc-4f53-48a8-b690-ad30611e1960",
      "17.5",
      "21F79",
      ["jailbroken"],
      "https://example.com/firmware.ipsw",
      "https://example.com/firmware.ipsw",
      true,
      "02:00:00:aa:bb:cc",
      true,
      NULL,
      "c67af9c0-26cd-4233-9782-436c842b60db",
      NULL,
      true,
      [{"charmd":"enabled"},{"strace-file-count":2},{"supportsVideoFile":true}]
    );
  }

  return create_instance_body;
}


#ifdef create_instance_body_MAIN

void test_create_instance_body(int include_optional) {
    create_instance_body_t* create_instance_body_1 = instantiate_create_instance_body(include_optional);

	cJSON* jsoncreate_instance_body_1 = create_instance_body_convertToJSON(create_instance_body_1);
	printf("create_instance_body :\n%s\n", cJSON_Print(jsoncreate_instance_body_1));
	create_instance_body_t* create_instance_body_2 = create_instance_body_parseFromJSON(jsoncreate_instance_body_1);
	cJSON* jsoncreate_instance_body_2 = create_instance_body_convertToJSON(create_instance_body_2);
	printf("repeating create_instance_body:\n%s\n", cJSON_Print(jsoncreate_instance_body_2));
}

int main() {
  test_create_instance_body(1);
  test_create_instance_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_instance_body_MAIN
#endif // create_instance_body_TEST
