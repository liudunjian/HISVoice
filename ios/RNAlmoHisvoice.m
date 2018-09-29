#import "RNAlmoHisvoice.h"

/*!
 NSDictionary* event = @{
 @"type": @"onMapPoiClick",
 @"params": @{
 @"name": mapPoi.text,
 @"uid": mapPoi.uid,
 @"latitude": @(mapPoi.pt.latitude),
 @"longitude": @(mapPoi.pt.longitude)
 }
 };
*/

@interface RNAlmoHisvoice() <HSSpeechRecognizerDelegate>
@property(nonatomic,strong)HSSpeechRecognizer *mHSSpeechRecognizer;
@end

@implementation RNAlmoHisvoice

@synthesize bridge = _bridge;

- (dispatch_queue_t)methodQueue {
    return dispatch_get_main_queue();
}

RCT_EXPORT_MODULE()

RCT_EXPORT_METHOD(startRecognize) {
    NSLog(@"startRecognize");
    
    if(self.mHSSpeechRecognizer !=nil){
        [self.mHSSpeechRecognizer stopHSRecord];
    }
    if(self.mHSSpeechRecognizer !=nil){
        [self.mHSSpeechRecognizer stopAsr];
    }
    //[NSThread sleepForTimeInterval:2];
    
    [self initHSRecognizer];
    [self.mHSSpeechRecognizer initRecorder];
    [self.mHSSpeechRecognizer startHSRecord];
    BOOL ret = [self.mHSSpeechRecognizer startAsr];
    
    NSLog(@"startRecognizer ret == %d",ret);
}

RCT_EXPORT_METHOD(stopRecognize) {
    NSLog(@"stopRecognize");
    [NSThread sleepForTimeInterval:0.5];
    [self.mHSSpeechRecognizer stopAsr];
    [self.mHSSpeechRecognizer stopHSRecord];
}

-(void)sendEvent:(NSString *)name body:(NSDictionary *)body {
    [self.bridge.eventDispatcher sendDeviceEventWithName:name body:body];
}

-(void)initHSRecognizer {
    if(self.mHSSpeechRecognizer ==nil){
        self.mHSSpeechRecognizer = [HSSpeechRecognizer getSharedInstance:@"16000" audioPath:nil];//[HSSpeechRecognizer getSharedInstance];
    }
    
    if(self.mHSSpeechRecognizer !=nil){
        //set sample rate, 16K as a recommended option
        [self.mHSSpeechRecognizer initASR];
    }
    
    self.mHSSpeechRecognizer.mHSSpeechRecognizerDelegate = self;
    
    if (self.mHSSpeechRecognizer != nil) {
        //set sample rate, 16K as a recommended option
        [self.mHSSpeechRecognizer setAsrParameter:@"16000" forKey:@"sample_rate"];
        
        //set whether or not to show punctuation in recognition results
        [self.mHSSpeechRecognizer setAsrParameter:@"0" forKey:@"asr_ptt"];
    }
}

#pragma speech recognize callback

- (void)onAsrError:(int)errorCode errorType:(int)errtype errorDesc:(NSString *)errdesc {
    NSLog(@"onAsrError-----errorCode:%d,errorType:%d,errdesc:%@",errorCode,errtype,errdesc);
    NSDictionary* event = @{
                            @"type": @"onAsrError",
                            @"params": @{
                                    @"errorCode": @(errorCode),
                                    @"errorType": @(errtype),
                                    @"errorDesc": errdesc
                                    }
                            };
    [self sendEvent:@"onAsrError" body:event];
}


- (void)onAsrResults:(NSString *)results isAge:(NSString *)age isSex:(NSString *)isex {
    NSLog(@"onAsrResults-----------:%@",results);
    NSDictionary* event = @{
                            @"type": @"onAsrResults",
                            @"params": @{
                                    @"results": results,
                                    @"isAge": age,
                                    @"isSex": isex
                                    }
                            };
    [self sendEvent:@"onAsrResults" body:event];
}

- (void)onRecorderError:(int)error {
    NSLog(@"onRecorderError");
    NSDictionary* event = @{
                            @"type": @"onRecorderError",
                            @"params": @{
                                    @"errorCode": @(error),
                                    }
                            };
    [self sendEvent:@"onRecorderError" body:event];
}

/*!
 *  音量变化回调<br>
 *  在录音过程中，回调音频的音量。
 *
 *  @param volume -[out] 音量，范围从0-30
 */
- (void) onAsrVolumeChanged: (int)volume {
    NSLog(@"onAsrVolumeChanged--------%d",volume);
}

/*!
 *  开始录音回调<br>
 *  当调用了`startListening`函数之后，如果没有发生错误则会回调此函数。<br>
 *  如果发生错误则回调onError:函数
 */
- (void) onAsrBeginOfSpeech {
    NSLog(@"onAsrBeginOfSpeech------------");
    NSDictionary* event = @{
                            @"type": @"onAsrBeginOfSpeech"
                            };
    [self sendEvent:@"onAsrBeginOfSpeech" body:event];
}

/*!
 *  停止录音回调<br>
 *  当调用了`stopListening`函数或者引擎内部自动检测到断点，如果没有发生错误则回调此函数。<br>
 *  如果发生错误则回调onError:函数
 */
- (void) onAsrEndOfSpeech {
    NSLog(@"onAsrEndOfSpeech-------------");
    NSDictionary* event = @{
                            @"type": @"onAsrEndOfSpeech"
                            };
    [self sendEvent:@"onAsrEndOfSpeech" body:event];
}

/*!
 *  取消识别回调<br>
 *  当调用了`cancel`函数之后，会回调此函数，在调用了cancel函数和回调onError之前会有一个<br>
 */
- (void) onAsrCancel {
    
}

/*!
 *  回调录音音量
 *
 *  @param power 音量值
 */
- (void) onRecorderVolumeChanged:(int) power {
    NSLog(@"onRecorderVolumeChanged--------%d",power);
    NSDictionary* event = @{
                            @"type": @"onRecorderVolumeChanged",
                            @"params": @{
                                    @"power": @(power),
                                    }
                            };
    [self sendEvent:@"onRecorderVolumeChanged" body:event];
}



@end
  
