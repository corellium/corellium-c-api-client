/*
 * plan.h
 *
 * Plan options
 */

#ifndef _plan_H_
#define _plan_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct plan_t plan_t;


// Enum LICENSETYPE for plan

typedef enum  { corellium_api_plan_LICENSETYPE_NULL = 0, corellium_api_plan_LICENSETYPE_premium, corellium_api_plan_LICENSETYPE_individual, corellium_api_plan_LICENSETYPE_standard, corellium_api_plan_LICENSETYPE_enterprise, corellium_api_plan_LICENSETYPE_individual_usage, corellium_api_plan_LICENSETYPE_enterprise_usage, corellium_api_plan_LICENSETYPE_unrestricted } corellium_api_plan_LICENSETYPE_e;

char* plan_license_type_ToString(corellium_api_plan_LICENSETYPE_e license_type);

corellium_api_plan_LICENSETYPE_e plan_license_type_FromString(char* license_type);



typedef struct plan_t {
    corellium_api_plan_LICENSETYPE_e license_type; //enum
    double cores; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} plan_t;

__attribute__((deprecated)) plan_t *plan_create(
    corellium_api_plan_LICENSETYPE_e license_type,
    double cores
);

void plan_free(plan_t *plan);

plan_t *plan_parseFromJSON(cJSON *planJSON);

cJSON *plan_convertToJSON(plan_t *plan);

#endif /* _plan_H_ */

