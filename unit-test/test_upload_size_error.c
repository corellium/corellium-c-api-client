#ifndef upload_size_error_TEST
#define upload_size_error_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define upload_size_error_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/upload_size_error.h"
upload_size_error_t* instantiate_upload_size_error(int include_optional);



upload_size_error_t* instantiate_upload_size_error(int include_optional) {
  upload_size_error_t* upload_size_error = NULL;
  if (include_optional) {
    upload_size_error = upload_size_error_create(
      "0",
      corellium_api_upload_size_error_ERRORID_UploadSizeError,
      "0"
    );
  } else {
    upload_size_error = upload_size_error_create(
      "0",
      corellium_api_upload_size_error_ERRORID_UploadSizeError,
      "0"
    );
  }

  return upload_size_error;
}


#ifdef upload_size_error_MAIN

void test_upload_size_error(int include_optional) {
    upload_size_error_t* upload_size_error_1 = instantiate_upload_size_error(include_optional);

	cJSON* jsonupload_size_error_1 = upload_size_error_convertToJSON(upload_size_error_1);
	printf("upload_size_error :\n%s\n", cJSON_Print(jsonupload_size_error_1));
	upload_size_error_t* upload_size_error_2 = upload_size_error_parseFromJSON(jsonupload_size_error_1);
	cJSON* jsonupload_size_error_2 = upload_size_error_convertToJSON(upload_size_error_2);
	printf("repeating upload_size_error:\n%s\n", cJSON_Print(jsonupload_size_error_2));
}

int main() {
  test_upload_size_error(1);
  test_upload_size_error(0);

  printf("Hello world \n");
  return 0;
}

#endif // upload_size_error_MAIN
#endif // upload_size_error_TEST
