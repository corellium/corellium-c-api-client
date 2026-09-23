#ifndef cloud_notification_item_TEST
#define cloud_notification_item_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cloud_notification_item_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cloud_notification_item.h"
cloud_notification_item_t* instantiate_cloud_notification_item(int include_optional);



cloud_notification_item_t* instantiate_cloud_notification_item(int include_optional) {
  cloud_notification_item_t* cloud_notification_item = NULL;
  if (include_optional) {
    cloud_notification_item = cloud_notification_item_create(
      "4f634e6a-189d-42eb-9bee-794df1f588d1",
      true,
      false,
      "project.1c41b1bc-4f53-48a8-b690-ad30611e1960",
      1,
      "Trial ended for acme.corellium.com",
      "The trial subscription for acme.corellium.com is now ended.",
      {"tags":["billing"]},
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z"
    );
  } else {
    cloud_notification_item = cloud_notification_item_create(
      "4f634e6a-189d-42eb-9bee-794df1f588d1",
      true,
      false,
      "project.1c41b1bc-4f53-48a8-b690-ad30611e1960",
      1,
      "Trial ended for acme.corellium.com",
      "The trial subscription for acme.corellium.com is now ended.",
      {"tags":["billing"]},
      "2026-03-14T09:12:47Z",
      "2026-03-17T11:41:05Z"
    );
  }

  return cloud_notification_item;
}


#ifdef cloud_notification_item_MAIN

void test_cloud_notification_item(int include_optional) {
    cloud_notification_item_t* cloud_notification_item_1 = instantiate_cloud_notification_item(include_optional);

	cJSON* jsoncloud_notification_item_1 = cloud_notification_item_convertToJSON(cloud_notification_item_1);
	printf("cloud_notification_item :\n%s\n", cJSON_Print(jsoncloud_notification_item_1));
	cloud_notification_item_t* cloud_notification_item_2 = cloud_notification_item_parseFromJSON(jsoncloud_notification_item_1);
	cJSON* jsoncloud_notification_item_2 = cloud_notification_item_convertToJSON(cloud_notification_item_2);
	printf("repeating cloud_notification_item:\n%s\n", cJSON_Print(jsoncloud_notification_item_2));
}

int main() {
  test_cloud_notification_item(1);
  test_cloud_notification_item(0);

  printf("Hello world \n");
  return 0;
}

#endif // cloud_notification_item_MAIN
#endif // cloud_notification_item_TEST
