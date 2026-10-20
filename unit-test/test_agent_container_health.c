#ifndef agent_container_health_TEST
#define agent_container_health_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define agent_container_health_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/agent_container_health.h"
agent_container_health_t* instantiate_agent_container_health(int include_optional);



agent_container_health_t* instantiate_agent_container_health(int include_optional) {
  agent_container_health_t* agent_container_health = NULL;
  if (include_optional) {
    agent_container_health = agent_container_health_create(
      true
    );
  } else {
    agent_container_health = agent_container_health_create(
      true
    );
  }

  return agent_container_health;
}


#ifdef agent_container_health_MAIN

void test_agent_container_health(int include_optional) {
    agent_container_health_t* agent_container_health_1 = instantiate_agent_container_health(include_optional);

	cJSON* jsonagent_container_health_1 = agent_container_health_convertToJSON(agent_container_health_1);
	printf("agent_container_health :\n%s\n", cJSON_Print(jsonagent_container_health_1));
	agent_container_health_t* agent_container_health_2 = agent_container_health_parseFromJSON(jsonagent_container_health_1);
	cJSON* jsonagent_container_health_2 = agent_container_health_convertToJSON(agent_container_health_2);
	printf("repeating agent_container_health:\n%s\n", cJSON_Print(jsonagent_container_health_2));
}

int main() {
  test_agent_container_health(1);
  test_agent_container_health(0);

  printf("Hello world \n");
  return 0;
}

#endif // agent_container_health_MAIN
#endif // agent_container_health_TEST
