#ifndef agent_frida_process_list_attached_TEST
#define agent_frida_process_list_attached_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define agent_frida_process_list_attached_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/agent_frida_process_list_attached.h"
agent_frida_process_list_attached_t* instantiate_agent_frida_process_list_attached(int include_optional);



agent_frida_process_list_attached_t* instantiate_agent_frida_process_list_attached(int include_optional) {
  agent_frida_process_list_attached_t* agent_frida_process_list_attached = NULL;
  if (include_optional) {
    agent_frida_process_list_attached = agent_frida_process_list_attached_create(
      "com.corellium.cafe",
      1234
    );
  } else {
    agent_frida_process_list_attached = agent_frida_process_list_attached_create(
      "com.corellium.cafe",
      1234
    );
  }

  return agent_frida_process_list_attached;
}


#ifdef agent_frida_process_list_attached_MAIN

void test_agent_frida_process_list_attached(int include_optional) {
    agent_frida_process_list_attached_t* agent_frida_process_list_attached_1 = instantiate_agent_frida_process_list_attached(include_optional);

	cJSON* jsonagent_frida_process_list_attached_1 = agent_frida_process_list_attached_convertToJSON(agent_frida_process_list_attached_1);
	printf("agent_frida_process_list_attached :\n%s\n", cJSON_Print(jsonagent_frida_process_list_attached_1));
	agent_frida_process_list_attached_t* agent_frida_process_list_attached_2 = agent_frida_process_list_attached_parseFromJSON(jsonagent_frida_process_list_attached_1);
	cJSON* jsonagent_frida_process_list_attached_2 = agent_frida_process_list_attached_convertToJSON(agent_frida_process_list_attached_2);
	printf("repeating agent_frida_process_list_attached:\n%s\n", cJSON_Print(jsonagent_frida_process_list_attached_2));
}

int main() {
  test_agent_frida_process_list_attached(1);
  test_agent_frida_process_list_attached(0);

  printf("Hello world \n");
  return 0;
}

#endif // agent_frida_process_list_attached_MAIN
#endif // agent_frida_process_list_attached_TEST
