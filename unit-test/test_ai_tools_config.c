#ifndef ai_tools_config_TEST
#define ai_tools_config_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ai_tools_config_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ai_tools_config.h"
ai_tools_config_t* instantiate_ai_tools_config(int include_optional);



ai_tools_config_t* instantiate_ai_tools_config(int include_optional) {
  ai_tools_config_t* ai_tools_config = NULL;
  if (include_optional) {
    ai_tools_config = ai_tools_config_create(
      true
    );
  } else {
    ai_tools_config = ai_tools_config_create(
      true
    );
  }

  return ai_tools_config;
}


#ifdef ai_tools_config_MAIN

void test_ai_tools_config(int include_optional) {
    ai_tools_config_t* ai_tools_config_1 = instantiate_ai_tools_config(include_optional);

	cJSON* jsonai_tools_config_1 = ai_tools_config_convertToJSON(ai_tools_config_1);
	printf("ai_tools_config :\n%s\n", cJSON_Print(jsonai_tools_config_1));
	ai_tools_config_t* ai_tools_config_2 = ai_tools_config_parseFromJSON(jsonai_tools_config_1);
	cJSON* jsonai_tools_config_2 = ai_tools_config_convertToJSON(ai_tools_config_2);
	printf("repeating ai_tools_config:\n%s\n", cJSON_Print(jsonai_tools_config_2));
}

int main() {
  test_ai_tools_config(1);
  test_ai_tools_config(0);

  printf("Hello world \n");
  return 0;
}

#endif // ai_tools_config_MAIN
#endif // ai_tools_config_TEST
