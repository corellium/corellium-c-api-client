#ifndef agent_temp_file_response_TEST
#define agent_temp_file_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define agent_temp_file_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/agent_temp_file_response.h"
agent_temp_file_response_t* instantiate_agent_temp_file_response(int include_optional);



agent_temp_file_response_t* instantiate_agent_temp_file_response(int include_optional) {
  agent_temp_file_response_t* agent_temp_file_response = NULL;
  if (include_optional) {
    agent_temp_file_response = agent_temp_file_response_create(
      "0"
    );
  } else {
    agent_temp_file_response = agent_temp_file_response_create(
      "0"
    );
  }

  return agent_temp_file_response;
}


#ifdef agent_temp_file_response_MAIN

void test_agent_temp_file_response(int include_optional) {
    agent_temp_file_response_t* agent_temp_file_response_1 = instantiate_agent_temp_file_response(include_optional);

	cJSON* jsonagent_temp_file_response_1 = agent_temp_file_response_convertToJSON(agent_temp_file_response_1);
	printf("agent_temp_file_response :\n%s\n", cJSON_Print(jsonagent_temp_file_response_1));
	agent_temp_file_response_t* agent_temp_file_response_2 = agent_temp_file_response_parseFromJSON(jsonagent_temp_file_response_1);
	cJSON* jsonagent_temp_file_response_2 = agent_temp_file_response_convertToJSON(agent_temp_file_response_2);
	printf("repeating agent_temp_file_response:\n%s\n", cJSON_Print(jsonagent_temp_file_response_2));
}

int main() {
  test_agent_temp_file_response(1);
  test_agent_temp_file_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // agent_temp_file_response_MAIN
#endif // agent_temp_file_response_TEST
