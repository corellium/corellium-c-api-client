/*
 * assessment_wordlist.h
 *
 * Wordlist used during the assessment, or null if none.
 */

#ifndef _assessment_wordlist_H_
#define _assessment_wordlist_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct assessment_wordlist_t assessment_wordlist_t;




typedef struct assessment_wordlist_t {
    char *id; // string
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} assessment_wordlist_t;

__attribute__((deprecated)) assessment_wordlist_t *assessment_wordlist_create(
    char *id,
    char *name
);

void assessment_wordlist_free(assessment_wordlist_t *assessment_wordlist);

assessment_wordlist_t *assessment_wordlist_parseFromJSON(cJSON *assessment_wordlistJSON);

cJSON *assessment_wordlist_convertToJSON(assessment_wordlist_t *assessment_wordlist);

#endif /* _assessment_wordlist_H_ */

