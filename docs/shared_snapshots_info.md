# shared_snapshots_info_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**id** | **char \*** | UUID of the snapshot | 
**name** | **char \*** | Snapshot name | 
**model** | **char \*** | Device model | 
**shared_on** | **double** | UNIX Date of when the snapshot was first shared with member | 
**shared_with_member** | **char \*** | The member who the snapshot was shared with. Only present in sharedWithUser | [optional] 
**shared_by** | [**snapshot_owner_v1_t**](snapshot_owner_v1.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


