#ifndef restore_backup_body_TEST
#define restore_backup_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define restore_backup_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/restore_backup_body.h"
restore_backup_body_t* instantiate_restore_backup_body(int include_optional);



restore_backup_body_t* instantiate_restore_backup_body(int include_optional) {
  restore_backup_body_t* restore_backup_body = NULL;
  if (include_optional) {
    restore_backup_body = restore_backup_body_create(
      "0"
    );
  } else {
    restore_backup_body = restore_backup_body_create(
      "0"
    );
  }

  return restore_backup_body;
}


#ifdef restore_backup_body_MAIN

void test_restore_backup_body(int include_optional) {
    restore_backup_body_t* restore_backup_body_1 = instantiate_restore_backup_body(include_optional);

	cJSON* jsonrestore_backup_body_1 = restore_backup_body_convertToJSON(restore_backup_body_1);
	printf("restore_backup_body :\n%s\n", cJSON_Print(jsonrestore_backup_body_1));
	restore_backup_body_t* restore_backup_body_2 = restore_backup_body_parseFromJSON(jsonrestore_backup_body_1);
	cJSON* jsonrestore_backup_body_2 = restore_backup_body_convertToJSON(restore_backup_body_2);
	printf("repeating restore_backup_body:\n%s\n", cJSON_Print(jsonrestore_backup_body_2));
}

int main() {
  test_restore_backup_body(1);
  test_restore_backup_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // restore_backup_body_MAIN
#endif // restore_backup_body_TEST
