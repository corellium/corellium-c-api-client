#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "instance_boot_options_fvp.h"



static instance_boot_options_fvp_t *instance_boot_options_fvp_create_internal(
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
    ) {
    instance_boot_options_fvp_t *instance_boot_options_fvp_local_var = malloc(sizeof(instance_boot_options_fvp_t));
    if (!instance_boot_options_fvp_local_var) {
        return NULL;
    }
    instance_boot_options_fvp_local_var->model_binary = model_binary;
    instance_boot_options_fvp_local_var->parameters = parameters;
    instance_boot_options_fvp_local_var->data = data;
    instance_boot_options_fvp_local_var->breaks = breaks;
    instance_boot_options_fvp_local_var->dumps = dumps;
    instance_boot_options_fvp_local_var->cadi_log = cadi_log;
    instance_boot_options_fvp_local_var->cadi_server = cadi_server;
    instance_boot_options_fvp_local_var->iris_server = iris_server;
    instance_boot_options_fvp_local_var->iris_log = iris_log;
    instance_boot_options_fvp_local_var->iris_allow_remote = iris_allow_remote;
    instance_boot_options_fvp_local_var->iris_port_range = iris_port_range;
    instance_boot_options_fvp_local_var->iris_port = iris_port;
    instance_boot_options_fvp_local_var->run = run;
    instance_boot_options_fvp_local_var->stat = stat;
    instance_boot_options_fvp_local_var->quiet = quiet;
    instance_boot_options_fvp_local_var->start = start;
    instance_boot_options_fvp_local_var->plugin = plugin;
    instance_boot_options_fvp_local_var->fast_ram = fast_ram;
    instance_boot_options_fvp_local_var->save = save;
    instance_boot_options_fvp_local_var->restore = restore;
    instance_boot_options_fvp_local_var->cpi_file = cpi_file;
    instance_boot_options_fvp_local_var->cycle_limit = cycle_limit;
    instance_boot_options_fvp_local_var->cpu_limit = cpu_limit;
    instance_boot_options_fvp_local_var->time_limit = time_limit;
    instance_boot_options_fvp_local_var->sim_limit = sim_limit;

    instance_boot_options_fvp_local_var->_library_owned = 1;
    return instance_boot_options_fvp_local_var;
}

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
    ) {
    return instance_boot_options_fvp_create_internal (
        model_binary,
        parameters,
        data,
        breaks,
        dumps,
        cadi_log,
        cadi_server,
        iris_server,
        iris_log,
        iris_allow_remote,
        iris_port_range,
        iris_port,
        run,
        stat,
        quiet,
        start,
        plugin,
        fast_ram,
        save,
        restore,
        cpi_file,
        cycle_limit,
        cpu_limit,
        time_limit,
        sim_limit
        );
}

void instance_boot_options_fvp_free(instance_boot_options_fvp_t *instance_boot_options_fvp) {
    if(NULL == instance_boot_options_fvp){
        return ;
    }
    if(instance_boot_options_fvp->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "instance_boot_options_fvp_free");
        return ;
    }
    listEntry_t *listEntry;
    if (instance_boot_options_fvp->model_binary) {
        free(instance_boot_options_fvp->model_binary);
        instance_boot_options_fvp->model_binary = NULL;
    }
    if (instance_boot_options_fvp->parameters) {
        object_free(instance_boot_options_fvp->parameters);
        instance_boot_options_fvp->parameters = NULL;
    }
    if (instance_boot_options_fvp->data) {
        list_ForEach(listEntry, instance_boot_options_fvp->data) {
            free(listEntry->data);
        }
        list_freeList(instance_boot_options_fvp->data);
        instance_boot_options_fvp->data = NULL;
    }
    if (instance_boot_options_fvp->breaks) {
        list_ForEach(listEntry, instance_boot_options_fvp->breaks) {
            free(listEntry->data);
        }
        list_freeList(instance_boot_options_fvp->breaks);
        instance_boot_options_fvp->breaks = NULL;
    }
    if (instance_boot_options_fvp->dumps) {
        list_ForEach(listEntry, instance_boot_options_fvp->dumps) {
            free(listEntry->data);
        }
        list_freeList(instance_boot_options_fvp->dumps);
        instance_boot_options_fvp->dumps = NULL;
    }
    if (instance_boot_options_fvp->cadi_log) {
        free(instance_boot_options_fvp->cadi_log);
        instance_boot_options_fvp->cadi_log = NULL;
    }
    if (instance_boot_options_fvp->cadi_server) {
        free(instance_boot_options_fvp->cadi_server);
        instance_boot_options_fvp->cadi_server = NULL;
    }
    if (instance_boot_options_fvp->iris_server) {
        free(instance_boot_options_fvp->iris_server);
        instance_boot_options_fvp->iris_server = NULL;
    }
    if (instance_boot_options_fvp->iris_log) {
        free(instance_boot_options_fvp->iris_log);
        instance_boot_options_fvp->iris_log = NULL;
    }
    if (instance_boot_options_fvp->iris_allow_remote) {
        free(instance_boot_options_fvp->iris_allow_remote);
        instance_boot_options_fvp->iris_allow_remote = NULL;
    }
    if (instance_boot_options_fvp->iris_port_range) {
        free(instance_boot_options_fvp->iris_port_range);
        instance_boot_options_fvp->iris_port_range = NULL;
    }
    if (instance_boot_options_fvp->iris_port) {
        free(instance_boot_options_fvp->iris_port);
        instance_boot_options_fvp->iris_port = NULL;
    }
    if (instance_boot_options_fvp->run) {
        free(instance_boot_options_fvp->run);
        instance_boot_options_fvp->run = NULL;
    }
    if (instance_boot_options_fvp->stat) {
        free(instance_boot_options_fvp->stat);
        instance_boot_options_fvp->stat = NULL;
    }
    if (instance_boot_options_fvp->quiet) {
        free(instance_boot_options_fvp->quiet);
        instance_boot_options_fvp->quiet = NULL;
    }
    if (instance_boot_options_fvp->start) {
        free(instance_boot_options_fvp->start);
        instance_boot_options_fvp->start = NULL;
    }
    if (instance_boot_options_fvp->plugin) {
        free(instance_boot_options_fvp->plugin);
        instance_boot_options_fvp->plugin = NULL;
    }
    if (instance_boot_options_fvp->fast_ram) {
        free(instance_boot_options_fvp->fast_ram);
        instance_boot_options_fvp->fast_ram = NULL;
    }
    if (instance_boot_options_fvp->save) {
        free(instance_boot_options_fvp->save);
        instance_boot_options_fvp->save = NULL;
    }
    if (instance_boot_options_fvp->restore) {
        free(instance_boot_options_fvp->restore);
        instance_boot_options_fvp->restore = NULL;
    }
    if (instance_boot_options_fvp->cpi_file) {
        free(instance_boot_options_fvp->cpi_file);
        instance_boot_options_fvp->cpi_file = NULL;
    }
    if (instance_boot_options_fvp->cycle_limit) {
        free(instance_boot_options_fvp->cycle_limit);
        instance_boot_options_fvp->cycle_limit = NULL;
    }
    if (instance_boot_options_fvp->cpu_limit) {
        free(instance_boot_options_fvp->cpu_limit);
        instance_boot_options_fvp->cpu_limit = NULL;
    }
    if (instance_boot_options_fvp->time_limit) {
        free(instance_boot_options_fvp->time_limit);
        instance_boot_options_fvp->time_limit = NULL;
    }
    if (instance_boot_options_fvp->sim_limit) {
        free(instance_boot_options_fvp->sim_limit);
        instance_boot_options_fvp->sim_limit = NULL;
    }
    free(instance_boot_options_fvp);
}

cJSON *instance_boot_options_fvp_convertToJSON(instance_boot_options_fvp_t *instance_boot_options_fvp) {
    cJSON *item = cJSON_CreateObject();

    // instance_boot_options_fvp->model_binary
    if(instance_boot_options_fvp->model_binary) {
    if(cJSON_AddStringToObject(item, "modelBinary", instance_boot_options_fvp->model_binary) == NULL) {
    goto fail; //String
    }
    }


    // instance_boot_options_fvp->parameters
    if(instance_boot_options_fvp->parameters) {
    cJSON *parameters_object = object_convertToJSON(instance_boot_options_fvp->parameters);
    if(parameters_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "parameters", parameters_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // instance_boot_options_fvp->data
    if(instance_boot_options_fvp->data) {
    cJSON *data = cJSON_AddArrayToObject(item, "data");
    if(data == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *dataListEntry;
    list_ForEach(dataListEntry, instance_boot_options_fvp->data) {
    if(cJSON_AddStringToObject(data, "", dataListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // instance_boot_options_fvp->breaks
    if(instance_boot_options_fvp->breaks) {
    cJSON *breaks = cJSON_AddArrayToObject(item, "breaks");
    if(breaks == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *breaksListEntry;
    list_ForEach(breaksListEntry, instance_boot_options_fvp->breaks) {
    if(cJSON_AddStringToObject(breaks, "", breaksListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // instance_boot_options_fvp->dumps
    if(instance_boot_options_fvp->dumps) {
    cJSON *dumps = cJSON_AddArrayToObject(item, "dumps");
    if(dumps == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *dumpsListEntry;
    list_ForEach(dumpsListEntry, instance_boot_options_fvp->dumps) {
    if(cJSON_AddStringToObject(dumps, "", dumpsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // instance_boot_options_fvp->cadi_log
    if(instance_boot_options_fvp->cadi_log) {
    if(cJSON_AddStringToObject(item, "cadiLog", instance_boot_options_fvp->cadi_log) == NULL) {
    goto fail; //String
    }
    }


    // instance_boot_options_fvp->cadi_server
    if(instance_boot_options_fvp->cadi_server) {
    if(cJSON_AddStringToObject(item, "cadiServer", instance_boot_options_fvp->cadi_server) == NULL) {
    goto fail; //String
    }
    }


    // instance_boot_options_fvp->iris_server
    if(instance_boot_options_fvp->iris_server) {
    if(cJSON_AddStringToObject(item, "irisServer", instance_boot_options_fvp->iris_server) == NULL) {
    goto fail; //String
    }
    }


    // instance_boot_options_fvp->iris_log
    if(instance_boot_options_fvp->iris_log) {
    if(cJSON_AddStringToObject(item, "irisLog", instance_boot_options_fvp->iris_log) == NULL) {
    goto fail; //String
    }
    }


    // instance_boot_options_fvp->iris_allow_remote
    if(instance_boot_options_fvp->iris_allow_remote) {
    if(cJSON_AddStringToObject(item, "irisAllowRemote", instance_boot_options_fvp->iris_allow_remote) == NULL) {
    goto fail; //String
    }
    }


    // instance_boot_options_fvp->iris_port_range
    if(instance_boot_options_fvp->iris_port_range) {
    if(cJSON_AddStringToObject(item, "irisPortRange", instance_boot_options_fvp->iris_port_range) == NULL) {
    goto fail; //String
    }
    }


    // instance_boot_options_fvp->iris_port
    if(instance_boot_options_fvp->iris_port) {
    if(cJSON_AddStringToObject(item, "irisPort", instance_boot_options_fvp->iris_port) == NULL) {
    goto fail; //String
    }
    }


    // instance_boot_options_fvp->run
    if(instance_boot_options_fvp->run) {
    if(cJSON_AddStringToObject(item, "run", instance_boot_options_fvp->run) == NULL) {
    goto fail; //String
    }
    }


    // instance_boot_options_fvp->stat
    if(instance_boot_options_fvp->stat) {
    if(cJSON_AddStringToObject(item, "stat", instance_boot_options_fvp->stat) == NULL) {
    goto fail; //String
    }
    }


    // instance_boot_options_fvp->quiet
    if(instance_boot_options_fvp->quiet) {
    if(cJSON_AddStringToObject(item, "quiet", instance_boot_options_fvp->quiet) == NULL) {
    goto fail; //String
    }
    }


    // instance_boot_options_fvp->start
    if(instance_boot_options_fvp->start) {
    if(cJSON_AddStringToObject(item, "start", instance_boot_options_fvp->start) == NULL) {
    goto fail; //String
    }
    }


    // instance_boot_options_fvp->plugin
    if(instance_boot_options_fvp->plugin) {
    if(cJSON_AddStringToObject(item, "plugin", instance_boot_options_fvp->plugin) == NULL) {
    goto fail; //String
    }
    }


    // instance_boot_options_fvp->fast_ram
    if(instance_boot_options_fvp->fast_ram) {
    if(cJSON_AddStringToObject(item, "fastRam", instance_boot_options_fvp->fast_ram) == NULL) {
    goto fail; //String
    }
    }


    // instance_boot_options_fvp->save
    if(instance_boot_options_fvp->save) {
    if(cJSON_AddStringToObject(item, "save", instance_boot_options_fvp->save) == NULL) {
    goto fail; //String
    }
    }


    // instance_boot_options_fvp->restore
    if(instance_boot_options_fvp->restore) {
    if(cJSON_AddStringToObject(item, "restore", instance_boot_options_fvp->restore) == NULL) {
    goto fail; //String
    }
    }


    // instance_boot_options_fvp->cpi_file
    if(instance_boot_options_fvp->cpi_file) {
    if(cJSON_AddStringToObject(item, "cpiFile", instance_boot_options_fvp->cpi_file) == NULL) {
    goto fail; //String
    }
    }


    // instance_boot_options_fvp->cycle_limit
    if(instance_boot_options_fvp->cycle_limit) {
    if(cJSON_AddStringToObject(item, "cycleLimit", instance_boot_options_fvp->cycle_limit) == NULL) {
    goto fail; //String
    }
    }


    // instance_boot_options_fvp->cpu_limit
    if(instance_boot_options_fvp->cpu_limit) {
    if(cJSON_AddStringToObject(item, "cpuLimit", instance_boot_options_fvp->cpu_limit) == NULL) {
    goto fail; //String
    }
    }


    // instance_boot_options_fvp->time_limit
    if(instance_boot_options_fvp->time_limit) {
    if(cJSON_AddStringToObject(item, "timeLimit", instance_boot_options_fvp->time_limit) == NULL) {
    goto fail; //String
    }
    }


    // instance_boot_options_fvp->sim_limit
    if(instance_boot_options_fvp->sim_limit) {
    if(cJSON_AddStringToObject(item, "simLimit", instance_boot_options_fvp->sim_limit) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

instance_boot_options_fvp_t *instance_boot_options_fvp_parseFromJSON(cJSON *instance_boot_options_fvpJSON){

    instance_boot_options_fvp_t *instance_boot_options_fvp_local_var = NULL;

    // define the local list for instance_boot_options_fvp->data
    list_t *dataList = NULL;

    // define the local list for instance_boot_options_fvp->breaks
    list_t *breaksList = NULL;

    // define the local list for instance_boot_options_fvp->dumps
    list_t *dumpsList = NULL;

    // instance_boot_options_fvp->model_binary
    cJSON *model_binary = cJSON_GetObjectItemCaseSensitive(instance_boot_options_fvpJSON, "modelBinary");
    if (cJSON_IsNull(model_binary)) {
        model_binary = NULL;
    }
    if (model_binary) { 
    if(!cJSON_IsString(model_binary) && !cJSON_IsNull(model_binary))
    {
    goto end; //String
    }
    }

    // instance_boot_options_fvp->parameters
    cJSON *parameters = cJSON_GetObjectItemCaseSensitive(instance_boot_options_fvpJSON, "parameters");
    if (cJSON_IsNull(parameters)) {
        parameters = NULL;
    }
    object_t *parameters_local_object = NULL;
    if (parameters) { 
    parameters_local_object = object_parseFromJSON(parameters); //object
    }

    // instance_boot_options_fvp->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(instance_boot_options_fvpJSON, "data");
    if (cJSON_IsNull(data)) {
        data = NULL;
    }
    if (data) { 
    cJSON *data_local = NULL;
    if(!cJSON_IsArray(data)) {
        goto end;//primitive container
    }
    dataList = list_createList();

    cJSON_ArrayForEach(data_local, data)
    {
        if(!cJSON_IsString(data_local))
        {
            goto end;
        }
        list_addElement(dataList , strdup(data_local->valuestring));
    }
    }

    // instance_boot_options_fvp->breaks
    cJSON *breaks = cJSON_GetObjectItemCaseSensitive(instance_boot_options_fvpJSON, "breaks");
    if (cJSON_IsNull(breaks)) {
        breaks = NULL;
    }
    if (breaks) { 
    cJSON *breaks_local = NULL;
    if(!cJSON_IsArray(breaks)) {
        goto end;//primitive container
    }
    breaksList = list_createList();

    cJSON_ArrayForEach(breaks_local, breaks)
    {
        if(!cJSON_IsString(breaks_local))
        {
            goto end;
        }
        list_addElement(breaksList , strdup(breaks_local->valuestring));
    }
    }

    // instance_boot_options_fvp->dumps
    cJSON *dumps = cJSON_GetObjectItemCaseSensitive(instance_boot_options_fvpJSON, "dumps");
    if (cJSON_IsNull(dumps)) {
        dumps = NULL;
    }
    if (dumps) { 
    cJSON *dumps_local = NULL;
    if(!cJSON_IsArray(dumps)) {
        goto end;//primitive container
    }
    dumpsList = list_createList();

    cJSON_ArrayForEach(dumps_local, dumps)
    {
        if(!cJSON_IsString(dumps_local))
        {
            goto end;
        }
        list_addElement(dumpsList , strdup(dumps_local->valuestring));
    }
    }

    // instance_boot_options_fvp->cadi_log
    cJSON *cadi_log = cJSON_GetObjectItemCaseSensitive(instance_boot_options_fvpJSON, "cadiLog");
    if (cJSON_IsNull(cadi_log)) {
        cadi_log = NULL;
    }
    if (cadi_log) { 
    if(!cJSON_IsString(cadi_log) && !cJSON_IsNull(cadi_log))
    {
    goto end; //String
    }
    }

    // instance_boot_options_fvp->cadi_server
    cJSON *cadi_server = cJSON_GetObjectItemCaseSensitive(instance_boot_options_fvpJSON, "cadiServer");
    if (cJSON_IsNull(cadi_server)) {
        cadi_server = NULL;
    }
    if (cadi_server) { 
    if(!cJSON_IsString(cadi_server) && !cJSON_IsNull(cadi_server))
    {
    goto end; //String
    }
    }

    // instance_boot_options_fvp->iris_server
    cJSON *iris_server = cJSON_GetObjectItemCaseSensitive(instance_boot_options_fvpJSON, "irisServer");
    if (cJSON_IsNull(iris_server)) {
        iris_server = NULL;
    }
    if (iris_server) { 
    if(!cJSON_IsString(iris_server) && !cJSON_IsNull(iris_server))
    {
    goto end; //String
    }
    }

    // instance_boot_options_fvp->iris_log
    cJSON *iris_log = cJSON_GetObjectItemCaseSensitive(instance_boot_options_fvpJSON, "irisLog");
    if (cJSON_IsNull(iris_log)) {
        iris_log = NULL;
    }
    if (iris_log) { 
    if(!cJSON_IsString(iris_log) && !cJSON_IsNull(iris_log))
    {
    goto end; //String
    }
    }

    // instance_boot_options_fvp->iris_allow_remote
    cJSON *iris_allow_remote = cJSON_GetObjectItemCaseSensitive(instance_boot_options_fvpJSON, "irisAllowRemote");
    if (cJSON_IsNull(iris_allow_remote)) {
        iris_allow_remote = NULL;
    }
    if (iris_allow_remote) { 
    if(!cJSON_IsString(iris_allow_remote) && !cJSON_IsNull(iris_allow_remote))
    {
    goto end; //String
    }
    }

    // instance_boot_options_fvp->iris_port_range
    cJSON *iris_port_range = cJSON_GetObjectItemCaseSensitive(instance_boot_options_fvpJSON, "irisPortRange");
    if (cJSON_IsNull(iris_port_range)) {
        iris_port_range = NULL;
    }
    if (iris_port_range) { 
    if(!cJSON_IsString(iris_port_range) && !cJSON_IsNull(iris_port_range))
    {
    goto end; //String
    }
    }

    // instance_boot_options_fvp->iris_port
    cJSON *iris_port = cJSON_GetObjectItemCaseSensitive(instance_boot_options_fvpJSON, "irisPort");
    if (cJSON_IsNull(iris_port)) {
        iris_port = NULL;
    }
    if (iris_port) { 
    if(!cJSON_IsString(iris_port) && !cJSON_IsNull(iris_port))
    {
    goto end; //String
    }
    }

    // instance_boot_options_fvp->run
    cJSON *run = cJSON_GetObjectItemCaseSensitive(instance_boot_options_fvpJSON, "run");
    if (cJSON_IsNull(run)) {
        run = NULL;
    }
    if (run) { 
    if(!cJSON_IsString(run) && !cJSON_IsNull(run))
    {
    goto end; //String
    }
    }

    // instance_boot_options_fvp->stat
    cJSON *stat = cJSON_GetObjectItemCaseSensitive(instance_boot_options_fvpJSON, "stat");
    if (cJSON_IsNull(stat)) {
        stat = NULL;
    }
    if (stat) { 
    if(!cJSON_IsString(stat) && !cJSON_IsNull(stat))
    {
    goto end; //String
    }
    }

    // instance_boot_options_fvp->quiet
    cJSON *quiet = cJSON_GetObjectItemCaseSensitive(instance_boot_options_fvpJSON, "quiet");
    if (cJSON_IsNull(quiet)) {
        quiet = NULL;
    }
    if (quiet) { 
    if(!cJSON_IsString(quiet) && !cJSON_IsNull(quiet))
    {
    goto end; //String
    }
    }

    // instance_boot_options_fvp->start
    cJSON *start = cJSON_GetObjectItemCaseSensitive(instance_boot_options_fvpJSON, "start");
    if (cJSON_IsNull(start)) {
        start = NULL;
    }
    if (start) { 
    if(!cJSON_IsString(start) && !cJSON_IsNull(start))
    {
    goto end; //String
    }
    }

    // instance_boot_options_fvp->plugin
    cJSON *plugin = cJSON_GetObjectItemCaseSensitive(instance_boot_options_fvpJSON, "plugin");
    if (cJSON_IsNull(plugin)) {
        plugin = NULL;
    }
    if (plugin) { 
    if(!cJSON_IsString(plugin) && !cJSON_IsNull(plugin))
    {
    goto end; //String
    }
    }

    // instance_boot_options_fvp->fast_ram
    cJSON *fast_ram = cJSON_GetObjectItemCaseSensitive(instance_boot_options_fvpJSON, "fastRam");
    if (cJSON_IsNull(fast_ram)) {
        fast_ram = NULL;
    }
    if (fast_ram) { 
    if(!cJSON_IsString(fast_ram) && !cJSON_IsNull(fast_ram))
    {
    goto end; //String
    }
    }

    // instance_boot_options_fvp->save
    cJSON *save = cJSON_GetObjectItemCaseSensitive(instance_boot_options_fvpJSON, "save");
    if (cJSON_IsNull(save)) {
        save = NULL;
    }
    if (save) { 
    if(!cJSON_IsString(save) && !cJSON_IsNull(save))
    {
    goto end; //String
    }
    }

    // instance_boot_options_fvp->restore
    cJSON *restore = cJSON_GetObjectItemCaseSensitive(instance_boot_options_fvpJSON, "restore");
    if (cJSON_IsNull(restore)) {
        restore = NULL;
    }
    if (restore) { 
    if(!cJSON_IsString(restore) && !cJSON_IsNull(restore))
    {
    goto end; //String
    }
    }

    // instance_boot_options_fvp->cpi_file
    cJSON *cpi_file = cJSON_GetObjectItemCaseSensitive(instance_boot_options_fvpJSON, "cpiFile");
    if (cJSON_IsNull(cpi_file)) {
        cpi_file = NULL;
    }
    if (cpi_file) { 
    if(!cJSON_IsString(cpi_file) && !cJSON_IsNull(cpi_file))
    {
    goto end; //String
    }
    }

    // instance_boot_options_fvp->cycle_limit
    cJSON *cycle_limit = cJSON_GetObjectItemCaseSensitive(instance_boot_options_fvpJSON, "cycleLimit");
    if (cJSON_IsNull(cycle_limit)) {
        cycle_limit = NULL;
    }
    if (cycle_limit) { 
    if(!cJSON_IsString(cycle_limit) && !cJSON_IsNull(cycle_limit))
    {
    goto end; //String
    }
    }

    // instance_boot_options_fvp->cpu_limit
    cJSON *cpu_limit = cJSON_GetObjectItemCaseSensitive(instance_boot_options_fvpJSON, "cpuLimit");
    if (cJSON_IsNull(cpu_limit)) {
        cpu_limit = NULL;
    }
    if (cpu_limit) { 
    if(!cJSON_IsString(cpu_limit) && !cJSON_IsNull(cpu_limit))
    {
    goto end; //String
    }
    }

    // instance_boot_options_fvp->time_limit
    cJSON *time_limit = cJSON_GetObjectItemCaseSensitive(instance_boot_options_fvpJSON, "timeLimit");
    if (cJSON_IsNull(time_limit)) {
        time_limit = NULL;
    }
    if (time_limit) { 
    if(!cJSON_IsString(time_limit) && !cJSON_IsNull(time_limit))
    {
    goto end; //String
    }
    }

    // instance_boot_options_fvp->sim_limit
    cJSON *sim_limit = cJSON_GetObjectItemCaseSensitive(instance_boot_options_fvpJSON, "simLimit");
    if (cJSON_IsNull(sim_limit)) {
        sim_limit = NULL;
    }
    if (sim_limit) { 
    if(!cJSON_IsString(sim_limit) && !cJSON_IsNull(sim_limit))
    {
    goto end; //String
    }
    }


    instance_boot_options_fvp_local_var = instance_boot_options_fvp_create_internal (
        model_binary && !cJSON_IsNull(model_binary) ? strdup(model_binary->valuestring) : NULL,
        parameters ? parameters_local_object : NULL,
        data ? dataList : NULL,
        breaks ? breaksList : NULL,
        dumps ? dumpsList : NULL,
        cadi_log && !cJSON_IsNull(cadi_log) ? strdup(cadi_log->valuestring) : NULL,
        cadi_server && !cJSON_IsNull(cadi_server) ? strdup(cadi_server->valuestring) : NULL,
        iris_server && !cJSON_IsNull(iris_server) ? strdup(iris_server->valuestring) : NULL,
        iris_log && !cJSON_IsNull(iris_log) ? strdup(iris_log->valuestring) : NULL,
        iris_allow_remote && !cJSON_IsNull(iris_allow_remote) ? strdup(iris_allow_remote->valuestring) : NULL,
        iris_port_range && !cJSON_IsNull(iris_port_range) ? strdup(iris_port_range->valuestring) : NULL,
        iris_port && !cJSON_IsNull(iris_port) ? strdup(iris_port->valuestring) : NULL,
        run && !cJSON_IsNull(run) ? strdup(run->valuestring) : NULL,
        stat && !cJSON_IsNull(stat) ? strdup(stat->valuestring) : NULL,
        quiet && !cJSON_IsNull(quiet) ? strdup(quiet->valuestring) : NULL,
        start && !cJSON_IsNull(start) ? strdup(start->valuestring) : NULL,
        plugin && !cJSON_IsNull(plugin) ? strdup(plugin->valuestring) : NULL,
        fast_ram && !cJSON_IsNull(fast_ram) ? strdup(fast_ram->valuestring) : NULL,
        save && !cJSON_IsNull(save) ? strdup(save->valuestring) : NULL,
        restore && !cJSON_IsNull(restore) ? strdup(restore->valuestring) : NULL,
        cpi_file && !cJSON_IsNull(cpi_file) ? strdup(cpi_file->valuestring) : NULL,
        cycle_limit && !cJSON_IsNull(cycle_limit) ? strdup(cycle_limit->valuestring) : NULL,
        cpu_limit && !cJSON_IsNull(cpu_limit) ? strdup(cpu_limit->valuestring) : NULL,
        time_limit && !cJSON_IsNull(time_limit) ? strdup(time_limit->valuestring) : NULL,
        sim_limit && !cJSON_IsNull(sim_limit) ? strdup(sim_limit->valuestring) : NULL
        );

    return instance_boot_options_fvp_local_var;
end:
    if (dataList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, dataList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(dataList);
        dataList = NULL;
    }
    if (breaksList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, breaksList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(breaksList);
        breaksList = NULL;
    }
    if (dumpsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, dumpsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(dumpsList);
        dumpsList = NULL;
    }
    return NULL;

}
