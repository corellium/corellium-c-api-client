#ifndef billing_line_item_TEST
#define billing_line_item_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define billing_line_item_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/billing_line_item.h"
billing_line_item_t* instantiate_billing_line_item(int include_optional);



billing_line_item_t* instantiate_billing_line_item(int include_optional) {
  billing_line_item_t* billing_line_item = NULL;
  if (include_optional) {
    billing_line_item = billing_line_item_create(
      "On",
      "iPhone 13 Pro on per hour",
      "iPhone 13 Pro",
      "my-device, OS version 17.5, OS build 21F79",
      6.25,
      8
    );
  } else {
    billing_line_item = billing_line_item_create(
      "On",
      "iPhone 13 Pro on per hour",
      "iPhone 13 Pro",
      "my-device, OS version 17.5, OS build 21F79",
      6.25,
      8
    );
  }

  return billing_line_item;
}


#ifdef billing_line_item_MAIN

void test_billing_line_item(int include_optional) {
    billing_line_item_t* billing_line_item_1 = instantiate_billing_line_item(include_optional);

	cJSON* jsonbilling_line_item_1 = billing_line_item_convertToJSON(billing_line_item_1);
	printf("billing_line_item :\n%s\n", cJSON_Print(jsonbilling_line_item_1));
	billing_line_item_t* billing_line_item_2 = billing_line_item_parseFromJSON(jsonbilling_line_item_1);
	cJSON* jsonbilling_line_item_2 = billing_line_item_convertToJSON(billing_line_item_2);
	printf("repeating billing_line_item:\n%s\n", cJSON_Print(jsonbilling_line_item_2));
}

int main() {
  test_billing_line_item(1);
  test_billing_line_item(0);

  printf("Hello world \n");
  return 0;
}

#endif // billing_line_item_MAIN
#endif // billing_line_item_TEST
