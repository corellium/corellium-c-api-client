#ifndef aws_create_response_TEST
#define aws_create_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define aws_create_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/aws_create_response.h"
aws_create_response_t* instantiate_aws_create_response(int include_optional);



aws_create_response_t* instantiate_aws_create_response(int include_optional) {
  aws_create_response_t* aws_create_response = NULL;
  if (include_optional) {
    aws_create_response = aws_create_response_create(
      1,
      1
    );
  } else {
    aws_create_response = aws_create_response_create(
      1,
      1
    );
  }

  return aws_create_response;
}


#ifdef aws_create_response_MAIN

void test_aws_create_response(int include_optional) {
    aws_create_response_t* aws_create_response_1 = instantiate_aws_create_response(include_optional);

	cJSON* jsonaws_create_response_1 = aws_create_response_convertToJSON(aws_create_response_1);
	printf("aws_create_response :\n%s\n", cJSON_Print(jsonaws_create_response_1));
	aws_create_response_t* aws_create_response_2 = aws_create_response_parseFromJSON(jsonaws_create_response_1);
	cJSON* jsonaws_create_response_2 = aws_create_response_convertToJSON(aws_create_response_2);
	printf("repeating aws_create_response:\n%s\n", cJSON_Print(jsonaws_create_response_2));
}

int main() {
  test_aws_create_response(1);
  test_aws_create_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // aws_create_response_MAIN
#endif // aws_create_response_TEST
