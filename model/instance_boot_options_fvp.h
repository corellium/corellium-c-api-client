/*
 * instance_boot_options_fvp.h
 *
 * 
 */

#ifndef _instance_boot_options_fvp_H_
#define _instance_boot_options_fvp_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct instance_boot_options_fvp_t instance_boot_options_fvp_t;

#include "any_type.h"
#include "object.h"



typedef struct instance_boot_options_fvp_t {
    char *model_binary; // string
    object_t *parameters; //object
    list_t *data; //primitive container
    list_t *breaks; //primitive container
    list_t *dumps; //primitive container
    char *cadi_log; // string
    char *cadi_server; // string
    char *iris_server; // string
    char *iris_log; // string
    char *iris_allow_remote; // string
    char *iris_port_range; // string
    char *iris_port; // string
    char *run; // string
    char *stat; // string
    char *quiet; // string
    char *start; // string
    char *plugin; // string
    char *fast_ram; // string
    char *save; // string
    char *restore; // string
    char *cpi_file; // string
    char *cycle_limit; // string
    char *cpu_limit; // string
    char *time_limit; // string
    char *sim_limit; // string

    int _library_owned; // Is the library responsible for freeing this object?
} instance_boot_options_fvp_t;

__attribute__((deprecated)) instance_boot_options_fvp_t *instance_boot_options_fvp_create(
    char *model_binary,
    object_t *parameters,
    list_t *data,
    list_t *breaks,
    list_t *dumps,
    char *cadi_log,
    char *cadi_server,
    char *iris_server,
    char *iris_log,
    char *iris_allow_remote,
    char *iris_port_range,
    char *iris_port,
    char *run,
    char *stat,
    char *quiet,
    char *start,
    char *plugin,
    char *fast_ram,
    char *save,
    char *restore,
    char *cpi_file,
    char *cycle_limit,
    char *cpu_limit,
    char *time_limit,
    char *sim_limit
);

void instance_boot_options_fvp_free(instance_boot_options_fvp_t *instance_boot_options_fvp);

instance_boot_options_fvp_t *instance_boot_options_fvp_parseFromJSON(cJSON *instance_boot_options_fvpJSON);

cJSON *instance_boot_options_fvp_convertToJSON(instance_boot_options_fvp_t *instance_boot_options_fvp);

#endif /* _instance_boot_options_fvp_H_ */

