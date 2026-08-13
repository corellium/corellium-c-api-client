#ifndef web_player_features_TEST
#define web_player_features_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define web_player_features_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/web_player_features.h"
web_player_features_t* instantiate_web_player_features(int include_optional);



web_player_features_t* instantiate_web_player_features(int include_optional) {
  web_player_features_t* web_player_features = NULL;
  if (include_optional) {
    web_player_features = web_player_features_create(
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1
    );
  } else {
    web_player_features = web_player_features_create(
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1
    );
  }

  return web_player_features;
}


#ifdef web_player_features_MAIN

void test_web_player_features(int include_optional) {
    web_player_features_t* web_player_features_1 = instantiate_web_player_features(include_optional);

	cJSON* jsonweb_player_features_1 = web_player_features_convertToJSON(web_player_features_1);
	printf("web_player_features :\n%s\n", cJSON_Print(jsonweb_player_features_1));
	web_player_features_t* web_player_features_2 = web_player_features_parseFromJSON(jsonweb_player_features_1);
	cJSON* jsonweb_player_features_2 = web_player_features_convertToJSON(web_player_features_2);
	printf("repeating web_player_features:\n%s\n", cJSON_Print(jsonweb_player_features_2));
}

int main() {
  test_web_player_features(1);
  test_web_player_features(0);

  printf("Hello world \n");
  return 0;
}

#endif // web_player_features_MAIN
#endif // web_player_features_TEST
