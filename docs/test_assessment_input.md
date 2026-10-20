# test_assessment_input_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**invert** | **int** | Optional, default false. When true, run every check EXCEPT those matched by &#x60;grep&#x60;. Has no effect without &#x60;grep&#x60;. | [optional] 
**grep** | **char \*** | A JavaScript regular expression; only checks whose check ID, group ID, or category ID matches it are run. Without anchors (&#x60;^&#x60;, &#x60;$&#x60;) it can match anywhere in the ID, so &#x60;masvs-storage&#x60; selects every storage check. Characters such as &#x60;.&#x60; have their regular-expression meaning. To add flags, wrap the pattern in slashes, for example &#x60;/^masvs-network-1-ios-/i&#x60;. Omit to run every applicable check. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


