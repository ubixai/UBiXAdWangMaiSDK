//
//  U_XAdWMNativeAd.h
//  U_AdWangMaiSDK
//
//  Created by xiang shi on 2024/9/12.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


typedef NS_ENUM(NSInteger, AdSlotType) {
    WMAdSlotTypeSplash, //开屏
    WMAdSlotTypeNative, //信息流
    WMAdSlotTypeRewardVideo, //激励视频
    WMAdSlotTypeInterstitial, //插屏
};

NS_ASSUME_NONNULL_BEGIN
@protocol U_XAdWMNativeAdDelegate;

@interface U_XAdWMNativeAd : NSObject

/// 广告类型 Ad type. [必传]
@property (nonatomic,assign) AdSlotType adSlotType;

/// 代理
@property (weak, nonatomic) id<U_XAdWMNativeAdDelegate>delegate;

/// 是否需要满足HTTPS  [可选] 默认为NO
@property (nonatomic,assign) BOOL secure;

/// 广告尺寸 [必传]
@property (nonatomic,assign) CGSize adSize;

/// [必传]开发者需传入用来弹出目标页的ViewController
@property (nonatomic, weak) UIViewController *controller;

/// 初始化广告
/// - Parameter adSlotId: 广告位id
- (instancetype)initWithAdSlotId:(NSString *)adSlotId;

/// 请求广告
- (void)loadAdData;

/// 竞价成功上报，脉盟平台竞胜之后调用，需要在广告请求成功之后,展示之前调用，winInfo脉盟平台竞价获胜信息，可为nil。
/// @param winInfo 竞胜信息 字典类型
- (void)sendWinNotificationWithInfo:(NSDictionary *_Nullable)winInfo;

/// 视图注册方法
/// - Parameter containerView: 广告容器视图
/// - Parameter clickableViews: 可点击的视图数组，此数组内的广告元素才可以响应广告对应的点击事件
- (void)registerContainer:(UIView *)containerView withClickableViews:(NSArray<UIView *> *_Nullable)clickableViews;

/// 广告数据渲染完毕，即将展示时需调用trackImpression方法。
- (void)trackImpression;

/// 广告曝光，广告视图曝光后调用adViewDidShow方法通知SDK。
- (void)adViewDidShow;

/// 广告将要关闭
- (void)adViewWillClosed;

/// 广告销毁
- (void)onDestroy;
@end

NS_ASSUME_NONNULL_END
