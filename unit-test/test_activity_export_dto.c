#ifndef activity_export_dto_TEST
#define activity_export_dto_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define activity_export_dto_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/activity_export_dto.h"
activity_export_dto_t* instantiate_activity_export_dto(int include_optional);



activity_export_dto_t* instantiate_activity_export_dto(int include_optional) {
  activity_export_dto_t* activity_export_dto = NULL;
  if (include_optional) {
    activity_export_dto = activity_export_dto_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    activity_export_dto = activity_export_dto_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return activity_export_dto;
}


#ifdef activity_export_dto_MAIN

void test_activity_export_dto(int include_optional) {
    activity_export_dto_t* activity_export_dto_1 = instantiate_activity_export_dto(include_optional);

	cJSON* jsonactivity_export_dto_1 = activity_export_dto_convertToJSON(activity_export_dto_1);
	printf("activity_export_dto :\n%s\n", cJSON_Print(jsonactivity_export_dto_1));
	activity_export_dto_t* activity_export_dto_2 = activity_export_dto_parseFromJSON(jsonactivity_export_dto_1);
	cJSON* jsonactivity_export_dto_2 = activity_export_dto_convertToJSON(activity_export_dto_2);
	printf("repeating activity_export_dto:\n%s\n", cJSON_Print(jsonactivity_export_dto_2));
}

int main() {
  test_activity_export_dto(1);
  test_activity_export_dto(0);

  printf("Hello world \n");
  return 0;
}

#endif // activity_export_dto_MAIN
#endif // activity_export_dto_TEST
