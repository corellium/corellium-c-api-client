#ifndef open_vpn_config_TEST
#define open_vpn_config_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define open_vpn_config_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/open_vpn_config.h"
open_vpn_config_t* instantiate_open_vpn_config(int include_optional);



open_vpn_config_t* instantiate_open_vpn_config(int include_optional) {
  open_vpn_config_t* open_vpn_config = NULL;
  if (include_optional) {
    open_vpn_config = open_vpn_config_create(
      "jane.doe",
      "<redacted>",
      "client
dev tun
proto udp
remote vpn.example.com 1194
resolv-retry infinite
nobind
persist-key
persist-tun
remote-cert-tls server
cipher AES-256-CBC
verb 3
<ca>
-----BEGIN CERTIFICATE-----
<ca-certificate>
-----END CERTIFICATE-----
</ca>
"
    );
  } else {
    open_vpn_config = open_vpn_config_create(
      "jane.doe",
      "<redacted>",
      "client
dev tun
proto udp
remote vpn.example.com 1194
resolv-retry infinite
nobind
persist-key
persist-tun
remote-cert-tls server
cipher AES-256-CBC
verb 3
<ca>
-----BEGIN CERTIFICATE-----
<ca-certificate>
-----END CERTIFICATE-----
</ca>
"
    );
  }

  return open_vpn_config;
}


#ifdef open_vpn_config_MAIN

void test_open_vpn_config(int include_optional) {
    open_vpn_config_t* open_vpn_config_1 = instantiate_open_vpn_config(include_optional);

	cJSON* jsonopen_vpn_config_1 = open_vpn_config_convertToJSON(open_vpn_config_1);
	printf("open_vpn_config :\n%s\n", cJSON_Print(jsonopen_vpn_config_1));
	open_vpn_config_t* open_vpn_config_2 = open_vpn_config_parseFromJSON(jsonopen_vpn_config_1);
	cJSON* jsonopen_vpn_config_2 = open_vpn_config_convertToJSON(open_vpn_config_2);
	printf("repeating open_vpn_config:\n%s\n", cJSON_Print(jsonopen_vpn_config_2));
}

int main() {
  test_open_vpn_config(1);
  test_open_vpn_config(0);

  printf("Hello world \n");
  return 0;
}

#endif // open_vpn_config_MAIN
#endif // open_vpn_config_TEST
