/*
 * assessment_format.h
 *
 * Report download format. Defaults to \&quot;html\&quot;.
 */

#ifndef _assessment_format_H_
#define _assessment_format_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct assessment_format_t assessment_format_t;


// Enum  for assessment_format

typedef enum { corellium_api_assessment_format__NULL = 0, corellium_api_assessment_format__json, corellium_api_assessment_format__html } corellium_api_assessment_format__e;

char* assessment_format_assessment_format_ToString(corellium_api_assessment_format__e assessment_format);

corellium_api_assessment_format__e assessment_format_assessment_format_FromString(char* assessment_format);

cJSON *assessment_format_convertToJSON(corellium_api_assessment_format__e assessment_format);

corellium_api_assessment_format__e assessment_format_parseFromJSON(cJSON *assessment_formatJSON);

#endif /* _assessment_format_H_ */

