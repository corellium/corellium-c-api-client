#ifndef matrix_error_TEST
#define matrix_error_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define matrix_error_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/matrix_error.h"
matrix_error_t* instantiate_matrix_error(int include_optional);



matrix_error_t* instantiate_matrix_error(int include_optional) {
  matrix_error_t* matrix_error = NULL;
  if (include_optional) {
    matrix_error = matrix_error_create(
      "0"
    );
  } else {
    matrix_error = matrix_error_create(
      "0"
    );
  }

  return matrix_error;
}


#ifdef matrix_error_MAIN

void test_matrix_error(int include_optional) {
    matrix_error_t* matrix_error_1 = instantiate_matrix_error(include_optional);

	cJSON* jsonmatrix_error_1 = matrix_error_convertToJSON(matrix_error_1);
	printf("matrix_error :\n%s\n", cJSON_Print(jsonmatrix_error_1));
	matrix_error_t* matrix_error_2 = matrix_error_parseFromJSON(jsonmatrix_error_1);
	cJSON* jsonmatrix_error_2 = matrix_error_convertToJSON(matrix_error_2);
	printf("repeating matrix_error:\n%s\n", cJSON_Print(jsonmatrix_error_2));
}

int main() {
  test_matrix_error(1);
  test_matrix_error(0);

  printf("Hello world \n");
  return 0;
}

#endif // matrix_error_MAIN
#endif // matrix_error_TEST
