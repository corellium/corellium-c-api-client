#ifndef agent_remote_it_status_TEST
#define agent_remote_it_status_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define agent_remote_it_status_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/agent_remote_it_status.h"
agent_remote_it_status_t* instantiate_agent_remote_it_status(int include_optional);



agent_remote_it_status_t* instantiate_agent_remote_it_status(int include_optional) {
  agent_remote_it_status_t* agent_remote_it_status = NULL;
  if (include_optional) {
    agent_remote_it_status = agent_remote_it_status_create(
      corellium_api_agent_remote_it_status_REMOTEITSTATUS_unknown,
      "0"
    );
  } else {
    agent_remote_it_status = agent_remote_it_status_create(
      corellium_api_agent_remote_it_status_REMOTEITSTATUS_unknown,
      "0"
    );
  }

  return agent_remote_it_status;
}


#ifdef agent_remote_it_status_MAIN

void test_agent_remote_it_status(int include_optional) {
    agent_remote_it_status_t* agent_remote_it_status_1 = instantiate_agent_remote_it_status(include_optional);

	cJSON* jsonagent_remote_it_status_1 = agent_remote_it_status_convertToJSON(agent_remote_it_status_1);
	printf("agent_remote_it_status :\n%s\n", cJSON_Print(jsonagent_remote_it_status_1));
	agent_remote_it_status_t* agent_remote_it_status_2 = agent_remote_it_status_parseFromJSON(jsonagent_remote_it_status_1);
	cJSON* jsonagent_remote_it_status_2 = agent_remote_it_status_convertToJSON(agent_remote_it_status_2);
	printf("repeating agent_remote_it_status:\n%s\n", cJSON_Print(jsonagent_remote_it_status_2));
}

int main() {
  test_agent_remote_it_status(1);
  test_agent_remote_it_status(0);

  printf("Hello world \n");
  return 0;
}

#endif // agent_remote_it_status_MAIN
#endif // agent_remote_it_status_TEST
