#ifndef agent_container_list_TEST
#define agent_container_list_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define agent_container_list_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/agent_container_list.h"
agent_container_list_t* instantiate_agent_container_list(int include_optional);



agent_container_list_t* instantiate_agent_container_list(int include_optional) {
  agent_container_list_t* agent_container_list = NULL;
  if (include_optional) {
    agent_container_list = agent_container_list_create(
      list_createList()
    );
  } else {
    agent_container_list = agent_container_list_create(
      list_createList()
    );
  }

  return agent_container_list;
}


#ifdef agent_container_list_MAIN

void test_agent_container_list(int include_optional) {
    agent_container_list_t* agent_container_list_1 = instantiate_agent_container_list(include_optional);

	cJSON* jsonagent_container_list_1 = agent_container_list_convertToJSON(agent_container_list_1);
	printf("agent_container_list :\n%s\n", cJSON_Print(jsonagent_container_list_1));
	agent_container_list_t* agent_container_list_2 = agent_container_list_parseFromJSON(jsonagent_container_list_1);
	cJSON* jsonagent_container_list_2 = agent_container_list_convertToJSON(agent_container_list_2);
	printf("repeating agent_container_list:\n%s\n", cJSON_Print(jsonagent_container_list_2));
}

int main() {
  test_agent_container_list(1);
  test_agent_container_list(0);

  printf("Hello world \n");
  return 0;
}

#endif // agent_container_list_MAIN
#endif // agent_container_list_TEST
