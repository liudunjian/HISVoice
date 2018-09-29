//
//  HSSemanticRecognizer.h
//  HisenseSDKDemo-v1.0
//
//  Created by 苗春 on 18/6/20
//  Copyright © 2018年 hisense keylab All rights reserved.
//

//识别协议
@protocol HSSemanticRecognizerDelegate <NSObject>

//语义识别开始回调
//@optional
//-(void)onSematicStart;

//语义识别结果回传
@required
-(void)onSematicResult:(NSString*) result;

//识别异常回传
-(void)onRecognitionException:(NSString*) exception;

//获取快捷指令错误
-(void)onShortcutInstructionException:(int)errorCode;

//快捷指令结果回调
-(void)onShortcutInstructionResult:(NSString *)siResult;

//设备列表上报结果
-(void)onReportDevs:(int)res;

@end


@interface HSSemanticRecognizer : NSObject

//获取单例
+(instancetype)getSharedInstance;

//注销
//-(void)uninit;

//设置设备id，设备类型，设备型号和地区
-(void)setParams:(NSString *)devID :(NSString *)devType :(NSString *)type :(NSString *)area;

//设置语音云版本，1为超级APP1.0，2为超级APP2.0
-(void)setCloudVersion:(int)version;

//设置麦克风类型
-(void)setMicType:(NSString *)micType;

//设置终端类型，超级APP1.0用smarthome，超级APP2.0用mobilephone
-(void)setTerminalType:(NSString *)terminalType;

//设置iPhone手机唯一标示
-(void)setMachineId:(NSString *)machineid;

//设置地区
-(void)setArea:(NSString *)area;

/**
 * 设置聚系列应用版本号
 * @param vod 聚好看版本
 * @param shopping 聚享购版本
 * @param education 聚好学版本
 * @param appStore 聚好用版本
 * @param game 聚好玩版本
 */
-(void)setHisAppVersion:(NSString *)vod shoppingVer:(NSString *)shopping educationVer:(NSString *)education appStoreVer:(NSString *)appStore gameVer:(NSString *)game;
/**
 * 设置聚好看牌照方
 * @param license 牌照方
 */
-(void)setVodLicense:(NSString *)license;

/**
 * 设置电视feature code
 * @param code 电视feature
 */
-(void)setTvFeatureCode:(NSString *)code;

/**
 * 设置语音助手版本
 * @param ver 语音助手版本
 */
-(void)setCoreVersion:(NSString *)ver;

/**
 * 设置网络环境，默认为线上环境NET_CHOICE_RELEASE
 * @param choice 网络环境，只能是NET_CHOICE_RELEASE和NET_CHOICE_DEBUG的一种
 */
-(void)setNetChoice:(NSString *)choice;


/**
 * 设置设备类型，默认值为"galamicsh"
 * @param type 设备类型
 */
-(void)setDeviceType:(NSString *)type;
/**
 * 设置设备型号，默认值为"VIDAA4"
 * @param type 设备型号
 */
-(void)setTvType:(NSString *)type;

/**
 * 设置聚好用参数
 * @param token 聚好用token
 * @param starttime 聚好用token创建时间
 * @param endtime 聚好用token有效时间
 * @param id 聚好用token请求id
 */
-(void)setTokenSetting:(NSString *)token createTime:(NSString *)starttime expiredTime:(NSString *)endtime subscried:(NSString *)id;


/**
 * 设置用户id
 * @param id 用户id
 */
-(void)setCustomerID:(NSString *)id;
/**
 * 设置电视版本号
 * @param version 电视版本号
 */
-(void)setTvVersion:(NSString *)version;

/**
 * 设置电视演示demo版本
 * @param ver 电视演示demo版本
 */
-(void)setTvDemoVer:(NSString *)ver;

/**
 * 设置vidaa助手版本
 * @param ver vidaa助手版本号
 */
-(void)setVidaaIdeVer:(NSString *)ver;

/**
 * 设置电视系统版本
 * @param ver 电视系统版本号
 */
-(void)setTvSystemVersion:(NSString *)ver;

/**
 * 设置聚好用版本
 * @param code 聚好用版本号
 */
-(void)setStoreVersionCode:(NSString *)code;

/**
 * 设置慧享家是否安装，默认值是false
 * @param isInstalled true，已安装 ；false，未安装
 */
-(void)setSmartHomeInstalled:(BOOL)isInstalled;
/**
 * 设置是否进入多轮，默认值是false
 * @param isOn true，进入多轮 ；false，不进入多轮
 */
-(void)setMenuOn:(BOOL)isOn;
/**
 * 设置请求的语义服务版本
 * @param ver 语义服务版本号
 */
-(void)setRequestVersion:(NSString *)ver;
/**
 * 设置智慧家居服务开关，默认为开启
 * @param swi 智慧家居服务开关  true:开启服务，false:关闭服务
 */
-(void)setSmartHomeSwitch:(BOOL)swi;

-(void)setCalendarVersion:(NSString *)calendar;

-(void)setFrontScene:(NSString *)scene;

-(void)setPosition:(NSString *)pos;

/**
 * 设置时序编号
 * @param numb 时序编号
 */
-(void)setSerialNumber:(NSString *)numb;

/**
 * 上报设备列表
 * @param devices  设备列表, for example:
     "[{'wifiID':'nibaba001','deviceID':'1wn100008v0c','deviceType':'00e','nickName':'智能冰箱'},{'wifiID':'nibaba001','deviceID':'1wn100008v0g','deviceType':'010006','nickName':'次卧纱帘'},{'wifiID':'nibaba001','deviceID':'1wn100008v0h','deviceType':'013','nickName':'中央空调'}]"
 * @param machineid  device id
 */
-(void)reportDevices:(NSString *)devices :(NSString *)machineid;

/**
 * 获取快捷指令
 * @param machineid  device id
 */
-(void)catchShortcutInstructions:(NSString *)machineid;

//单独语义识别
-(void)sematicRecognize:(NSString *)text;
-(void)destroySemantic;
@property(nonatomic,weak)id<HSSemanticRecognizerDelegate> mHSSemanticRecognizerDelegate;
@end
