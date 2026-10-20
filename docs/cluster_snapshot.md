# cluster_snapshot_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**id** | **char \*** | Unique identifier for the snapshot. | 
**name** | **char \*** | Snapshot name. | [optional] 
**volume** | **char \*** | Identifier of the volume this snapshot was taken from. | [optional] 
**instance** | **char \*** | Identifier of the instance this snapshot is associated with. | [optional] 
**status** | [**cluster_snapshot_status_t**](cluster_snapshot_status.md) \* |  | 
**type** | **corellium_api_cluster_snapshot_TYPE_e** | Storage backend type. | 
**compute_node** | **char \*** | Address of the compute node that owns this snapshot. | [optional] 
**metadata** | [**cluster_snapshot_metadata_t**](cluster_snapshot_metadata.md) \* |  | 
**created_at** | **char \*** | Timestamp when the snapshot was created. | 
**updated_at** | **char \*** | Timestamp when the snapshot was last updated. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


