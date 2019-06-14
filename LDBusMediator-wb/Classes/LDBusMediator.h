//
//  LDMediator.h
//  LDBusMediator
//
//  Created by 庞辉 on 4/8/16.
//  Copyright © 2016 casa. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "UIViewController+NavigationTip.h"


/**
 * 中间件向调用者提供:
 *  (1)baseViewController的传递key: kLDRouteViewControllerKey
 *  (2)newController导航方式的传递key: kLDRouteModeKey
 *  (3)LDBusNavigator.h定义了目前支持的导航方式有三种；
 */
#import "LDBusNavigator.h"
FOUNDATION_EXTERN NSString *__nonnull const kLDRouteViewControllerKey;
FOUNDATION_EXTERN NSString *__nonnull const kLDRouteModeKey; 


/**
 * @class LDBusMediator
 *  总线控制中心
 */
@protocol LDBusConnectorPrt;
@interface LDBusMediator : NSObject

#pragma mark - 向总控制中心注册挂接点

//connector自load过程中，注册自己
+(void)bus_registerConnector:(nonnull id<LDBusConnectorPrt>)connector;


#pragma mark - 页面跳转接口

//判断某个URL能否导航
+(BOOL)bus_canRouteURL:(nonnull NSURL *)URL;

//通过URL直接完成页面跳转
+(BOOL)bus_routeURL:(nonnull NSURL *)URL;
+(BOOL)bus_routeURL:(nonnull NSURL *)URL withParameters:(nullable NSDictionary *)params;

//通过URL获取viewController实例
+(nullable UIViewController *)bus_viewControllerForURL:(nonnull NSURL *)URL;
+(nullable UIViewController *)bus_viewControllerForURL:(nonnull NSURL *)URL withParameters:(nullable NSDictionary *)params;


#pragma mark - 服务调用接口

//根据protocol获取服务实例
+(nullable id)bus_serviceForProtocol:(nonnull Protocol *)protocol;


@end
