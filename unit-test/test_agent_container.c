#ifndef agent_container_TEST
#define agent_container_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define agent_container_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/agent_container.h"
agent_container_t* instantiate_agent_container(int include_optional);



agent_container_t* instantiate_agent_container(int include_optional) {
  agent_container_t* agent_container = NULL;
  if (include_optional) {
    agent_container = agent_container_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  } else {
    agent_container = agent_container_create(
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0",
      "0"
    );
  }

  return agent_container;
}


#ifdef agent_container_MAIN

void test_agent_container(int include_optional) {
    agent_container_t* agent_container_1 = instantiate_agent_container(include_optional);

	cJSON* jsonagent_container_1 = agent_container_convertToJSON(agent_container_1);
	printf("agent_container :\n%s\n", cJSON_Print(jsonagent_container_1));
	agent_container_t* agent_container_2 = agent_container_parseFromJSON(jsonagent_container_1);
	cJSON* jsonagent_container_2 = agent_container_convertToJSON(agent_container_2);
	printf("repeating agent_container:\n%s\n", cJSON_Print(jsonagent_container_2));
}

int main() {
  test_agent_container(1);
  test_agent_container(0);

  printf("Hello world \n");
  return 0;
}

#endif // agent_container_MAIN
#endif // agent_container_TEST
