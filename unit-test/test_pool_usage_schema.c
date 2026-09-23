#ifndef pool_usage_schema_TEST
#define pool_usage_schema_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define pool_usage_schema_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/pool_usage_schema.h"
pool_usage_schema_t* instantiate_pool_usage_schema(int include_optional);



pool_usage_schema_t* instantiate_pool_usage_schema(int include_optional) {
  pool_usage_schema_t* pool_usage_schema = NULL;
  if (include_optional) {
    pool_usage_schema = pool_usage_schema_create(
      1024,
      4096,
      3072,
      37
    );
  } else {
    pool_usage_schema = pool_usage_schema_create(
      1024,
      4096,
      3072,
      37
    );
  }

  return pool_usage_schema;
}


#ifdef pool_usage_schema_MAIN

void test_pool_usage_schema(int include_optional) {
    pool_usage_schema_t* pool_usage_schema_1 = instantiate_pool_usage_schema(include_optional);

	cJSON* jsonpool_usage_schema_1 = pool_usage_schema_convertToJSON(pool_usage_schema_1);
	printf("pool_usage_schema :\n%s\n", cJSON_Print(jsonpool_usage_schema_1));
	pool_usage_schema_t* pool_usage_schema_2 = pool_usage_schema_parseFromJSON(jsonpool_usage_schema_1);
	cJSON* jsonpool_usage_schema_2 = pool_usage_schema_convertToJSON(pool_usage_schema_2);
	printf("repeating pool_usage_schema:\n%s\n", cJSON_Print(jsonpool_usage_schema_2));
}

int main() {
  test_pool_usage_schema(1);
  test_pool_usage_schema(0);

  printf("Hello world \n");
  return 0;
}

#endif // pool_usage_schema_MAIN
#endif // pool_usage_schema_TEST
