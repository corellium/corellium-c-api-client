/*
 * agent_file_download_token.h
 *
 * 
 */

#ifndef _agent_file_download_token_H_
#define _agent_file_download_token_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct agent_file_download_token_t agent_file_download_token_t;




typedef struct agent_file_download_token_t {
    char *token; // string

    int _library_owned; // Is the library responsible for freeing this object?
} agent_file_download_token_t;

__attribute__((deprecated)) agent_file_download_token_t *agent_file_download_token_create(
    char *token
);

void agent_file_download_token_free(agent_file_download_token_t *agent_file_download_token);

agent_file_download_token_t *agent_file_download_token_parseFromJSON(cJSON *agent_file_download_tokenJSON);

cJSON *agent_file_download_token_convertToJSON(agent_file_download_token_t *agent_file_download_token);

#endif /* _agent_file_download_token_H_ */

