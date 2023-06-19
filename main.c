#include <stdio.h>
#include <sai.h>

const char* ss_get_value(
    _In_ sai_switch_profile_id_t profile_id,
    _In_ const char* variable) {
    printf("ss_get_value called. ProfileID: %d, Variable: %s\n", profile_id, variable);
    return NULL;
}

int ss_get_next_value(
    _In_ sai_switch_profile_id_t profile_id,
    _Out_ const char** variable,
    _Out_ const char** value) {
    printf("ss_get_next_value called. ProfileID: %d\n", profile_id);
    return -1;
}

// Define service method table
sai_service_method_table_t services = {
    ss_get_value,
    ss_get_next_value
};

sai_switch_api_t* sai_switch_api;
sai_port_api_t* sai_port_api;
sai_neighbor_api_t* sai_neighbor_api;

int main() {
    sai_status_t status;

    // Initialize the SAI API
    printf("sai_api_initialize()... ");
    status = sai_api_initialize(0, &services);
    if (status != SAI_STATUS_SUCCESS) {
        printf("Error: failed to initialize SAI, status=%x\n", -status);
        return -1;
    } else {
	printf("SUCCESS\n");
    }

    // Query the SAI API for the switch API
    printf("sai_api_query()... ");
    status = sai_api_query(SAI_API_SWITCH, (void**)&sai_switch_api);
    if (status != SAI_STATUS_SUCCESS) {
        printf("Error: failed to query SAI switch API, status=%x\n", -status);
        return -1;
    } else {
	printf("SUCCESS\n");
    }


    printf("create_switch()... ");
    sai_object_id_t switch_id;
    sai_attribute_t attr1[2];
    attr1[0].id = SAI_SWITCH_ATTR_INIT_SWITCH;
    attr1[0].value.booldata = true;
    //attr1[0].id = SAI_SWITCH_ATTR_OPER_STATUS;
    //attr1[0].value.u32 = 1;
    attr1[1].id = SAI_SWITCH_ATTR_SRC_MAC_ADDRESS;
    attr1[1].value.u32 = 0x22222200;
    status = sai_switch_api->create_switch(&switch_id, 2, attr1);
    if (status != SAI_STATUS_SUCCESS) {
        printf("Error: failed to initialize switch, status=%x\n", -status);
        return -1;
    } else {
	printf("SUCCESS\n");
    }

    // Uninitialize the SAI API
    printf("sai_api_uninitialize()\n");
    sai_api_uninitialize();

    return 0;
}
