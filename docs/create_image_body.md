# create_image_body_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | **image_type_t \*** |  | 
**encoding** | **image_encoding_t \*** |  | 
**encapsulated** | **int** | Whether the uploaded file is a ZIP wrapper the server should unzip. Leave this unset or false when you upload a file directly (a one-shot multipart create defaults it to false); only browser-style wrapped uploads set it to true. | [optional] 
**name** | **char \*** | Name for the image. In a multipart upload it defaults to the filename of the uploaded file; in a JSON request you must supply it. Names do not have to be unique. For &#x60;partition&#x60; images this must be the name of the partition to replace. | [optional] 
**full_path** | **char \*** | Not for normal API use. Registers a file that already exists on the server instead of uploading one; it is used by cluster installation tools. Leave it unset. | [optional] 
**project_id** | **char \*** | Optional. Puts the image in this project. You must have access to the project (otherwise 403). Project images count against the project&#39;s storage quota.  **Lifetime.** The image is deleted automatically when the project is deleted, which makes a scratch project a simple way to clean up test uploads.  **Booting from it.** Project firmware images do not appear in &#x60;GET /v3/models/{model}/software&#x60;. To create a device from one, pass the image &#x60;id&#x60; as &#x60;fwPackage&#x60; to &#x60;POST /v3/instances&#x60;; no install step is needed. Also pass &#x60;osVersion&#x60; or &#x60;osBuild&#x60;; if you do not know them, read them from the file first with &#x60;POST /v3/images/{imageId}/fwinfo&#x60;. Models whose &#x60;supportsCustomFirmwareImage&#x60; is false reject an image ID in &#x60;fwPackage&#x60;.  Side effect: if the project already holds 5 or more images that are not attached to an instance, the oldest of them is deleted to make room.  Ignored when &#x60;instanceId&#x60; is set: the image then belongs to that instance&#39;s project. Leave both unset to create a domain-level image. | [optional] 
**instance_id** | **char \*** | Optional. Attaches the image to this instance (device). The instance must exist (otherwise 404), and the image is placed in the instance&#39;s project. The instance can be running, paused or off.  **Lifetime.** The image is deleted automatically when the instance is deleted.  Side effect: any image of the same &#x60;type&#x60; already attached to the instance is deleted first, so each instance keeps at most one image per type. For &#x60;partition&#x60; images only the one with the same &#x60;name&#x60; is replaced. MATRIX types (&#x60;mast-*&#x60;) are never deleted this way, so a device can keep a history of MATRIX files. | [optional] 
**file** | **binary_t*** | Multipart requests only: the file contents. Send the &#x60;type&#x60; and other fields before this part. Omit it (or use a JSON request) to create the record now and upload the contents later. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


