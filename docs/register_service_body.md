# register_service_body_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**password** | **char \*** | Service password, must match the configured service password. | 
**node_id** | **char \*** | Node identifier. | 
**address** | **char \*** | Service address (IP:Port). | 
**service_name** | **char \*** | Service name (e.g. mast, c3po, iptables-nat). | 
**endpoints** | [**list_t**](service_endpoint_schema.md) \* | Endpoints this service exposes. Replaces any previously registered endpoints for this address. | [optional] 
**identity_key** | **char \*** | Identity key for mutual authentication. | 
**ca_cert** | **char \*** | CA certificate. | 
**cert_fingerprint** | **char \*** | Certificate fingerprint. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


