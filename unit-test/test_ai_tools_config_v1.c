#ifndef ai_tools_config_v1_TEST
#define ai_tools_config_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ai_tools_config_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ai_tools_config_v1.h"
ai_tools_config_v1_t* instantiate_ai_tools_config_v1(int include_optional);



ai_tools_config_v1_t* instantiate_ai_tools_config_v1(int include_optional) {
  ai_tools_config_v1_t* ai_tools_config_v1 = NULL;
  if (include_optional) {
    ai_tools_config_v1 = ai_tools_config_v1_create(
      1
    );
  } else {
    ai_tools_config_v1 = ai_tools_config_v1_create(
      1
    );
  }

  return ai_tools_config_v1;
}


#ifdef ai_tools_config_v1_MAIN

void test_ai_tools_config_v1(int include_optional) {
    ai_tools_config_v1_t* ai_tools_config_v1_1 = instantiate_ai_tools_config_v1(include_optional);

	cJSON* jsonai_tools_config_v1_1 = ai_tools_config_v1_convertToJSON(ai_tools_config_v1_1);
	printf("ai_tools_config_v1 :\n%s\n", cJSON_Print(jsonai_tools_config_v1_1));
	ai_tools_config_v1_t* ai_tools_config_v1_2 = ai_tools_config_v1_parseFromJSON(jsonai_tools_config_v1_1);
	cJSON* jsonai_tools_config_v1_2 = ai_tools_config_v1_convertToJSON(ai_tools_config_v1_2);
	printf("repeating ai_tools_config_v1:\n%s\n", cJSON_Print(jsonai_tools_config_v1_2));
}

int main() {
  test_ai_tools_config_v1(1);
  test_ai_tools_config_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // ai_tools_config_v1_MAIN
#endif // ai_tools_config_v1_TEST
