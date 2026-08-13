#ifndef agent_frida_response_TEST
#define agent_frida_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define agent_frida_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/agent_frida_response.h"
agent_frida_response_t* instantiate_agent_frida_response(int include_optional);



agent_frida_response_t* instantiate_agent_frida_response(int include_optional) {
  agent_frida_response_t* agent_frida_response = NULL;
  if (include_optional) {
    agent_frida_response = agent_frida_response_create(
      0,
      1
    );
  } else {
    agent_frida_response = agent_frida_response_create(
      0,
      1
    );
  }

  return agent_frida_response;
}


#ifdef agent_frida_response_MAIN

void test_agent_frida_response(int include_optional) {
    agent_frida_response_t* agent_frida_response_1 = instantiate_agent_frida_response(include_optional);

	cJSON* jsonagent_frida_response_1 = agent_frida_response_convertToJSON(agent_frida_response_1);
	printf("agent_frida_response :\n%s\n", cJSON_Print(jsonagent_frida_response_1));
	agent_frida_response_t* agent_frida_response_2 = agent_frida_response_parseFromJSON(jsonagent_frida_response_1);
	cJSON* jsonagent_frida_response_2 = agent_frida_response_convertToJSON(agent_frida_response_2);
	printf("repeating agent_frida_response:\n%s\n", cJSON_Print(jsonagent_frida_response_2));
}

int main() {
  test_agent_frida_response(1);
  test_agent_frida_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // agent_frida_response_MAIN
#endif // agent_frida_response_TEST
