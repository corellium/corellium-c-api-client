#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sys_info_schema.h"



static sys_info_schema_t *sys_info_schema_create_internal(
    double numa_nodes,
    object_t *cpu,
    object_t *cpu_avail,
    double slot,
    double slot_avail,
    double ram,
    double ram_avail,
    double vpn,
    double vpn_avail,
    double gpu,
    double gpu_avail,
    char *ram_cpu,
    char *el032,
    char *el132,
    char *mmu_tg16k,
    double hw_pac,
    char *arm_trace,
    double cores,
    double cores_avail,
    double ram_core
    ) {
    sys_info_schema_t *sys_info_schema_local_var = malloc(sizeof(sys_info_schema_t));
    if (!sys_info_schema_local_var) {
        return NULL;
    }
    sys_info_schema_local_var->numa_nodes = numa_nodes;
    sys_info_schema_local_var->cpu = cpu;
    sys_info_schema_local_var->cpu_avail = cpu_avail;
    sys_info_schema_local_var->slot = slot;
    sys_info_schema_local_var->slot_avail = slot_avail;
    sys_info_schema_local_var->ram = ram;
    sys_info_schema_local_var->ram_avail = ram_avail;
    sys_info_schema_local_var->vpn = vpn;
    sys_info_schema_local_var->vpn_avail = vpn_avail;
    sys_info_schema_local_var->gpu = gpu;
    sys_info_schema_local_var->gpu_avail = gpu_avail;
    sys_info_schema_local_var->ram_cpu = ram_cpu;
    sys_info_schema_local_var->el032 = el032;
    sys_info_schema_local_var->el132 = el132;
    sys_info_schema_local_var->mmu_tg16k = mmu_tg16k;
    sys_info_schema_local_var->hw_pac = hw_pac;
    sys_info_schema_local_var->arm_trace = arm_trace;
    sys_info_schema_local_var->cores = cores;
    sys_info_schema_local_var->cores_avail = cores_avail;
    sys_info_schema_local_var->ram_core = ram_core;

    sys_info_schema_local_var->_library_owned = 1;
    return sys_info_schema_local_var;
}

__attribute__((deprecated)) sys_info_schema_t *sys_info_schema_create(
    double numa_nodes,
    object_t *cpu,
    object_t *cpu_avail,
    double slot,
    double slot_avail,
    double ram,
    double ram_avail,
    double vpn,
    double vpn_avail,
    double gpu,
    double gpu_avail,
    char *ram_cpu,
    char *el032,
    char *el132,
    char *mmu_tg16k,
    double hw_pac,
    char *arm_trace,
    double cores,
    double cores_avail,
    double ram_core
    ) {
    return sys_info_schema_create_internal (
        numa_nodes,
        cpu,
        cpu_avail,
        slot,
        slot_avail,
        ram,
        ram_avail,
        vpn,
        vpn_avail,
        gpu,
        gpu_avail,
        ram_cpu,
        el032,
        el132,
        mmu_tg16k,
        hw_pac,
        arm_trace,
        cores,
        cores_avail,
        ram_core
        );
}

void sys_info_schema_free(sys_info_schema_t *sys_info_schema) {
    if(NULL == sys_info_schema){
        return ;
    }
    if(sys_info_schema->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "sys_info_schema_free");
        return ;
    }
    listEntry_t *listEntry;
    if (sys_info_schema->cpu) {
        object_free(sys_info_schema->cpu);
        sys_info_schema->cpu = NULL;
    }
    if (sys_info_schema->cpu_avail) {
        object_free(sys_info_schema->cpu_avail);
        sys_info_schema->cpu_avail = NULL;
    }
    if (sys_info_schema->ram_cpu) {
        free(sys_info_schema->ram_cpu);
        sys_info_schema->ram_cpu = NULL;
    }
    if (sys_info_schema->el032) {
        free(sys_info_schema->el032);
        sys_info_schema->el032 = NULL;
    }
    if (sys_info_schema->el132) {
        free(sys_info_schema->el132);
        sys_info_schema->el132 = NULL;
    }
    if (sys_info_schema->mmu_tg16k) {
        free(sys_info_schema->mmu_tg16k);
        sys_info_schema->mmu_tg16k = NULL;
    }
    if (sys_info_schema->arm_trace) {
        free(sys_info_schema->arm_trace);
        sys_info_schema->arm_trace = NULL;
    }
    free(sys_info_schema);
}

cJSON *sys_info_schema_convertToJSON(sys_info_schema_t *sys_info_schema) {
    cJSON *item = cJSON_CreateObject();

    // sys_info_schema->numa_nodes
    if(sys_info_schema->numa_nodes) {
    if(cJSON_AddNumberToObject(item, "numaNodes", sys_info_schema->numa_nodes) == NULL) {
    goto fail; //Numeric
    }
    }


    // sys_info_schema->cpu
    if(sys_info_schema->cpu) {
    cJSON *cpu_object = object_convertToJSON(sys_info_schema->cpu);
    if(cpu_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "cpu", cpu_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // sys_info_schema->cpu_avail
    if(sys_info_schema->cpu_avail) {
    cJSON *cpu_avail_object = object_convertToJSON(sys_info_schema->cpu_avail);
    if(cpu_avail_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "cpuAvail", cpu_avail_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // sys_info_schema->slot
    if(sys_info_schema->slot) {
    if(cJSON_AddNumberToObject(item, "slot", sys_info_schema->slot) == NULL) {
    goto fail; //Numeric
    }
    }


    // sys_info_schema->slot_avail
    if(sys_info_schema->slot_avail) {
    if(cJSON_AddNumberToObject(item, "slotAvail", sys_info_schema->slot_avail) == NULL) {
    goto fail; //Numeric
    }
    }


    // sys_info_schema->ram
    if(sys_info_schema->ram) {
    if(cJSON_AddNumberToObject(item, "ram", sys_info_schema->ram) == NULL) {
    goto fail; //Numeric
    }
    }


    // sys_info_schema->ram_avail
    if(sys_info_schema->ram_avail) {
    if(cJSON_AddNumberToObject(item, "ramAvail", sys_info_schema->ram_avail) == NULL) {
    goto fail; //Numeric
    }
    }


    // sys_info_schema->vpn
    if(sys_info_schema->vpn) {
    if(cJSON_AddNumberToObject(item, "vpn", sys_info_schema->vpn) == NULL) {
    goto fail; //Numeric
    }
    }


    // sys_info_schema->vpn_avail
    if(sys_info_schema->vpn_avail) {
    if(cJSON_AddNumberToObject(item, "vpnAvail", sys_info_schema->vpn_avail) == NULL) {
    goto fail; //Numeric
    }
    }


    // sys_info_schema->gpu
    if(sys_info_schema->gpu) {
    if(cJSON_AddNumberToObject(item, "gpu", sys_info_schema->gpu) == NULL) {
    goto fail; //Numeric
    }
    }


    // sys_info_schema->gpu_avail
    if(sys_info_schema->gpu_avail) {
    if(cJSON_AddNumberToObject(item, "gpuAvail", sys_info_schema->gpu_avail) == NULL) {
    goto fail; //Numeric
    }
    }


    // sys_info_schema->ram_cpu
    if(sys_info_schema->ram_cpu) {
    if(cJSON_AddStringToObject(item, "ramCpu", sys_info_schema->ram_cpu) == NULL) {
    goto fail; //String
    }
    }


    // sys_info_schema->el032
    if(sys_info_schema->el032) {
    if(cJSON_AddStringToObject(item, "el032", sys_info_schema->el032) == NULL) {
    goto fail; //String
    }
    }


    // sys_info_schema->el132
    if(sys_info_schema->el132) {
    if(cJSON_AddStringToObject(item, "el132", sys_info_schema->el132) == NULL) {
    goto fail; //String
    }
    }


    // sys_info_schema->mmu_tg16k
    if(sys_info_schema->mmu_tg16k) {
    if(cJSON_AddStringToObject(item, "mmuTg16k", sys_info_schema->mmu_tg16k) == NULL) {
    goto fail; //String
    }
    }


    // sys_info_schema->hw_pac
    if(sys_info_schema->hw_pac) {
    if(cJSON_AddNumberToObject(item, "hwPac", sys_info_schema->hw_pac) == NULL) {
    goto fail; //Numeric
    }
    }


    // sys_info_schema->arm_trace
    if(sys_info_schema->arm_trace) {
    if(cJSON_AddStringToObject(item, "armTrace", sys_info_schema->arm_trace) == NULL) {
    goto fail; //String
    }
    }


    // sys_info_schema->cores
    if(sys_info_schema->cores) {
    if(cJSON_AddNumberToObject(item, "cores", sys_info_schema->cores) == NULL) {
    goto fail; //Numeric
    }
    }


    // sys_info_schema->cores_avail
    if(sys_info_schema->cores_avail) {
    if(cJSON_AddNumberToObject(item, "coresAvail", sys_info_schema->cores_avail) == NULL) {
    goto fail; //Numeric
    }
    }


    // sys_info_schema->ram_core
    if(sys_info_schema->ram_core) {
    if(cJSON_AddNumberToObject(item, "ramCore", sys_info_schema->ram_core) == NULL) {
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

sys_info_schema_t *sys_info_schema_parseFromJSON(cJSON *sys_info_schemaJSON){

    sys_info_schema_t *sys_info_schema_local_var = NULL;

    // sys_info_schema->numa_nodes
    cJSON *numa_nodes = cJSON_GetObjectItemCaseSensitive(sys_info_schemaJSON, "numaNodes");
    if (cJSON_IsNull(numa_nodes)) {
        numa_nodes = NULL;
    }
    if (numa_nodes) { 
    if(!cJSON_IsNumber(numa_nodes))
    {
    goto end; //Numeric
    }
    }

    // sys_info_schema->cpu
    cJSON *cpu = cJSON_GetObjectItemCaseSensitive(sys_info_schemaJSON, "cpu");
    if (cJSON_IsNull(cpu)) {
        cpu = NULL;
    }
    object_t *cpu_local_object = NULL;
    if (cpu) { 
    cpu_local_object = object_parseFromJSON(cpu); //object
    }

    // sys_info_schema->cpu_avail
    cJSON *cpu_avail = cJSON_GetObjectItemCaseSensitive(sys_info_schemaJSON, "cpuAvail");
    if (cJSON_IsNull(cpu_avail)) {
        cpu_avail = NULL;
    }
    object_t *cpu_avail_local_object = NULL;
    if (cpu_avail) { 
    cpu_avail_local_object = object_parseFromJSON(cpu_avail); //object
    }

    // sys_info_schema->slot
    cJSON *slot = cJSON_GetObjectItemCaseSensitive(sys_info_schemaJSON, "slot");
    if (cJSON_IsNull(slot)) {
        slot = NULL;
    }
    if (slot) { 
    if(!cJSON_IsNumber(slot))
    {
    goto end; //Numeric
    }
    }

    // sys_info_schema->slot_avail
    cJSON *slot_avail = cJSON_GetObjectItemCaseSensitive(sys_info_schemaJSON, "slotAvail");
    if (cJSON_IsNull(slot_avail)) {
        slot_avail = NULL;
    }
    if (slot_avail) { 
    if(!cJSON_IsNumber(slot_avail))
    {
    goto end; //Numeric
    }
    }

    // sys_info_schema->ram
    cJSON *ram = cJSON_GetObjectItemCaseSensitive(sys_info_schemaJSON, "ram");
    if (cJSON_IsNull(ram)) {
        ram = NULL;
    }
    if (ram) { 
    if(!cJSON_IsNumber(ram))
    {
    goto end; //Numeric
    }
    }

    // sys_info_schema->ram_avail
    cJSON *ram_avail = cJSON_GetObjectItemCaseSensitive(sys_info_schemaJSON, "ramAvail");
    if (cJSON_IsNull(ram_avail)) {
        ram_avail = NULL;
    }
    if (ram_avail) { 
    if(!cJSON_IsNumber(ram_avail))
    {
    goto end; //Numeric
    }
    }

    // sys_info_schema->vpn
    cJSON *vpn = cJSON_GetObjectItemCaseSensitive(sys_info_schemaJSON, "vpn");
    if (cJSON_IsNull(vpn)) {
        vpn = NULL;
    }
    if (vpn) { 
    if(!cJSON_IsNumber(vpn))
    {
    goto end; //Numeric
    }
    }

    // sys_info_schema->vpn_avail
    cJSON *vpn_avail = cJSON_GetObjectItemCaseSensitive(sys_info_schemaJSON, "vpnAvail");
    if (cJSON_IsNull(vpn_avail)) {
        vpn_avail = NULL;
    }
    if (vpn_avail) { 
    if(!cJSON_IsNumber(vpn_avail))
    {
    goto end; //Numeric
    }
    }

    // sys_info_schema->gpu
    cJSON *gpu = cJSON_GetObjectItemCaseSensitive(sys_info_schemaJSON, "gpu");
    if (cJSON_IsNull(gpu)) {
        gpu = NULL;
    }
    if (gpu) { 
    if(!cJSON_IsNumber(gpu))
    {
    goto end; //Numeric
    }
    }

    // sys_info_schema->gpu_avail
    cJSON *gpu_avail = cJSON_GetObjectItemCaseSensitive(sys_info_schemaJSON, "gpuAvail");
    if (cJSON_IsNull(gpu_avail)) {
        gpu_avail = NULL;
    }
    if (gpu_avail) { 
    if(!cJSON_IsNumber(gpu_avail))
    {
    goto end; //Numeric
    }
    }

    // sys_info_schema->ram_cpu
    cJSON *ram_cpu = cJSON_GetObjectItemCaseSensitive(sys_info_schemaJSON, "ramCpu");
    if (cJSON_IsNull(ram_cpu)) {
        ram_cpu = NULL;
    }
    if (ram_cpu) { 
    if(!cJSON_IsString(ram_cpu) && !cJSON_IsNull(ram_cpu))
    {
    goto end; //String
    }
    }

    // sys_info_schema->el032
    cJSON *el032 = cJSON_GetObjectItemCaseSensitive(sys_info_schemaJSON, "el032");
    if (cJSON_IsNull(el032)) {
        el032 = NULL;
    }
    if (el032) { 
    if(!cJSON_IsString(el032) && !cJSON_IsNull(el032))
    {
    goto end; //String
    }
    }

    // sys_info_schema->el132
    cJSON *el132 = cJSON_GetObjectItemCaseSensitive(sys_info_schemaJSON, "el132");
    if (cJSON_IsNull(el132)) {
        el132 = NULL;
    }
    if (el132) { 
    if(!cJSON_IsString(el132) && !cJSON_IsNull(el132))
    {
    goto end; //String
    }
    }

    // sys_info_schema->mmu_tg16k
    cJSON *mmu_tg16k = cJSON_GetObjectItemCaseSensitive(sys_info_schemaJSON, "mmuTg16k");
    if (cJSON_IsNull(mmu_tg16k)) {
        mmu_tg16k = NULL;
    }
    if (mmu_tg16k) { 
    if(!cJSON_IsString(mmu_tg16k) && !cJSON_IsNull(mmu_tg16k))
    {
    goto end; //String
    }
    }

    // sys_info_schema->hw_pac
    cJSON *hw_pac = cJSON_GetObjectItemCaseSensitive(sys_info_schemaJSON, "hwPac");
    if (cJSON_IsNull(hw_pac)) {
        hw_pac = NULL;
    }
    if (hw_pac) { 
    if(!cJSON_IsNumber(hw_pac))
    {
    goto end; //Numeric
    }
    }

    // sys_info_schema->arm_trace
    cJSON *arm_trace = cJSON_GetObjectItemCaseSensitive(sys_info_schemaJSON, "armTrace");
    if (cJSON_IsNull(arm_trace)) {
        arm_trace = NULL;
    }
    if (arm_trace) { 
    if(!cJSON_IsString(arm_trace) && !cJSON_IsNull(arm_trace))
    {
    goto end; //String
    }
    }

    // sys_info_schema->cores
    cJSON *cores = cJSON_GetObjectItemCaseSensitive(sys_info_schemaJSON, "cores");
    if (cJSON_IsNull(cores)) {
        cores = NULL;
    }
    if (cores) { 
    if(!cJSON_IsNumber(cores))
    {
    goto end; //Numeric
    }
    }

    // sys_info_schema->cores_avail
    cJSON *cores_avail = cJSON_GetObjectItemCaseSensitive(sys_info_schemaJSON, "coresAvail");
    if (cJSON_IsNull(cores_avail)) {
        cores_avail = NULL;
    }
    if (cores_avail) { 
    if(!cJSON_IsNumber(cores_avail))
    {
    goto end; //Numeric
    }
    }

    // sys_info_schema->ram_core
    cJSON *ram_core = cJSON_GetObjectItemCaseSensitive(sys_info_schemaJSON, "ramCore");
    if (cJSON_IsNull(ram_core)) {
        ram_core = NULL;
    }
    if (ram_core) { 
    if(!cJSON_IsNumber(ram_core))
    {
    goto end; //Numeric
    }
    }


    sys_info_schema_local_var = sys_info_schema_create_internal (
        numa_nodes ? numa_nodes->valuedouble : 0,
        cpu ? cpu_local_object : NULL,
        cpu_avail ? cpu_avail_local_object : NULL,
        slot ? slot->valuedouble : 0,
        slot_avail ? slot_avail->valuedouble : 0,
        ram ? ram->valuedouble : 0,
        ram_avail ? ram_avail->valuedouble : 0,
        vpn ? vpn->valuedouble : 0,
        vpn_avail ? vpn_avail->valuedouble : 0,
        gpu ? gpu->valuedouble : 0,
        gpu_avail ? gpu_avail->valuedouble : 0,
        ram_cpu && !cJSON_IsNull(ram_cpu) ? strdup(ram_cpu->valuestring) : NULL,
        el032 && !cJSON_IsNull(el032) ? strdup(el032->valuestring) : NULL,
        el132 && !cJSON_IsNull(el132) ? strdup(el132->valuestring) : NULL,
        mmu_tg16k && !cJSON_IsNull(mmu_tg16k) ? strdup(mmu_tg16k->valuestring) : NULL,
        hw_pac ? hw_pac->valuedouble : 0,
        arm_trace && !cJSON_IsNull(arm_trace) ? strdup(arm_trace->valuestring) : NULL,
        cores ? cores->valuedouble : 0,
        cores_avail ? cores_avail->valuedouble : 0,
        ram_core ? ram_core->valuedouble : 0
        );

    return sys_info_schema_local_var;
end:
    return NULL;

}
