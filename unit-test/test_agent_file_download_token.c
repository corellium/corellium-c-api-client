#ifndef agent_file_download_token_TEST
#define agent_file_download_token_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define agent_file_download_token_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/agent_file_download_token.h"
agent_file_download_token_t* instantiate_agent_file_download_token(int include_optional);



agent_file_download_token_t* instantiate_agent_file_download_token(int include_optional) {
  agent_file_download_token_t* agent_file_download_token = NULL;
  if (include_optional) {
    agent_file_download_token = agent_file_download_token_create(
      "a1b2c3d4e5f6a7b8c9d0e1f2a3b4c5d6"
    );
  } else {
    agent_file_download_token = agent_file_download_token_create(
      "a1b2c3d4e5f6a7b8c9d0e1f2a3b4c5d6"
    );
  }

  return agent_file_download_token;
}


#ifdef agent_file_download_token_MAIN

void test_agent_file_download_token(int include_optional) {
    agent_file_download_token_t* agent_file_download_token_1 = instantiate_agent_file_download_token(include_optional);

	cJSON* jsonagent_file_download_token_1 = agent_file_download_token_convertToJSON(agent_file_download_token_1);
	printf("agent_file_download_token :\n%s\n", cJSON_Print(jsonagent_file_download_token_1));
	agent_file_download_token_t* agent_file_download_token_2 = agent_file_download_token_parseFromJSON(jsonagent_file_download_token_1);
	cJSON* jsonagent_file_download_token_2 = agent_file_download_token_convertToJSON(agent_file_download_token_2);
	printf("repeating agent_file_download_token:\n%s\n", cJSON_Print(jsonagent_file_download_token_2));
}

int main() {
  test_agent_file_download_token(1);
  test_agent_file_download_token(0);

  printf("Hello world \n");
  return 0;
}

#endif // agent_file_download_token_MAIN
#endif // agent_file_download_token_TEST
