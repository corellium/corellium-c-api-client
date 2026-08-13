#ifndef agent_error_v1_TEST
#define agent_error_v1_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define agent_error_v1_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/agent_error_v1.h"
agent_error_v1_t* instantiate_agent_error_v1(int include_optional);



agent_error_v1_t* instantiate_agent_error_v1(int include_optional) {
  agent_error_v1_t* agent_error_v1 = NULL;
  if (include_optional) {
    agent_error_v1 = agent_error_v1_create(
      "0",
      corellium_api_agent_error_v1_ERRORID_AgentError,
      0
    );
  } else {
    agent_error_v1 = agent_error_v1_create(
      "0",
      corellium_api_agent_error_v1_ERRORID_AgentError,
      0
    );
  }

  return agent_error_v1;
}


#ifdef agent_error_v1_MAIN

void test_agent_error_v1(int include_optional) {
    agent_error_v1_t* agent_error_v1_1 = instantiate_agent_error_v1(include_optional);

	cJSON* jsonagent_error_v1_1 = agent_error_v1_convertToJSON(agent_error_v1_1);
	printf("agent_error_v1 :\n%s\n", cJSON_Print(jsonagent_error_v1_1));
	agent_error_v1_t* agent_error_v1_2 = agent_error_v1_parseFromJSON(jsonagent_error_v1_1);
	cJSON* jsonagent_error_v1_2 = agent_error_v1_convertToJSON(agent_error_v1_2);
	printf("repeating agent_error_v1:\n%s\n", cJSON_Print(jsonagent_error_v1_2));
}

int main() {
  test_agent_error_v1(1);
  test_agent_error_v1(0);

  printf("Hello world \n");
  return 0;
}

#endif // agent_error_v1_MAIN
#endif // agent_error_v1_TEST
