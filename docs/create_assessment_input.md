# create_assessment_input_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**instance_id** | **char \*** | Identifier of the instance to assess. | 
**bundle_id** | **char \*** | Bundle identifier of the application to assess. | 
**wordlist_id** | **char \*** | ID of a wordlist: a plain-text file listing sensitive values (one per line), such as test passwords or account numbers, that MATRIX then looks for while testing the app. Upload the file first with &#x60;POST /v3/images&#x60; with &#x60;instanceId&#x60; set to this instance (use &#x60;type: \&quot;mast-wordlist\&quot;&#x60;), then pass the returned image ID here. The server only checks that an image with this ID exists on the instance, not its type, so make sure you pass the right file. The request fails if the image cannot be found. Deleting the assessment also deletes this file. | [optional] 
**frida_script_id** | **char \*** | ID of your own Frida script (JavaScript) to load into the app while it is being monitored, for example to bypass certificate pinning or reach code paths that are hard to trigger. Upload it first with &#x60;POST /v3/images&#x60; with &#x60;instanceId&#x60; set to this instance (use &#x60;type: \&quot;mast-frida\&quot;&#x60;). The server only checks that an image with this ID exists on the instance, not its type. The request fails if the image cannot be found. The script is not deleted when the assessment is. | [optional] 
**created_by** | **char \*** | Identifier of the user creating the assessment. Assigned server-side from the auth context; client-supplied values are ignored. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


