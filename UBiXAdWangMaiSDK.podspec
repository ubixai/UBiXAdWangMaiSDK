

Pod::Spec.new do |s|
  s.name             = 'UBiXAdWangMaiSDK'
  s.version          = '7.3.1.16'
  s.summary          = 'AdWangMai SDK for iOS'
  s.homepage         = 'https://www.ubixai.com/product/md'
  # s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'zhugq' => 'guoqiang.zhu@ubixai.com' }
  s.source           = { :git => 'https://github.com/ubixai/UBiXAdWangMaiSDK.git', :tag => s.version.to_s }
  s.ios.deployment_target = '11.0'

  # s.static_framework = true
  s.vendored_frameworks = 'UBiXAdWangMaiSDK/UBiX_AdWangMaiSDK.framework'
  s.resource = 'UBiXAdWangMaiSDK/adwangmai_sdk.bundle'
  

  

  
end
