#ifndef report_modification_result_TEST
#define report_modification_result_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define report_modification_result_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/report_modification_result.h"
report_modification_result_t* instantiate_report_modification_result(int include_optional);



report_modification_result_t* instantiate_report_modification_result(int include_optional) {
  report_modification_result_t* report_modification_result = NULL;
  if (include_optional) {
    report_modification_result = report_modification_result_create(
      "0",
      "0",
      corellium_api_report_modification_result_STATUS_inserted,
      "0"
    );
  } else {
    report_modification_result = report_modification_result_create(
      "0",
      "0",
      corellium_api_report_modification_result_STATUS_inserted,
      "0"
    );
  }

  return report_modification_result;
}


#ifdef report_modification_result_MAIN

void test_report_modification_result(int include_optional) {
    report_modification_result_t* report_modification_result_1 = instantiate_report_modification_result(include_optional);

	cJSON* jsonreport_modification_result_1 = report_modification_result_convertToJSON(report_modification_result_1);
	printf("report_modification_result :\n%s\n", cJSON_Print(jsonreport_modification_result_1));
	report_modification_result_t* report_modification_result_2 = report_modification_result_parseFromJSON(jsonreport_modification_result_1);
	cJSON* jsonreport_modification_result_2 = report_modification_result_convertToJSON(report_modification_result_2);
	printf("repeating report_modification_result:\n%s\n", cJSON_Print(jsonreport_modification_result_2));
}

int main() {
  test_report_modification_result(1);
  test_report_modification_result(0);

  printf("Hello world \n");
  return 0;
}

#endif // report_modification_result_MAIN
#endif // report_modification_result_TEST
