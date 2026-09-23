#ifndef agent_system_result_TEST
#define agent_system_result_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define agent_system_result_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/agent_system_result.h"
agent_system_result_t* instantiate_agent_system_result(int include_optional);



agent_system_result_t* instantiate_agent_system_result(int include_optional) {
  agent_system_result_t* agent_system_result = NULL;
  if (include_optional) {
    agent_system_result = agent_system_result_create(
      7,
      true
    );
  } else {
    agent_system_result = agent_system_result_create(
      7,
      true
    );
  }

  return agent_system_result;
}


#ifdef agent_system_result_MAIN

void test_agent_system_result(int include_optional) {
    agent_system_result_t* agent_system_result_1 = instantiate_agent_system_result(include_optional);

	cJSON* jsonagent_system_result_1 = agent_system_result_convertToJSON(agent_system_result_1);
	printf("agent_system_result :\n%s\n", cJSON_Print(jsonagent_system_result_1));
	agent_system_result_t* agent_system_result_2 = agent_system_result_parseFromJSON(jsonagent_system_result_1);
	cJSON* jsonagent_system_result_2 = agent_system_result_convertToJSON(agent_system_result_2);
	printf("repeating agent_system_result:\n%s\n", cJSON_Print(jsonagent_system_result_2));
}

int main() {
  test_agent_system_result(1);
  test_agent_system_result(0);

  printf("Hello world \n");
  return 0;
}

#endif // agent_system_result_MAIN
#endif // agent_system_result_TEST
