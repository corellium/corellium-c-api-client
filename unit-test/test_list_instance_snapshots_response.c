#ifndef list_instance_snapshots_response_TEST
#define list_instance_snapshots_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define list_instance_snapshots_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/list_instance_snapshots_response.h"
list_instance_snapshots_response_t* instantiate_list_instance_snapshots_response(int include_optional);



list_instance_snapshots_response_t* instantiate_list_instance_snapshots_response(int include_optional) {
  list_instance_snapshots_response_t* list_instance_snapshots_response = NULL;
  if (include_optional) {
    list_instance_snapshots_response = list_instance_snapshots_response_create(
      list_createList(),
      0,
      0,
      0,
      0,
      1
    );
  } else {
    list_instance_snapshots_response = list_instance_snapshots_response_create(
      list_createList(),
      0,
      0,
      0,
      0,
      1
    );
  }

  return list_instance_snapshots_response;
}


#ifdef list_instance_snapshots_response_MAIN

void test_list_instance_snapshots_response(int include_optional) {
    list_instance_snapshots_response_t* list_instance_snapshots_response_1 = instantiate_list_instance_snapshots_response(include_optional);

	cJSON* jsonlist_instance_snapshots_response_1 = list_instance_snapshots_response_convertToJSON(list_instance_snapshots_response_1);
	printf("list_instance_snapshots_response :\n%s\n", cJSON_Print(jsonlist_instance_snapshots_response_1));
	list_instance_snapshots_response_t* list_instance_snapshots_response_2 = list_instance_snapshots_response_parseFromJSON(jsonlist_instance_snapshots_response_1);
	cJSON* jsonlist_instance_snapshots_response_2 = list_instance_snapshots_response_convertToJSON(list_instance_snapshots_response_2);
	printf("repeating list_instance_snapshots_response:\n%s\n", cJSON_Print(jsonlist_instance_snapshots_response_2));
}

int main() {
  test_list_instance_snapshots_response(1);
  test_list_instance_snapshots_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // list_instance_snapshots_response_MAIN
#endif // list_instance_snapshots_response_TEST
