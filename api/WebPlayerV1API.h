#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/api_error_v1.h"
#include "../model/user_error_v1.h"
#include "../model/web_player_create_session_request.h"
#include "../model/web_player_session_v1.h"


// Retrieve the list of allowed domains for all Webplayer sessions
//
void
WebPlayerV1API_v1WebPlayerAllowedDomains(apiClient_t *apiClient);


// Create a new Webplayer Session
//
web_player_session_v1_t*
WebPlayerV1API_v1WebPlayerCreateSession(apiClient_t *apiClient, web_player_create_session_request_t *web_player_create_session_request);


// Tear down a Webplayer Session
//
list_t*
WebPlayerV1API_v1WebPlayerDestroySession(apiClient_t *apiClient, char *sessionId);


// List all Webplayer sessions
//
list_t*
WebPlayerV1API_v1WebPlayerListSessions(apiClient_t *apiClient);


// Retrieve Webplayer Session Information
//
web_player_session_v1_t*
WebPlayerV1API_v1WebPlayerSessionInfo(apiClient_t *apiClient, char *sessionId);


