#ifndef agent_profile_list_response_TEST
#define agent_profile_list_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define agent_profile_list_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/agent_profile_list_response.h"
agent_profile_list_response_t* instantiate_agent_profile_list_response(int include_optional);



agent_profile_list_response_t* instantiate_agent_profile_list_response(int include_optional) {
  agent_profile_list_response_t* agent_profile_list_response = NULL;
  if (include_optional) {
    agent_profile_list_response = agent_profile_list_response_create(
      ["com.apple.wifi.managed"]
    );
  } else {
    agent_profile_list_response = agent_profile_list_response_create(
      ["com.apple.wifi.managed"]
    );
  }

  return agent_profile_list_response;
}


#ifdef agent_profile_list_response_MAIN

void test_agent_profile_list_response(int include_optional) {
    agent_profile_list_response_t* agent_profile_list_response_1 = instantiate_agent_profile_list_response(include_optional);

	cJSON* jsonagent_profile_list_response_1 = agent_profile_list_response_convertToJSON(agent_profile_list_response_1);
	printf("agent_profile_list_response :\n%s\n", cJSON_Print(jsonagent_profile_list_response_1));
	agent_profile_list_response_t* agent_profile_list_response_2 = agent_profile_list_response_parseFromJSON(jsonagent_profile_list_response_1);
	cJSON* jsonagent_profile_list_response_2 = agent_profile_list_response_convertToJSON(agent_profile_list_response_2);
	printf("repeating agent_profile_list_response:\n%s\n", cJSON_Print(jsonagent_profile_list_response_2));
}

int main() {
  test_agent_profile_list_response(1);
  test_agent_profile_list_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // agent_profile_list_response_MAIN
#endif // agent_profile_list_response_TEST
