# shared_snapshots_info_schema_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**shared_on** | **char \*** | Date of when the snapshot was first shared with member. | [optional] 
**shared_with_member** | **char \*** | The member who the snapshot was shared with. Only present in sharedWithUser. | [optional] 
**sharing_type** | **corellium_api_shared_snapshots_info_schema_SHARINGTYPE_e** | Sharing type of the snapshot. | 
**shared_by** | [**snapshot_owner_schema_t**](snapshot_owner_schema.md) \* |  | [optional] 
**id** | **char \*** | The snapshot identifier. | 
**date** | **double** | Date that the snapshot was created (UNIX epoch milliseconds). | 
**hw_pac** | **double** | Denotes whether this snapshot requires a compute node with hardware PAC enabled. | 
**instance** | **char \*** | The UUID of the instance that this snapshot is of. | 
**live** | **int** | Live snapshot (included state and memory). | [optional] 
**local** | **int** | Denotes whether the snapshot has a local storage type. | 
**model** | **char \*** | The device model. | [optional] [default to '']
**type** | **char \*** | Device type of the instance this snapshot belongs to. | [optional] 
**name** | **char \*** | The snapshot name. | 
**status** | [**snapshot_status_schema_t**](snapshot_status_schema.md) \* |  | 
**fresh** | **int** | Denotes whether snapshot was created immediately after the device was restored. | [optional] 
**sharing** | [**snapshot_sharing_t**](snapshot_sharing.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


