/*
 * agent_file_archive_download_body.h
 *
 * 
 */

#ifndef _agent_file_archive_download_body_H_
#define _agent_file_archive_download_body_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct agent_file_archive_download_body_t agent_file_archive_download_body_t;




typedef struct agent_file_archive_download_body_t {
    list_t *paths; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} agent_file_archive_download_body_t;

__attribute__((deprecated)) agent_file_archive_download_body_t *agent_file_archive_download_body_create(
    list_t *paths
);

void agent_file_archive_download_body_free(agent_file_archive_download_body_t *agent_file_archive_download_body);

agent_file_archive_download_body_t *agent_file_archive_download_body_parseFromJSON(cJSON *agent_file_archive_download_bodyJSON);

cJSON *agent_file_archive_download_body_convertToJSON(agent_file_archive_download_body_t *agent_file_archive_download_body);

#endif /* _agent_file_archive_download_body_H_ */

