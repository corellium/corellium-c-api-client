#ifndef service_endpoint_schema_TEST
#define service_endpoint_schema_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define service_endpoint_schema_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/service_endpoint_schema.h"
service_endpoint_schema_t* instantiate_service_endpoint_schema(int include_optional);



service_endpoint_schema_t* instantiate_service_endpoint_schema(int include_optional) {
  service_endpoint_schema_t* service_endpoint_schema = NULL;
  if (include_optional) {
    service_endpoint_schema = service_endpoint_schema_create(
      "0",
      "0",
      "0",
      list_createList()
    );
  } else {
    service_endpoint_schema = service_endpoint_schema_create(
      "0",
      "0",
      "0",
      list_createList()
    );
  }

  return service_endpoint_schema;
}


#ifdef service_endpoint_schema_MAIN

void test_service_endpoint_schema(int include_optional) {
    service_endpoint_schema_t* service_endpoint_schema_1 = instantiate_service_endpoint_schema(include_optional);

	cJSON* jsonservice_endpoint_schema_1 = service_endpoint_schema_convertToJSON(service_endpoint_schema_1);
	printf("service_endpoint_schema :\n%s\n", cJSON_Print(jsonservice_endpoint_schema_1));
	service_endpoint_schema_t* service_endpoint_schema_2 = service_endpoint_schema_parseFromJSON(jsonservice_endpoint_schema_1);
	cJSON* jsonservice_endpoint_schema_2 = service_endpoint_schema_convertToJSON(service_endpoint_schema_2);
	printf("repeating service_endpoint_schema:\n%s\n", cJSON_Print(jsonservice_endpoint_schema_2));
}

int main() {
  test_service_endpoint_schema(1);
  test_service_endpoint_schema(0);

  printf("Hello world \n");
  return 0;
}

#endif // service_endpoint_schema_MAIN
#endif // service_endpoint_schema_TEST
