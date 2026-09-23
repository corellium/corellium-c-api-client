#ifndef login_result_domain_snapshot_sharing_permissions_TEST
#define login_result_domain_snapshot_sharing_permissions_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define login_result_domain_snapshot_sharing_permissions_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/login_result_domain_snapshot_sharing_permissions.h"
login_result_domain_snapshot_sharing_permissions_t* instantiate_login_result_domain_snapshot_sharing_permissions(int include_optional);



login_result_domain_snapshot_sharing_permissions_t* instantiate_login_result_domain_snapshot_sharing_permissions(int include_optional) {
  login_result_domain_snapshot_sharing_permissions_t* login_result_domain_snapshot_sharing_permissions = NULL;
  if (include_optional) {
    login_result_domain_snapshot_sharing_permissions = login_result_domain_snapshot_sharing_permissions_create(
      false,
      true,
      true,
      true,
      true,
      true
    );
  } else {
    login_result_domain_snapshot_sharing_permissions = login_result_domain_snapshot_sharing_permissions_create(
      false,
      true,
      true,
      true,
      true,
      true
    );
  }

  return login_result_domain_snapshot_sharing_permissions;
}


#ifdef login_result_domain_snapshot_sharing_permissions_MAIN

void test_login_result_domain_snapshot_sharing_permissions(int include_optional) {
    login_result_domain_snapshot_sharing_permissions_t* login_result_domain_snapshot_sharing_permissions_1 = instantiate_login_result_domain_snapshot_sharing_permissions(include_optional);

	cJSON* jsonlogin_result_domain_snapshot_sharing_permissions_1 = login_result_domain_snapshot_sharing_permissions_convertToJSON(login_result_domain_snapshot_sharing_permissions_1);
	printf("login_result_domain_snapshot_sharing_permissions :\n%s\n", cJSON_Print(jsonlogin_result_domain_snapshot_sharing_permissions_1));
	login_result_domain_snapshot_sharing_permissions_t* login_result_domain_snapshot_sharing_permissions_2 = login_result_domain_snapshot_sharing_permissions_parseFromJSON(jsonlogin_result_domain_snapshot_sharing_permissions_1);
	cJSON* jsonlogin_result_domain_snapshot_sharing_permissions_2 = login_result_domain_snapshot_sharing_permissions_convertToJSON(login_result_domain_snapshot_sharing_permissions_2);
	printf("repeating login_result_domain_snapshot_sharing_permissions:\n%s\n", cJSON_Print(jsonlogin_result_domain_snapshot_sharing_permissions_2));
}

int main() {
  test_login_result_domain_snapshot_sharing_permissions(1);
  test_login_result_domain_snapshot_sharing_permissions(0);

  printf("Hello world \n");
  return 0;
}

#endif // login_result_domain_snapshot_sharing_permissions_MAIN
#endif // login_result_domain_snapshot_sharing_permissions_TEST
