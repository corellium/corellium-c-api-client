#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/api_error.h"
#include "../model/api_not_found_error.h"
#include "../model/create_web_player_session_body.h"
#include "../model/user_error.h"
#include "../model/web_player_allowed_domains.h"
#include "../model/web_player_created_session.h"
#include "../model/web_player_session.h"
#include "../model/web_player_session_list_response.h"


// Create a webplayer session
//
// **Required role:** Domain administrator.  Creates a new webplayer session for the requested instance.
//
web_player_created_session_t*
WebPlayerAPI_v3CreateWebPlayerSession(apiClient_t *apiClient, create_web_player_session_body_t *create_web_player_session_body);


// Delete a webplayer session
//
// **Required role:** Domain administrator.  Deletes the webplayer session identified by the given sessionId.
//
list_t*
WebPlayerAPI_v3DeleteWebPlayerSession(apiClient_t *apiClient, char *sessionId);


// Get allowed webplayer domains
//
// Returns the list of domains that webplayer sessions are permitted to access.
//
web_player_allowed_domains_t*
WebPlayerAPI_v3GetWebPlayerAllowedDomains(apiClient_t *apiClient);


// Get a webplayer session
//
// **Required role:** Domain administrator.  Returns the webplayer session identified by the given sessionId.
//
list_t*
WebPlayerAPI_v3GetWebPlayerSession(apiClient_t *apiClient, char *sessionId);


// List webplayer sessions
//
// **Required role:** Domain administrator.  Returns a paginated list of webplayer sessions for the authenticated user.
//
web_player_session_list_response_t*
WebPlayerAPI_v3ListWebPlayerSessions(apiClient_t *apiClient, double *limit, double *offset);


