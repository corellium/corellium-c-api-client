#ifndef maintenance_TEST
#define maintenance_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define maintenance_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/maintenance.h"
maintenance_t* instantiate_maintenance(int include_optional);



maintenance_t* instantiate_maintenance(int include_optional) {
  maintenance_t* maintenance = NULL;
  if (include_optional) {
    maintenance = maintenance_create(
      "0",
      "0"
    );
  } else {
    maintenance = maintenance_create(
      "0",
      "0"
    );
  }

  return maintenance;
}


#ifdef maintenance_MAIN

void test_maintenance(int include_optional) {
    maintenance_t* maintenance_1 = instantiate_maintenance(include_optional);

	cJSON* jsonmaintenance_1 = maintenance_convertToJSON(maintenance_1);
	printf("maintenance :\n%s\n", cJSON_Print(jsonmaintenance_1));
	maintenance_t* maintenance_2 = maintenance_parseFromJSON(jsonmaintenance_1);
	cJSON* jsonmaintenance_2 = maintenance_convertToJSON(maintenance_2);
	printf("repeating maintenance:\n%s\n", cJSON_Print(jsonmaintenance_2));
}

int main() {
  test_maintenance(1);
  test_maintenance(0);

  printf("Hello world \n");
  return 0;
}

#endif // maintenance_MAIN
#endif // maintenance_TEST
