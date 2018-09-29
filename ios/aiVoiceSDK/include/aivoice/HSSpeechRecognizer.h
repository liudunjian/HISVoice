//
//  HSSpeechRecognizer.h
//  HisenseSDKDemo-v1.0
//
//  Created by 苗春 on 18/6/20
//  Copyright © 2018年 hisense keylab All rights reserved.
//


//识别协议
@protocol HSSpeechRecognizerDelegate <NSObject>

@required
//ASR callback start
/*!
 *  识别结果回调
 *
 *  在进行语音识别过程中的任何时刻都有可能回调此函数，你可以根据errorCode进行相应的处理，当errorCode没有错误时，表示此次会话正常结束；否则，表示此次会话有错误发生。特别的当调用`cancel`函数时，引擎不会自动结束，需要等到回调此函数，才表示此次会话结束。在没有回调此函数之前如果重新调用了`startListenging`函数则会报错误。
 *
 *  @param errorCode 错误描述
 */
- (void) onAsrError:(int)errorCode errorType:(int)errtype errorDesc:(NSString *)errdesc;

/*!
 *  识别结果回调
 *  @param results   音频数据识别的结果
 *  @param age 年龄信息 0-middle aged 1-children 2-old
 *  @param isex 性别 0-女声 1-男声
 */
- (void) onAsrResults:(NSString *) results isAge:(NSString *)age isSex:(NSString *)isex;
//ASR callback end

//record callback start
/*!
 *  回调音频数据
 *
 *  @param buffer 音频数据
 *  @param size   表示音频的长度
 */
//- (void) onRecorderBuffer: (const void *)buffer bufferSize:(int)size;

/*!
 *  回调音频的错误码
 *
 *  @param error   错误码
 */
- (void) onRecorderError:(int) error;
//record callback end

@optional
//ASR callback start========================================================
/*!
 *  音量变化回调<br>
 *  在录音过程中，回调音频的音量。
 *
 *  @param volume -[out] 音量，范围从0-30
 */
- (void) onAsrVolumeChanged: (int)volume;

/*!
 *  开始录音回调<br>
 *  当调用了`startListening`函数之后，如果没有发生错误则会回调此函数。<br>
 *  如果发生错误则回调onError:函数
 */
- (void) onAsrBeginOfSpeech;

/*!
 *  停止录音回调<br>
 *  当调用了`stopListening`函数或者引擎内部自动检测到断点，如果没有发生错误则回调此函数。<br>
 *  如果发生错误则回调onError:函数
 */
- (void) onAsrEndOfSpeech;

/*!
 *  取消识别回调<br>
 *  当调用了`cancel`函数之后，会回调此函数，在调用了cancel函数和回调onError之前会有一个<br>
 */
- (void) onAsrCancel;
//ASR callback end========================================================

/*!
 *  回调录音音量
 *
 *  @param power 音量值
 */
- (void) onRecorderVolumeChanged:(int) power;
@end


@interface HSSpeechRecognizer : NSObject

/*!
 *  返回对象的单例,并初始化，包括设置采样率和音频保存路径
 *
 *  @return 识别对象的单例
 */
//+(instancetype)getSharedInstance;
+(instancetype)getSharedInstance:(NSString *)sample_rate audioPath:(NSString *)save_audio_path;
/*!
 *  初始化
 */
-(void)initASR;
/*!
 *  准备开始录取音频数据
 *
 *  @return 返回准备状态结果
 */
-(BOOL)startAsr;

/*!
 *  停止录取音频数据
 *
 */
-(void)stopAsr;

/*!
 *  取消本次回话
 *
 */
-(void)cancelAsr;

/*!
 *  设置识别引擎参数
 *  | ------------- |-----------------------------------------------------------
 *  | 参数           | 描述
 *  | ------------- |-----------------------------------------------------------
 *  | sample_rate   |采样率:目前支持的采样率设置有 16000。
 *  | ------------- |-----------------------------------------------------------
 *  | asr_ptt       |标点符号设置: 默认为 1，当设置为 0 时，将返回无标点符号文本。
 *  | ------------- |-----------------------------------------------------------
 *  @return 返回取消状态结果
 */
-(BOOL)setAsrParameter:(NSString *)value forKey:(NSString *)key;

//record method start
/*!
 *  写入音频流
 *
 *  @return 返回写入状态结果
 */
-(BOOL)recordAudio :(const void *)buffer bufferSize : (int)size;


/*!
 *  初始化
 */
-(void)initRecorder;


/*!
 *  开始录音
 *
 *  @return  开启录音成功返回YES，否则返回NO
 */
- (BOOL) startHSRecord;

/*!
 *  停止录音
 */
- (void) stopHSRecord;

/*!
 *  设置音频采样率
 *
 *  @param rate -[in] 采样率，8k/16k
 */
- (void) setReocrdSample:(NSString *) rate;

/*!
 * 设置录音音量回调时间间隔参数
 */
- (void) setRecordPowerCycle:(float) cycle;

/*!
 *  保存录音
 *
 *  @param savePath 音频保存路径
 */
-(void) setRecordSaveAudioPath:(NSString *)savePath;
//record method end


@property(nonatomic,weak)id<HSSpeechRecognizerDelegate> mHSSpeechRecognizerDelegate;
@end
