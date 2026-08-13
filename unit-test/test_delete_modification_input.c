#ifndef delete_modification_input_TEST
#define delete_modification_input_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define delete_modification_input_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/delete_modification_input.h"
delete_modification_input_t* instantiate_delete_modification_input(int include_optional);



delete_modification_input_t* instantiate_delete_modification_input(int include_optional) {
  delete_modification_input_t* delete_modification_input = NULL;
  if (include_optional) {
    delete_modification_input = delete_modification_input_create(
      "masvs-storage-2-android-8",
      0
    );
  } else {
    delete_modification_input = delete_modification_input_create(
      "masvs-storage-2-android-8",
      0
    );
  }

  return delete_modification_input;
}


#ifdef delete_modification_input_MAIN

void test_delete_modification_input(int include_optional) {
    delete_modification_input_t* delete_modification_input_1 = instantiate_delete_modification_input(include_optional);

	cJSON* jsondelete_modification_input_1 = delete_modification_input_convertToJSON(delete_modification_input_1);
	printf("delete_modification_input :\n%s\n", cJSON_Print(jsondelete_modification_input_1));
	delete_modification_input_t* delete_modification_input_2 = delete_modification_input_parseFromJSON(jsondelete_modification_input_1);
	cJSON* jsondelete_modification_input_2 = delete_modification_input_convertToJSON(delete_modification_input_2);
	printf("repeating delete_modification_input:\n%s\n", cJSON_Print(jsondelete_modification_input_2));
}

int main() {
  test_delete_modification_input(1);
  test_delete_modification_input(0);

  printf("Hello world \n");
  return 0;
}

#endif // delete_modification_input_MAIN
#endif // delete_modification_input_TEST
