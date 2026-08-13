#ifndef cloud_notification_list_TEST
#define cloud_notification_list_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define cloud_notification_list_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/cloud_notification_list.h"
cloud_notification_list_t* instantiate_cloud_notification_list(int include_optional);



cloud_notification_list_t* instantiate_cloud_notification_list(int include_optional) {
  cloud_notification_list_t* cloud_notification_list = NULL;
  if (include_optional) {
    cloud_notification_list = cloud_notification_list_create(
      list_createList(),
      0,
      0,
      0,
      0,
      1
    );
  } else {
    cloud_notification_list = cloud_notification_list_create(
      list_createList(),
      0,
      0,
      0,
      0,
      1
    );
  }

  return cloud_notification_list;
}


#ifdef cloud_notification_list_MAIN

void test_cloud_notification_list(int include_optional) {
    cloud_notification_list_t* cloud_notification_list_1 = instantiate_cloud_notification_list(include_optional);

	cJSON* jsoncloud_notification_list_1 = cloud_notification_list_convertToJSON(cloud_notification_list_1);
	printf("cloud_notification_list :\n%s\n", cJSON_Print(jsoncloud_notification_list_1));
	cloud_notification_list_t* cloud_notification_list_2 = cloud_notification_list_parseFromJSON(jsoncloud_notification_list_1);
	cJSON* jsoncloud_notification_list_2 = cloud_notification_list_convertToJSON(cloud_notification_list_2);
	printf("repeating cloud_notification_list:\n%s\n", cJSON_Print(jsoncloud_notification_list_2));
}

int main() {
  test_cloud_notification_list(1);
  test_cloud_notification_list(0);

  printf("Hello world \n");
  return 0;
}

#endif // cloud_notification_list_MAIN
#endif // cloud_notification_list_TEST
