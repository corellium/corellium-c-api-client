#ifndef create_image_body_TEST
#define create_image_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_image_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_image_body.h"
create_image_body_t* instantiate_create_image_body(int include_optional);



create_image_body_t* instantiate_create_image_body(int include_optional) {
  create_image_body_t* create_image_body = NULL;
  if (include_optional) {
    create_image_body = create_image_body_create(
      corellium_api_create_image_body__fwbinary,
      corellium_api_create_image_body__plain,
      false,
      "firmware.ipsw",
      "/data/uploads/firmware.ipsw",
      "1c41b1bc-4f53-48a8-b690-ad30611e1960",
      "f7f9832a-f824-416f-a5ea-4adfe34754b5",
      instantiate_binary_t("blah", 5)
    );
  } else {
    create_image_body = create_image_body_create(
      corellium_api_create_image_body__fwbinary,
      corellium_api_create_image_body__plain,
      false,
      "firmware.ipsw",
      "/data/uploads/firmware.ipsw",
      "1c41b1bc-4f53-48a8-b690-ad30611e1960",
      "f7f9832a-f824-416f-a5ea-4adfe34754b5",
      instantiate_binary_t("blah", 5)
    );
  }

  return create_image_body;
}


#ifdef create_image_body_MAIN

void test_create_image_body(int include_optional) {
    create_image_body_t* create_image_body_1 = instantiate_create_image_body(include_optional);

	cJSON* jsoncreate_image_body_1 = create_image_body_convertToJSON(create_image_body_1);
	printf("create_image_body :\n%s\n", cJSON_Print(jsoncreate_image_body_1));
	create_image_body_t* create_image_body_2 = create_image_body_parseFromJSON(jsoncreate_image_body_1);
	cJSON* jsoncreate_image_body_2 = create_image_body_convertToJSON(create_image_body_2);
	printf("repeating create_image_body:\n%s\n", cJSON_Print(jsoncreate_image_body_2));
}

int main() {
  test_create_image_body(1);
  test_create_image_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_image_body_MAIN
#endif // create_image_body_TEST
