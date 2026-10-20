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
#include "../model/user_error_response.h"
#include "../model/web_player_allowed_domains.h"
#include "../model/web_player_created_session.h"
#include "../model/web_player_session.h"
#include "../model/web_player_session_list_response.h"


// Create a webplayer session
//
// **Required role:** Domain administrator.  Creates a Web Player session: a limited token that lets someone use one device, embedded in your own web page, without giving them a Corellium account. Requires a domain administrator.  Choose the device (`projectId`, `instanceId`), how long the session lasts (`expiresIn`, at least 1800 seconds), and which parts of the device interface the viewer may use (`features`). Pass the returned `token` to the Web Player in your page. The website domains configured for embedding are listed by `v3GetWebPlayerAllowedDomains` and set with `webplayer.allowedDomains` on `PATCH /v3/domain`. End the session early with `v3DeleteWebPlayerSession`.
//
web_player_created_session_t*
WebPlayerAPI_v3CreateWebPlayerSession(apiClient_t *apiClient, create_web_player_session_body_t *create_web_player_session_body);


// Delete a webplayer session
//
// **Required role:** Domain administrator.  Ends a Web Player session: its token stops working, so the embedded viewer loses access to the device. Requires a domain administrator. The device itself is not affected.  Deletes are idempotent: an unknown `sessionId` is a successful no-op that still returns 204, and repeated calls return 204 as well. A 404 means the request path did not match a delete route, not that the target was missing.
//
void
WebPlayerAPI_v3DeleteWebPlayerSession(apiClient_t *apiClient, char *sessionId);


// Get allowed webplayer domains
//
// Returns the website domains configured for embedding the Web Player (`webplayer.allowedDomains` in your domain settings). Change the list with `PATCH /v3/domain`.
//
web_player_allowed_domains_t*
WebPlayerAPI_v3GetWebPlayerAllowedDomains(apiClient_t *apiClient);


// Get a webplayer session
//
// **Required role:** Domain administrator.  Returns one Web Player session, including its token and expiration. Requires a domain administrator.
//
list_t*
WebPlayerAPI_v3GetWebPlayerSession(apiClient_t *apiClient, char *sessionId);


// List webplayer sessions
//
// **Required role:** Domain administrator.  Lists the Web Player sessions in your domain, with each session's ID, token and expiration. Requires a domain administrator. Results are paginated with `limit` and `offset`.
//
web_player_session_list_response_t*
WebPlayerAPI_v3ListWebPlayerSessions(apiClient_t *apiClient, double *limit, double *offset);


