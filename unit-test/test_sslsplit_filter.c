#ifndef sslsplit_filter_TEST
#define sslsplit_filter_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define sslsplit_filter_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/sslsplit_filter.h"
sslsplit_filter_t* instantiate_sslsplit_filter(int include_optional);



sslsplit_filter_t* instantiate_sslsplit_filter(int include_optional) {
  sslsplit_filter_t* sslsplit_filter = NULL;
  if (include_optional) {
    sslsplit_filter = sslsplit_filter_create(
      1
    );
  } else {
    sslsplit_filter = sslsplit_filter_create(
      1
    );
  }

  return sslsplit_filter;
}


#ifdef sslsplit_filter_MAIN

void test_sslsplit_filter(int include_optional) {
    sslsplit_filter_t* sslsplit_filter_1 = instantiate_sslsplit_filter(include_optional);

	cJSON* jsonsslsplit_filter_1 = sslsplit_filter_convertToJSON(sslsplit_filter_1);
	printf("sslsplit_filter :\n%s\n", cJSON_Print(jsonsslsplit_filter_1));
	sslsplit_filter_t* sslsplit_filter_2 = sslsplit_filter_parseFromJSON(jsonsslsplit_filter_1);
	cJSON* jsonsslsplit_filter_2 = sslsplit_filter_convertToJSON(sslsplit_filter_2);
	printf("repeating sslsplit_filter:\n%s\n", cJSON_Print(jsonsslsplit_filter_2));
}

int main() {
  test_sslsplit_filter(1);
  test_sslsplit_filter(0);

  printf("Hello world \n");
  return 0;
}

#endif // sslsplit_filter_MAIN
#endif // sslsplit_filter_TEST
