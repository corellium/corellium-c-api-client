#ifndef agent_icons_response_TEST
#define agent_icons_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define agent_icons_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/agent_icons_response.h"
agent_icons_response_t* instantiate_agent_icons_response(int include_optional);



agent_icons_response_t* instantiate_agent_icons_response(int include_optional) {
  agent_icons_response_t* agent_icons_response = NULL;
  if (include_optional) {
    agent_icons_response = agent_icons_response_create(
      1,
      0,
      0
    );
  } else {
    agent_icons_response = agent_icons_response_create(
      1,
      0,
      0
    );
  }

  return agent_icons_response;
}


#ifdef agent_icons_response_MAIN

void test_agent_icons_response(int include_optional) {
    agent_icons_response_t* agent_icons_response_1 = instantiate_agent_icons_response(include_optional);

	cJSON* jsonagent_icons_response_1 = agent_icons_response_convertToJSON(agent_icons_response_1);
	printf("agent_icons_response :\n%s\n", cJSON_Print(jsonagent_icons_response_1));
	agent_icons_response_t* agent_icons_response_2 = agent_icons_response_parseFromJSON(jsonagent_icons_response_1);
	cJSON* jsonagent_icons_response_2 = agent_icons_response_convertToJSON(agent_icons_response_2);
	printf("repeating agent_icons_response:\n%s\n", cJSON_Print(jsonagent_icons_response_2));
}

int main() {
  test_agent_icons_response(1);
  test_agent_icons_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // agent_icons_response_MAIN
#endif // agent_icons_response_TEST
