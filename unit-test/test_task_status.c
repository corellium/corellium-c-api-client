#ifndef task_status_TEST
#define task_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define task_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/task_status.h"
task_status_t* instantiate_task_status(int include_optional);



task_status_t* instantiate_task_status(int include_optional) {
  task_status_t* task_status = NULL;
  if (include_optional) {
    task_status = task_status_create(
    );
  } else {
    task_status = task_status_create(
    );
  }

  return task_status;
}


#ifdef task_status_MAIN

void test_task_status(int include_optional) {
    task_status_t* task_status_1 = instantiate_task_status(include_optional);

	cJSON* jsontask_status_1 = task_status_convertToJSON(task_status_1);
	printf("task_status :\n%s\n", cJSON_Print(jsontask_status_1));
	task_status_t* task_status_2 = task_status_parseFromJSON(jsontask_status_1);
	cJSON* jsontask_status_2 = task_status_convertToJSON(task_status_2);
	printf("repeating task_status:\n%s\n", cJSON_Print(jsontask_status_2));
}

int main() {
  test_task_status(1);
  test_task_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // task_status_MAIN
#endif // task_status_TEST
