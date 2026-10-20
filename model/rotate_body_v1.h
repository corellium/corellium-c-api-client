/*
 * rotate_body_v1.h
 *
 * 
 */

#ifndef _rotate_body_v1_H_
#define _rotate_body_v1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct rotate_body_v1_t rotate_body_v1_t;


// Enum ORIENTATION for rotate_body_v1

typedef enum  { corellium_api_rotate_body_v1_ORIENTATION_NULL = 0, corellium_api_rotate_body_v1_ORIENTATION__1, corellium_api_rotate_body_v1_ORIENTATION__2, corellium_api_rotate_body_v1_ORIENTATION__3, corellium_api_rotate_body_v1_ORIENTATION__4 } corellium_api_rotate_body_v1_ORIENTATION_e;

char* rotate_body_v1_orientation_ToString(corellium_api_rotate_body_v1_ORIENTATION_e orientation);

corellium_api_rotate_body_v1_ORIENTATION_e rotate_body_v1_orientation_FromString(char* orientation);



typedef struct rotate_body_v1_t {
    double orientation; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} rotate_body_v1_t;

__attribute__((deprecated)) rotate_body_v1_t *rotate_body_v1_create(
    double orientation
);

void rotate_body_v1_free(rotate_body_v1_t *rotate_body_v1);

rotate_body_v1_t *rotate_body_v1_parseFromJSON(cJSON *rotate_body_v1JSON);

cJSON *rotate_body_v1_convertToJSON(rotate_body_v1_t *rotate_body_v1);

#endif /* _rotate_body_v1_H_ */

