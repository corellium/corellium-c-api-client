#ifndef agent_frida_process_list_TEST
#define agent_frida_process_list_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define agent_frida_process_list_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/agent_frida_process_list.h"
agent_frida_process_list_t* instantiate_agent_frida_process_list(int include_optional);

#include "test_agent_frida_process_list_attached.c"


agent_frida_process_list_t* instantiate_agent_frida_process_list(int include_optional) {
  agent_frida_process_list_t* agent_frida_process_list = NULL;
  if (include_optional) {
    agent_frida_process_list = agent_frida_process_list_create(
      true,
      0,
      "  PID  Name
  1234  com.corellium.cafe
",
       // false, not to have infinite recursion
      instantiate_agent_frida_process_list_attached(0)
    );
  } else {
    agent_frida_process_list = agent_frida_process_list_create(
      true,
      0,
      "  PID  Name
  1234  com.corellium.cafe
",
      NULL
    );
  }

  return agent_frida_process_list;
}


#ifdef agent_frida_process_list_MAIN

void test_agent_frida_process_list(int include_optional) {
    agent_frida_process_list_t* agent_frida_process_list_1 = instantiate_agent_frida_process_list(include_optional);

	cJSON* jsonagent_frida_process_list_1 = agent_frida_process_list_convertToJSON(agent_frida_process_list_1);
	printf("agent_frida_process_list :\n%s\n", cJSON_Print(jsonagent_frida_process_list_1));
	agent_frida_process_list_t* agent_frida_process_list_2 = agent_frida_process_list_parseFromJSON(jsonagent_frida_process_list_1);
	cJSON* jsonagent_frida_process_list_2 = agent_frida_process_list_convertToJSON(agent_frida_process_list_2);
	printf("repeating agent_frida_process_list:\n%s\n", cJSON_Print(jsonagent_frida_process_list_2));
}

int main() {
  test_agent_frida_process_list(1);
  test_agent_frida_process_list(0);

  printf("Hello world \n");
  return 0;
}

#endif // agent_frida_process_list_MAIN
#endif // agent_frida_process_list_TEST
