#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "layout_schema.h"



static layout_schema_t *layout_schema_create_internal(
    object_t *free_cpus,
    object_t *free_ram,
    double free_ranges,
    double numa_nodes,
    char *ram_cpu,
    object_t *node_map,
    object_t *free_cores,
    double ram_core
    ) {
    layout_schema_t *layout_schema_local_var = malloc(sizeof(layout_schema_t));
    if (!layout_schema_local_var) {
        return NULL;
    }
    layout_schema_local_var->free_cpus = free_cpus;
    layout_schema_local_var->free_ram = free_ram;
    layout_schema_local_var->free_ranges = free_ranges;
    layout_schema_local_var->numa_nodes = numa_nodes;
    layout_schema_local_var->ram_cpu = ram_cpu;
    layout_schema_local_var->node_map = node_map;
    layout_schema_local_var->free_cores = free_cores;
    layout_schema_local_var->ram_core = ram_core;

    layout_schema_local_var->_library_owned = 1;
    return layout_schema_local_var;
}

__attribute__((deprecated)) layout_schema_t *layout_schema_create(
    object_t *free_cpus,
    object_t *free_ram,
    double free_ranges,
    double numa_nodes,
    char *ram_cpu,
    object_t *node_map,
    object_t *free_cores,
    double ram_core
    ) {
    return layout_schema_create_internal (
        free_cpus,
        free_ram,
        free_ranges,
        numa_nodes,
        ram_cpu,
        node_map,
        free_cores,
        ram_core
        );
}

void layout_schema_free(layout_schema_t *layout_schema) {
    if(NULL == layout_schema){
        return ;
    }
    if(layout_schema->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "layout_schema_free");
        return ;
    }
    listEntry_t *listEntry;
    if (layout_schema->free_cpus) {
        object_free(layout_schema->free_cpus);
        layout_schema->free_cpus = NULL;
    }
    if (layout_schema->free_ram) {
        object_free(layout_schema->free_ram);
        layout_schema->free_ram = NULL;
    }
    if (layout_schema->ram_cpu) {
        free(layout_schema->ram_cpu);
        layout_schema->ram_cpu = NULL;
    }
    if (layout_schema->node_map) {
        object_free(layout_schema->node_map);
        layout_schema->node_map = NULL;
    }
    if (layout_schema->free_cores) {
        object_free(layout_schema->free_cores);
        layout_schema->free_cores = NULL;
    }
    free(layout_schema);
}

cJSON *layout_schema_convertToJSON(layout_schema_t *layout_schema) {
    cJSON *item = cJSON_CreateObject();

    // layout_schema->free_cpus
    if(layout_schema->free_cpus) {
    cJSON *free_cpus_object = object_convertToJSON(layout_schema->free_cpus);
    if(free_cpus_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "freeCpus", free_cpus_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // layout_schema->free_ram
    if(layout_schema->free_ram) {
    cJSON *free_ram_object = object_convertToJSON(layout_schema->free_ram);
    if(free_ram_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "freeRam", free_ram_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // layout_schema->free_ranges
    if(layout_schema->free_ranges) {
    if(cJSON_AddNumberToObject(item, "freeRanges", layout_schema->free_ranges) == NULL) {
    goto fail; //Numeric
    }
    }


    // layout_schema->numa_nodes
    if(layout_schema->numa_nodes) {
    if(cJSON_AddNumberToObject(item, "numaNodes", layout_schema->numa_nodes) == NULL) {
    goto fail; //Numeric
    }
    }


    // layout_schema->ram_cpu
    if(layout_schema->ram_cpu) {
    if(cJSON_AddStringToObject(item, "ramCpu", layout_schema->ram_cpu) == NULL) {
    goto fail; //String
    }
    }


    // layout_schema->node_map
    if(layout_schema->node_map) {
    cJSON *node_map_object = object_convertToJSON(layout_schema->node_map);
    if(node_map_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "nodeMap", node_map_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // layout_schema->free_cores
    if(layout_schema->free_cores) {
    cJSON *free_cores_object = object_convertToJSON(layout_schema->free_cores);
    if(free_cores_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "freeCores", free_cores_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // layout_schema->ram_core
    if(layout_schema->ram_core) {
    if(cJSON_AddNumberToObject(item, "ramCore", layout_schema->ram_core) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

layout_schema_t *layout_schema_parseFromJSON(cJSON *layout_schemaJSON){

    layout_schema_t *layout_schema_local_var = NULL;

    // layout_schema->free_cpus
    cJSON *free_cpus = cJSON_GetObjectItemCaseSensitive(layout_schemaJSON, "freeCpus");
    if (cJSON_IsNull(free_cpus)) {
        free_cpus = NULL;
    }
    object_t *free_cpus_local_object = NULL;
    if (free_cpus) { 
    free_cpus_local_object = object_parseFromJSON(free_cpus); //object
    }

    // layout_schema->free_ram
    cJSON *free_ram = cJSON_GetObjectItemCaseSensitive(layout_schemaJSON, "freeRam");
    if (cJSON_IsNull(free_ram)) {
        free_ram = NULL;
    }
    object_t *free_ram_local_object = NULL;
    if (free_ram) { 
    free_ram_local_object = object_parseFromJSON(free_ram); //object
    }

    // layout_schema->free_ranges
    cJSON *free_ranges = cJSON_GetObjectItemCaseSensitive(layout_schemaJSON, "freeRanges");
    if (cJSON_IsNull(free_ranges)) {
        free_ranges = NULL;
    }
    if (free_ranges) { 
    if(!cJSON_IsNumber(free_ranges))
    {
    goto end; //Numeric
    }
    }

    // layout_schema->numa_nodes
    cJSON *numa_nodes = cJSON_GetObjectItemCaseSensitive(layout_schemaJSON, "numaNodes");
    if (cJSON_IsNull(numa_nodes)) {
        numa_nodes = NULL;
    }
    if (numa_nodes) { 
    if(!cJSON_IsNumber(numa_nodes))
    {
    goto end; //Numeric
    }
    }

    // layout_schema->ram_cpu
    cJSON *ram_cpu = cJSON_GetObjectItemCaseSensitive(layout_schemaJSON, "ramCpu");
    if (cJSON_IsNull(ram_cpu)) {
        ram_cpu = NULL;
    }
    if (ram_cpu) { 
    if(!cJSON_IsString(ram_cpu) && !cJSON_IsNull(ram_cpu))
    {
    goto end; //String
    }
    }

    // layout_schema->node_map
    cJSON *node_map = cJSON_GetObjectItemCaseSensitive(layout_schemaJSON, "nodeMap");
    if (cJSON_IsNull(node_map)) {
        node_map = NULL;
    }
    object_t *node_map_local_object = NULL;
    if (node_map) { 
    node_map_local_object = object_parseFromJSON(node_map); //object
    }

    // layout_schema->free_cores
    cJSON *free_cores = cJSON_GetObjectItemCaseSensitive(layout_schemaJSON, "freeCores");
    if (cJSON_IsNull(free_cores)) {
        free_cores = NULL;
    }
    object_t *free_cores_local_object = NULL;
    if (free_cores) { 
    free_cores_local_object = object_parseFromJSON(free_cores); //object
    }

    // layout_schema->ram_core
    cJSON *ram_core = cJSON_GetObjectItemCaseSensitive(layout_schemaJSON, "ramCore");
    if (cJSON_IsNull(ram_core)) {
        ram_core = NULL;
    }
    if (ram_core) { 
    if(!cJSON_IsNumber(ram_core))
    {
    goto end; //Numeric
    }
    }


    layout_schema_local_var = layout_schema_create_internal (
        free_cpus ? free_cpus_local_object : NULL,
        free_ram ? free_ram_local_object : NULL,
        free_ranges ? free_ranges->valuedouble : 0,
        numa_nodes ? numa_nodes->valuedouble : 0,
        ram_cpu && !cJSON_IsNull(ram_cpu) ? strdup(ram_cpu->valuestring) : NULL,
        node_map ? node_map_local_object : NULL,
        free_cores ? free_cores_local_object : NULL,
        ram_core ? ram_core->valuedouble : 0
        );

    return layout_schema_local_var;
end:
    return NULL;

}
