#ifndef agent_system_install_open_gapps_body_TEST
#define agent_system_install_open_gapps_body_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define agent_system_install_open_gapps_body_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/agent_system_install_open_gapps_body.h"
agent_system_install_open_gapps_body_t* instantiate_agent_system_install_open_gapps_body(int include_optional);



agent_system_install_open_gapps_body_t* instantiate_agent_system_install_open_gapps_body(int include_optional) {
  agent_system_install_open_gapps_body_t* agent_system_install_open_gapps_body = NULL;
  if (include_optional) {
    agent_system_install_open_gapps_body = agent_system_install_open_gapps_body_create(
      "http://downloads.sourceforge.net/project/opengapps/arm64/20220119/open_gapps-arm64-11.0-pico-20220119.zip",
      "58398bf7628f38ef07eaeb3abe26f3ebf0474f4d5ecdac0852bd5de3c15cc828",
      "google/flame/flame:11/RP1A.200720.009/6720564:user/release-keys__2020-09-05"
    );
  } else {
    agent_system_install_open_gapps_body = agent_system_install_open_gapps_body_create(
      "http://downloads.sourceforge.net/project/opengapps/arm64/20220119/open_gapps-arm64-11.0-pico-20220119.zip",
      "58398bf7628f38ef07eaeb3abe26f3ebf0474f4d5ecdac0852bd5de3c15cc828",
      "google/flame/flame:11/RP1A.200720.009/6720564:user/release-keys__2020-09-05"
    );
  }

  return agent_system_install_open_gapps_body;
}


#ifdef agent_system_install_open_gapps_body_MAIN

void test_agent_system_install_open_gapps_body(int include_optional) {
    agent_system_install_open_gapps_body_t* agent_system_install_open_gapps_body_1 = instantiate_agent_system_install_open_gapps_body(include_optional);

	cJSON* jsonagent_system_install_open_gapps_body_1 = agent_system_install_open_gapps_body_convertToJSON(agent_system_install_open_gapps_body_1);
	printf("agent_system_install_open_gapps_body :\n%s\n", cJSON_Print(jsonagent_system_install_open_gapps_body_1));
	agent_system_install_open_gapps_body_t* agent_system_install_open_gapps_body_2 = agent_system_install_open_gapps_body_parseFromJSON(jsonagent_system_install_open_gapps_body_1);
	cJSON* jsonagent_system_install_open_gapps_body_2 = agent_system_install_open_gapps_body_convertToJSON(agent_system_install_open_gapps_body_2);
	printf("repeating agent_system_install_open_gapps_body:\n%s\n", cJSON_Print(jsonagent_system_install_open_gapps_body_2));
}

int main() {
  test_agent_system_install_open_gapps_body(1);
  test_agent_system_install_open_gapps_body(0);

  printf("Hello world \n");
  return 0;
}

#endif // agent_system_install_open_gapps_body_MAIN
#endif // agent_system_install_open_gapps_body_TEST
