/*
 * domain_software.h
 *
 * 
 */

#ifndef _domain_software_H_
#define _domain_software_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct domain_software_t domain_software_t;




typedef struct domain_software_t {
    char *image_id; // string
    char *flavor; // string
    char *description; // string
    char *model; // string
    char *platform; // string
    int has_product_image; //boolean
    char *os_version; // string
    char *os_build; // string
    char *filename; // string
    double size; //numeric
    char *release_date; //date time
    char *upload_date; //date time
    char *download_url; // string

    int _library_owned; // Is the library responsible for freeing this object?
} domain_software_t;

__attribute__((deprecated)) domain_software_t *domain_software_create(
    char *image_id,
    char *flavor,
    char *description,
    char *model,
    char *platform,
    int has_product_image,
    char *os_version,
    char *os_build,
    char *filename,
    double size,
    char *release_date,
    char *upload_date,
    char *download_url
);

void domain_software_free(domain_software_t *domain_software);

domain_software_t *domain_software_parseFromJSON(cJSON *domain_softwareJSON);

cJSON *domain_software_convertToJSON(domain_software_t *domain_software);

#endif /* _domain_software_H_ */

