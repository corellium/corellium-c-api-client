#ifndef proxy_config_TEST
#define proxy_config_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define proxy_config_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/proxy_config.h"
proxy_config_t* instantiate_proxy_config(int include_optional);



proxy_config_t* instantiate_proxy_config(int include_optional) {
  proxy_config_t* proxy_config = NULL;
  if (include_optional) {
    proxy_config = proxy_config_create(
      1.337,
      1,
      1,
      1.337
    );
  } else {
    proxy_config = proxy_config_create(
      1.337,
      1,
      1,
      1.337
    );
  }

  return proxy_config;
}


#ifdef proxy_config_MAIN

void test_proxy_config(int include_optional) {
    proxy_config_t* proxy_config_1 = instantiate_proxy_config(include_optional);

	cJSON* jsonproxy_config_1 = proxy_config_convertToJSON(proxy_config_1);
	printf("proxy_config :\n%s\n", cJSON_Print(jsonproxy_config_1));
	proxy_config_t* proxy_config_2 = proxy_config_parseFromJSON(jsonproxy_config_1);
	cJSON* jsonproxy_config_2 = proxy_config_convertToJSON(proxy_config_2);
	printf("repeating proxy_config:\n%s\n", cJSON_Print(jsonproxy_config_2));
}

int main() {
  test_proxy_config(1);
  test_proxy_config(0);

  printf("Hello world \n");
  return 0;
}

#endif // proxy_config_MAIN
#endif // proxy_config_TEST
