# snapshot_v1_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**id** | **char \*** | Snapshot ID | 
**name** | **char \*** | Snapshot name | 
**instance** | **char \*** | Instance that this snapshot is of | 
**status** | [**snapshot_status_t**](snapshot_status.md) \* |  | 
**date** | **double** | UNIX Date that the snapshot was created | 
**fresh** | **int** |  | 
**live** | **int** | Live snapshot (included state and memory) | 
**local** | **int** |  | 
**model** | **char \*** | The device model | [optional] 
**sharing** | [**snapshot_sharing_v1_t**](snapshot_sharing_v1.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


