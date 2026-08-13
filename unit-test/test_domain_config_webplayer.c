#ifndef domain_config_webplayer_TEST
#define domain_config_webplayer_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define domain_config_webplayer_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/domain_config_webplayer.h"
domain_config_webplayer_t* instantiate_domain_config_webplayer(int include_optional);



domain_config_webplayer_t* instantiate_domain_config_webplayer(int include_optional) {
  domain_config_webplayer_t* domain_config_webplayer = NULL;
  if (include_optional) {
    domain_config_webplayer = domain_config_webplayer_create(
      1,
      list_createList()
    );
  } else {
    domain_config_webplayer = domain_config_webplayer_create(
      1,
      list_createList()
    );
  }

  return domain_config_webplayer;
}


#ifdef domain_config_webplayer_MAIN

void test_domain_config_webplayer(int include_optional) {
    domain_config_webplayer_t* domain_config_webplayer_1 = instantiate_domain_config_webplayer(include_optional);

	cJSON* jsondomain_config_webplayer_1 = domain_config_webplayer_convertToJSON(domain_config_webplayer_1);
	printf("domain_config_webplayer :\n%s\n", cJSON_Print(jsondomain_config_webplayer_1));
	domain_config_webplayer_t* domain_config_webplayer_2 = domain_config_webplayer_parseFromJSON(jsondomain_config_webplayer_1);
	cJSON* jsondomain_config_webplayer_2 = domain_config_webplayer_convertToJSON(domain_config_webplayer_2);
	printf("repeating domain_config_webplayer:\n%s\n", cJSON_Print(jsondomain_config_webplayer_2));
}

int main() {
  test_domain_config_webplayer(1);
  test_domain_config_webplayer(0);

  printf("Hello world \n");
  return 0;
}

#endif // domain_config_webplayer_MAIN
#endif // domain_config_webplayer_TEST
