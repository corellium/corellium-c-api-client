#ifndef agent_system_get_prop_response_TEST
#define agent_system_get_prop_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define agent_system_get_prop_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/agent_system_get_prop_response.h"
agent_system_get_prop_response_t* instantiate_agent_system_get_prop_response(int include_optional);



agent_system_get_prop_response_t* instantiate_agent_system_get_prop_response(int include_optional) {
  agent_system_get_prop_response_t* agent_system_get_prop_response = NULL;
  if (include_optional) {
    agent_system_get_prop_response = agent_system_get_prop_response_create(
      7,
      true,
      "33"
    );
  } else {
    agent_system_get_prop_response = agent_system_get_prop_response_create(
      7,
      true,
      "33"
    );
  }

  return agent_system_get_prop_response;
}


#ifdef agent_system_get_prop_response_MAIN

void test_agent_system_get_prop_response(int include_optional) {
    agent_system_get_prop_response_t* agent_system_get_prop_response_1 = instantiate_agent_system_get_prop_response(include_optional);

	cJSON* jsonagent_system_get_prop_response_1 = agent_system_get_prop_response_convertToJSON(agent_system_get_prop_response_1);
	printf("agent_system_get_prop_response :\n%s\n", cJSON_Print(jsonagent_system_get_prop_response_1));
	agent_system_get_prop_response_t* agent_system_get_prop_response_2 = agent_system_get_prop_response_parseFromJSON(jsonagent_system_get_prop_response_1);
	cJSON* jsonagent_system_get_prop_response_2 = agent_system_get_prop_response_convertToJSON(agent_system_get_prop_response_2);
	printf("repeating agent_system_get_prop_response:\n%s\n", cJSON_Print(jsonagent_system_get_prop_response_2));
}

int main() {
  test_agent_system_get_prop_response(1);
  test_agent_system_get_prop_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // agent_system_get_prop_response_MAIN
#endif // agent_system_get_prop_response_TEST
