/*
 * paginated_assessments.h
 *
 * 
 */

#ifndef _paginated_assessments_H_
#define _paginated_assessments_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct paginated_assessments_t paginated_assessments_t;

#include "assessment.h"



typedef struct paginated_assessments_t {
    double limit; //numeric
    double offset; //numeric
    double count; //numeric
    double total; //numeric
    list_t *results; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} paginated_assessments_t;

__attribute__((deprecated)) paginated_assessments_t *paginated_assessments_create(
    double limit,
    double offset,
    double count,
    double total,
    list_t *results
);

void paginated_assessments_free(paginated_assessments_t *paginated_assessments);

paginated_assessments_t *paginated_assessments_parseFromJSON(cJSON *paginated_assessmentsJSON);

cJSON *paginated_assessments_convertToJSON(paginated_assessments_t *paginated_assessments);

#endif /* _paginated_assessments_H_ */

