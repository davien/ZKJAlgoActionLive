#
# Be sure to run `pod lib lint ZKJAlgoActionLive.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'ZKJAlgoActionLive'
  s.version          = '0.2.0'
  s.summary          = 'A short description of ZKJAlgoActionLive.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/davien/ZKJAlgoActionLive'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'davien' => 'weiqiang.zhao@msxf.com' }
  s.source           = { :git => 'https://github.com/davien/ZKJAlgoActionLive.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '9.0'
  s.libraries  = "z", "c++"

  s.pod_target_xcconfig = {
    # 'VALID_ARCHS' => 'arm64',
    'EXCLUDED_ARCHS[sdk=iphoneos*]' => 'armv7 armv7s',
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'armv7 armv7s arm64'
  }
  s.user_target_xcconfig = {
    # 'VALID_ARCHS' => 'arm64',
    'EXCLUDED_ARCHS[sdk=iphoneos*]' => 'armv7 armv7s',
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => "armv7 armv7s arm64"
  }

  #s.source_files = 'ZKJAlgoActionLive/Classes/**/*'
  
  # s.resource_bundles = {
  #   'ZKJAlgoActionLive' => ['ZKJAlgoActionLive/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'

  #  新活体 V3.1.3.1
  s.subspec 'LibActionLive' do |ss|
    ss.vendored_frameworks = 'Framework/LibActionLive.framework'
    ss.resources     = ['Bundle/LibActionLive.bundle']
    ss.dependency 'ZKJAlgoBaseAbility'

  end
  
  #  老活体 V2.0.2
  s.subspec 'libidcardocr' do |ss|
    ss.vendored_frameworks = 'Framework/libidcardocr.framework'
    ss.resources     = ['Bundle/libidcardocr.bundle']
    ss.dependency 'ZKJAlgoBaseAbility'

  end
end
