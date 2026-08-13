#ifndef charm_tag_TEST
#define charm_tag_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define charm_tag_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/charm_tag.h"
charm_tag_t* instantiate_charm_tag(int include_optional);



charm_tag_t* instantiate_charm_tag(int include_optional) {
  charm_tag_t* charm_tag = NULL;
  if (include_optional) {
    charm_tag = charm_tag_create(
    );
  } else {
    charm_tag = charm_tag_create(
    );
  }

  return charm_tag;
}


#ifdef charm_tag_MAIN

void test_charm_tag(int include_optional) {
    charm_tag_t* charm_tag_1 = instantiate_charm_tag(include_optional);

	cJSON* jsoncharm_tag_1 = charm_tag_convertToJSON(charm_tag_1);
	printf("charm_tag :\n%s\n", cJSON_Print(jsoncharm_tag_1));
	charm_tag_t* charm_tag_2 = charm_tag_parseFromJSON(jsoncharm_tag_1);
	cJSON* jsoncharm_tag_2 = charm_tag_convertToJSON(charm_tag_2);
	printf("repeating charm_tag:\n%s\n", cJSON_Print(jsoncharm_tag_2));
}

int main() {
  test_charm_tag(1);
  test_charm_tag(0);

  printf("Hello world \n");
  return 0;
}

#endif // charm_tag_MAIN
#endif // charm_tag_TEST
