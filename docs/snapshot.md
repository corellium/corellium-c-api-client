# snapshot_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**id** | **char \*** | The snapshot identifier. | 
**name** | **char \*** | The snapshot name. | 
**instance** | **char \*** | The UUID of the instance that this snapshot is of. | 
**status** | [**snapshot_status_schema_t**](snapshot_status_schema.md) \* |  | 
**date** | **double** | Date that the snapshot was created (UNIX epoch milliseconds). | 
**fresh** | **int** | Denotes whether snapshot was created immediately after the device was restored. | [optional] 
**live** | **int** | Live snapshot (included state and memory). | [optional] 
**local** | **int** | Denotes whether the snapshot has a local storage type. | 
**model** | **char \*** | The device model. | [optional] 
**sharing** | [**snapshot_sharing_t**](snapshot_sharing.md) \* |  | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


