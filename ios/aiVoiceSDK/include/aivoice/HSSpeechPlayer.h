//
//  HSSpeechPlayer.h
//
//
//  Created by 苗春 on 18/6/20
//  Copyright © 2018年 hisense keylab All rights reserved.
//


//识别协议
//@class IFlySpeechError;
@protocol HSSpeechPlayerDelegate <NSObject>

@required

//tts callback start
/*!
 *  结束回调<br>
 *  当整个合成结束之后会回调此函数
 *
 *  @param errorCode 错误码
 *  @param errtype 错误类型
 *  @param errdesc 错误描述
 */
- (void) onTTSCompleted:(int)errorCode errorType:(int)errtype errorDesc:(NSString *)errdesc;
//tts callback end

@optional

//tts callback start========================================================
/*!
 *  开始合成回调
 */
- (void) onTTSBegin;

/*!
 *  播放进度回调
 *
 *  @param progress 当前播放进度，0-100
 *  @param beginPos 当前播放文本的起始位置（按照字节计算），对于汉字(2字节)需／2处理
 *  @param endPos 当前播放文本的结束位置（按照字节计算），对于汉字(2字节)需／2处理
 */
- (void) onTTSProgress:(int) progress beginPos:(int)beginPos endPos:(int)endPos;

/*!
 *  暂停播放回调
 */
- (void) onTTSPaused;

/*!
 *  恢复播放回调<br>
 *  注意：此回调方法SDK内部不执行，播放恢复全部在onSpeakBegin中执行
 */
- (void) onTTSResumed;

/*!
 *  正在取消回调<br>
 *  注意：此回调方法SDK内部不执行
 */
- (void) onTTSCancel;

//tts callback end========================================================

@end


@interface HSSpeechPlayer : NSObject
+(instancetype)getSharedInstance;
-(void)initTTS;
/*!
 *  销毁合成对象。
 *
 *  @return 成功返回YES,失败返回NO.
 */
+ (BOOL) destroyTTS;

/*
 *  | ------------- |-----------------------------------------------------------
 *  | 参数           | 描述
 *  | ------------- |-----------------------------------------------------------
 *  | speed         |合成语速,取值范围 0~100
 *  | ------------- |-----------------------------------------------------------
 *  | volume        |合成的音量,取值范围 0~100
 *  | ------------- |-----------------------------------------------------------
 *  | voice_name    |默认为”xiaoyan”；可以设置的参数列表可参考个性化发音人列表
 *  | ------------- |-----------------------------------------------------------
 *  | sample_rate   |采样率:目前支持的采样率设置有 16000 和 8000。
 *  | ------------- |-----------------------------------------------------------
 *  | tts_audio_path|音频文件名 设置此参数后，将会自动保存合成的音频文件。
 *  |               |路径为Documents/(指定值)。不设置或者设置为nil，则不保存音频。
 *  | ------------- |-----------------------------------------------------------
 *  | params        |扩展参数: 对于一些特殊的参数可在此设置。
 *  | ------------- |-----------------------------------------------------------
 *
 */

/*!
 *  设置合成参数
 *
 *  | 参数             | 描述                                               |
 *  |-----------------|----------------------------------------------------|
 *  | speed           | 合成语速,取值范围 0~100                               |
 *  | volume          | 合成的音量,取值范围 0~100                             |
 *  | voice_name      | 默认为”xiaoyan”；可以设置的参数列表可参考个性化发音人列表   |
 *  | sample_rate     | 采样率:目前支持的采样率设置有 16000 和 8000。            |
 *  | tts_audio_path  | 音频文件名 设置此参数后，将会自动保存合成的音频文件。<br>路径为Documents/(指定值)。不设置或者设置为nil，则不保存音频。|
 *  | params          | 扩展参数: 对于一些特殊的参数可在此设置。                  |
 *
 *  @param value 参数取值
 *  @param key   合成参数
 *
 *  @return 设置成功返回YES，失败返回NO
 */
-(BOOL) setTTSParameter:(NSString *) value forKey:(NSString*)key;

/*!
 *  获取合成参数
 *
 *  @param key 参数key
 *
 *  @return 参数值
 */
-(NSString*) getTTSParameterForKey:(NSString *)key;

/*!
 *  开始合成(播放)<br>
 *  调用此函数进行合成，如果发生错误会回调错误`onCompleted`
 *
 *  @param text 合成的文本,最大的字节数为1k
 */
- (void) startSynthesizeAndPlay:(NSString *)text;

/*!
 *  开始合成(不播放)<br>
 *  调用此函数进行合成，如果发生错误会回调错误`onCompleted`
 *
 *  @param text 合成的文本,最大的字节数为1k
 *  @param uri  合成后，保存再本地的音频路径
 */
-(void)startSynthesize:(NSString *)text toUri:(NSString*)uri;

/*!
 *  暂停播放<br>
 *  暂停播放之后，合成不会暂停，仍会继续，如果发生错误则会回调错误`onCompleted`
 */
- (void) pauseSpeechPlay;

/*!
 *  恢复播放
 */
- (void) resumeSpeechPlay;

/*!
 *  停止播放并停止合成
 */
- (void) stopSynthesizeAndPlay;

@property(nonatomic,weak)id<HSSpeechPlayerDelegate> mHSSpeechPlayerDelegate;
@end
