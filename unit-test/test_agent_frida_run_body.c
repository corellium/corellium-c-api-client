#ifndef agent_frida_run_body_TEST
#define agent_frida_run_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define agent_frida_run_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/agent_frida_run_body.h"
agent_frida_run_body_t* instantiate_agent_frida_run_body(int include_optional);



agent_frida_run_body_t* instantiate_agent_frida_run_body(int include_optional) {
  agent_frida_run_body_t* agent_frida_run_body = NULL;
  if (include_optional) {
    agent_frida_run_body = agent_frida_run_body_create(
      "1234",
      "com.corellium.cafe"
    );
  } else {
    agent_frida_run_body = agent_frida_run_body_create(
      "1234",
      "com.corellium.cafe"
    );
  }

  return agent_frida_run_body;
}


#ifdef agent_frida_run_body_MAIN

void test_agent_frida_run_body(int include_optional) {
    agent_frida_run_body_t* agent_frida_run_body_1 = instantiate_agent_frida_run_body(include_optional);

	cJSON* jsonagent_frida_run_body_1 = agent_frida_run_body_convertToJSON(agent_frida_run_body_1);
	printf("agent_frida_run_body :\n%s\n", cJSON_Print(jsonagent_frida_run_body_1));
	agent_frida_run_body_t* agent_frida_run_body_2 = agent_frida_run_body_parseFromJSON(jsonagent_frida_run_body_1);
	cJSON* jsonagent_frida_run_body_2 = agent_frida_run_body_convertToJSON(agent_frida_run_body_2);
	printf("repeating agent_frida_run_body:\n%s\n", cJSON_Print(jsonagent_frida_run_body_2));
}

int main() {
  test_agent_frida_run_body(1);
  test_agent_frida_run_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // agent_frida_run_body_MAIN
#endif // agent_frida_run_body_TEST
