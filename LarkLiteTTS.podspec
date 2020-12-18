#
# Be sure to run `pod lib lint LarkLiteTTS.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'LarkLiteTTS'
  s.version          = '1.3.0-fw'
  s.summary          = 'LarkLite SDK libs for iOS.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
  Tencent LarkLite TTS SDK libs for iOS.
                       DESC

  s.homepage         = 'https://github.com/LarkLite/LarkLite-iOS-SDK'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  # s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'Rinc' => 'rincliu@tencent.com' }
  s.source           = { :git => 'https://github.com/LarkLite/LarkLite-iOS-SDK.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  # s.source_files = '*.h'

  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'

  s.ios.vendored_frameworks = 'LarkLite.framework'
  # s.ios.vendored_libraries = 'libsynthesizer.a'
  
  # s.resource_bundles = {
  #  'LarkLite' => ['Assets/*.trf']
  # }

  s.ios.deployment_target = '9.0'
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
end

