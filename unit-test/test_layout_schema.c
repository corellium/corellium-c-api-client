#ifndef layout_schema_TEST
#define layout_schema_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define layout_schema_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/layout_schema.h"
layout_schema_t* instantiate_layout_schema(int include_optional);



layout_schema_t* instantiate_layout_schema(int include_optional) {
  layout_schema_t* layout_schema = NULL;
  if (include_optional) {
    layout_schema = layout_schema_create(
      0,
      0,
      6,
      2,
      "0",
      0,
      0,
      4096
    );
  } else {
    layout_schema = layout_schema_create(
      0,
      0,
      6,
      2,
      "0",
      0,
      0,
      4096
    );
  }

  return layout_schema;
}


#ifdef layout_schema_MAIN

void test_layout_schema(int include_optional) {
    layout_schema_t* layout_schema_1 = instantiate_layout_schema(include_optional);

	cJSON* jsonlayout_schema_1 = layout_schema_convertToJSON(layout_schema_1);
	printf("layout_schema :\n%s\n", cJSON_Print(jsonlayout_schema_1));
	layout_schema_t* layout_schema_2 = layout_schema_parseFromJSON(jsonlayout_schema_1);
	cJSON* jsonlayout_schema_2 = layout_schema_convertToJSON(layout_schema_2);
	printf("repeating layout_schema:\n%s\n", cJSON_Print(jsonlayout_schema_2));
}

int main() {
  test_layout_schema(1);
  test_layout_schema(0);

  printf("Hello world \n");
  return 0;
}

#endif // layout_schema_MAIN
#endif // layout_schema_TEST
