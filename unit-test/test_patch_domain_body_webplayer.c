#ifndef patch_domain_body_webplayer_TEST
#define patch_domain_body_webplayer_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define patch_domain_body_webplayer_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/patch_domain_body_webplayer.h"
patch_domain_body_webplayer_t* instantiate_patch_domain_body_webplayer(int include_optional);



patch_domain_body_webplayer_t* instantiate_patch_domain_body_webplayer(int include_optional) {
  patch_domain_body_webplayer_t* patch_domain_body_webplayer = NULL;
  if (include_optional) {
    patch_domain_body_webplayer = patch_domain_body_webplayer_create(
      list_createList()
    );
  } else {
    patch_domain_body_webplayer = patch_domain_body_webplayer_create(
      list_createList()
    );
  }

  return patch_domain_body_webplayer;
}


#ifdef patch_domain_body_webplayer_MAIN

void test_patch_domain_body_webplayer(int include_optional) {
    patch_domain_body_webplayer_t* patch_domain_body_webplayer_1 = instantiate_patch_domain_body_webplayer(include_optional);

	cJSON* jsonpatch_domain_body_webplayer_1 = patch_domain_body_webplayer_convertToJSON(patch_domain_body_webplayer_1);
	printf("patch_domain_body_webplayer :\n%s\n", cJSON_Print(jsonpatch_domain_body_webplayer_1));
	patch_domain_body_webplayer_t* patch_domain_body_webplayer_2 = patch_domain_body_webplayer_parseFromJSON(jsonpatch_domain_body_webplayer_1);
	cJSON* jsonpatch_domain_body_webplayer_2 = patch_domain_body_webplayer_convertToJSON(patch_domain_body_webplayer_2);
	printf("repeating patch_domain_body_webplayer:\n%s\n", cJSON_Print(jsonpatch_domain_body_webplayer_2));
}

int main() {
  test_patch_domain_body_webplayer(1);
  test_patch_domain_body_webplayer(0);

  printf("Hello world \n");
  return 0;
}

#endif // patch_domain_body_webplayer_MAIN
#endif // patch_domain_body_webplayer_TEST
