//
//  U_XAdRewardedVideoAd.h
//  U_AdWangMaiSDK
//
//  Created by 周泽浩 on 2023/3/1.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@protocol U_XAdRewardedVideoDelegate;

@interface U_XAdRewardedVideoAd : NSObject

/// 代理
@property (nonatomic,weak) id<U_XAdRewardedVideoDelegate>delegate;

/// 是否需要满足HTTPS  [可选] 默认为NO
@property (nonatomic,assign) BOOL secure;

/// 初始化广告
/// - Parameter adSlotId: 广告位id
- (instancetype)initWithAdSlotId:(NSString *)adSlotId;


/// 请求广告
- (void)loadAdData;

/// 展示广告方法
/// @param rootViewController 用于 present 激励视频 VC
- (void)showAdFromRootViewController:(UIViewController *)rootViewController;

/**
 返回广告的eCPM，单位：分
 
 @return 成功返回一个大于等于0的值，-1表示无权限或后台出现异常
 */
- (NSInteger)eCPM;

/// 竞价成功上报，脉盟平台竞胜之后调用，需要在广告请求成功之后,展示之前调用，winInfo脉盟平台竞价获胜信息，可为nil。
/// @param winInfo 竞胜信息 字典类型
- (void)sendWinNotificationWithInfo:(NSDictionary *_Nullable)winInfo;

/// 获取当前广告物料
/// material_url: 素材 url 数组
- (NSDictionary *)getCurrentAdMaterialsInfo;

@end

NS_ASSUME_NONNULL_END
