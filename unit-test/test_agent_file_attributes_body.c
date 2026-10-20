#ifndef agent_file_attributes_body_TEST
#define agent_file_attributes_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define agent_file_attributes_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/agent_file_attributes_body.h"
agent_file_attributes_body_t* instantiate_agent_file_attributes_body(int include_optional);



agent_file_attributes_body_t* instantiate_agent_file_attributes_body(int include_optional) {
  agent_file_attributes_body_t* agent_file_attributes_body = NULL;
  if (include_optional) {
    agent_file_attributes_body = agent_file_attributes_body_create(
      "/var/tmp/renamed.log",
      420,
      501,
      501
    );
  } else {
    agent_file_attributes_body = agent_file_attributes_body_create(
      "/var/tmp/renamed.log",
      420,
      501,
      501
    );
  }

  return agent_file_attributes_body;
}


#ifdef agent_file_attributes_body_MAIN

void test_agent_file_attributes_body(int include_optional) {
    agent_file_attributes_body_t* agent_file_attributes_body_1 = instantiate_agent_file_attributes_body(include_optional);

	cJSON* jsonagent_file_attributes_body_1 = agent_file_attributes_body_convertToJSON(agent_file_attributes_body_1);
	printf("agent_file_attributes_body :\n%s\n", cJSON_Print(jsonagent_file_attributes_body_1));
	agent_file_attributes_body_t* agent_file_attributes_body_2 = agent_file_attributes_body_parseFromJSON(jsonagent_file_attributes_body_1);
	cJSON* jsonagent_file_attributes_body_2 = agent_file_attributes_body_convertToJSON(agent_file_attributes_body_2);
	printf("repeating agent_file_attributes_body:\n%s\n", cJSON_Print(jsonagent_file_attributes_body_2));
}

int main() {
  test_agent_file_attributes_body(1);
  test_agent_file_attributes_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // agent_file_attributes_body_MAIN
#endif // agent_file_attributes_body_TEST
