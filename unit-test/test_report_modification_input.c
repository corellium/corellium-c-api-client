#ifndef report_modification_input_TEST
#define report_modification_input_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define report_modification_input_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/report_modification_input.h"
report_modification_input_t* instantiate_report_modification_input(int include_optional);



report_modification_input_t* instantiate_report_modification_input(int include_optional) {
  report_modification_input_t* report_modification_input = NULL;
  if (include_optional) {
    report_modification_input = report_modification_input_create(
      "masvs-storage-2-android-8",
      "severity",
      1,
      "low"
    );
  } else {
    report_modification_input = report_modification_input_create(
      "masvs-storage-2-android-8",
      "severity",
      1,
      "low"
    );
  }

  return report_modification_input;
}


#ifdef report_modification_input_MAIN

void test_report_modification_input(int include_optional) {
    report_modification_input_t* report_modification_input_1 = instantiate_report_modification_input(include_optional);

	cJSON* jsonreport_modification_input_1 = report_modification_input_convertToJSON(report_modification_input_1);
	printf("report_modification_input :\n%s\n", cJSON_Print(jsonreport_modification_input_1));
	report_modification_input_t* report_modification_input_2 = report_modification_input_parseFromJSON(jsonreport_modification_input_1);
	cJSON* jsonreport_modification_input_2 = report_modification_input_convertToJSON(report_modification_input_2);
	printf("repeating report_modification_input:\n%s\n", cJSON_Print(jsonreport_modification_input_2));
}

int main() {
  test_report_modification_input(1);
  test_report_modification_input(0);

  printf("Hello world \n");
  return 0;
}

#endif // report_modification_input_MAIN
#endif // report_modification_input_TEST
