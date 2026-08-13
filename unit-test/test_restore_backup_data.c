#ifndef restore_backup_data_TEST
#define restore_backup_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define restore_backup_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/restore_backup_data.h"
restore_backup_data_t* instantiate_restore_backup_data(int include_optional);



restore_backup_data_t* instantiate_restore_backup_data(int include_optional) {
  restore_backup_data_t* restore_backup_data = NULL;
  if (include_optional) {
    restore_backup_data = restore_backup_data_create(
      "0"
    );
  } else {
    restore_backup_data = restore_backup_data_create(
      "0"
    );
  }

  return restore_backup_data;
}


#ifdef restore_backup_data_MAIN

void test_restore_backup_data(int include_optional) {
    restore_backup_data_t* restore_backup_data_1 = instantiate_restore_backup_data(include_optional);

	cJSON* jsonrestore_backup_data_1 = restore_backup_data_convertToJSON(restore_backup_data_1);
	printf("restore_backup_data :\n%s\n", cJSON_Print(jsonrestore_backup_data_1));
	restore_backup_data_t* restore_backup_data_2 = restore_backup_data_parseFromJSON(jsonrestore_backup_data_1);
	cJSON* jsonrestore_backup_data_2 = restore_backup_data_convertToJSON(restore_backup_data_2);
	printf("repeating restore_backup_data:\n%s\n", cJSON_Print(jsonrestore_backup_data_2));
}

int main() {
  test_restore_backup_data(1);
  test_restore_backup_data(0);

  printf("Hello world \n");
  return 0;
}

#endif // restore_backup_data_MAIN
#endif // restore_backup_data_TEST
